#ifndef TYPE_HPP
#define TYPE_HPP
#include "Symbol.hpp"

class Type : public Symbol
{
public:
	enum TypeType{ type, record, array };
	TypeType typeType;
	int size;
	Type(std::string name, int size, TypeType typeType = type);
	bool isType();
};

class Simple : public Type
{
public:
	enum SimpleType{ integer, boolean, character, string };
	SimpleType simType;
	std::shared_ptr<Type> type;
	Simple(SimpleType simType, std::string name = "");
	bool isType(){
		return true;
	};
};


#endif
