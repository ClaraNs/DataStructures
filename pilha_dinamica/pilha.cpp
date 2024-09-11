#include <iostream>

using namespace std;

class Node
{
    public:
        // Construtor
        Node(int valor) : dado(valor), prox(nullptr) {}

        // Métodos
        int obterDado();
        Node* obterProximo();
        void setaProximo(Node *p);

    private:
        int dado;
        Node *prox;
};

class Pilha
{
    public:

        Pilha()
        {
            inicio = nullptr;
            tamanho = 0;
        }

        Pilha(int dado)
        {
            inicio = new Node(dado);
            tamanho++;
        }

        ~Pilha()
        {
            Node* atual = inicio;
            while (atual != nullptr) {
                Node* proximo = atual->obterProximo();
                delete atual;
                atual = proximo;
            }
        }

        // Métodos
        void push(int valor);
        void pop();
        bool isEmpty();
        void imprimePilha();

    private:
        Node *inicio;
        int tamanho;
};

int Node::obterDado()
{
    return dado;
}

Node *Node::obterProximo()
{
    return prox;
}

void Node::setaProximo(Node *p)
{
    prox = p;
}

bool Pilha::isEmpty(){
    if(inicio == nullptr)
        return true;
    return false;
}

void Pilha::push(int valor) //O(1)
{
    Node *novo = new Node(valor);
    novo->setaProximo(inicio);
    inicio = novo;
    tamanho++;
}

void Pilha::pop() //O(1)
{
    if(isEmpty())
        return;

    Node* aux = inicio;
    inicio = aux->obterProximo();
    delete(aux);
    tamanho--;
}

void Pilha::imprimePilha()
{   
    if (isEmpty())
    {
        cout << "Pilha vazia.\n";
        return;
    }
    
    Node *aux = inicio;

    cout << "\n";

    while (aux != nullptr)
    {
        cout << aux->obterDado() << "\n";
        aux = aux->obterProximo();
    }

    cout << "\nQuantidade de elemento(s):" << tamanho << "\n";
}

int main()
{
    Pilha pilha;

    int opcao, valor, posicao;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Inserir elemento na pilha\n";
        cout << "2. Remover elementon da pilha\n";
        cout << "3. Imprimir Pilha\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\nDigite o valor a inserir: ";
            cin >> valor;
            pilha.push(valor);
            pilha.imprimePilha();
            break;

        case 2:
            cout << "\nRemovido um elemento:";
            pilha.pop();
            pilha.imprimePilha();
            break;

        case 3:
            pilha.imprimePilha();
            break;

        case 4:
            cout << "\nSaindo...\n";
            break;

        default:
            cout << "\nOpção inválida!\n";
        }
    } while(opcao != 4);

    return 0;
}