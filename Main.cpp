// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// A main file to test sorting algorithms

#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
//#include "SortAlgorithms(All_In_One).h"
#include "utility.h"
#include <ctime>
#include <cstdlib>
#define defaultMax 10000


int main(int argc, char *argv[]) {
	srand(time(NULL));
	if (argc < 2)
	{
		cout << "Insert two arguments: number of elements, [0/1] manual fill, random fill." << endl;
		exit(-1);
	}
	Item* V;
	int size = atoi(argv[1]), fill = atoi(argv[2]);
	V = new Item[size];

	if (fill) arrayFill_auto(V, size, defaultMax);
	else {
		int value;
		for (int i = 0; i < size; i++) {
			cin >> value;
			V[i] = value;
		}
	}
	arrayPrint(V, size);

	insertionSort(V, size);
	bubbleSort(V, 0, size - 1);
	selectionSort(V, 0, size - 1);
	quickSort(V, 0, size - 1);
	arrayPrint(V, size);

	return 0;
}