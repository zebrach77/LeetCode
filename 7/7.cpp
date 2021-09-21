#include <iostream>
using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {

      long int res = 0;
      while (x!=0)
      {
        res = (res+x%10)*10;
        x /= 10;
      }
      res/=10;
      if (res < -INT_MAX || res > INT_MAX)
        return 0;
      return res;
    }

};


int main()
{
  Solution sol = Solution();
  cout << sol.reverse(-4654)<<endl;
}
