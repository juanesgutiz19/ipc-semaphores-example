#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void)
{

    // Se obtiene el semid de un conjunto de semáforos ya creado
    // Primer argumento es key que asignó un programador a un conjunto de semáforos ya existente
    int semid = semget(0xa, 0, 0);
    if(semid != -1){
        // Se usa semctl en este caso para ver el contenido del semáforo
        
        // Del conjunto semid se quiere ver el contenido del semáforo 0 (primero)
        printf(" sem 0 = %d\n", semctl(semid, 0, GETVAL));  
        // Del conjunto semid se quiere ver el contenido del semáforo 1 (segundo)
        printf(" sem 1 = %d\n", semctl(semid, 1 , GETVAL));  
    }else{
        printf("Error semget\n");
    }
    exit(0); 
}
