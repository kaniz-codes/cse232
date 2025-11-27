#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

const int INF = INT_MAX;
const int MAX_VERTICES = 100;

void floydWarshall(int W[MAX_VERTICES][MAX_VERTICES], int n)
{
    int D[MAX_VERTICES][MAX_VERTICES];

    // Initialize D with W
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            D[i][j] = W[i][j];
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (D[i][k] != INF && D[k][j] != INF)
                {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (D[i][j] == INF)
            {
                cout << "∞ ";
            }
            else
            {
                cout << D[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int W[MAX_VERTICES][MAX_VERTICES] = {
        {0, 3, 8, INF, -4},
        {INF, 0, INF, 1, 7},
        {INF, 4, 0, INF, INF},
        {2, INF, -5, 0, INF},
        {INF, INF, INF, 6, 0}

    };

    int n = 5;

    floydWarshall(W, n);

    return 0;
}
