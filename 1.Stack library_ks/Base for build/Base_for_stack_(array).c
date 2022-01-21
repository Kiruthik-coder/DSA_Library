# include <stdio.h>
// creating stack
# define MAXSIZE 9
int st[MAXSIZE], top;

void create()// intializing top
{
	top = -1;
}

void push() // pushes element into the stack
{
	if (top<=MAXSIZE-1)
	{
		int element;
		printf("Enter the element to be pushed into the stack :");
		scanf("%d",&element);
		printf("\n");
		st[top+1] = element;// inserting element 
		top++;
		printf("Element %d is pushed into the stack\n",element);
		
	}
	else
	{
		printf(" !! ERROR STACK OVERFLOW_-_-_-_-_-_-_-\n");
		printf("INFO : POP ELEMENTS TO PUSH NEW ELEMENT\n");
		
	}
}

void pop() // removes the top element
{
	if (top == -1)
	{
		printf("!! ERROR | NO ELEMENTS IN STACK\n");
	}
	else
	{
		printf("Element %d is popped out of the stack\n",st[top]);
		top--;
		
	}
}

void top_value()
{
	if (top == -1)
	{
		printf("------STACK IS EMPTY------\n");
		
	}
	else
	{
		printf("Element %d is the top element in the stack\n",st[top]);
		
	}
}

void display()
{
	if (top == -1)
	{
		printf("------STACK IS EMPTY------\n");
		
	}
	else
	{
		int i;
		printf("The elements in the stack are\n");
		for (i=0; i<=top; i++)
		{
			printf("%d  | \t",st[i]);
		}
	}
}

int main()
{
	create();
	int choice, j=1;
	while (j == 1)
	{
		printf("\n\n_________________________\n\nPlease Choose an option\n_________________________\n\n 1.PUSH ELEMENT\n 2.POP ELEMENT\n 3.DISPLAY STACK ELEMENTS\n 4.TOP VALUE\n 5.EXIT\n");
		printf("Enter option number :");
		scanf("%d",&choice);
		printf("\n");
		
		switch (choice)
		{
			case 1 : push();
					 break;
			case 2 : pop();
					 break;
			case 3 : display();
					 break;
			case 4 : top_value();
					 break;
			case 5 : j = 0;
					 break;
		}
	}
}

