#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace chrono;

// Map to store time and space complexity of sorting algorithms
unordered_map<int, pair<string, string>> complexities = {
    {1, {"O(n^2)", "O(1)"}},   // Bubble Sort
    {2, {"O(n^2)", "O(1)"}},   // Selection Sort
    {3, {"O(n^2)", "O(1)"}},   // Insertion Sort
    {4, {"O(n log n)", "O(n)"}}, // Quick Sort // worst case time= n^2
    {5, {"O(n log n)", "O(n)"}}, // Merge Sort
    {6, {"O(n log n)", "O(1)"}}  // Heap Sort  // all time comple is average case & worst case
                                               // all space comple is worst case
};


// Function prototypes
void bubbleSort(vector<int> &arr);
void selectionSort(vector<int> &arr);
void insertionSort(vector<int> &arr);
void mergeSort(vector<int> &arr, int start, int end);
void quickSort(vector<int> &arr, int start, int end);
void heapify(vector<int> &arr, int n, int i);
void heapSort(vector<int> &arr);
void displayArray(const vector<int> &arr);


//1.   Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}


//2.   Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    // i = 0, ko chod do
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // move elemwnt of arr[0...i-1] that are greter than
        // key to one posiiton ahead of there current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


//3.    Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}


//4.    Quick Sort
void quickSort(vector<int> &arr, int start, int end)
{
    // bs
    if (start >= end)
    {
        return;
    }

    int pivot = end;
    int i = start - 1;
    int j = start;

    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[j]);
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}


//5.  Merge function for merge sort

void Merge2Sortedarr(vector<int> &arr, int start, int end)
{

    int mid = (start + end) / 2;

    // 1 create left and right arr using dynamic allocation
    int lenLeft = mid - start + 1;
    int lenright = end - mid;

    int *left = new int[lenLeft];
    int *right = new int[lenright];

    // 2 copy from actual arr into left and right arr
    int k = start;
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }
    int w = mid + 1;
    for (int i = 0; i < lenright; i++)
    {
        right[i] = arr[w];
        w++;
    }
    // 3  2 pointer apprcoch 2 sort left ans right arr
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrIndex = start;

    while (leftIndex < lenLeft && rightIndex < lenright)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrIndex] = left[leftIndex];
            mainArrIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrIndex] = right[rightIndex];
            mainArrIndex++;
            rightIndex++;
        }
    }
    // 4. if left arr is exhaust
    while (rightIndex < lenright)
    {
        arr[mainArrIndex] = right[rightIndex];
        mainArrIndex++;
        rightIndex++;
    }
    // 4. if right arr is exhaust
    while (leftIndex < lenLeft)
    {
        arr[mainArrIndex] = left[leftIndex];
        mainArrIndex++;
        leftIndex++;
    }

    // 5. dellocation
    delete[] left;
    delete[] right;
}
// Merge Sort
void mergeSort(vector<int> &arr, int start, int end)
{
    // bs
    if (start >= end)
    {
        return;
    }
    // ek case
    int mid = (start + (end - start)) / 2;

    // break left arr
    mergeSort(arr, start, mid);
    // break right arr
    mergeSort(arr, mid + 1, end);

    // merge2sorted arr
    Merge2Sortedarr(arr, start, end);
}


//6.    Heapify function for Heap Sort
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
// Heap Sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}



// Display Array
void displayArray(const vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> arr;
    int n, choice;

    cout << "\nSelect a Sorting Algorithm (1-7):\n";
    cout << "1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort \n4. Quick Sort \n5. Merge Sort \n6. Heap Sort\n7. Exit.. \n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 7)
    {
        cout << "Exiting...\n";
        return 0;
    }

    if (choice < 1 || choice > 7)
    {
        cout << "Invalid choice! Exiting program...\n";
        return 1;
    }

    cout << "Enter the number of elements: ";
    cin >> n;

    arr.resize(n);

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = chrono::steady_clock::now();

    switch (choice)
    {
    case 1:
        bubbleSort(arr);
        cout << "Sorted using Bubble Sort:\n";
        break;
    case 2:
        selectionSort(arr);
        cout << "Sorted using Selection Sort:\n";
        break;
    case 3:
        insertionSort(arr);
        cout << "Sorted using Insertion Sort:\n";
        break;
    case 4:
        mergeSort(arr, 0, n - 1);
        cout << "Sorted using Merge Sort:\n";
        break;
    case 5:
        quickSort(arr, 0, n - 1);
        cout << "Sorted using Quick Sort:\n";
        break;
    case 6:
        heapSort(arr);
        cout << "Sorted using Heap Sort:\n";
        break;
    
    }

    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<nanoseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ns\n";

    displayArray(arr);

    // Display Time & Space Complexity
    cout << "Time Complexity: " << complexities[choice].first << endl;
    cout << "Space Complexity: " << complexities[choice].second << endl;

    return 0;
}
