#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAXVEX 100
#define INF 0x3f3f3f3f

int n;
int adj[MAXVEX][MAXVEX];

void Dijkstra(int v0, int dist[], int path[]) {
    int S[MAXVEX];
    for (int v = 0; v < n; v++) {
        dist[v] = adj[v0][v];
        if (dist[v] < INF)
            path[v] = v0;
        else
            path[v] = -1;
        S[v] = 0;
    }
    dist[v0] = 0;
    S[v0] = 1;

    for (int i = 1; i < n; i++) {
        int min = INF;
        int u = -1;
        for (int w = 0; w < n; w++) {
            if (!S[w] && dist[w] < min) {
                u = w;
                min = dist[w];
            }
        }
        if (u == -1) break;
        S[u] = 1;

        for (int w = 0; w < n; w++) {
            if (!S[w] && (min + adj[u][w] < dist[w])) {
                dist[w] = min + adj[u][w];
                path[w] = u;
            }
        }
    }
}

void PrintPath(int path[], int v0, int v) {
    if (v == v0) {
        printf("%d ", v0);
        return;
    }
    if (path[v] == -1) {
        printf("No path from %d to %d\n", v0, v);
        return;
    }
    int stack[MAXVEX];
    int top = -1;
    while (v != v0) {
        stack[++top] = v;
        v = path[v];
    }
    printf("%d ", v0);
    while (top != -1) {
        printf("-> %d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < MAXVEX; i++)
        for (int j = 0; j < MAXVEX; j++)
            adj[i][j] = INF;

    int m;
    printf("请输入城市数 n (<= %d) 与道路数 m：\n", MAXVEX);
    if (scanf("%d %d", &n, &m) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    if (n > MAXVEX || n <= 0) {
        printf("Number of vertices exceeds maximum limit.\n");
        return 1;
    }

    printf("接下来输入 %d 条边：每行格式 -> 起点 终点 时间(正整数)，节点编号从 0 到 %d\n", m, n-1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u < 0 || u >= n || v < 0 || v >= n) {
            fprintf(stderr, "边的节点编号非法：%d %d\n", u, v);
            return 1;
        }
        // 若有多条边，保留最短时间的那条
        if (w < adj[u][v]) adj[u][v] = w;
    }
     int s, t;
    printf("请输入起点 s 和终点 t（编号 0..%d）：\n", n-1);
    if (scanf("%d %d", &s, &t) != 2) {
        fprintf(stderr, "输入格式错误\n");
        return 1;
    }
    if (s < 0 || s >= n || t < 0 || t >= n) {
        fprintf(stderr, "起点或终点编号非法\n");
        return 1;
    }

    int dist[MAXVEX], prev[MAXVEX];
    Dijkstra(s, dist, prev);

    if (dist[t] == INF) {
        printf("从 %d 到 %d 无可达路径。\n", s, t);
    } else {
        printf("从 %d 到 %d 的最短时间为：%d\n", s, t, dist[t]);
        printf("路径为：");
        PrintPath(prev, s, t);
        printf("\n");
    }

    return 0;
}