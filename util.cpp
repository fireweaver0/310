//#include "heap.h"
#pragma warning(disable: 4996)
#include "util.h"
#include <fstream>
#include <string>
#include <iostream>
heap* add = NULL;

int nextCommand(int* i, int *v, int *f) {
	char c;
	while (1) {
		scanf("%c", &c);
		if (c == ' ' || c == '\t' || c == '\n')
		{
			continue;
		}
		if (c == 'S' || c == 'R' || c == 'W')
		{
			break;
		}
		if (c == 'K' || c == 'k') {
			
			scanf("%d", i);
			scanf("%d", v);
			scanf("%d", f);
			if (add == NULL)
			{
				cout << "Sorry!!! It can not be done. Please intialize the heap and put the values in it." << endl;
				return 0;
			}
			add->decreaseKey( *i, *v, *f);
			break;
		}
		if (c == 'C')
		{
			int n;
			if (scanf("%d", i) == 1)
			{
				if (*i > 0)
				{
					
					add = initialize(*i);
				}
				else
				{
					printf("Input entered must be postive\n");
				}
			}
			else {
				printf("Input was not an integer!\n");
			}

			break;
		}
		if (c == 'D')
		{

			if (scanf("%d", f) == 1)
			{
				if (add->size == 0) {
					cout << "There is no elements in heap to delete." << endl;
				}
				if (add == NULL)
				{
					cout << "Sorry!!! It can not be done.Please intialize the heap first." << endl;
					return 0;
				}
				add->deleteMin(*f);
				
			}
			break;
		}
		if (c == 'I')
		{
			
			
			if (scanf("%d", v) == 1)
			{
				
				if (scanf("%d", f) == 1)
				{
					if (add == NULL)
					{
						cout << "Sorry!!! It can not be done.Please intialize the heap first." << endl;
						return 0;
					}
					add->insert( *v, *f);
				}
			}
			break;

		}
		printf("Invalid Command \n");
	}
	return c;
}
void readFile(string fileName) {
	int count,cnt1 = 0;
	int i;
	string hold = "";
	heap* reader = add;
	ifstream myFileVar;
	if (add == NULL)
	{
		cout << "Sorry!!! It can not be done. Please intialize the heap first."<<endl;
		return;
	}	 
	
	myFileVar.open(fileName);
	if (myFileVar.is_open()) {
		myFileVar >> count;
		if (count > add->capacity)
		{
			cout << "Sorry!!! It can not be done. Please increase the capacity of heap first" << endl;
			myFileVar.close();
			return;
		}
		getline(myFileVar, hold);
		while (getline(myFileVar, hold)){
			const char *p = hold.c_str();
			int addto;
			sscanf(p, "%d", &addto );
			add->H[cnt1].key = addto;
			cnt1++;

		}
		if (cnt1 < count) {
			cout << "Sorry!!! It can not be done. The number of elements in file are less than as specified in the beginning of file" << endl;
			myFileVar.close();
			return;
		}
		/*for (i = 0; i<count; i++)
		{
			//reader = new heap();
			myFileVar >> add->H[i].key;
		}*/
		myFileVar.close();
		
	}
	else {
		printf("There was a problem opening file HEAPinput.txt for reading. \n");
	}
	add->buildHeap( count);
}



void writeFile() {
	int i;
	if (add == NULL)
	{
		cout<< "Sorry!!! It can not be done.Please intialize the heap first."<<endl;
		return;
	}
	printf("The capacity is ");
	printf("%d", add->capacity);
	printf(". \n");
	printf("Size is ");
	printf("%d", add->size);
	printf(". \n");
	for (i = 0; i <add->size; i++) {
		printf("%d", add->H[i].key);
		printf("\n");
	}

}

heap *initialize(int n)
{

	return new heap(n);
}





















