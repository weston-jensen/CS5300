 %{
#include "Globals.h"
#include <iostream>
#include <fstream>

extern int yyparse();
extern int yylex();
extern int yylineno;
extern char* yytext;
//extern int num_lines;
void yyerror(const char*);
%}

 /* TOKENS */
%error-verbose
%token ARRAY_SYM
%token ASSIGN_SYM 
%token BEGIN_SYM
%token CHARCONST_SYM
%token CHR_SYM
%token COLON_SYM
%token COMMA_SYM 
%token CONST_SYM 
%token DIV_SYM 
%token DO_SYM 
%token DOT_SYM 
%token DOWNTO_SYM 
%token ELSEIF_SYM 
%token ELSE_SYM 
%token END_SYM 
%token EQ_SYM 
%token FOR_SYM 
%token FORWARD_SYM
%token FUNCTION_SYM 
%token GTE_SYM
%token GT_SYM 
%token IDENT_SYM
%token IF_SYM
%token INT_SYM 
%token LBRACKET_SYM 
%token LPAREN_SYM 
%token LTE_SYM
%token LT_SYM 
%token MINUS_SYM 
%token MOD_SYM 
%token MULT_SYM
%token NOT_SYM 
%token OF_SYM
%token ORD_SYM
%token PLUS_SYM 
%token PRED_SYM 
%token PROCEDURE_SYM 
%token RBRACKET_SYM
%token READ_SYM 
%token RECORD_SYM 
%token REF_SYM
%token REPEAT_SYM 
%token RETURN_SYM 
%token RPAREN_SYM 
%token SEMICOLON_SYM 
%token STOP_SYM 
%token STRING_SYM 
%token SUCC_SYM
%token THEN_SYM 
%token TO_SYM 
%token TYPE_SYM 
%token UNTIL_SYM 
%token VAR_SYM 
%token WHILE_SYM 
%token WRITE_SYM

%left AND_SYM OR_SYM
%right NOT_SYM
%left PLUS_SYM MINUS_SYM
%left DIV_SYM MOD_SYM MULT_SYM
%nonassoc EQ_SYM LTE_SYM GTE_SYM GT_SYM LT_SYM NEQ_SYM
%right UMINUS_SYM


%%
Program : ProgramStart Block DOT_SYM {std::cout<<"*Program"<<std::endl;} ;

ProgramStart : optional_ConstDecls optional_TypeDecls optional_VarDecls optional_ProcOrFuncDecls ;

optional_ConstDecls : CONST_SYM ConstDecls
           			| 
					;

ConstDecls : ConstDecls ConstDecl 
           | ConstDecl 
           ;


ConstDecl : IDENT_SYM EQ_SYM Expression SEMICOLON_SYM {std::cout<<"*ConstDecl"<<std::endl;}
          ;

optional_ProcOrFuncDecls : optional_ProcOrFuncDecls ProcedureDecl 
                         | optional_ProcOrFuncDecls FunctionDecl 
                         | 
                         ;

ProcedureDecl : PROCEDURE_SYM IDENT_SYM LPAREN_SYM optional_FormalParameters RPAREN_SYM SEMICOLON_SYM FORWARD_SYM SEMICOLON_SYM {std::cout<<"*ProcedureDecl Forward"<<std::endl;}
              | PROCEDURE_SYM IDENT_SYM LPAREN_SYM optional_FormalParameters RPAREN_SYM SEMICOLON_SYM Body SEMICOLON_SYM {std::cout<<"ProcedureDecl Body"<<std::endl;} 
              ;

FunctionDecl : FUNCTION_SYM IDENT_SYM LPAREN_SYM optional_FormalParameters RPAREN_SYM COLON_SYM Type SEMICOLON_SYM FORWARD_SYM SEMICOLON_SYM {std::cout<<"*FunctionDecl"<<std::endl;}
             | FUNCTION_SYM IDENT_SYM LPAREN_SYM optional_FormalParameters RPAREN_SYM COLON_SYM Type SEMICOLON_SYM Body SEMICOLON_SYM {std::cout<<"*FunctionDecl"<<std::endl;}
             ;

optional_FormalParameters : FormalParameters {std::cout<<"*optional_FormalParameters"<<std::endl;}
                          | {std::cout<<"*optional_FormalParameters Empty"<<std::endl;}
                          ;

FormalParameters : FormalParameter {std::cout<<"*Empty FormalParameters"<<std::endl;}
				 | FormalParameters SEMICOLON_SYM FormalParameter {std::cout<<"*FormalParameters"<<std::endl;}
                 ;
FormalParameter : optional_Var IdentList COLON_SYM Type {std::cout<<"*FormalParameter"<<std::endl;}
                ;

optional_Var : VAR_SYM {std::cout<<"*Function VAR"<<std::endl;}
             | REF_SYM {std::cout<<"*Function REF"<<std::endl;}
             | {std::cout<<"*Function Nothing"<<std::endl;}
             ;


Body : optional_ConstDecls optional_TypeDecls optional_VarDecls Block {std::cout<<"*Body"<<std::endl;}
     ;

