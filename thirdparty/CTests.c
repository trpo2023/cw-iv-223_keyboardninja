#include "ctest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/word_lib.h"

CTEST(input_test, correct_input) {
    char input[5] = "word";
    const char word[5] = "word";
    int result = strcmp(input, word);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, incorrect_input) {
    char input[5] = "word";
    const char word[5] = "abcd";
    int result = strcmp(input, word);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(language_choice_test, english_language) {
    int language_choice = 1;
    const char (*WORDS)[MAX_LENGTH]; 
    int words_num;
    if (language_choice == 1) { 
        WORDS = WORDS_EN;
        words_num = WORDS_NUM;
    }

    const char (*expected_WORDS)[MAX_LENGTH] = WORDS_EN;
    int expected_words_num = WORDS_NUM;
    ASSERT_EQUAL(expected_words_num, words_num);
    for (int i = 0; i < expected_words_num; ++i) {
        ASSERT_STR(expected_WORDS[i], WORDS[i]);
    }
}

CTEST(language_choice_test, russian_language) {
    int language_choice = 2;
    const char (*WORDS)[MAX_LENGTH]; 
    int words_num;
    if (language_choice == 2) { 
        WORDS = WORDS_RU;
        words_num = WORDS_NUM;
    }

    const char (*expected_WORDS)[MAX_LENGTH] = WORDS_RU;
    int expected_words_num = WORDS_NUM;
    ASSERT_EQUAL(expected_words_num, words_num);
    for (int i = 0; i < expected_words_num; ++i) {
        ASSERT_STR(expected_WORDS[i], WORDS[i]);
    }
}

CTEST(accuracy_test, calculate_accuracy) {
    int num_correct = 5;
    int num_words = 10;
    double expected_accuracy = 50.0;
    double accuracy = (double)num_correct / num_words * 100;
    ASSERT_DBL_NEAR(expected_accuracy, accuracy);
}

CTEST(input_test, exit_input) {
    char input[2] = "q";
    int result = strcmp(input, "q");
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}
