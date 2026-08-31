/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *node=head;

        if(!node) return node;
        vector<Node*> temp;
        while(node || !temp.empty()){
            if(node->child){
                if(node->next){
                    temp.push_back(node->next);
                }
                    node->next=node->child;
                    node->next->prev=node;
                    node->child=nullptr;
            }
            if(!node->next && !temp.empty()){
                node->next=temp.back();
                temp.back()->prev=node;
                temp.pop_back();
            }
            node=node->next;
        }
        return head;
    }
};