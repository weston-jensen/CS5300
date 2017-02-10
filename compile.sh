#!/bin/bash

if [ -f "launcher.exe" ] ; then
	rm "launcher.exe"
fi

rm lex.yy.cpp *.tab.cpp *.tab.hpp
bison -d -o parser.tab.cpp *.y
flex -o lex.yy.cpp *.l
g++ -o launcher.exe *.cpp -lfl
