笔试遇上这道题，算是倒霉了。当我看到 1 2 5 14 这样规律的时候，我就知道是调出**卡特兰数**的时候了。（切分三角网格的算法）

悲剧的是，我根本没记住公式。于是，查了[维基百科](http://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0)。现再次记录于下：

<img src="http://chart.googleapis.com/chart?cht=tx&chl=C_n = \frac{1}{n%2B1}{2n \choose n} = \frac{(2n)!}{(n%2B1)!n!}" style="border:none;">

<img src="http://chart.googleapis.com/chart?cht=tx&chl=C_0 = 1 , C_{n%2B1}=\sum_{i=0}^{n}C_i\,C_{n-i}\quad\mbox{for }n\ge 0." style="border:none;">

<img src="http://chart.googleapis.com/chart?cht=tx&chl=C_0 = 1 , C_{n%2B1}=\frac{2(2n%2B1)}{n%2B2}C_n," style="border:none;">

这里面比较重要的是最后一个公式。（适用于循环解法）

-----

我首先尝试的其实是第二个公式，很明显的递归，但缺点也很明显，因为这道题已然涉及到大数乘法运算，我这高配的机器跑n = 19的时候，
竟然也有了等待计算的时间。我改用循环，用最后一个公式，速度明显提升，n = 19毫无压力，20都没问题。

-----

记公式的题，遇上就靠命了...

