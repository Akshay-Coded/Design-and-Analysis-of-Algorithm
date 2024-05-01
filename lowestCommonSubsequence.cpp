#include <iostream>
#include <string>
using namespace std;

// Function to print the LCS sequence
void printSequence(string X, string Y, int m, int n, int **L) {
    string lcs_sequence = "";

    // Start from the bottom-right corner of the matrix
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current characters match, move diagonally up-left
        if (X[i - 1] == Y[j - 1]) {
            lcs_sequence = X[i - 1] + lcs_sequence;
            i--;
            j--;
        }
        // If not, move to the cell with the greater value
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS sequence
    cout << "LCS sequence: " << lcs_sequence << endl;
}

// Function to find the length of LCS
int lcs(string X, string Y, int m, int n) {
    int **L = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        L[i] = new int[n + 1];
    }

    // Building the LCS matrix bottom-up
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    printSequence(X, Y, m, n, L); // Call the function to print LCS sequence

    int length = L[m][n];

}


int main() 
{ 
    int m,n;
    string S1,S2;
    cin>>m;//size of S1
    cin>>n;//Size of S2
    cin>>S1;
    cin>>S2;
    //function call
    lcs(S1, S2, m, n); 

    return 0; 
}
