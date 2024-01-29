#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
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
    const int n = 100;
    ofstream inputfile("input3.txt");
    inputfile << n << endl;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input3.txt");
    for (int i = 0; i < n; i++)
    {
        inputFile >> A[i];
    }
    inputFile.close();

    insertionSort(A, n);

    ofstream outputfile("output3.txt");

    for (int i = 0; i < n; i++)
    {
        outputfile << A[i] << " ";
    }
    outputfile.close();
}