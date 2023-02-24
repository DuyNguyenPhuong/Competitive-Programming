#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    // chracter to digit mapping, and the inverse
    // (if you want better performance: use array instead of unordered_map)
    unordered_map<char, int> c2i;
    unordered_map<int, char> i2c;
    // limit: length of result
    int limit = 0;

    // digit: index of digit in a word, widx: index of a word in word list, sum: summation of all word[digit]

    bool backTrack(vector<string> &words, string &result, int digit, int widx, int sum)
    {
        if (digit == limit)
        {
            return sum == 0;
        }

        // if summation at digit position complete, validate it with result[digit]
        if (widx == words.size())
        {
            // if result[digit] and sum%10 haven't assign to any value
            if (c2i.count(result[digit]) == 0 && i2c.count(sum % 10) == 0)
            {
                // if there is a leading 0
                if (sum % 10 == 0 && digit == limit - 1)
                {
                    return false;
                }
                c2i[result[digit]] = sum % 10;
                i2c[sum % 10] = result[digit];
                bool tmp = backTrack(words, result, digit + 1, 0, sum / 10);

                c2i.erase(result[digit]);
                i2c.erase(sum % 10);
                return tmp;
            }
            else if (c2i.count(result[digit]) == 1 && c2i[result[digit]] == sum % 10)
            {
                if (digit == limit - 1 && c2i[result[digit]] == 0)
                {
                    return false;
                }
                return backTrack(words, result, digit + 1, 0, sum / 10);
            }
            else
            {
                return false;
            }
        }

        // if word[widx] length less than digit, ignore and go to next word
        if (digit >= words[widx].length())
        {
            return backTrack(words, result, digit, widx + 1, sum);
        }
        // if word[widx][digit] already mapped to a value
        if (c2i.count(words[widx][digit]))
        {
            // If the first character is 0
            if (digit + 1 == words[widx].length() && words[widx].length() > 1 && c2i[words[widx][digit]] == 0)
            {
                return false;
            }

            return backTrack(words, result, digit, widx + 1, sum + c2i[words[widx][digit]]);
        }

        // if word[widx][digit] not mapped to a value yet

        for (int i = 0; i < 10; i++)
        {
            if (digit + 1 == words[widx].length() && i == 0 && words[widx].length() > 1)
            {
                continue;
            }
            if (i2c.count(i))
            {
                continue;
            }
            c2i[words[widx][digit]] = i;
            i2c[i] = words[widx][digit];

            bool tmp = backTrack(words, result, digit, widx + 1, sum + i);

            c2i.erase(words[widx][digit]);
            i2c.erase(i);

            if (tmp)
            {
                return true;
            }
        }
        return false;
    }

    bool isSolvable(vector<string> &words, string result)
    {
        limit = result.length();

        for (auto &w : words)
        {
            if (w.length() > limit)
            {
                return false;
            }
        }

        for (auto &w : words)
        {
            reverse(w.begin(), w.end());
        }
        reverse(result.begin(), result.end());

        return backTrack(words, result, 0, 0, 0);
    }
};