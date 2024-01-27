#include <bits/stdc++.h>
using namespace std;

int main()
{

    const int m = 1000, n = 1000;
    ofstream inputfile("input1.txt");
    inputfile << m << endl;
    int A[m];
    for (int i = 0; i < m; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile << n << endl;
    int B[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input1.txt");
    for (int i = 0; i < m; i++)
    {
        inputFile >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        inputFile >> B[i];
    }
    inputFile.close();

    ofstream outputfile("output1c.txt");

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
            i++;
        else if (B[j] < A[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            outputfile << B[j] << " ";
            i++;
            j++;
        }
    }

    /* Printing remaining elements of the larger array */
    while (i < m)
        outputfile << A[i++] << " ";

    while (j < n)
        outputfile << B[j++] << " ";

    // Time complexity O(m+n) for best, avg, worst cases as we traverse both arrays once.
    // This is the optimised approach

    outputfile.close();
    return 0;
}
