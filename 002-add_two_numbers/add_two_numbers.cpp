#include <iostream>

struct ListNode
{
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int x = 0, y = 0, carry = 0, sum = 0;

        ListNode *h = NULL, **t = &h;

        while(l1 != NULL && l2 != NULL)
        {
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);

            sum = carry + x + y;

            ListNode *node = new ListNode(sum % 10);
            *t = node;
            t = (&node->next);

            carry = sum/10;
        }

        if(carry > 0)
        {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }

        return h;
    }

private:
    int getValueAndMoveNext(ListNode* &l)
    {
        int x = 0;
        if(l != NULL)
        {
            x = l->val;
            l = l->next;
        }

        return x;
    }
};

int main(void)
{
    // 新建链表1
    struct ListNode *L1 = (struct ListNode*)calloc(3, sizeof(struct ListNode));
    struct ListNode *p1 = L1;
    
    p1->val = 2;
    p1->next = p1 + 1;
    p1++;
    
    p1->val = 4;
    p1->next = p1 + 1;
    p1++;
    
    p1->val = 5;
    p1->next = NULL;
    
    // 新建链表2
    struct ListNode *L2 = (struct ListNode*)calloc(5, sizeof(struct ListNode));
    struct ListNode *p2 = L2;
    
    p2->val = 3;
    p2->next = p2 + 1;
    p2++;
    
    p2->val = 6;
    p2->next = p2 + 1;
    p2++;
    
    p2->val = 8;
    p2->next = p2 + 1;
    p2++;
    
    p2->val = 7;
    p2->next = p2 + 1;
    p2++;
    
    p2->val = 4;
    p2->next = NULL;


    Solution solution;
    solution.addTwoNumbers(L1, L2);

    return 0;
}