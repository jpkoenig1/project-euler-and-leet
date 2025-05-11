/***
A palindromic number reads the same both ways. The largest palindrome made from the product of two -digit numbers is
9009 = 91 x 99.

Find the largest palindrome made from the product of two 3-digit numbers.
***/
#include "../ll_registry.h"
#include "../ll_framework.h"
#include <iostream>

bool isPalindrome(int num) {

    std::string numString = std::to_string(num);
    auto start = numString.begin();
    auto back = numString.end() - 1;

    while(start < back) {
        if (*start != *back) {
            return false;
        }
        ++start;
        --back;
    }
    return true;
}

static long largestPalindrome() {

    long largest = 0;
    for (int i = 100; i < 1000; ++i) {
        for (int j = i; j < 1000; ++j) {
            int mult = i * j;
            if (isPalindrome(mult) && largest < mult) {
                largest = mult;
            }
        }
    }

    return largest;
}

REGISTER_PROBLEM(largestPalindrome)