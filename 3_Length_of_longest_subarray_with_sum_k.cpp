https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// same as total subarray with sum equal to k

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int>mp;
        int i=-1,j=0;
        int sum=0,ans=0;
        mp[0]=-1;
        while(j<N){
            sum+=A[j];
            if(mp.find(sum-K)!=mp.end()){
                ans=max(ans,j-mp[sum-K]);
            }
            if(mp.find(sum)==mp.end())
            mp[sum]=j;
            j++;
        }
        return ans;
    } 

};


