https : // leetcode.com/problems/count-number-of-nice-subarrays/
        // Input: nums = [1,1,2,1,1], k = 3
        // Output: 2
        // Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

        class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        deque<int> dq = {-1};
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2)
                dq.push_back(i);
            if (dq.size() > k + 1)
                dq.pop_front();
            if (dq.size() == k + 1)
            {
                res += (dq[1] - dq[0]);
            }
        }
        return res;
    }
};