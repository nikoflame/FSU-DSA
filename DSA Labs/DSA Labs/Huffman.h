/*
File:			Huffman.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Purpose:		A class to wrap up Huffman compression algorithm
Notes:			Property of Full Sail University 2402
*/

// Header protection
#pragma once

/************/
/* Includes */
/************/
#include <queue>
#include "BitStream.h"

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
#define LAB_8	0

// Individual unit test toggles
#define HUFFMAN_CTOR					0
#define HUFFMAN_GENERATE_FREQUENCY		0
#define HUFFMAN_GENERATE_LEAFLIST		0
#define HUFFMAN_GENERATE_TREE			0
#define HUFFMAN_CLEAR_TREE				0
#define HUFFMAN_DTOR					0
#define HUFFMAN_GENERATE_ENCODING		0
#define HUFFMAN_COMPRESS				0
#define HUFFMAN_DECOMPRESS				0

// Optional unit tests for debugging with small file containing "HELLO WORLD"
#define HUFFMAN_DEBUG_COMPRESS			0
#define HUFFMAN_DEBUG_DECOMPRESS		0

// Wraps up Huffman compression algorithm
class Huffman {

	friend class UnitTests_Lab8; // Giving access to test code

	// A node for a a Huffman tree
	struct HuffNode {
		short value;		 
		unsigned int freq;	
		HuffNode* left;		
		HuffNode* right;	
		HuffNode* parent;	

		HuffNode(short _value, unsigned int _freq, HuffNode* _left = nullptr, HuffNode* _right = nullptr, HuffNode* _parent = nullptr)
			: value(_value), freq(_freq), left(_left), right(_right), parent(_parent) {
		}

		HuffNode(const HuffNode& _hnode)
			: value(_hnode.value), freq(_hnode.freq), left(_hnode.left), right(_hnode.right), parent(_hnode.parent) {
		}
	};

	struct HuffCompare {
		bool operator() (const HuffNode* _a, const HuffNode* _b) {
			return(_a->freq > _b->freq);
		}
	};


	// Data members
	// NOTE: Values set to 1/-1 for unit test purposes
	std::string mFileName = "-1";						
	unsigned int mFrequencyTable[256] = { 1 };			
	std::vector<HuffNode*> mLeafList;					
	HuffNode* mRoot = reinterpret_cast<HuffNode*>(-1);	
	std::vector<bool> mEncodingTable[256];				


	Huffman(const std::string& _fileName) {
		// TODO: Implement this method

	}

	~Huffman() {
		// TODO: Implement this method

	}


	void GenerateFrequencyTable() {
		// TODO: Implement this method

	}

	void GenerateLeafList() {
		// TODO: Implement this method
		
	}

	void GenerateTree() {
		// TODO: Implement this method

	}

	void GenerateEncodingTable() {
		// TODO: Implement this method
		
	}

	void ClearTree() {
		// TODO: Implement this method
	
	}

	void ClearTree(HuffNode* _curr) {
		// TODO: Implement this method
	
	}

	void Compress(const char* _outputFile) {
		// TODO: Implement this method

	}

	void Decompress(const char* _outputFile) {
		// TODO: Implement this method
		
	}
};

