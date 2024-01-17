parser: lexer.o parser.o polinom.o
	g++ lexer.o parser.o polinom.o -o parser

lexer.o: lex.yy.c
	g++ -c lex.yy.c -o lexer.o 

parser.o: parser.tab.cpp parser.tab.hpp
	g++	-c parser.tab.cpp -o parser.o

lex.yy.c: lexer.l parser.tab.hpp
	flex -l lexer.l

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp

polinom.o: Polinom.cpp Polinom.hpp
	g++ -c Polinom.cpp -o polinom.o

.PHONY: clean

clean:
	rm -rf p*.output *.o *.yy.* *.tab.* parser