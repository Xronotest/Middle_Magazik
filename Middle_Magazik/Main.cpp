#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>


//------------------------------------- Учётки --------------------------------------------
size_t userSize = 2;
std::string userStatus[3]{ "Maestro Mainer", "Maestro", "Operator" };
std::string* loginArr = new std::string[userSize]{ "maestro", "oper" };
std::string* passArr = new std::string[userSize]{ "maestro", "oper" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currrentStatus;

//-----------------------------------------------------------------------------------------

//------------------------------------- Склад ---------------------------------------------
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;

bool isStorageCreated = false;

void CreateStorage();

//-----------------------------------------------------------------------------------------

//------------------------------------- Служебные -----------------------------------------
void Start();
bool Login();
inline void Getline(std::string& str);
inline void Err(int time = 1500);
//-----------------------------------------------------------------------------------------


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();


	delete[]loginArr, passArr, statusArr;
	if (isStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}
	return 0;
}

void CreateStorage()
{
	const int staticSize = 10;

	unsigned int id[]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Броне-камера - Evil Eye", "Скрытая камера - Black Eye",
		"Мина - Kapkan", "Генератор помех", "Броне-баррикада",
		"Разведовательный дрон", "Нейтрализующий дрон - Шок-Бот",
		"Пулестойкий управляемый заряд - ЗУМ"
		"Дрон-перехватчик - Kludge", "Пробивной заряд - Thermite",
	};
	unsigned int count[staticSize]{ 14,28,40,30,32,500,70,20,40,20 };
	double price[staticSize]{ 936000, 87400, 147800, 680800, 120200, 46800, 200900, 700000, 1100000, 420000 };

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];

	isStorageCreated = true;
}
void Start() 
{
	std::cout << "\n\n\n\t\t\tМаэстро\n\n\n";

	if (Login())
	{
		if (currrentStatus == userStatus[0])
		{
			// открытие + создание склада
		}
		else if (currrentStatus == userStatus[1])
		{
			// открытие + создание склада
		}
		else if (currrentStatus == userStatus[2])
		{
			// открытие + создание склада
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершение работы...\n\n";
	}
}
bool Login() 
{
	std::string login, pass;

	while (true)
	{
		std::cout << "Введите логин: ";
		Getline(login);
		std::cout << "Введите пароль: ";
		Getline(pass);

		if (login == "exit" && pass == "exit")
		{
			currrentStatus = "";
			return false;
		}

		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобро пожаловать!\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				return true;
			}
		}

		
	}
}
inline void Getline(std::string& str) 
{
	std::getline(std::cin, str, '\n');
}
inline void Err(int time)
{
	std::cout << "Некоректнный ввод!\n\n";
	Sleep(time);
	system("cls");
}