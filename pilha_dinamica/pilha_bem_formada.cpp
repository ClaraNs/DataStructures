#include <iostream>

using namespace std;

class Node
{
    public:
        // Construtor
        Node(char valor) : dado(valor), prox(nullptr) {}

        // Métodos
        char obterDado();
        Node* obterProximo();
        void setaProximo(Node *p);

    private:
        char dado;
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

        Pilha(char dado)
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
        void push(char valor);
        void pop();
        bool isEmpty();
        void imprimePilha();
        bool bemFormada(string str);
        char top();

    private:
        Node *inicio;
        int tamanho;
};

char Node::obterDado()
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

void Pilha::push(char valor) //O(1)
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

char Pilha::top(){
    if(!isEmpty())
        return inicio->obterDado();
    return '\0';
}

bool Pilha::bemFormada(string str){
    for(int i = 0; i < str.size(); i++){

        if(str[i] == ' ')
            continue;

        if(str[i] == '(' || str[i] == '{')
            push(str[i]);

        if(str[i] == ')'){
            if(top() ==  '(')
                pop();
            else
                return false;
        }

        if(str[i] == '}'){
            if(top() == '{')
                pop();
            else
                return false;
        }
    }

    return isEmpty();
}

int main()
{
    Pilha pilha;
    string seq;

    cout << "Entre com a sequência: ";
    //cin >> seq;
    getline(cin, seq);

    if(pilha.bemFormada(seq))
        cout << "Sequência correta." << endl;
    else
        cout << "Sequência INCORRETA." << endl;

    return 0;
}