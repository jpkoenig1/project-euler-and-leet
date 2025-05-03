#pragma once
#include <functional>
#include <unordered_map>
#include <string>
#include <iostream>
#include <any> // For type-erased storage
#include <sstream>
#include "ll_framework.h"

class ProblemRegistry {
    using ProblemFunc = std::function<std::any()>;
    static std::unordered_map<std::string, ProblemFunc>& get_map() {
        static std::unordered_map<std::string, ProblemFunc> impl;
        return impl;
    }

public:
    // Register any function with any return type
    template <typename Func>
    static void add_problem(const std::string& name, Func fn) {
        get_map()[name] = [fn]() -> std::any {
            return fn();
        };
    }

    static void run_problem(const std::string& name) {
        auto it = get_map().find(name);
        if (it != get_map().end()) {
            ProblemFramework::benchmark(it->second, name);
            // std::string result = it->second();
            // std::cout << name << " result: " << result << std::endl;
        } else {
            std::cerr << "Problem not found: " << name << std::endl;
        }
    }
};

// Macro to register any function (int/long long/etc)
#define REGISTER_PROBLEM(name) \
    namespace { \
        struct AutoRegister_##name { \
            AutoRegister_##name() { \
                ProblemRegistry::add_problem(#name, name); \
            } \
        } auto_reg_##name; \
    }