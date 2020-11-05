#include <stdio.h>

int grafo[51][51];
int visitado[51];
int distancias[51];
int fila[50];
int c, e, l, p;

void zera_grafo() {
    int i, j;
    for(i = 0; i < 51; i++) {
        for(j = 0; j < 51; j++) {
            grafo[i][j] = 0;
        }
    }
}

void zera_visitado() {
    int i;
    for(i = 0; i < 51; i++) {
        visitado[i] = 0;
    }
}

void zera_distancias() {
    int i;
    for(i = 0; i < 51; i++) {
        distancias[i] = 0;
    }
}

void imprime_distancias() {
    int i;
    for(i = 1; i <= c; i++) {
        printf("distancia[%d][%d] = %d\n", l, i, distancias[i]);
    }
    printf("\n");
}

void busca_largura(int origem) {
    int i, vertice, cont = 1, anterior;
    int fila[c], inicio_fila = 0, fim_fila = 1;

    fila[fim_fila] = origem;
    visitado[origem] = cont;
    distancias[origem] = 0;

    while(inicio_fila != fim_fila) {
        inicio_fila = (inicio_fila + 1) % c;
        vertice = fila[inicio_fila];
        cont++;

        for(i = 1; i <= c; i++) {
            if(grafo[vertice][i] == 1 && visitado[i] == 0) {
                anterior = vertice;
                fim_fila = (fim_fila + 1) % c;
                fila[fim_fila] = i;
                visitado[i] = cont;
                if(distancias[i] == 0) distancias[i] = distancias[vertice] + 1;
            }
        }
    }

}

void imprime_resultado() {
    int i, j = 0;
    for(i = 1; i <= c; i++) {
        if(distancias[i] > 0 && distancias[i] <= p) {
            printf("%d ", i);
        }
    }

    printf("\n\n");
}

int main() {
    int x, y;
    int i, numero_teste = 0;

    do {
        zera_grafo();
        zera_distancias();
        zera_visitado();

        scanf("%d %d %d %d", &c, &e, &l, &p);
        if (c == 0 && e == 0 && l == 0 && p == 0) break;

        numero_teste++;

        for(i = 1; i <= e; i++) {
            scanf("%d %d", &x, &y);
            grafo[x][y] = 1;
            grafo[y][x] = 1;
        }

        busca_largura(l);
        printf("Teste %d\n", numero_teste);
        
        imprime_resultado();

    } while(1);

    return 0;
}