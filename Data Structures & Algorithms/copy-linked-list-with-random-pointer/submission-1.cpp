/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldtoneww;
        oldtoneww[NULL] =NULL;

        Node* cur=head;
        while(cur != NULL) {
            Node* neww =  new Node(cur->val);
            oldtoneww[cur]=neww;
            cur=cur->next;
        }
        cur=head;
        while(cur != NULL) {
            Node* neww=oldtoneww[cur];
            neww->next=oldtoneww[cur->next];
            neww->random=oldtoneww[cur->random];
            cur=cur->next;
        }
        return oldtoneww[head];
    }
};
