#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "Expressions.hpp"
#include "Symbol.hpp"
#include "Type.hpp"
#include "Constant.hpp"
#include "symbol_table.hpp"
#include "TreeParser.hpp"


class Expression;
class Symbol;
class SymbolTable;

extern FILE* yyin;
extern int yyparse();
extern int yylineno;
//extern int yylex();
extern int num_lines;

std::shared_ptr<SymbolTable> SymbolTable::instance;

std::fstream aout;


int main(int argc, char** argv)
{
	std::vector<std::string> arguments;
	std::string input_file = "expressions.cpsl";
	std::string output_file = "output.asm";
	for(int i=0; i<argc;i++)
	{
		arguments.push_back(std::string(argv[i]));
	}
	
	input_file = arguments[1];

	std::ifstream infile(input_file);
	if(!infile.good())
	{
		std::cout<<input_file<<" Does not Exist!!!" <<std::endl;
		return EXIT_FAILURE;
	}

	FILE *temp = fopen(argv[1],"r");
	if(!temp)
	{
		std::cout<<"Error opening file"<<std::endl;
		return -1;
	}
	else
	{
		std::cout<<"Opened FIle just fine"<<std::endl;
	}

	aout.open(output_file.data(),std::ios::out);
	aout <<".text"<<std::endl;
	aout <<".global __main"<<std::endl;
	aout <<"j __main" <<std::endl;

	yyin = temp;
	yyparse();
	
/*
    try
	{
		std::cout<<"right before yyparse()"<<std::endl;
		yyparse();
		//fclose(yyin);
	}
	catch(std::runtime_error e)
	{
		std::cout<<"Could not compile! "<< e.what() << " at line "<<yylineno << std::endl;
		fclose(yyin);
		return EXIT_FAILURE;
	}
*/
	std::cout<<"after try catch"<<std::endl;	
	aout.close();
	
	return 0;
}
