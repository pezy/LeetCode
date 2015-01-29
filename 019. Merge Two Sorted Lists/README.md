这是一道再基本不过的题了，甚至被收录在 [stanford 的 cs 课件](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf)里.

------

首先，最优美的应该是递归算法：
```cpp
if(l1 == NULL) return l2;
if(l2 == NULL) return l1;

if(l1->val < l2->val) 
{
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
} 
else 
{
    l2->next = mergeTwoLists(l2->next, l1);
    return l2;
}
```

写递归一定要用最自然而然的思路写，否则画虎不成反类犬。

------

如果不用递归，可能就会稍微丑陋点，不过也不算太麻烦，常规思路，去迭代比较即可。 我很快就写出了 [这个方案](https://github.com/pezy/LeetCode/commit/110b9882286517b71fd3c815f351b2edb8ec9471)

但我在写单元测试的时候，就发现一个致命问题： 我在 merge 的同时，也破坏了 l1 和 l2 的链表结构。所以那是一份优美但错误的代码。

为了不破坏原有结构， 不得不增加了一些时空复杂度。 唉，实在想不到什么别的办法了。

------

链表的基本题，还可以参考最开始提到的 stanford 的 cs 课件，讲的很全面。LinkedList 的结构其实是 C语言 里的东西。
C++ 里用 STL 的话，其实不需要考虑这么多。但用 C 实现一遍， 很可能不会迷惑于 STL 的 API 为什么要那样设计。
如当年我犯的迷糊： http://stackoverflow.com/questions/26312915/how-to-use-stdlistreverse-iterator-with-operator
