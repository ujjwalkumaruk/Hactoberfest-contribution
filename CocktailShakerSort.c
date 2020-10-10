#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cocktail_shaker_sort(int arr[], int low, int high)
{
    int flag = 1, i;
    while(flag){
        flag = 0;
        for(i = low; i <= high - 1; i++)
            if(arr[i] > arr[i + 1]){
                swap(&arr[i], &arr[i + 1]);
                flag = 1;
            }
        high--;
        flag = 0;
        for(i = high - 1; i >= low; i--)
            if(arr[i] > arr[i + 1]){
                swap(&arr[i], &arr[i + 1]);
                flag = 1;
            }
        low++;
    }
}

void print_array(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
int main()
{
    srand(time(NULL));
    int n, i;
    printf("\n Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("\n Populating the array with random values.... ");
    for(i = 0; i  < n; i++)
        arr[i] = rand() % 1000 + 1;
    printf("\n\n Array: ");
    print_array(arr, n);
    cocktail_shaker_sort(arr, 0, n - 1);
    printf("\n Array after sorting: ");
    print_array(arr, n);
    printf("\n");
    return 0;
}

