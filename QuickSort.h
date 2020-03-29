#ifndef QUICK_H
#define QUICK_H

#include "comp.h"
#include <iostream>
using namespace std;

template <class E>
void quickSort(E a[], int l, int r)
{
    if (l >= r) return;
    int p = partition(a, l, r);

    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}


template <class E>
int partition(E a[], int l, int r)
{
    int p_index = r; int cnt = 0;
    E pivot = a[r];
    int i = l - 1, j = r;

    while (i < j) {
        do {
            if (i == j) break;
            i++;
        } while (a[i] <= pivot);
        do {
            if (i == j) break;
            j--;
        } while (pivot < a[j]);

        if (i != j) exch(a[i], a[j]);
    }
    if (i != p_index) exch(a[i], a[p_index]);
    return i;
}



#endif // !QUICK_H

