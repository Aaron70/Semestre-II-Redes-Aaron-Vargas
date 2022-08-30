## Estructura del sistema telefónico

En el ámbito de las comunicaciones, las conexiones de dos alambres entre el teléfono de cada suscriptor y la oficina central se conoce como **Circuito local**.
Si un suscriptor conectado a una oficina central determinada llama a otro suscriptor conectado a la misma oficina central, el mecanismo de conmutación dentro de la oficina establece una conexión eléctrica directa entre los dos circuitos locales.

Cada oficina central tiene una o más líneas salientes a uno o más centros de conmutación cercanos, llamados **oficinas interurbanas** (si están dentro de la misma área local, **oficinas en tándem**). Estas líneas se llaman **troncales de conexión interurbanas**.
Las centrales interurbanas primarias, seccionales y regionales se comunican entre sí mediante **troncales interurbanas** de gran ancho de banda.

Entre las oficinas de conmutación se usan ampliamente cables coaxiales, microondas y, en especial, fibra óptica. Con el advenimiento de la
fibra óptica, la electrónica digital y las computadoras, actualmente todas las troncales y los conmutadores son digitales, y el circuito local queda como el único elemento de tecnología analógica del sistema.

El sistema telefónico consiste en tres componentes principales:

1. Circuitos locales (cables de par trenzado que van hacia las casas y las empresas).

2. Troncales (fibra óptica digital que conecta a las oficinas de conmutación).

3. Oficinas de conmutación (donde las llamadas pasan de un troncal a otro).

### El circuito local: Módem, ADSL e inalámbrico

El circuito local se conoce también como de "última milla" (la conexión hacia el cliente), aunque la longitud puede ser de varias millas. Cuando una computadora desea enviar datos digitales sobre una línea analógica de acceso telefónico, es necesario convertir primero los datos a formato analógico para transmitirlos sobre el circuito local, lo cual lo realiza el modem.
Los datos se convierten a formato digital en la oficina central de la compañía telefónica para transmitirlos sobre las líneas troncales que abarcan largas distancias.

Las líneas de transmisión tienen tres problemas principales: atenuación, distorsión por retardo y ruido. La **atenuación** es la pérdida de energía conforme la señal se propaga hacia su destino. La pérdida se expresa en decibeles por kilómetro. La cantidad de energía pérdida depende de la frecuencia.

Por si esto no fuera poco, los diferentes componentes de Fourier se propagan a diferente velocidad por el cable. Esta diferencia de velocidad ocasiona una **distorsión** de la señal que se recibe en el otro extremo. Otro problema es el **ruido**, qué es energía no deseada de fuentes distintas al transmisor. El movimiento al azar de los electrones en un cable causa el ruido térmico y es inevitable. La diafonía se debe al acoplamiento inductivo entre dos cables que están cerca uno del otro.

###  Troncales y multiplexión

Las compañías telefónicas han desarrollado esquemas complejos para multiplexar muchas conversaciones en una sola troncal física. Estos esquemas de multiplexión se pueden dividir en dos categorías principales: FDM (Multiplexión por División de Frecuencia) y TDM (Multiplexión por División de Tiempo). En FDM el espectro de frecuencia se divide en bandas de frecuencia, y cada usuario posee exclusivamente alguna banda. En TDM los usuarios esperan su turno (en round-robin), y cada uno obtiene en forma periódica toda la banda durante un breve lapso de tiempo.

Un estándar muy difundido es el de 12 canales de voz a 4000 Hz multiplexados dentro de la banda de 60 a 108 kHz. Esta unidad se llama grupo. La banda de 12 a 60 kHz a veces se usa para otro grupo.

Se pueden multiplexar cinco grupos (60 canales de voz) para formar un supergrupo. La siguiente unidad es el grupo maestro, que se compone de cinco supergrupos (en el estándar del CCITT) o de 10 supergrupos (en el sistema Bell).

## Multiplexión por división de longitud de onda

Para los canales de fibra óptica se utiliza una variante de la multiplexión por división de frecuencia llamada WDM (Multiplexión por División de Longitud de Onda). Aquí, cuatro fibras se juntan en un combinador óptico, cada una con su energía presente a diferentes longitudes de onda. Los cuatro haces se combinan en una sola fibra compartida para transmisión a un destino distante. En el extremo distante, el haz se divide en tantas fibras como hayan entrado. Cada fibra saliente contiene un núcleo corto especialmente construido que filtra todas las longitudes de onda, excepto una. Las señales resultantes pueden enrutar a su destino o recombinarse en diferentes formas para transporte adicional multiplexado.

