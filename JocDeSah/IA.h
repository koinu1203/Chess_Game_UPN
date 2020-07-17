#pragma once
#include "Chess.h"
#include <stdlib.h>

int tabV[8][8]; //tablero de valor contendra los valores de las fichas en tiempo real
/*
	-BLANCO / +NEGRO
	PEON = 10
	CABALLO = 30
	ALFIL = 30 
	TORRE = 50 
	REINA = 90 
	REY = 900
*/

void actTabV() { 
	//actualizar tablero de valor 
	for (int i = 0; i < 8; i++) {
		for (int s = 0; s < 8; s++) {
			switch (abs(tablero[i][s])) { //valor absoluto de la casilla en el tablero original 
			case 1: case 3: case 4: tabV[i][s] = tablero[i][s] * 10; break; //PEON CABALLO ALFIL 
			case 2: tabV[i][s] = tablero[i][s] * 25; break; //TORRE
			case 5: tabV[i][s] = (tablero[i][s]/5) * 90; break; // REINA
			case 6: tabV[i][s] = (tablero[i][s]/6) * 900; break; //REY 
			default: break;
			}
		}
	}
}
/*
	requisitos del algoritmo
	1)	Que te permita escoger un movimiento de todos los permitidos
	2)	Escoger el movimiento que de mayor valor, acá entra en juego 
		el tabV o tablero de valor (asegurarse de actualizar el tablero)
	3)	Saber si la jugada escogida a futuro (pensando un turno luego) 
		es la mejor
	4)	aplicar una tabla de posicion para definir la mejor posicion para pieza.
		ejemplo PEON: 
			[0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0]
			[5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0]
			[1.0,  1.0,  2.0,  3.0,  3.0,  2.0,  1.0,  1.0]
			[0.0,  0.0,  0.0,  2.0,  2.0,  0.0,  0.0,  0.0]
			[0.5, -0.5, -1.0,  0.0,  0.0, -1.0, -0.5,  0.5]
			[0.5,  1.0,  1.0, -2.0, -2.0,  1.0,  1.0,  0.5]
			[0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0]
		Segun este mapa las mejores posiciones en que puede estar el peon es en el centro
		para ver las demas posiciones de las piezas https://translate.google.com.pe/translate?hl=es&sl=auto&tl=es&u=https%3A%2F%2Fwww.freecodecamp.org%2Fnews%2Fsimple-chess-ai-step-by-step-1d55a9266977%2F 

	SeudoCodigo: 
	funcion IA:
		buscar todos los posibles movimientos 
		generar las tablas de posicion para el caballo, reina y alfil con respecto al rey enemigo y las demas piezas enemigas (aca podemos usar un algoritmo voraz o algun otro)
		funcion Evaluar movimiento:
			escoger un movimiento entre los posibles 
			realizarlo 
			ver el mejor movimiento del rival 
			realizarlo 
			escoger el siguiente mejor movimiento para la IA
			calcular el valor de la jugada con la tabV y la tabla de posicion
			comparar el valor de la jugada con la mejor jugada hasta el momento
			probar siguiente jugada 
		retornar movimiento escogido
*/


