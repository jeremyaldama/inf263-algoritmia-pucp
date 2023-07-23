#include <stdio.h>

void BubbleSort(int arr[], int left)
{
    int i, j, temp;

    for (i = 0; i <= left - 1; i++)
    {
        for (j = 0; j <= left - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {20, 4, 1, 9, 10, 5, 7, 20130, 0, -1, -10,0};
    int n = sizeof(arr) / sizeof(int);
    BubbleSort(arr, n - 1);
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}