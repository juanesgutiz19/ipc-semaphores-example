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
    // Simulación de consumo infinito por parte del proceso b
    while(1){
        // Se adquiere semáforo 1
        P(semid, 1);
        // Simulación de sección crítica
        printf("Sección crítica del proceso pb\n");
        sleep(1);
        // Se libera semáforo 0
        V(semid, 0);
    }
    exit(0);
}