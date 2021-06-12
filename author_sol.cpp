#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		vector<long long> l(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i];
		}
		// sort the sequence in non-decreasing order
		sort(l.begin(), l.end());
		int cnt = 0;
		// start the for-loop in the last element until the 2nd element
		for (int i = n - 1; i >= 2; i--) {
			// for every current element, we perform a binary search to find the
			// the number of ways that the sum of two values are STRICLY less
			// than the value of the current element being iterated upon
			// 1st addend: start from the next value before the current value 
			// (adjacent that is smaller)
			int j = i - 1;
			// 2nd addend: start from the 1st element
			int k = 0;
			// run a while-loop until 'k' is greater than or equal to 'j'
			while (k < j) {
				// check if the sum of the 1st and 2nd addends is STRICTLY less than
				// the current element being iterated upon
				if (l[k] + l[j] < l[i]) {
					// if yes, then count the number of elements between them (number of ways)
					// because any value before the 1st addend that is added to the 2nd addend
					// will produce a value that is less than the current element being iterated upon
					cnt += (j - k);
					// increment 'k' to the see if there are other valid addends
					k++;
				} else {
					// otherwise, if the sum of the 1st and 2nd addends is greater than or equal to
					// the current element being iterated upon, then we need to lower the search, so
					// that's why 'j' needs to be decremented until we find the 1st addend that
					// can form a sum with the 2nd addend which is less than the current element
					// being iterated upon (if it exists)
					j--;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
