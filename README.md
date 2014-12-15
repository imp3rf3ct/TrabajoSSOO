TrabajoSSOO
===========

Repositorio Dedicado al trabajo opcional de sistemas operativos de la escuela superior de informatica de la UCLM

Consta de los siguientes ejercicios:

escudo1.c
=========
Construir un programa llamado escudo1 que ejecute un bucle sin fin y responda
a la señal indicada en su argumento (escudo1 <número>) ignorando la señal. Probar
su ejecución desde el shell utilizando el programa de sistema kill y comprobar
la diferencia de comportamiento del programa según la señal recibida. Ejecute el
programa con la señal SIGINT e intente abortar el programa pulsando la combinación
de teclas <Ctrl-C>. Compruebe el comportamiento del programa con la
señal SIGKILL. Se aconseja consultar la página del manual correspondiente a la
llamada al sistema signal.

escudo2.c
=========
Construir un programa llamado escudo2 que ejecute un bucle sin fin y responda
a la señal indicada en su argumento (escudo2 <número>) escribiendo por la salida
estándar el mensaje “Recibida la señal <número de la señal recibida>” y terminando.
Probar su ejecución desde el shell. Se aconseja consultar las páginas del
manual correspondientes a las llamadas al sistema signal y _exit.

escudo3.c
=========
Construir un programa llamado escudo3 que ejecute un bucle sin fin y responda
a la señal indicada en su argumento (escudo3 <número>) escribiendo por la salida
estándar el mensaje “Recibida la señal <número de la señal recibida>” y continúe
la ejecución del bucle. Probar su ejecución desde el shell. Se aconseja consultar
la página del manual correspondiente a la llamada al sistema signal.

alarma.c
========
Construir un programa llamado alarma que escriba cada n segundos en la salida
estándar el mensaje “Alarma <número>” siendo <número> el número de mensajes
de alarmas escritos. El programa no debe tener una espera activa y su sintaxis
será alarma <segundos de espera>. Se aconseja consultar las páginas del manual
correspondientes a las llamadas al sistema signal, alarm y pause.

mikill.c
========
Construir un programa llamado mikill que envíe una señal al proceso que se
desee. La sintaxis del programa será mikill <nº de la señal> <pid del proceso
destinatario>. Probar la ejecución de los programas anteriores utilizando mikill.
Se aconseja consultar la página del manual correspondiente a la llamada al sistema
kill.

entrada.c
=========
Construir un programa llamado entrada que ejecute el programa indicado en la
línea de ordenes con su entrada estándar redirigida al archivo propuesto. La sintaxis
del programa será entrada <archivo> <programa> <arg1> <arg2> … <último
argumento>. Probar su ejecución desde el shell (por ejemplo, entrada datos.txt
wc -l -w). Se aconseja consultar las páginas del manual correspondiente a las llamadas
al sistema execvp, open y dup.

salida.c
========
Basado en el programa anterior construir otro programa llamado salida que redirija
la salida estándar en vez de la entrada estándar.

tuberia.c
=========
Construir un programa llamado tuberia que lance dos subprocesos que ejecuten
dos programas indicados en la línea de órdenes de tal forma que la salida estándar
del primero se conecte a la entrada estándar del segundo. El programa tuberia
deberá esperar a la terminación de los dos programas y escribirá una línea en la
salida estándar por cada programa con el pid del proceso que ha terminado y su
código de terminación. La sintaxis del programa será tuberia <programa1> <programa2>.
Probar su ejecución desde el shell (por ejemplo, tubería ls sort). Se
aconseja consultar las páginas del manual correspondiente a las llamadas al sistema
fork, execlp, _exit, pipe, dup, wait y/o waitpid.

consumidor.c
============
Construir un programa llamado consumidor que copie el contenido de una tubería
cuyo nombre recibe como argumento en la salida estándar. El programa debe continuar
esperando datos de la tubería aunque haya leído un fin de archivo. La sintaxis
del programa será consumidor <nombre de la tubería>. Crear en el directorio
de trabajo actual una tubería con nombre ejemplo-pipe mediante el programa
de sistema mkfifo. Probar la ejecución del programa consumidor y escribir con
otro programa en la tubería (por ejemplo, con el programa de sistema cat). Compruebe
que el programa consumidor sigue leyendo datos en sucesivas ejecuciones
de los programas que escriben en la tubería. También compruebe que si el programa
consumidor termina y los otros programas siguen escribiendo en la tubería,
en la siguiente ejecución del programa consumidor se obtienen todos los datos
escritos. El programa debe minimizar el tiempo de CPU invertido en los bucles
de espera. Se aconseja consultar las páginas del manual correspondientes a las
llamadas al sistema open, read, write y sleep.

mimkfifo.c
==========
Construir un programa llamado mimkfifo que cree una tubería con nombre. La
sintaxis del programa será mimkfifo <permisos en octal> <nombre de la tubería>.
Probar la ejecución del programa anterior creando la tubería con mimkfifo. Se
aconseja consultar las páginas del manual correspondientes a la llamada al sistema
mkfifo y a la función de la biblioteca estándar sscanf.

padre.c
=======
Construir un programa denominado padre que cree un número determinado (definido
en una constante) de procesos que ejecuten un código de programa denominado
hijo. El código del programa hijo hará que cada proceso hijo duerma un
número aleatorio de segundos entre 1 y un número máximo y, justo a continuación,
finalizará. El número máximo de segundos será indicado por el programa
padre a la hora de asignar un nuevo segmento de código a cada proceso hijo
mediante la primitiva execl, siendo la responsabilidad de cada proceso hijo generar
un número aleatorio (entre 1 y ese número máximo) que utilizará en la llamada
a la primitva sleep para dormir.
