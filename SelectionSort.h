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