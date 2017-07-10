# Backup distribuido

## Referencias del código

Este es el directorio del programa final a presentar. El código generado ha surgido reutilizando pautas y códigos de los mencionados en los siguientes links: 

- Servidor: http://softpei.blogspot.com.es/2013/07/desarrollo-de-un-servidor-tcpip-con-el.html
- Cliente: http://softpei.blogspot.com.es/2013/07/desarrollo-de-un-cliente-tcpip-con-el.html

Se han generado también varias clases utilizando el resto de códigos del repositorio (MySocket, MyServer, MyQTcpServer..). 

## Breve Descripción del Proyecto. 

Este proyecto contiene un programa Servidor y un programa Cliente. La función global de ambos programas es realizar copias de seguridad. El funcionamiento general se basa simplemente en que un cliente se conecte con el servidor a través de un puerto y dando la ip del servidor como dato; este cliente transfiere un directorio y todo su contenido al servidor, que podrá enviarlo a otro cliente para realizar la copia de seguridad o quedarse en el mismo servidor. Se pone al servidor por defecto como LocalHost (127.0.0.1). 


