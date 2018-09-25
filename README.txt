Programmed in C++

• ELEMENT is a data type that contains a field named key, which is of type int. Note that
ELEMENT should not be of type int.

• HEAP is a data type that contains three fields named capacity (of type int), size (of type int),
and H (an array of type ELEMENT with index ranging from 0 to capacity).

The functions:

• Initialize(n) which returns an object of type HEAP with capacity n and size 0. This function
requires you to perform dynamic memory allocation, given the demand.

• BuildHeap(heap, A, n), where heap is a HEAP object, A is an array of type ELEMENT, and n is
the size of array A. This function copies the elements in A into heap->H (starting from H[1]
and uses the linear time build heap algorithm to obtain a min-heap of size from the given
array A.

• Insert(heap, k, flag) which inserts an element with key equal to k into the min-heap heap.
When flag=0, the function does not do any additional printing. When flag=1, the function
prints out the heap content before the insertion, and the heap content after the insertion.

• DeleteMin(heap, flag) which deletes the element with minimum key and returns it to the caller.
When flag=0, the function does not do any additional printing. When flag=1, the function
prints out the heap content before the deletion, and the heap content after the deletion.

• DecreaseKey(heap, index, value, flag) which decreases the key field of the heap element pointed
to by index to value, which should not be larger than the current value. Note that you have
to make necessary adjustment to make sure that heap order is maintained. When flag=0,
the function does not do any additional printing. When flag=1, the function prints out the
heap content before the decrease key operation, and the heap content after the decrease key
operation.

• printHeap(heap) which prints out the heap information, including capacity, size, and the key
fields of the elements in the array with index going from 1 to size.
