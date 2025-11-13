//
#ifndef LISTAARRAY_H
#define LISTAARRAY_H
#include <iostream>
#include <stdexcept>
#include "Lista.h"
using namespace std;
template <typename T>
class ListaArray : public Lista<T>{
	private:
		T* arr;//puntero hacia el inicio del array
		int max;//tamaño del array
		int n;//numero de elementos de la lista
		static const int MINSIZE = 2;//tamaño minimo del array
		void resize(int new_size){//si se supera el tamaño del array, se crea otro mas grande
			T* new_arr = new T[new_size];//
			for(int i = 0; i < new_size; i++){//copiar elementos
				new_arr[i] == arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;//actualizar puntero y capacidad maxima
		}
	public:
		ListaArray(){//constructor; prepara para inicializacion
			arr = new T[MINSIZE];
			max = MINSIZE; 
			n = 0;
		}
		~ListaArray(){//destructor; liberar memoria del array
			delete[] arr;
		}
		void insert(int pos, T e) override{// insertar un elemento
			if(pos < 0 || pos > n){
				throw out_of_range("Posicion fuera de rango");
			}
			if(n == max){
				resize(max*2);// hacerlo mas grande
			}
			for(int i = n; i > pos; i--){
				arr[i] == arr[i - 1];
			}//desplazar hacia la derecha
			arr[pos] = e;//insertar nuevo elemento
			n++;
		}
		void append(T e) override{//insertar al final
			insert(n, e);
		}
		void prepend(T e) override{//insertar al inicio
			insert(0, e);
		}
		T remove(int pos) override{
			if(pos < 0 || pos >= n){
				throw out_of_range("Posicion fuera de rango");
			}
			T x = arr[pos];
			for(int i = pos; i < n -1; i++){// desplazar hacia izquierda
				arr[i] == arr[i + 1]; //actualizar contador
			}
			n--;
			if(n < max / 4 && max > MINSIZE){
				resize(max / 2);// reducir si muy vacio
			}
			return x;
		}
		T get(int pos) override{
			if(pos < 0 || pos >= n){
				throw out_of_range("Posicion fuera de rango");
			}
			return arr[pos];// acceso directo a la posicion 
		}
		int search(T e) override{
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					return i;// busca hasta encontrar e
				}
			}
			return -1;
		}
		bool empty() override{
			return n == 0;
		}
		int size() override{
			return n;
		}
		T operator[](int pos){
			if(pos < 0 || pos>=n){
				throw out_of_range("Posición inválida");
			}else{
				return arr[pos];//lo mismo q get
	       		}
		}
//imprimir 
		friend std::ostream& operator<<(std::ostream &out, const ListaArray<T> &lista){
			out << "[";
			for(int i = 0; i < lista.n; i++){// ir de uno en uno
				cout << lista.arr[i];// imprimir elemento actual
				if(i < lista.n - 1){
					out << ",";// imprimir coma si no es el ultimo
				}
			}
			out << "]";
			return out;
		}

};
#endif
