# 思路(C++)

这道题让我想起之前的 [Add Binary](../066.%20Add%20Binary). 思想几乎类似，难点在于**进位**。

其次，这种关系到两个链表的问题，dummy 节点应该是必不可少的了。

以上两点，便是这道题的核心。私以为，本题难度应为 Easy.

-----

具体说一下进位的事情。

STL 有一个专门的结构体叫做 `div_t`, 其包含两个成员，分别是 quot(quotient) 与 rem(remainder). 用来做什么，从命名上是否可以看出一点端倪呢？

举例说明.

     38 / 5 == 7 remainder 3

用 C++ 来描述，便是：

     div_t result = div(38, 5);
     cout << result.quot << result.rem;

前者为被除后的结果，后者为余数。

-----

与这道题的关系是？

本题的进位是基于十进制的，故两个节点相加之后的值，应判断是否超出了10，超出需要进位，留下的是余数。即，做了 div 操作后。sum.rem 是新链表的当前节点，sum.quot 是下一次加法运算的进位。

有：

```cpp
if (l1) { sum.quot += l1->val; l1 = l1->next; } // 进位 + l1
if (l2) { sum.quot += l2->val; l2 = l2->next; } // 进位 + l1 + l2
sum = div(sum.quot, 10); // 除 10 操作，得到新的 quot 与 rem.
tail->next = new ListNode(sum.rem); // rem 为节点值, quot 留作下次迭代
```

## Python

STL 里的 `div` 方法对应 Python 里的 [`divmod`](https://docs.python.org/3/library/functions.html#divmod). 其等同于 (a // b, a % b). 其余的思路一致，不过 Python 里似乎不方便取地址直接修改内存，只好用傀儡节点的方法替代。