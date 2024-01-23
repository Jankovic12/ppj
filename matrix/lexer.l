%option noyywrap

%{
    #include <iostream>
    #include <cstdlib>
    #include <vector>
    #include <cmath>


    #include "Matrix.hpp"
    #include "parser.tab.hpp"
%}


%%

size        {return SIZE_T;}
rows        {return ROWS_T;}
cols        {return COLS_T;}

[a-zA-Z_][a-zA-Z0-9_]*          {
                                    yylval.s = new std::string(yytext);
                                    return ID;
                                }
[0-9]+(\.[0-9]*)?               {
                                    yylval.v = atof(yytext);
                                    return NUMBER;
                                }
".*"                            { return MUL_BY_COORD; }
"!="                            { return NEQ; }
"=="                            { return EQ;  }
[=+*\(\)\[\],;\':\n-]             { return *yytext;      }
%.*                             { }
[ \t]                         {    }
.                               {
                                    std::cerr << "Lexical error: character `" << (*yytext) << "` not recognized" << std::endl; 
                                    exit(EXIT_FAILURE);
                                }

%%