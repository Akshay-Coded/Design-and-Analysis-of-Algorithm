#include <bits/stdc++.h>
using namespace std;

#define INF 99999

void printSolution(int distance[100], int n,int source){
    cout << "From source vertex " << source << endl;
    for (int i = 0; i < n; i++) {
        cout << "Distance of vertex " << i + 1 << ":";
        if (distance[i] == INFINITY) {
            cout << "INFINITY" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

void bellmanFord(int n,int source,int weight[100][100]){
    int distance[100];
    for(int i=0;i<n;i++){
        distance[i]=INF;
    }
    distance[source-1]=0;
    int i,u,v;
    for(i=0;i<n;i++){
        for(u=0;u<n;u++){
            for(v=0;v<n;v++){
                if(weight[u][v]!=0 && distance[u] != INF && distance[v]>(distance[u]+weight[u][v])){
                    distance[v]=(distance[u]+weight[u][v]);
                }
            }
        }
    }
    printSolution(distance,n,source);
}

// Driver program to test above functions
int main() {
    int n;
    cin >> n;
    
    int weight[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }
    
    bellmanFord(n, 5, weight);
    
    return 0;
}
