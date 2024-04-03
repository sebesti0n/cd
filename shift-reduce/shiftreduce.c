#include <stdio.h>
#include <string.h>

struct ProductionRule {
    char left[10];
    char right[10];
};

int main() {
    char input[20], stack[50], temp[50], ch;
    int i, j, stack_length, substring_length, stack_top, rule_count = 0;
    struct ProductionRule rules[10];

    stack[0] = '\0';

    // User input for the number of production rules
    printf("\nEnter the number of production rules: ");
    scanf("%d", &rule_count);

    // User input for each production rule in the form 'left=right'
    printf("\nEnter the production rules (in the form 'left=right'): \n");
    for (i = 0; i < rule_count; i++) {
        scanf("%s", temp);
        int left_index = 0, right_index = 0;
        while (temp[left_index] != '=') {
            rules[i].left[left_index] = temp[left_index];
            left_index++;
        }
        rules[i].left[left_index] = '\0'; // Terminate left side string
        left_index++; // Move past the equal sign (=)

        while (temp[left_index] != '\0') {
            rules[i].right[right_index] = temp[left_index];
            right_index++;
            left_index++;
        }
        rules[i].right[right_index] = '\0'; // Terminate right side string
    }

    // User input for the input string
    printf("\nEnter the input string: ");
    scanf("%s", input);

    i = 0;
    while (1) {
        // If there are more characters in the input string, add the next character to the stack
        if (i < strlen(input)) {
            ch = input[i];
            stack[strlen(stack)] = ch; // Append directly to stack string
            stack[strlen(stack)] = '\0'; // Update string terminator
            printf("%s\t", stack);
            for (int k = i + 1; k < strlen(input); k++) {
                printf("%c", input[k]);
            }
            printf("\tShift %c\n", ch);
            i++;
        }

        // Iterate through the production rules
        for (j = 0; j < rule_count; j++) {
            int match = 1;
            int right_index = 0;
            int stack_index = strlen(stack) - 1;

            // Check if the right-hand side of the production rule matches a substring in the stack
            while (right_index < strlen(rules[j].right) && stack_index >= 0) {
                if (rules[j].right[right_index] != stack[stack_index]) {
                    match = 0;
                    break;
                }
                right_index++;
                stack_index--;
            }

            if (match && right_index == strlen(rules[j].right)) {
                // Replace the matched substring with the left-hand side of the production rule
                stack_length = strlen(stack);
                substring_length = strlen(rules[j].right);
                stack[stack_length - substring_length] = '\0'; // Terminate at the match point
                strcat(stack, rules[j].left);
                printf("%s\t", stack);
                for (int k = i; k < strlen(input); k++) {
                    printf("%c", input[k]);
                }
                printf("\tReduce %s=%s\n", rules[j].left, rules[j].right);
                j = -1; // Restart the loop to ensure immediate reduction of the newly derived production rule
            }
        }

        // Check if the stack contains only the start symbol and if the entire input string has been processed
        if (strcmp(stack, rules[0].left) == 0 && i == strlen(input)) {
            printf("\nAccepted");
            break;
        }

        // Check if the entire input string has been processed but the stack doesn't match the start symbol
        if (i == strlen(input)) {
            printf("\nNot Accepted");
            break;
        }
    }
    return 0;
}