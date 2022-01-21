#include <stdio.h>
 
#define MAXSIZE 50
 
int queue_array[MAXSIZE], rear = - 1, front = - 1, num_of_trucks=0;

void enqueue()
{
    int get_truck_id;
    if (rear == MAXSIZE - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Enter the truck id  : ");
        scanf("%d", &get_truck_id);
        rear = rear + 1;
        num_of_trucks++;
        queue_array[rear] = get_truck_id;
    }
} 
 
void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Truck with id has been sent out : %d\n", queue_array[front]);
        front = front + 1;
        num_of_trucks--;
    }
} 
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Trucks in queur are (Truck_id) is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 

main()
{
    int choice, n=1;
    while (n == 1)
    {
    	printf("\nPlease choose an option\n");
        printf("\n1.Add an Truck to the queue \n");
        printf("2.Display Trucks id in queue \n");
        printf("3.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            display();
            break;
            case 3:
            n = 0;
            break;
            default:
            printf("Wrong choice \n");
        } 
        if (num_of_trucks == 5)
        {
        	dequeue();
        	dequeue();
		}
    }
} 
 

