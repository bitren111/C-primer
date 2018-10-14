#pragma once
#ifndef SortTestHelper_H
#define SortTestHelper_H
#include<ctime>
#include<iostream>
#include<assert.h>
#include <algorithm>
using namespace std;
namespace SortHelper {
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL < rangeR);
		int* arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}

	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	template<typename T>
	void testSort(std::string sortName, void(*sort)(T[], int), T arr[], int n) {
		std::clock_t start_time = std::clock();
		sort(arr, n);
		std::clock_t end_time = std::clock();
		assert(isSorted(arr, n)); //有序
		std::cout << sortName << " " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
		return;
	}

	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n-1; i++) {
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	template<typename T>
	T* copyArray(T a[], int n) {
		int* arr = new int[n];
		std::copy(a, a + n, arr);
		return arr;
	}

	int* generateNearlyOrderedArray(int n, int swapTimes) {
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;
			std::swap(arr[posx], arr[posy]);
		}
		return arr;
	}
}

template<typename T>
void Selection_Sort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
	return;
}

template<typename T>
void Insert_Sort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		T e = arr[i];
		int j;
		for (j = i; j > 0&& e < arr[j - 1]; j--) {
			//swap(arr[j], arr[j - 1]);
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}

template<typename T>
void Insert_Sort(T arr[], int l,int r) {
	for (int i = l + 1; i <= r; i++) {
		T e = arr[i];
		int j;
		for (j = i; j > l&&arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
	return;
}

template<typename T>
void Bubble_Sort(T arr[], int n) {
	int i, j;
	for (int i = 0; i < n - 1; i++) { //次数
		for (int j = 0; j < n - 1-i; j++) { //每次
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<typename T>
void merge_Sort(T arr[], int n) {

	__mergeSort(arr,0,n-1);

}

template<typename T>
void __mergeSort(T arr[], int l, int r) {
	/*if (l >= r)
		return;*/
	if (r - l <= 15) {
		Insert_Sort(arr, l, r);
		return;
	}
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if(arr[mid]>arr[mid+1])
		__merge(arr, l, mid, r);
}

//template<typename T>
void __merge(int arr[], int l, int mid, int r) {
	int* aux=new int[r - l + 1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}//copy
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i-l] < aux[j-l]) {
			arr[k] = aux[i-l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}
	}
	delete[] aux;
}

template<typename T>
void mergeSortBU(T arr[], int n) {

	for (int sz = 1; sz <= n; sz += sz) {// 元素个数
		for (int i = 0; i+sz < n; i += sz + sz) {//每一轮元素位置
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n-1));
		}
	}
}

template<typename T>
void quickSort(T arr[], int n) {
	__quickSort(arr, 0, n - 1);
}
template<typename T>
void __quickSort(T arr[], int l, int r) {
	if (l <= r)
		return;
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template<typename T>
int __partition(T arr[], int l, int r) {
	T v = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}
#endif // !SortTestHelper_H
