#include "UnitTests_Lab6.h"
/*
File:			UnitTests_Lab6.cpp
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
Created:		12.31.2021
Last Modified:	12.31.2021
Purpose:		Definitions of Lab5 Unit Tests for Dictionary
Notes:			Property of Full Sail University
*/

/************/
/* Includes */
/************/
#include "UnitTests_Lab6.h"
#include "Memory_Management.h"

// Maximum points for each test
#define POINTS_LAB6_POPULATE_LETTER_VALUES	10
#define POINTS_LAB6_GET_LETTER_VALUE		15
#define POINTS_LAB6_GET_WORD_VALUE			15
#define POINTS_LAB6_CREATE_PAIR				10
#define POINTS_LAB6_LOAD_FILE				25
#define POINTS_LAB6_FIND_WORD_SCORE			25

#if LAB_6
std::string UnitTests_Lab6::mTempFilename;

void UnitTests_Lab6::FullBattery() {

#ifndef _GRADING
	results::Log("Lab6.log", { "Lab6.h" });
#endif
	int totalScore = 0;

#if LAB6_POPULATE_LETTER_VALUES
		totalScore += Battery_PopulateLetterValues();
#endif
#if LAB6_GET_LETTER_VALUE
		totalScore += Battery_GetLetterValue();
#endif
#if LAB6_GET_WORD_VALUE
		totalScore += Battery_GetWordValue();
#endif
#if LAB6_CREATE_PAIR
		totalScore += Battery_CreatePair();
#endif
#if LAB6_LOAD_FILE
		totalScore += Battery_LoadFile();
#endif
#if LAB6_FIND_WORD_SCORE
		totalScore += Battery_FindWordScore();
#endif
		PrintTotalScore(totalScore);
}

#pragma region Test - Populate Letter Values
#if LAB6_POPULATE_LETTER_VALUES
int UnitTests_Lab6::Battery_PopulateLetterValues() {
	FailVector failVec;
	failVec.push_back(Fail_PopulateLetterValues_CopiesAddressInsteadOfValues);
	failVec.push_back(Fail_PopulateLetterValues_OnlyCopiesFirstElement);
	failVec.push_back(Fail_PopulateLetterValues_DoesNotCopyAllElements);

	PassVector passVec;
	passVec.push_back(Pass_PopulateLetterValues_AllElementsAreCopied);

	int totalDeductions = UnitTestBattery("Testing PopulateLetterValues", POINTS_LAB6_POPULATE_LETTER_VALUES, failVec, passVec);
	int scoreForTest = CalculatePointsForTest(POINTS_LAB6_POPULATE_LETTER_VALUES, totalDeductions);

	return scoreForTest;
}

#pragma region Fail Tests
FailResult UnitTests_Lab6::Fail_PopulateLetterValues_CopiesAddressInsteadOfValues() {
	int values[26];
	DSA_Lab6 scrabble;

	scrabble.PopulateLetterValues(values);

	FailResult result;
	result.check = (int*)scrabble.mLetterValues == (int*)values;
	result.deduction = 10;
	result.msg = "Array was shallow copied (has same memory address)";

	return result;
}

FailResult UnitTests_Lab6::Fail_PopulateLetterValues_OnlyCopiesFirstElement() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 100);
	DSA_Lab6 scrabble;

	scrabble.PopulateLetterValues(values);
	
	bool firstElementSame = scrabble.mLetterValues[0] == values[0];
	bool OtherElementsSame = memcmp(scrabble.mLetterValues + 1, values + 1, sizeof(int) * 25) == 0;

	FailResult result;
	result.check = firstElementSame == true && OtherElementsSame == false;
	result.deduction = 10;
	result.msg = "Only first element was copied";

	return result;
}

FailResult UnitTests_Lab6::Fail_PopulateLetterValues_DoesNotCopyAllElements() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 100);
	DSA_Lab6 scrabble;

	scrabble.PopulateLetterValues(values);

	FailResult result;
	result.check = memcmp(scrabble.mLetterValues, values, sizeof(int) * 26) != 0;
	result.deduction = 10;
	result.msg = "Not all values were copied";

	return result;
}
#pragma endregion

#pragma region Pass Tests

bool UnitTests_Lab6::Pass_PopulateLetterValues_AllElementsAreCopied() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 100);
	DSA_Lab6 scrabble;

	scrabble.PopulateLetterValues(values);

	bool result = memcmp(scrabble.mLetterValues, values, sizeof(int) * 26) == 0;

	return result;
}
#pragma endregion
#endif
#pragma endregion

