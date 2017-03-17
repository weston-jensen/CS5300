#ifndef RECORD_H
#define RECORD_H
#include "Type.hpp"
#include "Symbol.hpp"
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <map>

class Record :public Type{
public:
	Record(std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> tList, std::string id = "");
	std::map<std::string, std::pair<std::shared_ptr<Type>, int>> layout;
	bool isType()
	{
		return true;
	};
};


#endif