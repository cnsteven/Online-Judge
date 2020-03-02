/*
    寒假作业

    现在小学的数学题目也不是那么好玩的。
    看看这个寒假作业：

    □ + □ = □
    □ - □ = □
    □ × □ = □
    □ ÷ □ = □

    (如果显示不出来，可以参见【图1.jpg】)

    每个方块代表1~13中的某一个数字，但不能重复。
    比如：
    6  + 7 = 13
    9  - 8 = 1
    3  * 4 = 12
    10 / 2 = 5

    以及：
    7  + 6 = 13
    9  - 8 = 1
    3  * 4 = 12
    10 / 2 = 5

    就算两种解法。（加法，乘法交换律后算不同的方案）

    你一共找到了多少种方案？


    请填写表示方案数目的整数。
    注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

    64
*/
#include <iostream>
using namespace std;

const int N = 13;

int ans = 0;
int a[N] = {0};
bool vis[N] = {false};

bool test(int n) {
    if (n == 2) {
        if (a[0] + a[1] == a[2])
            return true;
    } else if (n == 5) {
        if (a[3] - a[4] == a[5])
            return true;
    } else if (n == 8) {
        if (a[6] * a[7] == a[8])
            return true;
    } else if (n == 11) {
        if (a[9] == a[10] * a[11]) {
            ans++;
            return true;
        }
    } else
        return true;
    return false;
}

void dfs(int n) {
    int i;
    if (n >= N)
        return;
    for (i = 0; i < N; i++) {
        if (!vis[i]) {
            vis[i] = true;
            a[n] = i + 1;
            if (!test(n)) {
                vis[i] = false;
                continue;
            }
            dfs(n + 1);
            vis[i] = false;
        }
    }
}

int main() {
    dfs(0);
    cout << ans << endl;
    return 0;
}