#include "Record.hpp"
#include <algorithm>


Record::Record(std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> tList, std::string name)
:Type(name, 0, Type::record)
{
	int offset = 0;
	std::for_each(tList.begin(), tList.end(), [&](std::pair<std::vector<std::string>, std::shared_ptr<Type>> val)
	{
		std::for_each(val.first.begin(), val.first.end(), [&](std::string id)
		{
			layout.insert(std::make_pair(name, std::make_pair(val.second, offset)));
			offset += 4; //could be val.second->size;
		});
	});
	this->size = offset;
}


