#include <stdio.h>

void radix_sort(int array[], int n)
{
	int max;
	int i,j,k;
	
	for (i =0; i <n; i++)
	{
		max = array[i];
		if ( array[i+1] > max )
		max = array[i+1];
	}	
	int temp_array[max];
//	printf("%d\n",max);
	int digits = 0, temp = max;
	while (temp != 0)
	{
		temp = temp/10;
		digits++;
	}
//	printf("%d\n",digits);
	int unit, divisor = 1, unit_value;; 
	int bucket[max][max], bucket_count[max];
	for (unit = 0; unit < digits; unit++)
	{
		for (i = 0; i<max; i++ )
		{
			bucket_count[i] = 0;
		}
		
		for (i = 0; i < n; i++)
		{
			unit_value = (array[i]/divisor) % 10;
			bucket[unit_value][bucket_count[unit_value]] = array[i];  
            bucket_count[unit_value] += 1;  
		}
		
		int m = 0;  
        for(j=0;j<10;j++)  
        {  
            for(k=0;k<bucket_count[j];k++)  
            {  
                array[m] = bucket[j][k];  
                m++;  
            }  
        }  
        
        divisor *= 10;  
	}
}

void main()
{
	int a[10] = {200,70,34,96,100};
	int n =5;
	radix_sort(a, 5);
	int h;
	for (h=0; h<n; h++)
	printf("%d |", 	a[h]);
}
