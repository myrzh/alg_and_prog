#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Максимальное количество цифр в длинном числе
#define MAX_DIGITS 500

typedef struct {
    int digits[MAX_DIGITS];
    int length;
    int sign; // 1 для положительного, -1 для отрицательного
} BigInt;

// Объявление функции вычитания, чтобы не ругался компилятор
void subtract(const BigInt* a, const BigInt* b, BigInt* result);

// Конструктор
void initialize(BigInt* num) {
    memset(num->digits, 0, sizeof(num->digits));
    num->length = 0;
    num->sign = 1;
}

// Создание большого числа из обычного числа
void fromInt(BigInt* num, long long int n) {
    initialize(num);
    if (n < 0) {
        num->sign = -1;
        n = -n;
    }
    while (n > 0) {
        num->digits[num->length++] = n % 10;
        n /= 10;
    }
}

// Создание большого числа из строки
void fromString(BigInt* num, const char* str) {
    initialize(num);
    int len = strlen(str);
    int start = 0;
    if (str[0] == '-') {
        num->sign = -1;
        start = 1;
    }
    for (int i = len - 1; i >= start; i--) {
        num->digits[num->length++] = str[i] - '0';
    }
}

// Вывод большого числа
void print(const BigInt* num) {
    if (num->sign == -1) {
        printf("-");
    }
    for (int i = num->length - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

// Функция сравнения большого числа
int compare(const BigInt* a, const BigInt* b) {
    if (a->length > b->length) {
        return 1;
    }
    else if (a->length < b->length) {
        return -1;
    }
    else {
        for (int i = a->length - 1; i >= 0; i--) {
            if (a->digits[i] > b->digits[i]) {
                return 1;
            }
            else if (a->digits[i] < b->digits[i]) {
                return -1;
            }
        }
        return 0;
    }
}

// Функция сложения
void add(const BigInt* a, const BigInt* b, BigInt* result) {
    initialize(result);
    // Сравниваем знаки чисел
    if (a->sign == b->sign) {
        result->sign = a->sign;
        int carry = 0;
        int max_length = a->length > b->length ? a->length : b->length;
        for (int i = 0; i < max_length; i++) {
            int sum = a->digits[i] + b->digits[i] + carry;
            result->digits[result->length++] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            result->digits[result->length++] = carry;
        }
    }
    // Иначе выявляем более из них
    else {
        BigInt temp;
        // а больше или равно
        if (compare(a, b) >= 0) {
            subtract(a, b, &temp);
            result->sign = a->sign;
        }
        // b больше
        else {
            subtract(b, a, &temp);
            result->sign = b->sign;
        }
        memcpy(result, &temp, sizeof(BigInt));
    }
}

// Функция вычитания
void subtract(const BigInt* a, const BigInt* b, BigInt* result) {
    initialize(result);
    // Тут идут такие же проверки со знаком для более корректных вычислений
    if (a->sign == b->sign) {
        if (compare(a, b) >= 0) {
            result->sign = a->sign;
            int borrow = 0;
            int max_length = a->length > b->length ? a->length : b->length;
            for (int i = 0; i < max_length; i++) {
                int diff = a->digits[i] - b->digits[i] - borrow;
                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                }
                else {
                    borrow = 0;
                }
                result->digits[result->length++] = diff;
            }
            while (result->length > 1 && result->digits[result->length - 1] == 0) {
                result->length--;
            }
        }
        else {
            subtract(b, a, result);
            result->sign = -a->sign;
        }
    }
    else {
        BigInt temp;
        if (a->sign == 1) {
            add(a, b, &temp);
            result->sign = 1;
        }
        else {
            add(a, b, &temp);
            result->sign = -1;
        }
        memcpy(result, &temp, sizeof(BigInt));
    }
}

// Функция умножения
void multiply(const BigInt* a, const BigInt* b, BigInt* result) {
    initialize(result);
    result->sign = a->sign * b->sign;
    int max_length = a->length + b->length;
    for (int i = 0; i < a->length; i++) {
        int carry = 0;
        for (int j = 0; j < b->length || carry != 0; j++) {
            int product = result->digits[i + j] + a->digits[i] * (j < b->length ? b->digits[j] : 0) + carry;
            result->digits[i + j] = product % 10;
            carry = product / 10;
        }
    }
    // Обновление длины результата
    result->length = max_length;
    // Удаление ведущих нулей
    while (result->length > 1 && result->digits[result->length - 1] == 0) {
        result->length--;
    }
}

// Инкрементирование числа
void increment(BigInt* num) {
    int carry = 1;
    for (int i = 0; i < num->length; i++) {
        num->digits[i] += carry;
        carry = num->digits[i] / 10;
        num->digits[i] %= 10;
        if (carry == 0) {
            break;
        }
    }
    if (carry > 0) {
        num->digits[num->length++] = carry;
    }
}

// Деление на целое число
void divideByInt(const BigInt* num, int divisor, BigInt* result) {
    initialize(result);
    int remainder = 0;
    for (int i = num->length - 1; i >= 0; i--) {
        int dividend = remainder * 10 + num->digits[i];
        int quotient = dividend / divisor;
        remainder = dividend % divisor;
        result->digits[i] = quotient;
        result->length++;
    }
    // Удаление ведущих нулей
    while (result->length > 1 && result->digits[result->length - 1] == 0) {
        result->length--;
    }
}

// Возведение в степень
void power(const BigInt* base, const BigInt* exponent, BigInt* result) {
    if (exponent->length == 1 && exponent->digits[0] == 0) {
        // Если степень равна 0, результат равен 1
        fromInt(result, 1);
        return;
    }
    if (exponent->length == 1 && exponent->digits[0] == 1) {
        // Если степень равна 1, результат равен базе
        memcpy(result, base, sizeof(BigInt));
        return;
    }
    BigInt halfExponent;
    divideByInt(exponent, 2, &halfExponent); // Функция divideByInt делит BigInt на int
    BigInt temp;
    power(base, &halfExponent, &temp); // Рекурсивный вызов для половины степени
    multiply(&temp, &temp, result); // Умножение результата на себя
    if (exponent->digits[0] % 2 == 1) {
        multiply(result, base, &temp); // Если степень нечетная, умножаем на базу
        memcpy(result, &temp, sizeof(BigInt));
    }
}

// Функция вычисления факториала
void factorial(const BigInt* num, BigInt* result) {
    // Инициализация результата
    fromInt(result, 1);

    // Умножение чисел от 1 до num
    BigInt i;
    fromInt(&i, 1);
    BigInt temp;
    initialize(&temp);
    while (compare(&i, num) <= 0) {
        multiply(result, &i, &temp);
        memcpy(result, &temp, sizeof(BigInt));
        increment(&i);
    }
}

// Функция вычисления значений в промежутке
void sumRange(const BigInt* start, const BigInt* end, BigInt* result) {
    // Инициализация результата
    initialize(result);

    // Сложение чисел от start до end
    BigInt current;
    memcpy(&current, start, sizeof(BigInt));
    BigInt temp;
    initialize(&temp);
    while (compare(&current, end) <= 0) {
        add(result, &current, &temp);
        memcpy(result, &temp, sizeof(BigInt));
        increment(&current);
    }
}

// Функция, которая задаёт преоритетность выполнения вычислений по операторам
int getPriority(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    }
    else if (operator == '*' || operator == '/') {
        return 2;
    }
    else if (operator == '^') {
        return 3;
    }
    else if (operator == '!') {
        return 4;
    }
    else {
        return 0;
    }
}

