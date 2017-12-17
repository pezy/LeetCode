# 思路(C++)

昨晚看C++ Primer 5th的[习题5.14](https://github.com/pezy/Cpp-Primer/blob/master/ch05/ex5_14.cpp)
想了很常规的解法，但脑子里一直都在想有没有更好的方案，因为这道题很像是在一篇文章里检索连续的高频词。应该是非常常见的才对。
但因为多了一个要求**连续**的条件，所以却又不太一样。

早上叹口气说，如果vector里放的是数字，就好办了，肯定有数学上的巧妙方法。比如可以通过**异或**来高效判断。

我脑子里不知道为啥就有**异或**这个概念(可能是本科时数字电路学的比较认真)。结果今天看见 @Mooophy 开始做LeetCode，想看看他做哪道题。
一看，咦~ 这不就是我之前想的那种情况吗？ 这也太巧了。于是我也有了第一道LeetCode的 AC。

不会用泛型模板。 简单题自己用常规思路想想吧。

-----

C++ Primer 5th ==> 4.8. The Bitwise Operators ==> Bitwise AND, OR, and XOR Operators

![qq 20141015093521](https://cloud.githubusercontent.com/assets/1147451/4639382/042223b6-540c-11e4-9fdc-8098179e6770.png)

异或(^)的特点是: **按位，同为0，异为1。**

所以这道题要找"落单"那哥们，就将他们全部异或，相同的小伙伴异或后为0了，可不就剩下那个老光棍了么。

## Python

心血来潮用 python 再刷一遍, 这道题有一种更简洁的写法是用 `reduce`. 为啥我只用了最简单的 `for` 循环呢?

请见 <https://stackoverflow.com/questions/181543/what-is-the-problem-with-reduce>
