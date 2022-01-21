# include <stdio.h>
# include <string.h>
# define MAXSIZE 70

int top, unbalanced = 0;
int st[MAXSIZE]; // declaring stack
char balanced[70], j=-1;

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
	top--;
}

void stack_LIFO_Handeler(char symbol) // handels the elements in stack (push and pop)
{
	if (symbol == '(' || symbol == '{' || symbol == '[')
	{
			push(symbol);
			balanced[j+1] = symbol;
			j++;
	}
	else if (symbol == ')') // it pops all the element till reaching '('
	{
		while (st[top] != '(')
		{
			if (st[top] == '[')
			{
				char brace = ']';
				unbalanced++;
				balanced[j+1] = brace;
				j++;
			}
			if (st[top] == '{')
			{
				char brace = '}';
				unbalanced++;
				balanced[j+1] = brace;
				j++;
			}
			pop();
		}
		pop();
		balanced[j+1] = symbol;
		j++;
	}
	else if (symbol == '}') // it pops all the element till reaching '{'
	{
		while (st[top] != '{')
		{
			if (st[top] == '[')
			{
				char brace = ']';
				unbalanced++;
				balanced[j+1] = brace;
				j++;
			}
			if (st[top] == '(')
			{
				char brace = ')';
				unbalanced++;
				balanced[j+1] = brace;
				j++;
			}
			pop();
		}
		pop();
		balanced[j+1] = symbol;
		j++;

	}
	else if (symbol == ']') // it pops all the element till reaching '['
	{
		while (st[top] != '[')
		{
			if (st[top] == '(')
			{
				char brace = ')';
				unbalanced++;
				balanced[j+1] = brace;
				j++;
			}
			if (st[top] == '{')
			{
				char brace = '}';
				unbalanced++;
				balanced[j+1] = brace;
				j++;
			}
			pop();
		}
		pop(); 
		balanced[j+1] = symbol;
		j++;
	}
	else
	{
		balanced[j+1] = symbol;
		j++;
		
	}
}
void create()// intializing top
{
	top = -1;
}

void main() 
{
	create();
	int i,total_unbalanced=0;
	char equ[70];
	printf("\n\nEnter here :");
	scanf("%s", &equ);
	printf("\n");
	for (i=0; i<=strlen(equ); i++)
	{
		if (equ[i] != '\0')
		stack_LIFO_Handeler(equ[i]); 
	}
	total_unbalanced = (top+1) + unbalanced;
	if (top != -1)
	{
		while (top != -1)
		{
			if (st[top] == '[')
			{
				char brace = ']';
				balanced[j+1] = brace;
				j++;
			}
			if (st[top] == '{')
			{
				char brace = '}';
				balanced[j+1] = brace;
				j++;
			}
			if (st[top] == '(')
			{
				char brace = ')';
				balanced[j+1] = brace;
				j++;
			}
			pop();
		}
	}
	if (total_unbalanced == 0)
	{
		printf("The expression is balanced ");
	}
	else
	{
		printf("Error braces are not balanced\n\n");
		printf("Balanced expression : %s", balanced);
	}
}

