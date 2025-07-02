/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    int length(ListNode * head){
        int count = 0;
        ListNode * temp;
        temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
     ListNode* adding( ListNode* l1,  ListNode* l2){
          ListNode* t1 = l1, *t2 = l2,*t3;
          int c = 0;
           t3 = t1;
          while(t2 != NULL){
              t1->val = t1->val + t2->val + c;
              if(t1->val  >= 10){
                  t1 -> val = t1->val - 10;
                  c = 1;
              }
              else{
                  c = 0;
              }
               t3 = t1;
              t1 = t1->next;
              t2 = t2->next;
          }
         while(t1 != NULL){
             t1->val = t1->val + c;
             t3 = t1;
             if(t1->val  >= 10){
                  t1 -> val = t1->val - 10;
                  c = 1;
              }
              else{
                  c = 0;
              }
              t1 = t1->next;
         }
         if(c == 1){
             ListNode* newnode = new ListNode(c);
                t3->next = newnode;
         }
         return l1;
     }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return (length(l1) >= length(l2)) ? adding(l1,l2) : adding(l2,l1);
    }
};