# include <stdio.h>

int binary_search(int array[], int n, int low, int high)
{
	while (low <= high)
	{
		int mid;
		mid = low + (high-low)/2;
		if (array[mid] ==  n)
		{
			return mid;
		}
		else if (array[mid] < n)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	
	}
	return -1;
}

void shell_sort(int array[], int n)    
{    
	int i, j, k, temp;    
	for (i = n / 2; i > 0; i = i / 2)    
	{    
		for (j = i; j < n; j++)    
		{    
			for(k = j - i; k >= 0; k = k - i)    
			{    
				if (array[k+i] >= array[k])    
				break;    
				else    
				{    
					temp = array[k];    
					array[k] = array[k+i];    
					array[k+i] = temp;    
				}    
			}    
		}		    
	}    
}	   

void main()
{
	int a[10] = {11,53,779, 19 ,1,4,5,88,100,10};
	shell_sort(a, 10);
	
	int result = binary_search(a, 19, 0, 9);
	
	if (result == -1)
	{
		printf("The Element is not in the array\n");
	}
	else
	printf("The Element is in the array at index %d\n", result); 
}


