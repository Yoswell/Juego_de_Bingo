#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include<iomanip> //Para setw (fijar elementos de las matrizes)
#include<ctime>
#include<stdexcept>
#include<sstream>
using namespace std;
const int F = 9; //Constante
const int C = 7; //Constante
const int tam = 12; //Constante para tamaño de los vectores pares e impares
const int tamano = 48; //Constantes para tamaño del vector principal

/*---- Prototipos de Funciones -----*/
int GNumAleatorio( int min, int max ); //Generar numeros aleatorios
int GNumPar( int min, int max );
int GNumImpar( int min, int max );
int CerosTabla( int Tabla[F][C] ); //Contador de ceros
int CerosTabla2( int Tabla2[F][C] ); //Contador de ceros
int Tabla2[F][C] = {{0}}; //Definimos matriz del segundo jugador
void JugadorEnCurso( int Jugador ); //Esta funcion lleva el control de que jugador esta en turno
void ImpTabla2( int Tabla2[F][C], int i, int j );
void DiferenciaJugador1( int Tabla[F][C] );
void DiferenciaJugador2( int Tabla[F][C] );
void LlenarCarton2( int Tabla2[F][C], int F, int C, int s, int i, int j, int ArrayPar[], int ArrayImpar[], int ArrayMayor[] );
void LlenarCarton( int Tabla[F][C], int F, int C, int s, int i, int j, int ArrayPar[], int ArrayImpar[], int ArrayMayor[], int min, int max );
void ImpTabla( int Tabla[F][C], int i, int j );
void Ranking ( string Jugador1, string Jugador2, int Puntos_Jugador1, int Puntos_Jugador2 ); //Funcion para el ganador
bool TurnoJugador1 = true; bool TurnoJugador2 = false; bool CambiarTurno();

