# philosopher_42
En este proyecto no voy a dejar guia como tal, os dejo la documentación por si a alguien le puede ser útil y alguna que otra explicación.

![badge42](https://github.com/ducksdoor/pipex_42/assets/128644496/766bc96f-5dca-407e-a5f8-d2455489b1b4)

“Cualquier idiota puede escribir un programa que una computadora entiende, los verdaderos programadores pueden escribir código que los humanos entienden.” – Martin Fowler


- [funciones permitidas](#-funciones-permitidas)
- [Como plantearse el proyecto](#-Como-plantearse-el-proyecto)
- [preguntas o pruebas típicas](#-preguntas-o-pruebas-típicas)
- [Comandos Útiles](#-Comandos-Útiles)


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
Se utiliza para inicializar un objeto de tipo "mutex" (mutexes) en un programa que utiliza hilos (threads). Los mutexes son una herramienta fundamental en la programación multihilo para lograr la sincronización. Lo que significa que permiten a los hilos cooperar y controlar el acceso concurrente a recursos compartidos.
Es importante destacar que después de utilizar un mutex, debes __liberar__ sus recursos llamando a pthread_mutex_destroy(). Esto es especialmente importante si el mutex fue inicializado dinámicamente con pthread_mutex_init(). La función pthread_mutex_destroy() libera los recursos asociados al mutex y debe llamarse cuando ya no se necesite.
El uso adecuado de mutexes es fundamental para garantizar que los hilos trabajen de manera sincronizada y segura en entornos multihilo. Los mutexes se utilizan para crear secciones críticas en las que solo un hilo puede acceder a un recurso compartido a la vez, evitando problemas de concurrencia como condiciones de carrera.

__Mutex__
Abreviatura de "mutual exclusion" (exclusión mutua).
Su función principal es garantizar que solo un hilo a la vez pueda ejecutar una sección de código protegida por el mutex, lo que ayuda a prevenir condiciones de carrera y asegura la consistencia de los datos compartidos.
El funcionamiento básico de un mutex implica dos operaciones principales: 

Bloqueo (Lock):
Cuando un hilo desea acceder a una sección crítica de código o un recurso compartido, primero intenta adquirir el mutex asociado a ese recurso.
Si el mutex está desbloqueado, el hilo lo adquiere y continúa ejecutando su código dentro de la sección crítica. En este punto, el mutex se bloquea y otros hilos que intenten adquirirlo tendrán que esperar.
Si el mutex ya está bloqueado por otro hilo, el hilo actual se bloqueará (generalmente en un estado de espera) hasta que el mutex se desbloquee.

Desbloqueo (Unlock):
Cuando un hilo ha terminado de utilizar la sección crítica o el recurso compartido, libera el mutex llamando a la operación de desbloqueo.
Al liberar el mutex, este se vuelve disponible para otros hilos que estén esperando adquirirlo.
Otro hilo en espera puede adquirir el mutex y ejecutar su sección crítica, y así sucesivamente.

__pthread_mutex_destroy()__
Se utiliza para destruir o liberar un objeto mutex (mutexes). Esto es importante para garantizar una gestión adecuada de los recursos y prevenir posibles pérdidas de memoria.
Es fundamental que llames a pthread_mutex_destroy solo cuando estés seguro de que ningún hilo está utilizando el mutex y que ya no se necesitará. Si intentas destruir un mutex que todavía está siendo utilizado por un hilo activo, puede llevar a comportamientos indefinidos en tu programa.

__pthread_mutex_lock()__
int pthread_mutex_lock(pthread_mutex_t *mutex);

Se utiliza en programación multihilo para adquirir la cerradura (lock) de un objeto mutex (mutexes). La adquisición de la cerradura de un mutex permite que un hilo entre en una sección crítica del código protegida por ese mutex, mientras que bloquea o pone en espera a otros hilos que intenten adquirir la misma cerradura. Esto se utiliza para lograr la exclusión mutua y garantizar que solo un hilo pueda acceder a un recurso compartido a la vez.

__pthread_mutex_unlock__
int pthread_mutex_unlock(pthread_mutex_t *mutex);

Se utiliza en programación multihilo para liberar o desbloquear la cerradura (lock).

# Apuntes para entender el código en un futuro:

   - La variable phl->inf->dead sirvio en un primer momento para saber si un filosofo esta muerto pero tambien sirve para ver si estan todos llenos, en cualquiera de los casos para la ejecución al completo.









# Como plantearse el proyecto:

0 comprobación de errores de los argumentos:
 - Que no tenga suficientes argumentos o demasiados.
 - Que tenga números negativos o ceros.
 - Que todo sean números y no letras. (Que no tenga letras entre los numeros)
 - Que acepte  un solo signo positivo pero no signos negativos negativos.
 - Que admita espacios.

1 crea una lista de los filosofos. En mi ejecución, cada hilo tiene su propia lista con todos los datos necesarios para el proceso.

 - La lista de filosofos es circular, es decir, el último filosofo apunta al primero

2 Crea un sistema de cronometraje para ver como pasa el tiempo.

3 Los filosofos intentan comer, todos a la vez. Los hilos no se quedaran bloqueados de forma infinita hasta que consigan acceder al mutex que quieren bloquear, de tal forma que si estos mutrex no son liberados, nunca dejaran de intentar bloquearlos... Si se intenta bloquear un hilo que no existe se creara un comportamiento indefinido. Ademas de los que llamaremos tenedor, tendremos tambien que bloquear el printf para que no se escriban mensajes encima de los mensajes de los demas.

 - Dicho esto abra que conseguir que coman en relativo orden, unas de las ayudas/ideas que vienen muy bien serian : 
   - Crear todos los filosofos y en ese momento que empiecen a comer, algo asi como un pistoletazo de salida.
   - Hacer que los filosofos pares (por ejemplo) coman despues que los impares (así no se molestaran entre ellos)
   - Limpieza de todas las cosas que tengas abiertas cuando los programas se acaben.

4 En el momento en que un filosofo muera o todos los filosofos coman lo necesario, se acabara el programa.






# preguntas o pruebas típicas:

Segun el subject las pruebas con más de 200 filósofos no se deben realizar, asi que puedes directamente programar que tu código no acepte mas de 200 filosofos como parametro, ademas, no puedes realizar pruebas con time_to_die, time_to_eat o time_to_sleep establecidos en valores inferiores a 60 milisegundos.

- Antes de las pruebas podran hacerte preguntas del proyecto, deberas estar capacitado para responder a todas:
     + ¿Que es un hilo?
     + ¿Diferencias entre hilos e hijos?
     + ¿Que es y como funciona un Mutex?
     + ¿Que pasa si un mutex no se cierra correctamente?
     + 


 - Si o SI teneis que hacer estas pruebas, *EN SERIO, SON IMPORTANTES* y comprobar que vuestro proyecto funciona perfectamente, si estos casos fallan, suspendereis:

Prueba 1 800 200 200. El filósofo no debe comer y debe morir. (🧟‍♂️ Ademas debera morirse. Esto comprueba que exista solo un filoso🧟‍♀️ )
Prueba 5 800 200 200. Ningún filósofo debería morir. (🦉 Concretamente si no pasa esta prueba, no entregues el proyecto. Prueba a meter los 200 filosofos a ver si funciona bien. 🦉) 
Prueba 5 800 200 200 7. Ningún filósofo debería morir y la simulación debería detenerse cuando cada filósofo haya comido al menos 7 veces. (Es decir. Los cinco filosofos del ejemplo tienen que comer 7 veces como minimo. No uno 7 y el resto 6)
Prueba 4 410 200 200. Ningún filósofo debería morir. (Realmente si le metes 200 tampoco deberia morirse...)
Prueba 4 310 200 100. Debería morir un filósofo. (💀 Ademas deberia morirse rápido 💀)
Realizar pruebas con 2 filósofos y verificar los diferentes tiempos: una muerte con un retraso de más de 10 ms es inaceptable. 

Estas son las pruebas que si o si os van a hacer. Ahora os dejo una pequeña lista de pruebas que podrian machacaros. Asegurarse de que los filósofos mueran en el momento adecuado, que no roben tenedores...

LEAKS LEAKS Y MAS LEAKS.
  + (Si lanzas el programa con esto -fsanitize=address -g no tendria que dar fallos.)
  + Puedes usar esta llamada tambien void leaks(void)
  {
      system("leaks -q a.philo"); 
  }
Todo el tema de DATA_RACES. 
  +  Para eso podemos ejecutar esto en el makefile:  -fsanitize=thread -g

 - Filosofos en versión impar siempre dan más problemas. Hay que hacer muchas pruebas con los impares pues puede ser que esto de problemas...
   
 Prueba 4 400 200 600. Tambien puedes probar 4 400 800 200 ( 😴 Si un filosofo se duerme y tarda más en despertar que el tiempo de muerte, tendra que morirse antes de despertar y pasa lo mismo mientras esta comiendo.) 
 
 - Comprobar que no existen variables estaticas. Realmente al pasar la norminette te chivara si hay o no variables estáticas.

 - Aunque lo dice en la hoja de correcciones probar las versiones infinitas y las finitas. sobretodo cuando hay muchos filósofos. Hay que tener en cuenta que el tiempo que pasan los hilos corriendo, el tiempo que imprimen va a ir subiendo. Estaria mal si un filosofo imprime cosas con un numero superior antes que un filosofo con un número mayor. Te pongo un ejemplo, si un filosofo come a 100. Ya no se podra pintar nada en pantalla que ocurriera antes, como un filosofo que como a 80 o variedades.
   
 - Lo último que se imprima en pantalla tiene que ser que un filósofo a muerto o que un filósofo ha comido.
  
 - Comprobar que no existan funciones prohibidas como exit y que el parseo este relativamente bien. Aunque no sea un proyecto de parsear cosas. En todos los programas hay que parsear cosas.


 - Para nota: 

   + Prueba esto ; ./philo 4 300 250 200 1 (el programa deberia terminar cuando coman todos y no morir, aunque la prueba va muy justa, si despues de comer sigue ejecutandose el programa y se ve la muerte del filosofo, estará mal. )






# Comandos Útiles:

-fsanitize=address -g
-fsanitize=thread -g

void leaks(void)
{
   system("leaks -q a.out"); 
}

atexit(leaks);
