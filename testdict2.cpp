#include <iostream>
#include "tddFuncs.h"
#include "WordCount.h"
void testWordCount() {
    WordCount wc;

    // Test incrementing word count
    wc.incrWordCount("Hello");
    wc.incrWordCount("world");
    wc.incrWordCount("hello"); // Should increment "Hello"

    // Test getWordCount
    ASSERT_EQUALS(2, wc.getWordCount("Hello"));  // "Hello" count should be 2
    ASSERT_EQUALS(1, wc.getWordCount("world"));  // "world" count should be 1
    ASSERT_EQUALS(0, wc.getWordCount("NonExistentWord"));  // Non-existent word should return 0

    // Test decrementing word count
    wc.decrWordCount("hello");
    ASSERT_EQUALS(1, wc.getWordCount("Hello"));  // "Hello" count should be 1
    wc.decrWordCount("Hello");
    ASSERT_EQUALS(0, wc.getWordCount("Hello"));  // "Hello" count should be 0 after decrementing twice

    // Test if a word exists after decrWordCount
    ASSERT_EQUALS(-1, wc.decrWordCount("Hello"));  // "Hello" should be removed, so it should return -1
}

void testMakeValidWord() {
    // Test valid words
    ASSERT_EQUALS("hello", WordCount::makeValidWord("Hello"));
    ASSERT_EQUALS("good-hearted", WordCount::makeValidWord("Good-Hearted"));

    // Test invalid words
    ASSERT_EQUALS("monkeys", WordCount::makeValidWord("13mOnkEYs-$"));
    ASSERT_EQUALS("paive", WordCount::makeValidWord("Pa55ive"));
    ASSERT_EQUALS("a", WordCount::makeValidWord("a123"));
}

void testEdgeCases() {
    WordCount wc;

    // Edge case for empty word
    ASSERT_EQUALS(0, wc.getWordCount(""));
    ASSERT_EQUALS("",WordCount::makeValidWord("12312"));
    ASSERT_EQUALS(-1, wc.decrWordCount(""));  // Should not crash or do anything

    // Edge case for non-alphabetical word (after conversion)
    ASSERT_EQUALS(0, wc.getWordCount("123word"));
}

int main() {
    std::cout << "Running test cases...\n";
    testWordCount();
    testMakeValidWord();
    testEdgeCases();
    return 0;
}