int main(){
    srand(time(NULL));
        int Puntos_Jugador1 = 0, Puntos_Jugador2 = 0, Turno1 = 1, Turno2 = 1, j = 0, s = 0, min = 1, max = 13;
        int i; int op;
        string Jugador1, Jugador2;
        int Tabla[F][C]; int ArrayPar[tam]; int ArrayImpar[tam]; int ArrayMayor[tamano]; int Libre[tamano]; int Desordenado[tamano];
    LlenarCarton( Tabla, F, C, i, j, s, ArrayPar, ArrayImpar, ArrayMayor, min, max );
    LlenarCarton2( Tabla2, F, C, i, j, s, ArrayPar, ArrayImpar, ArrayMayor );

bool continuar = true;
    do{ //Aquí solamente pedimos los datos de ambos jugadores y les damos la bienvenida.
        cout << "\n|==========================================|\n";
        cout << "|===== BIENVENIDOS AL JUEGO DE BINGO ======|\n";
        cout << "|==========================================|\n";
		cout << "\nJugador, digite su nombre: ";
        cin >> Jugador1;
		cout << "Bienvenido " << Jugador1 << " usted es el [1] jugador" << endl;
		cout << "\nJugador, digite su nombre: ";
        cin >> Jugador2;
		cout << "Bienvenido " << Jugador2 << " usted es el [2] jugador" << endl;
        bool saliendo = false;
        bool ok = false;
            do{ //Aquí establecemos este do while para el switch
                do{ //Aquí establecemos este do para validar estradas de caracteres en los case
                    cout << "\nMENU DE OPCIONES" << endl;
                    cout << "[1] Continuar con el juego diferencia de dos" << endl;
                    cout << "[2] Intrucciones del juego" << endl;
                    cout << "[0] Salir del juego" << endl;
                    cout << "\nIngrese una opcion: ";
                    cin >> op;
					switch(op){
                        case 1:
                            system("cls");
                            while(Turno1 <= 10){ //Repetimos el tueno del 1 jugador hasta que haya completado los 10
                                if(TurnoJugador1){
                                    cout << "\nPuntuacion actual del jugador" << right << setw( 3 ) << ": " << CerosTabla(Tabla)/2 << endl; //Dividimos entre dos para obtener los puntos de 1 en 1
                                    cout << "NUMERO DE TURNOS" << right << setw( 16 ) << ": " << Turno1 << endl;
                                    cout << "JUGADOR EN TURNO" << right << setw( 16 ) << ": " << Jugador1 << endl; cout << " " << endl;
                                    ImpTabla(Tabla, i, j); cout << "\n" << endl; //Imprimimos la matriz del 1 jugador
                                    DiferenciaJugador1(Tabla); //Llamamos la funcion de diferencia de 2
                                    system("pause");
                                    system("cls");
                                }
                                 Turno1++; //Aqui contamos los turnos del 1 jugador
                            }
                            if(Turno1 = 10){
                                    CambiarTurno(); //Cuando el tueno del 1 jugador llegue a 10 se va a cambiar para darle el espacio al 2 jugador
                                 }
                            while(Turno2 <= 10){ //Repetimos el tueno del 2 jugador hasta que haya completado los 10
                                if(TurnoJugador2){
                                        cout << "\nPuntuacion actual del jugador" << right << setw( 3 ) << ": " << CerosTabla2(Tabla2)/2 << endl; //Dividimos entre dos para obtener los puntos de 1 en 1
                                        cout << "NUMERO DE TURNOS" << right << setw( 16 ) << ": " << Turno2 << endl;
                                        cout << "JUGADOR EN TURNO" << right << setw( 16 ) << ": " << Jugador2 << endl; cout << " " << endl;
                                        ImpTabla2(Tabla2, i, j); cout << "\n" << endl; //Imprimimos la matriz del 2 jugador
                                        DiferenciaJugador2(Tabla2); //Llamamos la funcion de diferencia de 2
                                        system("pause");
                                        system("cls");
                                }
                                 Turno2++; //Aqui contamos los turnos del 1 jugador
                            }
                            Puntos_Jugador1 = CerosTabla(Tabla)/2; //Igulamos la variable de puntos del 1 jugador con el puntaje de la tabla 1
                            Puntos_Jugador2 = CerosTabla2(Tabla2)/2; //Igulamos la variable de puntos del 2 jugador con el puntaje de la tabla 2
                            Ranking(Jugador1, Jugador2, Puntos_Jugador1, Puntos_Jugador2);break; //Llamamos la funcon para verificar quien gano

                        case 2:
                            cout << "\n* Instrucciones: " << endl;
                            cout << "\t- Una vez empezado el juego ya no podra salirse hasta concluirlo" << endl;
                            cout << "\t- Debe de seleccionar dos valores cuando le toque su turno" << endl;
                            cout << "\t- Gana el jugador con mayor puntaje al final del juego" << endl;
                            cout << "\t- Los turnos de cada jugador son de manera continua" << endl;
                            cout << "\t- Son 10 turnos para cada jugador" << endl; cout << "\n";break;
                            system("pause");
                            system("cls");

                        case 0:
                            saliendo = true;
                            continuar = false;break;
                    }
                    if(!cin.fail()){    //Estos condicionales para validar la entrada de datos fueron tomados de www.cristalab.com
                            ok = true;  //cita: (esutaraiki. 2010)
                    } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "Esto es un caracter, prueba con un numero" << endl;
                    }
                }while(!ok);
        }while(saliendo == false);
    }while(continuar == true);
return 0;
}
/*---- Definicion de Funciones -----*/
//Los siguientes tres int para generar y numeros aleatorios y pares e impares y al principio de los llenado de la matriz fue tomado de: https://programacionencpp.blogspot.com/2016/01/dos-array-con-numeros-aleatorios-par-e.html
//Cita: (William. 2016).
int GNumAleatorio( int min , int max ){ //Genera numeros aleatorios usado de programacionencpp.blogspot.com
    return rand() % max + min;
}

int GNumPar( int min , int max ){ //Funcion para verificar el numero generado (Para Par) usado de programacionencpp.blogspot.com
    int n = GNumAleatorio( min , max );
    if(n % 2 == 0){ //Se valida el numero Par, luego se retorna.
        return n;
    } else
        if((n + 1) > max){
            return n - 1;
        } else
            return n + 1;
}

