/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        int lvl = -1;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        Node* nxt;
        while(!q.empty()){
            auto pr = q.front();
            q.pop();
            if(!pr.first) continue;
            if(pr.second != lvl){
                lvl = pr.second;
                
                nxt = pr.first;
            }else{
                nxt->next = pr.first;
                nxt = pr.first;
            }
            if(pr.first->left){
                q.push({pr.first->left,pr.second+1});
            }
            if(pr.first->right){
                q.push({pr.first->right, pr.second+1});
            }
        }
        return root;
    }
};