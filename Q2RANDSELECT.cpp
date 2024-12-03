#include <iostream>
#include <cstdlib>

using namespace std;

int comparisons = 0;


int Partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        comparisons++;
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int RandomPartition(int arr[], int l, int h) {
    int random_pivot = l + rand() % (h - l + 1);
    swap(arr[random_pivot], arr[h]);
    return Partition(arr, l, h);
}

int RandomizedSelect(int arr[], int l, int h, int i) {
    if (l == h) {
        return arr[l];
    }

    int pi = RandomPartition(arr, l, h); 
    int k = pi - l + 1;                 

    if (i == k) {
        return arr[pi]; 
    } else if (i < k) {
        return RandomizedSelect(arr, l, pi - 1, i); 
    } else {
        return RandomizedSelect(arr, pi + 1, h, i - k); 
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i;
    cout << "Enter the position (i) of the smallest element you want to find (1-based index): ";
    cin >> i;

    if (i < 1 || i > n) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    int result = RandomizedSelect(arr, 0, n - 1, i);

    cout << "The " << i << "-th smallest element is: " << result << endl;
    cout << "Total comparisons made: " << comparisons << endl;

    return 0;
}
