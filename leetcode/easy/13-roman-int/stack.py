"""
  @author Vortexx2

  Runtime - 164 ms
  Memory Usage - 15 MB
"""
class Solution:
  def removeDuplicates(self, s: str) -> str:
    st = []
    res = ""
    for ch in s:
      if len(st) and (st[-1] == ch):
        st.pop()

      else:
        st.append(ch)

      
    while len(st):
      res = st.pop() + res

    return res
