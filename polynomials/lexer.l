%option noyywrap

%{
    #include <iostream>
    #include <cstdlib>
    #include <map>
    #include <cmath>
    #include <vector>



    #include "Polinom.hpp"
    #include "parser.tab.hpp"
%}

%%

poly        {return POLY_T;}
print       {return PRINT_T;}
int         {return INT_T;}
deg         {return DEG_T;}

[A-Za-z_][A-Za-z0-9_]*      {
                                yylval.s = new std::string(yytext);
                                return ID;
                            }

[0-9]+(\.[0-9]*)?            {
                                yylval.v = atof(yytext);
                                return NUMBER;
                            }
"["     { return *yytext; }
"]"     { return *yytext; }
"'"     { return *yytext; }
[;*+=()<>,-]              {return *yytext;}
"=="                        {return EQ;}
"!="                        {return NEQ;}
[ \t\n]                     {  }
.                           {
                                std::cerr << "Lexical error: "
                                    << *yytext << " not recognized"
                                        << std::endl;
                                exit(EXIT_FAILURE);
                            }

%%