Cuando el número de canales es muy grande y las longitudes de onda están espaciadas entre sí de manera estrecha, por ejemplo a 0.1 nm, el sistema se conoce como DWDM (WDM Densa). Cabe señalar que la razón por la que WDM es popular es que la energía de una sola fibra por lo general es de unos cuantos gigahertz debido a que en la actualidad es imposible convertir con mayor rapidez entre los medios óptico y eléctrico.

## Multiplexión por división de tiempo

Aunque FDM aún se utiliza sobre cables de cobre o canales de microondas, requiere circuitos analógicos y no es fácil hacerla con una computadora. En contraste, TDM puede manejarse por completo mediante dispositivos digitales y a ello se debe su popularidad en los últimos años. Desgraciadamente, sólo se puede utilizar para datos digitales.

Las señales analógicas se digitalizan en la oficina central con un dispositivo llamado codec. El codec toma 8000 muestras por segundo. A una velocidad de muestreo menor, la información se perdería; a una mayor, no se ganaría información extra. Esta técnica se llama PCM (Modulación por Codificación de Impulsos). La PCM es el corazón del sistema telefónico moderno. En consecuencia, virtualmente todos los intervalos de tiempo dentro del sistema telefónico son múltiplos de 125 μseg.

Por lo común, las señales analógicas se muestrean por asignación cíclica (en round robin), alimentando el flujo analógico resultante al codec en lugar de tener 24 codecs y después mezclar la salida digital. Cada uno de los 24 canales inserta, a la vez, 8 bits en el flujo de salida. 140 LA CAPA FÍSICA CAP. 2 Siete bits son de datos y uno es de control, con lo que se obtienen 7 × 8000 = 56,000 bps de datos, y 1 × 8000 = 8000 bps de información de señalización por canal.

Una trama consiste en 24 × 8 = 192 bits más un bit extra para entramado, lo que da 193 bits cada 125 μseg. Esto produce una tasa de transmisión de datos bruta de 1.544 Mbps. El bit número 193 se usa para sincronización de la trama y sigue el patrón 0101010101... Por lo general, el receptor verifica de manera continua este bit para asegurarse de que no ha perdido la sincronización. Si llegara a perder sincronía, el receptor puede esperar hasta detectar otra vez el patrón y volverse a sincronizar. 
Cuando se utiliza un sistema T1 exclusivamente para datos, sólo 23 de los canales llevan datos. El vigésimo cuarto lleva un patrón especial de sincronización que permite la recuperación rápida en caso de que la trama pierda sincronía.

Hay dos variantes (incompatibles). En la señalización por canal común, el bit extra (que se anexa al final y no al principio de la trama de 193 bits) adopta los valores 10101010... en las tramas nones y contiene información de señalización para todos los canales de las tramas pares. En la otra variante, la señalización por canal asociado, cada canal tiene su propio subcanal privado de señalización. Se establece un subcanal privado asignando uno de los ocho bits de usuario de cada sexta trama a funciones de señalización, así que cinco de cada seis muestras tienen 8 bits de ancho y la otra sólo tiene 7.

### Televisión por cable

## Televisión por antena comunal

El sistema consistió inicialmente en una antena grande en la cima de una colina para captar la señal de televisión, un amplificador, llamado amplificador head end, para reforzar y un cable coaxial para enviarla a las casas de las personas.

En 1974, Time, Inc. inició un nuevo canal, Home Box Office, con contenido nuevo (películas) y que se distribuía sólo por cable. Le siguieron otros canales que se transmitían sólo por cable y cuyo contenido eran noticias, deportes, cocina entre muchos otros. Este desarrollo dio origen a dos cambios en la industria. Primero, las grandes compañías comenzaron a comprar sistemas de cable existentes e instalar nuevo cable para adquirir más suscriptores. Segundo, surgió la necesidad de conectar múltiples sistemas, por lo general en ciudades distantes, para distribuir los nuevos canales por cable.

## Internet a través de cable

A través de los años, el sistema de televisión por cable creció y los cables entre las distintas ciudades se reemplazaron por fibra de ancho de banda alto, de manera similar a lo que sucedió con el sistema telefónico. Un sistema con fibra para distancias considerables y cable coaxial para las casas se conoce como sistema HFC (Red Híbrida de Fibra Óptica y Cable Coaxial). Los convertidores electro ópticos que interactúan entre las partes óptica y eléctrica del sistema se llaman nodos de fibra, un nodo de fibra puede alimentar múltiples cables coaxiales.

