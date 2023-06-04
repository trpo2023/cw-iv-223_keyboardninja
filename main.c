#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORDS_NUM 7 // Количество слов
#define MAX_LENGTH 40 // Максимальная длина слова

const char WORDS_EN[WORDS_NUM][MAX_LENGTH] = { // Список английских слов
    "hello", 
    "world", 
    "function",
    "programming",
    "language",
    "computer",
    "keyboard"
};

const char WORDS_RU[WORDS_NUM][MAX_LENGTH] = { // Список русских слов
    "привет",
    "мир",
    "функция",
    "программирование",
    "язык",
    "компьютер",
    "клавиатура"
};

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    char input[MAX_LENGTH];
    int num_rounds = 0; // Количество раундов
    int num_correct = 0; // Количество правильных ответов
    int language_choice = 0; // Выбор языка

    printf("Welcome to the typing trainer!\n\n");

    printf("Choose language / Выберите язык:\n");
    printf("1 - English / Английский\n");
    printf("2 - Russian / Русский\n");
    scanf("%d", &language_choice);

    const char (*WORDS)[MAX_LENGTH]; // Указатель на массив слов
    int words_num; // Количество слов

    if (language_choice == 1) { // Если выбран английский язык
        WORDS = WORDS_EN;
        words_num = WORDS_NUM;
    }
    else if (language_choice == 2) { // Если выбран русский язык
        WORDS = WORDS_RU;
        words_num = WORDS_NUM;
    }
    else { // Если выбран неверный вариант
        printf("Invalid choice. Terminating program...");
        return 0;
    }

    while (1) { // Бесконечный цикл
        int rand_index = rand() % words_num; // Выбор случайного индекса в диапазоне [0, words_num-1]
        char word[MAX_LENGTH];
        strcpy(word, WORDS[rand_index]); // Копируем слово в переменную word

        printf("Type the following word and press ENTER or type 'q' to quit:\n");
        printf("%s\n", word);

        scanf("%s", input);

        if (strcmp(input, "q") == 0) // Если пользователь ввел 'q' - завершить игру
            break;

        num_rounds++; // Увеличиваем счетчик раундов

        if (strcmp(word, input) == 0) {
            printf("Congratulations! You typed correctly\n");
            num_correct++; // Увеличиваем счетчик правильных ответов
        }
        else
            printf("Sorry, you made a mistake. The correct word is: %s\n", word);
        
        printf("\n");
    }

    printf("Thanks for playing!\n");
    printf("You played %d rounds and got %d answers correct.\n", num_rounds, num_correct);

    return 0;
}
