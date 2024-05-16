/*
File:			DList.h\
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:	Nicholas Pierce

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
			data = _data;
			next = _next;
			prev = _prev;
		}
	};

public:

	class Iterator {
	public:

		Node* mCurr = reinterpret_cast<Node*>(-1);

		Iterator& operator++() {
			// TODO: Implement this method
			mCurr = mCurr->next;
			return *this;
		}

		Iterator operator++(int) {
			// TODO: Implement this method
			Iterator i;
			i.mCurr = mCurr;
			mCurr = mCurr->next;
			return i;
		}

		Iterator& operator--() {
			// TODO: Implement this method
			mCurr = mCurr->prev;
			return *this;
		}

		Iterator operator--(int) {
			// TODO: Implement this method
			Iterator i;
			i.mCurr = mCurr;
			mCurr = mCurr->prev;
			return i;
		}

		Type& operator*() {
			// TODO: Implement this method
			return mCurr->data;
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
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;
	}

	~DList() {
		// TODO: Implement this method
		Clear();
	}

	DList(const DList& _copy)  {
		// TODO: Implement this method
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;
		*this = _copy;
	}

	DList& operator=(const DList& _assign) {
		// TODO: Implement this method
		if (this == &_assign)
			return *this;

		Clear();
		Iterator it = _assign.Begin();
		for (int i = 0; i < _assign.mSize; i++, it++)
			AddTail(it.mCurr->data);
		return *this;
	}

	void AddHead(const Type& _data) {
		// TODO: Implement this method
		if (mSize == 0) {
			Node* newNode = new Node(_data);
			mHead = newNode;
			mTail = newNode;
		}
		else {
			Node* newNode = new Node(_data, mHead, nullptr);
			mHead->prev = newNode;
			if (mSize == 1)
				mTail = mHead;
			mHead = newNode;
		}
		mSize++;
	}

	void AddTail(const Type& _data) {
		// TODO: Implement this method
		if (mSize == 0) {
			Node* newNode = new Node(_data);
			mHead = newNode;
			mTail = newNode;
		}
		else {
			Node* newNode = new Node(_data, nullptr, mTail);
			mTail->next = newNode;
			if (mSize == 1)
				mHead = mTail;
			mTail = newNode;
		}
		mSize++;
	}

	void Clear() {
		// TODO: Implement this method
		for (int i = 0; i < mSize; i++) {
			Node* tempPtr = mHead;
			if (mHead != nullptr)
				mHead = mHead->next;
			delete tempPtr;
		}
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;
	}

	Iterator Insert(Iterator& _iter, const Type& _data) {
		// Implement this method
		if (_iter.mCurr == nullptr || _iter.mCurr == mHead) {
			AddHead(_data);
			_iter.mCurr = mHead;
		}
		else {
			Node* newNode = new Node(_data, _iter.mCurr, _iter.mCurr->prev);
			newNode->prev->next = newNode;
			newNode->next->prev = newNode;
			_iter--;
			mSize++;
		}
		return _iter;
	}

	Iterator Erase(Iterator& _iter) {
		// TODO: Implement this method
		if (_iter.mCurr == nullptr)
			return _iter;
		if (_iter.mCurr == mHead && _iter.mCurr == mTail) {
			Clear();
			_iter.mCurr = nullptr;
		}

		Node* nodeToDelete = _iter.mCurr;

		if (_iter.mCurr == mHead) {
			mHead->next->prev = nullptr;
			mHead = mHead->next;
		}
		else if (_iter.mCurr == mTail) {
			mTail->prev->next = nullptr;
			mTail = mTail->prev;
		}
		else {
			_iter.mCurr->prev->next = _iter.mCurr->next;
			_iter.mCurr->next->prev = _iter.mCurr->prev;
		}

		if (_iter.mCurr != nullptr) {
			_iter++;
			delete nodeToDelete;
		}

		mSize--;

		return _iter;
	}

	Iterator Begin() const {
		// TODO: Implement this method
		Iterator i;
		i.mCurr = mHead;
		return i;
	}

	Iterator End() const {
		// TODO: Implement this method
		Iterator i;
		i.mCurr = mTail->next;
		return i;
	}
};