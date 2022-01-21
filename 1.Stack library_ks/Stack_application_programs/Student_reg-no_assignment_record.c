# include <stdio.h>
// creating stack
# define MAXSIZE 30
int st[MAXSIZE], top;

void create()// intializing top
{
	top = -1;
}

void push(int iteration) // pushes element into the stack
{
	int loop_control=0;
	while (loop_control < iteration)
	{
		if (top<=MAXSIZE-1)
		{
			int element;
			printf(" Enter reg/roll number (%d/%d):", (loop_control+1), iteration);
			scanf("%d", &element);
			printf("\n");
			st[top+1] = element;// inserting element 
			top++;	
		}
		else
		{
			printf(" !! ERROR STACK OVERFLOW_-_-_-_-_-_-_-\n");
		}
		loop_control++;
	}
}

void display(int n_num)
{
	if (top == -1)
	{
		printf("------The Submission list is empty------\n");
		
	}
	else
	{
		int i;
		printf("The reg.no of first %d students who submitted the assignmet\n", n_num);
		for (i=0; i<=top; i++)
		{
			printf("%d  | \t",st[i]);
		}
	}
}

void first_n(int nth)
{
	if ((top+1) < nth) 
	{
		printf("\nSorry only %d has submitted the assignment", (top+1));
	}
	else
	{
		while (top != nth-1)
		top--;
		display(nth);
	}
}

void top_value()
{
	if (top == -1)
	{
		printf("------The Submission list is empty------\n");
	}
	else
	{
		printf("Student with reg : %d has submitted the last record\n",st[top]);
		
	}
}

void linear_search(int reg_no)
{
	int h, satisfied = 0;
	for (h=0; h<=top; h++)
	{
		if (st[h] == reg_no)
		{
			printf("The student with reg.no %d has submitted the assignment\n", reg_no);
			satisfied = 1;
			break;
		}
	}
	if (satisfied == 0)
	{
	printf("The student with reg.no %d has not submitted the assignment\n", reg_no);
	}
}

int main()
{
	create();
	int choice, j=1, n, num_of_student, register_num;
	while (j == 1)
	{
		printf("\n\nPlease Choose an option\n_________________________\n\n 1.Enter register number\n 2.Display last Assignment submitted\n 3.Display first 'n' number of students\n 4.Search for a student with reg.no\n 5.Close register\n");
		printf("Enter option number :");
		scanf("%d",&choice);
		printf("\n");
		
		switch (choice)
		{
			case 1 : printf(" Enter number of students : ");
					 scanf("%d", &num_of_student);
					 push(num_of_student);
					 break;
			case 2 : top_value();
					 break;
					 
			case 3 : printf("Enter the first 'n' number to show : ");
					 scanf("%d", &n);
					 first_n(n);
					 break;
					
			case 4 : printf("Enter the Reg.no to search:");
				     scanf("%d", &register_num);
					 linear_search(register_num);
					 break;
					 
			case 5 : j = 0;
					 break;
		}	
	}
	return 0;
}

