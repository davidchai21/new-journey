class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old_color = image[sr][sc];
        if (old_color == newColor) return image;
        queue<pair<int,int> > q;
        q.push(make_pair(sr,sc));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x-1>=0 && image[x-1][y]==old_color) q.push(make_pair(x-1,y));
            if (y-1>=0 && image[x][y-1]==old_color) q.push(make_pair(x,y-1));
            if (x+1<image.size() && image[x+1][y]==old_color) q.push(make_pair(x+1,y));
            if (y+1<image[0].size() && image[x][y+1]==old_color) q.push(make_pair(x,y+1));
            image[x][y]=newColor;
        }
        return image;
    }
};