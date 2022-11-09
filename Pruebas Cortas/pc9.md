1. # Pregunta 01
    a. ¿Es posible enviar datos que no sean HTTPs sobre el puerto 443?
        
        Sí es posible, ya que los puertos o well known ports, son estándares que se recomiendan seguir, sin embargo, no hay una limitación técnica que impida enviar datos por el puerto 443 que no sean HTTPs.

    b. Suponiendo que creamos el protocolo ATP over SSL (ATPs), describa un subprotocolo para el establecimiento de una conexión SSL.

        ### SSL Handshake protocol

        Después de realizar el handshake de TCP para establecer la conexión. El servidor y el cliente se encuentran hablando en texto plano, por lo que necesitan realizar el SSL Handshake protocol para establecer una conexión segura.

        Para esto el cliente inicia con un Client Hello hacia el server con el IP y puerto obtenidos durante el TCP Handshake. El server responde Sever Hello y durante esta transmisión de información, se hizo el traspaso de información como la version del protocolo, el Id de la session, la lista de Cipher Suites soportados por el cliente y el Cipher Suite elegido por el servidor. Así como el servidor le envía el certificado digital al cliente.
        El cliente verifica el certificado y el server envía una solicitud del certificado del cliente, este le envía el certificado (ya encriptado con la llave publica del servidor) el servidor verifica el certificado y ambos se intercambian un mensaje de finalizado.

    c. Si existe el protocolo ATPs, ¿Es posible transportar ATPs sobre HTTPs?

        Sí es posible, ya que una vez más, no hay una limitante técnica que no lo permita, es más, podría decirse que tendría varias capas de seguridad, es decir, el ATPs por sí mismo estaría encriptado y al enviarse através de HTTPs, se volvería a encriptar los datos encriptados por el ATPs. De manera que el ATPs encripta los datos con sus llaves y el protocolo los encripta nuevamente, por lo que del lado del receptor, debería desencriptar los datos con el protocolo HTTPs primeramente y luego con la llave de ATPs ya conocida.

    d. Desde un punto de vista de firewalls, ¿Porqué sería muy conveniente usar el puerto TCP/80 en lugar de puerto TCP/666?.

        Porque el puerto TCP/80 es un well known port, es decir, que se espera que hayan muchas peticiones dirigidas a puertos 80, por lo que utilizar el puerto TCP/666 sería sencillo de bloquear ya que muchos firewalls solo permiten el paso por puertos como TCP/80, TCP/443 y otros puertos estándares.

2. # Pregunta 02

Primeramente debemos calcular los siguientes parámetros primero 
1. Seleccionar dos números primos grandes, p y q (generalmente de 1024 bits). 
2. Calcular n = p X q  y  z = (p - 1) X (q - 1). 
3. Seleccionar un número primo con respecto a z, llamándolo d. 
4. Encontrar e tal que e X d = 1 mod z.

Una vez calculados los parámetros, para empezar la encriptación dividimos el texto plano (cadena de bits) en bloques, para que 
cada mensaje, P, caiga en el intervalo 0 ≤ P < n. Esto puede hacerse agrupando el texto plano en bloques de k bits, donde k es el entero más grande para el que 2k < n es verdadero. 
Para encriptar un mensaje, P, se calcula C = Pe (mod n). Para desencriptar C, se calcula P = Cd (mod n). 
Para encriptar, se necesitan e y n. Para llevar a cabo la desencriptación, se requieren d y n. Por lo que la clave pública consiste en el par (e, n), y la clave privada consiste en (d, n). Como la seguridad de este método se basa en la dificultad para factorizar números grandes. Si el criptoanalista pudiera factorizar n el cual es conocido publicamente, podría encontrar p y q y, a partir de éstos, z. Equipado con el conocimiento de z y de e, puede encontrar d usando el algoritmo de Euclides.