#include <stdio.h>

int grafo[2001][2001];
int visitado[2001];
int n, m;

void zera_visitado() {
    int i;
    for(i = 1; i <= n; i++) {
        visitado[i] = 0;
    }
}

void zera_grafo() {
    int i, j;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            grafo[i][j] = 0;
        }
    }
}

int resultado() {
    int i;
    for(i = 1; i <= n; i++) {
        if(visitado[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void busca_profundidade(int vertice) {
    int i;
    
    visitado[vertice] = 1;
    for(i = 0; i <= n; i++) {
        if(visitado[i] == 0 && grafo[vertice][i] == 1) {
            busca_profundidade(i);
        }
    }
}

int main() {
    int v, w, p;
    int i;
    
    do {
        zera_grafo();
        zera_visitado();

        scanf("%d", &n);
        if(n == 0) break;

        scanf("%d", &m);
        for(i = 1; i <= m; i++) {
            scanf("%d %d %d", &v, &w, &p);
            grafo[v][w] = 1;
            if(p == 2) {
                grafo[w][v] = 1;
            }
        }

        i = 1;
        int res = 1;
        while(i <= n) {
            busca_profundidade(i);
            res = resultado();
            
            if(res != 0){
                i++;
                zera_visitado();
            }
            else {
                break;
            }
        }

        if(i == n+1) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }

    } while(1);

    return 0;
}