#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(int arr[], int left, int right) {
    for ( int i = left; i <= right; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quick_sort(int arr[], int left, int right) {
    if ( left >= right ) {
        return;
    }
    int pivot = arr[left];
    int b[right - left + 1];
    int j = 0;
    int k = right - left;
    for ( int i = left + 1; i <= right; i++ ) {
        if ( arr[i] <= pivot ) {
            b[j++] = arr[i];
        } else {
            b[k--] = arr[i];
        }
    }
    b[j] = pivot;
    k = 0;
    for ( int i = left; i <= right; i++ ) {
        arr[i] = b[k++];
    }
    quick_sort(arr, left, left+j-1);
    quick_sort(arr, left+j+1, right);
}

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i]; 
    }
    quick_sort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
