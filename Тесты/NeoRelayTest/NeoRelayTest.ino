/*Хех, работаем именно с этой библиотекой*/
#include <Adafruit_NeoPixel.h>

/*Задействуем определённый пин*/
#define  BLOCK_RELAY_PIN 5
/*Количество релейных точек в блоке*/
#define  RELAY_QUANTITY 2

/*Все реле включены - безусловное выключение*/
#define  ALL_OFF ((uint32_t) 0x000000)
/*Все реле выключены - безусловное включение*/
#define  ALL_ON ((uint32_t) 0x0F0F0F)
/*Включено только первое реле*/
#define  OFF_OFF_OFF_ON ((uint32_t) 0x010101)
/*Включено только второе реле*/
#define  OFF_OFF_ON_OFF ((uint32_t) 0x020202)
/*Включены оба реле - условное включение*/
#define  OFF_OFF_ON_ON ((uint32_t) 0x030303)
/*Остальное будет испытано когда на руках будет модуль на 4 реле
#define  OFF_ON_OFF_OFF    ((uint32_t) 0x040404)
#define  OFF_ON_OFF_ON     ((uint32_t) 0x050505)
#define  OFF_ON_ON_OFF     ((uint32_t) 0x060606)
#define  OFF_ON_ON_ON      ((uint32_t) 0x070707)
#define  ON_OFF_OFF_FF    ((uint32_t) 0x080808)
#define  ON_OFF_ON_OFF     ((uint32_t) 0x0A0A0A)
#define  ON_OFF_ON_ON      ((uint32_t) 0x0B0B0B)
#define  ON_ON_OFF_OFF     ((uint32_t) 0x0C0C0C)
#define  ON_ON_OFF_ON      ((uint32_t) 0x0D0D0D)
#define  ON_ON_ON_OFF      ((uint32_t) 0x0E0E0E)*/

/*Создаём объект класса Adafruit_NeoPixel, в этот раз вместо пиксельной ленты блок-модуль на 2 реле*/
Adafruit_NeoPixel Relay(RELAY_QUANTITY, BLOCK_RELAY_PIN, NEO_GRB + NEO_KHZ800);


void setup(){
  /**/
  delay(3000);
  /*Инициализация блока*/
  Relay.begin();
  /*Установка цвета, в данном случае по таблице включение первого реле в блоке*/
  Relay.setPixelColor(0,OFF_OFF_OFF_ON);
  /*Ну и соответственно включение*/
  Relay.show();
  /**/
  delay(3000);
  /*Отключение первого реле, включение второго*/
  Relay.setPixelColor(0,OFF_OFF_ON_OFF);
  /**/
  Relay.show();
  /**/
  delay(3000);
  /*Выключаем всё нафиг*/
  Relay.setPixelColor(0,ALL_OFF);
  /**/
  Relay.show();
}

void loop(){
  /*По братски, напиши управление здесь*/
}
