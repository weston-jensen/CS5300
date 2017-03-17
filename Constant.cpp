#include "Constant.hpp"
#include "symbol_table.hpp"
#include <string>

extern void yyerror(const char *str);

Constant::Constant(int numVal, std::string name)
: Symbol(name), numVal(numVal)
{
	type = intType;
}
Constant::Constant(char CharVal, std::string name)
: Symbol(name), charVal(CharVal)
{
	type = charType;
}
Constant::Constant(std::string strVal, std::string name)
: Symbol(name)
, strVal(strVal)
,location(std::string("__stringConstLabel"+std::to_string(SymbolTable::getInstance()->labels++)))
{
	SymbolTable::getInstance()->stringConsts.push_back(*this);
	type = stringType;
}
Constant::Constant(bool boolVal, std::string name)
: Symbol(name), boolVal(boolVal)
{
	type = boolType;
}
Constant::Constant(std::string name, ConstType type)
: Symbol(name), type(type)
{

}
void Constant::print()
{

}

int Constant::getIntVal()
{
	if(type==intType)
	{
		return numVal;
	}
	
	if(type==identType)
	{
		auto ident = *(dynamic_cast<Constant*>(SymbolTable::getInstance()->getSymbol(name).get()));
		if(ident.type==intType)
		{
			return ident.numVal;
		}
	}
	yyerror("Not an int val\n");
}
