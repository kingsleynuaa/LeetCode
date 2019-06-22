/**
 * Defition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* result = NULL, *pNode = NULL, *res = NULL;
        
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        while(l1 != NULL && l2 != NULL){
            res = new ListNode(0);
            res->val =  (l1->val + l2->val + flag)%10;
            flag = (l1->val + l2->val + flag)/10;
            if(result == NULL)
            {
                result = pNode = res;
            }
            else
            {
                pNode->next = res;
                pNode = pNode->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL)
        {
            res = new ListNode(0);
            res->val =  (l1->val + flag)%10;
            
            cout << res->val;
            flag = (l1->val + flag)/10;
            pNode->next = res;
            pNode = res;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            res = new ListNode(0);
            res->val =  (l2->val + flag)%10;
            cout << "11" << res->val;
            flag = (l2->val + flag)/10;
            pNode->next = res;
            pNode = res;
            l2 = l2->next;
        }
        
        if(flag > 0)
        {
            res = new ListNode(0);
            res->val = 1;
            res->next = NULL;
            pNode->next = res;
        }
       // else
         //   pNode->next = NULL;
        
        
        
                
      return result;  
        
    }
};
