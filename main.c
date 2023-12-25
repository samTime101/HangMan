#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100

int main()
{
    srand(time(NULL));

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordsCount = 0;
    FILE *file = fopen("list_export.txt", "r");
    // stricts the buffer
    while (fscanf(file, "%49s", words[wordsCount]) == 1)
    {
        // checking and scanning the words matching bufffer
        wordsCount++;
        if (wordsCount >= MAX_WORDS)
        {
            break;
        }
    }
    fclose(file);
    //-------------------------------------------------------------------------
    // Random string assigning function

    // generarates a random no between 0 and wordcount
    int x = rand() % wordsCount;
    // now that random number is choosen as index for random word
    char random_word[MAX_WORD_LENGTH];
    // copying to random_word from words[x]
    strcpy(random_word, words[x]);
    //-------------------------------------------------------------------------
    char userinput;
    bool gameover = false, found, underscore;
    int length = strlen(random_word);
    int index;
    int chances = 7;
    char empty_list[MAX_WORD_LENGTH];
    //-------------------------------------------------------------------------

    for (index = 0; index < length; index++)
    {
        empty_list[index] = '_';
    }

    empty_list[length] = '\0';

    printf("%s\n", empty_list);

    while (!gameover)
    {
        printf("Guess the word: ");
        scanf(" %c", &userinput);
        found = false;
        underscore = false;

        for (index = 0; index < length; index++)
        {
            char letter = random_word[index];

            if (letter == userinput)
            {
                empty_list[index] = letter;
                printf("Beep..:\n");
                found = true;
                Beep(720, 300);
            }
        }

        printf("Current: %s\n", empty_list);

        if (!found)
        {
            chances--;
            Beep(1120, 300);
            printf("You have %d chances left\n", chances);
        }

        for (index = 0; index < length; index++)
        {
            if (empty_list[index] == '_' && chances == 0)
            {
                gameover = true;
                break;
            }
        }

        for (index = 0; index < length; index++)
        {
            if (empty_list[index] == '_')
            {
                underscore = true;
                break;
            }
        }

        if (!underscore)
        {
            gameover = true;
            break;
        }
    }

    if (gameover && (chances > 0))
        printf("YOU WON\n");
    else
        printf("Sorry, you lost. The word was %s\n", random_word);

    return 0;
}
