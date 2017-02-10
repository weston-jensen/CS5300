To Compile the Program:
bison -d -o parser.tab.cpp *.y
flex -o lex.yy.cpp *.l
g++ -o launcher *.cpp -lfl

./launcher < "test file"

-I believe my parser.y file is correct but I was unsure
how to really test it...
