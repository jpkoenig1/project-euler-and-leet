#include "../ll_framework.h"
#include "../ll_registry.h"

int max_water_area_impl(std::vector<int>& height) {
        int maxArea = 0;
        
        auto front = height.begin();
        auto back = height.end() - 1;
        
        
        while(front < back) {
            int curArea = std::min(*front, *back) * (back - front);
          if (maxArea < curArea) {
              maxArea = curArea;
          }
            if(*(front) < *(back) ) {
                ++front;
            } else {
                --back;
            }
            
        }
        return maxArea;
    }

    int max_water_area() {
        std::vector<int> heights_example = {1,8,6,2,5,4,8,3,7};
        return max_water_area_impl(heights_example);

    }

    REGISTER_PROBLEM(max_water_area)