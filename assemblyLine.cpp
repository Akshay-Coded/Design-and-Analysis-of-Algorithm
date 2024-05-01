#include <bits/stdc++.h>
#include <string>
using namespace std;

// Function to find the lowest time
int assemblyLine(int a[2][10], int t[2][10], int e[2], int x[2],int n) {
    int first,second;
    //initializing the first and second
    first = e[0]+a[0][0];
    second = e[1]+a[1][0];
    for(int i = 1;i<n;i++){
        int up = min(first+a[0][i],second+t[1][i-1]+a[0][i]);
        int down = min(second+a[1][i],first+t[0][i-1]+a[1][i]);
        first = up;
        second = down;
    }
    //returning minimum time
    return min(first+x[0],second+x[1]);
}


int main() 
{   
  //getting inputs
    int n;
    cin>>n;
    int a[2][10];
    int t[2][10];
    int e[2];
    int x[2];
    for(int i = 0;i<2;i++){
        for(int j = 0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j < n-1;j++){
            cin>>t[i][j];
        }
    }
    for(int i=0;i < 2;i++){
        cin>>e[i];
    }
    for(int i=0;i < 2;i++){
        cin>>x[i];
    }
    //function call
    cout<<"Minimum time to assemble: "<<assemblyLine(a,t,e,x,n);
    return 0; 
}
