#include <stdio.h>
 
#define MAXSIZE 20
 
int queue_array[MAXSIZE], rear = - 1, front = - 1;

void insert(loop)
{
    int add_rider, i=1;
    while (i <= loop)
    {
    	if (rear == MAXSIZE - 1)
    	printf("Queue Overflow \n");
    	else
    	{
        	if (front == - 1)
        	front = 0;
        	printf("Enter the rider number (%d,%d) : ", i, loop);
        	scanf("%d", &add_rider);
        	rear = rear + 1;
        	queue_array[rear] = add_rider;
    	}
    	i++;
	}
} 
 
void delete()
{
	int j=0;
	printf("RIDE STARTED ----------------------------");
	while (j < 20)
	{
    	if (front == - 1 || front > rear)
    	{
        	printf("\nQueue is empty now for next batch \n");
        	front = -1 ;
			rear = -1;
        	return ;
    	}
    	else
    	{
        	front = front + 1;
    	}
	}
} 
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Members in queue : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 

void vip_handler(int num)
{
	rear = rear + 1;
    queue_array[rear] = queue_array[front];
    queue_array[front] = num;
    printf("\nVIP with number %d is allowed %dst in queue", num, front+1);
}

main()
{
    int choice, m=1, v_num;
    int num_of_mem, adult, child, total, c, a;
    while (m ==
	 1)
    {
    	printf("\n\nPLEASE CHOOSE AN OPTION");
    	printf("\n_____________________________");
        printf("\n1.Allow members in queue\n");
        printf("2.Start Ride for the members in queue \n");
        printf("3.Display all members in queue \n");
        printf("4.VIP Enterance\n");
        printf("5.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
            printf("Enter number of members:");
            scanf("%d", &total);
            printf("Enter number of children:");
            scanf("%d", &c);
            child = child + c;
            printf("Enter number of Adults:");
            scanf("%d", &a);
            adult = adult + a;
            insert(total);
            break;
            case 2:
            if (rear == MAXSIZE -1)
            {
            delete();
            	printf("/nTotal Adults = %d, Total children = %d", adult, child);
            	child = 0; 
				adult = 0;
        	}
            else
            printf("Not possible to start ride only %d members are there", rear+1);
            break;
            case 3:
            display();
            break;
            case 4:
            printf("\nVIP number:");
            scanf("%d", &v_num);
            printf("\n");
            vip_handler(v_num);
            break;
            case 5:
            m = 0;
            break;
        } 
    }
} 
 

