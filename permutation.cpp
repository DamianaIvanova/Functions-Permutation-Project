#include "permutation.h"
#include<iostream>
using namespace std;

using std::cout;
using std::cin;


//First: Making a Dynamic 2D Array ; elements=cols
int** MakeArray(int elements, int rows, int** arr)
{
	cout << endl << "Our function with " << elements * 2 << " elements:" << endl;

	for (int i = 0; i < rows; i++) {
		if (i == 0) {
			cout << "Please enter " << elements << " elements for 1 row:" << endl << endl;
		}
		else {
			cout << "Now please enter " << elements << " elements for 2 row:" << endl << endl;
		}
		for (int j = 0; j < elements; j++) {
			cout << "arr[" << j << "]=  ";
			cin >> arr[i][j];
		}
		cout << endl << "***************" << endl;
	}
	return arr;
}

//Second: we will check if all elements in two rows are special
bool Special(int** arr, int elements)
{
	// check if the 1 row is unique
	bool flag = false;
	for (int i = 0; i < elements; i++) {
		for (int j = i + 1; j < elements; j++) {
			if (arr[0][i] == arr[0][j] || arr[1][i] == arr[1][j])
			{
				cout << endl << "ERROR!!! You have number/s duplicated!" << endl;
				flag = true; //flag is up
			}
		}
	}
	if (flag == true) { return false; } //error

	return true;
}

// 3 Injection
// If elements from the 1 row are different values from elements in the 2 row
bool Injection(int** arr, int elements)
{
	for (int first = 0; first < elements; first++)
	{
		bool flag = false; //Element in 2 row?
		for (int second = 0; second < elements; second++) {
			if (arr[0][first] == arr[1][second]) {

				//Element in prev iteration?

				if (flag == false) {
					flag = true; //true flag
				}

				//Element has been found already -> no injection
				else { return false; }
			}
		}

		//If element hasn't been found -> it's not injection
		if (flag == false) {
			return false;
		}
	}
	return true;
}

// 4 Surjection
// If element from the 2 row is mapped to by the 1 row at least once
bool Surjection(int** arr, int elements)
{
	for (int second = 0; second < elements; second++) {
		bool flag = false;

		for (int first = 0; first < elements; first++) {
			if (arr[0][first] == arr[1][second])
			{
				flag = true;
			}
		}
		//Check if the element has been found already in previous iterations
		if (flag == false) { return false; }
	}
	return true;
}

// 5 Bijection
// Injection + Surjection = Permutation
bool Bijection(int** arr, int elements)
{
	return Injection(arr, elements) && Surjection(arr, elements);
}

// 6 Number of permutations
// Like Factoriel 3*2*1
int NPermutations(long double elements)
{
	long double npermutation = 1;

	//start from 1 to multiply them
	for (unsigned int numelements = 1; numelements <= elements; numelements++)
	{
		npermutation = npermutation * numelements;
	}

	return npermutation;
}

// 7 Fixed Points
// In one column in row 1 and row 2 we have same element
bool FixedPoints(int** arr, int elements)
{
	for (int i = 0; i < elements; i++) {
		if (arr[0][i] == arr[1][i]) { //check cols
			return true;
		}
	}
	return false;
}

// 8 Number of fixed points
// We use counter and for cycle
int NFixedPoints(int** arr, int elements) {
	int cnt = 0;
	for (int i = 0; i < elements; i++) {
		if (arr[0][i] == arr[1][i]) {
			cnt++; //count cols
		}
	}

	return cnt;
}

// 9 Identical Function
// When all elements from 1 and 2 row are equal - identity
bool Identity(int** arr, int elements) {
	int cnt = 0;
	for (int i = 0; i < elements; i++) {
		if (arr[0][i] == arr[1][i]) // if fixed points = count of cols true
		{
			cnt++;
		}
	}
	if (cnt == elements) {
		return true;
	}
	return false;
}


//10 Independent Cycles
int swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return 0;
}

bool IndependentCycles(int** arr, int elements)
{
	for (int i = 0; i < elements; i++)
	{
		int start = arr[0][i];
		if (start != arr[1][i])
		{
			cout << "(";
			cout << arr[1][i] << " ";
			while (start != arr[1][i])
			{
				swap(arr[0][1], arr[1][1]);
				swap(arr[0][2], arr[1][2]);
				cout << arr[0][i] << " ";
				break;
			}
		}
	}
	cout << ")" << endl;
	return true;
}


// 11 Length of Independent Cycles with char array
void NIndependentCycles(char* arr, int size)
{
	int count = 0; //length of cycles
	int temp[100]; //new array for length
	int tempSize = 0; //length of int temp[100]
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == '(')
		{
			count = 0; //count 0
		}
		if (arr[i] == ')')
		{
			temp[tempSize] = count;//save count in array+1
			tempSize++;
		}
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			count++; //count numbers
		}
	}
	cout << "Length is: ";
	for (int i = 0; i < tempSize; i++)
	{
		cout << temp[i] << " "; //print
	}
	cout << endl;
}

