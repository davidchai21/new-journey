class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        for (int i=(N-1)%14+1;i>0;i--) {
            vector<int> t(8,0);
            for (int i=1;i<7;i++) {
                t[i]=(cells[i-1]==cells[i+1]);
            }
            cells.swap(t);
        }
        return cells;
    }
};