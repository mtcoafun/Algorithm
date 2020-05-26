#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
enum color {
    NONE, WHITE, BLACK,         //棋子颜色，NONE表示未落子
};
struct weiqi {
    enum color board[19][19];   //棋盘上每个位置的落子
};

int calc(struct weiqi *wq, int x, int y)
{
    //TODO:
    color self = wq->board[y][x];
    if (self == 0) return -1;
    color op = self == WHITE ? BLACK : WHITE;
    int nums = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    wq->board[y][x] = op;
    while (!q.empty()) {
        auto rc = q.front();
        int row = rc.first, col = rc.second;
        q.pop();
        if (row - 1 >= 0 && wq->board[row - 1][col] != op) {
            if (wq->board[row - 1][col] == NONE) {
                ++nums;
            }
            wq->board[row - 1][col] = op;
            q.push(make_pair(row - 1, col));
        }
        if (row + 1 < 19 && wq->board[row + 1][col] != op) {
            if (wq->board[row + 1][col] == NONE) {
                ++nums;
            }
            wq->board[row + 1][col] = op;
            q.push(make_pair(row + 1, col));
        }
        if (col - 1 >= 0 && wq->board[row][col - 1] != op) {
            if (wq->board[row][col - 1] == NONE) {
                ++nums;
            }
            wq->board[row][col - 1] = self;
            q.push(make_pair(row, col - 1));
        }
        if (row + 1 < 19 && wq->board[row][col + 1] != op) {
            if (wq->board[row][col + 1] == NONE) {
                ++nums;
            }
            wq->board[row][col + 1] = self;
            q.push(make_pair(row, col + 1));
        }
    }
    return nums;
}
int input(struct weiqi *wq, int *x, int *y)
{
    int row, col;
    int ret;
    char buf[80];
    
    for (row = 0; row < 19; ++row) {
        if (fgets(buf, sizeof(buf), stdin) == NULL)
            return -1;
        if (strlen(buf) < 19)
            return -1;
        for (col = 0; col < 19; ++col) {
            switch (buf[col]) {
            case '0':
                wq->board[row][col] = NONE;
                break;
            case '1':
                wq->board[row][col] = WHITE;
                break;
            case '2':
                wq->board[row][col] = BLACK;
                break;
            default:
                return -1;
            }
        }
    }
    ret = fscanf(stdin, "%d,%d\n", x, y);
    if (ret != 2)
        return -1;
    for (row = 0 ; row < 19; ++row) {
        for (col = 0; col < 19; ++col) {
            fprintf(stderr, "%d ", wq->board[row][col]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "x = %d, y = %d\n", *x, *y);
    return 0;
}

int main() {
    struct weiqi wq;
    int x = 0, y = 0;
    int cnt;

    memset(&wq, 0, sizeof(wq));
    if (input(&wq, &x, &y) < 0) {
        fprintf(stderr, "error!\n");
        return 1;
    }
    cnt = calc(&wq, x, y);

    printf("%d\n", cnt);
    return 0;
}