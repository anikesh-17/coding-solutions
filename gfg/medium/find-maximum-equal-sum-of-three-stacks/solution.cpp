class Solution {
	public:
	int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
		// code here
		int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		for (int i = n1 - 2; i >= 0; i--)
			{
			s1[i] += s1[i + 1];
			
		}
		for (int i = n2 - 2; i >= 0; i--)
			{
			s2[i] += s2[i + 1];
			
		}
		for (int i = n3 - 2; i >= 0; i--)
			{
			s3[i] += s3[i + 1];
			
		}
		
		int mx_eq_sum = 0;
		map<int, int>fre;
		for (int i = 0; i<n1; i++)fre[s1[i]]++;
		for (int i = 0; i<n2; i++)fre[s2[i]]++;
		for (int i = 0; i<n3; i++)fre[s3[i]]++;
		for (auto &x:fre)
			{
			if (x.second >= 3)mx_eq_sum = max(mx_eq_sum, x.first);
		}
		
		return mx_eq_sum;
		
	}
};
