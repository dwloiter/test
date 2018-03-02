
#include <stdio.h>

#define CHECK(PRED) printf("%s ... %s\n", (PRED) ? "passed" : "FAILED", #PRED)

/*
 - returns the value of the smallest integer in the integer array a of n elements
 - pre-condition: n >= 1
*/
int arr_min(const int a[], size_t n)
{
    size_t i;
    int min = a[0];

    for (i = 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
    }

    return min;
}

/*
 - returns the number of occurrences of the integer x in the integer array a of n elements
*/
size_t arr_count(const int a[], size_t n, int x)
{
    size_t i;
    size_t numOfOccurrences = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            numOfOccurrences++;
        }
    }

    return numOfOccurrences;
}

/*
 - returns 1 if all the integers in the array a of n elemens are even; otherwise returns 0
*/
int arr_all_even(const int a[], size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            return 0;
        }
    }

    return 1;
}

/*
 - if the ineger x occurs in the integer array a of n elements, returns the index of its
   last occurrence in the array; otherwise, returns -1 (cast as size_t)
*/
size_t arr_find_last(const int a[], size_t n, int x)
{
    size_t i;
    size_t lastIndex = (size_t)-1;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            lastIndex = i;
        }
    }

    return lastIndex;
}

int main(void)
{
    int a[] = {2, 5, 0, 4, -1, 7};
    int b[] = {5, 5, 5, 5, 5, 5, 5, 5};
    int c[] = {2};
    int d[] = {1, 2, 3, 4, 4, 4, 8};

    CHECK(arr_min(a, sizeof(a) / sizeof(int)) == -1);
    CHECK(arr_min(b, sizeof(b) / sizeof(int)) == 5);
    CHECK(arr_min(c, sizeof(c) / sizeof(int)) == 2);
    CHECK(arr_min(d, sizeof(d) / sizeof(int)) == 1);

    CHECK(arr_count(a, sizeof(a) / sizeof(int), 1) == 0);
    CHECK(arr_count(b, sizeof(b) / sizeof(int), 5) == sizeof(b) / sizeof(int));
    CHECK(arr_count(c, sizeof(c) / sizeof(int), 2) == 1);
    CHECK(arr_count(d, sizeof(d) / sizeof(int), 4) == 2);

    CHECK(arr_all_even(a, sizeof(a) / sizeof(int)) == 0);
    CHECK(arr_all_even(b, sizeof(b) / sizeof(int)) == 0);
    CHECK(arr_all_even(c, sizeof(c) / sizeof(int)) == 1);
    CHECK(arr_all_even(d, sizeof(d) / sizeof(int)) == 0);

    CHECK(arr_find_last(a, sizeof(a) / sizeof(int), 5) == 1);
    CHECK(arr_find_last(b, sizeof(b) / sizeof(int), 5) == 7);
    CHECK(arr_find_last(c, sizeof(c) / sizeof(int), 5) == (size_t)-1);
    CHECK(arr_find_last(d, sizeof(d) / sizeof(int), 4) == 5);

    return 0;
}
