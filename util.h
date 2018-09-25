#ifndef _UTIL_H_
#define _UTIL_H_
#include "heap.h"
#include <string>
using namespace std;

	heap* initialize(int n);
	int nextCommand(int *i, int *v, int *f);
	void readFile(string fileName);
	void writeFile();

#endif //	_UTIL_H_