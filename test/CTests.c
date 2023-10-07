#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/lib/func.h"
#include "../src/lib/word_lib.h"

CTEST(input_test, correct_input) {
    char input[5] = "word";
    const char word[5] = "word";
    int result = checkWord(word, input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(input_test, incorrect_input) {
    char input[5] = "word";
    const char word[5] = "abcd";
    int result = checkWord(word, input);
    int expected = 0;
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

CTEST(accuracy_test, calculate_accuracy_zero_words) {
    int num_correct = 0;
    int num_words = 0;
    double expected_accuracy = 0.0;
    double accuracy = calculateAccuracy(num_correct, num_words);
    ASSERT_DBL_NEAR(expected_accuracy, accuracy);
}

CTEST(accuracy_test, calculate_accuracy_all_words_correct) {
    int num_correct = 5;
    int num_words = 5;
    double expected_accuracy = 100.0;
    double accuracy = calculateAccuracy(num_correct, num_words);
    ASSERT_DBL_NEAR(expected_accuracy, accuracy);
}

CTEST(input_test, correct_exit_input) {
    char input[2] = "q";
    int result = checkWord("q", input);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}