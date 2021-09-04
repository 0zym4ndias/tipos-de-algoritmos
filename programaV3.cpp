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


//  Librerias 
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

//  Complejidad - Peor caso: O(log n) y Mejor caso: O(1)
int buscaBinaria(vector<int> &vec, int datoBusca, int &comp){ //  Busqueda binaria, relacionada con posBusBinaria (vec, datoBusca, cantCompBB)
	comp = 0;
	int inicio = 0, fin = vec.size()-1, mitad;
	while(inicio <= fin){
		mitad = (inicio + fin)/2;
		comp++;
		if(vec[mitad] == datoBusca){ //  Si vector en la posición mitad es = al dato que busco ya se encontró
			return mitad; //  Se regresa la mitad 
		}
		if(vec[mitad] > datoBusca){ //  Si el vector en la posición mitad es mayor al dato que busco, quiere decir que el dato que busco está a la izquierda
			fin = mitad-1;
		}
		else{ //  Si el vector en la posición mitad es menor al dato que busco, quiere decir que el dato que busco está a la derecha
			inicio = mitad+1;
		}
	}
	return -1; //  Cuando salga del while se regresa -1
}

/*
PARA EL ORDEN DESCENDENTE 
//  Complejidad - Peor caso: O(log n) y Mejor caso: O(1)
scaBinaria(vector<int> &vec, int datoBusca, int &comp){ //  Busqueda binaria, relacionada con posBusBinaria (vec, datoBusca, cantCompBB)
	comp = 0;
	int inicio = 0, fin = vec.size()-1, mitad;
	while(inicio <= fin){
		mitad = (inicio + fin)/2;
		comp++;
		if(vec[mitad] == datoBusca){ //  Si vector en la posición mitad es = al dato que busco ya se encontró
			return mitad; //  Se regresa la mitad 
		}
		if(vec[mitad] > datoBusca){ //  Si el vector en la posición mitad es mayor al dato que busco, quiere decir que el dato que busco está a la derecha
			inicio = mitad+1;
		}
		else{ //  Si el vector en la posición mitad es menor al dato que busco, quiere decir que el dato que busco está a la izquierda
			fin = mitad-1;

		}
	}
	return -1; //  Cuando salga del while se regresa -1
}
*/

//  Complejidad - O(n^2)
int sortIntercambio(vector<int> &vec){
	int comp = 0, temporal;
	for(int i = 0; i < vec.size()-1; i++){ //  Mientras la i sea menor a vector.size -1 
		for(int j = i + 1; j<vec.size(); j++) { //  i = izquierda -- j = derecha
			comp++; //  Medir las comparaciones 
			if(vec[i] > vec[j]){ //  Si el vector en la posición i es mayor que el vector en la posición j 
				temporal = vec[i];
				vec[i] = vec[j];
				vec[j] = temporal; 
			} 
		}
	} 
	return comp;
}

//  Complejidad - Peor caso: O(n^2) y Mejor caso: O(n)
int sortBurbuja(vector<int> &vec){
	bool interruptor = true;
	int comp = 0, temporal;
	for(int pasada = 0; pasada < vec.size() && interruptor; pasada++){
		interruptor = false;
		for(int j = 0; j < vec.size()-1-pasada; j++){
			comp++;
			if(vec[j+1] < vec[j]){
				temporal = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temporal;
				interruptor = true;
			}
		}
	}
	return comp;
}

//  Complejidad: O(n^2)
int sortSeleccion(vector<int> &vec){
	int indiceMenor, temporal, comparacion = 0;
	for(int i = 0; i < vec.size()-1; i++){ //  Tenemos n-1 pasadas 
		indiceMenor = i;
		for(int j = i+1; j < vec.size(); j++){
			comparacion++;
			if(vec[j] < vec[indiceMenor]){ //  Si el vector en la posicion j es menor a vec en el indice menor 
				indiceMenor = j; //  El nuevo indice menor es igual a j 
			}
		}
		if(i != indiceMenor){
			temporal = vec[i]; //  Temporal en la posición i 
			vec[i] = vec[indiceMenor];
			vec[indiceMenor] = temporal;
		}
	}
	return comparacion; //  Se regresan las comparaciones 
}

