#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include "Type.hpp"
#include "Symbol.hpp"
#include "Expressions.hpp"
#include "Constant.hpp"
#include "Var.hpp"
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <fstream>

class Constant;

extern void yyerror(const char *str);

class SymbolTable {
private:
	SymbolTable();
public:
	std::vector<std::map<std::string, std::shared_ptr<Symbol>>> tables;
	std::vector<int> offset;
	std::vector<int> ifStack;
	std::vector<std::pair<int, int>> spillStack;
	std::vector<bool> registers;
	std::vector<Constant> stringConsts;
	std::vector<int> controlStack;
	int controlLabels;
	int ifLabels;
	int labels;
	static std::shared_ptr<SymbolTable> instance;

	template<class T>
	void addSymbol(std::string name, T sym, bool init = false)
	{
		if (tables.back().find(name) != tables.back().end())
		{
			if (init)
			{
				std::cout << name << std::endl;
				yyerror(std::string(name + " already exists").data());
			}
		}
		auto temp = std::make_pair(name, std::make_shared<T>(sym));
		tables.back().insert(temp);
	};
	bool lookup(std::string name);
	void checkType(std::string name);
	std::shared_ptr<Symbol> getSymbol(std::string name);
	void popScope();
	int getReg();
	void clearReg();
	void emitEnd();
	static std::shared_ptr<SymbolTable> getInstance();
};

#endif
