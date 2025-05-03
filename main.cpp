// main.cpp
#include "ll_registry.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: ./framework <problem_name>\n";
        return 1;
    }
    
    ProblemRegistry::run_problem(argv[1]);
    return 0;
}