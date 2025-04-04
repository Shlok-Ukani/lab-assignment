class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int,int> a;
        for (auto i : nums) a[i]++;
        pair <int,int> b[a.size()];
        int j = 0;
        for (auto i : a) {
            b[j].first = i.second;
            b[j].second = i.first;
            j++;
        }
        sort (b, b+a.size());
        vector <int> ans;
        j = a.size()-1;
        while (k--) {
            ans.push_back(b[j].second);
            j--;
        }
        return ans;
    }
};
