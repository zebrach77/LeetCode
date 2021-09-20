#include <iostream>
#include <string>
#include <stack>
using namespace std;





class Solution
{
  public:
    bool isPalindrome(string sp)
    {
      for (int j = 0; j < sp.length()/2; ++j)
      {
        if(sp[j] != sp[sp.length()-j-1])
          return false;
      }
      return true;
    }
    string longestPalindrome(string s)
    {
      stack<char> st={}, stemp;
      int ind, maxLength = 0;
      string res = "", temp;
      char m1, m2 = s[0];
      if(isPalindrome(s)) return s;
      st.push(s[0]);
      for(int i=1; i<s.length(); ++i)
      {

        if(s[i]==m2 || m1==m2)
        {
          ind = i;
          stemp = st;
          while(!stemp.empty() && stemp.top() == s[ind] && ind<s.length()){
            // cout<<"!!!!!!"<<endl;
            stemp.pop();
            ++ind;
          }
          temp = s.substr(2*i-ind, 2*(ind-i));
          // cout<<temp<<endl;
          if(temp.length() > maxLength)
          {
            maxLength = temp.length();
            res = temp;
          }

        }
        if(s[i]==m1 || m2!=m1)
        {
          ind = i;

          stemp = st;
          stemp.pop();

          while(!stemp.empty() && stemp.top() == s[ind]&&ind<s.length()){
            stemp.pop();
            ++ind;
          }
          temp = s.substr(2*i-ind-1,2*(ind-i)+1);
          if(temp.length() > maxLength)
          {
            maxLength = temp.length();
            res = temp;
          }

        }
        else if(m1==m2)
        {

        }
        m1 = m2;
        m2 = s[i];
        st.push(s[i]);
      }
      int i = s.length()-1;
      if (!i) return s.substr(0,1);
      if(res.empty()) return s.substr(0, 1);
      return res;
    }
};



int main()
{
  string ss = "ffffffggggg";
  // cout<<ss.substr(1, 0)<<endl;
  Solution sol = Solution();
  // cout<<sol.isPalindrome("aaabaaa")<<endl;
  cout<<sol.longestPalindrome(ss)<<endl;
}
//hsdvhibasdfdsbhvuoaijp
//        sdfds
