/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

//https://leetcode.com/problems/first-missing-positive/

___________________________________Time->O(nLog(n)) and space->O(1)_____________________________________
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(begin(nums),end(nums));
        
        int min = 1;
        for(int el:nums){
            if(el == min){
                min++;
            }
        }
        
        return min;
    }
};


______________________________________Time->O(n) and Space->O(n)___________________________________
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end()); //O(n)
        
        for(int i=1;i<=nums.size();i++){ //O(n)
            if(st.count(i) == 0){
                return i;
            }
        }
        return nums.size()+1;
    }
};

______________________________________Time->O(n) and Space->O(1)______________________________________
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i] = 0;
            }
        }
        for(int i=0;i<n;i++){
            int idx = abs(nums[i]);
            if(idx>0 and idx<=n){
                if(nums[idx-1] == 0){
                    nums[idx-1] = -1*n; // NOTE 
                }
                else if(nums[idx-1]>0)
                    nums[idx-1] *= -1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            if(nums[i-1]>=0){
                return i;
            }
        }
        return n+1;
    }
};