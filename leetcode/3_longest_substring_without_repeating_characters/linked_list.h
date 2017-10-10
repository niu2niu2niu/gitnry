#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createHead(int arr[], int len)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;

    for (int i = len-1; i >= 0; i--) 
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->val = arr[i];

       // 插入第一个节点时,p->next指向head->next,此时为NULL,恰好作为尾节点;
        p->next = head->next; // 让新节点的next指向头节点之后
        head->next = p; // 让表头的next指向新节点
    }

    return head;
}

ListNode *createEnd(int arr[], int len)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    ListNode *end = head;

    for (int i = 0; i < len; i++)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->val = arr[i];
        end->next = p;
        end = p;
    }

    end->next = NULL; // 单链表建立完毕，将终端节点的指针域置空

    return head;
}

void print_linked_list(ListNode* head)
{
    if (head == NULL) return;

    ListNode *p = head->next;
    while (p->next)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << p->val << endl;
}

