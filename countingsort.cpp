#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = *max(arr, arr + n);
    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    for (int num : arr) cout << num << " ";
    return 0;
}
