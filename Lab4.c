
#include <stdio.h>
#include <ctype.h>

/* */
void squeeze_spaces(void)
{
    int c;
    int prevSpace = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            c = ' ';
        }

        if (c != ' ' || !prevSpace)
        {
            putchar(c);
        }

        prevSpace = c == ' ';
    }
}

/* */
void format_words(void)
{
    int c;
    int IsFirst = 1;
    while ((c = getchar()) != EOF)
    {
        putchar(IsFirst ? toupper(c) : tolower(c));
        IsFirst = isspace(c) || c == '\"';
    }
}

int main(void)
{
    /* squeeze_spaces */
    /* squeeze_spaces(); */

    /* format_words */
    format_words();
    return 0;
}
