#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i]; 
    }
    for ( int i = 1; i < n; i++ ) {
        int j = i;
        while ( j > 0 && arr[j-1] > arr[j] ) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        //printArray(arr, n);
    }
    printArray(arr, n);
    return 0;
}
