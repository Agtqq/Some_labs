

#include <string.h>
#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h>


int main()
{
    setlocale(LC_ALL, "Russian");
    char* st; char* str, * poisk;
    fflush(stdin);
    printf("������� ������: ");
    int i = 0, j = 1; st = 's';
    str = (char*)malloc(sizeof(char)); //�������� ������ ��� ������
    while (st != '\n')
    {
        st = getchar(); //������ 1 ������
        str = (char*)realloc(str, j * sizeof(char)); //�������� ������ �� +1 ������
        str[i] = st; //���������� ��������� ������ � ������
        i++;
        j++;
    }
    str[i] = '\0'; //��������� ������ ���������� ������

    fflush(stdin);
    printf("������� ���������: ");
    i = 0; j = 1; st = 's';
    poisk = (char*)malloc(sizeof(char)); //�������� ������ ��� ������
    while (st != '\n')
    {
        st = getchar(); //������ 1 ������
        poisk = (char*)realloc(poisk, j * sizeof(char)); //�������� ������ �� +1 ������
        poisk[i] = st; //���������� ��������� ������ � ������
        i++;
        j++;

    }
    poisk[i] = '\0'; //��������� ������ ���������� ������
    rabin_karp(str, poisk);
    return 0;
}


int rabin_karp(char *str, char *poisk)
{
    int n = strlen(str)-1;   //��������� ����� ������ � ���������
    int m = strlen(poisk)-1;
    int p = 0, t = 0, h = 1, d = 26, q = 97, ne = 0;

    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        p = (d * p + poisk[i]) % q;  //������� ��� ������ m ��������� ������ � ���������
        t = (d * t + str[i]) % q;

    }
        for (int i = 0; i <= n - m; i++)
        {

            if (p == t)  //���� ��� �����, ����������� �����������
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (str[i + j] != poisk[j]) //���� �����-�� 2 ������� �� �����, �����������
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)    //���� ��� ��������� �������� ��� ���������� - ������� ������, ��� ������� ���������
                {
                    printf("��������� ������� �� �������: %d\n", i + 1);
                    ne = 1;  //������� ����, ��� ���� �� 1 ��� ��������� �������
                }
            }
            /*����� ���-�������� ��������� ���������, ������ ������ ������ �� ���������� 
            ��������� � ������� ��������� ������ � ����� ���������� ������*/
            if (i < n - m)
            {
                t = (d * (t - str[i] * h) + str[i + m]) % q;
                if (t < 0)
                {
                    t = (t + q);
                }
            }
        } 

        if (ne==0)  printf("��������� �� �������");
}