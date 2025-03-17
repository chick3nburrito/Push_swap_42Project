#include "push_swap.h"

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int p;
    int i;
    int j;

    p = arr[low];
    i = low;
    j = high;
    while (i < j)
    {
        while (arr[i] <= p && i <= high - 1)
            i++;
        while (arr[j] > p && j >= low + 1)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int high)
{
    int low;
    int pi;

    low = 0;
    if (low < high)
    {
        pi = partition(arr, low, high);
        if (pi - 1 > low)
            quicksort(arr + low, pi - 1 - low);
        if (pi + 1 < high)
            quicksort(arr + pi + 1, high - (pi + 1));
    }
}

void sort(stack **top)
{
    int len;
    int *values;
    stack *current;
    int i;

    if (check_sort(*top))
        return ;
    len = stack_len(*top);
    values = (int *)malloc(sizeof(int) * len);
    if (!values)
        return ;
    fill_values(values, *top);
    quicksort(values, len - 1);
    i = 0;
    while (i < len)
    {
        printf("%d\n", values[i]);
        i++;
    }
    current = *top;
    i = 0;
    while (i < len && current)
    {
        current->value = values[i];
        current = current->next;
        i++;
    }
    assign_ranks(top, values, stack_len(*top));

    free(values);
}
