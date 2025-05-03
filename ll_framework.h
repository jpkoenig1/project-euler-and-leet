// ll_framework.h
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map> 
#include <chrono>

namespace ProblemFramework {
    using std::vector;
    using std::string;
    using std::unordered_map;
    
    // Input parser for LeetCode-style test cases
    template<typename T>
    vector<T> parse_input(const string& raw) {
        vector<T> result;
        // Implementation from lc-cpp template [1]
        return result;
    }

    // Benchmarking utility

    template<typename Func>
    void benchmark(Func&& f, const string& problem_name) {
        // Fully qualify chrono components
        auto start = std::chrono::high_resolution_clock::now();
        auto result = f();
        auto end = std::chrono::high_resolution_clock::now();
        
        // Explicitly use std::cout
        std::cout << problem_name << " result: " << result 
                  << " | Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << "ms\n";
    }

}
