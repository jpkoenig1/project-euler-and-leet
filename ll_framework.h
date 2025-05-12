// ll_framework.h
#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <any> 

namespace ProblemFramework {
    
    // Helper function to cast outputs appropriately. Possibly need to recurse through containers.
    std::string resolveType(std::any result_any);

    // Run the function/problem and benchmark results.
    template<typename Func>
    void benchmark(Func&& f, const std::string& problem_name) {
        // Get the timing for solution.
        auto start = std::chrono::high_resolution_clock::now();
        std::any result_any = f();
        auto end = std::chrono::high_resolution_clock::now();
        
        std::string result_str = resolveType(result_any);

        // Print results to terminal.
        std::cout << problem_name << " result: " << result_str
                  << " | Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << "ms\n";
    }

}
