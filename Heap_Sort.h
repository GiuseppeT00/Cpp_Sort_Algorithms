#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "Heap_PriorityQueue.h"

template <typename E> void Heap_Sort(E V[], int l, int r) {
	Heap_MaxPriorityQueue<E> PQ(r - l + 1);
	for (int i = l; i <= r; i++)
		PQ.insert(V[i]);
	for (int i = r; i >= l; i--)
		V[i] = PQ.getMax_element();
}


#endif // !HEAP_SORT_H