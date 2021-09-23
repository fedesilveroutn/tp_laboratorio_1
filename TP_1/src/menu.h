/*
 * menu.h
 *
 *  Created on: 15 sep. 2021
 *      Author: Fede
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>

void menu (int* eleccion, int operando1, int operando2);
void eleccion (int eleccion, int* operandoUno, int* operandoDos, int* continuar , int* flagCargaOperando2, int* flagCalculos, int* flagMenu);
void separador();
void separadorPunto();
void instrucciones();
#endif /* MENU_H_ */
