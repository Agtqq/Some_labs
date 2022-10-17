#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>




struct queue
{
	int number;
	queue* next;
	queue* prev;
};

void vvod(queue** head, queue** tail, int number, int variant)
{

	queue* elem = (queue*)calloc(1, sizeof(queue));
	elem->number = number;
	if (!*head)
		*head = *tail = elem;
	else
		if (variant)
		{
			(*tail)->next = elem;
			elem->prev = *tail;
			*tail = elem;
		}
		else
		{
			(*head)->prev = elem;
			elem->next = *head;
			*head = elem;
		}
}

void vyvod(queue* head, queue* tail, int variant)
{
	queue* point = head, * point2 = tail;
	if (variant)
		while (point)
		{
			printf("%d ", point->number);
			point = point->next;
		}
	else
		while (point2)
		{
			printf("%d ", point2->number);
			point2 = point2->prev;
		}
}

void vfile(queue* head, queue* tail, int variant, FILE* f)
{
	queue* point = head, * point2 = tail;
	if (variant)
		while (point)
		{
			fprintf(f, "%d ", point->number);
			point = point->next;
		}
	else
		while (point2)
		{
			fprintf(f, "%d ", point2->number);
			point2 = point2->prev;
		}
	fclose(f);
}

void del(queue** head, queue** tail, int var)
{
	if (!var)
	{
		queue* temp = (queue*)calloc(1, sizeof(queue));
		temp = (*head)->next;
		temp->prev = 0;
		free(*head);
		*head = temp;
	}
	else
	{
		queue* temp = (queue*)calloc(1, sizeof(queue));
		temp = (*tail)->prev;
		temp->next = 0;
		free(*tail);
		*tail = temp;
	}
}

void del1(queue** head, queue** tail, int num)
{
	queue* point = *head;
	while (point && point->next)
	{
		if (!point->next->next && point->number == num)
			del(&point, tail, 1);
		else
			if (!point->prev && point->number == num)
				del(&point, tail, 0);
		if (point->next && point->next->number == num)
		{
			queue* temp = point->next;
			point->next = point->next->next;
			temp->next->prev = point;
			free(temp);
		}
		else
			point = point->next;
	}
}

void delvse(queue** head, queue** tail)
{
	while (*head)
		del(head, tail, 0);
}

void sort(queue** head, queue** tail)
{
	//vvod(head, tail, 0, 1);
	queue* t = NULL, * t1 = NULL;
	int r;
	do {
		for (t1 = *head; t1->next != t; t1 = t1->next)
			if (t1->number < t1->next->number)
			{
				r = t1->number;
				t1->number = t1->next->number;
				t1->next->number = r;
			}
		t = t1;
	} while ((*head)->next != t);
	//del(head, tail, 1);
}

void sort2(queue** head, queue** tail)
{
	//vvod(head, tail, 0, 1);
	queue* t = NULL, * t1, * r;
	if ((*head)->next->next == NULL) return;
	do
	{
		for (t1 = *head; t1->next->next != t; t1 = t1->next)
			if (t1->next->number > t1->next->next->number) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*head)->next->next != t);
	//del1(head, tail, 1);
}

void zadanie(queue** head, queue** tail)
{

}

int main()
{
	 queue *head, *tail;
	 tail = head = NULL;
	int a = 1, n, amount, var;
	char in[] = "in.txt", out[] = "out.txt";
	system("CLS");
	setlocale(LC_ALL, "rus");
	
	printf("1.Ввод\n2.Вывод\n3.Удаление\n4.Сортировка\n");
	while (a)
	{
		printf("\nДействие:");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
		{
			printf("1 - С клавиатуры\n2 - Из файла\n");
			scanf_s("%d", &var);
			switch (var)
			{
			case 1:
			{
				int rep;
				printf("1 - Добавление в хвост\n0 - Добавление в голову\n");
				scanf_s("%d", &var);
					printf("Введите кол-во чисел: ");
					scanf_s("%d", &amount);
					printf("\nВведите числа: ");
					for (int i = 0; i < amount; i++)
					{
						scanf_s("%d", &n);
						vvod(&head, &tail, n, var);
					}
				
				break;
			}
			case 2:
			{
				FILE* input = fopen("in.txt", "r");
				printf("1 - добавление в хвост\n0 - добавление в голову\n");
				scanf_s("%d", &var);
				int rep;

					while (!feof(input))
					{
						fscanf(input, "%d", &n);
						vvod(&head, &tail, n, var);
					}
				
				break;
			}
			}
		}
		break;
		case 2:
		{
			printf("1 - В консоль\n2 - В файл\n");
			scanf_s("%d", &var);
			switch (var)
			{
			case 1:
			{
				printf("1 - Просмотр с головы\n0 - Просмотр с хвоста\n");
				scanf_s("%d", &var);
				if (head)
					vyvod(head, tail, var);
				else
					printf("Очередь пуста\n");
				break;
			}
			case 2:
			{
				FILE* output = fopen("out.txt", "w+");
				printf("1 - Просмотр с головы\n0 - Просмотр с хвоста\n");
				scanf_s("%d", &var);
				if (head)
					vfile(head, tail, var, output);
				else
					printf("Очередь пуста\n");
				break;
			}
			}
		}
		break;
		case 3:
		{
			printf("1 - Удаление 1\n0 - Удаление всех\n ");
			scanf_s("%d", &var);
			if (head)
				if (var)
				{   
					int var1;
					printf("1 - Удаление выбранного\n0 - Удаление с головы или хвоста\n");
					scanf_s("%d", &var1);
					if(var1)
					{
					  printf("Введите число для удаления: ");
					  scanf_s("%d", &var);
					  del1(&head, &tail, var);
					}
					else
					{
						printf("1 - Удаление с хвоста\n0 - Удаление с головы\n");
						scanf_s("%d", &var);
						del(&head, &tail, var);
					}
				}
				else
					delvse(&head, &tail);
			else
				printf("Очередь пуста\n");
		}
		break;
		case 4:
			printf("1 - Сортировка с перестановкой\n0 - Сортировка указателями\n");
			scanf_s("%d", &var);
			if (var)
			{
				sort(&head, &tail);
			}
			else sort2(&head, &tail);
			break;
		default:
			return 0;
		}
	}
}