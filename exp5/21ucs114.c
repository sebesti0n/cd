#include <stdio.h>
#include <string.h>
int main() {
    char arithmetic[5]={'+','-','*','/','%'};
    char relational[4]={'<','>','!','='};
    char bitwise[4]={'&','^','~','|'};
    char str[2]={'\0','\0'};
    int operator = 0, i;
    printf ("Enter operator to be identified: ");
    scanf ("%s", str);
    if(((str[0]=='&' || str[0]=='|') && str[0]==str[1]) || (str[0]=='!' && str[1]=='\0')) {
        printf("\nIt is Logical Operator.\n");
        operator = 1;
    }
    for(i=0;i<4;i++) {
        if((str[0]==relational[i] && (str[1]=='=' || str[1]=='\0')) || ((str[0]=='>' || str[0]=='<') && (str[1]=='\0'))) {
            printf("\nIt is Relational Operator.\n");
            operator = 1;
            break;
        } else if((str[0]==bitwise[i] && str[1]=='\0') || ((str[0]=='<' || str[0]=='>') && str[1]==str[0])) {
            printf("\nIt is Bitwise Operator.\n");
            operator = 1;
            break;
        }
    }
    if(str[0]=='?' && str[1]==':') {
        printf("\nIt is Ternary or Conditional Operator.\n");
        operator = 1;
    }
    for(i=0;i<5;i++) {
        if((str[0]=='+' || str[0]=='-') && str[0]==str[1]) {
            printf("\nIt is Unary Arithmetic Operator.\n");
            operator = 1;
            break;
        } else if((str[0]==arithmetic[i] && str[1]=='=') || (str[0]=='=' && str[1]=='\0')) {
            printf("\nIt is Assignment Operator.\n");
            operator = 1;
            break;
        } else if(str[0]==arithmetic[i] && str[1]=='\0') {
            printf("\nIt is Binary Arithmetic Operator.\n");
            operator = 1;
            break;
        }
    }
    if(operator != 1) {
        printf("\nIt is not an operator.\n");
    }
    return 0;
}