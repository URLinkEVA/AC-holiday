# AcWing 4656. 技能升级

# AcWing 4454. 未初始化警告

# AcWing 4509. 归一化处理

# AcWing 4699. 如此编码

# AcWing 4700. 何以包邮？
新学期伊始，适逢顿顿书城有购书满 x 元包邮的活动，小 P 同学欣然前往准备买些参考书。

一番浏览后，小 P 初步筛选出 n 本书加入购物车中，其中第 i 本（1≤i≤n）的价格为 ai 元。

考虑到预算有限，在最终付款前小 P 决定再从购物车中删去几本书（也可以不删），使得剩余图书的价格总和 m 在满足包邮条件（m≥x）的前提下最小。

试帮助小 P 计算，最终选购哪些书可以在凑够 x 元包邮的前提下花费最小？

## 输入格式
输入的第一行包含空格分隔的两个正整数 n 和 x，分别表示购物车中图书数量和包邮条件。

接下来输入 n 行，其中第 i 行（1≤i≤n）仅包含一个正整数 ai，表示购物车中第 i 本书的价格。

输入数据保证 n 本书的价格总和不小于 x。

## 输出格式
仅输出一个正整数，表示在满足包邮条件下的最小花费。

## 数据范围
70% 的测试数据满足：n≤15；

全部的测试数据满足：n≤30，每本书的价格 ai≤10^4 且 x≤a1+a2+⋯+an。

```
输入样例1：
4 100
20
90
60
60
输出样例1：
110
样例1解释
购买前两本书 (20+90) 即可包邮且花费最小。

输入样例2：
3 30
15
40
30
输出样例2：
30
样例2解释
仅购买第三本书恰好可以满足包邮条件。

输入样例3：
2 90
50
50
输出样例3：
100
样例3解释
必须全部购买才能包邮。
```

### dfs（超时）
- 可以依次枚举每个物品的价格，选和不选各dfs一次
- f[i]表示是否存在花费总和为i的方案，依次从包邮条件x往后枚举即可找到最小花费
- 由于最多有30件物品，每件物品都有选和不选两种可能，时间复杂度为O(2`30)，大约是O(1e9)，会超时，只能过70分的数据

```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35, M = 3e5 + 10;
int w[N];
bool f[M];
int n, x;

void dfs(int u,int v)
{
    f[v] = 1;
    if(u == n)   return;
    dfs(u + 1,v + w[u]);  //选
    dfs(u + 1,v);         //不选
}

int main()
{
    cin >> n >> x;
    for(int i = 0;i < n;i ++)   cin >> w[i];

    dfs(0, 0);

    for(int i = x;i <= M;i ++)
        if(f[i])
        {
            cout << i;
            break;
        }

    return 0;
}
```

### 动态规划（正解）
- f[i]表示是否存在花费总和为i的方案，1代表存在，0代表不存在
- 从价格最大值3e5从大到小枚举，状态方程为 f[j] |= f[j - w[i]]
- 时间复杂度O(30 * 3e5)，也就是O(9e6)，能通过全部用例

```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35, M = 3e5 + 10;
int w[N];
bool f[M];
int n, x;

int main()
{
    cin >> n >> x;
    for(int i = 0;i < n;i ++)
        cin >> w[i];

    f[0] = 1;
    for(int i = 0;i < n;i ++)
        for(int j = M;j >= w[i];j --)
            f[j] |= f[j - w[i]];

    for(int i = x;i <= M;i ++)
        if(f[i])
        {
            cout << i;
            break;
        }

    return 0;
}
```