https : // leetcode.com/problems/minimum-window-substring/
        // similar to find anagram in a string of another string

        // example:
        // Input: s = "ADOBECODEBANC", t = "ABC"
        // Output: "BANC"
        // Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

        class Solution
{
public:
    string minWindow(string s, string t)
    {
        string res = "";
        int i = 0, j = 0, maxLen = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]++;
        }
        int cnt = mp.size();
        while (j < s.size())
        {
            if (mp.count(s[j]) == 1)
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    cnt--;
            }
            while (cnt == 0)
            {
                if (j - i + 1 < maxLen)
                {
                    maxLen = j - i + 1;
                    res = s.substr(i, maxLen);
                }
                if (mp.count(s[i]) == 1)
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        cnt++;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};