#ifndef ARRAY_TYPE_H
#define ARRAY_TYPE_H
#include "Type.hpp"
#include "Symbol.hpp"
#include "Constant.hpp"
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <map>

class Array_Type :public Type
{
public:
	int upper;
	int lower;
	std::shared_ptr<Type> type;
	Array_Type(Type* type, Constant lower, Constant upper, std::string name = "");
	bool isType()
	{
		return true;
	};
};

#endif
