#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floydWarshall(int dist[][V]){
    int i,j,k;
    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i][j]>(dist[i][k]+dist[k][j])&&(dist[i][k]!=INF&&dist[k][j]!=INF)){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    printSolution(dist);
}

// Driver program to test above functions
int main()
{
	
	int graph[4][4];
	
	for(int i=0;i<4;i++){
	    for(int j=0;j<4;j++){
	        cin>>graph[i][j];
	    }
	}


	floydWarshall(graph);
	return 0;
}
