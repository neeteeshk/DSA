#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF (int)1e9

/*********************************************************/

class MaxHeap {
	vector<int> heapArr;
public:
	MaxHeap() {
	}

	int getLeft(int i) {
		return 2 * i + 1;
	}

	int getRight(int i) {
		return 2 * i + 2;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	void maxHeapify(int i) {
		int l = getLeft(i);
		int r = getRight(i);
		int largest = i;

		if (l < heapArr.size() && heapArr[l] > heapArr[largest]) {
			largest = l;
		}
		if (r < heapArr.size() && heapArr[r] > heapArr[largest]) {
			largest = r;
		}

		if (largest != i) {
			swap(heapArr[largest], heapArr[i]);
			maxHeapify(largest);
		}
	}

	void deleteKey(int i) {
		heapArr[i] = INF;
		extractMax();
	}

	void extractMax() {
		if (heapArr.size() == 0) {
			return;
		}
		if (heapArr.size() == 1) {
			heapArr.pop_back();
			return;
		}

		swap(heapArr[0], heapArr[heapArr.size() - 1]);
		heapArr.pop_back();
		maxHeapify(0);
	}

	void insertKey(int key) {
		heapArr.push_back(key);
		int i = heapArr.size() - 1;
		while (i != 0 && heapArr[parent(i)] < heapArr[i]) {
			swap(heapArr[parent(i)], heapArr[i]);
			i = parent(i);
		}
	}

	int getMax() {
		return heapArr[0];
	}

	int getKthLargest(int k) {
		while (k-- > 1) {
			extractMax();
		}

		return getMax();
	}

	void fillHeap(vector<int>& arr) {
		for (int i = 0; i < arr.size(); i++) {
			insertKey(arr[i]);
		}
	}

};
int findKthLargest(vector<int> nums, int k) {
	MaxHeap* heap = new MaxHeap();
	heap->fillHeap(nums);
	return heap->getKthLargest(k);
}

void solve(int test) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int k;
	cin >> k;
	cout << findKthLargest(nums, k) << endl;
}

/******************  Main Function  ***********************/
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int testCase;
	cin >> testCase;
	for (int test = 1; test <= testCase; test++) {
		solve(test);
	}
	return 0;
}