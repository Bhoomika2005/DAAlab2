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

    int *C = new int[m + n];

    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }

    while (i < m)
    {
        C[k++] = A[i++];
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }

    ofstream outputfile("output1a.txt");

    for (int i = 0; i < n; i++)
    {
        outputfile << A[i] << " ";
    }
    outputfile.close();

    // Time complexity O(m+n) for best, avg, worst cases as we traverse both arrays once.
    // This is the optimised approach
    cout << endl;
    return 0;
}