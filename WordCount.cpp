// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int totalWords = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		 for (const std::pair<std::string, int>& pair : table[i]) {
            totalWords += pair.second; 
        }
	}
	return totalWords;
}

int WordCount::getNumUniqueWords() const {
    int uniqueWords = 0;
    for (const auto& pairs : table) { 
        uniqueWords += pairs.size(); 
    }
    return uniqueWords;
}

int WordCount::getWordCount(std::string word) const {
	if (word.size() == 0) {
		return 0;
	}
	std::string validWord = makeValidWord(word);
	size_t bucketIndex = hash(validWord);
	for (const std::pair<std::string, int>& pair : table[bucketIndex]) {
		if (pair.first == validWord) {
			return pair.second; 
		}
	}
	return 0; 
}
	
int WordCount::incrWordCount(std::string word) {
	std::string validWord = makeValidWord(word);
	if (validWord.size() == 0) { //possible edgecase
		return 0; 
	}

	size_t arrayIndex = hash(validWord);
	for (std::pair<std::string, int>& pair: table[arrayIndex]) {
        if (pair.first == validWord) {
            pair.second += 1;   
            return pair.second;  
        }
    }

	//else not found
	table[arrayIndex].emplace_back(validWord, 1); 

	return 1;
}

int WordCount::decrWordCount(std::string word) {
	std::string validWord = makeValidWord(word);
	if (validWord.size() == 0) { //edge case
		return -1; 
	}

	size_t arrayIndex = hash(validWord);
    for (auto iterator = table[arrayIndex].begin(); iterator != table[arrayIndex].end(); iterator++) {
        if (iterator->first == validWord) {
            if (iterator->second > 1) {
                iterator->second -= 1;
                return iterator->second;
            } else {
                table[arrayIndex].erase(iterator); // Remove if count is 1
                return 0;
            }
        }
    }
	//else not found
	return -1;
}

bool WordCount::isWordChar(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

std::string WordCount::makeValidWord(std::string word) {
	std::string validWord; 
	int start = 0;

	if (word.size() == 0) {
		return validWord;
	}

	for (size_t i = 0; i < word.size(); i++) {
		if (isWordChar(word[i])) {
			break;
		} else {
			start++; 
		}
	} 

	int end = word.size() - 1; 
	for (int i = word.size() - 1; i >= 0; i--) {
		if (isWordChar(word[i])) {
			break;
		} else {
			end--; 
		}
	} 

	if (start > end) {
		return validWord; //no word essentially
	}

	for (int i = start; i <= end; i++) {
		if (isWordChar(word[i])) {
            validWord += std::tolower(word[i]); 
        } else if ((word[i] == '-' || word[i] == '\'')) {
            validWord += word[i]; 
        }
	}
	return validWord; 
}
