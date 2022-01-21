# include <stdio.h>
# include <stdlib.h>

struct Node
{
	int value;
	struct Node *next;
};

typedef struct Node node;

node *front = NULL;
node *rear = NULL;

void enqueue()
{
	node *temp = (node *)malloc(sizeof(node));
	int element;
	printf("\nEnter the element :");
	scanf("%d", &element);
	printf("\n");
	temp -> value = element;
	if (front == NULL)
	{
		temp -> next = NULL;
		front = temp;
		rear = temp;
	}
	else
	{
		rear -> next = temp;
		rear = temp;
		rear -> next = NULL;
	}
	printf("\nThe element %d is pushed into Queue", element);
}

void dequeue()
{
	node *temp;
	if (front == NULL)
	{
		printf("\n Error Queue is empty");
	}
	else
	{
		printf("\nThe element %d is dequed from the Queue", front -> value);
		temp = front;
		front = front -> next;
		free(temp);
	}
}

void display()
{
	if (front == NULL)
	{
		printf("\n ---Queue is empty---");
	}	
	else
	{
		printf("\nThe elements in queue are\n");
		node *temp;
		temp = front;
		while (temp != NULL)
		{
			printf("%d |", temp -> value);
			temp = temp -> next;
		}
	}
}

void front_value()
{
	if (front != NULL)
	printf("\nFront value = %d", front -> value);
	else
	printf("\nError stack is empty");
}


void main()
{
	int choice, j=1;
	while (j == 1)
	{
		printf("\n\n_________________________\n\nPlease Choose an option\n_________________________\n\n 1.ENQUEUE ELEMENT\n 2.DEQUEUE ELEMENT\n 3.DISPLAY QUEUE ELEMENTS\n 4.FRONT VALUE\n 5.EXIT\n");
		printf("Enter option number :");
		scanf("%d",&choice);
		printf("\n");
		
		switch (choice)
		{
			case 1 : enqueue();
					 break;
			case 2 : dequeue();
					 break;
			case 3 : display();
					 break;
			case 4 : front_value();
					 break;
			case 5 : j = 0;
					 break;
		}
	}
}
