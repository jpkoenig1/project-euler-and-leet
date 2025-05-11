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

    // Benchmarking utility

    template<typename Func>
    void benchmark(Func&& f, const std::string& problem_name) {
        // Fully qualify chrono components
        auto start = std::chrono::high_resolution_clock::now();
        std::any result_any = f();
        auto end = std::chrono::high_resolution_clock::now();
        
        std::string result_str;
        if (result_any.type() == typeid(int)) {
            result_str = std::to_string(std::any_cast<int>(result_any));
        } else if (result_any.type() == typeid(long long)) {
            result_str = std::to_string(std::any_cast<long long>(result_any));
        } else if (result_any.type() == typeid(long)) {
            result_str = std::to_string(std::any_cast<long>(result_any));
        } else {
            result_str = "(unknown type)";
        }

        // Explicitly use std::cout
        std::cout << problem_name << " result: " << result_str
                  << " | Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << "ms\n";
    }

}
