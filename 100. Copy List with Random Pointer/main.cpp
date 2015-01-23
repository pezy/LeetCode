#include "solution.h"
#include <iostream>

using namespace std;

void print_randomlist(RandomListNode *head)
{
    while (head) {
        cout << head->label << " ";
        if (head->random) cout << head->random->label << " ";
        else cout << "NULL" << " ";
        head = head->next;
    }
    cout << endl;
}

void clear(RandomListNode *head)
{
    while (head) {
        RandomListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{
    Solution s;
    RandomListNode head(0);
    RandomListNode node(1);
    RandomListNode last(2);

    head.next = &node;
    node.next = &last;

    head.random = &last;
    node.random = &head;
    last.random = &last;

    print_randomlist(&head);
    RandomListNode *new_head = s.copyRandomList(&head);
    print_randomlist(new_head);
    clear(new_head);

    return 0;
}