int GNumImpar( int min , int max ){ //Funcion para verificar el numero generado (Para Impar) usado de programacionencpp.blogspot.com
    int n = GNumAleatorio( min , max );
    if(n % 2 != 0){ //Se valida el numero Impar, luego se retorna.
        return n;
    } else
        if((n - 1) < min){
            return n + 1;
        } else
            return n - 1;
}

void LlenarCarton(int Tabla[F][C], int Fila, int Columna, int i, int j, int s, int ArrayPar[], int ArrayImpar[], int ArrayMayor[], int min, int max){ //Se inserta los elementos a los arrays de 12 posiciones
int Indice; int Libre[48];
//For para el llenado del array par e impar usado de programacionencpp.blogspot.com
    for(int i = 0 ; i < tam ; i++){
        ArrayPar[i] = GNumPar( min , max ); //Copiamos los numeros pares en el vector par
    }
    for(int i = 0 ; i < tam ; i++){
        ArrayImpar[i] = GNumImpar( min , max ); //Copiamos los numeros impares en el vector impar
    }
// for para el llenado del array de 48 posiciones
    for(int i = 0 ; i < 12 ; i++){ //Vector par (Primer valor)
        ArrayMayor[i] = ArrayPar[i];
    }
    for(int i = 12 ; i < 24 ; i++){ //Vector impar (Primer valor)
        ArrayMayor[i] = ArrayImpar[i-12];
    }
    for(int i = 24 ; i < 36 ; i++){ //Copiamos los valores del array par (Segundo valor)
        ArrayMayor[i] = ArrayPar[i-24] + 2; //Al segundo valor le sumamos 2 unidades para que tenga una diferencia de 2 con respecto al primero
    }
    for(int i = 36 ; i < 48 ; i++){ //Copiamos los valores del array impar (Segundo valor)
        ArrayMayor[i] = ArrayImpar[i-36] + 2; //Al segundo valor le sumamos 2 unidades para que tenga una diferencia de 2 con respecto al primero
    }
    for(i = 0; i < 48; i++) { //Este for crea las posiciones de indice aleatorias para barajar la matriz aleatoriamente
        Indice = rand() % 48;
        while (Libre[Indice] == 0){ //Este bucle evita que dos elementos sean guardados en la misma posicion
            Indice = rand() % 47 + 1;
            ArrayMayor[Indice] = ArrayMayor[i];
        }
    }
    for(i = 1 ; i < 9 ; i++){ // Llenamos la matriz del 1 jugador desde la posicion 1 para mejor comprension
        for(j = 1 ; j < 7 ; j++){
            Tabla[i][j] = ArrayMayor[s];
            s++;
        }
    }
}

//Aqui llenamos la otra matriz para el segundo jugador
void LlenarCarton2(int Tabla2[F][C], int Fila, int Columna, int i, int j, int s, int ArrayPar[], int ArrayImpar[], int ArrayMayor[]){ //Se inserta los elementos a los arrays de 12 posiciones
int Indice; int Libre[48];
    for(int i = 0 ; i < 12 ; i++){ //Vector impar (Primer valor)
        ArrayMayor[i] = ArrayImpar[i];
    }
    for(int i = 12 ; i < 24 ; i++){ //Vector par (Primer valor)
        ArrayMayor[i] = ArrayPar[i-12];
    }
    for(int i = 24 ; i < 36 ; i++){ //Copiamos los valores del array  (Segundo valor)
        ArrayMayor[i] = ArrayImpar[i-24] + 2; //Al segundo valor le sumamos 2 unidades para que tenga una diferencia de 2 con respecto al primero
    }
    for(int i = 36 ; i < 48 ; i++){ //Copiamos los valores del array par (Segundo valor)
        ArrayMayor[i] = ArrayPar[i-36] + 2; //Al segundo valor le sumamos 2 unidades para que tenga una diferencia de 2 con respecto al primero
    }
    for(i = 0; i < 48; i++) { //Este for crea las posiciones de indice aleatorias para barajar la matriz aleatoriamente
        Indice = rand() % 47 + 1;
        while (Libre[Indice] == 0){ //Este bucle evita que dos elementos sean guardados en la misma posicion
            Indice = rand() % 47 + 1;
            ArrayMayor[Indice] = ArrayMayor[i];
        }
    }
    for(i = 1 ; i < 9 ; i++){ //Llenamos la matriz del 2 jugador desde la posicion 1 para mejor comprension
        for(j = 1 ; j < 7 ; j++){
            Tabla2[i][j] = ArrayMayor[s];
            s++;
        }
    }
}

