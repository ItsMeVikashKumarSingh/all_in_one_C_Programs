#include <stdio.h>

/**
* Swaps the values of two integers.
* @param {int*} a Pointer to the first integer.
* @param {int*} b Pointer to the second integer.
*/
int swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

/**
* Sorts an array using the selection sort algorithm.
* @param {int[]} arr The array to be sorted.
* @param {int} num The number of elements in the array.
*/
void selectionSort(int arr[] , int num)
{
    for (int i = 0; i < num-1; i++)
    {
       int min=i;
        for (int j = i+1; j < num; j++)
        {
            if (arr[j]<arr[min])
                min=j;
        }      
        swap(&arr[min],&arr[i]); 
    } 
}

/**
* Prints the elements of an array.
* @param {int[]} arr The array to be printed.
* @param {int} count The number of elements in the array.
*/
void printArray(int arr[] , int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[]={1,8,4,2,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n );
    printf("Sorted Array are :\n");
    printArray(arr,n);
    return 0;
}