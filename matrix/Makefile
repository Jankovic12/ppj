parser: parser.o lexer.o Matrix.o
	g++ parser.o lexer.o Matrix.o -o parser

parser.o: parser.tab.cpp parser.tab.hpp
	g++ -c parser.tab.cpp -o parser.o

lexer.o: lex.yy.c
	g++ -c lex.yy.c -o lexer.o

lex.yy.c: lexer.l parser.tab.hpp
	flex -l lexer.l

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp

Matirx.o: Matrix.cpp Matrix.hpp
	g++ -c Matrix.cpp -o Matrix.o

.PHONY: clean

clean:
	rm -rf p*.output *.o *.yy.* *.tab.* parser