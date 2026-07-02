#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution{
public:
    int evalRPN(vector<string>&tokens){
        stack<int>st;
        int ketqua = 0;
        for(int i = 0;i<tokens.size();i++){
            if(isdigit(stoi(tokens[i]))){
                st.push(stoi(tokens[i]));
            }
            else if (!isdigit(stoi(tokens[i]))){
                int a = st.top(),b=st.top();
                int res;
                if(tokens[i] == "+"){
                     res = b + a;//+
                }
                else if(tokens[i] == "-"){
                     res = b - a;//-
                }
                else if(tokens[i] == "*"){
                    res = b * a;
                }
                else if(tokens[i] == "/"){
                     res = b / a;
                }
                st.push(res);
            }
        }
        ketqua = st.top();
        return ketqua;
    }
};