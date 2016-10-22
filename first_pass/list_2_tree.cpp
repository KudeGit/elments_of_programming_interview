#include <iostream>

using  namespace std;

template <class T>
struct ListNode {
    T val;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <class T>
ListNode<T>* list_2_bst_helper (ListNode<T>** head, const int s, const int e)
{
    if (!head || !(*head)) {
        return nullptr;
    }
    if (s >= e) {
        return nullptr;
    }
    auto m = s + ((e - s) >> 1) ;
    auto tmp_left = list_2_bst_helper(head, s, m);
    auto root = *head;
    root->prev = tmp_left;
    *head = (*head)->next;
    root->next = list_2_bst_helper(head, m+1, e);
    return root;
}

template <class T>
ListNode<T>* list_2_bst (ListNode<T>* head)
{
    int n = 0;
    auto x = head;
    while (x) {
        ++n; x = x->next;
    }
    return list_2_bst_helper(&head, 0, n-1);
}


template <class T>
ListNode<T>* create_list (T n)
{
    ListNode<T>* head = new ListNode<T>();
    head->val = n--;
    while (n) {
        auto x = new ListNode<T>();
        x->val = n;
        x->next = head;
        head->prev = x;
        head = x;
        --n;
    }
    return head;
}


template <class T>
void printTreeHelper (const ListNode<T>* root)
{
    if (!root) {
        return;
    } else {
        printTree(root->prev);
        cout << root->val << ", ";
        printTree(root->next);
    }
}

template <class T>
void printTree (const ListNode<T>* root)
{
    cout << endl;
    printTreeHelper(root);
    cout << endl;
}

template <class T>
ostream& operator<< (ostream& out, ListNode<T>* head)
{
    while (head) {
        out << head->val << ", ";
        head = head->next;
    }
    return out;
}

int main (void)
{
    auto head = create_list<int>(10);
    auto root = list_2_bst(head);
    printTree(root);
    cout << head << endl;
    return 0;

}


