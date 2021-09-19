#include <iostream>
#include <vector>



using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> merged12;
      double res;
      int i1 = 0, i2 = 0;
      while (i1 < nums1.size() && i2 < nums2.size())
      {
        if (nums1[i1]<nums2[i2])
        {
          merged12.push_back(nums1[i1]);
          ++i1;
        }
        else
        {
          merged12.push_back(nums2[i2]);
          ++i2;
        }
      }
      while (i1 < nums1.size())
      {
        merged12.push_back(nums1[i1]);
        ++i1;
      }
      while (i2 < nums2.size())
      {
        merged12.push_back(nums2[i2]);
        ++i2;
      }
      int t = merged12.size();
      if (t%2 == 0)
      {
        res = (merged12[t/2-1] + merged12[t/2])/(double) 2;
      }
      else
      {
        res = merged12[t/2];
      }
      return res;
    }
};









int main()
{
  vector<int> n1 = {1, 6, 44, 123};
  vector<int> n2 = {3, 4, 56, 78, 79};
  Solution s = Solution();
  cout << s.findMedianSortedArrays(n1, n2) << endl;
}
