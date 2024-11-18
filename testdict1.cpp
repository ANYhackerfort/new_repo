#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {
    WordCount wc;

    assertEquals(1, wc.incrWordCount("hello"), "", __LINE__);
    assertEquals(2, wc.incrWordCount("hello"), "", __LINE__);
    assertEquals(1, wc.incrWordCount("world"), "", __LINE__);
    assertEquals(2, wc.getWordCount("hello"), "", __LINE__);
    assertEquals(1, wc.getWordCount("world"), "", __LINE__);

    assertEquals(2, wc.getNumUniqueWords(), "", __LINE__);
    assertEquals(3, wc.getTotalWords(), "", __LINE__);

    assertEquals(3, wc.incrWordCount("HELLO"), "", __LINE__);
    assertEquals(3, wc.getWordCount("hello"), "", __LINE__);
    assertEquals(1, wc.getWordCount("world"), "", __LINE__);

    assertEquals(0, wc.incrWordCount("12345"), "", __LINE__);
    assertEquals(0, wc.incrWordCount(""), "", __LINE__);
    assertEquals(4, wc.incrWordCount("$$hello$$"), "", __LINE__);
    assertEquals(0, wc.getWordCount("12345"), "", __LINE__);
    assertEquals(0, wc.getWordCount(""), "", __LINE__);

    assertEquals(2, wc.getNumUniqueWords(), "", __LINE__);
    assertEquals(5, wc.getTotalWords(), "", __LINE__);

    assertEquals(1, wc.incrWordCount("can't"), "", __LINE__);
    assertEquals(1, wc.incrWordCount("good-hearted"), "", __LINE__);
    assertEquals(1, wc.getWordCount("can't"), "", __LINE__);
    assertEquals(1, wc.getWordCount("good-hearted"), "", __LINE__);

    assertEquals(3, wc.decrWordCount("hello"), "", __LINE__);
    assertEquals(2, wc.decrWordCount("hello"), "", __LINE__);
    assertEquals(1, wc.decrWordCount("hello----213123"), "", __LINE__);
    assertEquals(0, wc.decrWordCount("hello"), "", __LINE__);
    assertEquals(-1, wc.decrWordCount("hello"), "", __LINE__);

    assertEquals(-1, wc.decrWordCount("-1123"), "", __LINE__);
    assertEquals(-1, wc.decrWordCount("-1123"), "", __LINE__);
    assertEquals(-1, wc.decrWordCount("---Hello21123"), "", __LINE__);

    assertEquals(1, wc.incrWordCount("123monkEYs-$"), "", __LINE__);
    assertEquals(1, wc.getWordCount("monkeys"), "", __LINE__);

    assertEquals(0, wc.incrWordCount(""), "", __LINE__);
    assertEquals(0, wc.getWordCount(""), "", __LINE__);

    assertTrue(WordCount::isWordChar('A'), "", __LINE__);
    assertTrue(WordCount::isWordChar('z'), "", __LINE__);
    assertTrue(!WordCount::isWordChar('1'), "", __LINE__);
    assertTrue(!WordCount::isWordChar('$'), "", __LINE__);

    assertEquals("monkeys", WordCount::makeValidWord("123monkEYs-$"), "", __LINE__);
    assertEquals("can't", WordCount::makeValidWord("can't"), "", __LINE__);
    assertEquals("good-hearted", WordCount::makeValidWord("good-hearted"), "", __LINE__);
    assertEquals("good-hearted", WordCount::makeValidWord("good-hearted-------------------"), "", __LINE__);
    assertEquals("good-hearted", WordCount::makeValidWord("---------------good-hearted-------------------"), "", __LINE__);
    assertEquals("", WordCount::makeValidWord("12345"), "", __LINE__);
    assertEquals("", WordCount::makeValidWord("---"), "", __LINE__);

    return 0;
}