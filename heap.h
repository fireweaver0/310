#ifndef _HEAP_H_
#define _HEAP_H_
#include <string>

struct element{
	int key;
};
class heap{
public:
	int size;
	int capacity;
	element* H;
	heap(int capacity);
	
	heap* initialize(int n);
	void insert(int key, int flag );
	int deleteMin( int flag);
	void decreaseKey( int key, int value, int flag);
	void buildHeap( int length);
	void printHeap();
	void heapify( int i);
};
	
#endif //	_HEAP_H_