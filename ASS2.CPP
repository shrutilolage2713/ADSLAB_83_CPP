/*
Assignment No. 2 ADSL by Shruti Lolage Bearing PRN UCS23F1083
Problem 2: Move all zeroes to the end of an array.
Statement: Given an array of random numbers, push all zeroes to the end 
           while maintaining the relative order of the non-zero elements.

Approach : Apply Merge Sort manually and then push all 0s to the end.The input should be positive numbers

Input(Input should be positive numbers only):4 0 1 3 0 5
Output:1 3 4 5 0 0
*/

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int temp[100]; // temporary array
    int i = left, j = mid + 1, k = 0;

    // Merge non-zero elements in original order
    while (i <= mid && j <= right) {
        if (arr[i] != 0) temp[k++] = arr[i];
        i++;
        if (arr[j] != 0) temp[k++] = arr[j];
        j++;
    }

    // Remaining non-zero elements in left half
    while (i <= mid) {
        if (arr[i] != 0)
            temp[k++] = arr[i];
        i++;
    }

    // Remaining non-zero elements in right half
    while (j <= right) {
        if (arr[j] != 0)
            temp[k++] = arr[j];
        j++;
    }

    // Count zeros in the range
    int zeroCount = 0;
    for (int m = left; m <= right; m++) {
        if (arr[m] == 0)
            zeroCount++;
    }

    // Add zeros at the end
    while (zeroCount--)
        temp[k++] = 0;

    // Copy back to original array
    for (int m = 0; m < k; m++) {
        arr[left + m] = temp[m];
    }
}

void mergeShiftZeros(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeShiftZeros(arr, left, mid);
    mergeShiftZeros(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[100], n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeShiftZeros(arr, 0, n - 1);

    cout << "\nArray after shifting zeros to the end:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
