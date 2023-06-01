#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = createNode(0);
    struct ListNode* curr = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = createNode(sum % 10);
        curr = curr->next;
    }

    if (carry > 0) {
        curr->next = createNode(carry);
    }

    return dummyHead->next;
}
void printList(struct ListNode* head) {
    struct ListNode* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    // Example usage
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* sum = addTwoNumbers(l1, l2);
    printList(sum);

    return 0;
}
