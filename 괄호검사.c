#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element; //자료형에 따라 바꾸기 쉽게 하기위해 선언 

struct stack
{
	element data[MAX_STACK_SIZE];
	int top;
};

void init_stack(struct stack* a);

int check_matching(const char *a);


int main()
{
	char* p = "((1+2)+(2+4))";		
	int result = check_matching(p);

	if (result == 0)
	{
		printf("%s 괄호검사 문제 \'없습\'니다.\n",p);
	}
	else
	{
		printf("%s 괄호검사 문제 \'있습\'니다.\n",p);
	}
		
}

void init_stack(struct stack* a)
{
	a->top = -1;
}

int check_matching(const char* a)
{
	struct stack stack;
	init_stack(&stack);

	char ch, open_ch;

	for (int i = 0; i < strlen(a); i++)
	{
		ch = a[i];
		switch (ch)
		{
			case '(':
			case '{':
			case '[':
			{
				stack.data[++(stack.top)] = ch;
				break;
			}
			case '}':
			case ')':
			case ']':
			{
				open_ch = stack.data[(stack.top)--];
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']'))
				{
					return 1;
				}
				break;
			}			
		}
	}
	if (stack.top != -1)
	{
		return 1;
	}	

	return 0;
}
