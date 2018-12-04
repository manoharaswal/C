#include <stdio.h>
#include <stdlib.h>

void printRepeating(int arr[], int size)
{
	int i;
	printf("The repeating elements are: \n");
	for (i = 0; i < size; i++)
	{
		if (arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			printf("%d ", abs(arr[i]));
	}
	printf("\n");
}

int main()
{
	int i;
	int arr[] = {1, 2,5, 3, 1, 3, 6, 6 , 5};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	for(i = 0;i < arr_size;i++) 
		printf("%d ",arr[i]);
	printf("\n");
	printRepeating(arr, arr_size);
	return 0;
}