//  Complejidad: Peor caso: O(n^2) y Mejor caso: O(n)
int sortInsercion(vector<int> &vec){
	int temporal, comparacion = 0;
	for(int i = 1; i < vec.size(); i++){
		int j = i;
		temporal = vec[j];
		while(j > 0 && temporal < vec[j-1]){ //  Mientras la j sea mayor que 0 && el temporal sea menor que el vector en la posicion j-1
			comparacion++;
			vec[j] = vec[j-1]; //  Se realiza el corrimiento  
			j--;
		}
		if(j > 0){ //  Si j es mayor a 0 
			comparacion++; //  Se agrega una comparación más 
		}
		vec[j] = temporal;
	}
	return comparacion; 
}

void une(vector<int> &vec, int inicio, int mitad, int fin, int &comp){
	vector<int> aux(vec.size());
	int i = inicio, j = mitad + 1, k = inicio;
	while(i <= mitad && j <= fin){
		comp++;
		if(vec[i] < vec[j]){ //  Comparacion 
			aux[k++] = vec[i++];
		}
		else{
			aux[k++] = vec[j++];
		}
	}

	if(i > mitad){ //  Se acabo el lado izquierdo y se tiene que seguir traspasando el lado derecho 
		for(int a = j; a <= fin; a++){
			aux[k++] = vec[a];
		}
	}
	else{ //  Se acabó el lado derecho y se tiene que seguir traspasando el lado izquierdo 
		for(int a = i; a <= mitad; a++){
			aux[k++] = vec[a];
		}
	}
	for(int a = inicio; a <= fin; a++){
		vec[a] = aux[a];
	}
}

//  Complejidad - Peor caso: O(n log n) y Mejor caso: O(n log n)
void mergeSort(vector<int> &vec, int inicio, int fin, int &comp){
	if(inicio < fin){
		int mitad = (inicio + fin)/2;
		mergeSort(vec, inicio, mitad, comp);
		mergeSort(vec, mitad+1, fin, comp);
		une(vec, inicio, mitad, fin, comp); //  Se hacen las comparaciones 
		
	}
}

//  Complejidad de O(n)
void particion(vector<int> &vec, int inicio, int fin, int &pivote, int &comp)
{
    int elempivote = vec[inicio];
    int j = inicio; // Esta es la última posicion de los menores
    int aux;
    for (int i = inicio + 1; i <= fin; i++)
    {
        comp++;
        if (vec[i] < elempivote)
        {
            j++;
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
        }
    }
    pivote = j; //  Se posiciona al pivote en la posicion final
    aux = vec[pivote];
    vec[pivote] = vec[inicio];
    vec[inicio] = aux;
}

//  Complejidad - Peor Caso: O(n^2) y Mejor caso: O(nlogn)
void quickSort(vector<int> &vec, int inicio, int fin, int &comp)
{
    if (inicio < fin)
    {
        int pivote;
        particion(vec, inicio, fin, pivote, comp);
        quickSort(vec, inicio, pivote-1, comp); //  Se mandan a los menores al pivote
        quickSort(vec, pivote+1, fin, comp); //  Se mandan a los mayores al pivote
    }
}

