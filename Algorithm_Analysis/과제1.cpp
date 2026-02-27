#include <stdio.h>
#include <stdlib.h> // qsort 함수 사용을 위해 사용
#define MAX_VTX 9 // 정점의 개수
int p[MAX_VTX]; // 각 정점의 부모를 저장하는 배열

typedef struct Graph {
    int n; // 정점의 개수
    int adj[MAX_VTX][MAX_VTX]; // 비용 인접 행렬
} Graph;

typedef struct Edge { // 간선을 나타내는 구조체
    int a, b, w; // 간선의 두 정점과 가중치
} Edge;

void init(int n) {
    for (int i = 0; i < n; i++) p[i] = -1; // 모든 정점을 독립 집합으로 설정
}

int find(int x) {
    if (p[x] < 0) return x; // 루트 노드일 경우 반환
    return p[x] = find(p[x]); // 루트 노드로 갈때까지 반복
}

void union_sets(int x, int y) {
    if (p[x] > p[y]) // y 집합의 크기가 더 크면 y를 루트로 합침
        p[y] += p[x], p[x] = y;
    else // x 집합의 크기가 더 크면 x를 루트로 합침
        p[x] += p[y], p[y] = x;
}

int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w; // 간선의 가중치 차이 반환
}

void kruskal(int n, Edge edges[], int e_count) {
    int count = 0; // 선택된 간선의 개수
    int root1, root2; // 각 집합의 루트 저장 변수
    qsort(edges, e_count, sizeof(Edge), cmp); // 간선을 가중치 순으로 정렬
    init(n); // 집합 초기화

    for (int i = 0; count < n - 1 && i < e_count; i++) { // 간선 선택 반복
        root1 = find(edges[i].a); // 간선의 첫 번째 정점의 루트 찾기
        root2 = find(edges[i].b); // 간선의 두 번째 정점의 루트 찾기
        if (root1 != root2) { // 루트가 다르면 사이클이 발생하지 않음
            printf("간선 %d - %d :가중치: %d\n", edges[i].a, edges[i].b, edges[i].w); // 간선 추가 출력
            count++; // 추가된 간선 수 증가
            union_sets(root1, root2); // 두 정점을 같은 집합으로 합침
        }
    }
}

int create_edges(Graph* g, Edge edge_list[]) {
    int idx = 0; // 간선 배열 인덱스 초기화
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->adj[i][j] != -1 && g->adj[i][j] != 0) { // 간선이 존재하는 경우
                edge_list[idx].a = i; // 간선의 첫 번째 정점
                edge_list[idx].b = j; // 간선의 두 번째 정점
                edge_list[idx++].w = g->adj[i][j]; // 간선의 가중치
            }
        }
    }
    return idx; // 생성된 간선의 수 반환
}

int main() {
    Graph g = {
        9, // 정점의 개수
        { // 비용 인접 행렬
            {0, 4, -1, -1, -1, -1, -1, 8, -1},
            {4, 0, 8, -1, -1, -1, -1, 11, -1},
            {-1, 8, 0, 7, -1, 4, -1, -1, 2},
            {-1, -1, 7, 0, 9, 14, -1, -1, -1},
            {-1, -1, -1, 9, 0, 10, -1, -1, -1},
            {-1, -1, 4, 14, 10, 0, 2, -1, -1},
            {-1, -1, -1, -1, -1, 2, 0, 1, 6},
            {8, 11, -1, -1, -1, -1, 1, 0, 7},
            {-1, -1, 2, -1, -1, -1, 6, 7, 0}
        }
    };
    Edge edges[MAX_VTX * (MAX_VTX - 1) / 2]; // 간선 배열 선언
    int edge_count = create_edges(&g, edges); // 비용 인접 행렬을 기반으로 간선 배열 생성
    kruskal(g.n, edges, edge_count); // 크루스칼 알고리즘 호출
    return 0;
}