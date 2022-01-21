# include <stdio.h>

void join(int array[], int start, int mid, int end )
{
    int i = start, j = mid+1, k = start;  
    int temp_array[10];
	  
    while(i <= mid && j <= end)  
    {  
        if(array[i] < array[j])  
        {  
            temp_array[k] = array[i];  
            i++;  
        }  
        else   
        {  
            temp_array[k] = array[j];  
            j++;   
        }  
        k++;  
    }
	  
    if(i > mid)  
    {  
        while(j <= end)  
        {  
            temp_array[k] = array[j];  
            k++;  
            j++;  
        }  
    }  
    else   
    {  
        while(i <= mid)  
        {  
            temp_array[k] = array[i];  
            k++;  
            i++;  
        }  
    }
	  
    int m = start;
	  
    while( m < k)  
    {  
        array[m]= temp_array[m];  
        m++;  
    }   
}


void merge_sort(int array[], int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start+end)/2;
		merge_sort(array, start, mid);
		merge_sort(array, mid+1, end);
		join(array, start, mid, end);
	}
}

void main()
{
	int a[10] = {11,53,779,19,1,4,5,88,100,10};
	merge_sort(a, 0, 9);
	
	int h, n=10;
	for (h=0; h<n; h++)
	printf("%d |", 	a[h]);
}
