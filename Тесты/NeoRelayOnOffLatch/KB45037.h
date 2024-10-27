#ifndef KB45037_h
#define KB45037_h

#include "Arduino.h"

/*Переопределение косвенных кодов кнопок аналоговой клавиатуры*/
#define KEY_LEFT    0
#define KEY_UP      1
#define KEY_RIGHT   2
#define KEY_DOWN    3
#define KEY_SELECT  4
#define KEY_NONE    5 //Когда ни одна кнопка не нажата

/*Описание объекта класса*/
class KB45037{
    /*Пин подключения*/
    int Pin;
    /*Контроль состояния кнопок, подавляем дребезг*/
    int currentButtonState, previousButtonState;
    /*Маркер нажатия*/
    bool KeyIsPressed=false;
    /*Метод подавления дребезга контактов*/
    int DebounceKey(int,int);
public:
    /*Конструктор объекта класса*/
    KB45037(int);
    /*Обработчик событий нажатия*/
    bool KeyPressed();
    /*Возвращаем код нажатой кнопки*/
    int getKeyCode();
};

#endif