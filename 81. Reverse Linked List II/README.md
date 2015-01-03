此题属于基本题，可以见 [LinkedList Problems](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf).

但其难在限定范围，从 m ~ n 的范围内，进行逆序。这样操作就要反复一些。还是，分析其给的例子：

    1->2->3->4->5->NULL (m = 2, n = 4)
       ^

其实逆序的过程，即以 2 为支点，陆续将 3、4 插入到 1 的后面。故这涉及三个指针:

    1--->2--->3--->4--->5--->NULL (m = 2, n = 4)
    ^    ^    ^
    pre first p

插入的过程如下：

```cpp
first->next = p->next;
p->next = pre->next;
pre->next = p;
```

非常好理解，可以用笔比划一下。所以这道题的核心即为以上思路。

而额外需要处理的，就是如何找到 这三个关键的指针，以及如何迭代 p 的指向了。