#pragma region Test - Get Letter Value
#if LAB6_GET_LETTER_VALUE
int UnitTests_Lab6::Battery_GetLetterValue() {
	FailVector failVec;
	failVec.push_back(Fail_GetLetterValue_UsesToUpperOrToLower);
	failVec.push_back(Fail_GetLetterValue_DoesNotOffsetToGetToCorrectIndex);
	failVec.push_back(Fail_GetLetterValue_UsesLoop);
	failVec.push_back(Fail_GetLetterValue_UsesSwitch);
	failVec.push_back(Fail_GetLetterValue_DoesNotReturnCorrectValue);

	PassVector passVec;
	passVec.push_back(Pass_GetLetterValue_ReturnsCorrectValue);

	int totalDeductions = UnitTestBattery("Testing GetLetterValue", POINTS_LAB6_GET_LETTER_VALUE,failVec, passVec);
	int scoreForTest = CalculatePointsForTest(POINTS_LAB6_GET_LETTER_VALUE, totalDeductions);

	return scoreForTest;
}

#pragma region Fail Tests
FailResult UnitTests_Lab6::Fail_GetLetterValue_UsesToUpperOrToLower() {
	bool usesToFunction =
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "toupper") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "tolower");

	FailResult result;
	result.check = usesToFunction;
	result.deduction = 15;
	result.msg = "No need to use tolower or toupper in this method";

	return result;
}

FailResult UnitTests_Lab6::Fail_GetLetterValue_DoesNotOffsetToGetToCorrectIndex() {
	bool usesOffset =
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-65") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-=65") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-'A'") || 
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-='A'") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-\"A\"") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-=\"A\"") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-(int)'A'") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "-=(int)'A'");

	FailResult result;
	result.check = usesOffset == false;
	result.deduction = 15;
	result.msg = "Does not offset _letter into valid index range";

	return result;
}

FailResult UnitTests_Lab6::Fail_GetLetterValue_UsesLoop() {
	bool usesLoop = SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "for(") ||
		SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "while(");
	
	FailResult result;
	result.check = usesLoop == true;
	result.deduction = 15;
	result.msg = "This method does not require a loop";

	return result;
}

FailResult UnitTests_Lab6::Fail_GetLetterValue_UsesSwitch() {
	bool usesSwitch = SearchFile("Lab6.h", "GetLetterValue(char _letter)", "GetWordValue(const std::string", "switch");

	FailResult result;
	result.check = usesSwitch == true;
	result.deduction = 15;
	result.msg = "This method does not require a switch";

	return result;
}


FailResult UnitTests_Lab6::Fail_GetLetterValue_DoesNotReturnCorrectValue() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 100);
	int randomIndex = RandomInt('A', 'Z');
	int correctValue = values[randomIndex - unsigned int(64 | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);
	int outputValue = scrabble.GetLetterValue(randomIndex);
	
	FailResult result;
	result.check = outputValue != correctValue;
	result.deduction = 15;
	result.msg = "Does not return correct value";
	
	return result;
}

#pragma endregion

#pragma region Pass Tests
bool UnitTests_Lab6::Pass_GetLetterValue_ReturnsCorrectValue() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 100);
	int randomIndex = RandomInt('A', 'Z');
	int correctValue = values[randomIndex - unsigned int(64 | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);
	int outputValue = scrabble.GetLetterValue(randomIndex);

	bool result = outputValue == correctValue;

	return result;
}
#pragma endregion
#endif
#pragma endregion

#pragma region Test - Get Word Value
#if LAB6_GET_WORD_VALUE
int UnitTests_Lab6::Battery_GetWordValue() {
	FailVector failVec;
	failVec.push_back(Fail_GetWordValue_DoesNotLoopThroughWord);
	failVec.push_back(Fail_GetWordValue_DoesNotCallGetLetterValueOrUseOffset);
	failVec.push_back(Fail_GetWordValue_DoesNotReturnCorrectValue);

	PassVector passVec;
	passVec.push_back(Pass_GetWordValue_ReturnsCorrectValue);

	int totalDeductions = UnitTestBattery("Testing GetWordValue", POINTS_LAB6_GET_WORD_VALUE,failVec, passVec);
	int scoreForTest = CalculatePointsForTest(POINTS_LAB6_GET_WORD_VALUE, totalDeductions);

	return scoreForTest;
}

#pragma region Fail Tests
FailResult UnitTests_Lab6::Fail_GetWordValue_DoesNotLoopThroughWord() {
	bool usesLoop = SearchFile("Lab6.h", "GetWordValue(const std::string", "CreatePair(const std::string", "for(");
		
	FailResult result;
	result.check = usesLoop == false;
	result.deduction = 15;
	result.msg = "Does not use a loop to access all letters in the word";

	return result;
}

