#pragma once

// HuffmanLib.h - Contains declarations of Huffman functions

// Compress a file using Huffman compression
void HuffmanCompress(const char* _uncompressedFilename, const char* _compressedFilename);

// Decompress a file using Huffman compression
void HuffmanDecompress(const char* _compressedFilename, const char* _uncompressedFilename);
