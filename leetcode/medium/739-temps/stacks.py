from typing import List


class Solution:
  def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
    res = [None] * (len(temperatures))
    st = []

    for i in range(len(temperatures) - 1, -1, -1):

      # for temp in reversed(temperatures):

      while (len(st) and temperatures[i] >= temperatures[st[-1]]):
        st.pop()

      if not len(st):
        res[i] = 0

      else:
        res[i] = st[-1] - i

      st.append(i)

    return res
