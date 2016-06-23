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
    for ( int i = 0; i < n; i++ ) {
        int min_val = arr[i];
        int min_index = i;
        for ( int j = i+1; j < n; j++ ) {
            if ( min_val > arr[j] ) {
                min_val = arr[j];
                min_index = j;
            }
        }
        arr[min_index] = arr[i];
        arr[i] = min_val;
    }
    printArray(arr, n);
    return 0;
}
