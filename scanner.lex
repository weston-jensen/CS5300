%{
#include "Expressions.hpp"
#include "Constant.hpp"
#include "Type.hpp"
#include "TreeParser.hpp"
#include "parser.hpp"
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
bool debug = true;
int num_lines=1;
#define YY_DECL extern int yylex()
%}

%option noyywrap
%option yylineno

%%
 /* Keywords */
array|ARRAY {if(debug){std::cout<<"*ARRAY"<<std::endl;}return ARRAY_SYM;}
begin|BEGIN {if(debug){std::cout<<"*BEGIN"<<std::endl;}return BEGIN_SYM;}
chr|CHR {if(debug){std::cout<<"*CHR"<<std::endl;}return CHR_SYM;}
const|CONST {if(debug){std::cout<<"*CONST"<<std::endl;}return CONST_SYM;}
do|DO {if(debug){std::cout<<"*DO"<<std::endl;}return DO_SYM; }
downto|DOWNTO {if(debug){std::cout<<"*DOWNTO"<<std::endl;}return DOWNTO_SYM; }
else|ELSE {if(debug){std::cout<<"*ELSE"<<std::endl;}return ELSE_SYM;}
elseif|ELSEIF {if(debug){std::cout<<"*ELSEIF"<<std::endl;}return ELSEIF_SYM; }
end|END { if(debug){std::cout<<"**END**"<<std::endl;}return END_SYM; }
for|FOR { if(debug){std::cout<<"*FOR"<<std::endl;}return FOR_SYM; }
forward|FORWARD {if(debug){std::cout<<"*FORWARD"<<std::endl;} return FORWARD_SYM; }
function|FUNCTION {if(debug){std::cout<<"*FUNCTION"<<std::endl;}return FUNCTION_SYM;  }
if|IF { if(debug){std::cout<<"*IF"<<std::endl;}return IF_SYM; }
of|OF {if(debug){std::cout<<"*OF"<<std::endl;} return OF_SYM; }
ord|ORD {if(debug){std::cout<<"*ORD"<<std::endl;} return ORD_SYM; }
pred|PRED {if(debug){std::cout<<"*PRED"<<std::endl;} return PRED_SYM; }
procedure|PROCEDURE {if(debug){std::cout<<"*PROCEDURE"<<std::endl;} return PROCEDURE_SYM; }
read|READ { if(debug){std::cout<<"*READ"<<std::endl;}return READ_SYM; }
record|RECORD { if(debug){std::cout<<"*RECORD"<<std::endl;}return RECORD_SYM; }
ref|REF { if(debug){std::cout<<"*REF"<<std::endl;}return REF_SYM; }
repeat|REPEAT { if(debug){std::cout<<"*REPEAT"<<std::endl;}return REPEAT_SYM; }
return|RETURN { if(debug){std::cout<<"*RETURN"<<std::endl;}return RETURN_SYM; }
stop|STOP { if(debug){std::cout<<"*STOP"<<std::endl;}return STOP_SYM; }
succ|SUCC { if(debug){std::cout<<"*SUCC"<<std::endl;}return SUCC_SYM;}
then|THEN { if(debug){std::cout<<"*THEN"<<std::endl;}return THEN_SYM; }
to|TO { if(debug){std::cout<<"*TO"<<std::endl;}return TO_SYM; }
type|TYPE { if(debug){std::cout<<"*TYPE"<<std::endl;}return TYPE_SYM; }
(until)|(UNTIL) { if(debug){std::cout<<"*UNTIL***********"<<std::endl;}return UNTIL_SYM; }
var|VAR {if(debug){std::cout<<"*VAR"<<std::endl;} return VAR_SYM; }
while|WHILE { if(debug){std::cout<<"*WHILE"<<std::endl;}return WHILE_SYM; }
write|WRITE { if(debug){std::cout<<"*WRITE"<<std::endl;}return WRITE_SYM;}

 /* Operators */
