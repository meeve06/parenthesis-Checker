#include <stdio.h>
#include <string.h>
#define max 20

// declaring our global variables 
int top=-1;
int stack[max];

// declaring our functions for stack operation

void push(char);
char pop();

// main function
int main()
{
	char exp[max],temp;
	int flag=1;
	printf("Enter the expression to be checked :");
	printf("\n");
	gets(exp);
	
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' )
			push(exp[i]);
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']' )
			if(top==-1)
				flag=0;
			else
			{
				temp=pop();
				if(temp==')' && (temp=='{' || temp=='['))
					flag=0;
				if(temp=='}' && (temp=='(' || temp=='['))
					flag=0;
				if(temp==']' && (temp=='{' || temp=='('))
					flag=0;
			}
			
	}
	if( top>=0)
		flag=0;
	if(flag==1)
		printf("\n valid expression");
	else
		printf("\n Invalid Expression");
		
	return 0;
}


void push(char c)
{
	if(top ==(max-1))
		printf("\n Stack overflow");
	else
	{
		top++;
		stack[top]=c;
	}
}

char pop()
{
	if(top == -1)
		printf("\n Stack underflow");
	else
		return(stack[top--]);
}

