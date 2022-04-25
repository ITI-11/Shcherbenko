#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

struct process
{
	int Size;
	char Name[100];
	int Priority;
	int Address;
	bool first;
	bool third;
	bool present;
};

struct memory
{
	int size;
	int fullmemory;
	int first;
	int third;
};

void AddNewProcess(struct memory storage, struct process Block[100]);
void OutputData(struct memory storage, struct process Block[100]);
void calculation(struct memory storage, struct process Block[100]);
void ShowTable(struct memory storage, struct process Block[100]);
void DeleteProcess(struct memory storage, struct process Block[100]);

int FreeSpace, QuantityProcess = 0;



int main()
{
	setlocale (LC_ALL, "RUS");
	struct memory storage;
	struct process block[100];
	printf("Введите размер памяти:\n");
	int test = scanf("%d", &storage.size);
	storage.first=storage.size;
	storage.third=storage.size;
	if (test==0) 
	{ 
		printf("Некорректный ввод!\n"); 
		return 0; 
	}
	int FreeSpace = storage.size;
	int value = 0;
	while (1)
	{
		calculation(storage, block);
		printf("-----------------------------------\n");
		printf(" 1) Добавить новый процесс.\n");
		printf(" 2) Удалить процесс по адресу.\n");
		printf(" 3) Показать таблицу процессов.\n");
		printf("-----------------------------------\n");
		test = scanf("%d", &value);
		if (test==0) 
		{ 
			printf("Некорректный ввод!\n"); 
			return 0; 
		}
		switch (value)
		{
		case 1:
			AddNewProcess(storage, block);
			break;
		case 2:
			DeleteProcess(storage, block);
			break;
		case 3:
			ShowTable(storage, block);
			break;
		}
	}
}

void AddNewProcess(struct memory storage, struct process Block[100])
{
	setlocale (LC_ALL, "RUS");
	printf("Введите имя процесса %d:\n", QuantityProcess+1);
	scanf("%s", Block[QuantityProcess].Name);
	printf("Введите количество пямяти, которая занимает процесс:\n");
	int test = scanf("%d", &Block[QuantityProcess].Size);
	if (test==0) 
	{ 
		printf("Некорректный ввод!\n"); 
		return; 
	}
	printf("Введите приоритет процесса:\n");
	test = scanf("%d", &Block[QuantityProcess].Priority);
	if (test==0) 
	{ 
		printf("Некорректный ввод!\n"); 
		return; 
	}
	Block[QuantityProcess].Address = QuantityProcess;
	Block[QuantityProcess].present = true;
	Block[QuantityProcess].first = true;
	Block[QuantityProcess].third = false;
	QuantityProcess++;
}



void ShowTable(struct memory storage, struct process Block[100])
{
	int Counter = 0;
	printf("---------------------------------------------------------------------------\n");
	printf("|   Имя    |     Память    | 	 first    |   third   |  Адрес  |  Приоритет  |\n");
	for (Counter = 0; Counter < QuantityProcess; Counter++)
	{
		if (Block[Counter].present == true)
		{
			printf("|%10.10s|%13.1d  |%13.1d |%9.1d  |%9.1d|%13.1d|\n", Block[Counter].Name, Block[Counter].Size, Block[Counter].first, Block[Counter].third, Block[Counter].Address, Block[Counter].Priority);
		}
	}
	printf("\n");
	printf("---------------------------------------------------------------------------\n");
}


void calculation(struct memory storage, struct process Block[100])
{
	setlocale (LC_ALL, "RUS");
	int i = 0, j = 0;
	while (i < QuantityProcess)
	{
		if (storage.third==storage.first)
		{
		Block[i].first = true;
		Block[i].third = false;
		storage.first=storage.first-Block[i].Size;
		}
		else
		{
			if(storage.third>storage.first){
				Block[i].first = false;
				Block[i].third = true;
				storage.third=storage.third-Block[i].Size;
			}
			else{
				Block[i].first = true;
				Block[i].third = false;
				storage.first=storage.first-Block[i].Size;
			}
		}
		i++;
	}
//		if(storage.first<0 || storage.third<0){
//			storage.first=storage.first+500;
//			storage.third=storage.third+500;
//			storage.size=storage.size+500;
//		}
		printf("Размер памяти: %d \n", storage.size);
}

void DeleteProcess(struct memory storage, struct process Block[100])
{
	setlocale (LC_ALL, "RUS");
	bool flag = false;
	printf("Введите адресс процесса:\n");
	int value = 0;
	int test = scanf("%d", &value);
	if (test==0) 
	{ 
		printf("Некорректный ввод!\n"); 
		return; 
	}
	if (value >= 0 && value <= 100)
	{
		if(value != 0 )
		{
			for (int Counter = value; value < QuantityProcess; Counter++)
			{
				if(Block[Counter +1].present == true)
				{
					Block[Counter].Address = Block[Counter + 1].Address;
					strcpy(Block[Counter].Name, Block[Counter + 1].Name);
					Block[Counter].Priority = Block[Counter + 1].Priority;
					Block[Counter].Size = Block[Counter + 1].Size;
					Block[Counter].first = Block[Counter + 1].first;
					Block[Counter].third = Block[Counter + 1].third;
					flag = true;
				}
				else
				{
					QuantityProcess--;
				}
			}
			if(flag == true)
				{	
					QuantityProcess--;
				}
		}
		else
		{
			QuantityProcess--;
		}
	}
}


