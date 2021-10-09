#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>

// Prototipos que están en el objeto p y v
void P(int, int);
void V(int, int);

int main(void)
{
    // Se necesita saber el identificador del conjunto de semáforos
    int semid = semget(0xa, 0, 0);
    // Simulación de producción infinita del proceso a
    while(1){
        // Sección de entrada, se adquiere semáforo 0
        P(semid, 0);
        // Simulación de la sección crítica
        printf("Sección crítica del proceso pa\n");
        // Retardo de ejecución de la producción para la simulación
        sleep(1);
        // Sección de salida, se libera el semáforo 1
        V(semid, 1);
    }
    exit(0);
}