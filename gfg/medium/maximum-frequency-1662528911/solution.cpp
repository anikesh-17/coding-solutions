class Solution {
	public:
	int maxFrequency(vector<int>& arr, int ok) {
		// code here
		int i = 0, j = 1, w = 0, k = ok ;
		
		sort(arr.begin(), arr.end(), greater<>());
		
		while (i<j and j<arr.size()) {
			w = max(w, j - i);
			
			if (arr[i]-arr[j] <= k) {
				k -= arr[i]-arr[j];
				j++;
			}
			else {
				k += (arr[i]-arr[i + 1])*(j - i-1);
				i++;
				if (i == j)j++;
			}
		}
		w = max(w, j - i);
		
		return w;
	}
};