FailResult UnitTests_Lab6::Fail_GetWordValue_DoesNotCallGetLetterValueOrUseOffset() {
	bool callsGetLetter = SearchFile("Lab6.h", "GetWordValue(const std::string", "CreatePair(const std::string", "GetLetterValue(");
	bool usesOffset = SearchFile("Lab6.h", "GetWordValue(const std::string", "CreatePair(const std::string", "-65") ||
		SearchFile("Lab6.h", "GetWordValue(const std::string", "CreatePair(const std::string", "-'A'") ||
		SearchFile("Lab6.h", "GetWordValue(const std::string", "CreatePair(const std::string", "-\"A\"");

	FailResult result;
	result.check = callsGetLetter == false && usesOffset == false;
	result.deduction = 15;
	result.msg = "Does not use offset to get to valid index";

	return result;
}

FailResult UnitTests_Lab6::Fail_GetWordValue_DoesNotReturnCorrectValue() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 100);
	std::string randomWord;
	int randomLength = RandomInt(5, 10);
	int totalScore = 0;
	for (int i = 0; i < randomLength; ++i) {
		randomWord += RandomInt('A', 'Z');
		totalScore += values[randomWord[i]-((1<<6)|1)];
	}

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);
	int outputScore = scrabble.GetWordValue(randomWord);

	FailResult result;
	result.check = outputScore != totalScore;
	result.deduction = 15;
	result.msg = "Does not return correct value";

	return result;
}
#pragma endregion

#pragma region Pass Tests
bool UnitTests_Lab6::Pass_GetWordValue_ReturnsCorrectValue() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 100);
	std::string randomWord;
	int randomLength = RandomInt(5, 10);
	int totalScore = 0;
	for (int i = 0; i < randomLength; ++i) {
		randomWord += RandomInt('A', 'Z');
		totalScore += values[randomWord[i] - ((1 << 6) | 1)];
	}

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);
	int outputScore = scrabble.GetWordValue(randomWord);

	bool result = outputScore == totalScore;

	return result;
}
#pragma endregion
#endif
#pragma endregion

#pragma region Test - Create Pair
#if LAB6_CREATE_PAIR
int UnitTests_Lab6::Battery_CreatePair() {
	FailVector failVec;
	failVec.push_back(Fail_CreatePair_AllocatesDynamicMemory);
	failVec.push_back(Fail_CreatePair_FirstDoesNotStoreValue);
	failVec.push_back(Fail_CreatePair_SecondDoesNotStoreCorrectValue);

	PassVector passVec;
	passVec.push_back(Pass_CreatePair_FirstStoresCorrectValue);
	passVec.push_back(Pass_CreatePair_SecondStoresCorrectValue);

	int totalDeductions = UnitTestBattery("Testing CreatePair", POINTS_LAB6_CREATE_PAIR,failVec, passVec);
	int scoreForTest = CalculatePointsForTest(POINTS_LAB6_CREATE_PAIR, totalDeductions);

	return scoreForTest;
}

#pragma region Fail Tests
FailResult UnitTests_Lab6::Fail_CreatePair_AllocatesDynamicMemory() {
	DSA_Lab6 scrabble;
	
	size_t memoryDeltaStart = inUse;
	scrabble.CreatePair("TEST");
	size_t memoryDeltaEnd = inUse;

	FailResult result;
	result.check = memoryDeltaEnd > memoryDeltaStart;
	result.deduction = 10;
	result.msg = "No memory should be allocated";

	return result;
}

FailResult UnitTests_Lab6::Fail_CreatePair_FirstDoesNotStoreValue() {
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	DSA_Lab6 scrabble;
	
	auto currPair = scrabble.CreatePair(sampleWords[randomWordIndex]);

	FailResult result;
	result.check = currPair.first != sampleWords[randomWordIndex];
	result.deduction = 10;
	result.msg = "Word is not stored in proper portion of pair (or at all)";

	return result;
}

FailResult UnitTests_Lab6::Fail_CreatePair_SecondDoesNotStoreCorrectValue() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	int resultValue = 0;
	for (size_t i = 0; i < sampleWords[randomWordIndex].length(); ++i)
		resultValue += values[sampleWords[randomWordIndex][i] - ((1 << 6) | 1)];
	
	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);

	auto currPair = scrabble.CreatePair(sampleWords[randomWordIndex]);

	FailResult result;
	result.check = currPair.second != resultValue;
	result.deduction = 10;
	result.msg = "Word value is incorrect or not stored properly";

	return result;
}
#pragma endregion

