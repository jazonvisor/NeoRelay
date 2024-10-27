/*Обработчик нажатий кнопок клавиатурного модуля*/
void KeypadEventPressHandler(uint8_t key){
  /*Проверяем код нажатой кнопки*/
  switch(key){
    /*Нажатием кнопки "Влево" включаем 2-й релейный модуль*/
    case KEY_LEFT:
      Relay2.DirectControl(ON);
      break;
    /*Нажатием кнопки "Вниз" включаем 1-й релейный модуль*/
    case KEY_DOWN:
      Relay1.DirectControl(ON);
      break;
    /*Нажатием кнопки "Вверх" выключаем 2-й релейный модуль*/
    case KEY_UP:
      Relay2.DirectControl(OFF);
      break;
    /*Нажатие кнопки "Вправо" выключаем 1-й релейный модуль*/
    case KEY_RIGHT:
      Relay1.DirectControl(OFF);
      break;
    /*Нажатием кнопки "Выбор" включаем/выключаем все реле разом*/
    case KEY_SELECT:
      /*Управление через статический метод AllRelays*/
      if(latch){
        NeoRelayBlock::AllRelays(BlockRelay,OFF);
        latch=false;
      }else{
        NeoRelayBlock::AllRelays(BlockRelay,ON);
        latch=true;
      }
      break;
  }
}
