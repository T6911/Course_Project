#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string>
#include <cctype>
#include <iomanip>
#include <locale>
#include <codecvt>
using namespace std;

struct Client {
	string Login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	int family;
	string password;
	int Room;
	int Hotel;
	int Time;
	
	void setAll(string login, string SecondName,string Name, int Age,string Country, int family, string password,int Room,int Hotel,int Time) {
		this->Login = login;
		this->SecondName = SecondName;
		this->Name = Name;
		this->Age = Age;
		this->Country = Country;
		this->family = family;
		this->password = password;
		this->Room = Room;
		this->Hotel = Hotel;
		this->Time = Time;
	}

};
struct registrationMeneger {
	string Login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	string Number;
	int family;
	int Aducation;
	string password;


	void setAll(string login, string SecondName, string Name, int Age, string Country, string Number, int family, int Aducation, string password) {
		this->Login = login;
		this->SecondName = SecondName;
		this->Name = Name;
		this->Age = Age;
		this->Country = Country;
		this->family = family;
		this->Number = Number;
		this->Aducation = Aducation;
		this->password = password;
	}

};
struct Meneger {
	string Login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	string Number;
	int family;
	int Aducation;
	string password;


	void setAll(string login,string SecondName, string Name, int Age, string Country, string Number, int family, int Aducation, string password) {
		this->Login = login;
		this->SecondName = SecondName;
		this->Name = Name;
		this->Age = Age;
		this->Country = Country;
		this->family = family;
		this->Number = Number;
		this->Aducation = Aducation;
		this->password = password;
	}

};
struct Countryes {
	int Num;
	string Country;
	string Lang;
	string Code;

	void setAll(int Num, string Country, string Lang, string Code) {
		this->Num = Num;
		this->Country = Country;
		this->Lang = Lang;
		this->Code = Code;
	}
};
struct Room3 {
	int Num;
	int TypeRoom;
	int TypeLive;
	int Look;
	int Size;
	int Cost;
	int Status;

	void setAll(int Num, int TypeRoom, int TypeLive, int Look, int Size, int Cost, int Status) {
		this->Num = Num;
		this->TypeRoom = TypeRoom;
		this->TypeLive = TypeLive;
		this->Size = Size;
		this->Look = Look;
		this->Cost = Cost;
		this->Status = Status;
	}
};
struct Room4 {
	int Num;
	int TypeRoom;
	int TypeLive;
	int Look;
	int Size;
	int Cost;
	int Status;

	void setAll(int Num, int TypeRoom, int TypeLive, int Look, int Size, int Cost, int Status) {
		this->Num = Num;
		this->TypeRoom = TypeRoom;
		this->TypeLive = TypeLive;
		this->Size = Size;
		this->Look = Look;
		this->Cost = Cost;
		this->Status = Status;
	}
};
struct Room5 {
	int Num;
	int TypeRoom;
	int TypeLive;
	int Look;
	int Size;
	int Cost;
	int Status;

	void setAll(int Num, int TypeRoom, int TypeLive, int Look, int Size, int Cost, int Status) {
		this->Num = Num;
		this->TypeRoom = TypeRoom;
		this->TypeLive = TypeLive;
		this->Size = Size;
		this->Look = Look;
		this->Cost = Cost;
		this->Status = Status;
	}
};
struct Roomf {
	int Num;
	int TypeRoom;
	int TypeLive;
	int Look;
	int Size;
	int Cost;
	int Status;
	int TypeHotel;

	void setAll(int Num, int TypeRoom, int TypeLive, int Look, int Size, int Cost, int Status,int TypeHotel) {
		this->Num = Num;
		this->TypeRoom = TypeRoom;
		this->TypeLive = TypeLive;
		this->Look = Look;
		this->Size = Size;
		this->Cost = Cost;
		this->Status = Status;
		this->TypeHotel = TypeHotel;
	}
};
struct RequestClient {
	string login;
	int num;
	int hotel;
	int time;
	string SecondName;
	string Name;

	void setAll(string id,int num,int hotel,int time, string SecondName,string Name) {
		this->login = id;
		this->num = num;
		this->hotel = hotel;
		this->time = time;
		this->SecondName = SecondName;
		this->Name = Name;
	}
};

/*-------------------------------------------Глобальные переменные----------------------------------------------------------*/
/*----Цветовое оформление---*/

extern int colorSelect;
extern int colorUnSelect;
extern int colorCorrect;
extern int colorUnCorrect;
extern int colorWarning;
extern int colorTime;

/*--------Структуры---------*/

extern vector <Client> regisClient;
extern vector <Meneger> inMeneger;
extern vector <registrationMeneger> regisMeneger;
extern vector <Countryes> inCountry;
extern vector <Room3> inRoom3;
extern vector <Room4> inRoom4;
extern vector <Room5> inRoom5;
extern vector <Roomf> inRoomf;
extern vector <RequestClient> inRequestClient;

/*-------------------------------------------------Чтение-------------------------------------------------------------------*/
void readClient(); // 
void readRegMeneger(); // 
void readMeneger(); // 
void readCountry(); // 
void readRoom(); // 
void readRequestClient();

/*-------------------------------------------------Запись-------------------------------------------------------------------*/
void writeClient(); // 
void writeClient(int j); // 
void writeMeneger(); // 
void writeMeneger(int j);
void writeRegMeneger(); // 
void writeRegMeneger(int j); // 
void writeRoom();
void writeRequestClient();
void writeRequestClient(int id);
void writeClientRoom(int j, int num, int hotel,int time);

/*----------------------------------------------Регистрация-----------------------------------------------------------------*/
void regMenu();  // оформление
void regClient(); // Регистрация клиента
void regMeneger(); // Регистрация менеджера

/*------------------------------------------------Клиент--------------------------------------------------------------------*/
void workClient();
void lookRoom();// Просмотр списка комнат по фильтрам
void MyRoom();
void MyResque();
/*-----------------------------------------------Менеджер-------------------------------------------------------------------*/
void workMeneger(); // оформление
void okRequestClient(int i);
void lookRequestClient();
void banClient();
void PrintFromRegMeneger(int i, int sizeSecondName, int sizeName, int sizeAge, int sizeCountry);
void PrintFromMeneger(int i, int sizeSecondName, int sizeName, int sizeAge, int sizeCountry);
/*------------------------------------------------Админ---------------------------------------------------------------------*/
void workAdmin(); // оформление
void editClient(); // Изменение и удаление(доделать) клиентов, гечи, проверка данных
void editMeneger(); // Изменение и удаление(доделать) менеджеров, добавить преобразование образования, гечи, проверка данных
void lookRequestMeneger(); // оформление
void findMeneger(int i); // связана с lookRequesMeneger, оформление
void Rooms();
void addRoom();
void delRoom();
/*---------------------------------------------Общие функции----------------------------------------------------------------*/
int moveCursor(int sizeMenu, int posCursor); 
void PrintWithCursor(int posCursor, string text, int location,int sizetext);
void PrintWithCursorU(int posCursor, wstring text, int location, int sizetext); // Для u8
void PrintWait(string str, int time);
string fixString(const string str, int length); //обрезка string по размеру
void CleanWait(int size, int time); //Стирание с задержкой
void startMenu(); // Стартовое окно
void entrance(); // Вход, доделать