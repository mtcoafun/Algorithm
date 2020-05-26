#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int bfsCalNums(vector<vector<int> >& ground) {
    int rn = ground.size();
    if (!rn) return 0;
    int cn = ground[0].size();
    int nums = 0;
    vector<vector<int> > copy = ground;
    for (int r = 0; r < rn; r++) {
        for (int c = 0; c < cn; c++) {
            if (ground[r][c] == 1) {
                ++nums;
                ground[r][c] = 0;
                queue<pair<int, int> > q;
                q.push(make_pair(r, c));
                while (!q.empty()) {
                    auto rc = q.front();
                    q.pop();
                    int row = rc.first, col = rc.second;
                    if (row - 1 >= 0 && ground[row - 1][col] == 1) {
                        q.push(make_pair(row - 1, col));
                        ground[row - 1][col] = 0;
                        ++nums;
                    }
                    if (row + 1 < rn && ground[row + 1][col] == 1) {
                        q.push(make_pair(row + 1, col));
                        ground[row + 1][col] = 0;
                        ++nums;
                    }
                    if (col - 1 >= 0 && ground[row][col - 1] == 1) {
                        q.push(make_pair(row, col - 1));
                        ground[row][col - 1] = 0;
                        ++nums;
                    }
                    if (col + 1 < cn && ground[row][col + 1] == 1) {
                        q.push(make_pair(row, col + 1));
                        ground[row][col + 1] = 0;
                        ++nums;
                    }
                }
                ground = copy;
                ground[r][c] = 0;
            }
        }
    }
    return nums;
}

int main(){
    //freopen("1.in","r",stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    cout << N << " " << M << endl;
    if (N == 0 || M == 0) return 0;
    vector<vector<int> > ground (N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x; 
            scanf("%d", &x);
            ground[i][j] = x;
        }
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ground[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << bfsCalNums(ground) << endl;
    return 0;
}