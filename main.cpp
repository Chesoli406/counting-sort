#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSortDescending(int arr[], int n, long long &comparisons, long long &swaps) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
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

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

void printSample(int arr[], int n) {
    int limit = (n < 20) ? n : 20;
    for (int i = 0; i < limit; i++) {
        cout << arr[i] << " ";
    }
    if (n > 20) {
        cout << "...";
    }
    cout << endl;
}

void runExperiment(int n) {
    int* original = new int[n];
    int* bubbleArray = new int[n];
    int* selectionArray = new int[n];

    generateRandomArray(original, n);
    copyArray(original, bubbleArray, n);
    copyArray(original, selectionArray, n);

    long long bubbleComparisons = 0, bubbleSwaps = 0;
    long long selectionComparisons = 0, selectionSwaps = 0;

    bubbleSortDescending(bubbleArray, n, bubbleComparisons, bubbleSwaps);
    selectionSortDescending(selectionArray, n, selectionComparisons, selectionSwaps);

    cout << "\n==============================" << endl;
    cout << "List size: " << n << endl;
    cout << "Bubble Sort -> Comparisons: " << bubbleComparisons
         << ", Swaps: " << bubbleSwaps << endl;
    cout << "Selection Sort -> Comparisons: " << selectionComparisons
         << ", Swaps: " << selectionSwaps << endl;
    cout << "Sorted sample (Bubble): ";
    printSample(bubbleArray, n);

    delete[] original;
    delete[] bubbleArray;
    delete[] selectionArray;
}

int main() {
    srand(time(0));

    int sizes[] = {1, 2, 3, 4, 5, 10, 250, 999, 9999, 89786, 789300, 1780000};
    int totalSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < totalSizes; i++) {
        runExperiment(sizes[i]);
    }

    return 0;
}