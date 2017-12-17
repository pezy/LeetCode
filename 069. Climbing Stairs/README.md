这道题很经典，涉及到斐波那契数列的起源。故事来自于本专业最大的砖头《计算机程序设计艺术》，高老大所著。
说是1150年一个印度老僧 *Gopala* 和 *金月* 在研究箱子包装物件长阔刚好为 1 和 2 的可行方法数目时，首先描述了这个数列。

再看看这道题，把箱子包装物换成了梯子，貌似更接近生活了哈，谁没事去量什么箱子包装物呢？

看看斐波那契数列：

- F0 = 0
- F1 = 1
- Fn = Fn−1 + Fn−2 (n≧2)

这是一个经典的递归，也是我大学写的第一个递归。任何算法书介绍递归，都少不了这个吧，还有一个就是那个*汉诺塔问题*了。

-----

这道题的解法呼之欲出了吧：n <= 0 时，res = 0; n == 1 时，res = 1; 然后，res = climbStairs(n-1) + climbStairs(n-2);
```cpp
if (n <= 0) return 0;
if (n == 1) return n;
return climbStairs(n-1) + climbStairs(n-2);
```

~~但递归的效率真是没办法，LeetCode向来是判的比较宽松的，可是如果这道题你用递归，会悲剧，会提示你死在 n = 25上。~~
感谢 @Mooophy 指出这里的错误，效率低**并非因为递归**。而是因为上述写法，有一个致命缺点：

如，当你计算 climbStairs(5) 的时候，需要计算 climbStairs(4), climbStairs(3), climbStairs(2), climbStairs(1), climbStairs(0).
但想一想， 其实计算 climbStairs(4) 的时候，我们已经计算过上述 90% 的结果了。我们每一次都要重复计算 n-1 次已有结果， 
使得 LeetCode 的 CPU 和内存不堪重负。。。如何避免？ 只要保存上述中间计算结果不就行了？(动态规划的思想)

于是有了下列版本：

```cpp
if (n < 0) return 0;
std::vector<int> vec = {0,1,2,3};
if (n > 3) vec.resize(n+1, -1);
std::function<int(int)> fib = [&](int n)
{
    if (vec[n] == -1)
        vec[n] = fib(n-1) + fib(n-2);
    return vec[n];
};
return fib(n);
```

提交， AC。 

-----

但，这样一来，我们以空间换了时间。最终还是有损失的，所以回到一个最朴素的思路上去，还是老老实实用循环吧。算法如下
```cpp
res = stepOne + stepSecond;
stepOne = stepSecond;
stepSecond = res;
```

不多说了，Easy 难度， 基本题。
