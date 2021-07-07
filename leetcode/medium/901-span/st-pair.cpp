#include <iostream>
#include <stack>

using namespace std;

class StockSpanner
{
public:
  stack<pair<int, int>> st;
  int len;
  StockSpanner()
  {
    len = 0;
  }

  int next(int price)
  {
    len++;
    int P;

    while (!st.empty() && price >= st.top().second)
    {
      st.pop();
    }

    if (st.empty())
    {
      P = 0;
    }

    else
    {
      P = st.top().first;
    }
    st.push(make_pair(len, price));

    return (len - P);
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */