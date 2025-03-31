#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 50

int s[size];
int input[50];
int postfix[50];
int top = -1;

void push(int x)
{
	if(top >= size -1)
	{
		printf("stack overfolw");
	}
	else
	{
		top++;
		s[top]=x;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("stack overflow");
	}
	else
	{
		return s[top--];
	}
}
void main()
{
	char input[size];
	int i=0;
	char temp;
	
	printf(" enter prefix expression: ");
	scanf("%s",input);
	
	while(input[i]!='\0');
	{
		temp=input[i];
		
		if(isdigit(temp))
		{
			push(temp-'0');
		}
		else if(strchar("+-*/^",temp))
		{
			if(top<1)
			{
				printf("insufficient operands");
				return;
			}
			int op1=pop();
			int op2=pop();
			int value=evaluate(op1,op2,temp);
			return;
		}
		i++;
	}
	if(top!=0)
	{
		printf("error : invalid postfix");
		return;
	}
	printf("result: %d \n",pop());
}
