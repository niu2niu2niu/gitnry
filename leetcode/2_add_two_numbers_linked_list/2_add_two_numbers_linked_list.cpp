#include <iostream>
#include <linked_list.h>

using namespace std;

// good readability
class Solution1
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            // you should have a head
            ListNode* head = (ListNode *)malloc(sizeof(ListNode));
            head->next = NULL;
            ListNode* curr = head;
            int carry = 0;
            while (l1 || l2)
            {
                // l1 and l2 have head node which should not be calculate
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
                // simple writing
                //l1 = l1 ? l1->next : l1;
                //l2 = l2 ? l2->next : l2;
                int x = l1 ? (l1->val) : 0;
                int y = l2 ? (l2->val) : 0;
                int sum = x + y + carry;
                carry = sum / 10;
                curr->next = new ListNode (sum % 10);
                curr = curr->next;
            }
            // sum of last elements should be calculate
            if (carry)
                curr->next = new ListNode (carry);
            return head;
        }
};

// more simple
// because "carry" is 0 or 1, it can be write into "while"
class Solution2
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            // you should have a head
            ListNode head(0), *curr = &head;
            int carry = 0;
            while (l1 || l2 || carry)
            {
                int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
                carry = sum / 10;
                curr->next = new ListNode (sum % 10);
                curr = curr->next;
                l1 = l1 ? l1->next : l1;
                l2 = l2 ? l2->next : l2;
            }
            return head.next;
        }
};

// most simple
// make sum and next together
class Solution3
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            // you should have a head
            ListNode head(0), *curr = &head;
            int carry = 0;
            while (l1 || l2 || carry)
            {
                if (l1) carry += l1->val, l1 = l1->next;
                if (l2) carry += l2->val, l2 = l2->next;
                curr->next = new ListNode (carry % 10);
                carry /= 10;
                curr = curr->next;
            }
            return head.next;
        }
};

int main(int argc, char** argv)
{
    int arr1[] = {2, 4, 3, 5};
    int arr2[] = {5, 6, 4, 6};
    int len;

    len = sizeof(arr1)/sizeof(int);
    ListNode* l1 = createEnd(arr1, len);
    len = sizeof(arr2)/sizeof(int);
    ListNode* l2 = createHead(arr2, len);

    print_linked_list(l1);
    print_linked_list(l2);

    Solution1 s1;
    ListNode* result1 = NULL;
    result1 = s1.addTwoNumbers(l1, l2);
    print_linked_list(result1);

    Solution2 s2;
    ListNode* result2 = NULL;
    result2 = s2.addTwoNumbers(l1, l2);
    print_linked_list(result2);

    Solution3 s3;
    ListNode* result3 = NULL;
    result3 = s3.addTwoNumbers(l1, l2);
    print_linked_list(result3);

    return 0;
}
