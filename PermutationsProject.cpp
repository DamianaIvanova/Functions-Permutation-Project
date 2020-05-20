#include "permutation.h"
#include<iostream>
using namespace std;


int main()
{
	//Input elements and fix rows=2
	const unsigned rows = 2;
	int elements;
	cout << "HELLO! :) We are going to make an array :)" << endl;
	cout << "How many elements do you want in your array? ";
	cin >> elements;

	//Chechk if elements are > 0
	if (elements == 0 || elements < 0) {
		cout << "ERROR! Please, enter a number bigger than 0! ";
		return 0;
	}

	//Make a 2dynamic array
	int** PermArr = NULL;
	PermArr = new int* [rows];
	for (unsigned i = 0; i < rows; ++i) {
		PermArr[i] = new int[elements];
	}

	//Here we fill and print our array
	PermArr = MakeArray(elements, 2, PermArr);

	//For making a function we want to check if our rows are special
	if (Special(PermArr, elements) == false) {
		cout << endl << "ERROR! The elements are not special. Exit from program..." << endl;
		return false;
	}

	//Menu from where you can choice what program to start
	cout << endl << endl;
	cout << "************OUR MENU*************" << endl;
	cout << "Injection - please, enter 3" << endl;
	cout << "Surjection - please, enter 4" << endl;
	cout << "Bijection (permutation) - please, enter 5" << endl;
	cout << "Number of permutations - please, enter 6" << endl;
	cout << "Do you have fixed point/s - please, enter 7" << endl;
	cout << "Number of fixed point/s - please, enter 8" << endl;
	cout << "Identical function - please, enter 9" << endl;
	cout << "Decomposition of cycle - please, enter 10" << endl;
	cout << "Length of cycle - please, enter 11 and write your cycle like this (1,2,3).." << endl;
	cout << "Composition of Permutation - please, enter 13" << endl;
	cout << "Reverse Permutation - please, enter 14" << endl;
	cout << "Reverse Composition Identity - please, enter 15" << endl;
	cout << "No Comutation - please, enter 16" << endl;
	cout << "*******************************" << endl;
	cout << "Stop program - please, enter 0 " << endl;
	cout << "*******************************" << endl;

	int number;
	//Making your choice from menu with do while cycle (when number is !=0) and in it (if number)
	do {
		cout << "Choice a number from MENU: ";
		cin >> number;

		//3 Injection
		if (number == 3)
		{
			if (Injection(PermArr, elements) == true)
			{
				cout << "Yes, it's 'Injection'" << endl;
			}
			else
			{
				cout << "No, it's not 'Injection'" << endl;
			}
			cout << "*******************************" << endl;
		}

		//4 Surjection
		if (number == 4)
		{
			if (Surjection(PermArr, elements) == true)
			{
				cout << "Yes, this is 'Surjection'" << endl;
			}
			else
			{
				cout << "No, this is not 'Surjection'" << endl;
			}
			cout << "*******************************" << endl;
		}

		//5 Bijection
		if (number == 5)
		{
			if (Bijection(PermArr, elements) == true)
			{
				cout << "Yes, this is 'Bijection'" << endl;
			}
			else
			{
				cout << "No, this is not 'Bijection'" << endl;
			}
			cout << "*******************************" << endl;

		}

		//6 Number of Permutations
		if (number == 6)
		{
			if (Bijection(PermArr, elements) == true)
			{
				cout << "The number of Permutations is: " << NPermutations(elements) << endl;
				cout << "*******************************" << endl;
			}
			else
			{
				cout << "This is not a bijection try again!" << endl;
				cout << "*******************************" << endl;
			}
		}

		//7 Fixed Point/s
		if (number == 7)
		{
			if (Bijection(PermArr, elements) == true)
			{
				if (FixedPoints(PermArr, elements) == true)
				{
					cout << "In our permutation we have at least 1 fixed point" << endl;
				}
				else
				{
					cout << "In our permutation we haven't got fixed points" << endl;
				}
				cout << "*******************************" << endl;
			}
			else
			{
				cout << "This is not a bijection try again!" << endl;
				cout << "*******************************" << endl;
			}
		}

		//8 Number of Fixed Points
		if (number == 8)
		{
			if (Bijection(PermArr, elements) == true)
			{
				cout << "You have " << NFixedPoints(PermArr, elements) << " fixed point/points" << endl;
				cout << "*******************************" << endl;
			}
			else
			{
				cout << "This is not a bijection try again!" << endl;
				cout << "*******************************" << endl;
			}
		}

		//9 Identity Permutatuion
		if (number == 9)
		{
			if (Bijection(PermArr, elements) == true)
			{
				if (Identity(PermArr, elements) == true)
				{
					cout << "The function is identical" << endl;
				}
				else
				{
					cout << "The function is not identical" << endl;
				}
				cout << "*******************************" << endl;
			}
			else {
				cout << "This is not a bijection try again!" << endl;
				cout << "*******************************" << endl;
			}
		}

		//10 Independent Cycles
		if (number == 10)
		{
			if (Bijection(PermArr, elements) == true)
			{
				IndependentCycles(PermArr, elements);
				cout << "*******************************" << endl;
			}
			else
			{
				cout << "This is not a bijection try again!" << endl;
				cout << "*******************************" << endl;
			}
		}

		//11 Length of independent cycle
		if (number == 11)
		{
			char str[100];
			cout << "Enter the independent cycles (like this: (x,y,z)(x,z)): ";
			cin >> str;
			NIndependentCycles(str, strlen(str));
			cout << "*******************************" << endl;
		}

		//13 Composition Permutation
		if (number == 13)
		{
			int size = 0;
			cout << "How many elements do you want in your second array? ";
			cin >> size;
			int** TempArr = NULL;
			TempArr = new int* [rows];
			for (unsigned i = 0; i < rows; ++i) {
				TempArr[i] = new int[size];
			}
			TempArr = MakeArray(size, 2, TempArr);
			CompositionPermutation(PermArr, elements, TempArr, size);
			cout << "*****************************" << endl;
		}

		//14 Reverse Permutation
		if (number == 14)
		{
			ReversePermutation(PermArr, elements);
			cout << "*******************************" << endl;
		}

		//15 Reverse Composition Identity
		if (number == 15)
		{
			ReverseCompositionIdentity(PermArr, elements);
			cout << "*******************************" << endl;
		}

		//16 No Comutation
		if (number == 16)
		{
			int size = 0;
			cout << "How many elements do you want in your second array? ";
			cin >> size;
			int** TempArr = NULL;
			TempArr = new int* [rows];
			for (unsigned i = 0; i < rows; ++i) {
				TempArr[i] = new int[size];
			}
			TempArr = MakeArray(size, 2, TempArr);
			NoComutation(PermArr, elements, TempArr, size);
			cout << "*******************************" << endl;
		}

		//0 STOP PROGRAM
		if (number == 0)
		{
			cout << "Thank you, bye! :)" << endl;
			cout << "*******************************" << endl;

		}


	} while (number != 0);

	//Clear memory delete dynamical array!
	delete[] PermArr;
	PermArr = NULL;
}