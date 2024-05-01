#include <iostream>
#include <iomanip>

using namespace std;

void printArray(double arr[],int n){
    for(int i = 0;i < n;i++){
        cout<<setprecision(1)<<arr[i]<<" ";
    }
    cout<<endl;
}

void fractional_knapsack(int capacity,int n,int weight[],int profit[]){
    double ratio[10],result[10];
    int cap = capacity;
    for(int i = 0; i < n; i++){
        ratio[i] = (double)profit[i]/(double)weight[i];
    }
    
    for(int i = 0;i < n;i++){
        int ref = 0,count = 0;
        for(int i = 0;i<n;i++){
            if (ref < ratio[i]){
                ref = ratio[i];
                count = i;
            }
        
        }if(cap>=weight[count]){
            cap-=weight[count];
            result[count] = 1.0;
            ratio[count]=0;
        }else{
            result[count] = (double)cap/ (double)weight[count];
            break;
        }
    }
    printArray(result,n);
}

int main(){
    int capacity,n,weight[10],profit[10];
    cin>>capacity;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>weight[i];
    }
    for(int i = 0;i < n;i++){
        cin>>profit[i];
    }
    fractional_knapsack(capacity,n,weight,profit);
}
