#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fo(vector<int>&nums, int target) {
        int n=nums.size();
        int l=0, r=n-1;
        int ans=-1;
        while(l<=r) {
            int m=(l+r)/2;
            if(nums[m]==target) {
                ans=m;
                r=m-1;
            } else if(nums[m]<target) l=m+1;
            else r=m-1;
        }
        return ans;
    }

    int lo(vector<int>& nums, int target){
        int n=nums.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target) {
                ans=m;
                l=m+1;
            } else if(nums[m]<target) l=m+1;
            else r=m-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {fo(nums,target),lo(nums,target)};
    }
};