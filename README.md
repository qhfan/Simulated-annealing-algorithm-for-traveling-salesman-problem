# Simulated-annealing-algorithm-for-traveling-salesman-problem
利用模拟退火算法求解旅行商问题
<h2>问题描述</h2>
<p>有20个城市，TSP文件中给了每个城市的坐标，从A城市出发，最后再回到A城市，求解距离最短路线。</p>
<h2>模拟退火算法简介</h2>
<p>模拟退火是高级搜索的一种，算法简介在<a href='https://blog.csdn.net/huahua19891221/article/details/81737053'>这里</a></p>
<h2>算法思路</h2>
<p>整个过程是一个闭环，所以我们可以不必关心序列中首尾城市各是哪一个，只关心序列中城市的相对顺序</p>
