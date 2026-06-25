#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution{
public:
    string mergeAlternately(string word1,string word2){
        int w1 = 0,w2=0;
        string res = "";
        while(1){
            res += word1[w1];
            w1++;
            res += word2[w2];
            w2++;
        }
        return res;
    }
};
int main(){
    string w1,w2;
    getline(cin,w1);getline(cin,w2);
    string res;
    Solution sol;
    res = sol.mergeAlternately(w1,w2);
    cout << res; 
}