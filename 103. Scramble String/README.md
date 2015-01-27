两个字符串 s1, s2, 问是否是 scramble. --> 定义问题的解为：`S(s1, s2)`, s1,s2 的长度为 n (若不等，直接 `return false;`).

然后看给出的例子：

	     gr|eat               rg|tae          ----- i == 2 (1)
	     /    \               /    \
	   g|r   e|at           r|g   ta|e        ----- i == 1 (2)
	   / \   / \            / \    / \
	  g   r e   a|t        r   g t|a  e       ----- i == 1 (3)
	            / \              / \
	           a   t            t   a

可以来看看，这里面究竟有几种情况。按照上图所示的步骤进行分析：

1. `S(s1, s2) = S(s1.substr(0,i), s2.substr(0,i)) && S(s1.substr(i), s2.substr(i))` (第一种可能)
2. 重点看 `e|at` 与 `ta|e`, 可以推得: `S(s1, s2) = S(s1.substr(0,i), s2.substr(n-i)) && S(s1.substr(i), s2.substr(0, n-i))` (第二种可能)
3. 可以并入 2. 但可以看出 S 最简单的解: `S("a", "a") == true` 以及 `S("t", "t") == true`. 即 `if (s1 == s2) return true;`

综上三步，可以得到递归的公式：

                 _________ true; 
     S(s1, s2) _|s1 == s2
                |      __ S(s1.substr(0,i), s2.substr(0,i)) && S(s1.substr(i), s2.substr(i))
                |_ or |
                      |__ S(s1.substr(0,i), s2.substr(n-i)) && S(s1.substr(i), s2.substr(n-i))


显然 i 的范围是 [1 ,n-1]. 

-----

有了这个公式做支撑，我们基本看到了递归的雏形。也可以试着用这个来写出代码。

```cpp
if (s1.empty() || s2.empty() || s1.size() != s2.size()) return false;
else if (s1 == s2) return true;
for (size_t i=1; i<s1.size(); ++i)
     if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
     else if (isScramble(s1.substr(0,i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size()-i))) return true;
return false;
```

六行代码基本已经从逻辑上解出了这道题。但如果去 LeetCode 上提交，会发现 TimeOut. 因为这样其实与枚举无异。如果遇到连字符都不尽相同的两个字符串，实在是浪费时间。

于是我们考虑排除两种情况：

1. s1 与 s2 中字符组成有差异，如 s1 中有 'g', s2 中却无。直接 `return false;`
2. s1 与 s2 中字符出现的个数有差异，如 s1 中 'g' 出现两次，而 s2 中却只有一次。直接 `return false;`.

根据这俩个条件，我们在第三行补充代码：

```cpp
for(auto c : s1)
     if (s2.find_first_of(c) == string::npos) return false;
     else if (std::count(s1.cbegin(), s1.cend(), c) != std::count(s2.cbegin(), s2.cend(), c)) return false;
```

然后提交，AC, 16ms. 问题顺利解决。
