#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>

//------------------------------------- Учётки --------------------------------------------
size_t userSize = 2;
size_t staffCount = 1;
std::string userStatus[3]{ "Maestro Mainer", "Maestro", "Operator" };
std::string* loginArr = new std::string[userSize]{ "xrono", "operator" };
std::string* passArr = new std::string[userSize]{ "siege", "six" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currrentStatus;


void ChangeUsers();
void ShowUsers(int mode = 0);
void AddNewUser();
void ChangePass();
void DeleteUser();

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
void BuildStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();


void ChangeStorage();
void AddNewItem();
void ChangeName();
void DeleteItem();

template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize);
//-----------------------------------------------------------------------------------------

//------------------------------------- Служебные -----------------------------------------
std::unordered_set<char> loginSymbols;
std::unordered_set<char> passSymbols;
bool isLoginSetCreated = false;
bool isPassSetCreated = false;

void Start();
bool Login();
void SetLoginSymbols();
void SetPassSymbols();
bool CheckLogin(const std::string &str);
bool CheckPass(const std::string& str);
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

void ChangeUsers() 
{
	if (isLoginSetCreated == false)
	{
		SetLoginSymbols();
	}
	if (isPassSetCreated == false)
	{
		SetPassSymbols();
	}
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить нового пользователя\n";
		std::cout << "2 - Показать пользователей\n";
		std::cout << "3 - Изменить пароль пользователя\n";
		std::cout << "4 - Удалить пользователя\n";
		std::cout << "0 - Выход из редактора\n";
		std::cout << "Ввод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			AddNewUser();
		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (userSize < 2)
			{
				std::cout << "Пользователь отсутсвует\n";
			}
			Err();
		}
	}
}
void ShowUsers(int mode) 
{
	if (mode == 0)
	{
		system("cls");

		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "   Пароль\t\t\t" << "Роль\n";

		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t"
				<< statusArr[i] << "\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");

		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "   Пароль\t\t\t" << "Роль\n";

		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t"
				<< statusArr[i] << "\n";
		}
		system("pause");
	}
	
}
void AddNewUser()
{
	std::string newLogin, newPass, newRole,choose;
	bool exit = true;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::cout << "Введите логин нового пользователяили или\" exit \"для выхода: ";
			Getline(newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Отмена операции!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы: a-z, A-Z, 0-9\n\n";
				Sleep(1500);
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Введите пароль нового пользователяили или\" exit \"для выхода: ";
			Getline(newPass);
			if (newPass == "exit")
			{
				std::cout << "Отмена операции!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (CheckPass(newPass))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы: a-z, A-Z, 0-9 + спец символы\n\n";
				Sleep(1500);
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Выбирите роль для нового сотрудника или\" exit \"для выхода: \n";
			std::cout << "1 - Админимстратор\n2 - Сотрудник\nВвод: ";
			Getline(choose);
			if (choose == "exit")
			{
				std::cout << "Отмена операции!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
				break;
			}
			else if(choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}
		}

		while (exit)
		{
			system("cls");
			std::cout << "Пользователь: " << newLogin << "\n";
			std::cout << "Пароль: " << newPass << "\n";
			std::cout << "Роль: " << newRole << "\n";
			std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				userSize++;
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];

				FillArray(loginArrTemp, loginArr, userSize - 1);
				FillArray(passArrTemp, passArr, userSize - 1);
				FillArray(statusArrTemp, statusArr, userSize - 1);

				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;

				std::swap(loginArr, loginArrTemp);
				std::swap(passArr, passArrTemp);
				std::swap(statusArr, statusArrTemp);

				delete[]loginArrTemp, passArrTemp, statusArrTemp;
				std::cout << "Идёт подготовка... ";
				Sleep(2000);
				std::cout << "Пользователь успешно добавлен!\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена операции!";
				Sleep(1500);
			}
			else
			{
				Err();
			}
		}
		if (exit == false)
		{
			break;
		}
	}
}
void ChangePass() 
{
	system("cls");
	std::string newPass1, newPass2, choose;
	int userId = 0, isAdmin = 0;

	while (true)
	{
		if (currrentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}
		std::cout << "\nВыберете номер пользователя для смены пароля или \"exit\" для выхода: ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена операции!";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);
			if (userId < isAdmin || userId > userSize - 1)
			{
				std::cout << "Такого пользователя нет\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			Err();
			continue;
		}

		while (true)
		{
			system("cls");
			if (currrentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
			{
				std::cout << "Нельзя менять пароль админу!\n";
				Sleep(1500);
				break;
			}

			std::cout << "Введите новый пароль для пользователя " << loginArr[userId] << ": ";
			Getline(newPass1);
			std::cout << "Подтвердите новый пароль для пользователя " << loginArr[userId] << ": ";
			Getline(newPass2);

			if (CheckPass(newPass1) && CheckPass(newPass2))
			{
				if (newPass1 == newPass2 && newPass1 != passArr[userId] && newPass2 != passArr[userId])
				{
					passArr[userId] = newPass1;
					std::cout << "Успешно\n";
					Sleep(1500);
					break;
				}
				else
				{
					std::cout << "Повторите попытку\n";
					Sleep(1200);
				}
			}
		}
	}
}
void DeleteUser()
{
	std::string chooseId, checkPass, choose;
	int userId, isAdmin = 1;

	while (true)
	{
		if (currrentStatus == userStatus[0] && userSize < 2)
		{
			std::cout << "Нет пользователей для удаления!\n";
			Sleep(1500);
			return;
		}
		else if (currrentStatus == userStatus[1] && staffCount < 1)
		{
			std::cout << "Нет пользователей для удаления!\n";
			Sleep(1500);
			return;
		}

		//continue
	}
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
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(40) << "Название товара\t\t" <<
			std::left << std::setw(10) << "Кодовое имя\n";

		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(40) << nameArr[i]
				<< "\t" << std::left << std::setw(10) << codeNameArr[i] << "\n";
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

	if (isStorageCreated)
	{
		delete[]idArr, nameArr, codeNameArr, countArr, priceArr;
	}

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
void BuildStorage()
{
	while (true)
	{
		std::string choose;
		AddNewItem();
		if (storageSize == 0)
		{
			system("cls");
			std::cout << "Вы уверены что хотите оставить склад пустым?\n1 - Да\n2 - Нет\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				break;
			}
			else if (choose == "2")
			{
				continue;
			}
			else
			{
				Err();
				Sleep(1500);
				continue;
			}
		}
		else
		{
			ShowStorage();
			break;
		}
	}
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

void ChangeStorage() 
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить новый товар\n";
		std::cout << "2 - Изменить название товара\n";
		std::cout << "3 - Удалить товар\n";
		std::cout << "0 - Выход из редактора\n";
		std::cout << "Ввод: ";
		Getline(choose);
		system("cls");
		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ChangeName();
		}
		else if (choose == "3" && storageSize > 0)
		{
			DeleteItem();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Склад пуст\n";
			}
			Err();
		}
	}
}
void AddNewItem()
{
	std::string newName, newCodeName, newPrice, newCount, choose;
	double price = 0.0;
	unsigned int count = 0;
	bool exit;
	while (true)
	{
		exit = true;
		while (true)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращения операции\n";
			std::cout << "\tВведите название нового товара: ";
			Getline(newName);
			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n";
				Sleep(1500);
				exit = false;
				break;
			}

			if (newName.size() <= 0 || newName.size() >= 60)
			{
				std::cout << "Ошибка имени. Максимальная длина 60 символов\n";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращения операции\n";
			std::cout << "\tВведите кодовое имя нового товара: ";
			Getline(newCodeName);
			if (newCodeName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (newName.size() <= 0 || newName.size() >= 20)
			{
				std::cout << "Ошибка кодового имени. Максимальная длина 20 символов\n";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращения операции\n";
			std::cout << "\tВведите кол-во нового товара: ";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 700 || count < 0)
				{
					std::cout << "Ошибка максимального кол-ва товара. Не более 700 ед.\n";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращения операции\n";
			std::cout << "\tВведите цену нового товара: ";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				price = std::stod(newPrice);
				if (price > 2000000 || price < 0)
				{
					std::cout << "Ошибка максимальной цены товара. Не более 700 ед.\n";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "Новый товар: " << newName << " - " << newCodeName << "\n";
			std::cout << "Кол-во: " << newCount << "\n";
			std::cout << "Цена: " << newPrice << "\n";
			std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				storageSize++;
				unsigned int* idArrTemp = new unsigned int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				std::string* codeNameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				double* priceArrTemp = new double[storageSize];

				FillArray(idArrTemp, idArr, storageSize - 1);
				FillArray(nameArrTemp, nameArr, storageSize - 1);
				FillArray(codeNameArrTemp, codeNameArr, storageSize - 1);
				FillArray(countArrTemp, countArr, storageSize - 1);
				FillArray(priceArrTemp, priceArr, storageSize - 1);

				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				codeNameArrTemp[storageSize - 1] = newCodeName;
				countArrTemp[storageSize - 1] = count;
				priceArrTemp[storageSize - 1] = price;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(codeNameArr, codeNameArrTemp);
				std::swap(countArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);

				delete[]idArrTemp, nameArrTemp, codeNameArrTemp, countArrTemp, priceArrTemp;
				std::cout << "Идёт подготовка... ";
				Sleep(2000);
				std::cout << "Товар успешно добавлен!\n\n";
				Sleep(1500);
				break;

			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}

		if (exit == false)
		{
			break;
		}
	}
}
void ChangeName()
{
	std::string chooseId, newName, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции смены названия\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новое название товара: ";
		Getline(newName);

		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "Ошибка имени. Максимальная длина 60 символов\n";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << nameArr[id] << " --> " << newName << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nввод: ";
				Getline(choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Смена названия завершена\n";
					Sleep(1500);
					break;
				}
				else if (true)
				{
					std::cout << "Отмена операции\n";
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
void DeleteItem() 
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара для удаления или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции удаления товара\n";
			Sleep(1500);
			break;
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
			}
			else
			{
				std::cout << "Товар на удаление: " << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					std::string* codeNameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];

					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						codeNameArrTemp[i] = codeNameArr[c];
						countArrTemp[i] = countArr[c];
						priceArrTemp[i] = priceArr[c];
					}

					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(codeNameArr, codeNameArrTemp);
					std::swap(countArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[]idArrTemp, nameArrTemp, codeNameArrTemp, countArrTemp, priceArrTemp;
					std::cout << "Идёт подготовка... ";
					Sleep(2000);
					std::cout << "Товар успешно удалён\n\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена\n";
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
					if (isStorageCreated == false)
					{
						CreateStorage();
					}
					system("cls");
					ShowSuperAdminMenu();
				}
				else if (choose == "2")
				{
					if (isStorageCreated == false)
					{
						// пустовато...
						BuildStorage();
					}
					system("cls");
					ShowSuperAdminMenu();
				}
				else
				{
					Err();
				}
			}
		}
		else if (currrentStatus == userStatus[1])
		{
			if (isStorageCreated == false)
			{
				CreateStorage();
			}
			system("cls");
		}
		else if (currrentStatus == userStatus[2])
		{
			if (isStorageCreated == false)
			{
				CreateStorage();
			}
			system("cls");
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
bool CheckLogin(const std::string& str)
{
	if (str.size() < 5 || str.size() > 20)
	{
		std::cout << "Ошибка длинны логина!\n";
		Sleep(1500);
		return false;
	}

	for (char sym : str)
	{
		if (!loginSymbols.count(sym))
		{
			std::cout << "Некорректный логин\n";
			Sleep(1500);
			return false;
		}
	}
	for (size_t i = 0; i < userSize; i++)
	{
		if (str == nameArr[i])
		{
			std::cout << "Такой пельзователь уже есть\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}
bool CheckPass(const std::string& str) 
{
	if (str.size() < 8 || str.size() > 30)
	{
		std::cout << "Ошибка длинны пароля!\n";
		Sleep(1500);
		return false;
	}

	int symCount = 0;
	int numCount = 0;
	std::unordered_set<char> specialSynbols{'!','@','#','$','%','^','&','*','(',')','-','_','=','+','/','?','|','\\','\"','\'',',','.','<','>','~','`',':',';','{','}','[',']'};
	for (char sym : str)
	{
		if (!passSymbols.count(sym))
		{
			std::cout << "Некорректный пароль\n";
			Sleep(1500);
			return false;
		}

		if (std::isdigit(sym))
		{
			numCount++;
		}
		if (specialSynbols.count(sym))
		{
			symCount++;
		}
	}
	if (numCount > 2 && symCount > 2)
	{
		return true;
	}
	else
	{
		std::cout << "Минимум 3 символа и 3 цифры";
		Sleep(1500);
		return false;
	}
	return true;
}


void SetLoginSymbols()
{
	for (char i = '0'; i <= '9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	isLoginSetCreated = true;
}
void SetPassSymbols()
{
	for (char i = '!'; i <= '&'; i++)
	{
		passSymbols.insert(i);
	}
	for (char i = '('; i <= '+'; i++)
	{
		passSymbols.insert(i);
	}
	for (char i = '/'; i <= '~'; i++)
	{
		passSymbols.insert(i);
	}

	isPassSetCreated = true;
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
		if (choose == "1" && storageSize > 0)
		{
			
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeUsers();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Склад пуст\n";
			}
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