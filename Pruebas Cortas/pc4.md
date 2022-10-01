# Prueba Corta 04
## **Aaron Vargas Valerin**


1. ### Explique el concepto de Time Division Multiplexing y Frequency Division Multiplexing. (25 pts)

#### Time Division Multiplexing

El time division multiplexing otorga una cierta cantidad de tiempo a cada dispositivo para que realice el envío de datos, durante este tiempo el dispositivo es "dueño" del medio y es capaz de utilizar el 100% del ancho de banda disponible en el medio, mientras los otros dispositivos esperan su turno en el round robin.

#### Frequency Division Multiplexing

El frequency division multiplexing divide el ancho de banda del medio en canales de anchos de bandas menores (bandas) y se el otorga una banda o canal a cada dispositivo del cual el dispositivo es dueño, al utilizar este método se desperdicia un poco de ancho de banda ya que deben haber "banda guardas" que evitan choques o interferencias entre los canales divididos. Una desventaja clara es que entré más dispositivos hayan conectados menor será el ancho de banda para cada uno.

2. ### Explique el concepto de colisión durante el proceso de asignación del canal, comente las diferencias entre medios guiados y medios no guiados. (25 pts)

Cuando un dispositivo desea realizar un envío de datos, este debe observar el medio para determinar si el medio está disponible o no, si el medio está disponible procede a enviar los datos, si no esta disponible este se limita a esperar hasta que se desocupe.

Sin embargo, existe la posibilidad de que un dispositivo observer le medio y determine que el medio no está siendo ocupado, cuando realmente sí hay datos que están pasando por él, pero que no han llegado hasta el dispositivo, de esta manera el dispositivo "piensa" erroneamente que el medio está desocupado cuando realmente no lo está y se ocaciona una colisión de datos.

#### Diferencias entre medios guiados y no guiados

Los medios guiados son medios confiables como la fíbra optica, el par trenzado u otros medios cableados, estos medios tienen una  gran tolerancia a interferencias, es decir, que cuentan con un porcentaje de pérdida de tramas considerablemente bajo. Mientras que los medios no guiados wireless, tienen un gran porcentaje de colisión y pérdida de datos debido a que en el aire hay menos control y muchos más elementos que podrían interferir en la comunicación.
Es recomendable enviar tramas pequeñas por medios no guiados debido a que entre más grande sea la trama, mayor será el riesgo de colisión, mientras que por medios guiados es mejor envíar tramas más grandes ya que el riesgo de colisión es más bajo.

3. ### ¿Como funciona el algoritmo de asignación del canal Aloha y Aloha Ranurado? Explique (20 pts)

El algoritmo de transimisión de Aloha permite que varios disposivos transmitan al mismo tiempo, al tener un solo canal compartido es altamente probable que las tramas transmitidas colisiones y se dañen, entonces todos los dispositivos están escuchando por el feedback de sus tramas para saber si llegaron correctamente o hubo una colisión en el medio. Sí hubo una colisión entonces los dispositivos se dormiran una cantidad de tiempo aleatoria (debe ser aleatoria para evitar que los mismos dispositivos envien tramas y sigan chocando siempre) de esta manera la aletoreidad se entregen en tiempos distintos sin que choquen y haya una comunicación exitosa.

La principal diferencia entre el ranuardo y el puro, es que en el ranurado los dispositivos no pueden transmitir cuando ya están listos para enviar datos, si no que deben esperar hasta el comienzo de la siguiente ranura para poder empezar a transmitir sus tramas, de esta manera se reduce la probabilidad de que dos tramas choquen ya que en el método puro aunque la colisión sea parcial, es decir, solo una parte (inico o final) de la trama se dañe, la trama será completamente descartada y deberá ser enviada de nuevo.

4. ### ¿Cuáles son las diferencias entre Hub y Switch? ¿Porqué razón el Switch es mejor?

#### HUB
    - Tiene grandes dominios de colisión.
    - No conoce quienes están conectados a él.
    - Hace el "enrutamiento" con un mensaje de difusión.
    - Es half duplex

#### Switch
    - Tiene muy pocos dominios de colisión y hasta pueden llegar a ser nulos.
    - Conoce los dispositivos que están conectados a él (tiene tablas de ip)
    - Genera circuitos virtuales los cuales están separados. Por lo que no hace broadcast.
    - Permite hacer segregación de tráfico.

Es decir, que el switch es mucho mejor que los HUBs ya que disminuyen el dominio de colisión, además de que estos conocen las IPs de los dispositivos que están conectados a sus puertos, por lo que no se generan retrasos por colisiones entre sus medios. Es posible reducir el dominio de colisión de un switch a nulo utilizando medios simplex y de esta manera no habrá forma de que las tramas interfieran entre sí. Además de crear internamente circuitos virtuales por lo que se asegura que los datos solamente lleguen a su destino. En fin, no usar HUBs :D

5. ### ¿Es posible transportar tramas Ethernet embebidas en imágenes PNG? Justifique su respuesta. (30 pts)

Sí, debido a que las tramas son datos con la información necesaria (payload, header y trailer) podemos "codificar" o introducir esta información dentro de una imagen png.

Para esto sabemos que nuestro "ancho de banda" será la capacidad de informació que quepa en la sección de datos de una imágen png, por lo tanto en la sección de "datos", es decir, respetando la información del formato png header, paleta de colores, etc, colocaremos nuestras tramas en la sección donde van los píxeles de las imagenes.

Al inicio de la sección de datos colocaremos nuestro header con la información necesaria de nuestra trama (scr, dest, número de trama, etc), en el medio nuestro payload y al final nuestro trailer con la CRC de nuestra trama.

El receptor lo que deberá hacer es ignorar las secciones definidas del png y tomar la información dentro de la sección de datos (nuestra trama) y procesarla normalmente con el formato definido de nuestra trama.