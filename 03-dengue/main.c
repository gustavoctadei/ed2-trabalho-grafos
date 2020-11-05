#include <stdio.h>

int grafo[101][101];
int distancias[101][101];
int n;

void zera_grafo() {
    int i, j;
    for(i = 0; i < 101; i++) {
        for(j = 0; j < 101; j++) {
            grafo[i][j] = 0;
        }
    }
}

void ajusta_grafo() {
    int i, j;
    for(i = 1; i <=n; i++) {
        for(j = 1; j <= n; j++) {
            if(i == j) grafo[i][j] = 0;
            else if(grafo[i][j] == 0) grafo[i][j] = 999;
        }
    }
}

int retorna_resultado() {
    if(n == 1) return 1;

    int i, j, resultado;
    int soma_linha = 0, menor_soma_linha = 99999;

    for(i = 1; i <= n; i++) {
        soma_linha = 0;
        for(j = 1; j <= n; j++) {
            soma_linha += distancias[i][j];
        }

        if(menor_soma_linha > soma_linha) {
            menor_soma_linha = soma_linha;
            resultado = i;
        }
    }

    return resultado;
}

void imprime_distancias() {
    int i, j;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("|%d|", distancias[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall() {
    int i, j, k;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            distancias[i][j] = grafo[i][j];
        }
    }

    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(distancias[i][k] + distancias[k][j] < distancias[i][j]) {
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                }
            }
        }
    }
}

int main() {
    int x, y;
    int i, numero_teste = 0;

    do {
        numero_teste++;
        scanf("%d", &n);
        if(n == 0) break;

        zera_grafo();
        
        if(n > 1) {
            i = 0;
            do {
                scanf("%d %d", &x, &y);
                grafo[x][y] = 1;
                grafo[y][x] = 1;
                i++;
            } while(i < n-1);

            ajusta_grafo();
            floyd_warshall();
        }
        
        printf("Teste %d\n", numero_teste);
        printf("%d\n\n", retorna_resultado());
        imprime_distancias();

    } while(1);
    return 0;
}