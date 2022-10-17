

#include <string.h>
#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h>


int main()
{
    setlocale(LC_ALL, "Russian");
    char* st; char* str, * poisk;
    fflush(stdin);
    printf("Введите строку: ");
    int i = 0, j = 1; st = 's';
    str = (char*)malloc(sizeof(char)); //выделяем память под строку
    while (st != '\n')
    {
        st = getchar(); //вводим 1 символ
        str = (char*)realloc(str, j * sizeof(char)); //выделяем память на +1 символ
        str[i] = st; //записываем введенный символ в строку
        i++;
        j++;
    }
    str[i] = '\0'; //добавляем символ завершения строки

    fflush(stdin);
    printf("Введите подстроку: ");
    i = 0; j = 1; st = 's';
    poisk = (char*)malloc(sizeof(char)); //выделяем память под строку
    while (st != '\n')
    {
        st = getchar(); //вводим 1 символ
        poisk = (char*)realloc(poisk, j * sizeof(char)); //выделяем память на +1 символ
        poisk[i] = st; //записываем введенный символ в строку
        i++;
        j++;

    }
    poisk[i] = '\0'; //добавляем символ завершения строки
    rabin_karp(str, poisk);
    return 0;
}


int rabin_karp(char *str, char *poisk)
{
    int n = strlen(str)-1;   //вычисляем длину строки и подстроки
    int m = strlen(poisk)-1;
    int p = 0, t = 0, h = 1, d = 26, q = 97, ne = 0;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        p = (d * p + poisk[i]) % q;  //находим хеш первых m симоволов строки и подстроки
        t = (d * t + str[i]) % q;

    }
        for (int i = 0; i <= n - m; i++)
        {

            if (p == t)  //если хеш равен, стравниваем посимвольно
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (str[i + j] != poisk[j]) //если какие-то 2 символа не равны, прерываемся
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)    //если при сравнении символов они одинаковые - выводим индекс, где найдена подстрока
                {
                    printf("Подстрока найдена на индексе: %d\n", i + 1);
                    ne = 1;  //триггер того, что хотя бы 1 раз подстрока найдена
                }
            }
            /*найти хеш-значение следующей подстроки, удалив первый символ из предыдущей 
            подстроки и добавив следующий символ в конец предыдущей строки*/
            if (i < n - m)
            {
                t = (d * (t - str[i] * h) + str[i + m]) % q;
                if (t < 0)
                {
                    t = (t + q);
                }
            }
        } 

        if (ne==0)  printf("Подстрока не найдена");
}