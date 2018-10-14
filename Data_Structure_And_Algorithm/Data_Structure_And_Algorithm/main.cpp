#include"SortTestHelper.h"
#include"Student.h"

int main() {
	int n = 50000;
	int *arr = SortHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortHelper::copyArray(arr, n);
	SortHelper::testSort("Merge Sort BU", mergeSortBU, arr, n);
	SortHelper::testSort("Merge Sort", merge_Sort, arr2, n);
	delete[] arr;
	delete[] arr2;
	return 0;
}