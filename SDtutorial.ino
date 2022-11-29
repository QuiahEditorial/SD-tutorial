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
Serial.begin(9600);
if (!SD.begin(4))                                     // inicia la tarjeta SD en puerto 4
{Serial.println("!SD"); return;}

SD.exists("Bez.txt");                                  // Comprueba que exista el archivo

Bez = SD.open("Bezier.txt");                                // Abre el archivo Bezier.txt
while (Bez.available())                            // mientras el archivo esté disponible
{ Serial.write(Bez.read());}         // Lee el archivo Bezier.txt y escríbelo en pantalla

A = Bez.size(); Serial.println(A);                        // Evalúa el tamaño del archivo

Bez.seek(0);                                               // Se ubica en el n-ésimo byte
a = Bez.read(); Serial.println(a);                                      // se lee el byte

Bez.seek(0);
while (Bez.available())
  {
  a = Bez.read();
  b = b + a;                                                      // concatena caracteres
  C = Bez.position();                                        // Evalúa la posición actual
  if(a==10) { break; }                                   // 10 en ascii es salto de línea
  }
  Serial.print(b); Serial.println(b[3]);    // se imprime el tercer caracter de la cadena

Bez.close();                                                         // Cierra el archivo

Bzr = SD.open("log.txt", FILE_WRITE);                              // Crea un archivo txt
Bzr.print(b);                                                    // Escribe en el archivo
Bzr.close();
}

void loop()
{

}
