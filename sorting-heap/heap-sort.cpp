<<<<<<< HEAD
#include <iostream>
using namespace std;

void exchange(int A[], int i, int j)
{
    /* int temp = A[i];
    A[i] = A[j];
    A[j] = temp; */
    swap(A[i], A[j]);
}

int LEFT(int i)
{
    return 2 * i + 1;
}

int RIGHT(int i)
{
    return 2 * i + 2;
}

int PARENT(int i)
{
    return (i - 1) / 2;
}

void MAX_HEAPIFY(int A[], int i, int heap_size)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    if (l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r < heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        exchange(A, i, largest);
        MAX_HEAPIFY(A, largest, heap_size);
    }
}

void BUILD_MAX_HEAP(int A[], int heap_size)
{

    for (int i = (heap_size / 2) - 1; i >= 0; i--)
    {
        MAX_HEAPIFY(A, i, heap_size);
    }
}

void HEAPSORT(int A[], int n)
{
    int heap_size = n;
    BUILD_MAX_HEAP(A, heap_size);

    for (int i = n - 1; i >= 1; i--)
    {
        exchange(A, 0, i);
        heap_size--;
        MAX_HEAPIFY(A, 0, heap_size);
    }
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[] = {12, 11, 13, 154, 6, 7};
    int size = 6;

    cout << "Array: \n";
    printArray(A, size);

    HEAPSORT(A, size);

    cout << "Sorted array: \n";
    printArray(A, size);

    return 0;
}
=======
#include <iostream>
using namespace std;

void exchange(int A[], int i, int j)
{
    /* int temp = A[i];
    A[i] = A[j];
    A[j] = temp; */
    swap(A[i], A[j]);
}

int LEFT(int i)
{
    return 2 * i + 1;
}

int RIGHT(int i)
{
    return 2 * i + 2;
}

int PARENT(int i)
{
    return (i - 1) / 2;
}

void MAX_HEAPIFY(int A[], int i, int heap_size)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    if (l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r < heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        exchange(A, i, largest);
        MAX_HEAPIFY(A, largest, heap_size);
    }
}

void BUILD_MAX_HEAP(int A[], int heap_size)
{

    for (int i = (heap_size / 2) - 1; i >= 0; i--)
    {
        MAX_HEAPIFY(A, i, heap_size);
    }
}

void HEAPSORT(int A[], int n)
{
    int heap_size = n;
    BUILD_MAX_HEAP(A, heap_size);

    for (int i = n - 1; i >= 1; i--)
    {
        exchange(A, 0, i);
        heap_size--;
        MAX_HEAPIFY(A, 0, heap_size);
    }
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[] = {12, 11, 13, 154, 6, 7};
    int size = 6;

    cout << "Array: \n";
    printArray(A, size);

    HEAPSORT(A, size);

    cout << "Sorted array: \n";
    printArray(A, size);

    return 0;
}
>>>>>>> 8d57da36db2ce69d45c0841519c50e20160957fe
