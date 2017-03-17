#include "symbol_table.hpp"

#include "TreeParser.hpp"
#include <algorithm>
#include <string>
#include <memory>

extern std::fstream aout;
extern void yyerror(const char *str);

//std::shared_ptr<SymbolTable> SymbolTable::instance;

SymbolTable::SymbolTable()
: tables()
, labels(0)
, controlLabels(0)
, ifLabels(0)
, controlStack()
, ifStack()
, stringConsts()
{
	offset.resize(2);//should this be 4?
	registers.resize(18);
	std::fill(registers.begin(), registers.end(), true);
	std::map<std::string, std::shared_ptr<Symbol>> temp, mainScope;//might break .........

	temp.insert(std::make_pair("integer", std::make_shared<Simple>(Simple::integer, "integer")));
	temp.insert(std::make_pair("integer", std::make_shared<Simple>(Simple::integer, "INTEGER")));
	temp.insert(std::make_pair("char", std::make_shared<Simple>(Simple::character, "char")));
	temp.insert(std::make_pair("CHAR", std::make_shared<Simple>(Simple::character, "CHAR")));
	temp.insert(std::make_pair("string", std::make_shared<Simple>(Simple::string, "string")));
	temp.insert(std::make_pair("STRING", std::make_shared<Simple>(Simple::string, "STRING")));
	temp.insert(std::make_pair("boolean", std::make_shared<Simple>(Simple::boolean, "boolean")));
	temp.insert(std::make_pair("BOOLEAN", std::make_shared<Simple>(Simple::boolean, "BOOLEAN")));
	temp.insert(std::make_pair("true", std::make_shared<Constant>(true, "true")));
	temp.insert(std::make_pair("TRUE", std::make_shared<Constant>(true, "TRUE")));
	temp.insert(std::make_pair("false", std::make_shared<Constant>(false, "false")));
	temp.insert(std::make_pair("FALSE", std::make_shared<Constant>(false, "FALSE")));
	tables.push_back(temp);
	tables.push_back(mainScope);
};

std::shared_ptr<SymbolTable> SymbolTable::getInstance()
{
	if (!instance)
	{
		std::shared_ptr<SymbolTable> inst(new SymbolTable());
		instance = inst;
	}
	return instance;
};

void SymbolTable::popScope()
{
	tables.pop_back();
	offset.pop_back();
}

bool SymbolTable::lookup(std::string id)
{
	bool returnVal = false;

	std::for_each(tables.begin(), tables.end(),
		[&](std::map<std::string, std::shared_ptr<Symbol>> map){
		returnVal = returnVal || (map.find(id) != map.end());
	});
	return returnVal;
};

std::shared_ptr<Symbol> SymbolTable::getSymbol(std::string name)
{
	//for (int i = tables.size() - 1; i >= 0; --i)
	for(int i=0;i<tables.size();i++)
	{
		if (tables[i].find(name) != tables[i].end())
		{
			auto temp = tables[i].at(name);
			return temp;
		}
	}
	std::cout <<"cant find "<<name<<std::endl;
	yyerror("In SymbolTable getSymbol , Symbol not found");
};

void SymbolTable::clearReg()
{
	std::fill(registers.begin(), registers.end(), true);
};

void SymbolTable::checkType(std::string id)
{
	if (lookup(id))
	{
		if (getSymbol(id)->isType())
		{
			return;
		}
	}
	yyerror("Undefined type");
};

int SymbolTable::getReg()
{
	for (int i = 0; i < registers.size(); ++i)
	{
		if (registers[i])
		{
			registers[i] = false;
			std::cout<<"returning reg: "<<i+8<<std::endl;
			return i + 8;
		}
	}
	yyerror("Out of registers");
};

void SymbolTable::emitEnd()
{
	aout <<"li $v0, 10"<<std::endl<<"syscall"<<std::endl;
	aout <<".data"<<std::endl;
	aout <<"__newline: .asciiz \"\\n\""<<std::endl;

	if(stringConsts.size()>0)
	{
		std::for_each(stringConsts.begin(), stringConsts.end(), [&](Constant strCon)
		{
			aout <<strCon.location<<": .asciiz "<<strCon.strVal<<std::endl;
		});
	}
}
