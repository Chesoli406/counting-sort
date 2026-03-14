#include <iostream>
using namespace std;

void bubbleSortDescending(int arr[], int n, long long &comparisons, long long &swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

void selectionSortDescending(int arr[], int n, long long &comparisons, long long &swaps) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
            swaps++;
        }
    }
}

void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int original[] = {5, 1, 9, 3, 7};
    int n = sizeof(original) / sizeof(original[0]);

    int arr1[100], arr2[100];
    copyArray(original, arr1, n);
    copyArray(original, arr2, n);

    long long bubbleComparisons = 0, bubbleSwaps = 0;
    long long selectionComparisons = 0, selectionSwaps = 0;

    cout << "Original list: ";
    printArray(original, n);

    bubbleSortDescending(arr1, n, bubbleComparisons, bubbleSwaps);
    cout << "\nBubble Sort Result: ";
    printArray(arr1, n);
    cout << "Bubble Comparisons: " << bubbleComparisons << endl;
    cout << "Bubble Swaps: " << bubbleSwaps << endl;

    selectionSortDescending(arr2, n, selectionComparisons, selectionSwaps);
    cout << "\nSelection Sort Result: ";
    printArray(arr2, n);
    cout << "Selection Comparisons: " << selectionComparisons << endl;
    cout << "Selection Swaps: " << selectionSwaps << endl;

    return 0;
}