class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> freq(n+1);


         for(int i : nums){
         mp[i]++;
    }
    for(const auto it : mp){
        freq[it.second].push_back(it.first);

    }

    vector<int>res;

    for(int i = freq.size()-1; i>0; i--){
        for(int i : freq[i])
        res.push_back(i);
        if(res.size() == k)
        return res;
    }




           return res;
            }
};