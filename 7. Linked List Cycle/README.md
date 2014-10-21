这道题超级有意思的，虽然我第一次提交的时候`Time Limit Exceeded`了。

我是怎么考虑的呢？ 判断是否循环，那还不简单，就像咱们跑圈一样呗，**再次经过起点**不就证明是环？如果一直跑，跑到头都没见到起点，是不是就不是环？

于是我一边抱怨着这种题怎么也是中等题，一边写下了我超简单的答案：
```cpp
if (head && head->next)
    for (ListNode *runner = head->next; runner; runner = runner->next)
        if (head == runner) return true;
return false;
```

首先肯定要判断NULL，如果只有一个节点，也成不了环，所以第一个if语句排除了两种极端情况。然后就像我说的，一个指针等着，另一个指针跑。
于是我提交了，碰到了这么多天以来，第一次未通过：

        Submission Result: Time Limit Exceeded
        Last executed input:	{3,2,0,-4}, tail connects to node index 1
纳闷啊， 怎么回事？我也没消耗额外空间呐。看看报错说什么，说尾巴连上节点1. 等等，节点1？ 恍然大悟。原来题意是问，是否**有环**，
而不是**头尾成环**！也就说下面这种情况：

        (3) --> (2) --> (0)
                /|\     \|/
                 | ---- (-4)

不知道能看懂没，尾节点没有回到首节点，而是回到第二个节点， 也成了环！！！ 我的程序就检测不出来了！

怎么办？ 还有什么办法能够证明自己在跑圈呢？ 肯定还要找参照物啊，除了出发线，最好的参照物只能是一起跑步的人了！

OK, 现在@pezy 和 @Mooophy 一起跑步， pezy慢，Mooophy跑的嗖嗖的。只要存在环，那么飞快的 Mooophy一定可以套 pezy的圈。如果不存在环，
pezy 望着 Mooophy绝尘而去，将再也无法赶上他的脚步。于是我们修改了程序：

```cpp
if (head && head->next)
    for (ListNode *slower = head, *faster = head->next; faster && faster->next; slower = slower->next, faster = faster->next->next)
        if (slower == faster) return true;
return false;
```

直接AC。
