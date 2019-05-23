#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {
    
    /*1: Creo y destruyo una pila*/
    printf("Prueba 1:\n");
    pila_t* pila = pila_crear();
    print_test("Creo la pila: ",pila != NULL);
    pila_destruir(pila);
    print_test("Destruyo la pila: ",true);

    /*2: Pruebo invariante de pila*/
    printf("Pruebo invariante de pila, apilando, desapilando y veo tope:\n");

    int a = 10;
    int b = 4;
    int c = 3;

    int* p1 = &a;
    int* p2 = &b;
    int* p3 = &c;

    pila = pila_crear();
    
    print_test("Chequeo si esta vacia: ", pila_esta_vacia(pila));
    print_test("Apilo p1: ", pila_apilar(pila,p1) == true);
    print_test("Apilo p2: ", pila_apilar(pila,p2) == true);
    print_test("Apilo p3: ", pila_apilar(pila,p3) == true);
    print_test("Veo tope; ", pila_ver_tope(pila) == p3);
    print_test("Desapilo: ", pila_desapilar(pila) == p3);
    print_test("Veo tope; ", pila_ver_tope(pila) == p2);
    print_test("Desapilo: ", pila_desapilar(pila) == p2);
    print_test("Veo tope; ", pila_ver_tope(pila) == p1);
    print_test("Desapilo: ", pila_desapilar(pila) == p1);
    print_test("Chequeo si esta vacia: ", pila_esta_vacia(pila));

    pila_destruir(pila);

    /*Prueba de volumen*/
    printf("Pruebas de volumen: \n");
    
    pila = pila_crear();
    
    int vector_prueba[1000];

    for(int i = 0; i < 1000; i++){
        vector_prueba[i] = i;
        pila_apilar(pila,&vector_prueba[i]);
    }

    for(int i = 1000; i > 0; i--){
        print_test("Desapilo: ",pila_desapilar(pila) == &vector_prueba[i-1]);
    }

    pila_destruir(pila);

    /*Prueba Apilar NULLS*/
    printf("Prueba apilar NULLS:\n");

    pila = pila_crear();

    print_test("Apilo NULL numero 1: ", pila_apilar(pila,NULL));
    print_test("Apilo NULL numero 2: ", pila_apilar(pila,NULL));
    print_test("Veo si esta vacia: ",pila_esta_vacia(pila)==false);
    print_test("Veo tope: ", pila_ver_tope(pila)==NULL);
    print_test("Desapilo NULL numero 2: ",pila_desapilar(pila)==NULL);
    print_test("Desapilo NULL numero 1: ",pila_desapilar(pila)==NULL);
    print_test("Veo si esta vacia: ",pila_esta_vacia(pila)==true);

    /*Prueba condicion de borde pila se comporta como recien creada*/
    printf("Prueba que se comporte como nueva: \n");

    print_test("Apilo NULL numero 1: ", pila_apilar(pila,NULL));

    print_test("Veo si esta vacia: ",pila_esta_vacia(pila)==false);
    print_test("Veo tope: ", pila_ver_tope(pila)==NULL);

    print_test("Desapilo NULL numero 1: ",pila_desapilar(pila)==NULL);
    print_test("Veo si esta vacia: ",pila_esta_vacia(pila)==true);

    pila_destruir(pila);

    /*Prueba borde desapilar, ver tope y esta vacia en pila recien creada*/
    printf("Prueba borde desapilar y ver tope en pila recien creada: \n");
    
    pila = pila_crear();
    print_test("Desapilo pila vacia: ", pila_desapilar(pila)==NULL);
    print_test("Veo Tope pila vacia: ", pila_ver_tope(pila)==NULL);
    print_test("Veo si esta vacia: ",pila_esta_vacia(pila)==true);

    pila_destruir(pila);
}

