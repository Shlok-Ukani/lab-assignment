class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        for (int i=0; i<9; i++) {
            map <char,int> m1, m2;
            for (int j=0; j<9; j++) {
                if ( a[i][j]>='1' && a[i][j]<='9' ) m1[a[i][j]]++;
                if ( a[j][i]>='1' && a[j][i]<='9' ) m2[a[j][i]]++;
            }
            for (auto j : m1) if ( j.second>1 ) return false;
            for (auto j : m2) if ( j.second>1 ) return false;
        }
        int x = 3, y = 0, z = 3;
        while (x--) {
            map <char,int> m1, m2, m3;
            for (int i=y; i<z; i++) {
                for (int j=0; j<9; j++) {
                    if ( j<3 && a[i][j]>='1' && a[i][j]<='9' ) m1[a[i][j]]++;
                    else if ( j>=3 && j<6 && a[i][j]>='1' && a[i][j]<='9' ) m2[a[i][j]]++;
                    else if ( j>=6 && j<9 && a[i][j]>='1' && a[i][j]<='9' ) m3[a[i][j]]++;
                }
            }
            for (auto j : m1) if ( j.second>1 ) return false;
            for (auto j : m2) if ( j.second>1 ) return false;
            for (auto j : m3) if ( j.second>1 ) return false;
            y += 3, z += 3;
        }
        return true;
    }
};
