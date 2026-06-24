// bai 3 trong file btot
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//dinh nghia stack
typedef struct {
	char data[MAX];
	int top;
} Stack;

void init (Stack* s) {
	s->top = -1; 
}

int isEmpty (Stack* s) {
	return s->top == -1;
}

void push (Stack* s, char c) {
	if(s->top < MAX -1) 
	{
		s->data[++(s->top)] = c;
	}
}

char pop (Stack* s) {
	if (isEmpty(s)) 
	{
		return	NULL;
	}
	return s->data[(s->top)--];
}

//x? ly d? li?u

int isMatchingPair(char c1, char c2) 
{
	if (c1 == '(' && c2 == ')') 	return 1;
	if (c1 == '{' && c2 == '}') 	return 1;
	if (c1 == '[' && c2 == ']') 	return 1;
	return 0;
}

int test (char* exp) 
{
	Stack s;
	init(&s);
	
	for (int i = 0; i < strlen(exp); i++) {
		if(exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
		{
			push(&s, exp[i]);
		} 
		else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
		{
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
	exp1[strcspn(exp1, "\n")] = '\0';
	
	printf("Chuoi %s: %s\n", exp1, test(exp1) ? "Hop le" : "Khong hop le");

return 0;
}