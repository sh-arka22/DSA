/**
 * 386 · Longest Substring with At Most K Distinct Characters
 * 
 * @file 8-02-2022.cpp
 * @author Arakjyoti Saha (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * HARD
 * 
 Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
 */

//https://www.lintcode.com/problem/386/
//leetcode-> 386(HARD)



/**
 * @brief similar questions
 * 3. Longest Substring Without Repeating Characters
 * 928 · Longest Substring with At Most K Distinct Characters
 * 992. Subarrays with K Different Integers
 * 
 */

3. Longest Substring Without Repeating Characters
.................................____nlog(n)__
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        multiset<char>st;
        int n = s.size();
        int l = 0;
        int r = 0;
        
        int maxi = 0;
        while(l<=r and r<n){
            if(st.count(s[r]) == 0){
                maxi = max(maxi,r-l+1);
                st.insert(s[r]);
                r++;
            }
            else if(st.count(s[r]) > 0){
                auto it = st.find(s[l]);
                st.erase(it);
                l++;
            }
        }
        return maxi;
    }
};
......................._______ O(n)__________
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_set<char>st;
        int maxi = 0;
        while(r<n){
            if(st.count(s[r]) == 0){
                maxi = max(maxi,r-l+1);
                st.insert(s[r]);
                r++;
            }
            else if(st.count(s[r]) > 0){
                st.clear();
                l++;
                r = l;
            }
        }
        return maxi;
    }
};

928 · Longest Substring with At Most K Distinct Characters
class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        unordered_map<char,int>mp;
        int n = s.size(), l = 0, r = 0;
        int maxi = 0;
        while(r<n){
            mp[s[r]]++;
            if(mp.size() < k){
                maxi = max(maxi,r-l+1);
                r++;
            }
            else if(mp.size() == k){
                maxi = max(maxi,r-l+1);
                r++;
            }
            else if(mp.size() > k){
                while(mp.size() > k){
                    mp[s[l]]--;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
                r++;
            }
        }
        return maxi;
    }
};