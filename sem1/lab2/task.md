Необходимо разработать программу, которая вычисляет размер основных типов данных языка Си и выводит в следующем формате:

int: byte, MAX_INT, MIN_INT
short int: byte, MAX_INT, MIN_INT
unsigned short int: byte, MAX_INT, MIN_INT
char: byte, MAX_CHAR, MIN_CHAR
unsigned char: byte, MAX_UCHAR, MIN_UCHAR
unsigned int: byte, MAX_UINT, MIN_UINT
unsigned long long int: byte, MAX_LONG_INT, MIN_LONG_INT
float: byte
double: byte

Разработанное программное обеспечение должно вычислять данные менее, чем за 1 секунду.
Ограничение: нельзя пользоваться функциями, которые позволяют определить размер типа данных (к примеру, sizeof(), константы, содержащиеся в библиотеке limits.h и пр.). Для выполнения условия по времени разрешено использовать встроенные функции замера времени.
