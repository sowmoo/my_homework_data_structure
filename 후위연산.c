#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element;

struct stack
{
	element data[MAX_STACK_SIZE];
	int top;
};

void init_stack(struct stack* a);

int eval(char ch[]);

int main()
{
	int result;
	printf("후위값 표시 --> 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d 입니다.\n", result);
}

void init_stack(struct stack* a)
{
	a->top = -1;
}

int eval(char a[])
{
	int op1, op2, value;
	char ch;

	struct stack stack;
	init_stack(&stack);

	for (int i = 0; i < strlen(a); i++)
	{
		ch = a[i];
		if (ch != '+' && ch != '-' && ch != '/' && ch != '*' && ch != '%')
		{
			value = ch - '0';
			stack.data[++(stack.top)] = value;
		}
		else
		{
			op2 = stack.data[(stack.top)--];
			op1 = stack.data[(stack.top)--];
			
			switch (ch)
			{
				case '+' :
				{
					stack.data[++(stack.top)] = op1 + op2;
					break;
				}
				case '-' :
				{
					stack.data[++(stack.top)] = op1 - op2;
					break;
				}
				case '*':
				{
					stack.data[++(stack.top)] = op1 * op2;
					break;
				}
				case '/':
				{
					stack.data[++(stack.top)] = op1 / op2;
					break;
				}
				case '%':
				{
					stack.data[++(stack.top)] = op1 % op2;
					break;
				}
			}
		}		
	}
	return stack.data[(stack.top)--];
}
