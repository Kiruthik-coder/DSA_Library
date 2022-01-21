# include <stdio.h>
# include <string.h>
# define MAXSIZE 50

int stack_num[MAXSIZE], top;

void create()
{
	top =-1;
}

void pop()
{
	top--;
}

void executer(char symbol)
{
	int operand_1, operand_2, result, operand_a, operand_b, hold = 1, i;
	if (symbol != '^')
	{
		operand_1 = stack_num[(top-1)];
		operand_2 = stack_num[(top)];
		printf("\noperand_1 -> %d", operand_1);
		printf("\noperand_2 -> %d", operand_2);
		pop();
		pop();
	}
	if (symbol == '+')
	{
//		printf("\n i am in");
		result = operand_1 + operand_2;
	}
	if (symbol == '-')
	{
		result = operand_1 - operand_2;
	}
	if (symbol == '*')
	{
		result = operand_1 * operand_2;
		
	}
	if (symbol == '/')
	{
		result = operand_1 / operand_2;
	}
	if (symbol == '^')
	{
		operand_a = stack_num[(top-1)];
		operand_b = stack_num[(top)];
		printf("----%d\n -----%d\n", operand_a, operand_b);
		for ( i = 0; i < operand_b; i++)
		{
			hold = hold * operand_a;
		}
		result = hold ;
		pop();
		pop();
	}
//	printf("\n top = %d", top);
	top++;
	stack_num[top] = result;
	printf("\nInside result = %d", result);
}

void push(int element)
{
//	printf("\top before ++ = %d", top);
	top = top +1;
//	printf("\nTOp inside push = %d", top);
	stack_num[top] = element;
//	printf("\n Pushed --> %d", stack_num[top]);
}

void main()
{
	create();
	char input[50] = "+ 5 5";
	int i, j, out_result, temp=0;
	char rev_equ[50];
	int l = 0, k;
	for (k = (strlen(input)-1); k >= 0; k--)
	{
		rev_equ[l] = input[k];
		l++;
	}
	
	for (i=0; i < strlen(input); i++)
	{
		if (rev_equ[i] == ' ')
		{
			continue;
		}
		else if(isdigit(rev_equ[i]))
		{
			int digit = 0;
			while(isdigit(rev_equ[i]))
			{
				digit = digit * 10 + (int)(rev_equ[i] - '0');
				i++;
			}
			i--;
			push(digit);
		}
		else
		{
			if (rev_equ[i] == '^')
			{
				i = i + 1;
				int digit = 0;
				while(isdigit(rev_equ[i]))
				{
					digit = digit * 10 + (int)(rev_equ[i+1] - '0');
					i++;
				}
				i--;
				push(digit);
				printf("t---%d\n", digit);
			}	
			executer(rev_equ[i]);	
		}
		
	}
	out_result = stack_num[0];
	printf("\nResult :%d", out_result);
}
