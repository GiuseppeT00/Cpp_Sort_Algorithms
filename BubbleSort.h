#ifndef BUBBLE_H
#define BUBBLE_H

#include "comp.h"

template <typename E> void bubbleSort(E v[], int start, int size) {
	for (int i = start; i < size - 1; i++)
		for (int j = size - 1; j > i; j--)
			compexch(v[j - 1], v[j]);
}


#endif // !BUBBLE_H