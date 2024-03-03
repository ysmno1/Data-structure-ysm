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
	for (int i = 0; i < n - 1; i++) {   //之所以是n-1，是因为最后一个数不需要在向后找最小的数了
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

//选择排序，每一次遍历找到最小的一个数，记录位置并放到最前面去，所以需要minindex这个索引。过程中需要不断更新minindex，然后交换前面第i个数和最小值