En los vecindarios, muchas casas comparten un solo cable, mientras que en el sistema telefónico, cada casa tiene su propio circuito local privado. Cuando se emplea en la difusión de televisión, esta compartición no tiene importancia. Todos los programas se difunden a través del cable y no importa si hay diez o tres o 10,000 televidentes. Cuando el mismo cable se utiliza para el acceso a Internet, el hecho de que haya 10 o 10,000 usuarios tiene mucha importancia.  Entre más usuarios haya, habrá más competencia por el ancho de banda.

## Asignación de espectro

Los canales de televisión por cable en Norteamérica normalmente ocupan la región de 54–550 MHz (excepto por la radio FM de 88 a 108 MHz). Estos canales tienen 6 MHz de ancho, incluyendo las bandas de protección. En Europa el extremo inferior por lo general es de 65 MHz y los canales tienen un ancho de 6–8 MHz para la resolución más alta requerida por PAL y SECAM, pero en lo demás el esquema de asignación es similar. La parte baja de la banda no se utiliza.
La solución elegida fue introducir canales ascendentes en la banda de 5–42 MHz (un poco más arriba en Europa) y utilizar las frecuencias en el extremo superior para el flujo descendente.

Debido a que todas las señales de televisión son descendentes, es posible utilizar amplificadores ascendentes que funcionen en la región de 5–42 MHz y amplificadores descendentes que sólo funcionen a 54 MHz y mayor. Por lo tanto, obtenemos una asimetría en los anchos de banda de los flujos ascendente y descendente debido a que hay disponible más espectro arriba del espectro de la televisión que abajo.

## Módems de cable

El acceso a Internet requiere un módem de cable, un dispositivo que tiene dos interfaces: una en la computadora y la otra en la red de cable. En los primeros años de Internet por cable, cada operador tenía un módem de cable patentado, que era instalado por un técnico de la compañía de cable. Sin embargo, pronto quedó claro que un estándar abierto podría crear un mercado de módems de cable competitivo y bajar los precios, con lo que se alentaría el uso del servicio.

En consecuencia, los operadores de cable más grandes se unieron a una compañía llamada CableLabs para producir un módem de cable estándar y probar la compatibilidad de productos. Este estándar, llamado DOCSIS (Especificación de Interfaz para Servicio de Datos por Cable), está comenzando a reemplazar a los módems patentados.

La interfaz módem a computadora es directa. En la actualidad, con frecuencia es la Ethernet a 10-Mbps (y en ocasiones es USB). En el futuro, todo el módem podría ser una pequeña tarjeta conectada en la computadora, al igual que con los módems internos V.9x.

El otro extremo es más complicado. Una gran parte del estándar tiene que ver con la ingeniería de radio. La única parte que vale la pena mencionar aquí es que los módems de cable, al igual que los ADSL, siempre están activos. Establecen una conexión cuando se encienden y la mantienen todo el tiempo que tengan energía, debido a que los operadores de cable no cobran por el tiempo de conexión.

## ADSL en comparación con el cable

Además, estudiamos otro sistema con un canal compartido como el cable: el sistema telefónico móvil. Aquí un grupo de usuarios también comparte una cantidad fija de ancho de banda. Por lo general, la FDM y la TDM lo dividen estrictamente en porciones fijas entre los usuarios activos pues el tráfico de voz es suave. Pero para el tráfico de datos, esta división rígida es muy ineficiente debido a que los usuarios de datos por lo general están inactivos, en cuyo caso el ancho de banda reservado es un desperdicio. No obstante, en este caso el acceso al cable es más parecido al sistema telefónico móvil que al sistema fijo.

La disponibilidad es un tema en el que ADSL y el cable difieren. Todas las personas tienen teléfono, pero no todos los usuarios están lo suficientemente cerca de su oficina central local para obtener ADSL. Por otro lado, no todos los usuarios tienen cable, pero si usted tiene cable y la compañía proporciona acceso a Internet, puede obtenerlo. Para el nodo de fibra o el amplificador head end la distancia no es un problema. También vale la pena mencionar que debido a que el cable inició como un medio de distribución de televisión, pocos negocios cuentan con él.
