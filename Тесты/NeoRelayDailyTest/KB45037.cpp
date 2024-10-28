#include "KB45037.h"

/*Здесь и далее - методы класса KB45037*/
/*Конструктор объекта класса*/
KB45037::KB45037(int _pin){Pin=_pin;}

/*Метод подавления дребезга контактов при нажатии кнопок*/
int KB45037::DebounceKey(int Code,int _lastValue){
    int _nextValue=getKeyCode();
    if(_nextValue!=_lastValue){
        delay(15);
        _nextValue=getKeyCode();
    }
    return _nextValue;
}

/*Обработчик событий нажатия - возвращаем состояние маркера KeyIsPressed*/
bool KB45037::KeyPressed(){
    currentButtonState=DebounceKey(getKeyCode(),previousButtonState);
    if(currentButtonState!=KEY_NONE){
        if(currentButtonState!=previousButtonState)
            KeyIsPressed=true;
        else
            KeyIsPressed=false;
    }
    previousButtonState=currentButtonState;
    return KeyIsPressed;
}

/* Получение кода нажатой кнопки */
int KB45037::getKeyCode(){
    int buttonValue=analogRead(Pin);
    if(buttonValue > 1000)
        return KEY_NONE;
    else if(buttonValue<100)
        return KEY_LEFT;
    else if(buttonValue<147 && buttonValue>137)
        return KEY_UP;
    else if(buttonValue<332 && buttonValue>322)
        return KEY_DOWN;
    else if(buttonValue<510 && buttonValue>500)
        return KEY_RIGHT;
    else if(buttonValue<746 && buttonValue>736)
        return KEY_SELECT;
}
