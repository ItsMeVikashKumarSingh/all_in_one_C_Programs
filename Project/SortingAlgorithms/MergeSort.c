#include <stdio.h>

//Defining Merge Function which will be used to merge Sorted array
/**
* Merges two sorted subarrays of arr[].
* @param {int[]} arr The input array.
* @param {int} p The starting index of the first subarray.
* @param {int} q The ending index of the first subarray.
* @param {int} r The ending index of the second subarray.
*/
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

//Defining MergeSort Function
/**
* Sorts the input array using merge sort algorithm.
* @param {int[]} arr The input array.
* @param {int} l The starting index of the array.
* @param {int} r The ending index of the array.
*/
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        //recursively Calling mergeSort Function
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        //Calling Merge function
        merge(arr, l, m, r);
    }
}

//Defining Function for Printing Array
// @param {int[]} arr The input array.
// @param {int} size The size of the array.
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Main Method
int main()
{
    //Creating Array
    int arr[] = {1, 8, 4, 2, 3};

    //Finding Size of Array
    int size = sizeof(arr) / sizeof(arr[0]);

    //Calling MergeSort function
    mergeSort(arr, 0, size - 1);

    //Printing Sorted Array
    printf("Sorted array: \n");
    printArray(arr, size);
}