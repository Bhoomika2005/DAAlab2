#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    const int n = 1000;
    ofstream inputfile("input5.txt");
    inputfile << n << endl;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 10;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input5.txt");
    for (int i = 0; i < n; i++)
    {
        inputFile >> A[i];
    }
    inputFile.close();

    // int n = sizeof(A) / sizeof(A[0]); By sorting the given array
    // sort(A, A + n);                    O(logn)
    // cout << A[0] + A[1];

    // But we can optimize it to O(n) (traversing the entire array once)
    ll first = min(A[0], A[1]);
    ll sec = max(A[0], A[1]);
    for (int i = 2; i < n; i++)
    {
        if (A[i] < first)
        {
            sec = first;
            first = A[i];
        }
        else if (A[i] < sec && A[i] != first)
        {
            sec = A[i];
        }
    }

    ofstream outputfile("output5.txt");
    outputfile << "first minima: " << first << endl;
    outputfile << "second minima: " << sec << endl;
    outputfile.close();

    return 0;
}