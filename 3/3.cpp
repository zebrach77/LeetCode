#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      string res = "";
      int maxLength = 0;
      for(int i = 0; i < s.length(); ++i)
      {
        char c = s[i];
        int indFound = -1;
        for(int j = 0; j < res.length(); ++j)
        {
          if (c==res[j])
          {
            indFound = j;
            break;
          }
        }
        if (indFound != -1)
        {
          res = res.substr(indFound+1, res.length());
        }
        res = res + c;
        if (res.length() > maxLength)
        {
          maxLength = res.length();
        }
      }
      return maxLength;
    }
};



int main()
{
  string ss = "";
  Solution sol = Solution();
  cout << sol.lengthOfLongestSubstring(ss) << endl;
}
//haciohlivhlsdiblkvsd
//haciohl
//    ohliv
//      livh
//       ivhlsd
//        vhlsdib
//           sdiblkv
