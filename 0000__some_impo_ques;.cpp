https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!
//  https://leetcode.com/problems/replace-the-substring-for-balanced-string/discuss/409090/C%2B%2B-Sliding-Window

//  https://leetcode.com/contest/weekly-contest-315/problems/count-subarrays-with-fixed-bounds/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int i=0,j=0,jmin=-1,jmax=-1,jbad=-1;
        long long ans=0;
        for(;j<nums.size();j++){
            if(nums[j]< minK || nums[j]>maxK)jbad=j;
            if(nums[j]==minK)jmin=j;
            if(nums[j]==maxK)jmax=j;
         
           ans+= max(0, min(jmin,jmax)-jbad);
        }
        return ans;
    }
};

