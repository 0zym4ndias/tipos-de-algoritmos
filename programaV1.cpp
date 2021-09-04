//
//
//
//  Clase del Ing. Luis Humberto González Guerra
//  Roberto A. Pérez Iga - Estudiante de Tecnologías Computacionales
//  Tecnológico de Monterrey
//  Programación de Estructura de Datos y Algorítmos Fundamentales 
//
//
//

#include <iostream>
#include <vector>

using namespace std;


//  Complejidad O(n)
void print(vector<int> &vec){ //  &vec es importante para evitar utilizar una copia del vector, solo el original 
	for(int i = 0; i < vec.size(); i++){ //  Va a imprimir todo el size de el vector (sus datos)
		cout << vec[i] << " ";
	}
	cout << endl;
}

//  Complejidad - Peor Caso: O(n) y Mejor caso: O(1)
int BuscaSecuencial(vector<int> &vec, int datoBusca){ //  Busqueda secuencial, relacionada con posBusSecuencial 
	for(int i = 0; i < vec.size(); i++){ 
		if(vec[i] == datoBusca){ //  Si se encuentra el dato que el usuario quiere
			return i; //  Se regresa ese número
		}
	}
	return -1; //  Si no se encuentra ese número, se regresa un -1 en su lugar 
}

int main(){
	int n, dato, datoBusca;
	cin >> n;
/*	vector <int> vec //  Construiste el vector con 0 casillas 
	if(int i = 0; i < n; i++){
		cin >> dato;
		vec.push_back(dato); //  Va empujando al final una nueva casilla 
	}
	*/
	vector<int> vec(n); //  Construiste un vector con n casillas 
	for(int i = 0; i < n; i++){
		cin >> vec[i];
	}
	cout << "==================" << endl;
	cout << "Datos Originales: ";
	print(vec); //  Se imprimen los datos originales que el usuario ingresa 
	cout << "==================" << endl;
	cin >> datoBusca;
	int posBusSecuencial = BuscaSecuencial(vec, datoBusca); //  Posicion busqueda secuencial, va a buscar el numero que el usuario ponga
	//  Cantidad de comparaciones en la busqueda secuencial 
	//  Si posicion de busqueda secuencial es = -1 entonces (?) se imprime el size del vector, si no (:) se imprimen las posiciones que se hicieron 
	int cantCompBS = (posBusSecuencial == -1 ? vec.size() : posBusSecuencial + 1);
	cout << "Posición de busqueda secuencial:                  " << posBusSecuencial << endl; //  Se imprime la posicion de busqueda secuencial (index)
	cout << "Cantidad de comparaciones en busqueda secuencial: " << cantCompBS << endl; //  Se imprime la cantidad de comparaciones en busqueda secuencial 
	cout << "==================" << endl;
	cout << "Datos ordenados ascendentemente: ";
	sort(vec.begin(), vec.end()); //  Se ordenan los numeros desde el vector en inicio hasta vector del fin - todos los numeros 
	print(vec); //  Se imprime el vector ahora de forma ordenada 
	cout << "==================" << endl;
	cout << "Datos ordenados descendentemente: ";
	sort(vec.begin(), vec.end(), greater<int>()); //  Se ordenan los numeros desde el vector en inicio hasta vector del fin - todos los numeros descendentemente 
	print(vec); //  Se imprime el vector ahora de forma ordenada 
	cout << "==================" << endl;

}