// Функция вычисления в зависимости от оператора
void performOperation(char operator, BigInt* operand1, BigInt* operand2, BigInt* result) {
    initialize(result);
    switch (operator) {
    case '+':
        add(operand1, operand2, result);
        break;
    case '-':
        subtract(operand1, operand2, result);
        break;
    case '*':
        multiply(operand1, operand2, result);
        break;
    case '^':
        power(operand1, operand2, result);
        break;
    case '!':
        factorial(operand1, result);
        break;
    default:
        printf("Unsupported operator: %c\n", operator);
        break;
    }
}

// Функция для вычисления выражения
void evaluateExpression(const char* expression) {
    BigInt operandStack[10];
    char operatorStack[MAX_DIGITS];
    int operandTop = -1;
    int operatorTop = -1;

    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        char currentChar = expression[i];
        if (currentChar == ' ') {
            continue;
        }
        else if (currentChar >= '0' && currentChar <= '9') {
            // Если текущий символ является цифрой, прочитаем операнд
            BigInt operand;
            int j = i;
            while (j < length && expression[j] >= '0' && expression[j] <= '9') {
                j++;
            }

            char operandString[MAX_DIGITS];
            strncpy(operandString, expression + i, j - i);
            operandString[j - i] = '\0';
            fromString(&operand, operandString);

            // Добавляем операнд в стек операндов
            operandStack[++operandTop] = operand;

            // Обновляем индекс i
            i = j - 1;
        }
        else if (currentChar == '!') {
            // Если текущий символ '!', читаем операнд перед '!'
            BigInt operand = operandStack[operandTop];
            BigInt result;
            factorial(&operand, &result);
            operandStack[operandTop] = result;
        }
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '^') {
            // Если текущий символ является оператором, выполняем операции с более высоким приоритетом
            while (operatorTop >= 0 && getPriority(operatorStack[operatorTop]) >= getPriority(currentChar)) {
                BigInt operand2 = operandStack[operandTop--];
                BigInt operand1 = operandStack[operandTop--];
                BigInt result;
                performOperation(operatorStack[operatorTop--], &operand1, &operand2, &result);
                operandStack[++operandTop] = result;
            }

            // Добавляем текущий оператор в стек операторов
            operatorStack[++operatorTop] = currentChar;
        }
    }

    // Выполняем оставшиеся операции
    while (operatorTop >= 0) {
        BigInt operand2 = operandStack[operandTop--];
        BigInt operand1 = operandStack[operandTop--];
        BigInt result;
        performOperation(operatorStack[operatorTop--], &operand1, &operand2, &result);
        operandStack[++operandTop] = result;
    }

    // Выводим результат
    print(&operandStack[operandTop]);
}

int main() {
    char input[2 * MAX_DIGITS];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    char* space = strchr(input, ' ');
    if (space != NULL) {
        BigInt num1, num2, result;
        fromString(&num1, strtok(input, " "));
        fromString(&num2, strtok(NULL, " "));
        sumRange(&num1, &num2, &result);
        print(&result);
    }
    else {
        input[strcspn(input, "\n")] = '\0';
        evaluateExpression(input);
    }
    return 0;
}
