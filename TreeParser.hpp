#ifndef TREEPARSER_H
#define TREEPARSER_H
#include "Expressions.hpp"
#include "Type.hpp"
#include "Symbol.hpp"
#include "symbol_table.hpp"
#include "Record.hpp"
#include "Array_Type.hpp"
#include "Constant.hpp"
#include "Var.hpp"
#include <algorithm>



class Expression;
class Type;
class Array_Type;
class Record;
class Symbol;
//class SymbolTable;

/*ASM output only Functions*/
void ProgramStart();

/*Variable Assignment Functions*/
void VariableDeclaration(std::vector<std::string> *identList, Type *typeVal, std::string val);
void MoreVariableDeclarations(Type *typeVal, std::string val);

/*Type Declaration Function*/
void TypeDeclaration(char *strVal, Type *typeVal);
void addRecord(Record *recVal);
void addArray_Type(Array_Type *arrVal);
Type * newSimpleType(char *strVal);

/*Other*/
bool checkType(Constant &input, Constant::ConstType type);
bool isSameType(Constant &lhs, Constant &rhs);

/*Read/Write*/
void readStmt(std::vector<Expression> eList);
void writeStmt(std::vector<Expression> eList);

/*Control Loop Functions*/
void repeatStmt(Expression * cond);
void loopBegin();
void whileStmt(Expression *cond, bool input = false);
void loopEnd();
void ifBegin();
void ifBranch(Expression * cond);
void ifBranchEnd();
void labelIfBranch();
void endIf();
void forStmt(Expression * cond);


/*Expression Functions*/
void create(Expression *lhs, Expression *rhs);
Expression* AndExpr(Expression * lhs, Expression * rhs);
Expression* DivExpr(Expression * lhs, Expression * rhs);
Expression* EqExpr(Expression * lhs, Expression * rhs);
Expression* GteExpr(Expression * lhs, Expression * rhs);
Expression* GtExpr(Expression * lhs, Expression * rhs);
Expression* LteExpr(Expression * lhs, Expression * rhs);
Expression* LtExpr(Expression * lhs, Expression * rhs);
Expression* SubExpr(Expression * lhs, Expression * rhs);
Expression* ModExpr(Expression * lhs, Expression * rhs);
Expression* MultExpr(Expression * lhs, Expression * rhs);
Expression* NeqExpr(Expression * lhs, Expression * rhs);
Expression* OrExpr(Expression * lhs, Expression * rhs);
Expression* AddExpr(Expression * lhs, Expression * rhs);
Expression* IntExpr(int intVal);
Expression* CharExpr(char *strVal);
Expression* StrExpr(char *strVal);
Expression* IdentExpr(char *strVal);
Expression* genLValue(std::vector<Expression> exprList);

/*Constant Expression Functions */
Constant* ConstAndExpr(Constant lhs, Constant rhs);
Constant* ConstDivExpr(Constant lhs, Constant rhs);
Constant* ConstEqExpr(Constant lhs, Constant rhs);
Constant* ConstGteExpr(Constant lhs, Constant rhs);
Constant* ConstGtExpr(Constant lhs, Constant rhs);
Constant* ConstLteExpr(Constant lhs, Constant rhs);
Constant* ConstLtExpr(Constant lhs, Constant rhs);
Constant* ConstSubExpr(Constant lhs, Constant rhs);
Constant* ConstModExpr(Constant lhs, Constant rhs);
Constant* ConstMultExpr(Constant lhs, Constant rhs);
Constant* ConstNeqExpr(Constant lhs, Constant rhs);
Constant* ConstOrExpr(Constant lhs, Constant rhs);
Constant* ConstAddExpr(Constant lhs, Constant rhs);
Constant* ConstNotExpr(Constant in);
Constant* ConstUminusExpr(Constant in);




#endif

