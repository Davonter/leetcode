#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string word;
        if(0 == strs.size()) return "";
        if(1 == strs.size()) return strs[0];

        for(int i = 0; i <= strs[0].size(); i++)
        {
            string w = strs[0].substr(0, i);
            bool match = true;

            for(int j = 1; j < strs.size(); j++)
            {
                if(i > strs[j].size() || w != strs[j].substr(0, i))
                {
                    match = false;
                    break;
                }
            }

            if(!match) return word;
            word = w;
        }

        return word;
    }
};

int main(void)
{
    const char *str[] = {"find", "fight", "fill"};

    vector<string> v(str, str+3);

    Solution sol;

    cout << sol.longestCommonPrefix(v) << endl;

    return 0;
}