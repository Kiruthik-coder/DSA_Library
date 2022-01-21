# include <stdio.h>
# include <string.h>

int bubble_sort(int array[20])
{
	int i, j;
	int n = 10;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (array[j] > array[(j+1)])
            {
            	int temp_memory = array[j];
                array[j] = array[(j+1)];
                array[(j + 1)] = temp_memory;
			}
		}
	}
}

void main()
{
	int num_array[10];
	int b = 10, k, m;
	for (k=0; k < 10; k++)
	{
		scanf("%d", &num_array[k]);
	}
	bubble_sort(num_array);
	for (m = 0; m < b; m++)
	{
		printf("%d |", num_array[m]);
	}
}
