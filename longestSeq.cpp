class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), maxi = 0, count = 0, last = INT_MIN;
        map <int,int> a;
        for (int i=0; i<n; i++) a[ nums[i] ] = 1;
        for (auto i : a)
        {
            if ( i.first == last )
            {
                count++;
                last++;
            }
            else
            {
                maxi = count>maxi ? count : maxi;
                count = 1;
                last = i.first + 1;
            }
        }
        return max(maxi, count);
    }
};
