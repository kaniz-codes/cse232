#include <iostream>
using namespace std;
int partition(int array[], int p, int r)
{
    int pivot = array[r];
    int i = p-1;

    for (int j = p; j < r; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[r]);
    return i + 1;
}

void Quicksort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        Quicksort(array, p, q - 1);
        Quicksort(array, q + 1, r);
    }
}
void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int array[] = {2,8,7,1,3,5,6,4};
    int n = sizeof(array) / sizeof(array[0]);
    Quicksort(array, 0, n - 1);
    display(array, n);

    return 0;
}