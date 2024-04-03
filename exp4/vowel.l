%{
	#include<stdio.h>
    int vowel=0;
    int cons=0;
%}
%%
[aeiouAEIOU] {printf("\nIt is an Vowel"); vowel++;}
[^aeiouAEIOU] {printf("\nIt is a Consonant"); cons++;}
%%
int yywrap(){return 1;}
int main()
{
    printf("\nEnter the Character: ");
    yylex();
    printf("\nTotal Vowel=%d & Total Consonant= %d\n", vowel,cons);
    return 0;
}