# Sorting Assignment

## Student Details
**Name:** BRIAN WAFULA  
**Registration Number:** EB3/67300/23  

## Project Description
This project implements two sorting algorithms in C++ without using any built-in sorting functions:

1. **Bubble Sort**
2. **Selection Sort**

Both algorithms sort a list of integers in **descending order**.  
The program also counts and displays:
- the total number of comparisons
- the total number of swaps

## How Bubble Sort Works
Bubble Sort repeatedly compares adjacent elements.  
For descending order, if the left element is smaller than the right element, the two are swapped.  
After each pass, the next largest values move toward the beginning of the array.  
This process continues until the list is sorted.

## How Selection Sort Works
Selection Sort divides the array into a sorted and unsorted part.  
For descending order, it repeatedly finds the maximum value from the unsorted part and places it at the current position.  
This continues until all elements are arranged from largest to smallest.

## Step-by-Step Example Using Bubble Sort
Example list: `5, 1, 9, 3`

### Pass 1
- Compare 5 and 1 → already in descending order
- Compare 1 and 9 → swap → `5, 9, 1, 3`
- Compare 1 and 3 → swap → `5, 9, 3, 1`

### Pass 2
- Compare 5 and 9 → swap → `9, 5, 3, 1`
- Compare 5 and 3 → no swap
- Compare 3 and 1 → no swap

### Pass 3
- Compare 9 and 5 → no swap
- Compare 5 and 3 → no swap
- Compare 3 and 1 → no swap

Final sorted list: `9, 5, 3, 1`

## Time Complexity

### Bubble Sort
- **Best Case:** O(n)  
  When the list is already sorted in descending order and the optimized version stops early.
- **Average Case:** O(n²)  
- **Worst Case:** O(n²)  
  This happens when many swaps are needed.

### Selection Sort
- **Best Case:** O(n²)  
- **Average Case:** O(n²)  
- **Worst Case:** O(n²)  

Selection Sort always scans the remaining unsorted elements to find the maximum, so its number of comparisons stays quadratic.

## Space Complexity
Both Bubble Sort and Selection Sort use only a small fixed number of extra variables such as counters and temporary swap storage.

- **Bubble Sort Space Complexity:** O(1)
- **Selection Sort Space Complexity:** O(1)

This means both are **in-place sorting algorithms**.

## Experiment Results
The program was designed to run on the following list sizes:

`1, 2, 3, 4, 5, 10, 250, 999, 9999, 89786, 789300, 1780000`

### Discussion
Both algorithms are simple to implement, but they are inefficient for very large lists because their average and worst-case running time is O(n²).

- Bubble Sort may perform many swaps.
- Selection Sort usually performs fewer swaps than Bubble Sort.
- For very large inputs such as 789300 and 1780000 items, the runtime becomes impractical.

Therefore, although these algorithms are useful for learning, they are not suitable for large-scale real-world sorting tasks.
