01背包：0-1 Knapsack Problem
有n个物品，每个物品的体积是v[i]，价值是w[i]，
有一个背包，体积是V。问这个背包能装下最多多少价值的物品
需要在O(nV)的复杂度下完成

dp[i][j] ：已经讨论了前i个物品，消耗的体积不超过j，最多能拿多少价值。

不拿第i个物品：dp[i - 1][j]
拿第i个物品：dp[i - 1][j - v[i]] + w[i];

for (int i = 1; i <= n; i++)
	for (int j = 0; j <= V; j++)
		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]); 
printf("%d\n", dp[n][V]);

变形：背包必须恰好装满 
memset(dp, 0x80, sizeof(dp));
dp[0][0] = 0;
for (int i = 1; i <= n; i++)
	for (int j = 0; j <= V; j++)
		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]); 
printf("%d\n", dp[n][V]);

变形：n <= 100, V, v[i] <= 1e9, w[i] <= 100
dp[i][j] : 前i个物品的价值之和是j，最小花费多少体积

memset(dp, 0x3f, sizeof(dp)); //dp是ll 
dp[0][0] = 0;
int ans = 0;
for (int i = 1; i <= n; i++){
	for (int j = 0; j <= 10000; j++){
		dp[i][j] = min(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		if (dp[i][j] <= V) ans = max(ans, j);
	}
} 
printf("%d\n", ans);

变形：体积可以<0
先把体积小于0的都选了就可以。

变形：体积和价值都可以<0
处理一下下标可以<0即可。dp的第二维加上所有体积小于0的绝对值之和。
除dp[0][sum]以外，其他dp的初始值都是-inf 
