#include <stdio.h>

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define N 100005
#define oo 0x3c3c3c3c
#define TASK "SADMIN"
int n, m;
vector<int> a[N];
int Num[N], Low[N], cnt = 0;
stack<int> st;
int Count = 0;

void minimize(int &a, int b) {
    if (a > b) a = b;
}

void visit(int u) {
    Num[u] = Low[u] = ++cnt;
    st.push(u);

    for (int v : a[u])
        if (Num[v])
            minimize(Low[u], Num[v]);
        else {
            visit(v);
            minimize(Low[u], Low[v]);
        }

    if (Num[u] == Low[u]) {
        int v;
        do {
            v = st.top();
            st.pop();
            Num[v] = Low[v] = -oo;
        } while (v != u);
        Count++;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);  // WARNING: reversed edge
    }
    for (int i = 1; i <= n; ++i) if (!Num[i]) visit(i);
    printf("%d\n", (m - n) + Count);
}
