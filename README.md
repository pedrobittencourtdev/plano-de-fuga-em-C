# 🗼 Torre de Fuga — Sistema de Priorização de Componentes

> Projeto desenvolvido como desafio final de algoritmos de ordenação e busca em C.  
> Construído do zero, passo a passo, aprendendo na prática.

---

## 📖 Sobre o Projeto

Imagine que você sobreviveu até a última safe zone de um jogo e precisa montar uma **torre de resgate** para escapar da ilha. Para isso, você precisa organizar os componentes certos, na ordem certa e com a prioridade certa.

Este sistema em C permite:
- Cadastrar até 20 componentes da torre (nome, tipo e prioridade)
- Ordenar os componentes por diferentes critérios
- Localizar o componente-chave para ativar a torre usando busca binária
- Tudo através de um menu interativo

---

## 🚀 Funcionalidades

| Opção | Funcionalidade |
|-------|---------------|
| 1 | Cadastrar componentes |
| 2 | Exibir todos os componentes |
| 3 | Ordenar por **nome** (Bubble Sort) |
| 4 | Ordenar por **tipo** (Insertion Sort) |
| 5 | Ordenar por **prioridade** (Selection Sort) |
| 6 | Buscar componente por nome (Busca Binária) |
| 0 | Sair / Ativar torre |

---

## 🧠 O que eu aprendi

### 📦 Struct
Criar uma "ficha" com vários campos relacionados:
```c
typedef struct {
    char nome[30];
    char tipo[20];
    int  prioridade;
} Componente;
```

### 🔵 Bubble Sort — ordenar por nome
Compara dois vizinhos e troca se estiver fora de ordem. Repete até tudo estar correto.
```c
if (strcmp(vetor[j].nome, vetor[j+1].nome) > 0) {
    Componente temp = vetor[j];
    vetor[j]        = vetor[j+1];
    vetor[j+1]      = temp;
}
```

### 🟡 Insertion Sort — ordenar por tipo
Pega um elemento e insere ele no lugar certo dentro da parte já ordenada, como organizar cartas na mão.
```c
Componente chave = vetor[i];
while (j >= 0 && strcmp(vetor[j].tipo, chave.tipo) > 0) {
    vetor[j+1] = vetor[j];
    j--;
}
vetor[j+1] = chave;
```

### 🔴 Selection Sort — ordenar por prioridade
Encontra o elemento de maior prioridade e coloca na frente. Repete para o restante.
```c
if (vetor[j].prioridade > vetor[indiceMaior].prioridade) {
    indiceMaior = j;
}
```

### 🔍 Busca Binária — localizar por nome
Divide o vetor ao meio repetidamente para encontrar o componente-chave. Muito mais eficiente que busca linear — com 1000 itens, precisa de no máximo ~10 comparações!
```c
int meio = (inicio + fim) / 2;
int cmp  = strcmp(vetor[meio].nome, alvo);

if      (cmp == 0) return meio;       // achou!
else if (cmp <  0) inicio = meio + 1; // busca na direita
else               fim    = meio - 1; // busca na esquerda
```

---

## ⚡ Comparativo dos Algoritmos

| Algoritmo | Critério | Como funciona | Complexidade |
|-----------|----------|---------------|--------------|
| Bubble Sort | Nome | Troca vizinhos fora de ordem | O(n²) |
| Insertion Sort | Tipo | Insere no lugar certo | O(n²) |
| Selection Sort | Prioridade | Seleciona o maior repetidamente | O(n²) |
| Busca Binária | Nome | Divide ao meio | O(log n) |

---

## 🛠️ Como compilar e executar

**Pré-requisito:** ter o GCC instalado.

```bash
# Compilar
gcc -o torre_de_fuga torre_de_fuga.c

# Executar
./torre_de_fuga
```

---

## 📁 Estrutura do Código

```
torre_de_fuga.c
│
├── Bibliotecas e constantes
├── typedef struct Componente
│
├── mostrarComponentes()       → exibe tabela de componentes
├── cadastrarComponentes()     → lê dados do usuário
├── bubbleSortNome()           → ordena por nome
├── insertionSortTipo()        → ordena por tipo
├── selectionSortPrioridade()  → ordena por prioridade
├── buscaBinariaPorNome()      → busca binária por nome
│
└── main()                     → menu interativo do/while + switch
```

---

## 📚 Bibliotecas utilizadas

```c
#include <stdio.h>   // printf, fgets
#include <string.h>  // strcmp, strcspn
#include <stdlib.h>  // atoi
#include <time.h>    // clock()
```

---

## 👨‍💻 Sobre o desenvolvimento

Este projeto foi desenvolvido do zero como parte do aprendizado de:
- Estruturas de dados em C (`struct`, vetores)
- Algoritmos clássicos de ordenação
- Busca binária e sua eficiência
- Modularização com funções
- Entrada segura de dados com `fgets`

Cada etapa foi construída progressivamente, com compreensão de cada conceito antes de avançar.

---

*Missão cumprida. A torre de fuga está ativa.* 🚀