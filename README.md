# philosopher_42
otro proyecto del cursus 42, este un poquito mas abstracto pero más entretenido, creo, espero, deseo...

# funciones permitidas:

__usleep()__

Se utiliza para suspender la ejecución de un programa durante un período específico de tiempo, especificado en microsegundos. (1 segundo seria igual a poner usleep(1000000)).

__gettimeofday()__

Se utiliza para obtener información sobre la fecha y hora actual. La función gettimeofday es útil cuando necesitas medir el tiempo transcurrido entre dos eventos o cuando deseas obtener una marca de tiempo precisa en tu programa.

 - Se encuentra en la libreria <sys/time.h>
 - Dentro de esta libreria hay estructuras como __struct timeval__
 - Las estructuras struct timeval contienen dos campos principales:
   -   tv_sec: Representa los segundos.
   -   tv_usec: Representa los microsegundos (una fracción de un segundo).


__pthread_create()__

Pertenece a la libreria <pthread.h>. Se utiliza para crear y lanzar hilos (threads) en aplicaciones multiproceso.
La función devuelve un __0__ si todo a salido bien.
El prototipo es: pthread_create(pthread_t __*thread__, const pthread_attr_t __*attr__, void __*(*start_routine)(void *)__, void __*arg__);
Para probarlo  : pthread_create(__&my_thread__, __NULL__, __my_thread_function__, __NULL__);
- Los argumentos son:

- __thread__: Un puntero a una variable pthread_t que se utilizará para almacenar el identificador del hilo recién creado. Este identificador se usa para referirse al hilo más tarde en otras funciones relacionadas con hilos.

- __attr__: Un puntero a una estructura pthread_attr_t que se utiliza para especificar los atributos del hilo que se va a crear. Si deseas utilizar los atributos predeterminados, puedes pasar NULL.

- __start_routine__: Un puntero a la función que se ejecutará en el hilo recién creado. Esta función toma un argumento void * y devuelve un void *. Es el punto de entrada del hilo y es donde se coloca el código que deseas que se ejecute en paralelo en el nuevo hilo.

- __arg__: Un puntero al argumento que se pasará a la función start_routine cuando se inicie el hilo. Puede ser cualquier tipo de datos que desees pasar a la función.

__pthread_detach()__

Esta función se utiliza para marcar un hilo como "desprendido" para que el sistema pueda encargarse de limpiar sus recursos de forma automática una vez que haya finalizado.

__pthread_join()__

Se utiliza para esperar a que un hilo (thread) en un programa termine su ejecución. Se utiliza para sincronizar la ejecución del hilo principal con la finalización de otro hilo. La función pthread_join bloquea la ejecución del hilo llamante hasta que el hilo que se está esperando haya terminado. Es útil cuando necesitas asegurarte de que ciertos hilos hayan terminado su ejecución antes de continuar con otras partes del programa o cuando necesitas recopilar resultados de hilos secundarios.

el primer argumento es el identificador del hilo que quieres cerrar, mientras que el segundo es el vaor de retorno, si no se usa, se pondra NULL.

__pthread_mutex_init()__
Se utiliza para inicializar un objeto de tipo "mutex" (mutexes) en un programa que utiliza hilos (threads). Los mutexes son una herramienta fundamental en la programación multihilo para lograr la sincronización y la exclusión mutua, lo que significa que permiten a los hilos cooperar y controlar el acceso concurrente a recursos compartidos.
Es importante destacar que después de utilizar un mutex, debes liberar sus recursos llamando a pthread_mutex_destroy. Esto es especialmente importante si el mutex fue inicializado dinámicamente con pthread_mutex_init. La función pthread_mutex_destroy libera los recursos asociados al mutex y debe llamarse cuando ya no se necesite.
El uso adecuado de mutexes es fundamental para garantizar que los hilos trabajen de manera sincronizada y segura en entornos multihilo. Los mutexes se utilizan para crear secciones críticas en las que solo un hilo puede acceder a un recurso compartido a la vez, evitando problemas de concurrencia como condiciones de carrera.

__pthread_mutex_destroy()__
Se utiliza para destruir o liberar un objeto mutex (mutexes). Esto es importante para garantizar una gestión adecuada de los recursos y prevenir posibles pérdidas de memoria.
Es fundamental que llames a pthread_mutex_destroy solo cuando estés seguro de que ningún hilo está utilizando el mutex y que ya no se necesitará. Si intentas destruir un mutex que todavía está siendo utilizado por un hilo activo, puede llevar a comportamientos indefinidos en tu programa.

__pthread_mutex_lock()__
Se utiliza en programación multihilo para adquirir la cerradura (lock) de un objeto mutex (mutexes). La adquisición de la cerradura de un mutex permite que un hilo entre en una sección crítica del código protegida por ese mutex, mientras que bloquea o pone en espera a otros hilos que intenten adquirir la misma cerradura. Esto se utiliza para lograr la exclusión mutua y garantizar que solo un hilo pueda acceder a un recurso compartido a la vez.

__pthread_mutex_unlock__
Se utiliza en programación multihilo para liberar o desbloquear la cerradura (lock).




# Como funciona esto:

0 comprobación de errores (numeros positivos, suficientes argumentos)
1 crea una lista de los filosofos