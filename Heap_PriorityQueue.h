#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

inline void Assert(bool exp, string s) {
	if (!exp) {
		cout << "Assertion failed...! " << s << endl;
		exit(-1);
	}
}

inline int leftChild_index(int i) { return 2 * i; }
inline int rightChild_index(int i) { return 2 * i + 1; }
inline int parent_index(int i) { return i / 2; }

template <typename E> void printPQ(E V[], int S) {
	for (int i = 1; i <= S; i++)
		cout << V[i] << " ";
	cout << endl;
}

template <typename E> void max_fixUp(E V[], int i) {
	while (i > 1 && V[i] > V[parent_index(i)]) {
		swap(V[i], V[parent_index(i)]);
		i = parent_index(i);
	}
}

template <typename E> void max_fixDown(E V[], int i, int S) {
	while (i <= S / 2) {
		int max_index;
		if (leftChild_index(i) < S && rightChild_index(i) < S && V[i] < max(V[leftChild_index(i)], V[rightChild_index(i)]))
			max_index = (max(V[leftChild_index(i)], V[rightChild_index(i)]) == V[leftChild_index(i)] ? leftChild_index(i) : rightChild_index(i));
		else if (leftChild_index(i) < S && V[i] < V[leftChild_index(i)])
			max_index = leftChild_index(i);
		else if (rightChild_index(i) < S && V[i] < V[rightChild_index(i)])
			max_index = rightChild_index(i);
		else break;
		swap(V[i], V[max_index]);
		i = max_index;
	}
}

template <typename E> void min_fixUp(E V[], int i) {
	while (i > 1 && V[i] < V[parent_index(i)]) {
		swap(V[i], V[parent_index(i)]);
		i = parent_index(i);
	}
}

template <typename E> void min_fixDown(E V[], int i, int S) {
	while (i <= S / 2) {
		int min_index;
		if (leftChild_index(i) < S && rightChild_index(i) < S && V[i] > min(V[leftChild_index(i)], V[rightChild_index(i)]))
			min_index = (min(V[leftChild_index(i)], V[rightChild_index(i)]) == V[leftChild_index(i)] ? leftChild_index(i) : rightChild_index(i));
		else if (leftChild_index(i) < S && V[i] > V[leftChild_index(i)])
			min_index = leftChild_index(i);
		else if (rightChild_index(i) < S && V[i] > V[rightChild_index(i)])
			min_index = rightChild_index(i);
		else break;
		swap(V[i], V[min_index]);
		i = min_index;
	}
}

template <typename E> class Heap_MaxPriorityQueue {
private:
	E* V;
	int S;
	int maxSize;
	
public:
	Heap_MaxPriorityQueue(int max) {
		V = new E[max + 1];
		S = 0;
		maxSize = max;
	}

	~Heap_MaxPriorityQueue() { delete[] V; }

	bool empty() { return (S > 0 ? true : false); }

	void insert(const E& it) {
		Assert(S < maxSize, "Capacity exceeded...!");
		V[++S] = it;
		max_fixUp(V, S);
	}

	E getMax_element() {
		Assert(S > 0, "Priority Queue is empty...!");
		swap(V[1], V[S]);
		max_fixDown(V, 1, S);
		return V[S--];
	}

	void print() { printPQ(V, S); }
};

template <typename E> class Heap_MinPriorityQueue {
private:
	E* V;
	int S;
	int maxSize;

public:
	Heap_MinPriorityQueue(int max) {
		V = new E[max + 1];
		S = 0;
		maxSize = max;
	}
	~Heap_MinPriorityQueue() { delete[] V; }

	bool empty() { return (S > 0 ? true : false); }

	void insert(const E& it) {
		Assert(S < maxSize, "Capacity exceeded...!");
		V[++S] = it;
		min_fixUp(V, S);
	}

	E getMin_element() {
		Assert(S > 0, "Priority Queue is empty...!");
		swap(V[1], V[S]);
		min_fixDown(V, 1, S);
		return V[S--];
	}

	void print() { printPQ(V, S); }

};

#endif // !PRIORITY_QUEUE_H