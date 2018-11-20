/* Author: Jacob Leuquire
 * November 19, 2018
 * header file for sorting methods
 */

#pragma once

#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using std::vector;
using namespace std;


// Seed the random-number generator with current time so that
// the numbers will be different every time we run.
// WARNING:  Only do this once per run!
// The static variable called enforces the one call per run
// rule.
void randomizeSeed()
{
	static bool called = false;
	if (!called)
	{
		srand(long(std::time(NULL)));
		called = true;
	}
}


// Return a random variate distributed uniformly between
// zero and one.  All doubles in this range are
// approximately equally likely.
// 0 <= r < 1
double randUniform()
{
	double r = double(rand()) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	return  r;
};


// Return a random variate distributed uniformly on the
// range minReal upto, not including, maxReal.
// minReal is assumed < maxReal.
double randReal(double minReal, double maxReal)
{
	return minReal
		+ (maxReal - minReal) * randUniform();
}

//Create list of random doubles - edited from lab6
vector<double> newList(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

void print(vector<double> & numbers)
{
	cout << "List: [";
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << numbers[numbers.size() - 1] << "]" << endl;
}

//simple function to make swapping data easier - from geeksforgeeks.org
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

vector<double> bubbleSort(vector<double> & number)
{
	for (int n = 0; n < number.size(); n++)
	{
		bool check = false;
		for (int i = 0; i < number.size() - 1; i++)
		{
			if (number[i] > number[i + 1])
			{
				swap(number[i], number[i + 1]);
				check = true;
			}
		}
		if (check == false)
		{
			break;
		}
	}
	return number;
}

vector<double> insertionSort(vector<double> & number)
{
	for (int i = 1; i < number.size(); i++)
	{
		int n = i - 1;
		while (n >= 0 && number[n] > number[i])
		{
			number[n + 1] = number[n];
			n = n - 1;
		}
		number[n + 1] = number[i];
	}
	return number;
}

vector<double> selectionSort(vector<double> & number)
{
	int i, j, min;
	for (i = 0; i < number.size() - 1; i++)
	{
		min = i;
		for (j = i + 1; j < number.size(); j++)
		{
			if (number[j] < number[min])
				min = j;
		}
		swap(number[min], number[i]);
	}
	return number;
}

//This function created via assistance from geeksforgeeks.org
int part(vector<double> & number, int low, int high)
{
	double pivot = number[high];
	int i = low;

	for (int j = low + 1; j < high; j++)
	{
		if (number[j] <= pivot)
		{
			i++; 
			swap(number[i], number[j]);
		}
	}
	swap(number[i + 1], number[high]);
	return (i + 1);
}

vector<double> quickSort(vector<double> & number, int low, int high)
{
	if (low < high)
	{
		int p = part(number, low, high);
		quickSort(number, low, p - 1);
		quickSort(number, p + 1, high);
	}	
	return number;
}

vector<double> mergeSort(vector<double> & number, int l, int r)
{
	vector<double> Sortnumber;
	return Sortnumber;
}

