#include <vector>

#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"
using vecIter = std::vector<int>::iterator;

ListNode *createLinkedList(vecIter beg, vecIter end)
{
    ListNode *head = beg == end ? NULL : new ListNode(*beg++);
    for (ListNode *cur = head; beg != end; cur = cur->next)
        cur->next = new ListNode(*beg++);
    return head;
}

bool compareTwoLinkedList(ListNode *l1, ListNode *l2)
{
    for ( ; l1&&l2; l1 = l1->next, l2 = l2->next)
        if (l1->val != l2->val) break;
    
    return l1 || l2 ? false : true;
}

void clear(ListNode *head)
{
    while (head)
    {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

TEST_CASE("merge two sorted linkedlist", "[mergeTwoLists]")
{
    SECTION( "common" )
    {
        std::vector<int> vec1 = {1,3,5,7,9};
        std::vector<int> vec2 = {0,2,4,6,8};
        std::vector<int> vec3 = {0,1,2,3,4,5,6,7,8,9};
        
        ListNode *l1 = createLinkedList(vec1.begin(), vec1.end());
        ListNode *l2 = createLinkedList(vec2.begin(), vec2.end());
        ListNode *l3 = createLinkedList(vec3.begin(), vec3.end());
        
        Solution s;
        ListNode *lm = s.mergeTwoLists(l1,l2);
        REQUIRE( compareTwoLinkedList(l3, lm) == true );
        
        clear(l1);
        clear(l2);
        clear(l3);
        clear(lm);
    }
    
    SECTION( "one linkedlist is empty" )
    {
        std::vector<int> vec1 = {1,3,5,7,9};
        
        ListNode *l1 = createLinkedList(vec1.begin(), vec1.end());
        ListNode *l2 = NULL;
        
        Solution s;
        ListNode *lm = s.mergeTwoLists(l1,l2);
        REQUIRE( compareTwoLinkedList(l1, lm) == true );
        
        clear(l1);
        clear(lm);
    }
    
    SECTION( "small and large" )
    {
        std::vector<int> vec1 = {0,3,5};
        std::vector<int> vec2 = {1,2,4,6,7,8,9,10,11,12};
        std::vector<int> vec3 = {0,1,2,3,4,5,6,7,8,9,10,11,12};
        
        ListNode *l1 = createLinkedList(vec1.begin(), vec1.end());
        ListNode *l2 = createLinkedList(vec2.begin(), vec2.end());
        ListNode *l3 = createLinkedList(vec3.begin(), vec3.end());
        
        Solution s;
        ListNode *lm = s.mergeTwoLists(l1,l2);
        REQUIRE( compareTwoLinkedList(l3, lm) == true );
        
        clear(l1);
        clear(l2);
        clear(l3);
        clear(lm);
    }
}




