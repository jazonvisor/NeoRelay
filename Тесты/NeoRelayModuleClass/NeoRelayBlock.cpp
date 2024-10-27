#include "NeoRelayBlock.h"

/*Команда для всех релейных модулей в блоке одна*/
static uint32_t NeoRelayBlock::command=0x000000;

/*Безусловные команды на включение/выключение*/
static uint32_t NeoRelayBlock::allon=0x0f0f0f;
static uint32_t NeoRelayBlock::alloff=0x000000;

/*Конструктор класса*/
NeoRelayBlock::NeoRelayBlock(){
  /*При конструировании объекта, только в этот раз, режим прямого управления*/
  MODE=DIRECT;
}

/*Связывание с объектом NeoPixel*/
void NeoRelayBlock::ConnectWith(Adafruit_NeoPixel bindableObject){
  this->bindableObject=bindableObject;
}

/*Установка адреса*/
void NeoRelayBlock::SetAddress(uint32_t address){
  this->address=address;
}

/*Установка времени включения/выключения*/
void NeoRelayBlock::SetOnOffTime(uint32_t timeon,uint32_t timeoff){
  this->timeon=timeon;
  this->timeoff=timeoff;
}

/*Управление объектом, установка флага доступности управления*/
void NeoRelayBlock::SetActivity(bool enable){
  /*Первым делом проверям временные уставки, если числа равны то сбросить флаг доступности управления*/
  /*простыми словами - при равных уставках времени включения/выключения невозможно корректно управлять*/
  /*объектом. Но если уставки различаются, флаг доступности управления должен быть установлен.*/
  (timeon==timeoff)?
    isActive=false:
      enable?isActive=true:isActive=false;
}

/*Управление объектом, режим "Прямое включение/выключение"*/
void NeoRelayBlock::DirectControl(bool operation){
  if(operation){
    /*Формирование команды управления - включение релейного модуля*/
    command=command|address;
    /*Посылка команды в блок*/
    bindableObject.setPixelColor(0,command);
    /*Применение полученной команды*/
    bindableObject.show();
  }else{
    /*Формирование команды управления - выключение релейного модуля*/
    command=command&(~address);
    /*Посылка команды в блок*/
    bindableObject.setPixelColor(0,command);
    /*Применение полученной команды*/
    bindableObject.show();
  }
}

/*Управление объектом, режим "Суточный таймер", получаем форматированное текущее время в виде шестизначного числа*/
void NeoRelayBlock::DailyControl(uint32_t currtime){
  /*Если управление объектом доступно*/
  if(isActive){
    /*Полученную из аргумента строку преобразуем в целое число*/
    //this->currtime=currtime;
    /**/
    if(timeon<timeoff){
      /**/
      if(currtime>=timeon && currtime<timeoff){}
        //marker=true;
      else{}
        //marker=false;
    }else{
      if(timeon>timeoff){
        if(currtime>=timeoff && currtime<timeon){}
          //marker=false;
        else{}
          //marker=true;
      }
    }/*Иначе, не управлять объектом никак.*/
  }else{/*marker=false;*/};
  /*Записываем состояние маркера назначенному пину*/
  //digitalWrite(pinUsed,marker);
}

/*Управление блоком, включение/выключение всех реле разом*/
static void NeoRelayBlock::AllRelays(Adafruit_NeoPixel bindableObject,bool operation){
  /*Формирование команды*/
  //operation?command=command&(~alloff):command=command|allon;
  /*Посылка команды в блок*/
  if(operation)bindableObject.setPixelColor(0,allon);else bindableObject.setPixelColor(0,alloff);
  /*Применение полученной команды*/
  bindableObject.show();
}
