#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int,int>> q;
    q.push(make_pair(sr,sc));
    int nrows = image.size();
    int ncols = image[0].size();

    //mark the starting point
    int pcolor = image[sr][sc];
    image[sr][sc] = color;

    //visited set
    set<pair<int,int>> visited;

    while (!q.empty()){
        pair<int,int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        vector<vector<int>> neis = {
            {x+1,y},
            {x-1,y},
            {x,y+1},
            {x,y-1}
        };

        for(auto nei : neis){
            int nx = nei[0];
            int ny = nei[1];

            pair<int,int> nei_pair = make_pair(nx,ny);

            if (
                visited.find(nei_pair)==visited.end() &&\
                nx>=0 && nx<nrows && ny>=0 && ny<ncols\
                && image[nx][ny]==pcolor
            ){
                image[nx][ny] = color;
                q.push(nei_pair);
                visited.insert(nei_pair);
            }
        }
    }

    return image;
}

int main(){
    int nrows,ncols;

    cout << "Enter number of rows\n";
    cin >> nrows;

    cout << "Enter number of columns\n";
    cin >> ncols;

    vector<vector<int>> image;

    for(int i = 0;i<nrows;i++){
        vector<int> row;

        for(int j = 0;j<ncols;j++){
            cout << "Enter color\n";
            
            int color;
            cin >> color;
            row.push_back(color);
        }

        image.push_back(row);
    }

    int x,y;
    cout << "Enter source\n";
    cin >> x >> y;

    int color;
    cout << "Enter color\n";
    cin >> color;

    image = floodFill(image,x,y,color);
    
    return 0;
}