// 13 Group Pearmutation - Composition Permutation 
void CompositionPermutation(int** arr1, int cols1, int** arr2, int cols2)
{
	if (cols1 == cols2) //Compare columns from arrays because they must be equal
	{
		int temp[2][100]; //new array
		for (int i = 0; i < cols1; i++)
		{
			temp[0][i] = i + 1; //1 row save position of numbers 1 to 5
		}
		for (int i = 0; i < cols1; i++)
		{
			for (int j = 0; j < cols1; j++)
			{
				if (arr1[1][i] == arr2[0][j]) //Group
				{
					temp[1][i] = arr2[1][j];
				}
			}
		}
		//Print
		for (int i = 0; i < 2; ++i) {
			if (i == 0) {
				cout << "x   " << ": {";
			}
			else if (i == 1) {
				cout << "f(x)" << ": {";
			}
			for (int colNumber = 0; colNumber < cols1; ++colNumber) {
				cout << temp[i][colNumber] << ((colNumber == cols1 - 1) ? "}" : ", ");
			}
			cout << ((i == 2 - 1) ? "." : ", ") << endl;
		}
	}
	else
	{
		cout << "The colums of two permutations must be equal!" << endl; //=Cols
	}
}

// 14 Reverse Permutation - switch rows, 1 row in ascending order
void ReversePermutation(int** arr, int elements)
{
	int temp[2][100]; //new array
	for (int i = 0; i < elements; i++) //switch rows
	{
		temp[0][i] = arr[1][i];
		temp[1][i] = arr[0][i];
	}
	for (int i = 1; i < elements; ++i) //bubble sort for 2 rows
	{
		for (int j = 0; j < (elements - i); ++j)
			if (temp[0][j] > temp[0][j + 1])
			{
				int temp1 = temp[0][j];
				temp[0][j] = temp[0][j + 1];
				temp[0][j + 1] = temp1;

				int temp2 = temp[1][j];
				temp[1][j] = temp[1][j + 1];
				temp[1][j + 1] = temp2;
			}
	}
	//Print
	for (int i = 0; i < 2; ++i) {
		if (i == 0) {
			cout << "x   " << ": {";
		}
		else if (i == 1) {
			cout << "f(x)" << ": {";
		}

		for (int colNumber = 0; colNumber < elements; ++colNumber) {
			cout << temp[i][colNumber] << ((colNumber == elements - 1) ? "}" : ", ");
		}

		cout << ((i == 2 - 1) ? "." : ", ") << endl;
	}
}

//15 Reverse Composition Identity c
//with this function we have a Permutation then we made a new Permutation in which we save our reversed Permutation
void ReverseCompositionIdentity(int** arr, int cols)
{
	int** temp = NULL; //our permutation is saved in temp the reversed one
	temp = new int* [2]; //dynamic
	for (unsigned i = 0; i < 2; ++i) {
		temp[i] = new int[cols];
	}
	for (size_t i = 0; i < cols; i++)
	{
		temp[0][i] = arr[1][i];
		temp[1][i] = arr[0][i];
	}
	for (int i = 1; i < cols; ++i)
	{
		for (int j = 0; j < (cols - i); ++j)
			if (temp[0][j] > temp[0][j + 1])
			{
				int temp1 = temp[0][j];
				temp[0][j] = temp[0][j + 1];
				temp[0][j + 1] = temp1;

				int temp2 = temp[1][j];
				temp[1][j] = temp[1][j + 1];
				temp[1][j + 1] = temp2;
			}
	}

	//Here we make a new Permutation where we save the Composition of our Permutation and our Reversed
	int** perm = NULL;
	perm = new int* [2];
	for (unsigned i = 0; i < 2; ++i) {
		perm[i] = new int[cols];
	}
	for (size_t i = 0; i < cols; i++)
	{
		perm[0][i] = i + 1;
	}
	for (size_t i = 0; i < cols; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (arr[1][i] == temp[0][j])
			{
				perm[1][i] = temp[1][j];
			}
		}
	}

	//Check if our Composition of 2 Permutations is Identity
	cout << Identity(perm, cols);
	cout << endl;

	delete[] perm;
	perm = NULL;
	delete[] temp;
	temp = NULL;
}

//16 Nocomunitation - if 2 permutations are not Identity a*b=b*a a+b=b+a =!
void NoComutation(int** arr1, int cols1, int** arr2, int cols2)
{
	if (Identity(arr1, cols1) == false && Identity(arr2, cols2) == false) //check identity
	{
		CompositionPermutation(arr1, cols1, arr2, cols2); //a b
		CompositionPermutation(arr2, cols2, arr1, cols1); //b a
	}
	else
	{
		cout << "There is an identity in one of the permutations!" << endl; //no identity
	}
}