#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int m, int n)
{
    for (int i = m; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    const int n = 1000, m = 500;
    ofstream inputfile("input2.txt");
    inputfile << n << " " << m << endl;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input2.txt");
    for (int i = 0; i < n; i++)
    {
        inputFile >> A[i];
    }
    inputFile.close();

    insertionSort(A, m, n);

    ofstream outputfile("output2.txt");

    for (int i = 0; i < n; i++)
    {
        outputfile << A[i] << " ";
    }
    outputfile.close();
}