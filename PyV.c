#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// Equivalente a WAIT en POSIX}
// Primer argumento es identificador del conjunto de semáforos
// Segundo argumento es el número de semáforo, 0 si es el primero, 1 si es el segundo
void P(int semid, int sem)
{
    struct sembuf buf;
    // sem_num es número del semáforo
    buf.sem_num = sem;
    // sem_op es la operación, -1 define la operación para adquirir (o WAIT)
    // Indica que se resta 1 al valor del semáforo si el semáforo tiene un valor mayor a cero y el proceso entra a la sección crítica
    buf.sem_op = -1;
    // sem_flg se pone en 0 para hacer la operación estándar P (o WAIT)
    buf.sem_flg = 0;
    // Primer argumento es el semid del array de semáforos sobre el cual se va a realizar la operación
    // Segundo argumento es la operación que está definida en la estructura buf
    // Tercer argumento es cuántas operaciones son, en este caso una
    semop(semid, &buf, 1);
}

// Equivalente a POST o SIGNAL en Posix
// Primer argumento es identificador del conjunto de semáforos
// Segundo argumento es el número de semáforo, 0 si es el primero, 1 si es el segundo
void V(int semid, int sem)
{
    struct sembuf buf;
    // sem_num es número del semáforo
    buf.sem_num = sem;
    // sem_op es la operación, 1 define la operación para liberar (o POST)
    // Indica que se suma 1 al valor del semáforo
    buf.sem_op = 1;
    // sem_flg se pone en 1 para hacer la operación estándar V (o POST)
    buf.sem_flg = 0;
    // Primer argumento es el semid del array de semáforos sobre el cual se va a realizar la operación
    // Segundo argumento es la operación que está definida en la estructura buf
    // Tercer argumento es cuántas operaciones son, en este caso una
    semop(semid, &buf, 1);
}