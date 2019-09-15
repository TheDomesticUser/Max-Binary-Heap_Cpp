#pragma once
#include <iostream>
#include <vector>

template<class T>
class MaxBinaryHeap
{
	std::vector<T> heap;
public:
	inline void swap(T& val1, T& val2);
	void insert(const T& value);
	T extractMax();
	unsigned int size() const { return heap.size(); }

};

template<class T>
inline void MaxBinaryHeap<T>::swap(T& val1, T& val2)
{
	const T buffer = val1;
	val1 = val2;
	val2 = buffer;
}

template<class T>
void MaxBinaryHeap<T>::insert(const T& value)
{
	heap.push_back(value);
	unsigned int index = heap.size(); // Remember to always subtract index by 1 when accessing elements

	while (index - 1 > 0) {
		T& child = heap[index - 1];
		T& parent = heap[(index / 2) - 1];

		if (child > parent) {
			swap(child, parent);
			index /= 2;
			continue;
		}
		break;
	}
}

template<class T>
T MaxBinaryHeap<T>::extractMax()
{
	const T maxValue = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();

	unsigned int index = 1;

	while (true) {
		if ((index * 2) - 1 < heap.size()) { // Verify the left child index isn't out of range
			T& leftChild = heap[(index * 2) - 1];
			T& largerChild = leftChild;
			unsigned int newIndex = (index * 2) - 1; // Assign the new index after the values are swapped

			if (index * 2 < heap.size()) { // Verify the right child index isn't out of range
				T& rightChild = heap[index * 2];

				if (rightChild > leftChild) newIndex = index * 2;
			}

			if (heap[index - 1] < heap[newIndex]) swap(heap[index - 1], heap[newIndex]);
			else break;

			index = newIndex + 1;
		} else {
			break;
		}
	}
	return maxValue;
}
