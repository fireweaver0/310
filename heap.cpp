#include "heap.h"
#include <fstream>
#include <string>
using namespace std;
#include <iostream>
heap :: heap(int b){
	 size = 0;
	 capacity  = b;
	
	H = new element[capacity+1];
	
															//what if there's a capacity 4 tree and they only give 3 inputs
															//what if there's a capacity 2 tree and they give 5 inputs
}

void heap::heapify( int i){
	int l,r,exchange;
	int smallest = 0;
	l = (2*i)+1;
	r = (2*i+1)+1;
	if(l< size && H[l].key < H[i].key)
	{
		smallest = l;
	}
	else {
		smallest = i;
	}
	if(r<size && H[r].key < H[smallest].key)
	{
		smallest = r;
	}
	if(smallest != i)
	{
		exchange = H[i].key;
		H[i].key = H[smallest].key;
		H[smallest].key = exchange;
		heapify( smallest);
	}
	
}

void heap::buildHeap( int length){
	size = length;
	int i;
	for( i = length/2 -1; i>=0; i--) //maybe greater equal
	{
		heapify(i);
	}

}

void heap::decreaseKey(int index, int value, int flag){//not working
	int exchange;
	index--;
	int parent = index/2;
	if(flag == 1)
	{
		printHeap();
	}
	if( value > H[index].key)
	{
		cout << "There are only " << size << " elements in the heap. Hence this operation can not be completed. "<< endl;
		return;
	}
	else{
		H[index].key = value;

		while(index>1 && H[parent].key >  H[index].key)
		{
			exchange = H[parent].key;
			H[parent].key = H[index].key;
			H[index].key = exchange;
			index = parent;
			
		}
	}
	if(flag ==1)
	{
		printHeap();
	}
}


heap * heap::initialize(int n)
{
	return new heap(n);
}

void heap::insert(int key, int source, int destination){
	if (size == capacity)
	{
		element *highCapacity = new element[capacity*2];
		for (int i = 0; i < size; i++)
		{
			highCapacity[i].key = H[i].key;
		}
		delete H;
		H = highCapacity;
		capacity = capacity * 2;
	}
	
	size = size++;
	int i = size - 1;
	int parent = (i-1) / 2;//active line
	int hold = 0;
	H[i].key = key;
	while(i>0 && H[parent].key > key){
		
		hold = H[i].key;
		H[i].key = H[parent].key;
		H[parent].key = hold;
		i = parent;
		parent = (parent-1 ) / 2;
		if (parent == 0) {
			break;
		}
		
		
	}
	if (H[parent].key > key)
	{
		hold = H[i].key;
		H[i].key = H[parent].key;
		H[parent].key = hold;
	}
	
}

int heap::deleteMin(int flag){
	int min;
	
	if (flag == 1)
	{
		printHeap();
	}
	
	
		min = H[0].key;
		H[0].key = H[size-1].key;
		size--;
		heapify(0);
		
	
	if (flag == 1) {
		printHeap();
	}
	return min;
	
}

void heap::printHeap(){
	int i = 0;
	printf("The size is: ");
	printf("%d", size);
	printf("\nThe capacity is: ");
	printf("%d", capacity);
	printf("\n");
	cout <<"\n"<< endl;
	while(i< size){
		printf("%d", H[i].key);
		i++;
		printf("\n");
	}
}









