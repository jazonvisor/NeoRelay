# NeoRelay, интеллектуальный адресный релейный модуль для Arduino и Raspberry Pi проектов
## Описание
### Режимы работы
На плате размещены четыре реле с микроконтроллерной системой управления. Каждое реле может выдерживать до 10 А при 250 В переменного тока и позволяет управлять мощными нагрузками при подаче сигнала на управляющий вход. Модуль собран на микроконтроллере STM32F030F4P6, что позволило сделать четырехканальный релейный модуль универсальным с различными режимами работы.
***
### Прошивка «Заводская»
Все реле могут работать в двух режимах: кнопка или триггер. Дополнительно можно установить активный уровень срабатывания (1) или (0).
С помощью микропереключателя К1 выбираем режим: кнопка или триггер. Верхнее положение – кнопка. Нижнее положение – триггер.
С помощью микропереключателя К2 выбираем активный уровень срабатывания. Верхнее положение – реле срабатывают при активном высоком уровне сигнала управления (1). Нижнее положение – реле срабатывают при активном низком уровне сигнала управления (0).
Резисторы R1 -  R8 защищают от случайного срабатывания реле при включении питания. Резисторы R5 - R8 притягивает вход к Vin (напряжение питания). Они устанавливаются для режима срабатывания по низкому активному уровню (0), а резисторы R1 – R4 притягивают вход к GND и устанавливаются для режима срабатывания по высокому уровню (1).
На производстве устанавливаются только резисторы R1- R4 для высокого активного уровня срабатывания (1). При смене уровня срабатывания с (1) на (0) переставьте эти резистор на места R5 – R8.
Сигналы управления подаются на контакты 2, 3, 4, 5 разъема J1.
***
### Прошивка «Задержка»
Вы всегда можете сменить прошивку. В этой прошивке все реле работают в режиме кнопка с задержками включения/выключения или без задержек.
С помощью двух микропереключателей  установленных на плате задаются режимы работы описанные в Таблице:
Положение переключателей	Режим работы
K1 выкл, К2 выкл	Нет задержек
К1 вкл, К2 выкл	Задержка срабатывания 2 сек
К2 вкл, К1 выкл	Задержка отключения 0.3 сек
К1 вкл, К2 вкл	Задержки срабатывания 2 сек и отключения 0.3 сек
***
### Последовательный интерфейс "Neopixel"
При использовании модуля с контроллерами Arduino или Raspberry Pi может быть интересно и удобно управлять модулем с помощью цвета по аналогии со светодиодами WS2812b (Neopixel) подключив к входу Din микроконтроллер Arduino, Raspberry Pi. Модуль полностью совместим с протоколом управления адресными светодиодами и библиотекой Adafruit_NeoPixel.
В программе релейный модуль соответствует светодиоду WS2812b, а включение / выключение любого реле соответствует цвету отправляемому на светодиод. В следующей таблице указаны все “цвета” (команды) на которые реагирует модуль и то, как он реагирует:
 
Команда(Цвет)|Реле 1|Реле2|Реле3|Реле4
:------------|:-----|:----|:----|:----
0x000000|-|-|-|-	 	 	 	 
0x010101|ON|-|-|-	 	 	 
0x020202|-|ON|-|-	 	 
0x030303|ON|ON|-|-	 	 
0x040404|-|-|ON|-	 
0x050505|ON|-|ON|-	 
0x060606|-|ON|ON|-	 
0x070707|ON|ON|ON|-	 
0x080808|-|-|-|ON
0x090909|ON|-|-|ON
0x0A0A0A|-|ON|-|ON
0x0B0B0B|ON|ON|-|ON
0x0C0C0C|-|-|ON|ON
0x0D0D0D|ON|-|ON|ON
0x0E0E0E|-|ON|ON|ON
0x0F0F0F|ON|ON|ON|ON
ON – реле включено.
 
К выходу Dout можно подключить аналогичные релейные модули или светодиоды WS2812b. Светодиод HL1 сигнализирует о наличии посылки по каналу – neopixel.
В этом режиме последовательно можно включить до 140 подобных модулей или светодиодов WS2812b в любой комбинации.
Последовательный интерфейс всегда включен, и если выбрана прошивка «Задержка», то срабатывания реле по последовательному интерфейсу полностью соответствуют таблице режимов этой прошивки.
Если нет необходимости управлять модулями таким образом, просто оставьте эти выводы не подключенными, они не будут мешать основному режиму работы. И наоборот если вы не используете основной режим оставьте входные контакты XP2 не подключенными.
Оба режима могут работать совместно, дополняя друг друга, например, подав положительный сигнал на один из входов S, вы включите реле, а через последовательный интерфейс Neopixel командой 0x000000 выключите.
***
### Аварийный режим
При нажатии на кнопку аварийной остановки SW1 все реле переходят в нормальное состояние и не реагируют на сигналы управления до отключения и последующего включения питания.
***
### Технические характеристики
~~~
Номинальное напряжение питания: 5 В
Номинальное напряжение управляющего сигнала: 3–5 В
Последовательный интерфейс: Neopixel
Количество последовательно подключаемых модулей или WS2812b: 140
Максимальный ток коммутации одного канала: 10 А
Коммутируемое переменное напряжение одного канала: 250 В
Максимальный потребляемый ток: 220 мА
Рабочая температура: −30…+80 °C
Размеры платы: 96 х 75 мм
~~~
***
### Полезные картинки по теме можно найти здесь:
1. [Общий вид](Полезные картинки/1.jpg)
2. [Вид снизу](Полезные картинки/2.jpg)
3. [Назначение пинов](Полезные картинки/Appointment pins.jpg)
4. [Схема](Полезные картинки/Schematic.png)
5. [Подключение по USB-UART для смены прошивки контроллера](Полезные картинки/USB-UART-Conn.png)
