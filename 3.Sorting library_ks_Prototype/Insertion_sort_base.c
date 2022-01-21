# include <stdio.h>

void Insertion_sort(int array[], int n)
{
	int i, j, key;
	for (i=0; i < n; i++)
	{
		key = array[i];
		j = i - 1;
		while ( j >= 0 && array[j] > key)
		{
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j +1] = key;
	}
}

void main()
{
	int a[10] = {11,53,779,19,1,4,5,88,100,10};
	Insertion_sort(a, 10);
	
	int h, n=10;
	for (h=0; h<n; h++)
	{
		printf("%d |",a[h]);
	}
}
