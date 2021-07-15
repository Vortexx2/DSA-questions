"""
  @author Vortexx2

  Runtime - 160 ms
  Memory Usage - 15 MB
"""
class Solution:
  def removeDuplicates(self, s: str) -> str:

    res = ""
    ptr = - 1

    i = 0
    while i < len(s):

      if (ptr == -1 or res[ptr] != s[i]):
        ptr += 1
        res += s[i]
        i += 1

      else:

        while (i < len(s) and ptr != -1 and res[ptr] == s[i]):
          i += 1
          ptr -= 1
          res = res[: -1]

    return res


if __name__ == '__main__':
  sol = Solution()
  print(sol.removeDuplicates("abbaca"))