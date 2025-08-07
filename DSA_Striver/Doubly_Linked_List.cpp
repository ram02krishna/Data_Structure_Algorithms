#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node *back;

    node() : val(0), next(NULL), back(NULL) {}
    node(int value) : val(value), next(NULL), back(NULL) {}
};

node *convertArr2LL(const vector<int> &arr)
{
    if (arr.empty())
        return NULL;

    node *head = new node(arr[0]);
    node *current = head;

    for (size_t i = 1; i < arr.size(); i++)
    {
        node *newNode = new node(arr[i]);
        current->next = newNode;
        newNode->back = current;
        current = newNode;
    }

    return head;
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class solution
{
public:
    node *deleteHead(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        node *prev = head;
        head = head->next;

        head->back = nullptr;
        prev->next = nullptr;

        delete prev;
        return head;
    }

    node *deleteTail(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        node *newTail = tail->back;
        newTail->next = nullptr;
        tail->back = nullptr;
        delete tail;
        return head;
    }
    node *deleteKthElement(node *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        int cnt = 0;
        node *KthNode = head;
        while (KthNode != NULL)
        {
            cnt++;
            if (cnt == k)
                break;
            KthNode = KthNode->next;
        }
        node *prev = KthNode->back;
        node *front = KthNode->next;
        if (prev == NULL && front == NULL)
        {
            return NULL;
        }
        else if (prev == NULL)
        {
            return deleteHead(head);
        }
        else if (front == NULL)
        {
            return deleteTail(head);
        }
        prev->next = front;
        front->back = prev;

        KthNode->next = NULL;
        KthNode->back = NULL;

        return head;
    }
};

int main()
{
    vector<int> arr = {10, 20, 30, 35, 40, 55, 12};
    node *head = convertArr2LL(arr);
    printList(head);

    solution sol;
    // head = sol.deleteHead(head);
    // head = sol.deleteTail(head);
    head = sol.deleteKthElement(head, 3);

    printList(head);

    return 0;
}
