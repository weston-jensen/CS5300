#ifndef VAR_HPP
#define VAR_HPP
#include <iostream>
#include "Symbol.hpp"
#include "Type.hpp"
#include <string>
#include <memory>

class Var:public Symbol{
public:
	std::shared_ptr<Type> type;
	int location;
	Var(Type type, int location, std::string name = "");
};

#endif