#pragma region Pass Tests
bool UnitTests_Lab6::Pass_CreatePair_FirstStoresCorrectValue() {
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	DSA_Lab6 scrabble;

	auto currPair = scrabble.CreatePair(sampleWords[randomWordIndex]);

	bool result = currPair.first == sampleWords[randomWordIndex];

	return result;
}

bool UnitTests_Lab6::Pass_CreatePair_SecondStoresCorrectValue() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	int resultValue = 0;
	for (size_t i = 0; i < sampleWords[randomWordIndex].length(); ++i)
		resultValue += values[sampleWords[randomWordIndex][i] - ((1 << 6) | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);

	auto currPair = scrabble.CreatePair(sampleWords[randomWordIndex]);

	bool result = currPair.second == resultValue;

	return result;
}
#pragma endregion
#endif
#pragma endregion

#pragma region Test - Load File
#if LAB6_LOAD_FILE
int UnitTests_Lab6::Battery_LoadFile() {
	// Creating unique filename for test and duplicate file
	for (int i = 0; i < 8; ++i)
		mTempFilename += (char)RandomInt('a', 'z');
	mTempFilename += ".txt";
	CreateDuplicateFile("Files\\words.txt", mTempFilename.c_str());
	
	FailVector failVec;
	failVec.push_back(Fail_LoadFile_MapIsIncorrectSize);
	failVec.push_back(Fail_LoadFile_WordValuesAreIncorrect);

	PassVector passVec;
	passVec.push_back(Pass_LoadFile_MapIsCorrectSize);
	passVec.push_back(Pass_LoadFile_WordValuesAreCorrect);

	int totalDeductions = UnitTestBattery("Testing LoadFile - This will take a few seconds", POINTS_LAB6_LOAD_FILE,failVec, passVec);
	int scoreForTest = CalculatePointsForTest(POINTS_LAB6_LOAD_FILE, totalDeductions);

	// Cleaning up after all tests have been run
	std::remove(mTempFilename.c_str());

	return scoreForTest;
}

#pragma region Fail Tests
FailResult UnitTests_Lab6::Fail_LoadFile_MapIsIncorrectSize() {
	const int numWords = 178636;
	
	DSA_Lab6 scrabble;
	scrabble.LoadWords(mTempFilename.c_str());

	FailResult result;
	result.check = numWords != scrabble.mScrabbleMap.size();
	result.deduction = 25;
	result.msg = "Not all words were loaded into map";
	
	return result;
}

FailResult UnitTests_Lab6::Fail_LoadFile_WordValuesAreIncorrect() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	int resultValue = 0;
	for (size_t i = 0; i < sampleWords[randomWordIndex].length(); ++i)
		resultValue += values[sampleWords[randomWordIndex][i] - ((1 << 6) | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);

	scrabble.LoadWords(mTempFilename.c_str());
	auto word = scrabble.mScrabbleMap.find(sampleWords[randomWordIndex]);

	FailResult result;
	result.check = word == scrabble.mScrabbleMap.end() ||
				   resultValue != word->second;
	result.deduction = 20;
	result.msg = "Word values stored are incorrect";

	return result;
}
#pragma endregion

#pragma region Pass Tests
bool UnitTests_Lab6::Pass_LoadFile_MapIsCorrectSize() {
	const int numWords = 178636;

	DSA_Lab6 scrabble;
	scrabble.LoadWords(mTempFilename.c_str());

	bool result = numWords == scrabble.mScrabbleMap.size();

	return result;
}

