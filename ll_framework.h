// ll_framework.h
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map> 
#include <chrono>
#include <any> 

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

    // Helper function to cast outputs appropriately. Possibly need to recurse through containers.
    std::string resolveType(std::any result_any);
    
    // Run the function/problem and benchmark results.
    template<typename Func>
    void benchmark(Func&& f, const std::string& problem_name) {
        // Fully qualify chrono components
        auto start = std::chrono::high_resolution_clock::now();
        std::any result_any = f();
        auto end = std::chrono::high_resolution_clock::now();
        
        std::string result_str = resolveType(result_any);

        // Explicitly use std::cout
        std::cout << problem_name << " result: " << result_str
                  << " | Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << "ms\n";
    }

}
