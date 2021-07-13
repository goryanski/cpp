#pragma once

int analiz(int* arr, int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key)
			return 1;
	}
	return 0;
}
int* toEnd(int* arr, int& size, int key) {
	arr = (int*)realloc(arr, (size + 1) * sizeof(int));
	arr[size++] = key;
	return arr;
}
int* unicue(int* A, int n, int* B, int m, int& size) {
	size = 0;
	int* C = nullptr;
	for (int i = 0; i < n; i++) {
		if (analiz(B, m, A[i]) == 0 && analiz(C, size, A[i]) == 0)
			C = toEnd(C, size, A[i]);
	}
	for (int i = 0; i < m; i++) {
		if (analiz(A, n, B[i]) == 0 && analiz(C, size, B[i]) == 0)
			C = toEnd(C, size, B[i]);
	}
	return C;
}