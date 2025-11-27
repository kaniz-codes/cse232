#include <iostream>
using namespace std;

#define INF 999
#define MAX 100

// Function to perform Floyd-Warshall algorithm
void floydWarshall(int n, int W[MAX][MAX], int D[MAX][MAX]) {
    // Initialize D with W
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = W[i][j];
        }
    }

    // FW algorithm
    for (int k = 0; k < n; k++) {
        cout << "\nStep " << k + 1 << ": After considering vertex " << k << " as an intermediate vertex:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }

        // Print the matrix for this step
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][j] >= INF)
                    cout << "INF  ";
                else
                    cout << D[i][j] << "    ";
            }
            cout << endl;
        }
    }

    // Final output
    cout << "\nFinal Shortest Distance Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] >= INF)
                cout << "INF  ";
            else
                cout << D[i][j] << "    ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int W[MAX][MAX];  // given edges weights
    int D[MAX][MAX];  // shortest path distances

    cout << "Enter given matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }

    // Call the function
    floydWarshall(n, W, D);

    return 0;
}
