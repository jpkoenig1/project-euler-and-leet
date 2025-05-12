#include "../ll_framework.h"
#include "../ll_registry.h"

std::vector<int> twoSumImpl(std::vector<int>& nums, int target) {
    std::vector<int> solution;
    std::unordered_map<int, int > map;
    
    for(int i = 0; i < nums.size(); ++i) {
        map.emplace(target - nums[i], i);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if(map.contains(nums[i]) && map[nums[i]] != i) {
            solution.push_back(i);
            solution.push_back(map[nums[i]]);
                return solution;
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