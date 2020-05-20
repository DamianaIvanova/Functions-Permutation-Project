#pragma once
#include <iostream>

//1 with this function we fill and make our array
int** MakeArray(int, int, int**);

//2 For making a function we want to check if our rows are special
bool Special(int**, int);

//3 with this function we check if our function is 'Injection'
bool Injection(int**, int);

//4 with this function we check if our function is 'Surjection'
bool Surjection(int**, int);

//5 with this function we check if our function is 'Bijection'
bool Bijection(int**, int);

//6 with this function we count the number of permutations
int NPermutations(long double);

//7 with this function we check if we have fixed points
bool FixedPoints(int**, int);

//8 with this function we count the number of fixed points
int NFixedPoints(int**, int);

//9 with this function we check if we have Permutation Identity
bool Identity(int**, int);

//10 with this function we make Independent Cycles
int swap(int& a, int& b);
bool IndependentCycles(int**, int);

//11 with this function we check the length of Independent Cycle
void NIndependentCycles(char*, int);

//13
void CompositionPermutation(int**, int, int**, int);

//14 with this function we reverse our Permutation
void ReversePermutation(int**, int);

//15 with this function we have a Permutation then we made a new Permutation in which we save our reversed Permutation
void ReverseCompositionIdentity(int**, int);

//16 No Comutation
void NoComutation(int**, int, int**, int);