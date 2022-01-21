# include <stdio.h>

int Divider(int array[], int start, int end)
{
	int left = start, right = end, pivot = start; 
	int flag = 1;
	
	while (flag != 0)
	{
		while (array[pivot] <= array[right] && pivot != right)
		{
			right = right - 1;
		}
		if (pivot == right)
		{
			flag = 0;
		}
		else if (array[pivot] > array[right])
		{
			int temp = array[pivot];
			array[pivot] = array[right];
			array[right] = temp;
			pivot = right;
		}
		
		if (flag != 0);
		{
			while (array[pivot] >= array[left] && pivot != left)
			{
				left = left + 1;
			}
			if (pivot == left)
			{
				flag = 0;
			}
			else if (array[pivot] < array[left])
			{
				int temp = array[pivot];
				array[pivot] = array[left];
				array[left] = temp;
				pivot = left;
			}
		}
	}
	return pivot;
}

void Quick_sort(int array[], int start, int end)
{
	int pivot_element;
	if (start < end)
	{
		pivot_element = Divider(array, start, end);
		Quick_sort(array, start, pivot_element-1);
		Quick_sort(array, pivot_element + 1, end);
	}
}

void main()
{
	int a[10] = {11,53,779,19,1,4,5,88,100,10};
	Quick_sort(a, 0, 9);
	
	int h, n=10;
	for (h=0; h<n; h++)
	printf("%d |", 	a[h]);
}
