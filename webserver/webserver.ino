#include <SPI.h> //Az SPI kommunikációs protokoll használatához szükséges könyvtár
#include <EtherEncLib.h> //Az Ethernet shield által használt könyvtár beillesztése

static unsigned char ipaddr[] = { 192, 168, 1, 147 }; //A szerver ip címének megadása
static unsigned char macaddr[] = { 0x00, 0x11, 0x22, 0x44, 0x00, 0x25 }; //A szerver MAC címének megadása

EtherEncLib eElib(80); //A 80-as TCP port használata a Hypertext Transfer Protocol használatára

void setup()
{
  pinMode(10, OUTPUT); //Az SS-pin kimenetté alakítása
  Serial.begin(9600); //A soros porton történő kommunikáció bitrátája
  eElib.begin(ipaddr, macaddr); //Az eElib könyvtár használatának indítása valamin az ip és MAC cím átadása
  Serial.println("Szerver elindítva..."); //Megadott karakterlánc kiíratása a soros portra
}

void loop() //ciklus
{
  if ( eElib.available() ) //Feltétel vizsgálat:
  {
    if (eElib.isIndexHtml) //Feltétel vizsgálat:
    {
      eElib.print("<HTML>"); //A HTML tag kiíratása az eElib könyvtár segítségével
      eElib.print("<head> <meta charset=utf-8> </head>"); //Karakterkészlet beállítása a Magyar nyelv megjelenítéséhez
      eElib.print("<body style=background-color:#00CED1;>"); //A body tag kiíratása és a weblap hatterének beállítása
      eElib.print("<H1 style=text-align:center;>ARDUINO WEB SZERVER</H1>"); //A H1 es fejléc tag kiíratása
      eElib.print("<h2 style=text-align:center;>Ethernet shield-el</h2>"); //A H2 es fejléc tag kiíratása
      eElib.print("<center>"); //Középre igazítás
      eElib.print("<p>Ez a weblap az Arduinóra csatlakoztatható bővítőmodulok egyíkével az Ethernet shield-el készült.</p>"); //Szöveg megjelenítés
      eElib.print("Sajnos a rendelkezésünkre álló shield nem rendelkezik SD-kártya olvasóval ezért az Arduino UNO R3 FLASH memóriáját használja, mely mindössze 32kB.");
      eElib.print("Ennek ellenére egy alap html oldal megjelenítését eltudja végezni. Akár szenzorok által mért adatokat is megtudunk itt jeleníteni."); //Szöveg megjelenítés
      eElib.print("<br>"); //Sortörés végzése
      eElib.print("<center>"); //Középre igazítás
      eElib.print("<br>"); //Sortörés végzése
      eElib.print("<b>Például így:</b>"); //Vastagon jelölt szöveg megjelenítés
      eElib.print("<br>"); //Sortörés végzése
      eElib.print("Az <b>A2</b>-es analóg bemenet értéke: "); //Szöveg megjelenítése
      eElib.print(analogRead(A2)); //Az A2-es analóg bemenet értékének olvasásása és megjelenítése is egyben
      eElib.print("<br>"); //Sortörés végzése
      eElib.print("<br>"); //Sortörés végzése
      eElib.print("További tudnivalók az ethernet shield-ről és annak beszerzéséről az alábbi linkeken találhatóak:"); //Szöveg megjelenítése
      eElib.print("<p><a href=https://www.arduino.cc/en/Main/Arduino Ethernet Shield V1/>Arduino Ethernet Shield V1</a></p>"); //Hiperhivatkozás
      eElib.print("<p><a href=https://store.arduino.cc/arduino-ethernet-shield-2>Arduino Ethernet Shield V2</a></p>"); //Hiperhivatkozás
      eElib.print("<p><a href=https://www.heureka.sk/?h[fraze]=Ethernet+Shield+W5100>Beszerezhető itt</a></p>"); //Hiperhivatkozás
      eElib.print("</center>"); //Középre igazítás vége
      eElib.print("</form></body>"); //A form és body tag-ek vége
      eElib.print("</HTML>"); //A HTML tag vége
    }
    eElib.close(); //eElib könyvtárból való kilépés
  }
}
