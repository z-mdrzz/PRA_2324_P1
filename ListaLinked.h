//utiliza nodos (cadena de nodos)
#include <ostream>
#include "Lista.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListaLinked : public Lista<T>
{

private:
	Node<T> *first;//puntero al primer nodo
	int n;

public:
//inicializar first y n
	ListaLinked() override
	{
		first = nullptr;
		n = 0;
	}
//liberrar nodos "usados"
	~ListaLinked() override
	{
		for (int i = 0; i < n; i++)
		{
			Node<T> *aux = first->next;
			delete first;
			first = aux;
		}
	}
//operador[]-- devuelve el elemento en pos
	T operator[](int pos) override//empieza desde posicion 1, avanza pos veces
	{
		if (pos < 0 || pos >= n)
		{
			throw out_of_range("La posicion esta fuera del rango");
		}
		Node<T> *current = first;
		for (int i = 0; i < pos; i++)
		{
			current = current->next;//mover al siguiente nodo
		}
		return current->data;//devolver dato de esa posicion
	}
//imprimir la lista completa(lo q ha sacado el operador)
	friend ostream &operator<<(ostream &out, const ListLinked<T> &lista) {
    Node<T>* current = lista.first;// empezar del primero
    out << "[";// corchetes
    while (current != nullptr) {//mientras haya nodos
        out << current->data;//imprimir dato actual
        if (current->next != nullptr) out << ", ";
        current = current->next;//avanzar al siguiente
    }
    out << "]";
    return out;
}
	void insert(int pos, T e) override{// agregar un nuevo elemento en pos indicadada
		if(pos < 0 || pos > n) throw std::out_of_range("Posición fuera del rango de la array");
		if(pos == 0){//insertar al inicio
			Node<T>* aux = new Node<T>(e,first); 
			first = aux;
			n++;
		}
		else{//insertar en el medio/final
			Node<T>* prev = nullptr;
			Node<T>* aux = first;
			int i = 0;
			//buscar en q posicion
			while(aux != nullptr && i < pos){
				prev = aux;
				aux = aux -> next;
				i++;
			}
			if(i == pos){
				prev->next = new Node<T>(e,aux); 
				n++;
			}	
		}
	}
	void append(T e) override
	{
		insert(n, e);
	}
	void prepend(T e) override
	{
		insert(0, e);
	}
//insertar la funcion del examen capicua_lista
void capicua_list() override {
        if (n == 0) return;
        
        for (int i = n - 1; i >= 0; i--) {
            append(get(i));
        }
    }

	T remove(int pos) override
{
    if (pos < 0 || pos >= n) throw std::out_of_range("Posición fuera de rango");
    
    Node<T>* toDelete;
    T removed_value;
    
    if (pos == 0) {  //  Eliminar primer elemento
        toDelete = first;              //  Nodo a eliminar es el primero
        removed_value = first->data;   //  Guardar dato a devolver
        first = first->next;           // first ahora apunta al segundo nodo
    } 
    else {  //  Eliminar elemento intermedio o final
        Node<T>* prev = first;
        //  Buscar el nodo ANTERIOR al que queremos eliminar
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        toDelete = prev->next;         //  Nodo a eliminar
        removed_value = toDelete->data;//  Guardar dato
        prev->next = toDelete->next;   // + "Saltar" el nodo a eliminar
    }
    
    delete toDelete;  // Liberar memoria del nodo eliminado
    n--;             //  Actualizar contador
    return removed_value;  //  Devolver valor eliminado
}
	T get(int pos) override{// obtener elemento por posicion
		if(pos < 0 || pos >= n) throw std::out_of_range("Posición fuera del rango de la array");
		Node<T>* aux = first;
		for(int i= 0; i < pos; i++) aux = aux->next;
		return aux->data;
	}
	int search(T e) override {// buscar elemento
        Node<T>* aux = first;
		int i = 0;
		while(aux != nullptr && aux-> data != e){
			aux = aux-> next;
			i++;
		}
		if(aux != nullptr){ 
			return i;
		}else{ 
			return -1;
        }
	}
	bool empty() override
	{
		return n == 0;
	}
	int size() override
	{
		return n;
	}
};
