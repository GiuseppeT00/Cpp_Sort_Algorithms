#ifndef SORT_H
#define SORT_H

#include "comp.h"
#include <iostream>
using namespace std;
const int maxN = INT16_MAX;

//Insertion Sort -> O(n^2) in worst/medium case, O(n) in best case (semi-sorted list)
//v[] = array to sort; l = left far (i.e: 0); r = right far (i.e: size-1)
template <typename E> void insertionSort(E v[], int l, int r) {
	for (int i = l + 1; i <= r; i++)
		for (int j = i; (j > 0) && (comp(v[j - 1], v[j])); j--)
			exch(v[j - 1], v[j]);
}

//Bubble Sort -> O(n^2) in worst/medium/best case, O(n^2) swap in each case
//v[] = array to sort; l = left far (i.e: 0); r = right far (i.e: size-1)
template <typename E> void bubbleSort(E v[], int l, int r) {
	for (int i = l; i < r; i++)
		for (int j = r; j > i; j--)
			compexch(v[j - 1], v[j]);
}

//Selection Sort -> O(n^2) in worst/medium/best case, but O(n) swap (n-1 swaps in worst case)
//v[] = array to sort; l = left far (i.e: 0); r = right far (i.e: size-1)
template <typename E> void selectionSort(E v[], int l, int r) {
	int index;
	for (int i = l; i < r; i++)
	{
		index = i;
		for (int j = i + 1; j <= r; j++)
			if (comp(v[index], v[j])) index = j;
		exch(v[i], v[index]);
	}
}

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

//Partition function for quick sort (it finds the right position of the pivot)
template <typename E> int partition(E v[], int l, int r) {
	int i = l - 1, j = r;
	int p_index = r;
	E pivot = v[p_index];

	while (i < j) {
		do
		{
			if (i == j) break;
			i++;
		} while (v[i] <= pivot); 
		do
		{
			if (j == i) break;
			j--;
		} while (pivot < v[j]);
		if (i != j) exch(v[i], v[j]);
	}
	if (i != p_index) exch(v[i], v[p_index]);
	return i;
}

//Quick Sort
template <typename E> void quickSort(E v[], int l, int r) {
	if (l >= r) return;
	
	int p = partition(v, l, r);

	quickSort(v, l, p - 1);
	quickSort(v, p + 1, r);
}


#endif // !SORT_H