void ImpTabla( int Tabla[F][C], int i, int j ){ //Imprime el contenido de la matriz
for (j = 1; j <= 6; j++){
        cout << "      " << j << left << setw( 4 ) << "C"; //Agrega una c para orientarnos en las columnas
     }
     cout << "\n" << "   " << "----------------------------------------------------------------"; //Agrega una fila de (-) al principio de la matriz para que se vea igual al resto de las filas
     for (i = 1 ; i < 9 ; i++){
          cout << "\n" << i << "F" << ""; //Agrega una F para orientarnos a las columnas
        for (j = 1 ; j < 7 ; j++){
            cout << " | " << right << setw( 5 ) << Tabla[i][j] << " | " ; //Se imprimen los elementos de las posiciones de la matriza a un mismo espacio de distancia
        }
                    cout << "\n" << "   " << "----------------------------------------------------------------"; //Agrega una fila de (-) entre las filas para que paresca que los elementos estan dentro de un cuadro
    }
}

void ImpTabla2 (int Tabla2[F][C], int i, int j){ //Imprime el contenido de la matriz
for (j = 1; j < 7; j++){
        cout << "      " << j << left << setw( 4 ) << "C"; //Agrega una c para orientarnos en las columnas
     }
     cout << "\n" << "   " << "----------------------------------------------------------------"; //Agrega una fila de (-) al principio de la matriz para que se vea igual al resto de las filas
     for (i = 1 ; i < 9 ; i++){
          cout << "\n" << i << "F" << ""; //Agrega una F para orientarnos a las columnas
        for (j = 1 ; j < 7 ; j++){
            cout << " | " << right << setw( 5 ) << Tabla2[i][j] << " | " ; //Se imprimen los elementos de las posiciones de la matriza a un mismo espacio de distancia
        }
                    cout << "\n" << "   " << "----------------------------------------------------------------"; //Agrega una fila de (-) entre las filas para que paresca que los elementos estan dentro de un cuadro
    }
}

int CerosTabla(int Tabla[F][C]){ //Funcion para contar los ceros y llevar un puntaje
	int contarceros = 0;
	for(int i = 1 ; i < 9 ; i++){
		for(int j = 1 ; j < 7 ; j++){
			if(Tabla[i][j] == 0){ //Vemos cuales casillas contienen ceros
				contarceros++; //Cuenta los ceros en la tabla del 1 jugador
			}
		}
	}
	return contarceros;
}

int CerosTabla2(int Tabla2[F][C]){ //Funcion para contar los ceros y llevar un puntaje
	int contarceros = 0;
	for(int i = 1 ; i < 9 ; i++){
		for(int j = 1 ; j < 7 ; j++){
			if(Tabla2[i][j] == 0){ //Vemos cuales casillas contienen ceros
				contarceros++; //Cuenta los ceros en la tabla del 2 jugador
			}
		}
	}
	return contarceros;
}

bool CambiarTurno(){ //Funcion para cambuar de turno
		if(TurnoJugador1){ //Aqui cambiamos de turno entre los jugadores
           JugadorEnCurso(2);
		} else if(TurnoJugador2){
                   JugadorEnCurso(1);
               }
}

