#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1=0;
        int length2=0;
        
        ListNode *temp = headA;
        ListNode *hA,*hB;
        while(temp!=NULL)
        {
            length1++;
            temp=temp->next;
        }
        temp = headB;
        while(temp!=NULL)
        {
            length2++;
            temp=temp->next;
        }
        hA = headA;
        hB = headB;

        if(length1<length2)
        {
            int i=0;
            while(i<abs(length1-length2) && hB!=NULL)
            {
                hB=hB->next;
                i++;
            }
        }
        if(length1>length2)
        {
            int i=0;
            while(i<abs(length1-length2) && hA!=NULL)
            {
                hA=hA->next;
                i++;
            }
        }
        
        while(hA!=NULL && hB!=NULL)
        {
            if(hA==hB)
            return hA;

            hA=hA->next;
            hB=hB->next;
        }
        return NULL;
    }
};