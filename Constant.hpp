#ifndef CONSTANT_H
#define CONSTANT_H

#include <iostream>
#include <string>
#include "Symbol.hpp"

class Constant : public Symbol{
public:
	enum ConstType { intType, charType, stringType, boolType, identType };
	ConstType type;
	int numVal;
	char charVal;
	std::string strVal;
	bool boolVal;
	int getIntVal();
	std::string location;

	Constant(int numVal, std::string name = "");
	Constant(char CharVal, std::string name = "");
	Constant(std::string strVal, std::string name = "");
	Constant(bool boolVal, std::string name = "");
	Constant(std::string name, ConstType type);
	void print();
};

#endif
