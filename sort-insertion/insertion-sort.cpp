# include<iostream>
using namespace std;

void display(int A[], int size)
{
    for( int i=0; i < size; i++)
    {
        cout<< A[i] << " ";
    }
    cout << endl;
}

void insertionSort(int A[], int size)
{
    for(int j=1; j < size; j++)
    {
        int key= A[j];
        int i = j-1;

        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }

        A[i+1] = key;

        display(A, size);
    }

}

int main()
{
    int A[]= {5,54,154, 23, 8,1,4, 5};
    int size= sizeof(A) / sizeof(A[0]);

    insertionSort(A, size);

    return 0;
}