bool UnitTests_Lab6::Pass_LoadFile_WordValuesAreCorrect() {
	int values[26];
	for (int i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	int resultValue = 0;
	for (size_t i = 0; i < sampleWords[randomWordIndex].length(); ++i)
		resultValue += values[sampleWords[randomWordIndex][i] - ((1 << 6) | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);

	scrabble.LoadWords(mTempFilename.c_str());
	auto word = scrabble.mScrabbleMap.find(sampleWords[randomWordIndex]);

	bool result = word != scrabble.mScrabbleMap.end() &&
		resultValue == word->second;

	return result;
}
#pragma endregion
#endif
#pragma endregion

#pragma region Test - Find Word Score
#if LAB6_FIND_WORD_SCORE
int UnitTests_Lab6::Battery_FindWordScore() {
	FailVector failVec;
	failVec.push_back(Fail_FindWordScore_DoesNotCallFind);
	failVec.push_back(Fail_FindWordScore_UsesLoop);
	failVec.push_back(Fail_FindWordScore_ReturnsIncorrectValueForFoundWord);
	failVec.push_back(Fail_FindWordScore_ReturnsIncorrectValueForWordNotFound);

	PassVector passVec;
	passVec.push_back(Pass_FindWordScore_CallsFind);
	passVec.push_back(Pass_FindWordScore_ReturnsCorrectValueForFoundWord);
	passVec.push_back(Pass_FindWordScore_ReturnsCorrectValueForWordNotFound);

	int totalDeductions = UnitTestBattery("Testing FindWordScore", POINTS_LAB6_FIND_WORD_SCORE,failVec, passVec);
	int scoreForTest = CalculatePointsForTest(POINTS_LAB6_FIND_WORD_SCORE, totalDeductions);

	return scoreForTest;
}

#pragma region Fail Tests
FailResult UnitTests_Lab6::Fail_FindWordScore_DoesNotCallFind() {
	bool callsFind = SearchFile("Lab6.h", "int FindValueInMap", "};", ".find(");

	FailResult result;
	result.check = callsFind == false;
	result.deduction = 25;
	result.msg = "Does not use .find";

	return result;
}

FailResult UnitTests_Lab6::Fail_FindWordScore_UsesLoop() {
	bool usesFor =	SearchFile("Lab6.h", "int FindValueInMap", "};", "for(") ||
					SearchFile("Lab6.h", "int FindValueInMap", "};", "while");

	FailResult result;
	result.check = usesFor == true;
	result.deduction = 25;
	result.msg = "No need for a loop";

	return result;
}


FailResult UnitTests_Lab6::Fail_FindWordScore_ReturnsIncorrectValueForFoundWord() {
	int values[26];
	for (size_t i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	int resultValue = 0;
	for (size_t i = 0; i < sampleWords[randomWordIndex].length(); ++i)
		resultValue += values[sampleWords[randomWordIndex][i] - ((1 << 6) | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);
	auto pair = std::make_pair(sampleWords[randomWordIndex], resultValue);
	scrabble.mScrabbleMap.insert(pair);

	int foundScore = scrabble.FindValueInMap(sampleWords[randomWordIndex]);

	FailResult result;
	result.check = resultValue != foundScore;
	result.deduction = 25;
	result.msg = "FindValueInMap not returning correct result for found word";

	return result;
}

FailResult UnitTests_Lab6::Fail_FindWordScore_ReturnsIncorrectValueForWordNotFound() {
	int values[26];
	for (size_t i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWord = "ZZZZ";
	
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	int resultValue = 0;
	for (size_t i = 0; i < sampleWords[randomWordIndex].length(); ++i)
		resultValue += values[sampleWords[randomWordIndex][i] - ((1 << 6) | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);
	auto pair = std::make_pair(sampleWords[randomWordIndex], resultValue);
	scrabble.mScrabbleMap.insert(pair);

	int foundScore = scrabble.FindValueInMap(sampleWord);

	FailResult result;
	result.check = -1 != foundScore;
	result.deduction = 25; 
	result.msg = "FindValueInMap not returning -1 for word not found";

	return result;
}
#pragma endregion

#pragma region Pass Tests
bool UnitTests_Lab6::Pass_FindWordScore_CallsFind() {
	bool callsFind = SearchFile("Lab6.h", "int FindValueInMap", "};", ".find(");

	bool result = callsFind == true;

	return result;
}

bool UnitTests_Lab6::Pass_FindWordScore_ReturnsCorrectValueForFoundWord() {
	int values[26];
	for (size_t i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWords[3] = { "APPLE", "PEROXIDE", "UMBRAGEOUSNESS" };
	int randomWordIndex = RandomInt(0, 2);
	int resultValue = 0;
	for (size_t i = 0; i < sampleWords[randomWordIndex].length(); ++i)
		resultValue += values[sampleWords[randomWordIndex][i] - ((1 << 6) | 1)];

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);
	auto pair = std::make_pair(sampleWords[randomWordIndex], resultValue);
	scrabble.mScrabbleMap.insert(pair);

	int foundScore = scrabble.FindValueInMap(sampleWords[randomWordIndex]);

	bool result = resultValue == foundScore;

	return result;
}

bool UnitTests_Lab6::Pass_FindWordScore_ReturnsCorrectValueForWordNotFound() {
	int values[26];
	for (size_t i = 0; i < 26; ++i)
		values[i] = RandomInt(1, 10);
	std::string sampleWord = "ZZZZ";

	DSA_Lab6 scrabble;
	memcpy(scrabble.mLetterValues, values, sizeof(int) * 26);

	int foundScore = scrabble.FindValueInMap(sampleWord);

	bool result = -1 == foundScore;

	return result;
}
#pragma endregion
#endif
#pragma endregion
#endif