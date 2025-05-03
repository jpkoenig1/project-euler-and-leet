// project_euler/p1.cpp
#include "../ll_framework.h"
#include "../ll_registry.h"

static int sum_even_fib() {
    long sum = 0;
    long fib1 = 2;
    long fib2 = 8;
    long max = 4000000;

    while(fib2 < max) {
        if(fib2 % 2 == 0) sum += fib2;
        int tmp = fib2;
        fib2 += fib1;
        fib1 = tmp;
    }
    return sum;
}

REGISTER_PROBLEM(sum_even_fib)
