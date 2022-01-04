#ifndef __COLA__
#define __COLA__
#include<cassert>
#include<iostream>
using namespace std;
template <typename TIPO>class cola{
	public:
		cola();									//Constructor basico
		cola(const cola<TIPO>&C);						//Constructor por copia
		cola<TIPO>& operator=(const cola<TIPO>&C);				//Sobrecarga de operador =
		bool vacia()const;							//Metodo que compruebe que la cola esta vacia
		void push(const TIPO&x);							//Metodo que pone un dato al final de la cola
		void pop();								//Metodo que quita un elemento del frente de la cola
		const TIPO& frente()const;						//Metodo que nos devuelve lo que haya al comienzo de la cola
		~cola();								//Destructor de la cola
	private:
		struct nodo{								//Estructura que conectara los distintos elementos de la cola
			TIPO elemento;							//El elelemento contenido en la n posicion de la cola
			nodo* siguiente;						//Puntero que apunta a el siguiente nodo de la lista
			nodo(const TIPO&x,nodo*p=nullptr):elemento(x),siguiente(p){};	//Constructor de los nodos
		};
		nodo* Final;								//Nodo que apunta al final de la cola
		void copiar(const cola<TIPO>&C);					//Metodo privado para copiar colas
};


//Metodos privados
template<typename TIPO>
void cola<TIPO>::copiar(const cola<TIPO>&C){
	if(!C.vacia()){
		Final=new nodo(C.frente());
		nodo* p=Final;
		nodo* q=C.Final->siguiente;
		q=q->siguiente;
		while(q!=C.Final){
			p->siguiente= new nodo(q->elemento);
			p=p->siguiente;
			q=q->siguiente;
		}
		p->siguiente=new nodo (q->elemento);
		p=p->siguiente;
		p->siguiente=Final;
		Final=p;
	}
}
//Metodos publicos
template <typename TIPO>
cola<TIPO>::cola():Final(nullptr){}

template <typename TIPO>
cola<TIPO>::cola(const cola<TIPO>&C){
	copiar(C);
}

template <typename TIPO>
cola<TIPO>& cola<TIPO>::operator=(const cola<TIPO>&C){
	if(this!=&C){
		this->~cola();
		copiar(C);
	}
	return *this;
}

template <typename TIPO>
bool cola<TIPO>::vacia()const{
	return(Final==nullptr);
}

template <typename TIPO>
void cola<TIPO>::push(const TIPO&x){
	if(Final!=nullptr){
		nodo*q=new nodo(x,Final->siguiente);
		Final->siguiente=q;
		Final=q;
	}
	else{
		Final=new nodo(x);
		nodo*q=Final;
		Final->siguiente=q;
	}
}

template <typename TIPO>
void cola<TIPO>::pop(){
	assert(!vacia());
	if(Final!=Final->siguiente){
		nodo*q=Final->siguiente;
		Final->siguiente=q->siguiente;
		delete q;
	}
	else{	
		nodo*q= Final->siguiente;
		delete q;
		Final=nullptr;

	}
}

template <typename TIPO>
const TIPO& cola<TIPO>::frente()const{
	nodo *q=Final->siguiente;
	return(q->elemento);
}

template <typename TIPO>
cola<TIPO>::~cola(){
	if(Final!=nullptr){
		nodo*q=Final;
		nodo*p=Final->siguiente;
		while(q!=p){
			delete Final;
			Final=p;
			p=Final->siguiente;
		}
	delete Final;
	}
}
#endif


