#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void)
{
     // semid es el identificador del conjunto de semáforos que devuelve el sistema operativo
     // Primer argumento con valor 0xa de semget es la clave que se le otorga a ese conjunto de semáforos
     // Segundo argumento es la cantidad de semáforos que quiero dentro del conjunto, en este caso es 2
     // El primer flag IPC_CREAT indica que se van a crear los semáforos
     // El segundo flag IPC_EXCL, si ya existe un conjunto de semáforos con la key 0xa, se retorna un error   
     // 0600 - El usuario que va a ejecutar el código va a tener permiso de lectura y escritura sobre los semáforos del conjunto
    int semid = semget(0xa, 2, IPC_CREAT|IPC_EXCL|0600);
    // Se comprueba si ya existe un conjunto de  semáforos con esa key dada
    if (errno == EEXIST) {
        printf("Ya existe un conjunto de semáforos para la clave 0xa\n");
    }else {
        // Si no, se muestra el valor de semid, lo cual es un valor distinto a -1
        printf("semid = %d\n", semid);
    }
    exit(0); 
}


// P ---> Wait o adquirir
// V ---> Post o liberar