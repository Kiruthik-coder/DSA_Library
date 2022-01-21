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
	int a[10] = {11,53,779,19,1,4,5,88,100,10};
	shell_sort(a, 10);
	
	int h, n=10;
	for (h=0; h<n; h++)
	{
		printf("%d |",a[h]);
	}
}
