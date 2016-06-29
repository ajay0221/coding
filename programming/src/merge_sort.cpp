#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for ( int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int left, int middle, int right, int alt[]) {
    int i = left;
    int j = middle + 1;
    int k = 0;
    while ( i <= middle && j <= right ) {
        if ( arr[i] <= arr[j] ){
            alt[k++] = arr[i++];
        } else {
            alt[k++] = arr[j++];
        }
    }
    while ( i <= middle ) {
        alt[k++] = arr[i++];
    }
    while ( j <= right ) {
        alt[k++] = arr[j++];
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = (left + right)/2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    int alt[right - left + 1];
    merge(arr, left, middle, right, alt);
    int k = 0;
    for ( int i = left; i <= right; i++ ) {
        arr[i] = alt[k++];
    }
}

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i]; 
    }
    merge_sort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
