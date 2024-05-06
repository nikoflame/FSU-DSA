/*
File:			BST.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Purpose:		A binary search tree
Notes:			Property of Full Sail University 2402
*/

// Header protection
#pragma once

/************/
/* Includes */
/************/
#include <string>

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
#define LAB_7	0

// Individual unit test toggles
#define BST_CTOR								0
#define BST_NODE_CTOR							0
#define BST_PUSH_EMPTY							0
#define BST_PUSH_LEFT							0
#define BST_PUSH_RIGHT							0
#define BST_CLEAR								0
#define BST_DTOR								0
#define BST_CONTAINS_FOUND						0
#define BST_CONTAINS_NOTFOUND					0
#define BST_REMOVE_CASE0_ROOT					0
#define BST_REMOVE_CASE0_LEFT					0
#define BST_REMOVE_CASE0_RIGHT					0
#define BST_REMOVE_CASE1_ROOT_LEFT				0
#define BST_REMOVE_CASE1_ROOT_RIGHT				0
#define BST_REMOVE_CASE1_LEFT_LEFT				0
#define BST_REMOVE_CASE1_LEFT_RIGHT				0
#define BST_REMOVE_CASE1_RIGHT_LEFT				0
#define BST_REMOVE_CASE1_RIGHT_RIGHT			0
#define BST_REMOVE_CASE2_CASE0					0
#define BST_REMOVE_CASE2_CASE1					0
#define BST_REMOVE_CASE0						0
#define BST_REMOVE_CASE1						0
#define BST_REMOVE_CASE2						0
#define BST_REMOVE_NOT_FOUND					0
#define BST_IN_ORDER_TRAVERSAL					0
#define BST_ASSIGNMENT_OP						0
#define BST_COPY_CTOR							0


// Templated binary search tree
template<typename Type>
class BST {

	friend class UnitTests_Lab7;	// Giving access to test code

	struct Node {
		Type data;					
		Node* left, * right;		
		Node* parent;				

			Node(const Type& _data, Node* _parent = nullptr) {
			// TODO: Implement this method

		}
	};

	// Data members
	// NOTE: All values set to -1 for unit test purposes
	Node* mRoot = reinterpret_cast<Node*>(-1);	

public:

	BST() {
		// TODO: Implement this method

	}

	~BST() {
		// TODO: Implement this method

	}

	BST(const BST& _copy) {
		// TODO: Implement this method

	}

	BST& operator=(const BST& _assign) {
		// TODO: Implement this method
		
	}

private:
	// Recursive helper method for use with Rule of 3
	void Copy(const Node* _curr) {
		// TODO: Implement this method

	}

public:

	void Clear() {
		// TODO: Implement this method

	}

private:

	// Recursive helper method for use with Clear
	void Clear(Node* _curr) {
		// TODO: Implement this method

	}

public:

	void Push(const Type& _val) {
		// TODO: Implement this method

	}

	bool Contains(const Type& _val) {
		// TODO: Implement this method

	}

private:

	Node* FindNode(const Type& _val) {
		
	}

	void RemoveCase0(Node* _node) {
		// TODO: Implement this method

	}

	void RemoveCase1(Node* _node) {
		// TODO: Implement this method

	}

	void RemoveCase2(Node* _node) {
		// TODO: Implement this method

	}

public:

	bool Remove(const Type& _val) {
		// TODO: Implement this method

	}

	std::string InOrder() {
		// TODO: Implement this method

	}

private:

	// Recursive helper method to help with InOrder
	void InOrder(Node* _curr, std::string& _str) {
		// TODO: Implement this method

	}
};

