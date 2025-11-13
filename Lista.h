// todas las listas deben de seguir esta (punto de unificacion)
#ifndef LISTA_H
#define LISTA_H

template <typename T> 
class List {
    public:
	    void insert(int pos, T e);//inserta (e) en posicion especifica
	    void append(T e);//inserta al final una e
            void prepend(T e);//inserta al inicio
	    T remove(int pos);//elimina y devuelve elemento
	    T get(int pos);//obtiene elemento (e)
	    int search(T e);//busca elemento (e)
	    bool empty();//verifica si esta vacia
	    int size();//tamaño de (e)
//funncion capicua_list examen practica
virtual void capicua_list() = 0;
};
#endif
