#include "../ll_framework.h"
#include "../ll_registry.h"

std::vector<int> twoSumImpl(std::vector<int>& nums, int target) {
        std::vector<int> solution;
        std::unordered_map<int, int > indexMap;
        
       for(int i = 0; i < nums.size(); ++i) {
           int value = nums[i];
           
            auto otherIndex = indexMap.find(value);
            if ( otherIndex != indexMap.end()) {
                solution.push_back(i);
                solution.push_back(otherIndex->second);
                return solution;
            }    
            else{           
                indexMap.emplace(target - nums[i], i);
            }
        }
        return solution;
    }

std::vector<int> two_sum() {

    std::vector<int> exampleNums = {2,9,11,13};
    int exampleTarget = 7;

    return twoSumImpl(exampleNums, exampleTarget);
}

REGISTER_PROBLEM(two_sum)