#include <bits/stdc++.h>
#include <string>
using namespace std;

int board[10][10];
int n;

void printBoard(int board[10][10])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if(board[i][j])
                cout << "1 ";
            else cout<<"0 ";
        printf("\n");
    }
}

bool isSafe(int board[10][10],int row,int col){
    for(int i = 0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j]){
            return false;
        }
    }
    
    for (int i = row, j = col; j >= 0 && i < n; i++, j--){
        if (board[i][j]){
            return false;
        }
    }
    return true;
}

bool NQueenAlg(int board[10][10],int col) {
    if(col>=n){
        return true;
    }
    for(int i = 0;i<n;i++){
        if(isSafe(board,i,col)){
            board[i][col]=1;
            if(NQueenAlg(board,col+1)){
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}


int main() 
{   
    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            board[i][j] = 0;
        }
    }
    
    if(!NQueenAlg(board,0)){
        cout<<"solution does not exist";
    }else{
        printBoard(board);
    }
}
