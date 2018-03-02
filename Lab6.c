
#include <stdio.h>

#define CHECK(PRED) printf("%s ... %s\n", (PRED) ? "passed" : "FAILED", #PRED)

/* pre-condition: n >= 1 */
void min_max(const int a[], size_t n, int *pmin, int *pmax)
{
    size_t i;
    *pmin = a[0];
    *pmax = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] < *pmin)
        {
            *pmin = a[i];
        }
        else if (a[i] > *pmax)
        {
            *pmax = a[i];
        }
    }
}

size_t num_digits(unsigned long n)
{
    size_t ret = 0;
    while (n > 0)
    {
        n /= 10;
        ret++;
    }

    return ret == 0 ? 1 : ret;
}

int is_reversible(unsigned long n)
{
    unsigned long revNum = 0;
    unsigned long temp = n;
    while (temp)
    {
        revNum *= 10;
        revNum += temp % 10;
        temp /= 10;
    }

    return revNum == n;
}

int main(void)
{
    {
        int testArray1[] = {0, 1, 2, 3, 4, 5, -1};
        int testArray2[] = {1};
        int testArray3[] = {3, 3, 3, 3, 3, 3, 3, 3};
        int *p;

        int min, max;

        min_max(testArray1, sizeof(testArray1) / sizeof(int), &min, &max);
        CHECK(min == -1);
        CHECK(max == 5);

        min_max(testArray2, sizeof(testArray2) / sizeof(int), &min, &max);
        CHECK(min == 1);
        CHECK(max == 1);

        min_max(testArray3, sizeof(testArray3) / sizeof(int), &min, &max);
        CHECK(min == 3);
        CHECK(max == 3);

        p = &(testArray1[2]);

        printf("%d", p[2]);
    }

    {
        unsigned long test1 = 0;
        unsigned long test2 = 2348703475;
        unsigned long test3 = 1234;

        CHECK(num_digits(test1) == 1);
        CHECK(num_digits(test2) == 10);
        CHECK(num_digits(test3) == 4);
    }

    {
        unsigned long test1 = 3;
        unsigned long test2 = 327686723;
        unsigned long test3 = 1221;
        unsigned long test4 = 0;

        unsigned long test5 = 2342;
        unsigned long test6 = 327327;

        CHECK(is_reversible(test1));
        CHECK(is_reversible(test2));
        CHECK(is_reversible(test3));
        CHECK(is_reversible(test4));

        CHECK(!is_reversible(test5));
        CHECK(!is_reversible(test6));
    }
}


