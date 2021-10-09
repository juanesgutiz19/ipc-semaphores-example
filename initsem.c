#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void)
{
    // Se obtiene el semid de un conjunto de semáforos ya creado previamente (esto se hace en el archivo creasem.c)
    // Primer argumento es la key que asignó un programador a un conjunto de semáforos ya existente
    int semid = semget(0xa, 0, 0);

    // Si efectivamente existe el conjunto de semáforos se retorna el semid, que es != -1
    if(semid != -1){
        // Se inicializan los semáforos

        // El segundo argumento es el número del semáforo, si es 0, es el primero, si es 1 es el segundo
        // El comando SETVAL es para inicializar el semáforo
        // El cuarto argumento es el valor de inicialización
        semctl(semid, 0, SETVAL, 1);
        semctl(semid, 1, SETVAL, 0);
    }else{
        printf("Error semget\n");
    }
    exit(0); 
}
