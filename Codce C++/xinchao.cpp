#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution{
    public:
    int largestRectangleArea(vector<int>&heights){
        int dientich = 0;
        int n = heights.size();
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                dientich = max(dientich, height * width);
            }
            st.push(i);
        }
        return dientich;
    }
}