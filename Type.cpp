#include "Type.hpp"

Type::Type(std::string name, int size, TypeType typeType) : Symbol(name)
, size(size)
, typeType(typeType)
{}

bool Type::isType()
{
return true;
}

Simple::Simple(SimpleType simType, std::string name) :Type(name, 4)
, simType(simType){}



