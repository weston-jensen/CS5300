%{
#include "Expressions.hpp"
#include "symbol_table.hpp"
#include "Constant.hpp"
#include "Type.hpp"
#include "Array_Type.hpp"
#include "TreeParser.hpp"
#include <algorithm>

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>


extern int num_lines;
extern void yyerror(const char *str);
extern int yylex();
extern int yylineno;
extern char* yytext;
%}

%union
{
  int intVal;
  char *strVal;
  std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> *typeList;
  std::vector<std::string> *identList;
  std::vector<Expression> *exprList;
  Type *typeVal;
  Array_Type *arrVal;
  Record *recVal;
  Constant *constVal;
  Expression *expr;
  void *none;
}


 /* TOKENS */
%error-verbose
%token <none> ARRAY_SYM
%token <none> ASSIGN_SYM 
%token <none> BEGIN_SYM
%token <strVal> CHAR_SYM
%token <none> CHR_SYM
%token <none> COLON_SYM
%token <none> COMMA_SYM 
%token <none> CONST_SYM 
%token <none> DIV_SYM 
%token <none> DO_SYM 
%token <none> DOT_SYM 
%token <none> DOWNTO_SYM 
%token <none> ELSEIF_SYM 
%token <none> ELSE_SYM 
%token <none> END_SYM 
%token <none> EQ_SYM 
%token <none> FOR_SYM 
%token <none> FORWARD_SYM
%token <none> FUNCTION_SYM 
%token <none> GTE_SYM
%token <none> GT_SYM 
%token <strVal> IDENT_SYM
%token <none> IF_SYM
%token <intVal> INT_SYM 
%token <none> LBRACKET_SYM 
%token <none> LPAREN_SYM 
%token <none> LTE_SYM
%token <none> LT_SYM 
%token <none> MINUS_SYM 
%token <none> MOD_SYM 
%token <none> MULT_SYM
%token <none> NOT_SYM 
%token <none> OF_SYM
%token <none> ORD_SYM
%token <none> PLUS_SYM 
%token <none> PRED_SYM 
%token <none> PROCEDURE_SYM 
%token <none> RBRACKET_SYM
%token <none> READ_SYM 
%token <none> RECORD_SYM 
%token <none> REF_SYM
%token <none> REPEAT_SYM 
%token <none> RETURN_SYM 
%token <none> RPAREN_SYM 
%token <none> SEMICOLON_SYM 
%token <none> STOP_SYM 
%token <strVal> STRING_SYM 
%token <none> SUCC_SYM
%token <none> THEN_SYM 
%token <none> TO_SYM 
%token <none> TYPE_SYM 
%token <none> UNTIL_SYM 
%token <none> VAR_SYM 
%token <none> WHILE_SYM 
%token <none> WRITE_SYM


%left AND_SYM OR_SYM ASSIGN_SYM
%right NOT_SYM
%left PLUS_SYM MINUS_SYM
%left DIV_SYM MOD_SYM MULT_SYM
%nonassoc EQ_SYM LTE_SYM GTE_SYM GT_SYM LT_SYM NEQ_SYM
%right UMINUS_SYM



 /* Types */
%type <expr> Expression LValue Statement ForBegin ForIncGuts ForDecGuts
%type <typeList> RecordTypeDecls
%type <exprList> WriteArgs ReadArgs LValues 
%type <constVal> ConstExpression
%type <none> NullStatement Assignment ReadStatement WriteStatement Optional_ConstDecl Optional_ConstDecls
%type <identList> IdentList IdentLists
%type <typeVal> Type SimpleType
%type <recVal> RecordType
%type <arrVal> ArrayType

%start Program

%%


Program : ProgramStart Block DOT_SYM 
	    {
			std::cout<<"in parser.y"<<std::endl;
			SymbolTable::getInstance()->popScope();
			SymbolTable::getInstance()->popScope();
			SymbolTable::getInstance()->emitEnd();
		} 
		;

ProgramStart : ConstDecl TypeDecl VarDecl Optional_ProcOrFuncDecls { ProgramStart();}
			 ;

ConstDecl :
		  | CONST_SYM ConstDecls IDENT_SYM EQ_SYM ConstExpression SEMICOLON_SYM
		  {
			$5->name = $3;
			SymbolTable::getInstance()->addSymbol($3,*$5,true);
		  }
		  ;

ConstDecls : ConstDecls IDENT_SYM EQ_SYM ConstExpression SEMICOLON_SYM
		   {
				$4->name = $2;
				SymbolTable::getInstance()->addSymbol($2,*$4,true);
		   }
           |  
           ;

