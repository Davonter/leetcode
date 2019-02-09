/*
 * compile options: -std=c++11
 */
#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <unistd.h>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        static int res = 0;

        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for(int i = 0; i < s.size(); i++)
        {
            int val = m[s[i]];
            if( i == s.size() - 1 || m[s[i+1]] <= m[s[i]])
            {
                res += val;
            }
            else 
            {
                res -= val;
            }
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s number", argv[0]);
        exit(0);
    }

    Solution sol;
    cout << sol.romanToInt(argv[1]) << endl;

    return 0;
}