#include <stdio.h>
#define MAXSIZE 50
 
int queue_array[MAXSIZE], rear, front;

void create()
{
	rear = -1;
	front = -1;
}

void enqueue()
{
    int add_item;
    if (rear == MAXSIZE - 1)
    {
    printf("\nError queue Overflow ");
	}
    else
    {
        if (front == - 1)
        {
        front = 0;
    	}
        printf("Enter the element : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
        printf("\nThe element %d has been enqued", queue_array[rear]);
    }
} 
 
void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("\nQueue Underflow ");
        return ;
    }
    else
    {
        printf("\nElement deleted from queue is : %d", queue_array[front]);
        front = front + 1;
    }
} 
 
void display()
{
    int i;
    if (front == - 1)
        printf("\nError the Queue is empty ");
    else
    {
        printf("\nThe elements in Queue are\n");
        for (i = front; i <= rear; i++)
            printf("%d |", queue_array[i]);
        printf("\n");
    }
} 

void main()
{
	create();
    int choice, j=1;
    while (j == 1)
    {
    	printf("\nPlease choose an option:\n");
        printf("1.Add an element to queue(enqueue) \n");
        printf("2.Remove element from queue(dequeue) \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            j = 0;
            break;
            default:
            printf("\nERROR WRONG CHOICE, PLEASE CHOOSE CORRECT OPTION");
        } 
    }
} 
 

