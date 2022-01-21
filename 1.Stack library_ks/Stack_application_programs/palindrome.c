# include <stdio.h>
# include <string.h>
# define MAXSIZE 50

int stack[MAXSIZE], top,j=0;
char output[50];

void create()
{
	top = -1;
}

void push(char element)
{
	if (top == MAXSIZE-1)
	{
		printf("\nError stack is empty");
	}
	else
	{
		top++;
		stack[top] = element;
	}
};

void pop()
{
	if (top == -1)
	{
		printf("\nError stack is empty");
	}
	else
	{
		output[j] = stack[top];
		j++;
		top--;
	}
}

void main()
{
	char input[50];
	int i, j, k, repeat_count = 1;
	printf("\n Enter the word here :");
	scanf("%s",&input);
	printf("\n");
	for (k = 0; k < strlen(input); k++)
	{
		if (input[k] == input[k+1])
		{
			repeat_count++;
		}
	}
	if (repeat_count > 2)
	{
		printf("\nINVALID INPUT");
	}
	else
	{
 		for ( i = 0; i < strlen(input) ; i++)
		{
			push(input[i]);
		}
		for ( j = 0; j < strlen(input); j++)
		{
			pop();
		}
		printf("\nReversed string = %s", output);
	}
}
