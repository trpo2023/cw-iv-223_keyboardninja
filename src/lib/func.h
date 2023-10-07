#include <stdio.h>
#include <string.h>

int chooseLanguage() {
    int language_choice = 0;
    scanf("%d", &language_choice);
    return language_choice;
}

int checkWord(const char* word, const char* input) {
    if (strcmp(word, input) == 0) {
        return 1;
    } else {
        return 0;
    }
}

double calculateAccuracy(int num_correct, int num_words) {
    if (num_words > 0) {
        double accuracy = (double)num_correct / num_words * 100;
        return accuracy;
    } else {
        return 0;
    }
}