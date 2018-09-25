#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
using namespace std;
int main(){
	char c;
	int i, v, f;
	
	while(1){
		c = nextCommand(&i, &v, &f);
		switch(c){
			case 's':
			case 'S': printf("COMMAND: %c.\n", c); 
				cout << "The program is going to be terminated." << endl;
				return 0;//exit(0)
			
			case 'k':
			case 'K': printf("COMMAND: %c %d %d %d.\n", c, i, v, f); break;
			
			case 'c':
			case 'C': printf("COMMAND: %c %d. \n", c, i);
				break;
			
			case 'r':
			case 'R':printf("COMMAND: %c. \n", c);
				
				readFile("HEAPinput.txt");
				break;

			case 'w':
			case 'W':printf("COMMAND: %c. \n", c);
				writeFile();
				break;

			case 'i':
			case 'I':printf("COMMAND: %c %d %d. \n", c, v, f);
				break;

			case 'd':
			case 'D':printf("COMMAND: %c %d. \n", c, f);
				break;

			default: break;
		}
	}
	return 0;
}