#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//si tu display no usa pin reset, aquí pon -1 para no desperdiciar un pin de tu arduino
    Adafruit_SSD1306 display(-1);


void setup(){
    Serial.begin(9600);
    //Inicio el display para la AxAA dirección
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3D (for the 128x64)

    // Borrar display
      display.clearDisplay();
      display.drawRect(0,0,100,64,WHITE); //dibuja rectángulo vacio
      //display.fillRect(0,0,100,64,WHITE); //dibuja rectángulo lleno
      //display.drawRoundRect(0,0,100,64,20,WHITE); //dibuja rectángulo redondeado

      //display.fillRoundRect(0,0,100,64,20,WHITE); //dibuja rectángulo redondeado
      //display.drawTriangle(10,10,45,60,60,60,WHITE);
      //display.fillTriangle(10,10,45,60,60,60,WHITE);

      display.setTextSize(1);
      display.setTextColor(WHITE,BLACK);
      display.setCursor(5,5);
      display.println("Hello, world!");
      display.setCursor(5,15);
      display.println("Hello, world2!");
      display.display();
}

void loop(){

}
