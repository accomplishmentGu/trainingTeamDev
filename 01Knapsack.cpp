01������0-1 Knapsack Problem
��n����Ʒ��ÿ����Ʒ�������v[i]����ֵ��w[i]��
��һ�������������V�������������װ�������ټ�ֵ����Ʒ
��Ҫ��O(nV)�ĸ��Ӷ������

dp[i][j] ���Ѿ�������ǰi����Ʒ�����ĵ����������j��������ö��ټ�ֵ��

���õ�i����Ʒ��dp[i - 1][j]
�õ�i����Ʒ��dp[i - 1][j - v[i]] + w[i];

for (int i = 1; i <= n; i++)
	for (int j = 0; j <= V; j++)
		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]); 
printf("%d\n", dp[n][V]);

���Σ���������ǡ��װ�� 
memset(dp, 0x80, sizeof(dp));
dp[0][0] = 0;
for (int i = 1; i <= n; i++)
	for (int j = 0; j <= V; j++)
		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]); 
printf("%d\n", dp[n][V]);

���Σ�n <= 100, V, v[i] <= 1e9, w[i] <= 100
dp[i][j] : ǰi����Ʒ�ļ�ֵ֮����j����С���Ѷ������

memset(dp, 0x3f, sizeof(dp)); //dp��ll 
dp[0][0] = 0;
int ans = 0;
for (int i = 1; i <= n; i++){
	for (int j = 0; j <= 10000; j++){
		dp[i][j] = min(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		if (dp[i][j] <= V) ans = max(ans, j);
	}
} 
printf("%d\n", ans);

���Σ��������<0
�Ȱ����С��0�Ķ�ѡ�˾Ϳ��ԡ�

���Σ�����ͼ�ֵ������<0
����һ���±����<0���ɡ�dp�ĵڶ�ά�����������С��0�ľ���ֵ֮�͡�
��dp[0][sum]���⣬����dp�ĳ�ʼֵ����-inf 