void JugadorEnCurso(int Jugador){ //Aqui establecemos cual jugador estara jugando
	if(Jugador == 1){ //Si el jugador 1 esta en curso el jugador 2 debe esperar
       TurnoJugador1 = true;
       TurnoJugador2 = false;
	}else if(Jugador == 2){ //Si el jugador 2 esta en curso el jugador 1 debe esperar
              TurnoJugador2 = true;
              TurnoJugador1 = false;
          }
}

void DiferenciaJugador1(int Tabla[F][C]){
    int Fila1 = 0, Columna1 = 0, Fila2 = 0, Columna2 = 0;
    bool ok = false;
        do{ //Este do es para validar que no se seleccione una casilla que contiene ceros
            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "PRIMER VALOR" << endl; cout << "Jugador, digite la fila: ";
                    cin >> Fila1;
                        if(Fila1 > 8 || Fila1 < 1){
                            cout << "\tLa fila seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                          }
                }while(!ok);
            }while(Fila1 > 8 || Fila1 < 1);

            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "Jugador, digite la columna: ";
                    cin >> Columna1;
                        if(Columna1 > 6 || Columna1 < 1){
                            cout << "\tLa columna seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                        }
                }while(!ok);
            }while(Columna1 > 6 || Columna1 < 1);
        cout << " " << endl; cout << "...Valor seleccionado: " << Tabla[Fila1][Columna1] << endl; cout << " " << endl;
            if(Tabla[Fila1][Columna1] == 0){
                cout << "Los elementos de esta posicion ya fueron selecionados" << endl; cout << " " << endl;
            }
        }while(Tabla[Fila1][Columna1] == 0);

        do{
            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "SEGUNDO VALOR" << endl; cout << "Jugador, digite la fila: ";
                    cin >> Fila2;
                        if(Fila2 > 8 || Fila2 < 1){
                            cout << "\tLa fila seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                          }
                }while(!ok);
            }while(Fila2 > 8 || Fila2 < 1);

            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "Jugador, digite la columna: ";
                    cin >> Columna2;
                        if(Columna2 > 6 || Columna2 < 1){
                            cout << "\tLa columna seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                          }
                }while(!ok);
            }while(Columna2 > 6 || Columna2 < 1);
        cout << " " << endl; cout << "...Valor seleccionado: " << Tabla[Fila2][Columna2] << endl; cout << " " << endl;
            if(Tabla[Fila2][Columna2] == 0){
                cout << "Los elementos de esta posicion ya fueron selecionados" << endl;cout << " " << endl;
            }
         }while(Tabla[Fila2][Columna2] == 0);

            if(Tabla[Fila1][Columna1] > Tabla[Fila2][Columna2]){ //Si el primer valor es mayor al segundo, al primero se le resta el segundo
                Tabla[Fila1][Columna1] = Tabla[Fila1][Columna1] - Tabla[Fila2][Columna2];
                    if(Tabla[Fila1][Columna1] == 2){ //Dicha resta debe de dar 2 si ambos numeros tienen una diferencia de 2
                        cout << "Felicidades has obtenido un punto" << endl;
                        Tabla[Fila1][Columna1] = 0;
                        Tabla[Fila2][Columna2] = 0;
            } else if(Tabla[Fila1][Columna1] != 2){ //Y si no es 2, los numeros no tienen una diferencia de 2
                        cout << "Incorrecto, no has obtenido ningun punto" << endl;
                   }
            } else if(Tabla[Fila2][Columna2] > Tabla[Fila1][Columna1]){ //Si el segundo valor es mayor al primero, al segundo se le resta el primero ya que no se le puede restar a un numero menor uno mayor porque dara negativo
                        Tabla[Fila2][Columna2] = Tabla[Fila2][Columna2] - Tabla[Fila1][Columna1];
                        if(Tabla[Fila2][Columna2] == 2){ //Dicha resta debe de dar 2 si ambos numeros tienen una diferencia de 2
                            cout << "Felicidades has obtenido un punto" << endl;
                            Tabla[Fila2][Columna2] = 0;
                            Tabla[Fila1][Columna1] = 0;
            } else if(Tabla[Fila2][Columna2] != 2){ //Y si no es 2, los numeros no tienen una diferencia de 2
                        cout << "Incorrecto, no has obtenido ningun punto" << endl;
                   }
            } else if(Tabla[Fila1][Columna1] == Tabla[Fila2][Columna2]){ //Si los numeros son iguales se considera como incorrecta
                        cout << "Incorrecto, no has obtenido nungun punto" << endl;
                   }
}

