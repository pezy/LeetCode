这道题挺难，我今天在外用手机没解出来，很多思路都写不通。

第一道坎，在递归传值的问题，我将同级别的`vector<int>`作为参数传吧，那顶级的 `vector<vector<int> >` 怎么办，也要传呐。

后来发现，可以将 `vector<vector<int> >` 作为全局的对象，即成员变量。

再发现，传`vector<int>` 很麻烦，因为肯定是个引用，但一开始这个`vector`是没创建的，哪来的引用呢？纪录level更有效。

第二个坎，就是顺序问题，题目故意将顶层的放在`vector`的最后，给人一种暗示使用递归，自然倒序的感觉。后来发现压根构不成递归树。而且发现顺序的入`vector`，思路更加的顺，可是倒序咋办。

结果发现，这根本不是个问题，顺序的入，然后在return的时候，将成员变量倒序即可。

这是一个小技巧：

```cpp
vector<int> vec;
vec_inverse = vector<int> (vec.rbegin(), vec.rend());
```

呵呵，你以为vector容器构造函数里有个用迭代器构造是干啥使的？

其余的没啥好说的了。遇到level第一个元素，需要在`vector<vector<int>` >中塞一个`vector`.后续的只需要在该`vector`中`push_back`即可。

记录level就是为了找到那个`vector`.
