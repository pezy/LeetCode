    "LeetCode" ["Leet", "Code"]
     ^^^^

拿到 dict 和 word, 如何确定是否正好可以 break? 题目中给的例子，判断起来很简单，首先从 word 的第一个字母开始迭代，迭代到 pos == 3 的位置时，发现 "Leet" 在 dict 中有记录，那么继续从 pos == 4 开始迭代，到 pos == 7 的时候，发现 "Code" 也在 dict 中有记录。此时，迭代已经走到 word 的末尾，恰好结束。可以认为 break 成功。

整理一下上述的思路，即为：

```cpp
auto subBeg = s.cbegin();
for (auto subEnd = subBeg; subEnd != s.cend(); ++subEnd)
     if (dict.find(string(subBeg, subEnd)) != dict.end()) subBeg = subEnd;
//                                                        ^^^^^^^^^^^^^^^
return dict.find(string(subBeg, s.cend())) != dict.end();
```

短短四行，跑通上面的例子完全不成问题。

但这段代码的逻辑硬伤在于 subBeg 每一次找到后便立即后移，会错失一些子串的匹配，如何理解？看例子：

     "aaaaaaa", ["aaaa", "aaa"]
      ^^^```^

按照上述代码的逻辑，最终会返回 false, 因为每一次查找的都是 "aaa", 最终剩下的 "a" 无法匹配。在这个特殊例子里，"aaaa" 的子串，永远无法被验证。

这时候想，都是讨厌的 "aaa" 碍事，能否每次 find 成功后将其 key 在 dict 里删掉？貌似这样的确可以跑通了。

但如果 dict 里的某一个 key 真的就需要反复多次出现以拼成 s 呢？如以下例子：

     "bb", ["a", "b"]
      ^`

可以发现，如果我们匹配上第一个 "b", 继而删除之，那么第二个 "b" 将永远无法匹配，从而被认为是 false, 大错特错了。

真烦，删除肯定是走不通了，那我们笨一点，每一次 find 成功之后，都去多看一眼，后面剩下的子串能否也 find 上，如果可以，直接就返回 true 了。

```cpp
auto subBeg = s.cbegin();
for (auto subEnd = subBeg; subEnd != s.cend(); ++subEnd)
     if (dict.find(string(subBeg, subEnd)) != dict.end()) {
          subBeg = subEnd;
          if (dict.find(string(subBeg, s.cend())) != dict.end()) return true;
     }
return false;
```

虽然有点狗尾续貂的感觉，但的确好使，上述的全部用例都能一次性通过。

当然，对于一些特殊情况，如：

     "a", ["a"]
      ^

需要做特殊判断：

     if (dict.find(s) != dict.end()) return true;

但这样就能躲过最开始我们讲述的硬伤了吗？譬如如下用例：

     "goalspecial", ["go","goal","goals","special"]
        ^^^^^^^^^

按照上述代码逻辑，首先匹配上 "go", 然后 `subBeg` 就已经后移至 'a', 这部分子串，无论如何也是匹配不上了，但如果一开始是分割成："goal" + "special", 那么恰好匹配上。

经过这么多用例的摧残，我们应该可以感受到**硬伤**到底在何处了。第一次 find 成功，应该产生两条备选方案：

1. `subEnd` 继续后移，继续尝试匹配。
2. `subBeg` 后移，继续尝试匹配。

每一次 find 成功，都有这两个分支。那么我们有一个很自然的思路，就是：在这次迭代里不动 `subBeg`，让这一次迭代继续，每一次 find 成功，我们都将此刻的 `subEnd` 给记录下来。下一次迭代，直接从记录的 `subEnd` 开始。这样，就不会有所遗漏了。

当然，每一次迭代，我们都会立刻判断剩下的子串，是否能够匹配，如果可以，直接返回 true, 这一点逻辑不变。

故，我们需要一个容器来存储 `subEnd`, 代码如下：

```cpp
if (dict.find(s) != dict.end()) return true;

std::vector<string::const_iterator> cache{s.cbegin()};

for (auto subEnd = s.cbegin(); subEnd != s.cend(); ++subEnd)

     for (auto subBeg : cache)

          if (subBeg < subEnd && dict.find(string(subBeg, subEnd)) != dict.end()) {

               if (dict.find(string(subEnd, s.cend())) != dict.end()) return true;

               cache.push_back(subEnd); break;

          }

return false;
```

提交，AC.
