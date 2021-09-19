#include <iostream>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
  public:
    ListNode* res = new ListNode;
    ListNode* resHead = res;
    int l = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!l1 && !l2 && l)
      {
        ListNode* temp = new ListNode(l);
        res->next = temp;
        res = res->next;
        return resHead->next;
      }
      else if(!l1 && !l2 && !l)
      {
        return resHead->next;
      }
      else if(l1 && !l2)
      {
        //res->val = l1->val + l;
        int tSum = l1->val + l;
        ListNode* temp = new ListNode(tSum%10);
        l = tSum/10;
        res->next = temp;
        res = res->next;
        return addTwoNumbers(l1->next, l2);
      }
      else if(!l1 && l2)
      {
        // res->val = l2->val + l;
        int tSum = l2->val + l;
        ListNode* temp = new ListNode(tSum%10);
        l = tSum/10;
        res->next = temp;
        res = res->next;
        return addTwoNumbers(l1, l2->next);
      }
      else
      {
        cout<<l1->val<<"  "<<l2->val<< endl<< endl;
        int tSum = l1->val + l2->val + l;
        l = tSum/10;
        // res->val = tSum%10;
        ListNode* temp = new ListNode(tSum%10);
        res->next = temp;
        res = res->next;
        return addTwoNumbers(l1->next, l2->next);
      }
    }
};



int main()
{
  Solution sol = Solution();

  int tempInt1, tempInt2;
  cin>>tempInt1;
  ListNode* t1 = new ListNode(tempInt1);
  for (int i = 0; i<5; ++i)
  {
    cin>>tempInt1;
    ListNode* tempListNode1 = new ListNode(tempInt1, t1);
    t1 = tempListNode1;
  }

  cout<<"OK"<<endl;

  cin>>tempInt2;
  ListNode* t2 = new ListNode(tempInt2);
  for (int i = 0; i<4; ++i)
  {
    cin>>tempInt2;
    ListNode* tempListNode2 = new ListNode(tempInt2, t2);
    t2 = tempListNode2;
  }
  ListNode* t3 = sol.addTwoNumbers(t1, t2);

  while(t3)
  {
    cout << t3->val << endl;
    t3 = t3->next;
  }
}
//567834+65412=633246
