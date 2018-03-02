
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHECK(PRED) printf("%s ... %s\n", (PRED) ? "passed" : "failed", #PRED)

/*
 - replace all occurrences of the character oldc in the string s by the charactr newc
 - returns the number of replacements
*/
size_t str_replace_all(char s[], int oldc, int newc)
{
    size_t i;
    size_t numberOfReplacements = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == (char)oldc)
        {
            s[i] = (char)newc;
            numberOfReplacements++;
        }
    }

    return numberOfReplacements;
}

/*
 - replaces the last occurrence of the character oldc in the string s by the character newc
 - returns 1 if a replacement has been made; otherwise returns 0
*/
int str_replace_last(char s[], int oldc, int newc)
{
    size_t i;
    size_t lastIndex = (size_t)-1;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == (char)oldc)
        {
            lastIndex = i;
        }
    }

    if (lastIndex != (size_t)-1)
    {
        s[lastIndex] = (char)newc;
        return 1;
    }

    return 0;
}

/*
 - returns 1 if the string s consists entirely of digits; otherwise, returns 0
*/
int str_all_digits(const char s[])
{
    size_t i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return 0;
        }
    }

    return 1;
}

/*
 - returns 1 if the 2 strings s and t consist of the same sequence of characters; otherwise, returns 0
*/
int str_equal(const char s[], const char t[])
{
    size_t i;
    for (i = 0; s[i] != '\0' && t[i] != '\0'; i++)
    {
        if (s[i] != t[i])
        {
            return 0;
        }
    }

    return s[i] == t[i];
}

int main(void)
{
    /* test for str_replace_all */
    {
        char s1[] = "hello world";
        char s2[] = "kkkkkkkkkkk";
        char s3[] = "hello world";

        CHECK(str_replace_all(s1, 'l', 'x') == 3);
        CHECK(strcmp(s1, "hexxo worxd") == 0);
        CHECK(str_replace_all(s2, 'l', 'x') == 0);
        CHECK(strcmp(s2, "kkkkkkkkkkk") == 0);
        CHECK(str_replace_all(s3, 'd', 'x') == 1);
        CHECK(strcmp(s3, "hello worlx") == 0);
    }

    /* test for str_replace_last */
    {
        char s4[] = "hello world";
        char s5[] = "kkkkkkkkkkk";
        char s6[] = "hello world";

        CHECK(str_replace_last(s4, 'l', 'x') == 1);
        CHECK(strcmp(s4, "hello worxd") == 0);
        CHECK(str_replace_last(s5, 'k', 'x') == 1);
        CHECK(strcmp(s5, "kkkkkkkkkkx") == 0);
        CHECK(str_replace_last(s6, 'a', 'x') == 0);
        CHECK(strcmp(s6, "hello world") == 0);
    }

    /* test for str_all_digits */
    {
        char s7[] = "1234567890";
        char s8[] = "1234aaa";
        char s9[] = "hello world";

        CHECK(str_all_digits(s7) == 1);
        CHECK(str_all_digits(s8) == 0);
        CHECK(str_all_digits(s9) == 0);
    }

    /* test for str_str_equal */
    {
        char s10[] = "hello world";
        char s11[] = "hello world aa";
        char s12[] = "hello world";
        char s13[] = "asdfqwerdad";

        CHECK(str_equal(s10, s11) == 0);
        CHECK(strcmp(s10, s11) != 0);
        CHECK(str_equal(s10, s12) == 1);
        CHECK(strcmp(s10, s12) == 0);
        CHECK(str_equal(s10, s13) == 0);
        CHECK(strcmp(s10, s13) != 0);
    }

    return 0;
}
