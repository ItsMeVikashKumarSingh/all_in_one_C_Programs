#include <stdio.h>

/**
* Swaps the values of two integers.
* @param {int*} a Pointer to the first integer.
* @param {int*} b Pointer to the second integer.
*/
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* Reorganizes the heap structure to maintain the property of the largest element being at the root.
* @param {int[]} arr The array to be heapified.
* @param {int} N The size of the array.
* @param {int} i The index of the current element.
*/
void heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] > arr[largest])
		largest = left;
	if (right < N && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}

/**
* Sorts an array in ascending order using the heap sort algorithm.
* @param {int[]} arr The array to be sorted.
* @param {int} N The size of the array.
*/

void heapSort(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	for (int i = N - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

/**
* Prints the elements of an array.
* @param {int[]} arr The array to be printed.
* @param {int} N The size of the array.
*/

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/**
* The entry point of the program.
*/

int main()
{
	int arr[] = { 1, 8, 4, 2, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
}