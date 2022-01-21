void slect_sort(int given_array[])
{
	int x, j,m,b=6;
	int n = 10;
	for (x = 0; x < b ; x++)
	{
    	int minimum_value_holder = x;
        for (j = x + 1; j < b; j++)
        	{
            	if (given_array[j] < given_array[minimum_value_holder])
            	{
                minimum_value_holder = j;
            	}
        	}
        if (minimum_value_holder != x)
        {
        int temp = given_array[x];
        given_array[x] = given_array[minimum_value_holder];
        given_array[minimum_value_holder] = temp;
    	}
	}
}

void main()
{
	int num_array[10];
	int b = 6, k, m;
	for (k=0; k < 6; k++)
	{
		scanf("%d", &num_array[k]);
	}
	slect_sort(num_array);
	for (m = 0; m < b; m++)
	{
		printf("%d |", num_array[m]);
	}
}
