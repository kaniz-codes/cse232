#include <iostream>
using namespace std;

void Merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + 1 + j];
    }

    L[n1] = 1000000000; 
    R[n2] = 1000000000;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    int A[] = {154, 77, 2, 5, 8, 12, 4, 7, 9, 15};
    int size = sizeof(A) / sizeof(A[0]);

    MergeSort(A, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
