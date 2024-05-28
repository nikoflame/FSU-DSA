/*
File:			BST.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:	Nicholas Pierce

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
#define LAB_7	1

// Individual unit test toggles
#define BST_CTOR								1
#define BST_NODE_CTOR							1
#define BST_PUSH_EMPTY							1
#define BST_PUSH_LEFT							1
#define BST_PUSH_RIGHT							1
#define BST_CLEAR								1
#define BST_DTOR								1
#define BST_CONTAINS_FOUND						1
#define BST_CONTAINS_NOTFOUND					1
#define BST_REMOVE_CASE0_ROOT					1
#define BST_REMOVE_CASE0_LEFT					1
#define BST_REMOVE_CASE0_RIGHT					1
#define BST_REMOVE_CASE1_ROOT_LEFT				1
#define BST_REMOVE_CASE1_ROOT_RIGHT				1
#define BST_REMOVE_CASE1_LEFT_LEFT				1
#define BST_REMOVE_CASE1_LEFT_RIGHT				1
#define BST_REMOVE_CASE1_RIGHT_LEFT				1
#define BST_REMOVE_CASE1_RIGHT_RIGHT			1
#define BST_REMOVE_CASE2_CASE0					1
#define BST_REMOVE_CASE2_CASE1					1
#define BST_REMOVE_CASE0						1
#define BST_REMOVE_CASE1						1
#define BST_REMOVE_CASE2						1
#define BST_REMOVE_NOT_FOUND					1
#define BST_IN_ORDER_TRAVERSAL					1
#define BST_ASSIGNMENT_OP						1
#define BST_COPY_CTOR							1


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
				data = _data;
				parent = _parent;
				left = nullptr;
				right = nullptr;
		}
	};

	// Data members
	// NOTE: All values set to -1 for unit test purposes
	Node* mRoot = reinterpret_cast<Node*>(-1);	

public:

	BST() {
		// TODO: Implement this method
		mRoot = nullptr;
	}

	~BST() {
		// TODO: Implement this method
		Clear();
	}

	BST(const BST& _copy) {
		// TODO: Implement this method
		mRoot = nullptr;
		*this = _copy;
	}

	BST& operator=(const BST& _assign) {
		// TODO: Implement this method
		if (this != &_assign) {
			Clear();
			Copy(_assign.mRoot);
			return *this;
		}
	}

private:
	// Recursive helper method for use with Rule of 3
	void Copy(const Node* _curr) {
		// TODO: Implement this method
		Push(_curr->data);
		if (_curr->left)
			Copy(_curr->left);
		if (_curr->right)
			Copy(_curr->right);
	}

public:

	void Clear() {
		// TODO: Implement this method
		if (mRoot)
			Clear(mRoot);
	}

private:

	// Recursive helper method for use with Clear
	void Clear(Node* _curr) {
		// TODO: Implement this method
		if (_curr->left)
			Clear(_curr->left);
		if (_curr->right)
			Clear(_curr->right);
		if (_curr == mRoot)
			mRoot = nullptr;
		delete _curr;
	}

public:

	void Push(const Type& _val) {
		// TODO: Implement this method
		if (!mRoot)
			mRoot = new Node(_val);
		else {
			Node* tmp = mRoot;
			while (true) {
				if (_val < tmp->data) {
					if (tmp->left)
						tmp = tmp->left;
					else {
						tmp->left = new Node(_val, tmp);
						break;
					}
				}
				else {
					if (tmp->right)
						tmp = tmp->right;
					else {
						tmp->right = new Node(_val, tmp);
						break;
					}
				}
			}
		}
	}

	bool Contains(const Type& _val) {
		// TODO: Implement this method
		Node* tmp = mRoot;
		while (true) {
			if (!tmp)
				return false;
			if (_val < tmp->data)
				tmp = tmp->left;
			else if (_val > tmp->data)
				tmp = tmp->right;
			else
				return true;
		}
	}

private:

	Node* FindNode(const Type& _val) {
		Node* tmp = mRoot;
		while (true) {
			if (!tmp)
				return tmp;
			if (_val < tmp->data)
				tmp = tmp->left;
			else if (_val > tmp->data)
				tmp = tmp->right;
			else
				return tmp;
		}
	}

	void RemoveCase0(Node* _node) {
		// TODO: Implement this method
		if (_node == mRoot)
			Clear();
		else {
			if (_node == _node->parent->left)
				_node->parent->left = nullptr;
			else
				_node->parent->right = nullptr;
			delete _node;
		}
	}

	void RemoveCase1(Node* _node) {
		// TODO: Implement this method
		if (_node == mRoot) {
			if (_node->left)
				mRoot = _node->left;
			else
				mRoot = _node->right;
			delete _node;
			mRoot->parent = nullptr;
		}
		else if (_node == _node->parent->left) {
			if (_node->left) {
				_node->left->parent = _node->parent;
				_node->parent->left = _node->left;
			}
			else {
				_node->right->parent = _node->parent;
				_node->parent->left = _node->right;
			}
			delete _node;
		}
		else {
			if (_node->left) {
				_node->left->parent = _node->parent;
				_node->parent->right = _node->left;
			}
			else {
				_node->right->parent = _node->parent;
				_node->parent->right = _node->right;
			}
			delete _node;
		}
	}

	void RemoveCase2(Node* _node) {
		// TODO: Implement this method
		Node* tmp = _node->right;
		while (true) {
			if (tmp->left)
				tmp = tmp->left;
			else
				break;
		}
		_node->data = tmp->data;
		if (tmp->right)
			RemoveCase1(tmp);
		else
			RemoveCase0(tmp);
	}

public:

	bool Remove(const Type& _val) {
		// TODO: Implement this method
		Node* tmp = FindNode(_val);
		if (tmp) {
			if (tmp->left && tmp->right)
				RemoveCase2(tmp);
			else if (tmp->left || tmp->right)
				RemoveCase1(tmp);
			else
				RemoveCase0(tmp);
			return true;
		}
		else
			return false;
	}

	std::string InOrder() {
		// TODO: Implement this method
		std::string str;
		InOrder(mRoot, str);
		return str;
	}

private:

	// Recursive helper method to help with InOrder
	void InOrder(Node* _curr, std::string& _str) {
		// TODO: Implement this method
		if (_curr->left)
			InOrder(_curr->left, _str);
		if (_str != "")
			_str += ' ';
		_str += std::to_string(_curr->data);
		if (_curr->right)
			InOrder(_curr->right, _str);
	}
};