void DiferenciaJugador2(int Tabla2[F][C]){
    int Fila1 = 0, Columna1 = 0, Fila2 = 0, Columna2 = 0;
    bool ok = false;
        do{ //Este do es para validar que no se seleccione una casilla que contiene ceros
            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "PRIMER VALOR" << endl; cout << "Jugador, digite la fila: ";
                    cin >> Fila1;
                        if(Fila1 > 8 || Fila1 < 1){
                            cout << "\tLa fila seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                          }
                }while(!ok);
            }while(Fila1 > 8 || Fila1 < 1);

            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "Jugador, digite la columna: ";
                    cin >> Columna1;
                        if(Columna1 > 6 || Columna1 < 1){
                            cout << "\tLa columna seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                          }
                }while(!ok);
            }while(Columna1 > 6 || Columna1 < 1);

        cout << " " << endl; cout << "...Valor seleccionado: " << Tabla2[Fila1][Columna1] << endl; cout << " " << endl;
            if(Tabla2[Fila1][Columna1] == 0){
                cout << "Los elementos de esta posicion ya fueron selecionados" << endl; cout << " " << endl;
            }
        }while(Tabla2[Fila1][Columna1] == 0); //Establecemos un do para cuando el usuario elija elementos que ya se hayan convertido en ceros

        do{
            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "SEGUNDO VALOR" << endl; cout << "Jugador, digite la fila: ";
                    cin >> Fila2;
                        if(Fila2 > 8 || Fila2 < 1){
                            cout << "\tLa fila seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                          }
                }while(!ok);
            }while(Fila2 > 8 || Fila2 < 1);

            do{ //A continuacion hay un do para validar que el usuario ingrese filas y columnas dentro de los posiciones que contiene la matriz
                do{
                    cout << "Jugador, digite la columna: ";
                    cin >> Columna2;
                        if(Columna2 > 6 || Columna2 < 1){
                            cout << "\tLa columna seleccionada no existe" << endl;
                        }
                        if(!cin.fail()){
                            ok = true;
                        } else {
                                cin.clear();
                                cin.ignore(256,'\n');
                                cout << "\tEsto es un caracter, prueba con un numero" << endl; cout << " " << endl;
                          }
                }while(!ok);
            }while(Columna2 > 6 || Columna2 < 1);
        cout << " " << endl; cout << "...Valor seleccionado: " << Tabla2[Fila2][Columna2] << endl; cout << " " << endl;
            if(Tabla2[Fila2][Columna2] == 0){
                cout << "Los elementos de esta posicion ya fueron selecionados" << endl; cout << " " << endl;
            }
        }while(Tabla2[Fila2][Columna2] == 0); //Establecemos un do para cuando el usuario elija elementos que ya se hayan convertido en ceros

            if(Tabla2[Fila1][Columna1] > Tabla2[Fila2][Columna2]){ //Si el primer valor es mayor al segundo, al primero se le resta el segundo
                Tabla2[Fila1][Columna1] = Tabla2[Fila1][Columna1] - Tabla2[Fila2][Columna2];
                if(Tabla2[Fila1][Columna1] == 2){ //Dicha resta debe de dar 2 si ambos numeros tienen una diferencia de 2
                    cout << "Felicidades has obtenido un punto" << endl;
                    Tabla2[Fila2][Columna2] = 0;
                    Tabla2[Fila1][Columna1] = 0;
            } else if(Tabla2[Fila1][Columna1] != 2){ //Y si no es 2, los numeros no tienen una diferencia de 2
                        cout << "Incorrecto, no has obtenido nungun punto" << endl;
                   }
            } else if(Tabla2[Fila2][Columna2] > Tabla2[Fila1][Columna1]){ //Si el segundo valor es mayor al primero, al segundo se le resta el primero ya que no se le puede restar a un numero menor uno mayor porque dara negativo
                        Tabla2[Fila2][Columna2] = Tabla2[Fila2][Columna2] - Tabla2[Fila1][Columna1];
                        if(Tabla2[Fila2][Columna2] == 2){ //Dicha resta debe de dar 2 si ambos numeros tienen una diferencia de 2
                            cout << "Felicidades has obtenido un punto" << endl;
                            Tabla2[Fila2][Columna2] = 0;
                            Tabla2[Fila1][Columna1] = 0;
            } else if(Tabla2[Fila2][Columna2] != 2){ //Y si no es 2, los numeros no tienen una diferencia de 2
                        cout << "Incorrecto, no has obtenido ningun punto" << endl;
                   }
            } else if (Tabla2[Fila1][Columna1] == Tabla2[Fila2][Columna2]){ //Si los numeros son iguales se considera como incorrecta
                        cout << "Incorrecto, no has obtenido ningun punto" << endl;
                   }
}
void Ranking(string Jugador1, string Jugador2, int Puntos_Jugador1, int Puntos_Jugador2){
    string NombreDelGanador = " "; //Aqui almacenamos el nombre del ganador
    int PuntosDelGanador = 0; //Aqui almacenamos los puntos del ganador

    if(Puntos_Jugador1 > Puntos_Jugador2){ //If para cuando el jugador 1 sea el ganador
         NombreDelGanador = Jugador1;
         PuntosDelGanador = Puntos_Jugador1;
         cout << "\n---EN ORA BUENA TENEMOS UN GANADOR---" << endl;
		 cout << "\nEl JUGADOR GANADOR ES: " << NombreDelGanador << endl;
    } else if(Puntos_Jugador2 > Puntos_Jugador1){ //If para cuando el jugador 2 sea el ganador
                NombreDelGanador = Jugador2;
                PuntosDelGanador = Puntos_Jugador2;
                cout << "\n---EN ORA BUENA TENEMOS UN GANADOR---" << endl;
                cout << "\nEl JUGADOR GANADOR ES : " << NombreDelGanador << endl;
           } else if(Puntos_Jugador1 == Puntos_Jugador2){ //If para cuando los dos jugadores queden empatados
                      cout << "\n---HAY UN EMPATE ENTRE TODOS LOS JUGADORES---" << endl;
                      cout << "\nLOS JUGADORES EMPATADOS SON: "<< Jugador1 <<" y " << Jugador2 << endl;
                  }
    cout << " " << endl;
    cout << "\tRegistros del juego : " << endl; //Imprimimos un registro en forma de tabla sobre el juego
    cout << "\t---------------------------------------------" << endl;
    cout << "\t| " << left << setw( 25 ) << "Jugador" << "|" << right << setw( 15 ) << "Puntaje" << " |" << endl;
    cout << "\t---------------------------------------------" << endl;
    cout << "\t| " << left << setw( 25 ) << Jugador1 << "|" << right << setw( 15 ) << Puntos_Jugador1 << " | " << endl;
    cout << "\t---------------------------------------------" << endl;
    cout << "\t| " << left << setw( 25 ) << Jugador2 << "|" << right << setw( 15 ) << Puntos_Jugador2 << " | " << endl;
    cout << "\t---------------------------------------------" << endl;
    cout << "\n---Felicidades jugadores, han hecho un exelente juego---" << endl; cout << " " << endl;
    system("pause");
    system("cls");
}
//Referencias Bibliograficas:
//William. (27 de enero del 2016). Dos Array con Números Aleatorios Par e Impar. v1. programacionencpp.blogspot.com https://programacionencpp.blogspot.com/2016/01/dos-array-con-numeros-aleatorios-par-e.html
//esutoraiki. (29 de noviembre del 2010). Validación de tipos de datos en C++. www.cristalab.com https://www.cristalab.com/tutoriales/validacion-de-tipos-de-datos-en-c--c92149l/
