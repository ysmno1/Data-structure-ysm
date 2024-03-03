#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
}


//为什么要写双层的循环？因为上面的i是遍历的次数，当i为第一个数时，整体遍历一遍排个序；i为第二个数时，整体遍历一遍排个序等等