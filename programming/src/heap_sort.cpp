#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for ( int i = 1; i <= n; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert (int arr[], int x, int n) {
    arr[n] = x;
    int i = n/2;
    while ( i >= 1 && arr[i] > arr[n] ) {
        int temp = arr[i];
        arr[i] = arr[n];
        arr[n] = temp;
        i = i/2;
        n = n/2;
    }
}

int pop (int arr[], int n) {
    int result = arr[1];
    arr[1] = arr[n];
    int j = 1;
    while ( j <= (n-1)/2 ) {
        if ( arr[j] > arr[2*j] && arr[2*j] <= arr[2*j+1] ) {
            int temp = arr[j];
            arr[j] = arr[2*j];
            arr[2*j] = temp;
            j = 2*j;
        } else if ( arr[j] > arr[2*j+1] && arr[2*j+1] <= arr[2*j] ) {
            int temp = arr[2*j+1];
            arr[2*j+1] = arr[j];
            arr[j] = temp;
            j = j*2+1;
        } else {
            break;
        }
    }
    return result;
}

int main (void) {
    int n;
    int x;
    cin >> n;
    int arr[n+1];
    for ( int i = 1; i <= n; i++ ) {
        cin >> x;
        insert(arr, x, i);
        //printArray(arr, i);
    }
    for ( int i = 1; i <= n; i++ ) {
        cout << pop(arr, n+1-i) << " ";
        //cout << "Head : ";
        //printArray(arr, n-i);
    }
    cout << endl;
    return 0;
}
