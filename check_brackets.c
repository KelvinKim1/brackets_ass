#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
	
	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line);
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];
        if (next == '(' || next == '[' || next == '{') {
            Bracket bracket;
            if (next == '('){
                bracket.type = ROUND;
            } else if(next == '['){
                bracket.type = SQUARE;
            } else {
                bracket.type = CURLY;
            }
            bracket.position = position+1;
            push(opening_brackets_stack, bracket, max_line);
        }

        if (next == ')' || next == ']' || next == '}') {
            enum BracketType type;
            Bracket top;
            if (next == ')'){
                type = ROUND;
            } else if (next == ']'){
                type = SQUARE;
            } else {
                type = CURLY;
            }
            if (isEmpty(opening_brackets_stack) == 1){
                printf("My result is: %d", position+1);
                return 0;
            }
            top = opening_brackets_stack->array[opening_brackets_stack->top];
            if (type == top.type){
                pop(opening_brackets_stack);
            } else {
                printf("My result is: %d", position+1);
                return 0;
            }
        }
    }
    
    if (isEmpty(opening_brackets_stack) == 0){
         printf("My result is: %d", (opening_brackets_stack->array[opening_brackets_stack->top]).position);
        return 0;
    }
    // Printing answer, write your code here
	printf("My result is: Success");
    return 0;
}
