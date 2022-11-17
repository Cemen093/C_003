#include <iostream>
using namespace std;

//Курс «Язык программирования C++»
//Тема : Рекурсия.
//Домашнее задание
//Задание 1 :
//Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.
int greatestCommonDivisor(int a, int b)
{
    if (b == 0)
        return a;
    if (a > b)
        return greatestCommonDivisor(b, a % b);
    else
        return greatestCommonDivisor(a, b % a);
}
//Задание 2 :
//Написать рекурсивную функцию нахождения степени числа.
int pow(int num, int p)
{
    printf("num=%d; p=%d;\n", num, p);
    if (p == 1)
        return num;
    if (!p)
        return 1;
    return num * pow(num, p-1);
}
//Задание 3 :
//Написать рекурсивную функцию, выводящую N звезд в ряд, число N задает пользователь.Проиллюстрируйте работу функции примером.
void ptintNStar(int n)
{
    cout << '*';
    if (n == 1)
    {
        cout << endl;
        return;
    }
    ptintNStar(--n);
}
//Задание 4 :
//Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.Пользователь вводит a и b.Проиллюстрируйте работу функции примером.
int sumRange(int a, int b)
{
    if (a == b)
    {
        return b;
    } else if (a < b)
    {
        return a + sumRange(a+1, b);
    }
    else
    {
        return b + sumRange(b+1, a);
    }
}
//Задание 5 :
//Напишите рекурсивную функцию, принимающую одномерный массив из 100 целых чисел, заполненных случайным образом, и находит позицию, с которой начинается последовательность из 10 чисел, сумма которых минимальна.
int sumTen(int arr[100], int start)
{
    int sum = 0;
    for (size_t i = start; i < start + 10; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int find(int arr[100], int start)
{
    if (start == 88)
    {
        return start;
    }

    int indexMin = find(arr, start + 1);
    if (sumTen(arr, start) < sumTen(arr, indexMin))
    {
        return start;
    }
    else
    {
        return indexMin;
    }
}


//Домашнее задание №6
//Тема : Указатели.
//Домашнее задание
//Задание 1 :
//Используя два указателя на массив целых чисел, скопируйте один массив в другой.Используйте в программе арифметику указателей для продвижения массивом, а также оператора разименования.
void task01()
{
    cout << "task 01" << endl;
    const int n = 30;
    int* arr1 = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        *(arr1+i) = rand() % 10;
    }

    int* arr2 = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        *(arr2 + i) = *(arr1 + i);
    }

    cout << "arr1[" << *arr1;
    for (size_t i = 1; i < n; i++)
    {
        cout << ", " << *(arr1 + i);
    }
    cout << "]" << endl;

    cout << "arr2[" << *arr2;
    for (size_t i = 1; i < n; i++)
    {
        cout << ", " << *(arr2 + i);
    }
    cout << "]" << endl;
}
//Задание 2 :
//Используя указатель на массив целых чисел, изменить порядок прохождения элементов массива на противоположный.
void task02()
{
    cout << "task 02" << endl;
    const int n = 30;
    int* arr1 = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        *(arr1 + i) = rand() % 10;
    }

    cout << "arr1[";
    for (size_t i = 0; i < n; i++)
    {
        cout << *(arr1 + i) << ((i != n - 1) ? ", " : "");
    }
    cout << "]" << endl;

    cout << "arr1[";
    for (size_t i = 0; i < n; i++)
    {
        cout << *(arr1 + n - 1 - i) << ((i != n - 1) ? ", " : "");
    }
    cout << "]" << endl;
}
//Задание 3 :
//Используя два указателя на массивы целых чисел, скопируйте один массив в другой так, чтобы во втором массиве элементы находились в обратном порядке.
//Использовать в программе арифметику указателей для продвижения массивом, а также оператор разименования.
void task03()
{
    cout << "task 03" << endl;
    const int n = 30;
    int* arr1 = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        *(arr1 + i) = rand() % 10;
    }

    int* arr2 = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        *(arr2 + n - 1 - i) = *(arr1 + i);
    }

    cout << "arr1[";
    for (size_t i = 0; i < n; i++)
    {
        cout << *(arr1 + i) << ((i != n - 1) ? ", " : "");
    }
    cout << "]" << endl;

    cout << "arr2[";
    for (size_t i = 0; i < n; i++)
    {
        cout << *(arr2 + i) << ((i != n - 1) ? ", " : "");
    }
    cout << "]" << endl;
}

//Задание 4 :
//Используя указатели и оператор разименования, определить большее из двух чисел.
void task04()
{
    cout << "task 04" << endl;
    int* a = new int(5);
    int* b = new int(7);
    cout << (*a > *b ? "a" : (*b > *a ? "b" : "a=b")) << endl;

}

//Задание 5 :
//Используя указатели и оператора разименования, определить знак числа, введенного с клавиатуры.
void task05()
{
    cout << "task 05" << endl;
    int* a = new int;
    cout << "input a >> ";
    cin >> *a;
    cout << (*a < 0 ? "-" : "+") << endl;
}

//Задание 6 :
//Используя указатели и оператора разименования, обменять местами значения двух переменных.
void task06()
{
    cout << "task 06" << endl;
    int* a = new int(3);
    int* b = new int(5);

    cout << "a=" << *a << "; b=" << *b << ";" << endl;
    int* c = new int;
    *c = *a;
    *a = *b;
    *b = *c;
    cout << "a=" << *a << "; b=" << *b << ";" << endl;
}

//Задание 7 :
//Написать примитивный калькулятор, используя только указатели.
void task07()
{
    cout << "task 07" << endl;
    float* a = new float;
    float* b = new float;
    float* c = new float;
    char* oper = new char;
    cout << "input a >> ";
    cin >> *a;
    cout << "input b >> ";
    cin >> *b;
    cout << "input operator >> ";
    cin >> *oper;

    if (*oper == '+')
    {
        *c = *a + *b;
    }
    else if (*oper == '-')
    {
        *c = *a - *b;
    }
    else if (*oper == '*')
    {
        *c = *a * *b;
    }
    else if (*oper == '/')
    {
        *c = *a / *b;
    }
    cout << "result = " << *c << endl;
}
//Задание 8 :
//Используя указатель массив целых чисел, сосчитать сумму элементов массива.Использовать в программе арифметику указателей для продвижения массивом, а также оператор разименования.
void task08()
{
    cout << "task 08" << endl;
    const int n = 30;
    int* arr1 = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        *(arr1 + i) = rand() % 10;
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << (i == 0 ? "arr[" : "") << *(arr1 + i) << ((i != n - 1) ? ", " : "]\n");
    }

    int* sum = new int(0);
    for (size_t i = 0; i < n; i++)
    {
        *sum += *(arr1 + i);
    }
    cout << "sum = " << *sum << endl;
}

int main()
{
    //cout << greatestCommonDivisor(4, 14) << endl;
    //cout << pow(2, 4) << endl;
    //ptintNStar(7);
    //cout << sumRange(9, 7);
    //
    //int arr[100];
    //for (size_t i = 0; i < 100; i++)
    //{
    //    arr[i] = rand() % 10;
    //}
    //for (size_t i = 0; i < 100; i++)
    //{
    //    cout << arr[i] + ' ';
    //}
    //cout << endl;
    //cout << find(arr, 0) << endl;

    task01();
    task02();
    task03();
    task04();
    task05();
    task06();
    task07();
    task08();
}