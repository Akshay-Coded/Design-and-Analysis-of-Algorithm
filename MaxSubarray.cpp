#include <bits/stdc++.h>
#include <climits>
using namespace std;

void maxSubArraySum(int arr[],int size){
    int max_so_far = 0;
    int max_ending_here = 0,s=0,start = 0,end = 0;
    for(int i=0;i<size;i++){
        max_ending_here+=arr[i];
        if(max_so_far<max_ending_here){
            max_so_far=max_ending_here;
            start=s;
            end = i;
        }
        if(max_ending_here<0){
            max_ending_here=0;
            s=i+1;
        }
    }
    cout<<"maximum subarray length: "<<end-start+1<<endl;
    cout<<"maximum subarray sum: "<<max_so_far<<endl;
    for(int i=start;i<end+1;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}

	maxSubArraySum(a, n);
	return 0;
}
