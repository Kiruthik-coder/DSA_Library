# include <stdio.h>
# include <stdlib.h>
struct Node
{
	int value;
	struct Node *next;
};

typedef struct Node node;

node *top = NULL;

void push()
{
	node *temp = (node *)malloc(sizeof(node));
	int element;
	printf("\nEnter the element :");
	scanf("%d", &element);
	printf("\n");
	if (top == NULL)
	{
		temp -> value = element;
		temp -> next = NULL;
		top = temp;
	}
	else
	{
		temp -> value = element;
		temp -> next = top;
		top = temp;
	}
	printf("\nThe element %d is pushed into stack", element);
}

void pop()
{
	node *temp;
	if (top == NULL)
	{
		printf("\n Error stack is empty");
	}
	else
	{
		printf("\nThe element %d is poped from the stack", top -> value);
		temp = top;
		top = top -> next;
		free(temp);
	}
}

void display()
{
	if (top == NULL)
	{
		printf("\n ---Stack is empty---");
	}	
	else
	{
		printf("\nThe elements in stack are\n");
		node *temp;
		temp = top;
		while (temp != NULL)
		{
			printf("%d |", temp -> value);
			temp = temp -> next;
		}
	}
}

void top_value()
{
	if (top != NULL)
	printf("\nTOP value = %d", top -> value);
	else
	printf("\nError stack is empty");
}


void main()
{
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
