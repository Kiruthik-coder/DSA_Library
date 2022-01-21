# include <stdio.h>
 
void Max_heap(int array[], int n)
{
	int i, temp1, temp2, root;
	for ( i = 1; i < n; i++)
	{
		temp1 = i;
		while (temp1 != 0)
		{
			root = (temp1 - 1) / 2;             
            if (array[root] < array[temp1])   
            {
                temp2 = array[root];
                array[root] = array[temp1];
                array[temp1] = temp2;
            }
            temp1 = root;
		}
	}
}

void Heap_sort(int array[], int n)
{
	int i, temp1, temp2, root2;
	Max_heap(array, n);
	
	for ( i = n - 1; i >= 0; i--)
	{
		temp2 = array[0];
		array[0] = array[i];
		array[i] = temp2;
		root2 = 0;
		temp1 = 2 * root2 + 1;
		while (temp1 < i)
		{
			temp1 = 2 * root2 + 1;   
            if (array[temp1] < array[temp1 + 1] && temp1 < i-1)
            temp1 = temp1 + 1;
                    
            if (array[root2]< array[temp1] && temp1 < i)    
            {
                temp2 = array[root2];
                array[root2] = array[temp1];
                array[temp1] = temp2;
            }
            root2 = temp1;
		}
	}
}

void main()
{
	int a[10] = {11,53,779,19,1,4,5,88,100,10};
	Heap_sort(a, 10);
	
	int h, n=10;
	for (h=0; h<n; h++)
	printf("%d |", 	a[h]);
}
