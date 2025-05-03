// project_euler/p1.cpp
#include "../ll_framework.h"
#include "../ll_registry.h"

static long long largest_prime_factor() {
    long long num = 600851475143;
    long long biggest_fact = -1;

    while(num % 2 == 0) {
        num /= 2;
        biggest_fact = 2;
    }


    for(long long i = 3; i < std::sqrt(num); i +=2 ) {
        if ( num % i == 0) {
            biggest_fact = i;
            num /= i;
        }
    }

    if(num > 2)
        biggest_fact = num;

    return biggest_fact;
}

REGISTER_PROBLEM(largest_prime_factor)