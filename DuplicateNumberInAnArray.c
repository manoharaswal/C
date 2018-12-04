/* An array of size N contains numbers ranging from 1 to N-1.
   There is exactly one number is duplicated in the array.
   Write a C program to find the duplicated number?
*/

#include <stdio.h>
#define N 5
int main()
{
	int arr[N];
	int arrSum = 0,i;

	int sum = (N * (N - 1)) / 2; 

	printf("Enter %d integers form 1 to %d, with one duplicate:", N, N-1);

	for (i = 0; i < N; i++)
	{
		scanf ("%d", &arr[i]);
		arrSum += arr[i];
	}

	printf("\nDuplicate number is: %d\n", arrSum - sum);
}
