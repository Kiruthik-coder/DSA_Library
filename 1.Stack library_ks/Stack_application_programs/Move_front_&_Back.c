# include <stdio.h>
// creating stack
# define MAXSIZE 100
int st[MAXSIZE], top_1, top_2;

void create()// intializing top
{
	top_1 = -1;// 0 - 49 back stack
	top_2 = 49;// 50 - 99 front stack
}

void push(int iteration) // pushes element into the stack
{
	int loop_control=0;
	while (loop_control < iteration)
	{
		if (top_1<=MAXSIZE-1)
		{
			int element;
			printf(" Enter reg number (%d/%d):", (loop_control+1), iteration);
			scanf("%d", &element);
			printf("\n");
			st[top_1+1] = element;// inserting element 
			top_1++;	
		}
		else
		{
			printf(" !! ERROR STACK OVERFLOW_-_-_-_-_-_-_-\n");
		}
		loop_control++;
	}
}
void pop(char st_name)
{
	if (st_name == '<')
	{
		st[top_2+1] = st[top_1];
		top_2++;
		top_1--; 
	}
	if (st_name == '>')
	{
		st[top_1+1] = st[top_2];
		top_1++;
		top_2-- ;
	}
}

void move_back(char symbol, int numm)
{
	if (top_1 == -1)
	{
		printf("Can't Move back");
	}
	else
	{
		pop(symbol);
		printf(" Reg no (%d/%d) :%d", (top_1+1), numm, st[top_1]);
	}
}

void move_front(char symbol,int num)
{
	if (top_2 <= 49)
	{
		printf("Can't move front'");
	}
	else
	{
	pop(symbol);
	printf(" Reg no (%d/%d) :%d", (top_1+1), num, st[top_1]);
	}
}




void display(char stack)
{
	if (stack == 'b')
	{
		if (top_1 == -1)
		{
			printf("------STACK IS EMPTY------\n");
		}
		else
		{
			int i;
			printf("The elements in the back stack are\n");
			for (i=0; i<=top_1; i++)
			{
				printf("%d  | \t",st[i]);
			}
		}
	}
	else if (stack == 'f')
	{
		if (top_2 == 49)
		{
			printf("------STACK IS EMPTY------\n");
		}
		else
		{
			int i;
			printf("The elements in the front stack are\n");
			for (i=50; i<=top_2; i++)
			{
				printf("%d  | \t",st[i]);
			}
		}
	}
}

void main()
{
	create();
	int num_of_student, register_num,j = 1, temp;
	char cmd[1];
	printf("\n");	
	printf(" Enter number of students : ");
	scanf("%d", &num_of_student);
	push(num_of_student);
	printf(" Menu to check entered reg.no\n");
	temp = num_of_student;
	printf("\nINSTRUCTIONS--------------------\nEnter '>' to move forward\nEnter '<' to move backward\nEnter 'f' to display front stack\nEnter 'b' to display back stack \n");
	while (j != 0)
	{

		printf("\nCOMMAND : ");
		scanf("%s", &cmd);
		if (cmd[0] ==  '<')
		{
			move_back(cmd[0], temp);
		}
		else if (cmd[0] == '>')
		{
			move_front(cmd[0], temp);
		}
		else if (cmd[0] == 'B' || cmd[0] == 'b')
		{
			display('b');
		}
		else if (cmd[0] == 'F' || cmd[0] == 'f')
		{
			display('f');
		}
		else
		{
			j = 0;
		}
	}
}

