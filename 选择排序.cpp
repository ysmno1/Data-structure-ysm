#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i, minindex;
	for (int i = 0; i < n - 1; i++) {   //֮������n-1������Ϊ���һ��������Ҫ���������С������
		minindex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minindex]) {
				minindex = j;
			}
			swap(a[i], a[minindex]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
}

//ѡ������ÿһ�α����ҵ���С��һ��������¼λ�ò��ŵ���ǰ��ȥ��������Ҫminindex�����������������Ҫ���ϸ���minindex��Ȼ�󽻻�ǰ���i��������Сֵ