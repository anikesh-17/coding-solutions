class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        vector<int> odd, even;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] % 2 == 0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        
        int idx = 0;
        for (int x : odd) {
            arr[idx++] = x;
        }
        for (int x : even) {
            arr[idx++] = x;
        }
    }
};