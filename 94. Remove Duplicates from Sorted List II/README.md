这道题没有太多可说的，属于基本题的扩展。

可以先参考前面的 [12. Remove Duplicates from Sorted List](../12. Remove Duplicates from Sorted List).

而这道题多出的一点把戏在于，要把重复的数据删的干干净净。我的策略很简单，将重复的数据做一个标记，`isDuplicate`, 然后再删掉重复元素的基础上，最后给剩下那个光棍补上一刀。

虽然有点啰嗦，但是效率还过得去。
