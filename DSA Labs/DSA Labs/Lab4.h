/*
File:			DSA_Lab4.h	
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Purpose:		Usage of the std::list class
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
#define LAB_4	0

// Individual unit test toggles
#define LAB4_QUEUE_ADD			0
#define LAB4_STACK_ADD			0
#define LAB4_QUEUE_REMOVE		0
#define LAB4_STACK_REMOVE		0
#define LAB4_INSERT_ITER		0
#define LAB4_INSERT_INDEX		0
#define LAB4_REMOVE_DECIMAL		0

/************/
/* Includes */
/************/
#include <list>

class DSA_Lab4 {

	friend class UnitTests_Lab4;	// Giving access to test code

	// Data members
	std::list<float> mList;

public:

	void QueueOrderingAdd(const float* _arr, size_t _size) {
		// TODO: Implement this method
		
	}

	void StackOrderingAdd(const float* _arr, size_t _size) {
		// TODO: Implement this method
		
	}

	float QueueOrderingRemove() {
		// TODO: Implement this method
		
	}

	float StackOrderingRemove() {
		// TODO: Implement this method
		
	}

	void Insert(int _index, float _val) {
		// TODO: Implement this method
		
	}

	void Insert(std::list<float>::iterator _iter, float _val) {
		// TODO: Implement this method
		
	}

	int RemoveDecimalGreater(float _decimal) {
		// TODO: Implement this method
		
	}
 	
};