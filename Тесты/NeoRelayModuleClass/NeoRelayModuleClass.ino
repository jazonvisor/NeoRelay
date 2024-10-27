/**/
#include "defines.h"
#include "variables.h"
/*Подключаем клавиатурны модуль на пять кнопок KB45037*/
#include "KB45037.h"
/*Хех, работаем именно с этой библиотекой*/
#include <Adafruit_NeoPixel.h>
/*Подключаем эту библиотеку после подключения библиотеки Adafruit_NeoPixel, здесь нужно передать в конструктор объект*/
#include "NeoRelayBlock.h"



/*Создаём объект для работы с клавиатурным модулем*/
KB45037 Keypad(KEYPAD_PIN);

/*Создаём объект класса Adafruit_NeoPixel, вместо пиксельной ленты блок-модуль на 2 реле*/
Adafruit_NeoPixel BlockRelay(RELAY_QUANTITY, BLOCK_RELAY_PIN, NEO_GRB + NEO_KHZ800);

/*Создаём объекты класса RelayTimer*/
NeoRelayBlock Relay1;
NeoRelayBlock Relay2;

void setup(){
  /*Для отладки*/
  //Serial.begin(9600);
  /**/
  delay(3000);
  /*Связывание объектов RelayTimer с объектом BlockRelay(а точнее с объектом Adafruit_NeoPixel)*/
  Relay1.ConnectWith(BlockRelay);
  Relay2.ConnectWith(BlockRelay);
  /*Назначение адресов*/
  Relay1.SetAddress(RELAY1_ADDRESS);
  Relay2.SetAddress(RELAY2_ADDRESS);
  /*Инициализация блока*/
  BlockRelay.begin();
  /*Задаём команду - выключение всех модулей группы/блока*/
  BlockRelay.setPixelColor(0,RELAYS_OFF);
  /*Передать сигнал управления на релейные модули - выключаем*/
  BlockRelay.show();
}

void loop(){
  /*Проверяем работу кнопок, если было событие нажатия*/
  if(Keypad.KeyPressed())
    KeypadEventPressHandler(Keypad.getKeyCode());
}