Block : BEGIN_SYM StatementSequence END_SYM {std::cout<<"*Block"<<std::endl;}
      ;

optional_TypeDecls : TYPE_SYM TypeDecls
                   |
                   ;

TypeDecls : TypeDecls TypeDecl
          | TypeDecl
          ;

TypeDecl : IDENT_SYM EQ_SYM Type SEMICOLON_SYM {std::cout<<"*TypeDecl"<<std::endl;}
         ;

Type : SimpleType {std::cout<<"*Type: SimpleType"<<std::endl;}
     | RecordType {std::cout<<"*Type: RecordType"<<std::endl;}
     | ArrayType {std::cout<<"*Type: ARRAY_SYMType"<<std::endl;}
     ;

SimpleType : IDENT_SYM {std::cout<<"*SimpleType"<<std::endl;}
           ;

RecordType : RECORD_SYM FieldDecls END_SYM {std::cout<<"*RecordType"<<std::endl;}
           ;

FieldDecls : FieldDecls FieldDecl {std::cout<<"*FieldDecls FieldDecl"<<std::endl;}
           | {std::cout<<"*FieldDeclEmpty"<<std::endl;}
           ;

FieldDecl : IdentList COLON_SYM Type SEMICOLON_SYM {std::cout<<"*FieldDecl"<<std::endl;}
          ;

IdentList : IdentList COMMA_SYM IDENT_SYM {std::cout<<"*IdentList , Ident"<<std::endl;}
          | IDENT_SYM {std::cout<<"*IdentList Ident"<<std::endl;}
          ;

ArrayType : ARRAY_SYM LBRACKET_SYM Expression COLON_SYM Expression RBRACKET_SYM OF_SYM Type {std::cout<<"*ArrayType"<<std::endl;}
          ;

 /* Variable Declarations */
optional_VarDecls : VAR_SYM VarDecls
                  |
                  ;

VarDecls : VarDecls VarDecl
         | VarDecl
         ;

VarDecl : IdentList COLON_SYM Type SEMICOLON_SYM {std::cout<<"*VarDecl"<<std::endl;}
        ;

 /* CPSL Statements */
StatementSequence : StatementSequence SEMICOLON_SYM Statement {std::cout<<"*StatementSeq ; Statement"<<std::endl;}
                  | Statement {std::cout<<"*StatementSeq"<<std::endl;}
                  ;

Statement : Assignment {std::cout<<"*Stm: Assignment"<<std::endl;}
          | IfStatement {std::cout<<"*Stm: If"<<std::endl;}
          | WhileStatement {std::cout<<"*Stm: While"<<std::endl;}
          | RepeatStatement {std::cout<<"*Stm: Repeat"<<std::endl;}
          | ForStatement {std::cout<<"*Stm: For"<<std::endl;}
          | StopStatement {std::cout<<"*Stm: Stop"<<std::endl;}
          | ReturnStatement {std::cout<<"*Stm: Return"<<std::endl;}
          | ReadStatement {std::cout<<"*Stm: Read"<<std::endl;}
          | WriteStatement {std::cout<<"*Stm: Write"<<std::endl;}
          | ProcedureCall {std::cout<<"*Stm: Procedure"<<std::endl;}
          | {std::cout<<"*Stm: NullStatement"<<std::endl;}
          ;

Assignment : LValue ASSIGN_SYM Expression {std::cout<<"*Assignment"<<std::endl;}
           ;

IfStatement : IfHead ThenPart ElseIfList ElseClause END_SYM {std::cout<<"*IfStatement"<<std::endl;}
            ;

IfHead : IF_SYM Expression {std::cout<<"*IfHead"<<std::endl;}
       ;

ThenPart : THEN_SYM StatementSequence {std::cout<<"*ThenPart"<<std::endl;}
         ;

ElseIfList : ElseIfList ElseIfHead ThenPart {std::cout<<"*ElseIfList"<<std::endl;}
           | {std::cout<<"*ElseIfList empty"<<std::endl;}
           ;

ElseIfHead : ELSEIF_SYM Expression {std::cout<<"*ElseIfHead"<<std::endl;}
           ;

ElseClause : ELSE_SYM StatementSequence {std::cout<<"*ElseClause"<<std::endl;}
           | {std::cout<<"*ElseClause"<<std::endl;}
           ;

WhileStatement : WhileHead DO_SYM StatementSequence END_SYM {std::cout<<"*WhileStatement"<<std::endl;}
               ;

WhileHead : WHILE_SYM Expression {std::cout<<"*WhileHead"<<std::endl;}
          ;

RepeatStatement : REPEAT_SYM StatementSequence UNTIL_SYM Expression {std::cout<<"*RepeatStatement"<<std::endl;}
                ;

ForStatement : ForHead ToHead DO_SYM StatementSequence END_SYM{std::cout<<"*ForStatement"<<std::endl;}
             ;

ForHead : FOR_SYM IDENT_SYM ASSIGN_SYM Expression {std::cout<<"*ForHead"<<std::endl;}
        ;

ToHead : TO_SYM Expression {std::cout<<"*ToHead To"<<std::endl;}
       | DOWNTO_SYM Expression {std::cout<<"*ToHead Downto"<<std::endl;}
       ;

