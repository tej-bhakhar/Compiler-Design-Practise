%{
#include<stdio.h>
%}

%%
if |
else |
for {printf("\n%s is a keyword",yytext);}
[0-9]+ {printf("\n%s is a number",yytext);}
[a-zA-Z]+ {printf("\n%s is a word",yytext);}
. | \n {ECHO;}
%%

int main()
{
	printf("\nEnter the string: ");
	yylex();
}

int yywrap()
{
	return 1;
}