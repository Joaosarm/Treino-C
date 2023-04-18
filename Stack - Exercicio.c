#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack{
    int topo;
    unsigned int capacity;
    char* array;
};

struct Stack* CreateStack (unsigned int capacity){
    struct Stack* stack = (struct Stack*) malloc (sizeof(struct Stack)); 
    stack -> capacity = capacity;
    stack -> topo = -1;
    stack -> array = (char*) malloc(stack -> capacity * sizeof(char));
    return stack;
}

bool isFull(struct Stack* stack){
    return stack ->topo == stack-> capacity;
}

bool isEmpty(struct Stack* stack){
    return stack ->topo == -1;
}

void push(struct Stack* stack, char item){
    if (isFull(stack)) return;
    
    stack -> array [++stack->topo] = item;
    printf("%c Pushed to stack\n", item);
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack)) return -1;
    
    return stack->array[stack->topo--];
}

void printStack(struct Stack* stack){
    if (stack -> topo == -1) printf("Pilha Vazia");
    else{
        printf("[");
        
        for (int i=0; i<= stack -> topo; i++){
            printf("%c", stack -> array[i]);
            if (i!= 0) printf(", ");
        }
        
        printf("]");
    }
}

bool isBalanced(struct Stack* stack){
    struct Stack* stack1 = CreateStack(10);
    
    for (int i = 0; i <= stack -> topo; i++){
        
        if(stack -> array[i] == '(') {
            push(stack1, '(');
        }
        else{
            if(stack -> array[i] == ')' && !isEmpty(stack1)) pop(stack1);
            else{
                return false;
            }
        }
    }
    
    return isEmpty(stack1);
    
}

int main()
{
  struct Stack* stack = CreateStack(10);
  
    push(stack, '(');
    push(stack, '(');
    push(stack, ')');
    push(stack, ')');
    
    
    printf("%B", isBalanced(stack));
    

    return 0;
}