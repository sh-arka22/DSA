/*
HARD
Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array 
is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5],the expected output would be [120, 60, 40, 30, 24].
 If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

// https://leetcode.com/problems/product-of-array-except-self/




// This solution wont work when we have a 0 element in the array as division by zero is not possible
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long pro = 1;
        for(int el :nums){
            pro *= el;
        }
        vector<int>ans;
        for(int el : nums){
            ans.push_back(pro/el);
        }
        return ans;
    }
};




//Another solution is using prefix and suffix product array
Complexity will be O(2n) and O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>sufix(n);
        vector<int>ans(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i];
        }
        sufix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            sufix[i] = sufix[i+1]*nums[i];
        }
        ans[0] = sufix[1];
        ans[n-1] = prefix[n-2];
        for(int i=1;i<n-1;i++){
            ans[i] = prefix[i-1]*sufix[i+1];
        }
        return ans;
    }
};





//Optimised Solution that uses O(1) extra space and time O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        for(int i = 1; i < size(nums); i++) 
            ans[i] = ans[i-1] * nums[i-1];
        for(int i = size(nums)-1, suffixProd = 1; i >= 0; i--) {
            ans[i] *= suffixProd;          
            suffixProd *= nums[i];
        }
        return ans;
    }
};











