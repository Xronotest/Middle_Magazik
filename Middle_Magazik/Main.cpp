#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>

//------------------------------------- Учётки --------------------------------------------
size_t userSize = 3;
size_t staffCount = 1;
std::string userStatus[3]{ "Maestro Mainer", "Maestro", "Operator" };
std::string* loginArr = new std::string[userSize]{ "xrono", "admin", "operator" };
std::string* passArr = new std::string[userSize]{ "siege", "admin", "six" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[1], userStatus[2] };
long double* bonusArr = new long double[userSize] {0.0, 0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2, 3};
unsigned int currentId = 0;
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
long double* priceArr = nullptr;

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

void StorageReturner();

template<typename ArrType>
void FillArray(ArrType* dynamicArray, ArrType* staticArray, size_t arraySize);
//-----------------------------------------------------------------------------------------

//------------------------------------- Продажи -------------------------------------------
size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
long double* priceArrCheck;
long double* totalPriceArrCheck;

long double cashIncome = 0.0;
long double bankIncome = 0.0;
long double cash = 990000;

void Selling();
void CheckArrAppend();
void PrintCheck(long double& totalSum);

long double Discount(long double& totalSum);

//-----------------------------------------------------------------------------------------

//------------------------------------- Служебные -----------------------------------------
std::unordered_set<char> loginSymbols;
std::unordered_set<char> passSymbols;
bool isLoginSetCreated = false;
bool isPassSetCreated = false;

void Start();
bool Login();
bool Logout();
void ShowIncome();
void SetLoginSymbols();
void SetPassSymbols();
bool CheckLogin(const std::string &str);
bool CheckPass(const std::string& str);
void ShowSuperAdminMenu();
void ShowAdminMenu();
void ShowUserMenu();
bool IsNumber(const std::string& str);
inline void Getline(std::string& str);
inline void Err(int time = 1500);
//-----------------------------------------------------------------------------------------


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();


	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;
	delete[]bonusArr;
	delete[]userIdArr;

	if (isStorageCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]codeNameArr;
		delete[]countArr;
		delete[]priceArr;
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
			DeleteUser();
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
				if (newRole == userStatus[2])
				{
					staffCount++;
				}
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];
				long double* bonusArrTemp = new long double[userSize];
				unsigned int* userIdArrTemp = new unsigned int[userSize];

				FillArray(loginArrTemp, loginArr, userSize - 1);
				FillArray(passArrTemp, passArr, userSize - 1);
				FillArray(statusArrTemp, statusArr, userSize - 1);
				FillArray(bonusArrTemp, bonusArr, userSize - 1);
				FillArray(userIdArrTemp, userIdArr, userSize - 1);

				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;
				bonusArrTemp[userSize - 1] = 0.0;
				userIdArrTemp[userSize - 1] = userSize;

				std::swap(loginArr, loginArrTemp);
				std::swap(passArr, passArrTemp);
				std::swap(statusArr, statusArrTemp);
				std::swap(bonusArr, bonusArrTemp);
				std::swap(userIdArr, userIdArrTemp);

				delete[]loginArrTemp;
				delete[]passArrTemp;
				delete[]statusArrTemp;
				delete[]bonusArrTemp;
				delete[]userIdArrTemp;

				std::cout << "Идёт подготовка... ";
				Sleep(2000);
				exit = false;
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

		ShowUsers();
		std::cout << "\nВыберете номер пользователя для удаления или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена удаления пользователя!\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			userId = std::stoi(chooseId);
			if (userId < isAdmin || userId > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует!\n";
				Sleep(1500);
				break;
			}

			while (true)
			{
				system("cls");
				if (currrentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
				{
					std::cout << "Нельзя удалять админа!\n";
					Sleep(1500);
					break;
				}

				std::cout << "Удаление пользователя: " << loginArr[userId] << "\n\n";
				std::cout << "Для подтверждения введите пароль Мейнера или \"exit\" для выхода: ";
				Getline(checkPass);
				if (checkPass == "exit")
				{
					std::cout << "Отмена удаления пользователя: " << loginArr[userId] << "\n";
					Sleep(1500);
					break;
				}
				else if (checkPass == passArr[0])
				{
					if (statusArr[userId] == userStatus[2])
					{
						staffCount--;
					}
					userSize--;
					std::string* loginArrTemp = new std::string[userSize];
					std::string* passArrTemp = new std::string[userSize];
					std::string* statusArrTemp = new std::string[userSize];
					long double* bonusArrTemp = new long double[userSize];
					unsigned int* userIdArrTemp = new unsigned int[userSize];

					for (size_t i = 0, c = 0; i < userSize; i++, c++)
					{
						if (userId == c)
						{
							c++;
						}
						loginArrTemp[userSize - 1] = loginArr[c];
						passArrTemp[userSize - 1] = passArr[c];
						statusArrTemp[userSize - 1] = statusArr[c];
						bonusArrTemp[userSize - 1] = bonusArr[c];
						userIdArrTemp[userSize - 1] = i + 1;
					}

					std::swap(loginArr, loginArrTemp);
					std::swap(passArr, passArrTemp);
					std::swap(statusArr, statusArrTemp);
					std::swap(bonusArr, bonusArrTemp);
					std::swap(userIdArr, userIdArrTemp);

					delete[]loginArrTemp;
					delete[]passArrTemp;
					delete[]statusArrTemp;
					delete[]bonusArrTemp;
					delete[]userIdArrTemp;
					std::cout << "Идёт подготовка... ";
					Sleep(2000);
					std::cout << "Пользователь успешно добавлен!\n\n";
					Sleep(1500);
					break;
				}
				else
				{
					Err();
				}
			}
		}
		else
		{
			Err();
		}
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
	long double price[staticSize]{ 936000, 87400, 147800, 680800, 120200, 46800, 200900, 700000, 990000, 420000 };

	if (isStorageCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]codeNameArr;
		delete[]countArr;
		delete[]priceArr;
	}

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	codeNameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new long double[storageSize];

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
	long double newPrice = 0.0;

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
	long double price = 0.0;
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
					std::cout << "Ошибка максимальной цены товара. Не более 2000000 руб.\n";
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
				long double* priceArrTemp = new long double[storageSize];

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

				delete[]idArrTemp;
				delete[]nameArrTemp;
				delete[]codeNameArrTemp;
				delete[]countArrTemp;
				delete[]priceArrTemp;

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
				else if (choose == "2")
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
					long double* priceArrTemp = new long double[storageSize];

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

					delete[]idArrTemp;
					delete[]nameArrTemp;
					delete[]codeNameArrTemp;
					delete[]countArrTemp;
					delete[]priceArrTemp;
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

