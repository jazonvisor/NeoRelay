#include <Adafruit_NeoPixel.h>

#ifndef NEORELAYBLOCK_h
#define NEORELAYBLOCK_h

#define ON 1
#define OFF 0

#include <Arduino.h>

class NeoRelayBlock{
  /*Адрес релейного модуля на шине NeoPixel*/
  uint32_t address;
  /*Время включения*/
  uint32_t timeon;
  /*Время выключения*/
  uint32_t timeoff;
  /*Текущее время приведённое в формат шестизначного целого числа*/
  uint32_t currtime;
  /*Текущий статус доступности управления*/
  bool isActive=false;
  /*Режимы работы*/
  enum:uint8_t{DIRECT,DAILY}MODE;
  /*Маркер защёлка*/
  bool latch;
  /*Для наглядности, команда инициализирована в HEX-формате*/
  static uint32_t command;
  /*Безусловные команды на включение/выключение всех реле разом*/
  static uint32_t allon;
  static uint32_t alloff;
  /**/
  Adafruit_NeoPixel bindableObject;
public:
  /*Конструктор класса*/
  NeoRelayBlock();
  /*Связывание с объектом NeoPixel*/
  void ConnectWith(Adafruit_NeoPixel);
  /*Установка адреса*/
  void SetAddress(uint32_t);
  /*Установка времени включения/выключения*/
  void SetOnOffTime(uint32_t,uint32_t);
  /*Управление объектом, установка флага доступности управления*/
  void SetActivity(bool);
  /*Управление объектом, режим "Прямое включение/выключение"*/
  void DirectControl(bool);
  /*Управление объектом, режим "Суточный таймер", получаем форматированное текущее время в виде шестизначного числа*/
  void DailyControl(uint32_t);
  /*Управление блоком, включение всех реле*/
  static void AllRelays(Adafruit_NeoPixel,bool);
};

#endif
