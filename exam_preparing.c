#include <stdio.h>
#include <malloc.h>
int binary_system(int b){
    int a, i, mass[99];
    for (i = 0; i < 99; i++)
    {
        mass[i] = 0;
    }
    printf("Введите число: ");
    scanf("%d", &a);
    i = 0;
    //printf("this is number %d\n", a);
    while (a != 0)
    {
        if (a % 2 == 0)
        {
            mass[i] = 0;
            a = a / 2;
        }
        else
        {
            mass[i] = 1;
            a = a / 2;
        }
        i++;
    }
    //i = i - 1;

    printf("i = %d\n", i);
    for (; i >= 0; i--)
        printf("%d", mass[i]);
    return 0;
}

void item_2_2 () {
    int a, b;
    char c, d, e, f, g, h, i, j;
    //binary_system(a); // перевод числа в двоичную сс
    a = 3;
    b = 12;
    printf("%.2f\n", (float)b); //2.1 правило приведения типов, нужно в каждой сиутации

    b++; // 2.2 арифметические операции (инкреметирование)
    b--; // 2.2 арифметические операции (декрементирование)
    a = a + b;  // 2.2 арифметические операции (сложение)
    printf("сложение %d\n", a);
    a = b - a; // 2.2 арифметические операции (вычитание)
    printf("вычитание %d\n", a);
    a = b / a; // 2.2 арифметические операции (деление)
    printf("деление %d\n", a);
    a = b % a; // 2.2 арифметические операции (остаток от деления)
    printf("остаток от деления %d\n", a);
    a = -b; // 2.2 арифметические операции (изменение знака)
    printf("изменение знака %d\n", a);

    c = 2;
    d = ~c; // 2.2 побитовое отрицание
    e = c ^ d; //   2.2 побитовое исключающее или
    f = 4;
    g = 12;
    f = f & g; //  2.2 побитовое и (произведение)
    h = 2;
    i = 8;
    i = h | i; // 2.2 побитовое или (сложение)
    j = 125;
    j = j >> 4; // 2.2 побитовый сдвиг вправо на 4 позиции
    printf("побитовое отрицание %d\n", d);
    printf("побитовое исключающее или %d\n", e);
    printf("побитовое и %d\n", f);
    printf("побитовое или %d\n", i);
    printf("побитовый сдвиг вправо %d\n", j);
}

void item_3_1() {
    int a, b, c;
    printf("введите три числа\n");
    scanf("%d %d %d", &a, &b, &c);
    if ((a <= b) && ((b <= c) || (a <= c)))
        printf("a = %d - наименьшее число\n", a);
    else if ((a >= b) && (b <= c))
        printf("b = %d - наименьшее число\n", b);
    else if(((a <= b) ||(b >= c)) && (a >= c))
        printf("c = %d - наименьшее число\n", c);

    if((a != b) && (b != c) && (c != a))
        printf("все числа разные\n");

    char array[] = {0, 1, 2, 3, 4, 5}; // 3.1 логические выражения и операции for, while
    for(int i = 0; i<6; i++) {
        printf("%d ", array[i]);
    }
    int i = 0;
    printf("\n");
    while (i < 6) {
        printf("%d ", array[i]);
        i++;
    }
}

void item_3_2() {
    int array[] = {0, 1 , -1, 3, -4, 6, 8, 10, -10};
    for (int i = 0; i<9; i++) {
        if(array[i]<0)
            break;
        printf("%d ", array[i]);
    }
    printf("\n");
    for(int i = 0; i<9; i++) {
        if(array[i] < 0) {
            continue;
        }
        printf("%d ", array[i]);
    }
    printf("\n");
    for(int i = 0; i<9; i++) {
        if(array[i] > 0)
            if(array[i] % 2 == 0) {
                printf("%d", array[i]);
                goto exit;
            }
    }
    exit: printf(" - первое положительное четное число\n");
}

