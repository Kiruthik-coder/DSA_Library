#include <stdio.h>  
#include <string.h>

# define max 6  
int Buffer[max], DVD[100], l = -1, j = 0; 
int front=-1;  
int rear=-1;  
 
void enqueue(char element)  
{
    if(front==-1 && rear==-1)   
    {  
        front=0;  
        rear=0;  
        Buffer[rear]=element; 
        printf("\n");
		printf("%c has been enqueued\n", Buffer[rear]);  
    }  
    else if((rear+1)%max==front)  
    {  
        printf("\nQueue is overflow..");  
    }  
    else  
    {  
        rear=(rear+1)%max;
        Buffer[rear]=element;      
		printf("%c has been enqueued\n", Buffer[rear]);
    }
}  
  
void dequeue()  
{  
    if((front==-1) && (rear==-1)) 
    { 
        printf("\nQueue is underflow..");  
    }  
	else if(front==rear)  
	{	  
   		DVD[l+1] = Buffer[front];	
   		l++;
   		printf("%c has been dequeued\n", Buffer[front]);
   		front=-1;  
   		rear=-1;  
	}	   
	else  
	{  
   		DVD[l+1] = Buffer[front];	
   		l++; 
   		printf("%c has been dequeued\n", Buffer[front]);
   		front=(front+1)%max;  
	}  
}  
 
void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("\n BUFFER is empty..");  
    }  
    else  
    {  
        while(i<=rear)  
        {  
            printf("%c |", Buffer[i]);  
            i++;
        }  
    }  
}  
void buffer_intialize(char to_write[100])
{
	char symbol;
	for (j; j<= (max-1); j++)
	{
		symbol = to_write[j];
		enqueue(symbol);
	}
	printf("\nBuffer filled, element in buffer now\n");
	display();
	printf("\n");
}

void burner(char to_burn[100])
{ 
	int loop;
	for (loop = 0; loop<= strlen(to_burn); loop++)
	{
		dequeue();
		if (j <= strlen(to_burn))
		{
			enqueue(to_burn[j]);
			j++;
		}
	}	
	printf("\nCompleted Burning process");
}

void main()  
{  
    int choice, m=1;     
    char word[100];
    while (m == 1)
    {
    	printf("\nPlease choose an option\n");
		printf("\n1.Enter a word\n");
		printf("2.Fill Buffer\n");
		printf("3.Burn DVD\n");
		printf("4.Display buffer\n");
		printf("5.Display DVD elements\n");
		printf("6.Quit\n");
		printf("Enter your choice :");
		scanf("%d", &choice);
		printf("\n");
		if (choice == 1)
		{
			printf("\nType the word here :");
			scanf("%s", &word);
			printf("\n");
		}	
		if (choice == 2)
		buffer_intialize(word);
		if (choice == 3)
		burner(word);
		if (choice == 4)
		display();
		if (choice == 5)
		{
			int h;
			printf("\nThe elements in DVD\n");
			for (h=0; h < l; h++)
			printf("%c |", DVD[h]);
		}
		if (choice == 6)
		m = 0;
	}
}  
