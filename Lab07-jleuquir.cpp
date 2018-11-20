/* Author: Jacob Leuquire
 * November 19, 2018
 * main file for computing sorting methods
 */

#include <iostream>
#include "Lab07-jleuquir.h"
#include <list>
#include "windowsTimer.h"

using namespace std;


int first = 1;
int last = 500;

int main() {
	while (true)
	{
		cout << "Enter size of Vector: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
		{
			break;
		}
		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		vector<double> List = newList(n, first, last);
		if (n < 11)
		{
			print(List);
		}

		cout << "Input case" << endl;
		int var;
		Timer time;
		cin >> var;
		switch (var)
		{
		case 1:
			time.start();
			sort(List.begin(), List.end());
			time.stop();
		case 2:
			time.start();
			quickSort(List, -1, List.size() - 1);
			time.stop();
		case 3:
			time.start();
			bubbleSort(List);
			time.stop();
		case 4:
			time.start();
			insertionSort(List);
			time.stop();
		case 5:
			time.start();
			selectionSort(List);
			time.stop();
		case 6:
			time.start();
			//mergeSort(List, 0, List.size()-1); couldn't get to work
			time.stop();
		}

		if (n < 11)
		{
			print(List);
		}
		cout << "Time to sort: " << time() << endl;
	}
	return 0;
}
