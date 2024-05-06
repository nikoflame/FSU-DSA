/*
File:			DSA_Lab6.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Purpose:		Usage of the std::unordered_map class
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
#define LAB_6	0

// Individual unit test toggles
#define LAB6_POPULATE_LETTER_VALUES	0
#define LAB6_GET_LETTER_VALUE		0
#define LAB6_GET_WORD_VALUE			0
#define LAB6_CREATE_PAIR			0
#define LAB6_LOAD_FILE				0
#define LAB6_FIND_WORD_SCORE		0

/************/
/* Includes */
/************/
#include <string>
#include <fstream>
#include <unordered_map>

class DSA_Lab6 {

	friend class UnitTests_Lab6;	// Giving access to test code

	// Data members
	int mLetterValues[26] = { -1 };
	std::unordered_map<std::string, int> mScrabbleMap;

public:

	void PopulateLetterValues(const int* _letterValues) {
		// TODO: Implement this method

	}

	int GetLetterValue(char _letter) const {
		// TODO: Implement this method

	}

	int GetWordValue(const std::string& _word) const {
		// TODO: Implement this method

	}

	std::pair<std::string, int> CreatePair(const std::string& _word) const {
		// TODO: Implement this method

	}

	void LoadWords(const char* _filename) {
		// TODO: Implement this method

	}

	int FindValueInMap(const std::string& _word) {
		// TODO: Implement this method

	}
};
