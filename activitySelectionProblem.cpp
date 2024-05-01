#include <bits/stdc++.h> 
using namespace std; 

void printArray(int arr[],int n){
    cout<<"The selected Activities: ";
    for(int i = 0;i<n;i++){
        cout<< arr[i] << " ";
    }
}

void MaxActivities(int start[],int finish[],int n){
    int i=0,j=1,k=1;
    int activity[10];
    activity[0] = i;
    for(j = 1;j < n;j++){
        //Checking for clash in finish time of previous activity and current activity.
        if(start[j]>=finish[i]){
            activity[k]=j;
            k++;
            i=j;
        }
    }
    printArray(activity,k);
}

int main() 
{ 
    int n;
    cin>>n;
    int x;
    cin>>x;
    int s[n]; 
    int f[n]; 
    for(int i = 0; i < n;i++){
        cin>>s[i];
    }
    for(int i = 0; i < n;i++){
        cin>>f[i];
    }
    // Function call 
    MaxActivities(s, f, n); 
    return 0; 
} 
