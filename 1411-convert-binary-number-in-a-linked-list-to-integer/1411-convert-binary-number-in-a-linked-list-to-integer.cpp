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
public:
    int getDecimalValue(ListNode* head) {
        auto temp = head;
        string s = "";
        while(temp != NULL){
            s += to_string(temp->val);
            temp = temp->next;
        }    
        long long ans = 0;
        int cnt = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '1'){
                ans += pow(2,cnt);
            }
            cnt++;
        }
        return ans;
    }
};