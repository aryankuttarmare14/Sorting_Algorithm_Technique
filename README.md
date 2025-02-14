# Sorting Algorithms in C++

This project implements multiple sorting algorithms in C++ and provides a user-friendly interface to choose an algorithm for sorting a list of numbers. It also measures the execution time of each sorting algorithm with nanosecond precision.

## Features
- **Implemented Algorithms:**
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Merge Sort
  - Quick Sort
  - Heap Sort
- **Performance Measurement:**
  - The program calculates the time taken by each sorting algorithm to sort the array, now displayed in nanoseconds (ns).
- **Interactive User Interface:**
  - Users can input an array of numbers and select the sorting algorithm to apply.

## How It Works
1. The user provides the number of elements and the array elements.
2. The program displays a menu of sorting algorithms.
3. Based on the user's choice, the selected sorting algorithm is applied to the array.
4. The sorted array and the time taken for sorting are displayed in nanoseconds.

## Prerequisites
- A C++ compiler (e.g., GCC, Clang, or MSVC).
- Basic knowledge of compiling and running C++ programs.

## Usage
1. Clone or download this repository.
2. Compile the program using a C++ compiler. For example:
   ```bash
   g++ -O0 sortingAlgorithms.cpp -o sortingAlgorithms
   ```
3. Run the executable:
   ```bash
   ./sortingAlgorithms
   ```
4. Follow the on-screen instructions to enter the array elements and select a sorting algorithm.

## Example
### Input:
```
Choose a sorting algorithm (1-7:
1. Bubble Sort
2. Insertion Sort
3. Selection Sort
4. Merge Sort
5. Quick Sort
6. Heap Sort
7. Exit
Enter the number of elements: 5
Enter the elements: 9 4 6 2 8

Enter your choice: 4
```
### Output:
```
Sorted using Merge Sort:
2 4 6 8 9
Time taken: 12345 ns
```

## Sorting Algorithm Details
### 1. Bubble Sort
- Compares adjacent elements and swaps them if they are in the wrong order.
- **Time Complexity:**
  - Best: O(n)
  - Worst: O(n^2)
- **Space Complexity:** O(1)

### 2. Insertion Sort
- Builds the sorted array one element at a time by inserting elements at the correct position.
- **Time Complexity:**
  - Best: O(n)
  - Worst: O(n^2)
- **Space Complexity:** O(1)

### 3. Selection Sort
- Selects the minimum element and places it at the correct position.
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)

### 4. Merge Sort
- Divides the array into halves, sorts them recursively, and merges them.
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

### 5. Quick Sort
- Picks a pivot element, partitions the array, and sorts the partitions recursively.
- **Time Complexity:**
  - Best: O(n log n)
  - Worst: O(n^2)
- **Space Complexity:** O(log n) (average case)

### 6. Heap Sort
- A comparison-based sorting algorithm that uses a binary heap data structure to sort elements by repeatedly extracting the largest (or smallest) element.
- **Time Complexity:**
  - Best: O(n log n)
  - Worst: O(n log n)
- **Space Complexity:** O(1)


## Author
- [Aryan Kuttarmare](https://www.github.com/aryankuttarmare14)

## Contact
If you have any questions or need further assistance, please feel free to contact us at aryan.kuttarmare2002@gmail.com
