#include <iostream>
using namespace std;
int main()
{
    int A[] = {5, 54, 2, 5, 4, 6, 1, 3};
    int n = sizeof(A) / sizeof(A[0]);
    for (int j = 1; j < n; j++)
    {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
        for (int k = 0; k < n; k++)
        {
            cout << A[k] << " ";
        }
        cout << endl;
    }
    /* for(int k=0;k<n;k++)
 {
     cout<<A[k]<<" ";
 }
 */
    return 0;
}
