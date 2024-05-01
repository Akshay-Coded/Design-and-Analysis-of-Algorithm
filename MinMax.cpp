#include <iostream>
#include <string>
using namespace std;

struct Pair {
    int min;
    int max;
};

struct Pair MinMax(int arr[], int low, int high) {
    struct Pair minmax, mleft, mright;
    int mid;
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.min = arr[high];
            minmax.max = arr[low];
        } else {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }
    mid = (low + high) / 2; // Corrected calculation of mid
    mleft = MinMax(arr, low, mid);
    mright = MinMax(arr, mid + 1, high);
    if (mleft.min < mright.min) {
        minmax.min = mleft.min;
    } else {
        minmax.min = mright.min;
    }
    if (mleft.max > mright.max) {
        minmax.max = mleft.max;
    } else {
        minmax.max = mright.max;
    }
    return minmax; // Added return statement
}

int arr_position(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    struct Pair result = MinMax(list, 0, n - 1); 
    cout << "Winner: " << arr_position(list, n, result.max) << endl; 
    cout << "Worst player: " << arr_position(list, n, result.min);
    return 0;
}
