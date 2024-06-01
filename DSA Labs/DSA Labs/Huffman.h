/*
File:			Huffman.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:	Nicholas Pierce

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
#define LAB_8	1

// Individual unit test toggles
#define HUFFMAN_CTOR					1
#define HUFFMAN_GENERATE_FREQUENCY		1
#define HUFFMAN_GENERATE_LEAFLIST		1
#define HUFFMAN_GENERATE_TREE			1
#define HUFFMAN_CLEAR_TREE				1
#define HUFFMAN_DTOR					1
#define HUFFMAN_GENERATE_ENCODING		1
#define HUFFMAN_COMPRESS				1
#define HUFFMAN_DECOMPRESS				1

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
		mFileName = _fileName;
		for (int i = 0; i < 256; i++)
			mFrequencyTable[i] = 0;
		mRoot = nullptr;
	}

	~Huffman() {
		// TODO: Implement this method
		ClearTree();
	}


	void GenerateFrequencyTable() {
		// TODO: Implement this method
		std::ifstream fin;
		fin.open(mFileName, std::ios_base::binary);
		if (fin.is_open()) {
			unsigned char tempChar;
			while (true) {
				fin.read((char *)&tempChar, 1);
				if (fin.eof())
					break;
				mFrequencyTable[tempChar]++;
			}
			fin.close();
		}
	}

	void GenerateLeafList() {
		// TODO: Implement this method
		for (int i = 0; i < 256; i++) {
			if (mFrequencyTable[i] != 0) {
				HuffNode* node = new HuffNode(i, mFrequencyTable[i]);
				mLeafList.push_back(node);
			}
		}
	}

	void GenerateTree() {
		// TODO: Implement this method
		std::priority_queue<HuffNode*, std::vector<HuffNode*>, HuffCompare> queue;
		for (HuffNode* node : mLeafList)
			queue.push(node);
		HuffNode* tempNode1 = nullptr;
		HuffNode* tempNode2 = nullptr;
		while (queue.size() > 1) {
			tempNode1 = queue.top();
			queue.pop();
			tempNode2 = queue.top();
			queue.pop();

			HuffNode* parent = new HuffNode(-1, tempNode1->freq + tempNode2->freq, tempNode1, tempNode2);

			tempNode1->parent = parent;
			tempNode2->parent = parent;

			queue.push(parent);
		}
		mRoot = queue.top();
	}

	void GenerateEncodingTable() {
		// TODO: Implement this method
		HuffNode* temp = nullptr;
		for (int i = 0; i < mLeafList.size(); i++) {
			temp = mLeafList[i];
			while (temp != mRoot) {
				if (temp->parent->left == temp)
					mEncodingTable[mLeafList[i]->value].push_back(0);
				else
					mEncodingTable[mLeafList[i]->value].push_back(1);
				temp = temp->parent;
			}
			std::reverse(mEncodingTable[mLeafList[i]->value].begin(), mEncodingTable[mLeafList[i]->value].end());
		}
	}

	void ClearTree() {
		// TODO: Implement this method
		if (mRoot)
			ClearTree(mRoot);

	}

	void ClearTree(HuffNode* _curr) {
		// TODO: Implement this method
		if (_curr->left)
			ClearTree(_curr->left);
		if (_curr->right)
			ClearTree(_curr->right);
		if (_curr == mRoot)
			mRoot = nullptr;
		delete _curr;
	}

	void Compress(const char* _outputFile) {
		// TODO: Implement this method
		GenerateFrequencyTable();
		GenerateLeafList();
		GenerateTree();
		GenerateEncodingTable();

		BitOfstream fout(_outputFile, (const char*)mFrequencyTable, 1024);

		std::ifstream fin;
		fin.open(mFileName, std::ios_base::binary);

		if (fin.is_open()) {
			unsigned char tempChar;
			while (true) {
				fin.read((char*)&tempChar, 1);
				if (fin.eof())
					break;
				fout << mEncodingTable[tempChar];
			}

			fin.close();
		}

		fout.Close();
	}

	void Decompress(const char* _outputFile) {
		// TODO: Implement this method
		BitIfstream fin(mFileName.c_str(), (char*)mFrequencyTable, 1024);
		GenerateLeafList();
		GenerateTree();
		std::ofstream fout;
		fout.open(_outputFile, std::ios_base::binary);

		if (fout.is_open()) {
			bool bit;
			unsigned char chr;
			HuffNode* node = nullptr;

			for (unsigned int i = 0; i < mRoot->freq; i++) {
				node = mRoot;
				while (node->left) {
					fin >> bit;
					if (bit)
						node = node->right;
					else
						node = node->left;
				}
				chr = (char)node->value;
				fout.write((char*)&chr, sizeof(char));
			}

			fout.close();
		}

		fin.Close();
	}
};

