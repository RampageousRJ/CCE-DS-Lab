#include <bits/stdc++.h>
#include <iostream>
using namespace std;

    long reverse(long num){
        long rev=0;
        while(num>0){
            int dig = num%10;
            num/=10;
            rev = (rev*10)+dig;
        }
        return rev;
    }

    ListNode* addNode(ListNode *head,int val){
        ListNode *temp = new ListNode(val);
        if(!head){
            return temp;
        }
        ListNode *t = head;
        while(t->next){
            t=t->next;
        }
        t->next = temp;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t = l1;
        long num1=0;
        while(t){
            num1 = (num1*10)+(t->val);
            t=t->next;
        }
        t = l2;
        long num2=0;
        while(t){
            num2 = (num2*10)+(t->val);
            t=t->next;
        }
        num1 = reverse(num1);
        num2 = reverse(num2);
        long sum = num1+num2;
        ListNode *head = NULL;
        if(sum==0){
            head = addNode(head,0);
            return head;
        }
        while(sum>0){
            int dig = sum%10;
            sum/=10;
            head = addNode(head,dig);
        }
        return head;
    }
};