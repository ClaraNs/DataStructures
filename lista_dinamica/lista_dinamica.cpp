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

class listaEncadeada
{
    public:

        listaEncadeada()
        {
            inicio = nullptr;
            final = nullptr;
        }

        listaEncadeada(int dado)
        {
            inicio = new Node(dado);
            final = inicio;
        }

        ~listaEncadeada()
        {
            Node* atual = inicio;
            while (atual != nullptr) {
                Node* proximo = atual->obterProximo();
                delete atual;
                atual = proximo;
            }
        }

        // Métodos
        void insereInicio(int valor);
        void insereFim(int valor);
        void insereOrdenado(int valor);
        void removeInicio();
        void removeFim();
        void removePos(int posicao);
        void removeValor(int valor);
        int buscaElemento(int valor);
        void imprimeLista();

    private:
        Node *inicio;
        Node *final;
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

void listaEncadeada::insereInicio(int valor) //O(1)
{
    Node *novo = new Node(valor);
    novo->setaProximo(inicio);
    inicio = novo;

    if (novo->obterProximo() == nullptr)
        final = novo;
}

void listaEncadeada::insereFim(int valor) //O(1)
{
    Node *novo = new Node(valor); // prox já é setado como nulo

    if (final == nullptr)
    {
        inicio = novo;
    }
    else
    {
        Node *anterior = final;
        anterior->setaProximo(novo);
    }

    final = novo;
}

void listaEncadeada::insereOrdenado(int valor) //O(n)
{
    Node *aux = inicio;
    Node *ant = nullptr;

    while (aux != nullptr && aux->obterDado() < valor)
    {
        ant = aux;
        aux = aux->obterProximo();
    }

    if (ant == nullptr)
        insereInicio(valor);
    else if (aux == nullptr)
        insereFim(valor);
    else
    {
        Node *novo = new Node(valor);
        ant->setaProximo(novo);
        novo->setaProximo(aux);
    }
}

void listaEncadeada::removeInicio() //O(1)
{
    if(inicio == nullptr)
        return;

    Node* aux = inicio;
    inicio = aux->obterProximo();

    if(aux->obterProximo() == nullptr) //era o único elemento
        final = nullptr;

    delete(aux);
}

void listaEncadeada::removeFim() //O(n)
{
    if(inicio == nullptr)
        return;
    if(inicio->obterProximo() == nullptr){
        removeInicio();
        return;
    }

    Node *atual = inicio;

    // Encontra o anterior
    while(atual->obterProximo() != final){
        atual = atual->obterProximo();
    }
        
    delete(final);
    //cout << "novo fim: " << atual->obterDado() << "\n";
    final = atual;
    atual->setaProximo(nullptr);

}

void listaEncadeada::removeValor(int valor) //O(n)
{
    if(inicio == nullptr)
        return;

    Node* aux = inicio;
    Node* anterior = nullptr;

    while(aux != nullptr && aux->obterDado() != valor){
        anterior = aux;
        aux = aux->obterProximo();
    }

    if(aux == nullptr){
        cout << valor << "\nValor não encontrado na lista.\n";
        return;
    }

    if(anterior == nullptr){
        removeInicio();
        return;
    }

    anterior->setaProximo(aux->obterProximo());
    
    if(final == aux)
        final = anterior;
    
    delete (aux);
}

void listaEncadeada::removePos(int posicao)
{
    if(inicio == nullptr){
        cout << "Lista vazia.\n";
        return;
    }

    Node* anterior = nullptr;
    Node* aux = inicio;
    int cnt = 0;

    while(aux != nullptr && cnt < posicao){
        anterior = aux;
        aux = aux->obterProximo();
        cnt++;
    }

    if(aux == nullptr){
       cout << "Essa posição não existe na lista.\n"; 
       return;
    }
    
    if(aux == inicio){
        removeInicio();
        return;
    }

    if(aux == final){
        removeFim();
        return;
    }

    anterior->setaProximo(aux->obterProximo());
    delete(aux);
}

// Retorna a posição do elemento na lista
int listaEncadeada::buscaElemento(int valor)
{
    Node* aux = inicio;
    int cnt = 0;

    while(aux != nullptr && aux->obterDado() != valor){
        aux = aux->obterProximo();
        cnt++;
    }

    if(aux == nullptr)
        return -1;
    return cnt;
}

void listaEncadeada::imprimeLista()
{
    Node *aux = inicio;

    while (aux != nullptr)
    {
        cout << aux->obterDado() << " -> ";
        aux = aux->obterProximo();
    }

    cout << "null\n";
}

int main()
{
    listaEncadeada lista;

    int opcao, valor, posicao;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Inserir no início\n";
        cout << "2. Inserir no final\n";
        cout << "3. Inserir ordenado\n";
        cout << "4. Remover do início\n";
        cout << "5. Remover do final\n";
        cout << "6. Remover valor específico\n";
        cout << "7. Remover na posição\n";
        cout << "8. Buscar elemento\n";
        cout << "9. Imprimir lista\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor para inserir no início: ";
            cin >> valor;
            lista.insereInicio(valor);
            lista.imprimeLista();
            break;

        case 2:
            cout << "Digite o valor para inserir no final: ";
            cin >> valor;
            lista.insereFim(valor);
            lista.imprimeLista();
            break;

        case 3:
            cout << "Digite o valor para inserir ordenado: ";
            cin >> valor;
            lista.insereOrdenado(valor);
            lista.imprimeLista();
            break;

        case 4:
            lista.removeInicio();
            cout << "Lista após remover do início: ";
            lista.imprimeLista();
            break;

        case 5:
            lista.removeFim();
            cout << "Lista após remover do final: ";
            lista.imprimeLista();
            break;

        case 6:
            cout << "Digite o valor para remover: ";
            cin >> valor;
            lista.removeValor(valor);
            lista.imprimeLista();
            break;

        case 7:
            cout << "Digite a posição para remover: ";
            cin >> posicao;
            lista.removePos(posicao);
            lista.imprimeLista();
            break;

        case 8:
            cout << "Digite o valor para buscar: ";
            cin >> valor;
            posicao = lista.buscaElemento(valor);
            if (posicao != -1)
            {
                cout << "Elemento encontrado na posição: " << posicao << "\n";
                lista.imprimeLista();
            }
            else
                cout << "Elemento não encontrado na lista.\n";
            break;

        case 9:
            lista.imprimeLista();
            break;

        case 0:
            cout << "Saindo...\n";
            break;

        default:
            cout << "Opção inválida!\n";
        }
    } while(opcao != 0);

    return 0;
}