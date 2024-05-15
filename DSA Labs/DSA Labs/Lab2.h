/*
File:			Lab2.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:	Nicholas Pierce

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
	std::string numStr = std::to_string(_num);
	int numLen = (int)numStr.length();
	int start = 0;
	int end = numLen - 1;

	for (; start < numLen / 2; start++, end--)
		if (numStr[start] != numStr[end])
			return false;
	return true;
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
		std::ifstream fin;
		fin.open(_inputFilename, std::ios_base::binary);
		
		if (fin.is_open()) {
			int numOfValues, tempValue;
			fin.read((char*)&numOfValues, sizeof(int));
			for (int i = 0; i < numOfValues; i++) {
				fin.read((char*)&tempValue, sizeof(int));
				mValues.push_back(tempValue);
			}
			fin.close();
		}
	}

	void Fill(const int* _arr, size_t _size) {
		// TODO: Implement this method
		for (int i = 0; i < _size; i++)
			mValues.push_back(_arr[i]);
	}

	void Clear() {
		// TODO: Implement this method
		mValues.clear();
		mValues.shrink_to_fit();
	}

	void Sort(bool _ascending) {
		// TODO: Implement this method
		if (_ascending)
			std::sort(mValues.begin(), mValues.end());
		else
			std::sort(mValues.begin(), mValues.end(), std::greater<int>());
	}

	int operator[](int _index) {
		// TODO: Implement this method
		return mValues[_index];
	}

	bool Contains(int _val) const {
		// TODO: Implement this method
		for (int i : mValues)
			if (i == _val)
				return true;
		return false;
	}

	void MovePalindromes() {	
		// TODO: Implement this method
		for (int i = 0; i < mValues.size();) {
			if (IsPalindromeNumber(mValues[i])) {
				mPalindromes.push_back(mValues[i]);
				mValues.erase(mValues.begin() + i);
			}
			else
				i++;
		}
	}
};

