#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode* l2)
{
    if(NULL == l1) return l2;
    if(NULL == l2) return l1;
    
    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *ans = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode *p = ans, *last = NULL, *t = NULL;
    
    int sum = 0;
    
    while(1)
    {
        if(p1 && p2)
        {
            sum += p1->val + p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1 && (p2 == NULL))
        {
            sum += p1->val;
            p1 = p1->next;
        }
        else if((p1 == NULL) && p2)
        {
            sum += p2->val;
            p2 = p2->next;
        }
        else
        {
            break;
        }
        
        p->val = sum % 10;
        sum /= 10;
        
        p->next = t = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        last = p;
        p = p->next;
    }
    
    if(sum != 0)
    {
        t->val = sum;
    }
    else
    {
        free(t);
        last->next = NULL;
    }
    
    return ans;
}

int main(int argc, char *argv[])
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
    
    struct ListNode *p = addTwoNumbers(L1, L2);
    
    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    
    return 0;
}