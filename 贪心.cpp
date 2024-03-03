
//1.汽车加油问题 
/*
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int n,k;
	cin>>n>>k;
	int a[k+1];
	for(int i=0; i<k+1; i++)
		cin>>a[i];
	bool f=0;
	int sum=0,gas=n;//gas表示当前的油还可以走多少km
	for(int i=0; i<k+1; i++) {
		if(n<a[i]) f=1;
		if(gas<a[i]) {
			sum++;
			gas=n;
		}
		gas=gas-a[i];
	}
	if(f)
		cout<<"No Solution\n";
	else
		cout<<sum<<endl;
	return 0;
}
*/

/*
//2.活动选择问题 

#include<bits/stdc++.h>
using namespace std;
struct movie {
	int start, end;
};

int cmp(movie a, movie b) {
	return a.end < b.end;
}

int main() {
	int n;
		cin >> n;
		vector<movie> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i].start >> arr[i].end;//输入开始时间和结束时间
		}
		sort(arr.begin(), arr.end(), cmp);//按结束时间从小到大排序
		int end = arr[0].end;//取第一个活动的结束时间
		int sum = 1;//第一个活动一定能放完
		for (int i = 1; i < n; i++) {
			if (arr[i].start < end) {
				continue;//开始时间小于上个活动结束时间的活动不符合要求，跳过
			}
			end = arr[i].end;//更新结束时间
			sum++;
		}
		cout << sum << endl;

}
*/

//3.装箱问题

#include<bits/stdc++.h>
int main() 
{
	int N,xsum=0;
	int s[1000],x[1000];
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&s[i]);
		x[i]=100;
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(x[j]-s[i]>=0)
			{
				x[j]-=s[i];
				printf("%d %d\n",s[i],j+1);
				if(xsum<j+1)
					xsum=j+1;
				break;
			}
		}
	printf("%d\n",xsum);
	return 0;
}
 
 
 //4. 月饼
 
#include<bits/stdc++.h>
using namespace std;
struct node{
	double w;
	double v;
	double c;
}f[10001];
bool cmp(node a,node b)
{
	return a.c>b.c;
}
int main()
{
	int n,m,t;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>f[i].w;
	}
	for(int i=0;i<n;i++){
		cin>>f[i].v;
		f[i].c=f[i].v/f[i].w;
	}
	sort(f,f+n,cmp);
	double ans=0;
	for(int i=0;i<n;i++){
		if(m>f[i].w){
			m-=f[i].w;
			ans+=f[i].v;
		}
		else{
			ans+=m*f[i].c;
			break;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
 
