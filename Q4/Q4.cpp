#include <bits/stdc++.h>
using namespace std;

// partition, quickSelect, findMedian functions are related to approach based on quick sort
//  time complexity best case: O(1)    avg case: O(n)   worst case: O(n^2)

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex == k)
        {
            return arr[partitionIndex];
        }
        else if (partitionIndex < k)
        {
            return quickSelect(arr, partitionIndex + 1, high, k);
        }
        else
        {
            return quickSelect(arr, low, partitionIndex - 1, k);
        }
    }
    return -1; // This should not happen for a valid input
}

double findMedian(int arr[], int size)
{
    if (size % 2 == 1)
    {
        // If the size is odd, return the middle element directly
        return quickSelect(arr, 0, size - 1, size / 2);
    }
    else
    {
        // If the size is even, return the average of the two middle elements
        int median1 = quickSelect(arr, 0, size - 1, size / 2 - 1);
        int median2 = quickSelect(arr, 0, size - 1, size / 2);
        return (static_cast<double>(median1) + median2) / 2.0;
    }
}

// optimised approach using STL, time complexity O(n)
double Median(vector<int> a,
              int n)
{

    if (n % 2 == 0)
    {

        nth_element(a.begin(),
                    a.begin() + n / 2,
                    a.end());

        nth_element(a.begin(),
                    a.begin() + (n - 1) / 2,
                    a.end());

        return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
    }

    else
    {

        nth_element(a.begin(),
                    a.begin() + n / 2,
                    a.end());

        return (double)a[n / 2];
    }
}

int main()
{
    const int n = 1000;
    ofstream inputfile("input4.txt");
    inputfile << n << endl;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input4.txt");
    for (int i = 0; i < n; i++)
    {
        inputFile >> A[i];
    }
    inputFile.close();

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }                                         // By sorting array, Time complexity O(nlogn)
    // sort(arr, arr + n);
    // if(n%2!=0){
    //     cout << arr[n / 2];
    // }
    // else{
    //     int result = arr[n / 2] + arr[(n - 1) / 2];
    //     cout << result / 2;
    // }

    // double median = findMedian(arr, n);
    // cout << "Median: " << median << endl;

    // vector<int> arr = {1, 3, 4, 2,
    //                    7, 5, 8, 6};

    // Function Call

    ofstream outputfile("output4.txt");

    outputfile << "Median: " << findMedian(A, n) << endl;

    outputfile.close();

    return 0;
}