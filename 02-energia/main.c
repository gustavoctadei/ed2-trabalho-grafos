#include <stdio.h>

int grafo[101][101];
int visitado[101];
int e, l;

void zera_grafo() {
    int i, j;
    for(i = 0; i < 101; i++) {
        for(j = 0; j < 101; j++) {
            grafo[i][j] = 0;
        }
    }
}

void zera_visitado() {
    int i;
    for(i = 0; i < 101; i++) {
        visitado[i] = 0;
    }
}

int resultado() {
    int i;
    for(i = 1; i <= e; i++) {
        if(visitado[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void busca_profundidade(int vertice) {
    int i;

    visitado[vertice] = 1;
    for(i = 1; i <= e; i++) {
        if(visitado[i] == 0 && grafo[vertice][i] == 1) {
            busca_profundidade(i);
        }
    }
}

int main() {
    int x, y;
    int i, numero_teste = 0;;
    int sucesso;

    do {
        zera_grafo();
        zera_visitado();

        scanf("%d %d", &e, &l);
        if(e == 0 || l == 0) break;

        numero_teste++;

        for(i = 1; i <= l; i++) {
            scanf("%d %d", &x, &y);
            grafo[x][y] = 1;
            grafo[y][x] = 1;
        }

        printf("Teste %d\n", numero_teste);

        i = 1;
        sucesso = 1;
        while(i <= e) {
            busca_profundidade(i);
            sucesso = resultado();

            if(sucesso != 0) {
                i++;
                zera_visitado();
            }
            else {
                break;
            }
        }

        if(i == e+1) {
            printf("normal\n");
        }
        else {
            printf("falha\n");
        }

        printf("\n");

    } while(1);

    return 0;
}