Optional_ProcOrFuncDecls : Optional_ProcOrFuncDecls ProcedureDecl 
                         | Optional_ProcOrFuncDecls FunctionDecl 
                         | 
                         ;

ProcedureDecl : PROCEDURE_SYM IDENT_SYM LPAREN_SYM Optional_FormalParameters RPAREN_SYM SEMICOLON_SYM FORWARD_SYM SEMICOLON_SYM {std::cout<<"Empty"<<std::endl;}
              | PROCEDURE_SYM IDENT_SYM LPAREN_SYM Optional_FormalParameters RPAREN_SYM SEMICOLON_SYM Body SEMICOLON_SYM {std::cout<<"Empty"<<std::endl;} 
              ;

FunctionDecl : FUNCTION_SYM IDENT_SYM LPAREN_SYM Optional_FormalParameters RPAREN_SYM COLON_SYM Type SEMICOLON_SYM FORWARD_SYM SEMICOLON_SYM {std::cout<<"Empty"<<std::endl;}
             | FUNCTION_SYM IDENT_SYM LPAREN_SYM Optional_FormalParameters RPAREN_SYM COLON_SYM Type SEMICOLON_SYM Body SEMICOLON_SYM {std::cout<<"Empty"<<std::endl;}
             ;

Optional_FormalParameters : FormalParameters {std::cout<<"optinal formal params\n";}
                          | {std::cout<<"Empty"<<std::endl;}
                          ;

FormalParameters : FormalParameter {std::cout<<"Empty"<<std::endl;}
				 | FormalParameters SEMICOLON_SYM FormalParameter {std::cout<<"Empty"<<std::endl;}
                 ;

FormalParameter : Optional_Var IdentList COLON_SYM Type {std::cout<<"Empty"<<std::endl;}
                ;

Optional_Var : VAR_SYM {std::cout<<"Empty"<<std::endl;}
             | REF_SYM {std::cout<<"Empty"<<std::endl;}
             | {std::cout<<"Empty"<<std::endl;}
             ;


Body : Optional_ConstDecl TypeDecl VarDecl Block
     ;

Optional_ConstDecl :
				   | CONST_SYM Optional_ConstDecls IDENT_SYM EQ_SYM ConstExpression SEMICOLON_SYM 
				   {
						$5->name=$3;
						SymbolTable::getInstance()->addSymbol($3, *$5, true);
				   }
				   ;

Optional_ConstDecls :
					| Optional_ConstDecls IDENT_SYM EQ_SYM ConstExpression SEMICOLON_SYM
					{
						$4->name=$2;
						SymbolTable::getInstance()->addSymbol($2, *$4, true);
					}
					;

Block : BEGIN_SYM StatementSequence END_SYM 
      ;

Optional_TypeDecls : TYPE_SYM TypeDecls
                   |
                   ;

TypeDecl :    
		 | TYPE_SYM TypeDecls IDENT_SYM EQ_SYM Type SEMICOLON_SYM{ TypeDeclaration($3, $5);	}
         ;
		 
TypeDecls :
		  | TypeDecls IDENT_SYM EQ_SYM Type SEMICOLON_SYM {TypeDeclaration($2, $4);}        
          ;

Type : SimpleType {$<typeVal>$=$1;}
     | RecordType { addRecord($1); $<recVal>$=$1;}
     | ArrayType { addArray_Type($1); $<arrVal>$=$1;}
     ;

SimpleType : IDENT_SYM { $$ = newSimpleType($1);}
           ;

RecordType : RECORD_SYM RecordTypeDecls END_SYM { $$ = new Record(*$2);}
           ;
		   
RecordTypeDecls : {  $$=new std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>>();}
				| RecordTypeDecls IdentList COLON_SYM Type SEMICOLON_SYM 
				{
					$1->push_back(std::make_pair(*$2, std::make_shared<Type>(*$4)));
					$$=$1;
				}
				;
		   
ArrayType : ARRAY_SYM LBRACKET_SYM ConstExpression COLON_SYM ConstExpression RBRACKET_SYM OF_SYM Type{$$ = new Array_Type($8, *$3, *$5);}
          ;

IdentList : IdentLists IDENT_SYM
		  {
			std::cout<<"ident list"<<std::endl;
			$1->push_back($2);
			$$=$1;
		  }
          ;
		  
