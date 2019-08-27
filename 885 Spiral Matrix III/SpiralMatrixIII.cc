class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int N=R*C;
        vector<vector<int> > res(N);
        bool flag = false;
        int value = 0;
        int len=1;
        int x=r0;
        int y=c0;
        int index = 0;
        while (value<N) {
            for (int i=0;i<len;i++) {
                cout<<"x="<<x<<" ,y="<<y<<endl;
                if (x>=0 && x<R && y>=0 && y<C) {
                    res[value++]={x,y};
                    if (value==N) break;
                }
                x+=dir[index].first;
                y+=dir[index].second;
            }
            if (!flag) flag=true;
            else {
                flag = false;
                len++;
            }
            index = (index+1)%4;
        }
        return res;
    }
private:
    vector<pair<int,int> > dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
};