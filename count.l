%{
    #include<stdio.h>
    int lc=0,sc=0,tc=0;
%}
%%
[\n] { lc++;}
[  ] { sc++;}
[\t]+ { tc++;} 
%%
int yywrap(){return 1;}
int main(){
    printf("Enter the Sentence : ");
    yylex();
    printf("Number of lines : %d\n",lc);
    printf("Number of spaces : %d\n",sc);
    printf("Number of tabs: %d\n",tc);
    return 0;
}