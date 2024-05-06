/*
File:			DList.h\
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Purpose:		A doubly-linked list (similar to std::list)
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
#define LAB_3	0

// Individual unit test toggles			
#define LAB3_CTOR						0
#define LAB3_NODE_CTOR_DEFAULT			0
#define LAB3_NODE_CTOR					0
#define LAB3_ADDHEAD_EMPTY				0
#define LAB3_ADDHEAD					0
#define LAB3_ADDTAIL_EMPTY				0
#define LAB3_ADDTAIL					0
#define LAB3_CLEAR						0
#define LAB3_DTOR						0
#define LAB3_ITER_BEGIN					0
#define LAB3_ITER_END					0
#define LAB3_ITER_INCREMENT_PRE			0
#define LAB3_ITER_INCREMENT_POST		0
#define LAB3_ITER_DECREMENT_PRE			0
#define LAB3_ITER_DECREMENT_POST		0
#define LAB3_ITER_DEREFERENCE			0
#define LAB3_INSERT_EMPTY				0
#define LAB3_INSERT_HEAD				0
#define LAB3_INSERT_MIDDLE				0
#define LAB3_ERASE_EMPTY				0
#define LAB3_ERASE_HEAD					0
#define LAB3_ERASE_TAIL					0
#define LAB3_ERASE_MIDDLE				0
#define LAB3_ASSIGNMENT_OP				0
#define LAB3_COPY_CTOR					0

template<typename Type>
class DList {

	friend class UnitTests_Lab3;	// Giving access to test code

	struct Node {
		// NOTE: Values set to -1 for unit test purposes
		Type data;
		Node* next = reinterpret_cast<Node*>(-1);
		Node* prev = reinterpret_cast<Node*>(-1);

	
		Node(const Type& _data, Node* _next = nullptr, Node* _prev = nullptr) {
			// TODO: Implement this method
			
		}
	};

public:

	class Iterator {
	public:

		Node* mCurr = reinterpret_cast<Node*>(-1);

		Iterator& operator++() {
			// TODO: Implement this method
		
		}

		Iterator operator++(int) {
			// TODO: Implement this method
			
		}

		Iterator& operator--() {
			// TODO: Implement this method
			
		}

		Iterator operator--(int) {
			// TODO: Implement this method
			
		}

		Type& operator*() {
			// TODO: Implement this method
			
		}

	
		bool operator != (const Iterator& _iter) const {
			return mCurr != _iter.mCurr;
		}
	};

	// Data members
	// NOTE: All values set to -1 for unit test purposes
	Node* mHead = reinterpret_cast<Node*>(-1);
	Node* mTail = reinterpret_cast<Node*>(-1);
	size_t mSize = -1;

public:

	DList() {
		// TODO: Implement this method
		
	}

	~DList() {
		// TODO: Implement this method
		
	}

	DList(const DList& _copy)  {
		// TODO: Implement this method
		
	}

	DList& operator=(const DList& _assign) {
		// TODO: Implement this method
		
	}

	void AddHead(const Type& _data) {
		// TODO: Implement this method
		
	}

	void AddTail(const Type& _data) {
		// TODO: Implement this method
		
	}

	void Clear() {
		// TODO: Implement this method
		
	}

	Iterator Insert(Iterator& _iter, const Type& _data) {
		// Implement this method
		
	}

	Iterator Erase(Iterator& _iter) {
		// TODO: Implement this method
		
	}

	Iterator Begin() const {
		// TODO: Implement this method
		
	}

	Iterator End() const {
		// TODO: Implement this method
		
	}
};