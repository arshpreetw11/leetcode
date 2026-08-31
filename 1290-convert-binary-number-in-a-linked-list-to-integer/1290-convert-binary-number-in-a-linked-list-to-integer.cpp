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
    int decimal(string binary){
        int val=0,x=0;
        for(int i=binary.size()-1;i>=0;i--){
            val+=(binary[i]-'0')*pow(2,x);
            x++;   
        }
        return val;
    }
    int getDecimalValue(ListNode* head) {
        string binary="";
        ListNode* node=head;
        while(node){
            if(node->val==0)
                binary.push_back('0');
            else
                binary.push_back('1');
            node=node->next;
        }
        return decimal(binary);

    }
};