IdentLists : 
		   {
			 $$ = new std::vector<std::string>();
		   }
		   | IdentLists IDENT_SYM COMMA_SYM 
		   {
		    std::cout<<"ident lists"<<std::endl;
			$1->push_back($2);
			$$=$1;
		   } 
		   ;

VarDecl : 
	    | VAR_SYM VarDecls IdentList COLON_SYM Type SEMICOLON_SYM
	    {
			std::cout<<"found a var"<<std::endl;
			std::for_each($3->begin(), $3->end(), [&](std::string val)
			{
				if(!SymbolTable::getInstance()->lookup($5->name))
				{
					VariableDeclaration($3, $5, val);
				}
				Var var(*$5, SymbolTable::getInstance()->offset.back(), val);
				SymbolTable::getInstance()->offset.back()+=$5->size;
				SymbolTable::getInstance()->addSymbol(val, var, true);
			});
		}
		;
		  
VarDecls :
         | VarDecls IdentList COLON_SYM Type SEMICOLON_SYM{
			std::cout<<"Found Var"<<std::endl;
			std::for_each($2->begin(), $2->end(),[&](std::string val)
			{
				MoreVariableDeclarations($4, val);
			});
	     }
		 ;
		 
FieldDecls : FieldDecls FieldDecl {std::cout<<"Empty"<<std::endl;}
           | {std::cout<<"Empty"<<std::endl;}
           ;

FieldDecl : IdentList COLON_SYM Type SEMICOLON_SYM {std::cout<<"Empty"<<std::endl;}
          ;
		
		
 /* CPSL Statements */
StatementSequence : StatementSequences Statement 
                  ;

StatementSequences :
				   | StatementSequences Statement SEMICOLON_SYM

Statement : Assignment 		{ SymbolTable::getInstance()->clearReg();}
          | IfStatement 	{ SymbolTable::getInstance()->clearReg();}
          | WhileStatement 	{ SymbolTable::getInstance()->clearReg();}
          | RepeatStatement { SymbolTable::getInstance()->clearReg();}
          | ForStatement 	{ SymbolTable::getInstance()->clearReg();}
          | StopStatement 	{ SymbolTable::getInstance()->clearReg();}
          | ReturnStatement { SymbolTable::getInstance()->clearReg();}
          | ReadStatement 	{ SymbolTable::getInstance()->clearReg();}
          | WriteStatement 	{ SymbolTable::getInstance()->clearReg();}
          | ProcedureCall 	{ SymbolTable::getInstance()->clearReg();}
		  | Expression		{ $$ = $1;}
          | NullStatement   { SymbolTable::getInstance()->clearReg();}
          ;

Assignment : LValue ASSIGN_SYM Expression 
           {
		     create($1, $3);
			 std::cout<<"after Assignment create()"<<std::endl;
		   }
           ;

IfStatement : IfHead ElseIfList ElseClause END_SYM 
			{
			   endIf();
			}
            ;

IfHead : IfBegin THEN_SYM StatementSequence 
       {
      	   ifBranchEnd();
	   }
	   ;

IfBegin : IF_SYM Expression
		{
		   ifBegin();
		   ifBranch($2);
		}
        ;

ElseIfList : 
		   | ElseIfList ElseIfHead THEN_SYM StatementSequence
		   {
		      ifBranchEnd();
		   }
           ;

ElseIfHead : ElseBegin Expression 
		   {
		      ifBranch($2);
		   }
           ;
		   
ElseBegin : ELSEIF_SYM
		  {
		     labelIfBranch();
		  }
		  ;

ElseClause : 
		   | ElseStart StatementSequence 
		   {
		      ifBranchEnd();
		   }
           ;
	 
ElseStart : ELSE_SYM 
		  {
			labelIfBranch();
		  }

WhileStatement : WhileHead DO_SYM StatementSequence END_SYM 
			   {
			      loopEnd();
			   }
               ;

WhileBegin : WHILE_SYM
		   {
		      loopBegin();
		   }
		   ;

WhileHead : WhileBegin Expression 
		  {
		     whileStmt($2,true);
		  }
          ;

RepeatStatement : RepeatStatementMiddle UNTIL_SYM Expression 
				{
				   std::cout<<"RepeatStatement ending"<<std::endl;
				   repeatStmt($3);
				}
                ;
			
RepeatStatementMiddle : RepeatStatementBegin StatementSequence
					  ;

RepeatStatementBegin : REPEAT_SYM
					 {
						std::cout<<"RepeatStatementBegin"<<std::endl;
					    loopBegin();
					 }
					 ;

