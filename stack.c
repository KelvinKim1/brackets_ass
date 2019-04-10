// C-implementation of stack 
#include "stack.h" 
  
// function to create a stack of given capacity. 
Stack* createStack(unsigned capacity){
	Stack* stack = (Stack*) malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1;
	stack->array = (Bracket*) malloc(stack->capacity * sizeof(Bracket));
    return stack;
}

// Stack is full when top index is equal to capacity-1
int isFull(Stack* stack, unsigned capacity){
    if (stack->top == capacity-1){
        return 1;
    }
    return 0;
}

// Stack is empty when top is equal to -1 (or head of the list is NULL)
int isEmpty(Stack* stack){
    if (stack->top == -1){
        return 1;
    }
	return 0;
}

// Function to add an item to stack.  
void push(Stack* stack, Bracket item, unsigned capacity){
	if (isFull(stack, capacity))
        return;
    stack->top ++;
    stack->array[stack->top] = item;
}

// Function to remove an item from stack and return it. 
Bracket pop(Stack* stack){
	Bracket top = stack->array[stack->top];
    stack->top = (stack->top)-1;
	return top;
}    
  
