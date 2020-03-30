// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Selection Sort, a sorting algorithm with O(n^2) complexity in every case.
// It's good when swap take a lot of memory, because it made a max of n-1 swap


#ifndef SELECTION_H
#define SELECTION_H

#include "comp.h"

template <typename E> void selectionSort(E v[], int start, int size) {
	int index;
	for (int i = start; i < size - 1; i++)
	{
		index = i;

		for (int j = i + 1; j < size; j++)
			if (comp(v[index], v[j])) index = j;

		if (i != index) exch(v[i], v[index]);
	}
}


#endif // !SELECTION_H