int main(){
	int n, dato, datoBusca;
	cin >> n;
	//  Vector 1 ==> Ordenar con Intercambio
	//  Vector 2 ==> Ordenar con Burbuja
	//  Vector 3 ==> Ordenar con Selección Menor 
	//  Vector 4 ==> Ordenar con Inserción
	//  Vector 5 ==> Ordenar con Merge Sort
	//  Vector 6 ==> Ordenar con Quick Sort 
	vector <int> vec1, vec2, vec3, vec4, vec5, vec6; //  Construiste el vector con 0 casillas 
	for(int i = 0; i < n; i++){
		cin >> dato;
		vec1.push_back(dato); //  Va empujando al final una nueva casilla 
		vec2.push_back(dato); //  Va empujando al final una nueva casilla 
		vec3.push_back(dato); //  Va empujando al final una nueva casilla 
		vec4.push_back(dato); //  Va empujando al final una nueva casilla 
		vec5.push_back(dato); //  Va empujando al final una nueva casilla 
		vec6.push_back(dato); //  Va empujando al final una nueva casilla 
	}

/*  vector<int> vec(n); //  Construiste un vector con n casillas 
	for(int i = 0; i < n; i++){
		cin >> vec[i];
	}
	*/
	cout << "==================" << endl;
	cout << "Datos Originales: ";
	print(vec1); //  Te imprime los datos originales que el usuario ingresa 
	cout << "==================" << endl;
	cin >> datoBusca;
	int posBusSecuencial = BuscaSecuencial(vec1, datoBusca); //  Posicion busqueda secuencial, va a buscar el numero que el usuario ponga
	//  Cantidad de comparaciones en la busqueda secuencial 
	//  Si posicion de busqueda secuencial es = -1 entonces (?) se imprime el size del vector, si no (:) se imprimen las posiciones que se hicieron 
	int cantCompBS = (posBusSecuencial == -1 ? vec1.size() : posBusSecuencial + 1);
	cout << "Posición de busqueda secuencial:                  " << posBusSecuencial << endl; //  Se imprime la posicion de busqueda secuencial (index)
	cout << "Cantidad de comparaciones en busqueda secuencial: " << cantCompBS << endl; //  Se imprime la cantidad de comparaciones en busqueda secuencial 
	cout << "==================" << endl;
	cout << "Datos ordenados Intercambio: ";
	int compIntercambio = sortIntercambio(vec1); //  Comparacion del intercambio - Sort del intercambio 
	print(vec1); //  Se imprime el vector 1 ya ordenado 
	cout << "Comparaciones intercambio: " << compIntercambio << endl; //  Se muestra el numero de comparaciones con el metodo intercambio
	cout << "==================" << endl;
	cout << "Datos ordenados Burbuja: ";
	int compBurbuja = sortBurbuja(vec2); //  Comparacion burbuja - Sort burbuja
	print(vec2); //  Se imprime el vector 2 ya ordenado 
	cout << "Comparaciones burbuja: " << compBurbuja << endl; //  Se muestra el numero de comparaciones con el metodo burbuja 
	cout << "==================" << endl;
	cout << "Datos ordenados Seleccion Menor: ";
	int compSeleccion = sortSeleccion(vec3); //  Comparacion selección menor - Sort selección menor
	print(vec3); //  Se imprime el vector 3 ya ordenado 
	cout << "Comparaciones Seleccion Menor: " << compSeleccion << endl; //  Se muestra el numero de comparaciones con el metodo selección menor  
	cout << "==================" << endl;
	cout << "Datos ordenados Insercion: ";
	int compInsercion = sortInsercion(vec4); //  Comparacion insercion - Sort insercion
	print(vec4); //  Se imprime el vector 3 ya ordenado 
	cout << "Comparaciones Insercion: " << compInsercion << endl; //  Se muestra el numero de comparaciones con el metodo insercion 
	cout << "==================" << endl;
	cout << "Datos ordenados Merge Sort: ";
	int compMerge = 0; //  Comparación de merge 
	mergeSort(vec5, 0, n-1,  compMerge); //  Merge sort con parametros vec y comparacion de merge 
	print(vec5); //  Se imprime el vector 5 ya ordenado 
	cout << "Comparaciones Merge Sort: " << compMerge << endl; //  Se muestra el numero de comparaciones con el metodo merge sort
	cout << "==================" << endl;
    cout << "Datos Ordenados Quick:  ";
    int compQuick = 0;
	quickSort(vec6, 0, n-1, compQuick);
	print(vec6);
	cout << "Comparaciones Quick Sort: " << compQuick<< endl;
//	sort(vec.begin(), vec.end()); //  Se ordenan los numeros desde el vector en inicio hasta vector del fin - todos los numeros ascendentemente
//	print(vec); //  Se imprime el vector ahora de forma ordenada 
	int cantCompBB; //  Cantidad de comparaciones de la busqueda binaria 
	int posBusBinaria = buscaBinaria(vec1, datoBusca, cantCompBB); //  Posición de busqueda binaria - busqueda binaria 
	cout << "==================" << endl;
	cout << "Posición de busqueda binaria:                  " << posBusBinaria << endl; //  Se imprime la posicion de busqueda secuencial (index)
	cout << "Cantidad de comparaciones en busqueda binaria: " << cantCompBB << endl; //  Se imprime la cantidad de comparaciones en busqueda secuencial 
	cout << "==================" << endl;
/*	cout << "Datos ordenados descendentemente: ";
	sort(vec.begin(), vec.end(), greater<int>()); //  Se ordenan los numeros desde el vector en inicio hasta vector del fin - todos los numeros descendentemente 
	print(vec); //  Se imprime el vector ahora de forma ordenada 
	cout << "==================" << endl;
*/

}