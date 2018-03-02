
#include <stdio.h>
#include <string.h>

#define LINESIZE 512
#define WORDSIZE 20
#define MIN_VALUE 0
#define MAX_VALUE 100

/* - returns 1 if a word is successfully read & stored in the array word of n
     characters; returns 0 on end-of-file or when the user enters a blank line
   - precondition: n < LINESIZE (a macro with a value of 512 */
int get_word(const char prompt[], char word[], size_t n)
{
    char line[LINESIZE];
    char temp[LINESIZE];
    while (1)
    {
        printf("%s", prompt);

        if (!fgets(line, LINESIZE, stdin))
        {
            break;
        }

        if (sscanf(line, "%s", temp) != EOF)
        {
            if (strlen(temp) < n)
            {
                strcpy(word, temp);
                return 1;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

/* - if an integer between min & max inclusive is successfully read, it is returned;
     otherwise, the integer -1 is returned either on end-of-file or when the user
     enters a blank line
   - precondition: 0 <= min && min <= max */
int get_int(const char prompt[], int min, int max)
{
    char line[LINESIZE];
    int scanfRet;
    int ret;
    while (1)
    {
        printf("%s", prompt);

        if (!fgets(line, LINESIZE, stdin))
        {
            break;
        }

        scanfRet = sscanf(line, "%d", &ret);

        if (scanfRet == EOF)
        {
            break;
        }
        else if (scanfRet == 1 && ret >= min && ret <= max)
        {
                return ret;
        }
    }

    return -1;
}

int main(void)
{
    char word[WORDSIZE];
    int number;
    while (get_word("Enter a word\n", word, WORDSIZE))
    {
        printf("%s\n", word);
    }

    while ((number = get_int("Enter a integer between 0 and 100\n", MIN_VALUE, MAX_VALUE)) != -1)
    {
        printf("%d", number);
    }
    
    return 0;
}
