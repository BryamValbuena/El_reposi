#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu();
void insertar_lista(Nodo *&,int);
void mostrar_lista(Nodo*);
void buscar_lista(Nodo*, int);
void eliminar_nodo(Nodo *&,int);

Nodo *lista = NULL;


int main (){

	menu();
	
	getch();
	return 0;
}

void menu(){
	int opcion,dato;
	do{
		cout<<"\t--menu--\n";
		cout<<"1. Insertar elementos a la lista\n";
		cout<<"2. Mostrar los elemnentos de la lista\n";
		cout<<"3. Buscar un elemento \n";
		cout<<"4. Eliminar nodo de la lista\n";
		cout<<"5. Salir\n";		
		cout<<"opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nPon un numero: ";
	                cin>>dato;
	                insertar_lista(lista,dato); 
	                cout<<"\n";
	                system("pause");
					break;
			case 2: mostrar_lista(lista);
			        cout<<"\n";
	                system("pause");
                    break;
            case 3: cout<<"\nPon un nuemero para buscarlo: ";
                    cin>>dato;
                    buscar_lista(lista,dato);
                    cout<<"\n";
                    system("pause");
                    break;
            case 4: cout<<"\nPon un nuemero para eliminarlo: ";
                    cin>>dato;
                    eliminar_nodo(lista,dato);
                    cout<<"\n";
                    system("pause");
                    break;
                    
		}
		system("cls");
	}while(opcion != 5);
}

void insertar_lista(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	Nodo *aux1 = lista;
	Nodo *aux2;

while((aux1 != NULL)&&(aux1->dato < n)){
	aux2 = aux1;
	aux1 = aux1->siguiente;
}

if (lista == aux1){
	lista = nuevo_nodo;
}
else{
	aux2->siguiente = nuevo_nodo;
}

nuevo_nodo->siguiente = aux1;

cout<<"\tElemento "<<n<<" Insertado a la lista a la perfe\n";
}

void mostrar_lista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<actual->dato<<" -> ";
		actual = actual ->siguiente;
	}
}

void buscar_lista(Nodo *lista,int n){
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual != NULL) && (actual->dato <=n)){
		if(actual->dato==n){
			band = true;
		}
		actual = actual->siguiente;
	}
	if (band == true){
		cout<<"ELemento "<<n<<" Si a sido encontrado en lista\n";
	}
	else{
		cout<<"ELemento "<<n<<" No a sido encontrado en lista\n";
	}
}
	

void eliminar_nodo(Nodo *&lista,int n){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		while ((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		else if (anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		}
		else{
			anterior ->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
			
		}
		
	}
}
	
	
	
	

