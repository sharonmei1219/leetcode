// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
 
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carryOver = 0;
//         ListNode * pl1 = l1, * pl2 = l2, * result = NULL, * preNode = NULL;
//         while(pl2 != NULL || pl1 != NULL){
//             ListNode * node = new ListNode(valOfNode(pl1) + valOfNode(pl2) + carryOver);
//             if(result == NULL) result = node;
            
//             if(preNode != NULL) preNode->next = node;
//             preNode = node;
            
//             if(valOfNode(node) >= 10){ 
//                 carryOver = 1;
//                 node->val = node->val%10;
//             }
//             else carryOver = 0;
            
//             pl2 = nextNode(pl2);
//             pl1 = nextNode(pl1);
//         }
        
//         if (carryOver == 1){
//             preNode->next = new ListNode(1);
//         }
        
//         return result;
        
//     }
    
//     int valOfNode(ListNode* n){
//         if (n == NULL) return 0;
//         return n->val;
//     }
    
//     ListNode* nextNode(ListNode* n){
//         if (n == NULL) return NULL;
//         return n->next;
//     }
// };