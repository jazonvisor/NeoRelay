/*Пин для подключения клавиатурного модуля KB45037*/
#define KEYPAD_PIN A0

/*Для подключения блока NeoRelay задействуем определённый пин*/
#define  BLOCK_RELAY_PIN 5
/*Количество релейных точек в блоке*/
#define  RELAY_QUANTITY 2

/*Все реле включены - безусловное выключение*/
#define RELAYS_OFF ((uint32_t) 0x000000)
/*Все реле выключены - безусловное включение*/
#define RELAYS_ON ((uint32_t) 0x0F0F0F)
/*Включено только первое реле*/
#define  RELAY1_ADDRESS ((uint32_t) 0x010101)
/*Включено только второе реле*/
#define  RELAY2_ADDRESS ((uint32_t) 0x020202)
/*Включены оба реле - условное включение*/
//#define  OFF_OFF_ON_ON ((uint32_t) 0x030303)
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
