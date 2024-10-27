/**/
#include "defines.h"
#include "variables.h"
/*Подключаем клавиатурны модуль на пять кнопок KB45037*/
#include "KB45037.h"
/*Хех, работаем именно с этой библиотекой*/
#include <Adafruit_NeoPixel.h>



/*Создаём объект для работы с клавиатурным модулем*/
KB45037 Keypad(KEYPAD_PIN);

/*Создаём объект класса Adafruit_NeoPixel, в этот раз вместо пиксельной ленты блок-модуль на 2 реле*/
Adafruit_NeoPixel BlockRelay(RELAY_QUANTITY, BLOCK_RELAY_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  /*Для отладки*/
  Serial.begin(9600);
  /**/
  delay(3000);
  /*Инициализация блока*/
  BlockRelay.begin();
  /*Задаём команду - выключение всех модулей группы*/
  BlockRelay.setPixelColor(0,RELAYS_OFF);
  /*Передать сигнал управлния на релейные модули - выключаем*/
  BlockRelay.show();
}

void loop(){
  /*Проверяем работу кнопок, если было событие нажатия*/
  if(Keypad.KeyPressed()){
    /*Получаем код нажатой кнопки*/
    int key=Keypad.getKeyCode();
    /*Проверяем код и выводим сообщение*/
    switch(key){
      case KEY_LEFT:
        /*Левой кнопкой включаем/выключаем 2-й релейный модуль в группе*/
        if(Relay2Latch){
          Command=Command&(~RELAY2);
          Relay2Latch=false;
        }else{
          Command=Command|RELAY2;
          Relay2Latch=true;
        }
        /*Задаём команду - включение/выключение первого модуля группы*/
        BlockRelay.setPixelColor(0,Command);
        /*Передать сигнал управлния на релейный модуль*/
        BlockRelay.show();
        break;
      case KEY_DOWN:
        Serial.println("Нажатие кнопки \"Вниз\"");
        break;
      case KEY_UP:
        Serial.println("Нажатие кнопки \"Вверх\"");
        break;
      case KEY_RIGHT:
        /*Правой кнопкой включаем/выключаем 1-й релейный модуль в группе*/
        if(Relay1Latch){
          Command=Command&(~RELAY1);
          Relay1Latch=false;
        }else{
          Command=Command|RELAY1;
          Relay1Latch=true;
        }
        /*Задаём команду - включение/выключение первого модуля группы*/
        BlockRelay.setPixelColor(0,Command);
        /*Передать сигнал управлния на релейный модуль*/
        BlockRelay.show();
        break;
      case KEY_SELECT:
        Serial.println("Нажатие кнопки \"Выбор\"");
        break;
    }
  }
}
