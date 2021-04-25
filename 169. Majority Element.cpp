/**
 * Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, int> m;
        
        for (const auto n : nums) {
            ++m[n];
        }
        for (const auto val : nums) {
            if (m[val] > nums.size() / 2) {
                ret = val;
                break;
            }
        }
        
        return ret;
    }
};