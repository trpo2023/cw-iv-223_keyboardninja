#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORDS_NUM 12 
#define MAX_LENGTH 40 

const char WORDS_EN[WORDS_NUM][MAX_LENGTH] = {"verify", "plug", "debug", "access", "include",
 "keyboard", "language", "network", "process", "programming","mouse","useless"
};

const char WORDS_RU[WORDS_NUM][MAX_LENGTH] = {
"переменная", "алгоритм", "разработчик", "отказоустойчивость", "компьютер", "реализация", 
"функция", "библиотека", "веб-страница", "таблица","оператор","обработка"
};

int main() {
    srand(time(NULL));
    char input[MAX_LENGTH];
    int num_words = 0; 
    int num_correct = 0; 
    int language_choice = 0;
    printf("Добро пожаловать в Keyboard Ninja!\n\n");

    printf("Выберите язык:\n");
    printf("1 - Английский\n");
    printf("2 - Русский\n");
    scanf("%d", &language_choice);

    const char (*WORDS)[MAX_LENGTH]; 
    int words_num;

    if (language_choice == 1) { 
        WORDS = WORDS_EN;
        words_num = WORDS_NUM;
    }
    else if (language_choice == 2) { 
        WORDS = WORDS_RU;
        words_num = WORDS_NUM;
    }
    else { 
        printf("Такого варианта языка нет...");
        return 0;
    }

    while (1) { 
        int rand_index = rand() % words_num;
        char word[MAX_LENGTH];
        strcpy(word, WORDS[rand_index]); 
        printf("Нажмите ENTER для ввода или 'q' для выхода:\n");
        printf("%s\n", word);
        scanf("%s", input);

        if (strcmp(input, "q") == 0)
            break;

        num_words++;

        if (strcmp(word, input) == 0) {
            printf("Замечательно! Вы ввели слово верно!\n");
            num_correct++; 
        }
        else
            printf("Вы допустили ошибку! Правильное слово: %s\n", word);
        
        printf("\n");
    }
    
    printf("Спасибо за игру!\n");
    printf("Всего слов: %d \nПравильных слов: %d\n", num_words, num_correct);
    if (num_words > 0) { 
        double accuracy = (double)num_correct / num_words * 100; 
        printf("Точность: %.2f%%\n", accuracy);
    }

    return 0;

}


