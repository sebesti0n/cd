%{
    #include<stdio.h>
    int count = 0;
%}
%%
[A-Z]   {printf("%s is capital letter\n", yytext); count++;}
[a-z]   {printf("%s is not a capital letter\n", yytext);}
\n      {return 0;}
%%

int yywrap(){return 1;}
int main()
{
    printf("\nEnter the characters: ");
    yylex();
    printf("\nNumber of Capital letters in the given input - %d\n", count);
    return 0;
}