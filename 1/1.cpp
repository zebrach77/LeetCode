#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    vector<int> invNums(nums.size());
    vector<int> res(2);
    for(int i = 0; i < nums.size(); ++i)
    {
      for(int j = 0; j < i; ++j)
      {
        if (nums[i] == invNums[j])
        {
          res[0]=j;
          res[1] = i;
          return res;
        }
      }
      invNums[i] = target - nums[i];
    }
    return res;
  }
};



int main()
{
  vector<int> k(10);
  int tr;
  Solution t = Solution();
  for(int i = 0; i < 10; ++i)
  {
    cin >> k[i];
  }
  cout << "OK" << endl;
  cin>>tr;
  vector<int> r = t.twoSum(k, tr);
  cout << r[0] << "  " << r[1] << endl;
}
