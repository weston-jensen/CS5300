#include "Var.hpp"

Var::Var(Type type, int location, std::string name)
: Symbol(name)
, type(std::make_shared<Type>(type))
, location(location)
{}

