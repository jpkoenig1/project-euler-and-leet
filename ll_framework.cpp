
#include "ll_framework.h"
#include <string>
#include <any>

namespace ProblemFramework {


std::string resolveType(std::any result_any) { 
        std::cout << "Inside resolveTyp" << std::endl;

        if (result_any.type() == typeid(int)) {
            return std::to_string(std::any_cast<int>(result_any));
        } else if (result_any.type() == typeid(long long)) {
            return std::to_string(std::any_cast<long long>(result_any));
        } else if (result_any.type() == typeid(long)) {
            return std::to_string(std::any_cast<long>(result_any));
        } else if (result_any.type() == typeid(std::vector<int> )) {
            std::string result_str = "[";
            std::vector<int> int_vec = std::any_cast<std::vector<int>>(result_any);
            for(int i : int_vec) {
                result_str += ( std::to_string(i) + "," );
            }
            return result_str;
        } else {
            return "(unknown type)";
        }
    }
}