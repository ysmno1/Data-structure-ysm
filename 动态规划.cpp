//��̬�滮����ѧϰ 


/*
//1.��������   ͬ��쳲�����Ҳ���������Ӧ�� 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long dp[100] = {0};
	dp[1] = 1;      //����ʽ�ӣ���ô��Ҫ�ѳ�ʼ��ֵд���� 
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);  //ͨ��dp�ĵ��Ʒ������ 
	}
	cout << dp[n];
}
*/



/*
//2.��ͬ·������ 
//m*n�ķ���ֻ��������or�����ƶ� 
#include <bits/stdc++.h> 
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
        int dp[m][n];
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;    //��һ��ȫ����Ϊ1 ����Ϊ1���߷� 
        }
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;    //��һ��ȫ����Ϊ1 
        }
        for(int i=1;i<m;i++)    //���ǲ��ǵ�һ�е�һ�е���� 
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];    //�����ߵ����������ط����߷���� 
            }
        }
    cout<<dp[m-1][n-1];
	}

*/

/*
//3.������������
//�������������飬�ҳ��ܺ������������� 

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
	dp[0]=a[0];  //����dp�ĳ�ʼ�������һ����Ҫ���ǰ��� 
	int ans=a[0];
	for (int i=1;i<n;i++){
		dp[i]=max(a[i],dp[i-1]+a[i]);   //Ϊʲô��a��i������ΪҪע�⣬������в�һ���Ǵӵ�һ����ʼ�ģ� 
		ans=max(dp[i],ans);
	}
	cout<<ans;
} 
*/


/*
//4.��󹫹������� 
#include <bits/stdc++.h>
using namespace std;
char a[10000];
char b[10000];
int cnt[10000][10000];
int n,m;
int main(){
    cin>>n>>m;   //��������n��m
    for (int i=0;i<n;i++)
        cin>>a[i];

    for (int i=0;i<m;i++)
        cin>>b[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])   //ע��һ��Ҫ��i-1����Ϊѭ���Ǵ�1��ʼ��
                //�������ȵ�
                cnt[i][j]=cnt[i-1][j-1]+1;   //����+1
            else   //
                cnt[i][j]=max(cnt[i-1][j],cnt[i][j-1]);
        }
    cout<<cnt[n][m];
}
*/


/*
//�����ص�0-1�������� 
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
            if (j<w[i])    //j��ʣ�����������ʣ������С����Ʒ������
                temp[i][j]=temp[i-1][j];   //�ͷŲ��ˣ�ʣ������j����
            else     //����Ž�����
                temp[i][j]=max(temp[i-1][j],temp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<temp[n][c];
}
*/

/*
//�����Ӵ��ͻ��������е�����
//�����Ӵ�Ҫ������ ���������в��ã� 
//5.�����Ӵ�
 
#include <iostream>
using namespace std;
int main()
{
    string str; 
    cin >> str;
    int dp[str.size() + 1][str.size() + 1]={};     //���dp��bool�͵ģ�Ϊ1�������i��j�ǻ��ĵ�   �����ƺ�һ��Ҫ�����dp�ȸ�ֵΪ�� 
	int ans = 1;
    for (int i = 0; i < int(str.size()); i++) {      //1. s[i] = s[j]ʱ, ���dp[i+1][j-1] = 0, ����s[i+1]��s[j-1]�ǻ����Ӵ�,
	                                              //��ô��s[i][j]��Ȼ�ǻ����Ӵ�, ����dp[i][j] = dp[i+1][j-1]
                                                  //2. s[i] != s[j]ʱ, �������dp[i][j] = 0 
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
 
 
 //6.�����������
 #include<bits/stdc++.h>
using namespace std;
 
//��̬�滮�������������У�ʱ�临�Ӷ�ΪO(n^2)
int lpsDp(char *str, int n)
{
	int dp[10][10]={0}, tmp;
	//memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) 	
		dp[i][i] = 1;
 
	for (int i = 1; i < n; i++)
	{
		tmp = 0;
		//�������������ĳ���Ϊi+1���Ӵ���str[j....j+i]  /��j��j+i 
		for (int j = 0; j + i < n; j++)
		{
			//�����β��ͬ
			if (str[j] == str[j + i])
				//tmp = dp[j + 1][j + i - 1] + 2;    //����+2����Ϊ��β��һ���� 
				dp[j][j + i] = dp[j + 1][j + i - 1] + 2;    //����+2����Ϊ��β��һ���� 
			//�����β��ͬ
			else 
				 dp[j][j + i]= max(dp[j + 1][j + i], dp[j][j + i - 1]);       //������tmp��������Ҳû������ 
				//tmp = max(dp[j + 1][j + i], dp[j][j + i - 1]);   
			//dp[j][j + i] = tmp;
		}
	}
	return dp[0][n - 1]; //�����ַ���str[0...n-1]������������г���
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

