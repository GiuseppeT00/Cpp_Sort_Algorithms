#ifndef COMP_H
#define COMP_H

template<typename E> bool comp(E& A, E& B) {
	if (B < A) return true;
	else return false;
}

template <typename E> void exch(E& A, E& B) {
	E temp = A;
	A = B; B = temp;
}

template <typename E> void compexch(E& A, E& B) {
	if (B < A) exch(A, B);
}




#endif // !COMP_H

