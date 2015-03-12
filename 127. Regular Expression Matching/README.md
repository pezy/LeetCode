讨厌这种不清不楚的题目。

`.` 代表任意单字符，`*` 可以代表将前面的字符去掉，也可以代表是对前面字符的重复（数目无限）。

下面分析题目中给出的例子：

    aa a    // 不匹配，很明显
    aa aa   // 匹配，也很明显
    aaa aa  // 不匹配
    aa a*   // 匹配，* 可以重复为a
    aa .*   // 匹配，. 可以是 a, * 可以重复 a。
    ab .*   // 匹配，等等，不对啊，什么玩意。先放一放。
    aab c*a*b   // 匹配，第一个 * 可以是 0，剩下 a*b，* 可以是 a 的重复，则 aab 匹配。

貌似唯一的疑问出在 `ab .*` 的匹配上。这个我也困惑了好久好久。无奈之下查看了[讨论](https://leetcode.com/discuss/4514/ismatch-ab-%E2%86%92-true-why-ab-c-expected-false)

摘录让我醍醐灌顶的解释：

> `.*` means zero or any occurrence of `.`, which can be  (no dot at all), `.`, `..`, `...`, etc. `aab` matches `...`, which is one of the possible meanings of `.*`, `ab` matches `..` which is another possible meaning of `.*`. So `isMatch("ab",".*") = isMatch("aab", ".*") = True`.

> So in short, `.*` can match any string.

> One step further, `.*c` matches any string ending with `c`, which does not include `ab`. So `isMatch("ab", ".*c") = False`

> -----
> by @MoonKnight

是否看明白了呢？`.*`中 `*` 重复的并不是某一个特定的字符，而是 `.` 本身。所以 `.*` 可以是 `..`。
这样一来，第一个`.`匹配`a`，第二个`.`匹配`b`。这不就与`ab`匹配上了吗？

再往远了想一想，`.*` 可以匹配任意字符串啊。（本质在于咱们脑子里规定了一个与出题人不一致的顺序，我们认为要先确定`.`，然后再去看 `*`。）

说这题不清不楚，没说错吧。如果你一开始就能会意，恭喜你了。

-----

我的思路是，要判断字符串，肯定要从字符开始。这就简化了问题，比较两个字符是否匹配很容易。

```cpp
// char s,p;
if (s == p || (p == '.' && s != '\0')) // same character.
```

首先，迭代 `p`，如果 `*p == '\0'`，那么可以直接返回 `return *s == '\0';`

其次，判断后面有没有跟`*`，即 `if (p[1] != '*')` 那么就正常比较当前字符。若跟了 `*`，
则与判断 `isMatch(s, p+2)` 无异。（因为 `*` 可以代表0）

最后，一旦出现不同字符，直接返回 `false`。

代码很简单，5行搞定。
