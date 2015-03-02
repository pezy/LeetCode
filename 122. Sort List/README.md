链表的排序，需要掌握的至少有两种。

1. 插入排序 - 只在面试的时候使用
2. 归并排序 - 最基础的"合理"排序

我知道插入排序会比较搞笑，但还是先用插入排序试了一试，果然 TimeOut 了。感兴趣的童鞋可以来看看我在 [弹指神通之链表排序](http://segmentfault.com/blog/pezy/1190000002490878#articleHeader6) 中的方法。

于是我改用了另一个基础的方案，归并排序。AC 后发现效果并不差的离谱，是 C++ 方案中的头筹呢。

-----

简单说说归并排序。

关键在于**归并**，这是废话。但想要归并，显然就要有两段链表，我们的原始链表显然就应该分割为两段。我们把这个分割过程，抽取成一个函数。

```cpp
void frontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef) {
    if (source == NULL || sorce->next == NULL) return;
    else {
        ListNode *slow = source, *fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}
```

这里面一个基本的技巧就是快慢指针，LeetCode 里面链表题中出现过多次使用这个技巧解决的，有心的童鞋应该会心一笑。

另外，我们可以利用之前的遇到过的 [019. Merge Two Sorted Lists](../019. Merge Two Sorted Lists).

这样我们的 `mergeSort` 函数将会无比简单。

```cpp
void mergeSort(ListNode **headRef) {
    ListNode *head = *headRef, *front, *back;
    if (head == NULL || head->next == NULL) return;
    frontBackSplit(head, &front, &back);
    mergeSort(&front);
    mergeSort(&back);
    *headRef = sortedMerge(front, back);
}
```
