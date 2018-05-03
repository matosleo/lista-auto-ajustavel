//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = new Node<string>();
    this->tail = new Node<string>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

LinkedList::~LinkedList()
{
    Node<string>* n = this->head;
    
    while(n != this->tail)
    {
        Node<string>* toDestroy = n;
        
        n = n->getNext();
        
        delete toDestroy;
    }
    
    delete this->tail;
}

Node<string>* LinkedList::getHead(void)
{
    return this->head;
}

Node<string>* LinkedList::getTail(void)
{
    return this->tail;
}

int LinkedList::getQuantity(void)
{
    return this->quantity;
}

bool LinkedList::isEmpty(void)
{
    return this->quantity == 0;
}

string LinkedList::get(int i)
{
    if( i < 1 || i > this->getQuantity())
    {
        throw invalid_argument("Valor do índice de busca deve estar entre [1, quantity].");
    }
    
    int counter = 1;
    
    string result;
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        if( i == counter )
        {
            result = n->getValue();
            break;
        }
        counter++;
    }
    
    return result;
}

int LinkedList::search(string s)
{
    return -1;
}

void LinkedList::print(void)
{
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        std::cout << n->getValue() << " ";
    }
    std::cout << std::endl;
}

ListStatus LinkedList::checkConsistency()
{
    if( this->head == NULL )
    {
        return HeadNull;
    }
    else if( this->head->getNext() == NULL )
    {
        return HeadNextNull;
    }
    else if( this->head->getNext()->getPrevious() != this->head )
    {
        return IncorrectLink;
    }
    else if( this->head->getPrevious() != NULL )
    {
        return HeadPrevious;
    }
    
    if( this->tail == NULL )
    {
        return TailNull;
    }
    else if( this->tail->getPrevious() == NULL )
    {
        return TailPreviousNull;
    }
    else if( this->tail->getPrevious()->getNext() != this->tail )
    {
        return IncorrectLink;
    }
    else if( this->tail->getNext() != NULL )
    {
        return TailNext;
    }
    
    if(this->isEmpty())
    {
        if( this->head->getNext() != this->tail )
        {
            return HeadTail;
        }
        
        if( this->head != this->tail->getPrevious() )
        {
            return HeadTail;
        }
    }
    else
    {
        // Verifica encadeamento dos elementos
        for(Node<string>* i = this->head->getNext(); i != this->tail; i=i->getNext())
        {
            if( i->getNext()->getPrevious() != i )
            {
                return IncorrectLink;
            }
            if( i->getPrevious()->getNext() != i )
            {
                return IncorrectLink;
            }
        }
    }
    
    return OK;
}

bool LinkedList::insertEnd(string s)
{
    Node<string>* n = new Node<string>(s);

    n->setNext( this->getTail() );
    n->setPrevious( this->getTail()->getPrevious() );

    n->getPrevious()->setNext( n );
    n->getNext()->setPrevious( n );

    ++this->quantity;

    return true;
}

/**
    Este método pode assumir que a lista está previamente ordenada em ordem crescente do conteúdo do nó.

    Este método deve inserir um novo nó com conteúdo (string) 's' na lista, mantendo sua ordenação.
*/
bool LinkedList::insertOrdered(string s)
{
    Node<string> *aux = this->getHead()->getNext();
    while(aux != this->getTail() && aux->getValue() < s)
    {
        aux = aux->getNext();
    }
    Node<string> *n = new Node<string>(s);
    n->setNext(aux);
    n->setPrevious(aux->getPrevious());
    n->getNext()->setPrevious(n);
    n->getPrevious()->setNext(n);
    this->quantity++;
    return true;

}

/**
    Este método pode assumir que a lista está previamente ordenada em ordem decrescente do contador de frequência (atributo 'count' do Node).

    Este método deve buscar o novo nó com conteúdo igual a (string) 's' na lista, incrementando o contador de frequência e mantendo sua ordenação.
*/
Node<string>* LinkedList::searchCF(string s)
{
	std::cout << "\tERRO: LinkedList::searchCF - not yet implemented.\n";
    std::exit(-1);
}

/**
    Este método deve buscar o novo nó com conteúdo (string) 's' na lista, movendo-o para a primeira posição da lista.
*/
Node<string>* LinkedList::searchMF(string s)
{
	std::cout << "\tERRO: LinkedList::searchMF - not yet implemented.\n";
    std::exit(-1);
}