void Selling()
{
	std::string chooseId, chooseCount, chooseMoney, choose;
	unsigned int id = 0, count = 0;
	int index = -1;
	long double money = 0.0, totalSum = 0.0;
	bool isFirst = false;

	while (true)
	{
		ShowStorage();
		std::cout << "\nВведите ID товара для покупки или \"exit\" для завершения выбора товаров: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			if (isFirst == false)
			{
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				break;
			}

			PrintCheck(totalSum);
			totalSum -= Discount(totalSum);

			std::cout << "Подтвердить покупку?\n1 - Да\n2 - Добавить ещё товара\n3 - Отмена\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				while (true)
				{
					system("cls");
					std::cout << "Выберете способ оплаты\n1 - Наличными\n2 - Безнал\nВвод: ";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "К оплате: " << totalSum << "\n\n";
						std::cout << "Введите кол-во наличных: ";
						Getline(chooseMoney);
						if (IsNumber(chooseMoney))
						{
							money = std::stod(chooseMoney);
							if (money < totalSum)
							{
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;
							}
							else if (money - totalSum > cash)
							{
								std::cout << "У нас нет сдачи.\n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши: " << money << "\n\n";
								Sleep(400);
								std::cout << "Оплата прошла успешно. Сдача: " << money - totalSum << "рублей\n";
								Sleep(2000);
								cash += totalSum;
								cashIncome += totalSum;
								bonusArr[currentId - 1] += totalSum;
								system("cls");
								break;
							}
						}
					}
					else if (choose == "2")
					{
						std::cout << "Приложите карту\n\n";
						Sleep(1500);
						if (rand() % 10 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(300);
							}
							std::cout << "\nСоединения нет.\n\n";
							Sleep(1500);
						}
						else
						{

							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(800);
							}
							std::cout << "\nОплата принята.\n\n";
							Sleep(2000);
							bankIncome += totalSum;
							bonusArr[currentId - 1] += totalSum;
							system("cls");
							break;
						}
					}
					else if (choose == "EvilEye")
					{
						std::cout << "Rainbow оплатила ваши покупки.";
						Sleep(1500);
						system("cls");
						break;
					}
					else
					{
						Err();
					}
				}

				delete[]idArrCheck;
				delete[]nameArrCheck;
				delete[]countArrCheck;
				delete[]priceArrCheck;
				delete[]totalPriceArrCheck;

				idArrCheck = nullptr;
				nameArrCheck = nullptr;
				countArrCheck = nullptr;
				priceArrCheck = nullptr;
				totalPriceArrCheck = nullptr;

				checkSize = 0;

				break;
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Отмена покупки!\n";

				Sleep(1500);
				StorageReturner();
				system("cls");
				return;
			}
			else if (choose == "EvilEye")
			{

			}
			else
			{
				Err();
			}
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id <  0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		std::cout << "\nВведите кол-во товара или \"exit\" для выбора другого товара: ";
		Getline(chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "Отмена покупки: " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}
		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);
			if (count <  1 || count > countArr[id])
			{
				std::cout << "Ошибка кол-ва: " << nameArr[id] << "\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		CheckArrAppend();
		if (isFirst == false)
		{
			isFirst = true;
		}
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		countArr[id] -= count;
		totalSum += totalPriceArrCheck[index];

		std::cout << "\nТовар добавлен в чек\n\n";
		Sleep(1000);
	}
}
void CheckArrAppend()
{
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrcheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	long double* priceArrCheckTemp = new long double[checkSize];
	long double* totalPriceArrCheckTemp = new long double[checkSize];

	FillArray(idArrCheckTemp, idArrCheck, checkSize - 1);
	FillArray(nameArrcheckTemp, nameArrCheck, checkSize - 1);
	FillArray(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArray(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArray(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrcheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[]idArrCheckTemp;
	delete[]nameArrcheckTemp;
	delete[]countArrCheckTemp;
	delete[]priceArrCheckTemp;
	delete[]totalPriceArrCheckTemp;
}
void PrintCheck(long double& totalSum)
{
	system("cls");
	std::cout << "№\t" << "ID\t" << std::left << std::setw(40) << "Название товара\t\t" <<
		std::left << std::setw(10) << "Кодовое имя\t" << "Цена за ед\t" << "Кол-во\t" << "Итого\n";

	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << idArrCheck[i] << "\t" << std::left << std::setw(40) << nameArrCheck[i]
			<< "\t\t" << std::left << std::setw(10) << codeNameArr[i] << "\t" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << std::fixed << totalPriceArrCheck[i] << "\n";
	}
	Discount(totalSum);
	std::cout << "\nИтого к оплате: " << std::fixed << totalSum - Discount(totalSum) << std::left << std::setw(10) << "\n\n";
}
void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[]idArrCheck;
	delete[]nameArrCheck;
	delete[]countArrCheck;
	delete[]priceArrCheck;
	delete[]totalPriceArrCheck;

	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
	checkSize = 0;
}
long double Discount(long double& totalSum)
{
	long double discount = 0.0;
	bool evil = false, black = false;

	for (size_t i = 0; i < checkSize; i++)
	{
		if (countArrCheck[i] == 3)
		{
			if (idArrCheck[i] == idArr[0])
			{
				evil = true;
			}
			else if (idArrCheck[i] == idArr[1])
			{
				black = true;
			}
		}
	}
	if (black && evil)
	{
		discount += totalSum * 0.1;
		std::cout << "Вы собрали набор \"Наблюдатель\" и получили скидку 10%\n";
	}
	if (totalSum > 10000000)
	{
		discount += totalSum * 0.15;
		std::cout << "Вы собрали карзину более чем на 10000000 и получили скидку 15%\n";
	}
	return discount;
}

void Start() 
{
	std::string choose;
	while (true)
	{
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
				ShowAdminMenu();
			}
			else if (currrentStatus == userStatus[2])
			{
				if (isStorageCreated == false)
				{
					CreateStorage();
				}
				system("cls");
				ShowUserMenu();
				
			}
		}
		else
		{
			system("cls");
			std::cout << "Введите парось супер админа для завершения смены или \"exit\" для отмены: ";
			Getline(choose);
			if (choose == passArr[0])
			{
				system("cls");
				std::cout << "Итоговая прибыль за смену: " << std::fixed << cashIncome + bankIncome;
				std::cout << "\n\n\n\t\tЗавершение работы...\n\n";
				Sleep(2000);
				break;
			}
			else if (choose == "exit")
			{
				continue;
			}
			else
			{
				Err();
			}
		}
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
				currentId = userIdArr[i];
				return true;
			}
		}

		Err();
	}
}
bool Logout()
{
	std::string choose;
	system("cls");
	while (true)
	{
		std::cout << "Для подтверждения выхода из пользователя введите свой пароль или \"exit\" для возврата в меню: ";
		Getline(choose);
		if (choose == "exit")
		{
			system("cls");
			return false;
		}
		else if (choose == passArr[currentId - 1] || choose == passArr[0])
		{
			system("cls");
			return true;
		}
		else
		{
			Err();
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

void ShowIncome()
{
	system("cls");
	std::cout << "Текущая прибыль за смену\n\n";
	std::cout << "Наличный расчёт: " << cashIncome << "\n";
	std::cout << "Безналичный: " << bankIncome << "\n";
	std::cout << "Итого: " << bankIncome + cashIncome << "\n\n";
	std::cout << "Сумма ваших продаж: " << bonusArr[currentId] << "\n\n";

	system("pause");
	system("cls");
}

void ShowSuperAdminMenu()
{
	system("cls");
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
			Selling();
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
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Logout())
			{
				break;
			}
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
void ShowAdminMenu()
{
	system("cls");
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - Редактировать склад\n";
		std::cout << "6 - Редактировать персонал\n";
		std::cout << "7 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);
		system("cls");
		if (choose == "1" && storageSize > 0)
		{
			Selling();
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
		else if (choose == "5")
		{
			ChangeStorage();
		}
		else if (choose == "6")
		{
			ChangeUsers();
		}
		else if (choose == "7")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Logout())
			{
				break;
			}
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
void ShowUserMenu()
{
	system("cls");
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "Ввод: ";
		Getline(choose);
		system("cls");
		if (choose == "1" && storageSize > 0)
		{
			Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Logout())
			{
				break;
			}
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