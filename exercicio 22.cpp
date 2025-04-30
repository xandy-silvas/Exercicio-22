#include <stdio.h>

void imprimir_subconjunto(int arr[], int n, int mascara) {
    printf("{");
    int primeiro = 1;
    for (int i = 0; i < n; i++) {
        if (mascara & (1 << i)) {
            if (!primeiro) printf(",");
            printf("%d", arr[i]);
            primeiro = 0;
        }
    }
    printf("} ");
}

void gerar_subconjuntos(int arr[], int n, int indice, int mascara) {

    if (indice == n) {
        imprimir_subconjunto(arr, n, mascara);
        return;
    }
    
    gerar_subconjuntos(arr, n, indice + 1, mascara);
    
    gerar_subconjuntos(arr, n, indice + 1, mascara | (1 << indice));
}

void subconjuntos(int arr[], int n) {
    gerar_subconjuntos(arr, n, 0, 0);
}

int main() {
    int n, i;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    
    
    int arr[n];
    
    printf("Digite os %d elementos do array:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Subconjuntos do array [");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]:\n");
    
    subconjuntos(arr, n);
    printf("\n");
    
    return 0;
}
