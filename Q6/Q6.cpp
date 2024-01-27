#include <bits/stdc++.h>
using namespace std;

// Function to partition the Aay using the middle element as the pivot
int partition(int A[], int low, int high)
{
    int pivot = A[low + (high - low) / 2]; // Choose middle element as pivot
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            ++i;
        } while (A[i] < pivot);

        do
        {
            --j;
        } while (A[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        std::swap(A[i], A[j]);
    }
}

// Function to perform the QuickSort algorithm
void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        // Partition the Array and get the pivot index
        int partitionIndex = partition(A, low, high);

        // Recursively sort the subArrays
        quickSort(A, low, partitionIndex);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    const int n = 1000;
    ofstream inputfile("input6.txt");
    inputfile << n << endl;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input6.txt");
    for (int i = 0; i < n; i++)
    {
        inputFile >> A[i];
    }
    inputFile.close();

    quickSort(A, 0, n-1);

    ofstream outputfile("output6.txt");

    for (int i = 0; i < n; i++)
    {
        outputfile << A[i] << " ";
    }
    outputfile.close();

    return 0;
}
