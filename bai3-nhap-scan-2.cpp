#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define the Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Initialize the stack
void init(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack* s, char c) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = c;
    }
}

// Pop an element from the stack
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

// Check if opening and closing brackets match
int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return 1;
    if (character1 == '{' && character2 == '}') return 1;
    if (character1 == '[' && character2 == ']') return 1;
    return 0;
}

// Your validation function
int test(char* exp) {
    Stack s;
    init(&s);
    
    for (int i = 0; i < strlen(exp); i++) {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&s, exp[i]);
        } 
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (isEmpty(&s)) return 0;
            char topChar = pop(&s);
            if(!isMatchingPair(topChar, exp[i])) return 0;
        }
    }
    return isEmpty(&s);
}

int main () {
    char exp1[50];
    printf("Nhap cac ngoac: ");
    fgets(exp1, sizeof(exp1), stdin);
    exp1[strcspn(exp1, "\n")] = '\0'; // Remove trailing newline
    
    printf("Chuoi %s: %s\n", exp1, test(exp1) ? "Hop le" : "Khong hop le");

    return 0;
}
