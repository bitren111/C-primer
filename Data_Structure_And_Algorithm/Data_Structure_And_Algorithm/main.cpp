#include"SortTestHelper.h"
#include"Student.h"
#include"Heap_Sort.h"
int main() {
	/*int n = 100000;
	int* arr1 = SortHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortHelper::copyArray(arr1, n);
	SortHelper::testSort("Merge Sort", merge_Sort, arr1, n);
	SortHelper::testSort("Quick Sort", quickSort, arr2, n);
	delete[] arr1;
	delete[] arr2;

	int swapTimes = 100;
	std::cout << "Test for  Random Nearly Ordered Array, size= " << n << ", swap time =" << swapTimes << endl;
	arr1 = SortHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortHelper::copyArray(arr1, n);
	SortHelper::testSort("Merge Sort", merge_Sort, arr1, n);
	SortHelper::testSort("Quick Sort", quickSort, arr2, n);
	delete[] arr1;
	delete[] arr2;
	std::cout << std::endl;

	cout << "Test for Random Array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortHelper::generateRandomArray(n, 0, 10);
	arr2 = SortHelper::copyArray(arr1, n);
	SortHelper::testSort("Merge Sort", merge_Sort,arr1, n);
	SortHelper::testSort("Quick Sort", quickSort2, arr2, n);
	delete[] arr1;
	delete[] arr2;
	std::cout << std::endl;*/
	MaxHeap<int> heap = MaxHeap<int>(100);
	std::cout << heap.size() << std::endl;
	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		heap.insert(rand() % 100);
	}
	return 0;
}