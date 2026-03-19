// BIBLIOTECAS

#include <stdio.h> // rintf, fgets, scanf
#include <string.h> // strings (strcmp, strcpy)
#include <stdlib.h> // Funções gerais
#include <time.h> // Medir tempo

// CONSTANTE
#define MAX_COMPONENTES 20 // Limite máximo de componentes

// Definições de cores de texto (Foreground)
#define ANSI_COLOR_RED     "\x1b[1;31m"
#define ANSI_COLOR_GREEN   "\x1b[1;32m"
#define ANSI_COLOR_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct{
    char nome [30];
    char tipo [20];
    int prioridade;
} Componente;

// Chamada das Funções

int cadastrarComponentes (Componente vetor[]);
void mostrarComponentes(Componente vetor[], int n);
void bubbleSortNome(Componente vetor[], int n);
void insertionSortTipo (Componente vetor[], int n);
void selectionSortPrioridade(Componente vetor[], int n);
int buscaBinariaPorNome(Componente vetor[], int n, char alvo[]);

// === Função principal === //

int main() {
    Componente componentes[MAX_COMPONENTES];
    int n = 0;
    int opcao;
    int ordenadoPorNome = 0; // flag de controle

    printf("TORRE DE FUGA INICIADA\n");

    do {
        // menu
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar componentes\n");
        printf("2. Mostrar componentes\n");
        printf("3. Bubble Sort (por nome)\n");
        printf("4. Insertion Sort (por tipo)\n");
        printf("5. Selection Sort (por prioridade)\n");
        printf("6. Busca binaria por nome\n");
        printf(ANSI_COLOR_RED"0. Sair\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW"Escolha: "ANSI_COLOR_RESET);

        char buffer[10];
        fgets(buffer, 10, stdin);
        opcao = atoi(buffer);

        switch (opcao) {
            case 1:
            
                n = cadastrarComponentes (componentes);
                break;
            case 2:
                if (n == 0) {
                printf("\nNenhum componente cadastrado!\n");
                } else {
                    mostrarComponentes(componentes, n);
                }
                break;
            case 3:
                if (n == 0) {
                printf("\nNenhum componente cadastrado!\n");
                } else {
                    bubbleSortNome(componentes, n);
                    ordenadoPorNome = 1;  // ← marca que está ordenado por nome!
                    mostrarComponentes(componentes, n);
                }
                break;
            case 4:
                if (n == 0) {
                printf("\nNenhum componente cadastrado!\n");
                } else {
                    insertionSortTipo (componentes, n);
                    mostrarComponentes(componentes, n);
                }
                break;
            case 5:

                if (n == 0) {
                printf("\nNenhum componente cadastrado!\n");
                } else {
                    selectionSortPrioridade(componentes, n);
                    ordenadoPorNome = 0;  // ← perdeu a ordem por nome
                    mostrarComponentes(componentes, n);
                }
                break;
            case 6:
                if (n == 0) {
                printf("\nNenhum componente cadastrado!\n");
                } else {
                if (ordenadoPorNome == 0) {
                    printf("\nOrdene por nome primeiro! (opcao 3)\n");
                } else {
                    char nomeChave[30];
                    printf("Digite o nome: ");
                    fgets(nomeChave, 30, stdin);
                    nomeChave[strcspn(nomeChave, "\n")] = '\0';

                    int pos = buscaBinariaPorNome(componentes, n, nomeChave);

                    if (pos != -1) {
                        printf("\nEncontrado! Nome: %s | Tipo: %s | Prioridade: %d\n",
                                    componentes[pos].nome,
                                    componentes[pos].tipo,
                                    componentes[pos].prioridade);
                    } else {
                        printf("\nComponente nao encontrado!\n");
                        }
                    }
                }
                break;      
            case 0:
                printf("\nAtivando torre de fuga...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}




    // ========= ESTRUTURA DAS FUNÇÕES ========= //

int cadastrarComponentes (Componente vetor[]){

    char buffer [10];
    printf("Quantos componentes: ");
    fgets(buffer, 10, stdin);
    int n =  atoi (buffer);

    for (int i = 0; i < n; i++) {

        printf("\n--- Cadastre o item %d ---\n", i + 1);
        printf("Nome: ");
        fgets(vetor[i].nome, 30, stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = '\0';

        printf("Tipo: ");
        fgets(vetor[i].tipo, 20, stdin);
        vetor[i].tipo[strcspn(vetor[i].tipo, "\n")] = '\0';

        printf("Prioridade: ");
        char buffer2[10];
        fgets(buffer2, 10, stdin);
        vetor[i].prioridade = atoi(buffer2);

        printf("\n");
        printf("Item %d cadastrado com sucesso!\n", i + 1);
        printf("\n");
    }
    return n; // ← devolve quantos foram cadastrados
}


void mostrarComponentes(Componente vetor[], int n){
    printf("\n+--------------------------------+----------------------+------------+\n");
    printf("| %-30s | %-20s | PRIORIDADE |","NOME", "TIPO");
    printf("\n+--------------------------------+----------------------+------------+\n");

    for(int i =0; i<n; i++){
     printf("| %-30s | %-20s |      %2d    | \n",
         vetor[i].nome, vetor[i].tipo, vetor[i].prioridade);

    printf("+--------------------------------+----------------------+------------+\n");
    };
}


void bubbleSortNome(Componente vetor[], int n){

    for (int i = 0; i < n - 1; i++) {       // passagens
        for (int j = 0; j < n - 1 - i; j++) { // compara vizinhos

            if (strcmp(vetor[j].nome, vetor[j+1].nome) > 0) {
                Componente temp = vetor[j];      // 1. guarda o [j]
                vetor[j]        = vetor[j + 1]; // 2. [j] recebe [j+1]
                vetor[j + 1]    = temp;          // 3. [j+1] recebe o guardado
            }
        }
    }
}

void insertionSortTipo (Componente vetor[], int n){

    for (int i = 1; i < n; i++) {

        Componente chave = vetor[i]; // pega a carta atual
        int j = i - 1;

        // enquanto o vizinho da esquerda for maior que a chave...
        while (j >= 0 && strcmp(vetor[j].tipo, chave.tipo) > 0) {
            vetor[j + 1] = vetor[j]; // empurra ele para direita
            j--;
        }

        vetor[j + 1] = chave; // insere a chave na posição certa
    }
}

void selectionSortPrioridade(Componente vetor[], int n){
     for (int i = 0; i < n; i++) {      // rodadas

        int indiceMaior = i;            // assume que o maior está em i

        for (int j = i +1 ; j < n; j++) {  // procura o maior no restante
            if (vetor[j].prioridade > vetor[indiceMaior].prioridade) {
                indiceMaior = j;        // achou um maior!
            }
        }

        // troca vetor[i] com vetor[indiceMaior]
        Componente temp    = vetor[i];
        vetor[i]         = vetor[indiceMaior];
        vetor[indiceMaior] = temp;
    }
}

int buscaBinariaPorNome(Componente vetor[], int n, char alvo[]){
    int inicio = 0;
    int fim    = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        int cmp = strcmp(vetor[meio].nome, alvo);

        if (cmp == 0) {
            return meio;       // achou! retorna a posição
        } else if (cmp < 0) {
            inicio = meio + 1; // busca na metade direita
        } else {
            fim = meio - 1;    // busca na metade esquerda
        }
    }

    return -1; // não encontrou
}
