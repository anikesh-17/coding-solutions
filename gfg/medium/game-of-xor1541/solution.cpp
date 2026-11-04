class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        
        // If n is even, result is always 0
        if (n % 2 == 0) return 0;
        
        // Otherwise XOR all elements at even indices
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans ^= arr[i];
        }
        
        return ans;
    }
};
