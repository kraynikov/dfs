#include <iostream>
#include <stdio>

using namespace std;

int cnt = 0;
int razmer;

void dfs(int ** mtx, bool * used, int s) {
    used[s] = true;
    cnt++; //function knows that cnt exists, since it's global variable
    for (int i = 0; i < razmer; i++) {
        if (mtx[s][i] == 1) {
            if (used[i] == false) {
                dfs(mtx, used, s);
                }
        }
    }

    return;
}

int main() {
    int elstart;

    scanf("%d %d", &razmer, &elstart);
    int ** mtx = new int *[razmer];
    for (int i = 0; i < razmer; i++) {
        mtx[i] = new int[razmer];
    }
    for (int i = 0; i < razmer; i++) {
        for (int j = 0; j < razmer; j++) {
            scanf("%d", &mtx[i][j]);
        }
    }

    bool * used = new bool[razmer];
    dfs(mtx, used, elstart);
    cout << cnt;
    return 0;
}