// Tutorial de la librería SD, incluida con el IDE de Arduino

#include <SD.h>

File Bez;                                              // File es una variable de archivo
File Bzr;
File Log;

int A;
int B;
int C;

char a;                                                                       // caracter
String b;                                                         // cadena de caracteres

void setup()
{
Serial.begin(9600);                                                // comunicación serial
if (!SD.begin(4)) {Serial.println("!SD"); return;}    // inicia la tarjeta SD en puerto 4
                                                           // Por defecto D4 es CS de SPI
SD.exists("Bez.txt");                                  // Comprueba que exista el archivo
                                                           // Puede incluir sudirectorios
Bez = SD.open("Bezier.txt");                                // Abre el archivo Bezier.txt
while (Bez.available()) { Serial.write(Bez.read());}         // Lee el archivo Bezier.txt
                                           // Sin el while sólo se escribe el primer byte
A = Bez.size(); Serial.println(A);                        // Evalúa el tamaño del archivo

Bez.seek(0); a = Bez.read(); Serial.println(a);            // Se ubica en el n-ésimo byte

Bez.seek(0);
while (Bez.available())
  {
  a = Bez.read();
  b = b + a;                                                      // concatena caracteres
  C = Bez.position();                                        // Evalúa la posición actual
  if(a==10) { break; }
  }
  Serial.print(b); Serial.println(b[3]);

Bez.close();                                                         // Cierra el archivo

Bzr = SD.open("log.txt", FILE_WRITE);                              // Crea un archivo txt
Bzr.print(b);                                                    // Escribe en el archivo
Bzr.close();
}

void loop()
{

}
