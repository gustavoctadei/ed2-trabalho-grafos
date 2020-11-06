#include <stdio.h>

int incl[] = {-1, 0, 0, 1};
int incc[] = {0, -1, 1, 0};

int caverna[10][10000];
int N, M;

int dentro_caverna(int l, int c) {
    //Verifica se os vértices de entrada estão dentro dos limites da caverna
    return l >= 0 && l < N && c >= 0 && c < M;
}

int busca_largura(int l, int c) {
    int ini = 0, fim = 0;
    int larguras[10000], comprimentos[10000], distancias_origem[10000];
    int dist = 0;
    larguras[fim] = l;
    comprimentos[fim] = c;
    distancias_origem[fim] = 0;
    fim++;

    while (ini != fim) {
        l = larguras[ini];
        c = comprimentos[ini];
        dist = distancias_origem[ini];
        ini++;

        if (caverna[l][c] == 0) { //Se chegou na saída
            return dist;
        }
        else if (caverna[l][c] == 1) { //Se não é saída, verifica se pode entrar no salão
            for (int i = 0; i < 4; i++) {
                if (dentro_caverna(l + incl[i], c + incc[i]) && caverna[l + incl[i]][c + incc[i]] < 2) {
                    larguras[fim] = l + incl[i];
                    comprimentos[fim] = c + incc[i];
                    distancias_origem[fim] = dist + 1;
                    fim++;
                }
            }
        }

        caverna[l][c] = 2;
    }

    return -1;
}

int main() {
    int x, y, z;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &z);
            caverna[i][j] = z;
            if (caverna[i][j] == 3) {
                x = i;
                y = j;
                caverna[i][j] = 1;
            }
        }
    }

    printf("%d\n", busca_largura(x, y));
    return 0;
}