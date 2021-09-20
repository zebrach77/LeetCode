#include <iostream>
#include <string>
using namespace std;





class Solution
{
  public:
    bool isPalindrome(string sp)
    {
      for (int i = 0; i < sp.length()/2; ++i)
      {
        if(sp[i] != sp[sp.length()-i-1])
          return false;
      }
      return true;
    }
    string longestPalindrome(string s)
    {
      string maxRes;
      int maxLength = 0, ind1 = 0;
      string res = "", resTemp;
      for (int i = 0; i < s.length(); ++i)
      {
        res += s[i];
        if (isPalindrome(res))
        {
          if(res.length() > maxLength)
          {
            maxLength = res.length();
            maxRes = res;
          }
        }
        else
        {
          if(ind1)
          {
            resTemp = s[ind1-1]+res;
            if (isPalindrome(resTemp) && resTemp.length() > maxLength)
            {
              res = resTemp;
              --ind1;
              maxLength = res.length();
              maxRes = res;
            }
          }
          else
          {
            if(!isPalindrome(res))
            {
              for (int j = 1; j < res.length()-maxLength; ++j)
              {
                resTemp = res.substr(j, res.length()-1);
                if (isPalindrome(resTemp) && resTemp.length() > maxLength)
                {
                  res = resTemp;
                  ind1 = j;
                  maxLength = res.length();
                  maxRes = res;
                }
              }
            }
          }
        }
      }
      return maxRes;
    }
};






int main()
{
  string ss = "fsdfghgcfghjdabcdcbad";
  Solution sol = Solution();
  cout<<sol.longestPalindrome(ss)<<endl;
}
//hsdvhibasdfdsbhvuoaijp
//        sdfds
