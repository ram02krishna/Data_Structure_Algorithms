#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node() : val(0), next(NULL) {}
    node(int value) : val(value), next(NULL) {}
    node(int value, node *next) : val(value), next(next) {}
};

class Solution
{
public:
    node *deleteKthNode(node *head, int k)
    {
        if (head == NULL)
            return NULL;

        if (k == 1)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        node *temp = head;
        node *prev = NULL;
        int cnt = 1;

        while (temp != NULL && cnt < k)
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }

        if (temp != NULL && prev != NULL)
        {
            prev->next = temp->next;
            delete temp;
        }

        return head;
    }

    node *insertHead(node *head, int val)
    {
        return new node(val, head);
    }

    node *insertTail(node *head, int val)
    {
        if (head == NULL)
        {
            return new node(val);
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node *newNode = new node(val);
            temp->next = newNode;
            return head;
        }
    }

    node *insertAtPos(node *head, int el, int k)
    {
        if (head == NULL)
        {
            if (k == 1)
            {
                return new node(el);
            }
            else
            {
                return head;
            }
        }
        if (k == 1)
        {
            return new node(el, head);
        }
        int cnt = 0;
        node *temp = head;
        while (temp != NULL)
        {
            cnt++;
            if (cnt == k - 1)
            {
                node *x = new node(el, temp->next);
                temp->next = x;
                break;
            }
            temp = temp->next;
        }
        return head;
    }

    node *insertBeforeVal(node *head, int el, int value)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->val == value)
        {
            return new node(el, head);
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->val == value)
            {
                node *x = new node(el, temp->next);
                temp->next = x;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

node *convertArr2LL(const vector<int> &arr)
{
    if (arr.empty())
        return NULL;

    node *head = new node(arr[0]);
    node *current = head;

    for (size_t i = 1; i < arr.size(); i++)
    {
        current->next = new node(arr[i]);
        current = current->next;
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

int main()
{
    // vector<int> arr = {4, 6, 3, 8, 12, 15};
    vector<int> arr = {1,2,3};
    node *head = convertArr2LL(arr);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteKthNode(head, 1);
    // head = sol.insertHead(head, 24);
    // head = sol.insertTail(head, 71);
    // head = sol.insertAtPos(head, 42, 7);
    // head = sol.insertBeforeVal(head, 100, 8);
    cout << "Modified List: ";
    printList(head);

    return 0;
}
