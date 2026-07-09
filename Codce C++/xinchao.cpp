#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
class Solution{
public:
   ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
     ListNode* temp = new ListNode(0);
     ListNode* cur = head;
     while(list1 != nullptr && list2 != nullptr){
        if(list1 -> val <= list2->val){
            cur->next = list1;
            list1 = list1 -> next;
        }
        else{
            cur->next = list2;
            list2= list2->next;
        }
        cur = cur->next;
     }
     if(list1 != nullptr)cur -> next = list1;
     if(list2 != nullptr)cur -> next = list2;
     return head -> next;
   }
}