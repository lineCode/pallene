#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Use 1-based arrays!
size_t binsearch(int64_t *t, size_t N, int64_t x)
{
    size_t lo = 1;
    size_t hi = N;

    size_t steps = 0;

    while (lo < hi) {
        size_t mid = lo + (hi - lo)/2;
        steps++;
        int64_t tmid = t[mid];

        if (x == tmid) {
            return steps;
        } else if (x < tmid) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return steps;
}

size_t test(int64_t *t, size_t N)
{
    size_t out = 0;
    for (size_t i = 1; i <= 10000000; i++) {
        if (binsearch(t, N, i) != 22) {
            out++;
        }
    }
    return out;
}

int main()
{
    size_t N = 1000000;
    int64_t *xs = malloc((1+N)*sizeof(int64_t));
    for (size_t i = 1; i <= N; i++) {
        xs[i] = i;
    }

    size_t out = test(xs, N);
    printf("%lu\n", out);
}
