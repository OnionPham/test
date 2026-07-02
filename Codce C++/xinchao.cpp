#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution{
public:
    vector<int>dailyTemperatures(vector<int> &temperatures){
        int n = temperatures.size();
        vector<int>res(n,0);
        stack<int>st;
        for(int i = n - 2;i>=0;i--){
            int j = i + 1;
            while( j < n){
                if(temperatures[j] > temperatures[i]){
                    res[i] = j - i;
                    break;
                }
                if(res[j] == 0)break;
                j += res[j];
            }
        }
        return res;
    }
};