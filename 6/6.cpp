#include <iostream>
#include <string>
using namespace std;
//abcdefghijklmnoprstuvwxyz
/*

a1            m2           z3
b4          l5 n6         y7
c8        k9   o10      x11
d12     j13    p14    w15
e16  i17       r18  v19
f20 h21        s22 u23
g24            t25

i1+numRows*2-2 = i2
ind1+ind2 = 2*numRows (if from 1)
ind1+ind2 = 2*numRows-2 (if from 0)



a1 --- 1
b2 --- 4
c3 --- 8
d4 --- 12
e5 --- 16
f6 --- 20
g7 --- 24
h8 --- 21
i9 --- 17
j10 -- 13
k11 -- 9
l12 -- 5
m13 -- 2
n14 -- 6
o15 -- 10
p16 -- 14
r17 -- 18
s18 -- 22
t19 -- 25
u20 -- 23
v21 -- 19
w22 -- 15
x23 -- 11
y24 -- 7
z25 -- 3
*/


class Solution
{
  public:

    string lineCompute(string s, int beginIndex1, int beginIndex2, int n)
    {
      string res = "";
      while(beginIndex1<s.length())
      {
        res += s[beginIndex1];

        if(beginIndex2<s.length() && (beginIndex2-beginIndex1)%(2*(n-1)))
        {
          res += s[beginIndex2];
          beginIndex2 += n*2-2;
        }
        beginIndex1 += n*2-2;
        // else
        //   cout << beginIndex1<<"  "<<beginIndex2<<endl;
      }

      return res;
    }
    string convert(string s, int numRows)
    {
      string res = "";
      if(numRows==1)
        return s;
      for (int i=0; i < numRows; ++i)
      {
        int ind1 = i;
        int ind2 = 2*numRows-2-ind1;
        res += lineCompute(s, ind1, ind2, numRows);
      }
      return res;
    }
};




int main()
{
  string ss = "AigewiyguodhnkbsfjdasFhildh";
  Solution sol = Solution();
  cout<<sol.convert(ss, 5)<<endl;
  //PINALSIGYAHRPI
}
