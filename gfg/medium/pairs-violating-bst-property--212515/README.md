# pairs-violating-bst-property--212515

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-23T13:26:26.193Z  

```cpp
/* BST Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	void inorder(Node* root, vector<int>& vals) {
		if (!root)
			return;
		inorder(root->left, vals);
		vals.push_back(root->data);
		inorder(root->right, vals);
	}
	
	long long merge(vector<int>& arr, int low, int mid, int high) {
		vector<int> temp;
		int i = low, j = mid + 1;
		long long inv = 0;
		while (i <= mid && j <= high) {
			if (arr[i] <= arr[j]) {
				temp.push_back(arr[i++]);
			} else {
				inv += (mid - i + 1);
				temp.push_back(arr[j++]);
			}
		}
		while (i <= mid)
			temp.push_back(arr[i++]);
		while (j <= high)
			temp.push_back(arr[j++]);
		for (int k = low; k <= high; k++)
			arr[k] = temp[k - low];
		return inv;
	}
	
	long long mergeSort(vector<int>& arr, int low, int high) {
		long long inv = 0;
		if (low < high) {
			int mid = low + (high - low) / 2;
			inv += mergeSort(arr, low, mid);
			inv += mergeSort(arr, mid + 1, high);
			inv += merge(arr, low, mid, high);
		}
		return inv;
	}
	
	int pairsViolatingBST(Node *root) {
		vector<int> vals;
		inorder(root, vals);
		return (int)mergeSort(vals, 0, (int)vals.size() - 1);
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1)