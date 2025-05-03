// project_euler/p1.cpp
#include "../ll_framework.h"
#include "../ll_registry.h"

int sum_multiples() {
    int sum = 0;
    for(int i = 3; i < 1000; ++i) {
        if(i % 3 == 0 || i % 5 == 0) sum += i;
    }
    return sum;
}

REGISTER_PROBLEM(sum_multiples)
