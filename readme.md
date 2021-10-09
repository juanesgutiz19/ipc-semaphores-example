# Semáforos IPC

## Asignación de permisos a script de bash

Lo primero que debe hacer es asignarle permisos de ejecución al archivo compilar.sh. Este archivo contiene los comandos necesarios para que se generen los ejecutables y los archivos objeto necesarios para el funcionamiento de la aplicación.

```bash
$ chmod +x compilar.sh
```

## Ejecución de archivos

Se deben abrir dos terminales, en la primera se ejecuta el ejecutable pb:

```bash
$ ./pb
```
Se observa que no puede avanzar ya que no puede consumir nada que produzca el proceso a. Posteriormente se ejecuta pa:
```bash
$ ./pa
```
Se observará una pequeña simulación de como el proceso pa va produciendo y el proceso pb consume.