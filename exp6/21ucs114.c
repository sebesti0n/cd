#include<stdio.h>

int main() {
    char string[30];
    printf("\nEnter the string: ");
    scanf("%s", string);
    //Regular expression : a* | a*b+ | abb
    int i = 0, final = 0;
    if(string[0] == '\0') {
        final = 1;
    } else {
        while(string[i] != '\0' && string[i] == 'a') {
            i++;
            if(string[i] == '\0') {
                final = 1;
                break;
            }
        }
        while(string[i] != '\0' && string[i] == 'b') {
            i++;
            if(string[i] == '\0') {
                final = 1;
                break;
            }
        }
    }
    if(final == 1) {
        printf("\nThe string is valid. It is ACCEPTED.\n");
    } else {
        printf("\nThe string is not valid.It is REJECTED.\n");
    }
    return 0;
}