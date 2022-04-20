/*
EASY
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/


______________________________O(n)   Space:O(n)_______________________________________________

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int el = nums[i];
             if(mp.count(target-el) != 0  ){
                return {mp[(target-el)],i};
            }
            mp[el] = i;
        }
        return {};
    }
};
 


