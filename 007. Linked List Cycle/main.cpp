#include <iostream>
#include "solution.h"

// Unit Test
//
//    |1|-|--> |2|-|--> |3|||
//    /|\                  |
//     |                  \|/
//    |||6| <--|-|5| <--|-|4|

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node1;
    
    Solution s;
    std::cout << s.hasCycle(&node1) << std::endl;
    
	return 0;
}
