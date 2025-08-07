#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    struct ListNode* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    struct ListNode* mergedList = mergeTwoLists(l1, l2);

    printList(mergedList);

    struct ListNode* temp;
    while (mergedList != NULL) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
