#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>
#include <memory>

class Symbol{
public:
	std::string name;
	Symbol(std::string name) :name(name){};
	virtual bool isType(){ return false; };

	/*Function Calls to Make things nicer*/
	static std::string char_type() { return "char"; }
	static std::string int_type() { return "integer"; }
	static std::string bool_type() { return "boolean"; }
	static std::string string_type() { return "string"; }
	static std::string null_type() { return "null"; }
	static std::string record_type() { return "array"; }

};


#endif
