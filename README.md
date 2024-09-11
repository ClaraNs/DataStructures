<h1 align="center">DataStructures</h1>
<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++ Badge">
</p>

Este repositório contém implementações realizadas na disciplina PCO001 - Algoritmos e Estruturas de Dados.

## :link: Lista Encadeada (Linked List)

<div align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20220712172013/Singlelinkedlist.png" alt="Descrição da Imagem" width="500"/>
</div>

Uma **lista encadeada** é uma estrutura de dados linear composta por uma sequência de elementos chamados **nós**. Cada nó contém dois componentes principais:

1. A informação que o nó armazena.
2. Um ponteiro que aponta para o próximo nó na sequência.

A lista começa com um nó chamado **cabeça (head)** e termina com um nó cujo ponteiro é `NULL`, indicando o fim da lista.

### Vantagens:

- **Inserção/remoção eficiente**: Operações de inserção ou remoção de elementos podem ser feitas em tempo constante, desde que a posição seja conhecida. Isso é mais eficiente do que em arrays, onde a realocação de elementos é necessária.
- **Tamanho dinâmico**: Diferentemente de arrays, uma lista encadeada pode crescer ou diminuir conforme necessário, já que a memória é alocada dinamicamente.

### Desvantagens:

- **Acesso lento**: Para acessar um elemento em uma lista encadeada, você precisa percorrer a lista a partir da cabeça, o que leva tempo linear (O(n)). Arrays permitem acesso direto em tempo constante (O(1)).

### Operações implementadas:

- Impressão;
- Inserção;
- Remoção;
- Busca.

## Como Compilar e Executar
Para compilar:
```bash
g++ lista_dinamica.cpp -o lista_dinamica
```
Para executar:
```bash
./lista_dinamica
```
## :pushpin: Pilha (Stack)

<div align="center">
    <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTqJs7ubppRlFkErqG86-4B7bWLYb22rMTRLw&s" alt="Pilha" width="300"/>
</div>

Uma **pilha** (do inglês, **stack**) é uma estrutura de dados linear que segue o princípio **LIFO (Last In, First Out)**, ou seja, o último elemento a ser inserido é o primeiro a ser removido.

### Aplicações:

- Recursão;
- Avaliação e análise de expressões;
- Busca em profundidade (DFS);
- Operações de desfazer/refazer (Undo/Redo);
- Histórico do navegador;
- Chamadas de função;

### Operações implementadas:

- Empilhar (Push);
- Desempilhar (Pop);
- Verificar se está vazia (IsEmpty).

## Como Compilar e Executar

Para compilar:
```bash
g++ pilha.cpp -o pilha
```
```bash
./pilha
```