ForStatement : ForInc
			 | ForDec
			 ;

ForInc : ForIncGuts DO_SYM StatementSequence END_SYM
	   {
	      create($1, AddExpr($1,(new Expression(1,Expression::intType,true))));
	      loopEnd();
	   }
	   ;


ForIncGuts : ForBegin TO_SYM Expression
		   {
		     forStmt(GtExpr($1,$3));
		     $$ = $1;
		   }
		   ;
		
ForDec : ForDecGuts DO_SYM StatementSequence END_SYM
	   {
	      create($1, SubExpr($1,(new Expression(1, Expression::intType,true))));
	      loopEnd();
	   }
	   ;
	 
ForDecGuts : ForBegin DOWNTO_SYM Expression
		   {
		     forStmt(LtExpr($1,$3));
		     $$ = $1;
		   }
		   ;
		   
ForBegin : FOR_SYM IDENT_SYM ASSIGN_SYM Expression
		 {
		    auto newExpr = new Expression(std::string($2),Expression::stringType);
			auto newExprVec = new std::vector<Expression>();
			
			newExprVec->push_back(*newExpr);
			auto temp = genLValue(*newExprVec);
			
			create(temp,$4);
			loopBegin();
			$$ = temp;
		 }
		 ;

ToHead : TO_SYM Expression {std::cout<<"Empty"<<std::endl;}
       | DOWNTO_SYM Expression {std::cout<<"Empty"<<std::endl;}
       ;

StopStatement : STOP_SYM {std::cout<<"Empty"<<std::endl;}
              ;

ReturnStatement : RETURN_SYM Expression {std::cout<<"Empty"<<std::endl;}
                | RETURN_SYM 
                ;


ReadStatement : READ_SYM LPAREN_SYM ReadArgs LValue RPAREN_SYM 
			  {
			    std::cout<<"finished read statement"<<std::endl;
				$3->push_back(*$4);
				readStmt(*$3);
			  }
              ;

ReadArgs : {$$ = new std::vector<Expression>();}
		 | ReadArgs LValue COMMA_SYM
		 {
			$1->push_back(*$2);
			$$ = $1;
		 }
         ;

WriteStatement : WRITE_SYM LPAREN_SYM WriteArgs Expression RPAREN_SYM 
               {
				  std::cout<<"finished write statement"<<std::endl;
			      $3->push_back(*$4);
				  writeStmt(*$3);
			   }
               ;

WriteArgs :
	      {
			 std::cout<<"WriteArgs, new vector"<<std::endl;
		     $$ = new std::vector<Expression>();
		  }
          | WriteArgs Expression COMMA_SYM 
		  {
			 std::cout<<"WriteArgs, pushing another back"<<std::endl;
			 $1->push_back(*$2);
			 $$ = $1;
		  }
          ;

ProcedureCall : IDENT_SYM LPAREN_SYM Optional_Arguments RPAREN_SYM {std::cout<<"Empty"<<std::endl;}
              ;

Optional_Arguments : Arguments {std::cout<<"Empty"<<std::endl;}
           | {std::cout<<"Empty"<<std::endl;}
           ;
 
Arguments : Arguments COMMA_SYM Expression {std::cout<<"Empty"<<std::endl;}
          | Expression {std::cout<<"Empty"<<std::endl;}
          ;

