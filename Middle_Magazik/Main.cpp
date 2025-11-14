#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>


//------------------------------------- Учётки --------------------------------------------
size_t userSize = 2;
std::string userStatus[3]{ "Maestro Mainer", "Maestro", "Operator" };
std::string* loginArr = new std::string[userSize]{ "xrono", "operator" };
std::string* passArr = new std::string[userSize]{ "siege", "six" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currrentStatus;

//-----------------------------------------------------------------------------------------

//------------------------------------- Склад ---------------------------------------------
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
std::string* codeNameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;

bool isStorageCreated = false;

void CreateStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();

template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize);
//-----------------------------------------------------------------------------------------

//------------------------------------- Служебные -----------------------------------------
void Start();
bool Login();
void ShowSuperAdminMenu();
bool IsNumber(const std::string& str);
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
		delete[]idArr, nameArr, codeNameArr, countArr, priceArr;
	}
	return 0;
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(40) << "Название товара\t\t" <<
			std::left << std::setw(10) << "Кодовое имя\t" << "Кол-во\t" << "Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(40) << nameArr[i]
				<< "\t" << std::left << std::setw(10) << codeNameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(40) << "Название товара\t\t" <<
			std::left << std::setw(10) << "Кодовое имя\t" << "Кол-во\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(40) << nameArr[i]
				<< "\t" << std::left << std::setw(10) << codeNameArr[i] << "\t" << countArr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(40) << "Название товара\t\t" <<
			std::left << std::setw(10) << "Кодовое имя\t" << "Цена\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(40) << nameArr[i]
				<< "\t" << std::left << std::setw(10) << codeNameArr[i] << "\t" << priceArr[i] << "\n";
		}
	}
	
}

void CreateStorage()
{
	const int staticSize = 10;

	unsigned int id[]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Броне-камера", "Скрытая камера",
		"Мина", "Генератор помех", "Броне-баррикада",
		"Разведовательный дрон", "Нейтрализующий дрон",
		"Пулестойкий управляемый заряд",
		"Хак-Дрон-перехватчик", "Пробивной заряд",
	};
	std::string codeName[staticSize]
	{
		"Evil Eye", 
		"Black Eye",
		"Kapkan", 
		"MUTE", 
		"Castle",
		"Bot", 
		"Shock-Bot",
		"ЗУМ", 
		"Kludge", 
		"Thermite",
	};

	unsigned int count[staticSize]{ 14,28,40,30,32,500,70,20,40,20 };
	double price[staticSize]{ 936000, 87400, 147800, 680800, 120200, 46800, 200900, 700000, 990000, 420000 };

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	codeNameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];

	isStorageCreated = true;

	FillArray(idArr, id, storageSize);
	FillArray(nameArr, name, storageSize);
	FillArray(codeNameArr, codeName, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(priceArr, price, storageSize);

}

void AddStorageItem() 
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \" exit \" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во товара для пололнения товара: ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > 700)
			{
				std::cout << "Некорректный ID или кол-во\nМаксимальное кол-во 700\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(40) << nameArr[id] << "\t" <<
					countArr[id] << " ---> " << countArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "1")
				{
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}
void RemoveStorageItem() 
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;

	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "\nВведите ID товара или \" exit \" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите кол-во списанного товара: ";
		Getline(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "Некорректный ID или кол-во\nМаксимальное кол-во " << countArr[id] << "\n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(40) << nameArr[id] << "\t" <<
					countArr[id] << " ---> " << countArr[id] - count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Товар успешно списан\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена списывания товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}
void ChangePrice() 
{
	std::string chooseId, choosePrice, choose;
	unsigned int id = 0;
	double newPrice = 0.0;

	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "\nВведите ID товара или \" exit \" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции!\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новую цену товара: ";
		Getline(choosePrice);

		if (IsNumber(chooseId) && IsNumber(choosePrice))
		{
			id = std::stoi(chooseId) - 1;
			newPrice = std::stod(choosePrice);

			if (id < 0 || id > storageSize - 1 || newPrice < 0.0 || newPrice > 2000000.0)
			{
				std::cout << "Некорректный ID или цена\nМаксимальное цена - 2.000.000\n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(40) << nameArr[id] << "\t" <<
					priceArr[id] << " ---> " << newPrice << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					priceArr[id] = newPrice;
					std::cout << "Цена успешно изменена\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена изменения цены\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void Start() 
{
	std::string choose;

	if (Login())
	{
		if (currrentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберете склад:\n1 - Готовый склад\n2 - Создать новый\nВвод: ";
				Getline(choose);
				system("cls");

				if (choose == "1")
				{
					CreateStorage();
					ShowSuperAdminMenu();
				}
				else if (choose == "2")
				{
					// создать новый склад
				}
				else
				{
					Err();
				}
			}
		}
		else if (currrentStatus == userStatus[1])
		{
			CreateStorage();
			// открытие + создание склада
		}
		else if (currrentStatus == userStatus[2])
		{
			CreateStorage();
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
		std::cout << "\n\n\n\t\t\tМаэстро\n\n\n";
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
				system("cls");
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобро пожаловать!\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				currrentStatus = statusArr[i];
				return true;
			}
		}
	}
}

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Редактировать склад\n";
		std::cout << "7 - Редактировать персонал\n";
		std::cout << "8 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			
		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			AddStorageItem();
		}
		else if (choose == "4")
		{
			RemoveStorageItem();
		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			Err();
		}
	}
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длины числа. Максимум 9-ти значные числа!\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введённые данные не являются числом!\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
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

template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize) 
{
	for (size_t i = 0; i < arraySize; i++)
	{
		dynamicArray[i] = staticArray[i];
	}
}