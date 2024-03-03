//动态规划例题学习 


/*
//1.三步问题   同理，斐波那契也是这个样子应该 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long dp[100] = {0};
	dp[1] = 1;      //递推式子，那么就要把初始的值写出来 
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);  //通过dp的递推方程求解 
	}
	cout << dp[n];
}
*/



/*
//2.不同路径问题 
//m*n的方格，只能向下移or向右移动 
#include <bits/stdc++.h> 
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
        int dp[m][n];
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;    //第一行全部赋为1 ，即为1种走法 
        }
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;    //第一列全部赋为1 
        }
        for(int i=1;i<m;i++)    //考虑不是第一行第一列的情况 
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];    //等于走到上面两个地方的走法相加 
            }
        }
    cout<<dp[m-1][n-1];
	}

*/

/*
//3.连续数列问题
//给定整数的数组，找出总和最大的连续数列 

#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int dp[100];
	dp[0]=a[0];  //进行dp的初始化，这个一定不要忘记啊！ 
	int ans=a[0];
	for (int i=1;i<n;i++){
		dp[i]=max(a[i],dp[i-1]+a[i]);   //为什么是a【i】，因为要注意，最长的序列不一定是从第一个开始的！ 
		ans=max(dp[i],ans);
	}
	cout<<ans;
} 
*/


/*
//4.最大公共子序列 
#include <bits/stdc++.h>
using namespace std;
char a[10000];
char b[10000];
int cnt[10000][10000];
int n,m;
int main(){
    cin>>n>>m;   //两个整数n和m
    for (int i=0;i<n;i++)
        cin>>a[i];

    for (int i=0;i<m;i++)
        cin>>b[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])   //注意一定要是i-1，因为循环是从1开始的
                //如果有相等的
                cnt[i][j]=cnt[i-1][j-1]+1;   //长度+1
            else   //
                cnt[i][j]=max(cnt[i-1][j],cnt[i][j-1]);
        }
    cout<<cnt[n][m];
}
*/


/*
//最朴素的0-1背包问题 
#include <bits/stdc++.h>
using namespace std;
int w[1000];
int v[1000];
int temp[101][1001]={0};
int main(){
    int n,c;
    cin>>n>>c;
    for (int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    int i,j;
    for ( i=1;i<=n;i++){
        for ( j=1;j<=c;j++){
            if (j<w[i])    //j是剩余容量，如果剩余容量小于商品的重量
                temp[i][j]=temp[i-1][j];   //就放不了，剩余容量j不变
            else     //如果放进来了
                temp[i][j]=max(temp[i-1][j],temp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<temp[n][c];
}
*/

/*
//回文子串和回文子序列的区别：
//回文子串要连续！ 回文子序列不用！ 
//5.回文子串
 
#include <iostream>
using namespace std;
int main()
{
    string str; 
    cin >> str;
    int dp[str.size() + 1][str.size() + 1]={};     //这个dp是bool型的，为1，代表从i到j是回文的   这里似乎一定要把这个dp先赋值为空 
	int ans = 1;
    for (int i = 0; i < int(str.size()); i++) {      //1. s[i] = s[j]时, 如果dp[i+1][j-1] = 0, 即从s[i+1]到s[j-1]是回文子串,
	                                              //那么从s[i][j]自然是回文子串, 所以dp[i][j] = dp[i+1][j-1]
                                                  //2. s[i] != s[j]时, 如论如何dp[i][j] = 0 
        dp[i][i] = 1;
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            ans = 2;
        }
    }
    for (int len = 3; len <= (int)str.size(); len++) {
        for (int i = 0; i + len - 1 < (int)str.size(); ++i) {
            int k = i + len - 1;
            if (str[i] == str[k]) {
                dp[i][k] = dp[i + 1][k - 1];
                if (dp[i][k]) 
				ans = len;
            }
        }
    }
    cout << ans;
}

//PATZJUJZTACCBCC    ans = 9

//34567536487326483254   ans = 1
 */
 
 
 //6.最长回文子序列
 #include<bits/stdc++.h>
using namespace std;
 
//动态规划求解最长回文子序列，时间复杂度为O(n^2)
int lpsDp(char *str, int n)
{
	int dp[10][10]={0}, tmp;
	//memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) 	
		dp[i][i] = 1;
 
	for (int i = 1; i < n; i++)
	{
		tmp = 0;
		//考虑所有连续的长度为i+1的子串，str[j....j+i]  /从j到j+i 
		for (int j = 0; j + i < n; j++)
		{
			//如果首尾相同
			if (str[j] == str[j + i])
				//tmp = dp[j + 1][j + i - 1] + 2;    //长度+2（因为首尾各一个） 
				dp[j][j + i] = dp[j + 1][j + i - 1] + 2;    //长度+2（因为首尾各一个） 
			//如果首尾不同
			else 
				 dp[j][j + i]= max(dp[j + 1][j + i], dp[j][j + i - 1]);       //这样把tmp换掉好像也没有问题 
				//tmp = max(dp[j + 1][j + i], dp[j][j + i - 1]);   
			//dp[j][j + i] = tmp;
		}
	}
	return dp[0][n - 1]; //返回字符串str[0...n-1]的最长回文子序列长度
}
 
int main()
{
	char str[MAXN];
	while (cin >> str)
	{
		int res = lpsDp(str, strlen(str));
		cout << res << endl;
	}
}

