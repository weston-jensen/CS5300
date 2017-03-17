#include "Array_Type.hpp"

Array_Type::Array_Type(Type* type, Constant lower, Constant upper, std::string name)
:Type(name, type->size*(upper.getIntVal() - lower.getIntVal()), Type::array)
, lower(lower.getIntVal())
, upper(upper.getIntVal())
, type(std::make_shared<Type>(*type))
{
	if (this->upper <= this->lower)
	{
		std::cout << "invalid array index" << std::endl;
	}
	this->name = "Array[" + std::to_string(this->lower) + ":" + std::to_string(this->upper) + "] of " + type->name;
}

