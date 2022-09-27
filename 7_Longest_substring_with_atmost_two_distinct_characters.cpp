class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        if (s.length() == 0)
            return 0;

        unordered_map<char, int> table;
        int begin = 0, end = 0, len = 0, counter = 0;

        while (end < s.length())
        {
            char current = s[end];

            table[current]++;
            if (table[current] == 1)
                counter++;

            end++;

            while (counter > 2)
            {
                char startchar = s[begin];

                if (table.count(startchar) == 1)
                {
                    table[startchar]--;
                    if (table[startchar] == 0)
                        counter--;
                }

                begin++;
            }

            len = max(len, end - begin);
        }

        return len;
    }
};