// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Merge Sort, a sorting algorithm with O(nlogn) complexity in every case.

#ifndef MERGE_H
#define MERGE_H

#include "comp.h"

//Merge Sort
template <typename E> void merge(E v[], int l, int mid, int r) {
	static E temp[maxN];
	int i, j;
	for (i = mid + 1; i > l; i--) temp[i - 1] = v[i - 1];
	for (j = mid; j < r; j++) temp[r + mid - j] = v[j + 1];
	for (int k = l; k <= r; k++)
	{
		if (temp[j] < temp[i]) v[k] = temp[j--];
		else v[k] = temp[i++];
	}
}

//v[] = array to sort; l = left far index; r = right far index
template <typename E> void mergeSort(E v[], int l, int r) {
	if (r <= l) return;
	int mid = (l + r) / 2;

	mergeSort(v, l, mid);
	mergeSort(v, mid + 1, r);

	merge(v, l, mid, r);
}


#endif // !MERGE_H