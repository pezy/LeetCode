这道题很经典，涉及到斐波那契数列的起源。故事来自于本专业最大的砖头《计算机程序设计艺术》，高老大所著。
说是1150年一个印度老僧 *Gopala* 和 *金月* 在研究箱子包装物件长阔刚好为 1 和 2 的可行方法数目时，首先描述了这个数列。

再看看这道题，把箱子包装物换成了梯子，貌似更接近生活了哈，谁没事去量什么箱子包装物呢？

看看斐波那契数列：

- F0 = 0
- F1 = 1
- Fn = Fn−1 + Fn−2 (n≧2)

这是一个经典的递归，也是我大学写的第一个递归。任何算法书介绍递归，都少不了这个吧，还有一个就是那个*汉诺塔问题*了。

-----

这道题的解法呼之欲出了吧：n < 0 时，res = 0; n == 0 || n == 1 时，res = n; 然后，res = climbStairs(n-1) + climbStairs(n-2);
```cpp
if (n<0) return 0;
else if (n<2) return n;
else return climbStairs(n-1) + climbStairs(n-2);
```

但递归的效率真是没办法，LeetCode向来是判的比较宽松的，可是如果这道题你用递归，会悲剧，会提示你死在 n = 25上。
所以还是老老实实用循环吧。算法如下
```cpp
res = stepOne + stepSecond;
stepOne = stepSecond;
stepSecond = res;
```

不多说了，Easy 难度， 基本题。
