# include <stdio.h>
# include <string.h>

# define MAXSIZE 100
int top, j=0;// j handels the elements position in output
int st[MAXSIZE]; // declaring stack
char output[100]="";// output which contains postfix expression

void push(char element) // pushes element into the stack
{
	if (top<=MAXSIZE-1)
	{
		st[top+1] = element;// inserting element 
		top++;		
	}
	else
	{
		printf(" !! ERROR STACK OVERFLOW_-_-_-_-_-_-_-\n");
	}
}

void pop() // removes the top element
{
	for (j = strlen(output); j <= (strlen(output) + 1); j++)
	{
		if (st[top] != ')' && st[top] != '}')
		{
			output[j] += st[top];
		}
		break;
	}
	top--;
}

int precedence_assigner(char value)// assigns the precedence value to symbol
{
	if (value == '+' || value == '-')
	{
		return 4;
	}
	else if (value == '*' || value == '/')
	{
		return 5;
	}
	else if (value == '^')
	{
		return 6;
	}
	else if (value == ')' || value == '}')
	{
		return 10;
	}
	else
	{
		return 0;
	}
}

void prioritizer(char symbol) // handels the elements in stack (push and pop)
{
	int priority_num, top_pri_num;
	if (st[top] == ')' || st[top] == '}')
	{
			push(symbol);
	}
	else if (symbol == '(') // it pops all the element till reaching '('
	{
		while (st[top] != ')')
		{
			pop();
		}
		pop(); // pops "("
	}
	else if (symbol == '{')
	{
		while (st[top] != '}')
		{
			pop();
		}
		pop(); // pops "("
	}
	else
	{
		priority_num = precedence_assigner(symbol); // holds the precedence number of the character
		
		top_pri_num = precedence_assigner(st[top]);// holds the precedence number of the top element
		
		if (top_pri_num < priority_num) 
		{
			push(symbol);
		}
		else if( top_pri_num == priority_num)
		{
			push(symbol);
		}
		else
		{
			if (top_pri_num > priority_num) 
			{
				if (st[top] != '(' || st[top] != '{')
				{
					pop();
					prioritizer(symbol);
				}
				else
				{
					push(symbol);
				}
			}
			else
			{
				push(symbol);
			}
		}
	}
}

void create()// intializing top
{
	top = -1;
}

void main() 
{
	create();
	int i, k, m, n=0, l=0;
	char equ[50], rev_equ[50], rev_output[50];
	printf("Welcome to the program to convert infix expression to prefix expression\n\n");
	printf("\n\nEnter the infix equation :");
	scanf("%s", &equ);
	printf("\n");
	for (k = (strlen(equ)-1); k >= 0; k--)
	{
		rev_equ[l] = equ[k];
		l++;
	}
	for (i=0; i<=strlen(rev_equ); i++)
	{
		if (isalpha(rev_equ[i]))   
		{
			for (j = strlen(output); j <= (strlen(output) + 1); j++)
			{
				output[j] += rev_equ[i]; // operands are added in output
				break;
			}
		}
		else
		{
			prioritizer(rev_equ[i]);
		
		}
	}
	for (m = (strlen(output)-1); m >= 0; m--)
	{
		rev_output[n] = output[m];
		n++;
	}
	printf("Prefix expressin : %s", rev_output);	
}

