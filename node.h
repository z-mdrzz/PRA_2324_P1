//construye listas enlazadas, cada nodo tiene (T,puntero siguiente)
#include <ostream>
using namespace std;
template <typename T> 
class Node {
    public:
	//atributos
        T data;
	Node<T>* next;// puntero al suiguiente nodo
// constructor
Node(T data, Node<T> next=nullptr){
		this->data = data;// guarda en data y lo enlaza con el nodo
		this->next = next;
	}
//impresor
	friend ostream& operator<<(std::ostream &out, const Node<T> &node){
		out << node.data;//solo el dato
		return out;
	}
    
};
