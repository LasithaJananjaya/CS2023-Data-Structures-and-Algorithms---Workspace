#include <vector>
#include <algorithm>
#include <climits>

std::vector<int> findClosestNumbers(std::vector<int> nums) {
    std::vector<int> tempNums(nums.size());
    int minDiff = INT_MAX;
    int n = nums.size();
    
    std::sort(nums.begin(), nums.end());
    
    for (int i = 1; i < n; i++){
        tempNums[i] = nums[i] - nums[i - 1];
        if (minDiff > tempNums[i]) {
            minDiff = tempNums[i];
        }  
    }
    
    std::vector<int> result;
    for (int i = 1; i < n; i++){
        if (tempNums[i] == minDiff){
            result.push_back(nums[i - 1]);
            result.push_back(nums[i]);
        }
    }
    
    return result;
}
