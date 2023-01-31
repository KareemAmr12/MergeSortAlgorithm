#include <bits/stdc++.h>
using namespace std;


void partition(int a[], int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r];

    while (true) {
       
        while (a[++i] < v);
            
        while (v < a[--j])
            if (j == l)
                break;

        if (i >= j)
            break;
        swap(a[i], a[j]);

        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }
        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }

    swap(a[i], a[r]);

    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}


void quicksort(int a[], int l, int r)
{
    if (r <= l)
        return;

    int i, j;

    
    partition(a, l, r, i, j);

    
    quicksort(a, l, j);
    quicksort(a, i, r);
}


void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d  ", a[i]);
    printf("\n");
}


int main()
{
    int a[] = { 5, 10, 5, 5, 2, 10, 5, 5, 10, 5, 5, 2, 5 };
    int size = sizeof(a) / sizeof(int);

    
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printarr(a, size);
    system("pause");
    return 0;
}