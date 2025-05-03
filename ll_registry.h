// ll_registry.h
#pragma once
#include <functional>
#include <unordered_map>
#include <string>
#include <iostream>
#include "ll_framework.h"

class ProblemRegistry {
    using ProblemFunc = std::function<int()>;
    static std::unordered_map<std::string, ProblemFunc>& get_map() {
        static std::unordered_map<std::string, ProblemFunc> impl;
        return impl;
    }
public:
    static void add_problem(const std::string& name, ProblemFunc fn) {
        get_map()[name] = fn;
    }
    static void run_problem(const std::string& name) {
        auto it = get_map().find(name);
        if(it != get_map().end()) {
            ProblemFramework::benchmark(it->second, name);
            // int result = it->second();
            // std::cout << name << " result: " << result << std::endl;
        } else {
            std::cerr << "Problem not found: " << name << std::endl;
        }
    }
};

#define REGISTER_PROBLEM(name) \
    namespace { \
        struct AutoRegister_##name { \
            AutoRegister_##name() { \
                ProblemRegistry::add_problem(#name, name); \
            } \
        } auto_reg_##name; \
    }
