#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(std::string s) {
        stack<char> st;
        for(auto ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else if(ch == ')' || ch == '}' || ch == ']') {
                if(st.empty()) return false;
                char sch = st.top();

                if((sch == '(' && ch == ')') || (sch == '{' && ch == '}') || (sch == '[' && ch == ']'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }   
            }
            else
            {
                return false;
            }
            
        }

        return st.empty();
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s = "(([]){})";

    if(argc > 1) {
        s = argv[1];
    }

    cout << "str = \"" << (s) << "\"" << endl;
    cout << boolalpha << sol.isValid(s) << endl;

    return 0;
}