StopStatement : STOP_SYM {std::cout<<"*StopStatement"<<std::endl;}
              ;

ReturnStatement : RETURN_SYM Expression {std::cout<<"*ReturnStatement"<<std::endl;}
                | RETURN_SYM {std::cout<<"*Return empty"<<std::endl;}
                ;


ReadStatement : READ_SYM LPAREN_SYM ReadArgs RPAREN_SYM {std::cout<<"*ReadStatement"<<std::endl;}
              ;

ReadArgs : ReadArgs COMMA_SYM LValue {std::cout<<"*ReadArgs , LVal"<<std::endl;}
         | LValue {std::cout<<"*ReadArgs LVal"<<std::endl;}
         ;

WriteStatement : WRITE_SYM LPAREN_SYM WriteArgs RPAREN_SYM {std::cout<<"*WriteStatement"<<std::endl;}
               ;

WriteArgs : WriteArgs COMMA_SYM Expression {std::cout<<"*WriteArgs , exp"<<std::endl;}
          | Expression {std::cout<<"*WriteArgs Exp"<<std::endl;}
          ;

ProcedureCall : IDENT_SYM LPAREN_SYM optional_Arguments RPAREN_SYM {std::cout<<"*ProcedureCall"<<std::endl;}
              ;

optional_Arguments : Arguments {std::cout<<"*optional_Arguments"<<std::endl;}
           | {std::cout<<"*optional_Arguments Empty"<<std::endl;}
           ;
 
Arguments : Arguments COMMA_SYM Expression {std::cout<<"*Arguments , exp"<<std::endl;}
          | Expression {std::cout<<"*Arguments exp"<<std::endl;}
          ;

Expression : CHARCONST_SYM								{std::cout<<"*charconst"<<std::endl;}
           | CHR_SYM LPAREN_SYM Expression RPAREN_SYM   {std::cout<<"*char (exp)"<<std::endl;}
           | Expression AND_SYM Expression         		{std::cout<<"*exp & exp"<<std::endl;}
           | Expression DIV_SYM Expression         		{std::cout<<"*exp / exp"<<std::endl;}
           | Expression EQ_SYM Expression          		{std::cout<<"*exp = exp"<<std::endl;}
           | Expression GTE_SYM Expression         		{std::cout<<"*exp >= exp"<<std::endl;}
           | Expression GT_SYM Expression         		{std::cout<<"*exp > exp"<<std::endl;}
           | Expression LTE_SYM Expression         		{std::cout<<"*exp <= exp"<<std::endl;}
           | Expression LT_SYM Expression          		{std::cout<<"*exp < exp"<<std::endl;}
           | Expression MINUS_SYM Expression       		{std::cout<<"*exp -  exp"<<std::endl;}
           | Expression MOD_SYM Expression         		{std::cout<<"*exp precent exp"<<std::endl;}
           | Expression MULT_SYM Expression        		{std::cout<<"*exp * exp"<<std::endl;}
           | Expression NEQ_SYM Expression         		{std::cout<<"*exp != exp"<<std::endl;}
           | Expression OR_SYM Expression          		{std::cout<<"*exp | exp"<<std::endl;}
           | Expression PLUS_SYM Expression        		{std::cout<<"*exp + exp"<<std::endl;}
           | FunctionCall                      			{std::cout<<"*functionCall"<<std::endl;}
           | INT_SYM                               		{std::cout<<"*Int"<<std::endl;}
           | LPAREN_SYM Expression RPAREN_SYM           {std::cout<<"*( exp )"<<std::endl;}
           | LValue                            			{std::cout<<"*LValue"<<std::endl;}
           | MINUS_SYM Expression %prec UMINUS_SYM      {std::cout<<"*Unary Minus "<<std::endl;}
           | NOT_SYM Expression                    		{std::cout<<"*~ exp"<<std::endl;}
           | ORD_SYM LPAREN_SYM Expression RPAREN_SYM   {std::cout<<"*| ( exp )"<<std::endl;}
           | PRED_SYM LPAREN_SYM Expression RPAREN_SYM	{std::cout<<"*&( exp )"<<std::endl;}
           | STRING_SYM                          		{std::cout<<"*String"<<std::endl;}
           | SUCC_SYM LPAREN_SYM Expression RPAREN_SYM      {std::cout<<"*Succ( exp )"<<std::endl;}
           ;
   
FunctionCall : IDENT_SYM LPAREN_SYM optional_Arguments RPAREN_SYM {std::cout<<"*FunctionCall"<<std::endl;}
             ;

LValue : LValue DOT_SYM IDENT_SYM {std::cout<<"*LValue"<<std::endl;}
       | LValue LBRACKET_SYM Expression RBRACKET_SYM {std::cout<<"*LValue"<<std::endl;}
       | IDENT_SYM {std::cout<<"*LValue"<<std::endl;}
       ;


%%

int main(void)
{
	yyparse();
}

void yyerror(const char* msg)
{
	std::cout<<"ERROR! "<< msg << " Line: "<< num_lines <<std::endl;
}