"\+" {if(debug){std::cout<<"'+'"<<std::endl;} return PLUS_SYM; }
"-" {if(debug){std::cout<<"'-'"<<std::endl;} return MINUS_SYM; }
"\*" {if(debug){std::cout<<"'*'"<<std::endl;} return MULT_SYM; }
"/" {if(debug){std::cout<<"'/'"<<std::endl;} return DIV_SYM; }
"&" {if(debug){std::cout<<"'&'"<<std::endl;} return AND_SYM; }
"\|" {if(debug){std::cout<<"'|'"<<std::endl;} return OR_SYM; }
"~" {if(debug){std::cout<<"'~'"<<std::endl;} return NOT_SYM; }
"=" {if(debug){std::cout<<"'='"<<std::endl;} return EQ_SYM; }
"<>" {if(debug){std::cout<<"'<>'"<<std::endl;} return NEQ_SYM; }
"<" {if(debug){std::cout<<"'<'"<<std::endl;} return LT_SYM; }
"<=" {if(debug){std::cout<<"'<='"<<std::endl;} return LTE_SYM; }
">" {if(debug){std::cout<<"'>'"<<std::endl;} return GT_SYM;}
">=" {if(debug){std::cout<<"'>='"<<std::endl;} return GTE_SYM; }
"\." {if(debug){std::cout<<"'.'"<<std::endl;} return DOT_SYM; }
"," {if(debug){std::cout<<"','"<<std::endl;} return COMMA_SYM; }
":" {if(debug){std::cout<<"':'"<<std::endl;} return COLON_SYM; }
";" {if(debug){std::cout<<"';'"<<std::endl;} return SEMICOLON_SYM; }
"\(" {if(debug){std::cout<<"'('"<<std::endl;} return LPAREN_SYM; }
"\)" {if(debug){std::cout<<"')'"<<std::endl;} return RPAREN_SYM; } 
"[" {if(debug){std::cout<<"'['"<<std::endl;} return LBRACKET_SYM; }
"]" {if(debug){std::cout<<"']'"<<std::endl;}return RBRACKET_SYM; }
":=" {if(debug){std::cout<<"':='"<<std::endl;}return ASSIGN_SYM; }
"%" {if(debug){std::cout<<"'%'"<<std::endl;} return MOD_SYM; }

 /* Idents */
[a-zA-Z][a-zA-Z0-9_]* {if(debug){std::cout<<"Ident: "<<yytext<<std::endl;} yylval.strVal=strdup(yytext);return(IDENT_SYM);}

 /* Constants */
0[1-7][0-7]*	{if(debug){std::cout<<"INT_SYM\n";}yylval.intVal=strtol(yytext, &yytext, 8);return(INT_SYM);}
[1-9][0-9]*	{if(debug){std::cout<<"INT_SYM\n";}yylval.intVal=atoi(yytext);return(INT_SYM);}
0x[0-9a-fA-F]+	{if(debug){std::cout<<"INT_SYM\n";}yylval.intVal=strtol(yytext, &yytext, 16);return(INT_SYM);}
0 {if(debug){std::cout<<"INT_SYM\n";}yylval.intVal=0;return(INT_SYM);}

'\\n' {if(debug){std::cout<<"Char Const: "<<yytext<<std::endl;}yylval.strVal=strdup(yytext);return CHAR_SYM;}
'\\t' {if(debug){std::cout<<"Char Const: "<<yytext<<std::endl;}yylval.strVal=strdup(yytext);return CHAR_SYM;}
'\\r' {if(debug){std::cout<<"Char Const: "<<yytext<<std::endl;}yylval.strVal=strdup(yytext);return CHAR_SYM;}
'\\?.' {if(debug){std::cout<<"Char Const: "<<yytext<<std::endl;}yylval.strVal=strdup(yytext);return CHAR_SYM;}

\"[ -!#-~]*\"	{if(debug){std::cout<<"STRING_SYM\n";}yylval.strVal=strdup(yytext);return(STRING_SYM);}
\$[^\r\n]*	{}
[ \t]	{}

[a-zA-Z][a-zA-Z0-9_]* {if(debug){std::cout<<"IDENTIFIER_SYM\n";}yylval.strVal=strdup(yytext);return(IDENT_SYM);}

[\n\r] {num_lines++;}

. {std::cout<<"Unexpected token "<<+yytext<<std::endl;}

%%