void item_4_1() {
    int a, b, c;
    printf("введите три числа\n");
    scanf("%d %d %d", &a, &b, &c);
    if ((a <= b) && ((b <= c) || (a <= c)))
        printf("a = %d - наименьшее число\n", a);
    else if ((a >= b) && (b <= c))
        printf("b = %d - наименьшее число\n", b);
    else if(((a <= b) ||(b >= c)) && (a >= c))
        printf("c = %d - наименьшее число\n", c);

    if((a != b) && (b != c) && (c != a))
        printf("все числа разные\n");

    printf("\n");

    int i = 0, consonant = 0, vowel = 0;
    char array[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    while (array[i] != '\0') {
        switch (array[i]) {
            case 'h': case 'l':
                consonant++;
                break; // без break пойдет дальше по всем  case
            case 'e': case 'o':
                vowel++;
                break;
        }
        i++;
    }
    printf("согласных букв %d\n", consonant);
    printf("гласных букв %d", vowel);
}

void item_5_1() {
    int array[6] = {0, 1, 2, 3, 4, 5};  //  Здесь цикл for задан с ошибкой. В некоторых старых версиях компиляторов
    // этот код зацикливался. Дело в том, что переменная i располагалась при компиляции сразу за массивом A. При
    // выходе за границы массива счётчик переводился в 1. Массивы небезопасны, так как неправильная работа с индексом
    // может приводить к доступу к произвольному участку памяти (Теоретически. Современные компиляторы сами заботятся
    // о том, чтобы вы не копались в чужой памяти).
    int i;
    for (i = 0; i <= 6 ; i++) { // 5.1 операции и ошибки при работе с массивами, переполнение массива
        array[i] = 1;
        printf("%d ", array[i]); //
    }

    //В си массив не хранит своего размера и не проверяет индекс массива на корректность. Это значит, что
    // можно выйти за пределы массива и обратиться к памяти, находящейся дальше последнего элемента массива (или ближе).
    void *p = NULL; //указатели типа void или пустые указатели. Эти указатели используются в том случае,
    // когда тип переменной не известен. Так как void не имеет типа, то к нему не применима
    // операция разадресации (взятие содержимого) и адресная арифметика, так как неизвестно
    // представление данных. Тем не менее, если мы работаем с указателем типа void, то нам доступны операции сравнения.
    int intVar     = 10;
    char charVar   = 'A';
    float floatVar = 24.3;
    float *floatPtr = NULL;

    p = &intVar;
    *((int*) p) = 20; // присваиваем значение 20, приводим тип указаетля int
    printf("\nintVar = %d\n", intVar);

    p = &charVar;
    printf("charVar = %c\n", *((char*) p)); // приводим тип указателя char

    p = &floatVar;
    floatPtr = (float*) p; // приводим тип указателя float
    printf("floatVar = %.3f", *floatPtr);
}

void item_5_2(){
    int A = 5; // 5.2 указатели и арифметика указателей
    int *p;
    p = &A; //Получаем адрес переменной A
    printf("%p\n", p); // Выводим адрес переменной A
    printf("%d\n", *p); // Выводим содержимое переменной A
    *p = 10; // Меняем содержимое переменной A
    printf("%d\n", A);
    printf("%d\n", p);

    int B[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *a, *b;

    a = &B[0];
    b = &B[9];

    printf("&B[0] == %p\n", a);
    printf("&B[9] == %p\n", b);

    if (a < b) { // a > b, если адрес, который хранит a, больше адреса, который хранит b.
        printf("a < b");
    } else {
        printf("b < a");
    }

    int C[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p2;

    p2 = C; // получили адрес первого элемента в массиве С
    printf("\nfirst %d\n", *p2);
    p2++;
    printf("second %d\n", *p2);
    p2 = p2 + 4;
    printf("third %d\n", *p2);
}



void item_6_1() {
    int sum_6_1(int c, int d){
        c = c + d;
        printf("%d\n", c);
    }

    char point_6(char *estr) {
        int len = 0;
        while(*estr != '\0') {
            estr++;
            len++;
        }
        printf("%d", len);
    }

    int a = 5, b = 3; // 6.1 подпрограммы, область видимости, передача параметров по значению/через указатели
    sum_6_1(a, b); //  main
    char string[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char *str;
    str = string;
    point_6(str);
}

void item_6_2() {
    int factorail(int n) {
        if ((n == 1) || (n == 0)) return 1;
        return n * factorail(n-1);
    }

    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        return fib (n-1)+ fib(n-2);
    }

    int n = 5, a = 1; // 6.2 рекурсия (вычисление факториала числа) - main
    a = factorail(n);
    printf("%d\n", a);

    int k = 3, b = 1; // 6.2 рекурсия (числа фиббоначи - выводит kтое число в последовательности)
    b = fib(k);
    printf("%d", b);
}

void item_7_1() { //  общая карта памяти, локальные переменные, глобальные переменные
    int l = 1;
    void func_local() {
        int k = 1; // локальная переменная
        printf("k = %d\n", k);
        k = k + 1;
    }

    void func_global() {
        printf("l = %d\n", l);
        l = l + 1;
    }
    for(int i = 0; i < 3; i++) { // область видмости i - цикл - main
        func_local();
    }

    for(int i = 0; i < 3; i++)
        func_global();
}

void item_7_2() { // динамическая память (malloc/free)
    int *block; // указатель для блока памяти
    int n;      // количество элементов массива
    printf("Size of array = ");
    scanf("%d", &n);
    block = malloc(n * sizeof(int)); // выделяем память для массива,
    // функция malloc возвращает указатель типа void*, который автоматически преобразуется в тип int*
    for(int i = 0; i < n; i++) { // зполняем массив
        printf("block[%d] = ", i);
        scanf("%d", &block[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++) { // вывод введенных чисел на консоль
        printf("%d ", block[i]);
    }
    free(block); // освобождаем память
}

void item_8_2() {
    int a = 3, c;
    float b = 5.03;
    char array[255];
    char str[255];

    printf("вывод целого числа %d\n", a);
    printf("вывод числа с плавающей точкой %.3f\n", b);
    printf("введите строку\n");

    fgets(array, 255, stdin);
    fputs(array, stdout);

    printf("вывод процента %% и слэша \\ \n");
    printf("введите число ");
    scanf("%d", &c);
    printf("ваше число %d\n", c);

    sprintf(str, "%s %d %c\n", "слово", 2, 'x');
    fputs(str, stdout);

    char str2[255];
    int i;
    sscanf("hello 123", "%s%d", str2, &i);
    printf("%s %d", str2, i);
}
int main() {
//    item_2_2();
//    item_3_1();
   item_3_2();
//    item_4_1();
//    item_5_1();
//    item_5_2();
//    item_6_1();
//    item_6_2();
//    item_7_1();
//    item_7_2();
//    item_8_2();
//
//    FILE *file1; // 8.1 пример работы программы с текстовым файлом
//    int k = 0;
//    char string[256];
//
//    printf("открытие файла 1: ");
//    file1 = fopen("/home/polina/CLionProjects/exam_preparing/text.txt", "r+"); // прописываю полный адрес файла,
//
//    if (file1 == NULL) // проверка
//        printf("не выполнено!\n");
//    else
//        printf("выполнено!\n");
//
//    printf("открытие файла 2: ");
//    FILE *file2 = fopen("/home/polina/CLionProjects/exam_preparing/read.txt", "w");
//    if (file2 == NULL) // проверка
//        printf("не выполнено!\n");
//    else
//        printf("выполнено!\n");
//
//    fputc('o', file2);
//    if (ferror(file2)) // если произошла ошибка
//        puts("Ошибка записи файла file2.txt");
//
//    printf("открытие файла 3: ");
//    FILE *file3 = fopen("/home/polina/CLionProjects/exam_preparing/file3.txt", "r");
//    if (file3 == NULL) // проверка
//        printf("не выполнено!\n");
//    else
//        printf("выполнено!\n");
//
//    fgets(string, 255, stdin); //  8_2 рассказать про stdout, stderr
//    fputs(string, file1);
//
//    while (!feof(file3)) {
//        fgetc(file3);
//        k++;
//    }
//    printf("%d\n", k);
//    fclose (file1);
//    fclose(file2);
//    fclose(file3);
//    printf ("файлы закрыты");
    return 0;
}