Expression : LValue									    {$$=$1;}
           | Expression AND_SYM Expression         		{$$ = AndExpr($1,$3);}
           | Expression DIV_SYM Expression         		{$$ = DivExpr($1,$3);}
           | Expression EQ_SYM Expression          		{$$ = EqExpr($1,$3);}
           | Expression GTE_SYM Expression         		{$$ = GteExpr($1,$3);}
           | Expression GT_SYM Expression         		{$$ = GtExpr($1,$3);}
           | Expression LTE_SYM Expression         		{$$ = LteExpr($1,$3);}
           | Expression LT_SYM Expression          		{$$ = LtExpr($1,$3);}
           | Expression MINUS_SYM Expression       		{$$ = SubExpr($1,$3);}
           | Expression MOD_SYM Expression         		{$$ = ModExpr($1,$3);}
           | Expression MULT_SYM Expression        		{$$ = MultExpr($1,$3);}
           | Expression NEQ_SYM Expression         		{$$ = NeqExpr($1,$3);}
           | Expression OR_SYM Expression          		{$$ = OrExpr($1,$3);}
           | Expression PLUS_SYM Expression        		{{$$ = AddExpr($1,$3);}std::cout<<"after PlusExpression"<<std::endl;}
		   | INT_SYM 									{$$ = IntExpr($1);}
		   | CHAR_SYM 									{{$$ = CharExpr($1);}std::cout<<"after charexpr"<<std::endl;}
		   | STRING_SYM									{$$ = StrExpr($1);}
           | FunctionCall                      			{} 
           | LPAREN_SYM Expression RPAREN_SYM          {{std::cout<<"( exp )"<<std::endl;}$$=$2;}
           | MINUS_SYM Expression %prec UMINUS_SYM      {std::cout<<"Empty"<<std::endl;}
           | NOT_SYM Expression                    		{std::cout<<"Empty"<<std::endl;}
           | ORD_SYM LPAREN_SYM Expression RPAREN_SYM   
           | PRED_SYM LPAREN_SYM Expression RPAREN_SYM	
           | SUCC_SYM LPAREN_SYM Expression RPAREN_SYM  
		   | CHR_SYM LPAREN_SYM Expression RPAREN_SYM
           ;

		   
ConstExpression : INT_SYM                                   {$$ = new Constant($1);}
				| CHAR_SYM									{$$ = new Constant($1[1]);}
				| STRING_SYM								{$$ = new Constant(std::string($1),std::string($1));}
				| IDENT_SYM									{$$ = new Constant(std::string($1),Constant::identType);}
			    | ConstExpression AND_SYM ConstExpression	{$$ = ConstAndExpr(*$1,*$3);}
			    | ConstExpression DIV_SYM ConstExpression   {$$ = ConstDivExpr(*$1,*$3);}
			    | ConstExpression EQ_SYM ConstExpression    {$$ = ConstEqExpr(*$1,*$3);}
			    | ConstExpression GTE_SYM ConstExpression   {$$ = ConstGteExpr(*$1,*$3);}
			    | ConstExpression GT_SYM ConstExpression    {$$ = ConstGtExpr(*$1,*$3);}
			    | ConstExpression LTE_SYM ConstExpression   {$$ = ConstLteExpr(*$1,*$3);}
			    | ConstExpression LT_SYM ConstExpression    {$$ = ConstLtExpr(*$1,*$3);}
			    | ConstExpression MINUS_SYM ConstExpression {$$ = ConstSubExpr(*$1,*$3);}
			    | ConstExpression MOD_SYM ConstExpression   {$$ = ConstModExpr(*$1,*$3);}
			    | ConstExpression MULT_SYM ConstExpression  {$$ = ConstMultExpr(*$1,*$3);}
			    | ConstExpression NEQ_SYM ConstExpression   {$$ = ConstNeqExpr(*$1,*$3);}
			    | ConstExpression OR_SYM ConstExpression    {$$ = ConstOrExpr(*$1,*$3);}
			    | ConstExpression PLUS_SYM ConstExpression  {$$ = ConstAddExpr(*$1,*$3);}
				| LPAREN_SYM ConstExpression RPAREN_SYM     {$$ = $2;}
				| NOT_SYM ConstExpression                   {$$ = ConstNotExpr(*$2);}
				| MINUS_SYM ConstExpression %prec UMINUS_SYM{$$ = ConstUminusExpr(*$2);}
			    ;
   
FunctionCall : IDENT_SYM LPAREN_SYM Optional_Arguments RPAREN_SYM {std::cout<<"Empty"<<std::endl;}
             ;

LValue : IDENT_SYM LValues
	   {
		  std::cout<<"***LValue"<<std::endl;
	      auto temp = new Expression(std::string($1), Expression::stringType);
		  $2->push_back(*temp);
		  std::reverse($2->begin(), $2->end());
		  $$ = genLValue(*$2);
	   }
	   ;

LValues : {$$ = new std::vector<Expression>();}
		| DOT_SYM IDENT_SYM LValues
		{
			std::cout<<"LValues"<<std::endl;
			auto temp = new Expression(std::string($2), Expression::stringType);
			$3->push_back(*temp);
			$$ = $3;
		}
		| LBRACKET_SYM Expression RBRACKET_SYM LValues 
		{
			std::cout<<"LValues"<<std::endl;
			$4->push_back(*$2);
			$$=$4;
		}
		;

NullStatement :
			  ;
%%

void yyerror(const char* msg)
{
	std::cout<<"ERROR! "<< msg << " "<<num_lines<<std::endl;
}




