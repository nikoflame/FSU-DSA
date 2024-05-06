/*
File:			Lab2.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Purpose:		Usage of the std::vector class
Notes:			Property of Full Sail University 2402
*/

// Header protection
#pragma once

/***********/
/* Defines */
/***********/

/*
How to use:

	When working on a lab, turn that lab's #define from 0 to 1

		Example:	#define LAB_1	1

	When working on an individual unit test, turn that #define from 0 to 1

		Example:	#define DYNARRAY_DEFAULT_CTOR	1

NOTE: If the unit test is not on, that code will not be compiled!
*/

// Main toggle
#define LAB_2	0

// Individual unit test toggles
#define LAB2_PALINDROME_NUMBER		0
#define LAB2_FILL_FILE				0
#define LAB2_FILL_ARRAY				0
#define LAB2_CLEAR					0
#define LAB2_SORT_ASCENDING			0
#define LAB2_SORT_DESCENDING		0
#define LAB2_BRACKETS				0
#define LAB2_CONTAINS_TRUE			0
#define LAB2_CONTAINS_FALSE			0
#define LAB2_MOVE_PALINDROMES		0

/************/
/* Includes */
/************/
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>


inline int IsPalindromeNumber(unsigned int _num) {
	// TODO: Implement this function	
	
}

class DSA_Lab2
{
	friend class UnitTests_Lab2;	// Giving access to test code

private:

	std::vector<int> mValues;		// contains all of the values
	std::vector<int> mPalindromes;	// contains just the numbers that are palindromes (only used in MovePalindromes method)

public:

	void Fill(const char* _inputFilename) {
		// TODO: Implement this method

	}

	void Fill(const int* _arr, size_t _size) {
		// TODO: Implement this method

	}

	void Clear() {
		// TODO: Implement this method

	}

	void Sort(bool _ascending) {
		// TODO: Implement this method

	}

	int operator[](int _index) {
		// TODO: Implement this method
	
	}

	bool Contains(int _val) const {
		// TODO: Implement this method
	
	}

	void MovePalindromes() {	
		// TODO: Implement this method

	}
};

