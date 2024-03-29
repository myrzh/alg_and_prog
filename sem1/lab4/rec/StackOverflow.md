Студенты, которые выполняют лаборатоную работу №4 путем полного перебора, могут столкнуться с получением ошибки stack overflow. Это говорит о том, что глубина рекурсии достигла максимума и служебная структура данных (стек) переполнилась. Полный перебор для этой работы вполне корректен. Получая такую ошибку, вы можете изменить поведение программы таким образом, чтобы увеличить размер стека. Ребята, которые используют ОС Windows могут положиться на настройки программы-линковщика, который участвует в процессе компиляции. Для увеличения размера стека необходимо в программный код добавить специальное макроопределение. Значение указывается в байтах.

```
#pragma comment(linker, "/STACK:209715200")
```
В данном случае в процессе сборки вашего проекта будет передан специальный ключ для компоновщика, который при создании исполняемого файла учтет указанный размер стека.
Те ребята, кто использует Linux, могут также воспользоваться директивами компиляторов, однако компиляторов обычно на этой ОС большое множество и ключи могут отличаться, поэтому предлагается программный метод решения такой проблемы.

```
#include <sys/resource.h> // необходимо для определения служебных структур ОС
const rlim_t kStackSize = 1000L * 1024L * 1024L;   // определяем размер стека в байтах
struct rlimit rl; // содержит так называемые мягкие ограничения на ресурсы и жесткие
int result; // переменная состояния
result = getrlimit(RLIMIT_STACK, &rl); // позволяет получить (наполнить структуру) текущие настройки
if (result == 0) // проверка на корректность результата работы функции getrlimit
{
   if (rl.rlim_cur < kStackSize) // проверяем текущий размер стека с желаемым
   {
       rl.rlim_cur = kStackSize; // перепопределяем размер стека через поле структуры
       result = setrlimit(RLIMIT_STACK, &rl); // вызов функции для корректировки настройки программы
       if (result != 0) // проверка на корректность результата работы функции setrlimit
       {
           fprintf(stderr, "setrlimit returned result = %d\n", result); // вывод кода ошибки через поток ошибок с помощью функции fprintf
       }
    }
}
```