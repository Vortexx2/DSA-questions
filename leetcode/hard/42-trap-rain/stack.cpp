#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    stack<int> st;
    int area = 0;
    int ht = 0;
    int distance;

    for (int i = 0; i < height.size(); i++)
    {

      while (!st.empty() && height[i] > height[st.top()])
      {
        int top = st.top();
        st.pop();

        if (st.empty())
          break;

        ht = min(height[i], height[st.top()]) - height[top];
        distance = i - st.top() - 1;
        area += ht * distance;
      }

      st.push(i);
    }

    return area;
  }
};


int main() {
  Solution sol = Solution();
  // vector<
  // cout << sol.trap()
}