#include "Header.h"

int colorSelect = 1;
int colorUnSelect = 7;
int colorCorrect = 10;
int colorUnCorrect = 4;
int colorWarning = 6;
int colorTime = 14;

string adminNik = "admin";
string adminPass = "admin";

int clientID = -1;
int menegerID = -1;
int countRequestClient = -1;
int countWaitingMeneger = -1;
int countMeneger = -1;
int countClient = -1;

int ifTypeRoom = 0;
int ifTypeLive = 0;
int ifLook = 0;
int ifCost = 0;
int ifTime = 0;
int ifTypeHotel = 0;
int ch1 = 0;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

vector <Client> regisClient;
vector <Meneger> inMeneger;
vector <registrationMeneger> regisMeneger;
vector <Countryes> inCountry;
vector <Room3> inRoom3;
vector <Room4> inRoom4;
vector <Room5> inRoom5;
vector <Roomf> inRoomf;
vector <RequestClient> inRequestClient;

int moveCursor(int sizeMenu, int posCursor) {
	int ch = 97;
	ch = _getch();
	posCursor = posCursor - 30;
	sizeMenu--;

	if (ch == 119) {
		if (posCursor > 0) {
			posCursor--;
			return (posCursor + 30);
		}
		else if (posCursor == 0) {
			posCursor = sizeMenu;
			return (posCursor + 30);
		}
	}
	else if (ch == 115) {
		if (posCursor < sizeMenu) {
			posCursor++;
			return (posCursor + 30);
		}
		else if (posCursor == sizeMenu) {
			posCursor = 0;
			return (posCursor + 30);
		}
	}
	else if (ch == 13) {
		return posCursor;
	}
	else if (ch == 27) {
		return 100;
	}
	/*keybd_event(VK_RETURN, 0, 0, 0);
	keybd_event(VK_RETURN, key, 0, 0);*/

	else return (posCursor + 30);
}
int moveCursorW(int sizeMenu, int posCursor) {
	int ch = _getch();
	posCursor = posCursor - 30;
	sizeMenu--;

	if (ch == 97) {
		if (posCursor > 0) {
			posCursor--;
			return (posCursor + 30);
		}
		else if (posCursor == 0) {
			posCursor = sizeMenu;
			return (posCursor + 30);
		}
	}
	else if (ch == 100) {
		if (posCursor < sizeMenu) {
			posCursor++;
			return (posCursor + 30);
		}
		else if (posCursor == sizeMenu) {
			posCursor = 0;
			return (posCursor + 30);
		}
	}
	else if (ch == 13) {
		return posCursor;
	}
	else if (ch == 27) {
		return 100;
	}
	/*keybd_event(VK_RETURN, 0, 0, 0);
	keybd_event(VK_RETURN, key, 0, 0);*/

	else return (posCursor + 30);
}
void PrintWithCursor(int posCursor, string text, int location, int sizetext) {
	posCursor = posCursor - 30;
	if (posCursor == location) {
		SetConsoleTextAttribute(hConsole, colorSelect);
		printf(("%" + to_string(sizetext) + "s").c_str(), text.c_str());
		SetConsoleTextAttribute(hConsole, colorUnSelect);
	}
	else printf(("%" + to_string(sizetext) + "s").c_str(), text.c_str());
}
void PrintWithCursorU(int posCursor, wstring text, int location, int sizetext) {
	posCursor = posCursor - 30;
	if (posCursor == location) {
		SetConsoleTextAttribute(hConsole, colorSelect);
		wcout << setw(sizetext) << text;
		SetConsoleTextAttribute(hConsole, colorUnSelect);
	}
	else wcout << setw(sizetext) << text;
}
void PrintWait(string str, int time) {
	int size = str.size();
	for (int i = 0; i < size; i++) {
		cout << str[i];
		Sleep(time);
	}
}
void CleanWait(int size, int time) {
	for (int i = 0; i < size; i++) {
		cout << char(8) << " " << char(8);
		Sleep(time);
	}
}

string fixString(const string str, int length) {
	string stroka = str;
	if (stroka.length() <= length) {
		return stroka;
	}
	else {
		stroka.erase(length);
		if (length >= 3) {
			for (int i = length - 3; i < length; i++) {
				stroka[i] = '*';
			}
		}
		return stroka;
	}
}

int getch1() {
	int ch = _getch();
	return ch;
}

void PrintFromRegMeneger(int i, int sizeSecondName, int sizeName, int sizeAge, int sizeCountry) {
	string SecondName = fixString(regisMeneger[i].SecondName, sizeSecondName - 1);
	string Name = fixString(regisMeneger[i].Name, sizeName - 1);
	string Country = fixString(regisMeneger[i].Country, sizeCountry - 1);
	printf(("%" + to_string(sizeSecondName) + "s").c_str(), SecondName.c_str());
	printf(("%" + to_string(sizeName) + "s").c_str(), Name.c_str());
	printf(("%" + to_string(sizeAge) + "s").c_str(), to_string(regisMeneger[i].Age).c_str());
	printf(("%" + to_string(sizeCountry) + "s").c_str(), Country.c_str());
	switch (regisMeneger[i].Aducation)
	{
	case 2:
		cout << setw(12) << "Базовое";
		break;
	case 3:
		cout << setw(12) << "Специальное";
		break;
	case 4:
		cout << setw(12) << "Высшее";
		break;
	}
}
void PrintFromMeneger(int i, int sizeSecondName, int sizeName, int sizeAge, int sizeCountry) {
	string SecondName = fixString(inMeneger[i].SecondName, sizeSecondName - 1);
	string Name = fixString(inMeneger[i].Name, sizeName - 1);
	string Country = fixString(inMeneger[i].Country, sizeCountry - 1);
	cout << setw(sizeSecondName) << SecondName;
	cout << setw(sizeName) << Name;
	cout << setw(sizeAge) << inMeneger[i].Age;
	cout << setw(sizeCountry) << Country;
	switch (inMeneger[i].Aducation)
	{
	case 2:
		cout << setw(12) << "Базовое";
		break;
	case 3:
		cout << setw(12) << "Специальное";
		break;
	case 4:
		cout << setw(12) << "Высшее";
		break;
	}
}

void readCountry() {
	inCountry.clear();
	ofstream out2("data/countryes.txt", ios::app);
	out2.close();
	ifstream in("data/countryes.txt");
	string Numb;
	int Num;
	string Country;
	string Lang;
	string Code;
	string str;
	for (int i = 0; i < 197; i++) {
		int counter = 0;
		getline(in, str);
		Numb.clear();
		Country.clear();
		Lang.clear();
		Code.clear();
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '*') {
				counter++;
			}
			if (str[i] != '*' && counter == 0) {
				Numb.push_back(str[i]);
			}
			if (str[i] != '*' && counter == 1) {
				Country.push_back(str[i]);
			}
			if (str[i] != '*' && counter == 2) {
				Lang.push_back(str[i]);
			}
			if (str[i] != '*' && counter == 3) {
				Code.push_back(str[i]);
			}
		}
		Num = stoi(Numb);
		Countryes d;
		d.setAll(Num, Country, Lang, Code);
		inCountry.push_back(d);
	}
	in.close();
}
void readRoom() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	inRoom3.clear();
	inRoom4.clear();
	inRoom5.clear();
	ofstream out1("data/Room3.txt", ios::app);
	out1.close();
	ofstream out2("data/Room4.txt", ios::app);
	out2.close();
	ofstream out3("data/Room3.txt", ios::app);
	out3.close();

	int flag = 0;
	int Num;
	string Num_Str;
	int TypeRoom;
	string TypeRoom_Str;
	int TypeLive;
	string TypeLive_Str;
	int Look;
	string Look_Str;
	int Size;
	string Size_Str;
	int Cost;
	string Cost_Str;
	int Status;
	string Status_Str;
	ifstream in1("data/Room3.txt");
	while (in1 >> Num >> TypeRoom >> TypeLive >> Look >> Size >> Cost >> Status) {
		Room3 d;
		d.setAll(Num, TypeRoom, TypeLive, Look, Size, Cost, Status);
		inRoom3.push_back(d);
	}
	in1.close();

	ifstream in2("data/Room4.txt");
	while (in2 >> Num >> TypeRoom >> TypeLive >> Look >> Size >> Cost >> Status) {
		Room4 q;
		q.setAll(Num, TypeRoom, TypeLive, Look, Size, Cost, Status);
		inRoom4.push_back(q);
	}
	in2.close();

	ifstream in3("data/Room5.txt");
	while (in3 >> Num >> TypeRoom >> TypeLive >> Look >> Size >> Cost >> Status) {
		Room5 w;
		w.setAll(Num, TypeRoom, TypeLive, Look, Size, Cost, Status);
		inRoom5.push_back(w);
	}
	in3.close();
}

void readRequestClient() {
	inRequestClient.clear();
	ofstream out("data/ClientRequest.txt", ios::app);
	out.close();
	ifstream in("data/ClientRequest.txt");
	string login;
	int num;
	int hotel;
	int time;
	string SecondName;
	string Name;
	countRequestClient = -1;
	while (in >> login >> num >> hotel >> time >> SecondName >> Name) {
		countRequestClient++;
		RequestClient d;
		d.setAll(login, num, hotel, time, SecondName, Name);
		inRequestClient.push_back(d);
	}
	in.close();
}
void writeRequestClient() {
	readRequestClient();
	ofstream out("data/ClientRequest.txt");
	for (const auto& i : inRequestClient) {
		out << i.login << " " << i.num << " " << i.hotel << " " << i.time << " " << i.SecondName << " " << i.Name << endl;
	}
	out.close();
}
void writeRequestClient(int id) {
	int counter = -1;
	readRequestClient();
	ofstream out("data/ClientRequest.txt");
	for (const auto& i : inRequestClient) {
		counter++;
		if (counter != id) {
			out << i.login << " " << i.num << " " << i.hotel << " " << i.time << " " << i.SecondName << " " << i.Name << endl;
		}
	}
	out.close();
}
void writeRoom() {
	ofstream out1("data/Room3.txt");
	for (const auto& i : inRoom3) {
		out1 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
	}
	out1.close();
	ofstream out2("data/Room4.txt");
	for (const auto& i : inRoom4) {
		out2 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
	}
	out2.close();
	ofstream out3("data/Room5.txt");
	for (const auto& i : inRoom5) {
		out3 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
	}
	out3.close();
}

void writeRoom(int num,int Hotel) {
	ofstream out1("data/Room3.txt");
	for (const auto& i : inRoom3) {
		if (Hotel == 1) {
			if (i.Num == num) {

			}
			else {
				out1 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
			}
		}
		else {
			out1 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
		}
	}
	out1.close();
	ofstream out2("data/Room4.txt");
	for (const auto& i : inRoom4) {
		if (Hotel == 2) {
			if (i.Num == num) {

			}
			else {
				out2 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
			}
		}
		else {
			out2 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
		}
	}
	out2.close();
	ofstream out3("data/Room5.txt");
	for (const auto& i : inRoom5) {
		if (Hotel == 3) {
			if (i.Num == num) {

			}
			else {
				out3 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
			}
		}
		else {
			out3 << i.Num << " " << i.TypeRoom << " " << i.TypeLive << " " << i.Look << " " << i.Size << " " << i.Cost << " " << i.Status << endl;
		}
	}
	out3.close();
}

void readClient() {
	regisClient.clear();
	ofstream out2("Clients/Client.txt", ios::app);
	out2.close();
	ifstream in("Clients/Client.txt");
	string login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	int family;
	string password;
	int Room;
	int Hotel;
	int Time;
	countClient = -1;
	while (in >> login >> SecondName >> Name >> Age >> Country >> family >> password >> Room >> Hotel >> Time) {
		countClient++;
		Client d;
		d.setAll(login, SecondName, Name, Age, Country, family, password, Room, Hotel, Time);
		regisClient.push_back(d);
	}
	in.close();
}
void writeClient() {
	ofstream out("Clients/Client.txt");
	for (const auto& i : regisClient) {
		out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.family << " " << i.password << " " << i.Room << " " << i.Hotel << " " << i.Time << endl;
	}
	out.close();
}
void regClient() {
	readClient();
	setlocale(LC_ALL, "RUS");
	string login;
	string erCounrty = "Такой страны не существует!";
	string erLogin = "Этот логин уже занят!";
	string erAgeMany = "Вы уже мертвы!";
	string erAgeLow = "Возраст слишком мал!";
	string SecondName;
	string Name;
	login.clear();
	SecondName.clear();
	Name.clear();
	bool end = 0;
	string age;
	int Time = 0;
	bool agechech = 0;
	bool Countrychech = 0;
	int Age;
	bool login2 = 0;
	bool log = 0;
	int temp = -1;
	int Room = 0;
	int Hotel = 0;
	string Country;
	Country.clear();
	int family;
	string password;
	password.clear();
	int size;
	int ch;
	int counter = -1;
	PrintWait("Регистрация клиента \n", 20);
	PrintWait("Введите логин: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		login2 = 0;
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				login.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			if (counter > -1) {
				readClient();
				readMeneger();
				size = login.size();
				for (int i = 0; i < size; i++) {
					cout << char(8) << " " << char(8);
				}
				for (const auto& i : regisClient) {
					if (login == i.Login) {
						SetConsoleTextAttribute(hConsole, colorUnCorrect);
						cout << login; cout << " ";
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						end = 0;
						PrintWait(erLogin, 15);
						Sleep(1000);
						CleanWait(erLogin.size() + 1 + size, 20);
						counter = -1;
						login.clear();
						login2 = 1;
						break;
					}
				}
				for (const auto& i : inMeneger) {
					if (login == i.Login) {
						SetConsoleTextAttribute(hConsole, colorUnCorrect);
						cout << login; cout << " ";
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						end = 0;
						SetConsoleTextAttribute(hConsole, colorWarning);
						PrintWait(erLogin, 15);
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						Sleep(1000);
						login2 = 1;
						CleanWait(erLogin.size() + 1 + size, 20);
						login.clear();
						counter = -1;
						break;
					}
				}
				if (login2 == 0) {
					SetConsoleTextAttribute(hConsole, colorCorrect);
					cout << login;
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					end = 1;
				}
			}
			break;
		case 32:
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите пароль: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				password.erase(counter);
				counter = counter - 1;
			}
			break;
		case 32:
			break;
		case 13:
			if (counter > -1) {
				end = 1;
				size = password.size();
				for (int i = 0; i < size; i++) {
					cout << char(8) << " " << char(8);
				}
				SetConsoleTextAttribute(hConsole, colorCorrect);
				cout << password;
				SetConsoleTextAttribute(hConsole, colorUnSelect);
			}
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите фамилию: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		switch (ch)
		{
		case 32:
			break;
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				SecondName.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			if (counter > -1) {
				end = 1;
				size = SecondName.size();
				for (int i = 0; i < size; i++) {
					cout << char(8) << " " << char(8);
				}
				SetConsoleTextAttribute(hConsole, colorCorrect);
				cout << SecondName;
				SetConsoleTextAttribute(hConsole, colorUnSelect);
			}
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите имя: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		switch (ch)
		{
		case 32:
			break;
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				Name.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			if (counter > -1) {
				end = 1;
				size = Name.size();
				for (int i = 0; i < size; i++) {
					cout << char(8) << " " << char(8);
				}
				SetConsoleTextAttribute(hConsole, colorCorrect);
				cout << Name;
				SetConsoleTextAttribute(hConsole, colorUnSelect);
			}
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите возраст: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		agechech = 0;
		ch = _getch();
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				age.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			end = 1;
			size = age.size();
			for (int i = 0; i < size; i++) {
				cout << char(8) << " " << char(8);
			}
			Age = stoi(age);
			if (Age > 130) {
				SetConsoleTextAttribute(hConsole, colorUnCorrect);
				cout << Age; cout << " ";
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				SetConsoleTextAttribute(hConsole, colorWarning);
				PrintWait(erAgeMany, 20); Sleep(1000);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				CleanWait(erAgeMany.size() + 1 + size, 20);
				counter = -1;
				age.erase();
				end = 0;
				agechech = 1;
			}
			if (Age < 14) {
				SetConsoleTextAttribute(hConsole, colorUnCorrect);
				cout << Age; cout << " ";
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				SetConsoleTextAttribute(hConsole, colorWarning);
				PrintWait(erAgeLow, 20); Sleep(1000);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				CleanWait(erAgeLow.size() + 1 + size, 20);
				counter = -1;
				age.erase();
				end = 0;
				agechech = 1;
			}
			if (agechech == 0) {
				SetConsoleTextAttribute(hConsole, colorCorrect);
				cout << Age;
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				end = 1;
			}
			break;
		default:
			if (ch > 47 && ch < 58 && counter < 20) {
				cout << char(ch);
				age.push_back(char(ch));
				counter++;
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите страну: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		Countrychech = 0;
		ch = _getch();
		switch (ch)
		{
		case 32:
			break;
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				Country.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			if (counter > -1) {
				readCountry();
				size = Country.size();
				for (int i = 0; i < size; i++) {
					cout << char(8) << " " << char(8);
				}
				for (const auto& i : inCountry) {
					if (Country == i.Country) {
						SetConsoleTextAttribute(hConsole, colorCorrect);
						cout << Country;
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						Countrychech = 1;
						end = 1;
					}
				}
				if (Countrychech == 0) {
					SetConsoleTextAttribute(hConsole, colorUnCorrect);
					cout << Country; cout << " ";
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					SetConsoleTextAttribute(hConsole, colorWarning);
					PrintWait(erCounrty, 20);
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					Sleep(1000);
					CleanWait(erCounrty.size() + 1 + size, 20);
					Country.clear();
					end = 0;
					counter = -1;
				}
			}
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Выберите семейное положение(1-cвободен, 2-в браке, 3-1ребёнок, 4-2ребёнка): ", 20);
	while (true) {
		char ch2 = _getch();
		if (isdigit(ch2)) {
			if (ch2 - '0' < 5) {
				family = ch2 - '0';
				break;
			}
		}
	}
	readClient();
	Client d;
	cout << "id: " << clientID << end;
	d.setAll(login, SecondName, Name, Age, Country, family, password, Room, Hotel, Time);
	regisClient.push_back(d);
	writeClient();
	cout << "\n";
	cout << "\n";
	PrintWait("Начинается процесс создания профиля\n", 20);
	Sleep(1000);
	setlocale(LC_ALL, "en_US.UTF-8");
	int counteru8 = 0;
	for (int i = 0; i < 101; i++) {
		counteru8 = 0;
		system("cls");
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "                         ";
		wcout << L"┌──────────────────────────────────────────────────┐\n";
		cout << "                         ";
		wcout << L"│";
		for (int j = 0; j < i / 4; j++) {
			counteru8++;
			SetConsoleOutputCP(CP_UTF8);
			SetConsoleCP(CP_UTF8);
			SetConsoleTextAttribute(hConsole, colorCorrect);
			wcout << L"██";
			SetConsoleTextAttribute(hConsole, colorUnSelect);
		}
		for (int y = counteru8; y < 25; y++) {
			wcout << L"  ";
		}
		wcout << L"│\n";
		cout << "                         ";
		wcout << L"└──────────────────────────────────────────────────┘\n";
		cout << "\n";
		cout << "                      "; cout << "                      "; cout << i << " %\n";
		Sleep(25);
	}
	Sleep(1000);
	setlocale(LC_ALL, "Rus");
	system("cls");
	SetConsoleTextAttribute(hConsole, colorCorrect);
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                       "; cout << "                ";
	PrintWait("Профиль успешно создан", 25); cout << "\n";
	SetConsoleTextAttribute(hConsole, colorUnSelect);
	Sleep(2000);
	startMenu();
}
void writeClient(int j) {
	int counter = -1;
	ofstream out("Clients/Client.txt");
	for (const auto& i : regisClient) {
		counter++;
		if (counter != j) {
			out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.family << " " << i.password << " " << i.Room << " " << i.Hotel << " " << i.Time << endl;
		}
	}
	out.close();
}
void writeClientRoom(int j, int num, int hotel, int Time) {
	int counter = -1;
	ofstream out("Clients/Client.txt");
	for (const auto& i : regisClient) {
		counter++;
		if (counter == j) {
			out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.family << " " << i.password << " " << num << " " << hotel << " " << Time << endl;
		}
		else {
			out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.family << " " << i.password << " " << i.Room << " " << i.Hotel << " " << i.Time << endl;
		}
	}
	out.close();
}

void readRegMeneger() {
	regisMeneger.clear();
	ofstream out2("Menegers/WaitingMenegers.txt", ios::app);
	out2.close();
	ifstream in("Menegers/WaitingMenegers.txt");
	string login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	string Number;
	int family;
	int Aducation;
	string password;
	countWaitingMeneger = -1;
	while (in >> login >> SecondName >> Name >> Age >> Country >> Number >> family >> Aducation >> password) {
		countWaitingMeneger++;
		registrationMeneger d;
		d.setAll(login, SecondName, Name, Age, Country, Number, family, Aducation, password);
		regisMeneger.push_back(d);
	}
	in.close();
}
void writeRegMeneger() {
	ofstream out("Menegers/WaitingMenegers.txt");
	for (const auto& i : regisMeneger) {
		out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.Number << " " << i.family << " " << i.Aducation << " " << i.password << endl;
	}
}
void writeRegMeneger(int j) {
	ofstream out("Menegers/WaitingMenegers.txt");
	int counter = -1;
	for (const auto& i : regisMeneger) {
		counter++;
		if (counter != j) {
			out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.Number << " " << i.family << " " << i.Aducation << " " << i.password << endl;
		}
	}
	out.close();
}
void regMeneger() {
	readRegMeneger();
	setlocale(LC_ALL, "Rus");
	string erCounrty = "Такой страны не существует!";
	string erLogin = "Этот логин уже занят!";
	string erAgeMany = "Вы уже мертвы!";
	string erAgeLow = "Возраст слишком мал!";
	string login;
	string SecondName;
	string Name;
	int Age;
	int countryID = -1;
	string Country;
	string Number{ "1234" };
	int family;
	int Aducation;
	string password;

	string age;
	bool agechech = 0;
	bool Countrychech = 0;
	int size;
	bool end = 0;
	int ch;
	bool login2 = 0;
	int counter = -1;
	PrintWait("Регистрация менеджера", 20);
	cout << "\n";
	PrintWait("Введите логин: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		login2 = 0;
		switch (ch)
		{
		case 32:
			break;
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				login.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			readClient();
			readMeneger();
			size = login.size();
			for (int i = 0; i < size; i++) {
				cout << char(8) << " " << char(8);
			}
			for (const auto& i : regisClient) {
				if (login == i.Login) {
					SetConsoleTextAttribute(hConsole, colorUnCorrect);
					cout << login; cout << " ";
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					end = 0;
					PrintWait(erLogin, 15);
					Sleep(1000);
					CleanWait(erLogin.size() + 1 + size, 20);
					counter = -1;
					login.clear();
					login2 = 1;
					break;
				}
			}
			for (const auto& i : inMeneger) {
				if (login == i.Login) {
					SetConsoleTextAttribute(hConsole, colorUnCorrect);
					cout << login; cout << " ";
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					end = 0;
					SetConsoleTextAttribute(hConsole, colorWarning);
					PrintWait(erLogin, 15);
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					Sleep(1000);
					login2 = 1;
					CleanWait(erLogin.size() + 1 + size, 20);
					login.clear();
					counter = -1;
					break;
				}
			}
			if (login2 == 0) {
				SetConsoleTextAttribute(hConsole, colorCorrect);
				cout << login;
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				end = 1;
			}
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите пароль: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			cout << char(ch) << " " << char(ch);
			password.erase(counter);
			counter--;
			break;
		case 13:
			end = 1;
			size = password.size();
			for (int i = 0; i < size; i++) {
				cout << char(8) << " " << char(8);
			}
			SetConsoleTextAttribute(hConsole, colorCorrect);
			cout << password;
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			break;
		case 32:
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				password.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите фамилию: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				SecondName.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			end = 1;
			size = SecondName.size();
			for (int i = 0; i < size; i++) {
				cout << char(8) << " " << char(8);
			}
			SetConsoleTextAttribute(hConsole, colorCorrect);
			cout << SecondName;
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			break;
		case 32:
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				SecondName.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите имя: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		ch = _getch();
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				Name.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			end = 1;
			size = Name.size();
			for (int i = 0; i < size; i++) {
				cout << char(8) << " " << char(8);
			}
			SetConsoleTextAttribute(hConsole, colorCorrect);
			cout << Name;
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			break;
		case 32:
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				Name.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите возраст: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		agechech = 0;
		ch = _getch();
		switch (ch)
		{
		case 32:
			break;
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				age.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			end = 1;
			size = age.size();
			for (int i = 0; i < size; i++) {
				cout << char(8) << " " << char(8);
			}
			Age = stoi(age);
			if (Age > 130) {
				SetConsoleTextAttribute(hConsole, colorUnCorrect);
				cout << Age; cout << " ";
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				SetConsoleTextAttribute(hConsole, colorWarning);
				PrintWait(erAgeMany, 20); Sleep(1000);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				CleanWait(erAgeMany.size() + 1 + size, 20);
				counter = -1;
				age.erase();
				end = 0;
				agechech = 1;
			}
			if (Age < 14) {
				SetConsoleTextAttribute(hConsole, colorUnCorrect);
				cout << Age; cout << " ";
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				SetConsoleTextAttribute(hConsole, colorWarning);
				PrintWait(erAgeLow, 20); Sleep(1000);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				CleanWait(erAgeLow.size() + 1 + size, 20);
				counter = -1;
				age.erase();
				end = 0;
				agechech = 1;
			}
			if (agechech == 0) {
				SetConsoleTextAttribute(hConsole, colorCorrect);
				cout << Age;
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				end = 1;
			}
			break;
		default:
			if (ch > 47 && ch < 58 && counter < 20) {
				cout << char(ch);
				age.push_back(char(ch));
				counter++;
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Введите страну: ", 20);
	end = 0;
	counter = -1;
	while (!end) {
		Countrychech = 0;
		ch = _getch();
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				Country.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			readCountry();
			size = Country.size();
			for (int i = 0; i < size; i++) {
				cout << char(8) << " " << char(8);
			}
			for (const auto& i : inCountry) {
				if (Country == i.Country) {
					countryID++;
					SetConsoleTextAttribute(hConsole, colorCorrect);
					cout << Country;
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					Countrychech = 1;
					end = 1;
				}
			}
			if (Countrychech == 0) {
				SetConsoleTextAttribute(hConsole, colorUnCorrect);
				cout << Country; cout << " ";
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				SetConsoleTextAttribute(hConsole, colorWarning);
				PrintWait(erCounrty, 20);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				Sleep(1000);
				CleanWait(erCounrty.size() + 1 + size, 20);
				Country.clear();
				end = 0;
				counter = -1;
			}
			break;
		case 32:
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				Country.push_back(char(ch));
			}
			break;
		}
	}
	cout << endl;
	PrintWait("Выберите семейное положение(1-cвободен, 2-в браке, 3-1ребёнок, 4-2ребёнка): ", 20);
	while (true) {
		char ch2 = _getch();
		if (isdigit(ch2)) {
			if (ch2 - '0' < 5) {
				family = ch2 - '0';
				break;
			}
		}
	}
	cout << endl;
	/*cout << "Введите номер телефона: ";
	end = 0;
	counter = -1;
	while (!end) {
	}
	cout << endl;*/
	PrintWait("Выберите образование(1-нет, 2-базовое, 3-специальное, 4-высшее): ", 20);
	while (true) {
		char ch2 = _getch();
		if (isdigit(ch2)) {
			if (ch2 - '0' < 5) {
				Aducation = ch2 - '0';
				break;
			}
		}
	}
	registrationMeneger d;
	d.setAll(login, SecondName, Name, Age, Country, Number, family, Aducation, password);
	regisMeneger.push_back(d);
	writeRegMeneger();
	system("cls");
	SetConsoleTextAttribute(hConsole, colorCorrect);
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "                      ";
	PrintWait("Заявка создана, ожидайте подтверждения администратора", 25); cout << "\n";
	SetConsoleTextAttribute(hConsole, colorUnSelect);
	Sleep(2000);
	startMenu();
}

void readMeneger() {
	inMeneger.clear();
	ofstream out2("Menegers/Menegers.txt", ios::app);
	out2.close();
	ifstream in("Menegers/Menegers.txt");
	string login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	string Number;
	int family;
	int Aducation;
	string password;
	countMeneger = -1;
	while (in >> login >> SecondName >> Name >> Age >> Country >> Number >> family >> Aducation >> password) {
		countMeneger++;
		Meneger d;
		d.setAll(login, SecondName, Name, Age, Country, Number, family, Aducation, password);
		inMeneger.push_back(d);
	}
	in.close();
}
void writeMeneger() {
	ofstream out("Menegers/Menegers.txt");
	for (const auto& i : inMeneger) {
		out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.Number << " " << i.family << " " << i.Aducation << " " << i.password << endl;
	}
	out.close();
}
void writeMeneger(int j) {
	int counter = -1;
	ofstream out("Menegers/Menegers.txt");
	for (const auto& i : inMeneger) {
		counter++;
		if (counter != j) {
			out << i.Login << " " << i.SecondName << " " << i.Name << " " << i.Age << " " << i.Country << " " << i.Number << " " << i.family << " " << i.Aducation << " " << i.password << endl;
		}
	}
	out.close();
}

void workAdmin() {
	bool workadmin = 0;
	int posCursor = 30;
	int sizeMenu = 5;
	while (!workadmin) {
		system("cls");
		cout << "                                       Ваш статус: Админ\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║  Редактирование клиентов  ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║ Редактирование менеджеров ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║   Редактирование комнат   ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 2, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 3, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║    Просмотреть заявки     ║", 3, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 3, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 4, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Выйти в меню        ║", 4, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 4, 62); cout << "\n";
		setlocale(LC_ALL, "Rus");
		switch (posCursor)
		{
		case 0:
			workadmin = 1;
			system("cls");
			editClient();
			break;
		case 1:
			workadmin = 1;
			system("cls");
			editMeneger();
			break;
		case 2:
			workadmin = 1;
			system("cls");
			Rooms();
			break;
		case 3:
			workadmin = 1;
			system("cls");
			lookRequestMeneger();
			break;
		case 4:
			workadmin = 1;
			system("cls");
			startMenu();
			break;
		}
		if (workadmin == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { workadmin = 1; startMenu(); break; }
	}
}
void workMeneger() {
	bool workmeneger = 0;
	int posCursor = 30;
	int sizeMenu = 5;
	while (!workmeneger) {
		system("cls");
		cout << "                          Добро пожаловать, " << inMeneger[menegerID].SecondName << " " << inMeneger[menegerID].Name << "." << " Ваш статус: Менеджер\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         Заселение         ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         Выселение         ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═══════════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Выйти в меню        ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═══════════════════════════╝", 2, 62); cout << "\n";
		setlocale(LC_ALL, "Rus");

		switch (posCursor)
		{
		case 0:
			workmeneger = 1;
			system("cls");
			lookRequestClient();
			break;
		case 1:
			workmeneger = 1;
			system("cls");
			banClient();
			break;
		case 2:
			workmeneger = 1;
			system("cls");
			startMenu();
			break;
		}
		if (workmeneger == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { startMenu(); workmeneger = 1; break; }
		system("cls");
	}
}
void workClient() {
	bool workclient = 0;
	int posCursor = 30;
	int sizeMenu = 6;
	int code = 0;
	while (!workclient) {
		system("cls");
		cout << "\n";
		cout << "                          Добро пожаловать, " << regisClient[clientID].SecondName << " " << regisClient[clientID].Name << "." << " Ваш статус: Клиент\n";
		cout << "\n";

		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔═════════════════════════╗", 0, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Выбор номера      ║", 0, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═════════════════════════╝", 0, 64); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═════════════════════════╗", 1, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Мои Заявки        ║", 1, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═════════════════════════╝", 1, 64); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═════════════════════════╗", 2, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Моя комната       ║", 2, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═════════════════════════╝", 2, 64); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═════════════════════════╗", 3, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"║     Удалить аккаунт     ║", 3, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═════════════════════════╝", 3, 64); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔═════════════════════════╗", 4, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"║      Выйти в меню       ║", 4, 64); cout << "\n";
		PrintWithCursorU(posCursor, L"╚═════════════════════════╝", 4, 64); cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << endl;
		switch (posCursor)
		{
		case 0:
			workclient = 1;
			system("cls");
			lookRoom();
			break;
		case 1:
			workclient = 1;
			system("cls");
			MyResque();
			break;
		case 2:
			workclient = 1;
			system("cls");
			MyRoom();
			break;
		case 3:
			workclient = 1;
			system("cls");
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "                                       ";
			PrintWait("Подтвердите удаление", 25);
			code = getch1();
			if (code == 13) {
				readClient();
				int counter = -1;
				if (regisClient[clientID].Room != 0) {
					counter = -1;
					switch (regisClient[clientID].Hotel)
					{
					case 1:
						for (const auto& i : inRoom3) {
							counter++;
							if (i.Num == regisClient[clientID].Room) {
								inRoom3[counter].Status = 0;
								break;
							}
						}
						break;
					case 2:
						for (const auto& i : inRoom4) {
							counter++;
							if (i.Num == regisClient[clientID].Room) {
								inRoom4[counter].Status = 0;
								break;
							}
						}
						break;
					case 3:
						for (const auto& i : inRoom3) {
							counter++;
							if (i.Num == regisClient[clientID].Room) {
								inRoom5[counter].Status = 0;
								break;
							}
						}
						break;
					}
				}
				writeClient(clientID);
				SetConsoleTextAttribute(hConsole, colorUnCorrect);
				system("cls");
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "                                       ";
				PrintWait("Идёт процесс удаления", 25);
				SetConsoleTextAttribute(hConsole, colorCorrect);
				Sleep(1500);
				system("cls");
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "                                       ";
				PrintWait("Удаление завершено", 25);
				SetConsoleTextAttribute(hConsole, colorSelect);
				Sleep(1500);
				startMenu();
				break;
			}
			else workClient();
			break;
		case 4:
			workclient = 1;
			system("cls");
			startMenu();
			ifTypeRoom = 0;
			ifTypeLive = 0;
			ifLook = 0;
			ifCost = 0;
			ifTime = 0;
			ifTypeHotel = 0;
			break;
		}
		if (workclient == 0) posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { startMenu(); workclient = 1; break; }
	}
}
//--------------------------------Клиент
void lookRoom() {
	readClient();
	if (regisClient[clientID].Room != 0 && regisClient[clientID].Hotel != 0) {
		SetConsoleTextAttribute(hConsole, colorUnCorrect);
		cout << "Ваша комната уже одобрена, для смены свяжитесь с персоналом\n";
		SetConsoleTextAttribute(hConsole, colorUnSelect);
		Sleep(1500);
		workClient();
	}
	int sizeMenuWidth = 5;
	int sizeMenuHight = 20;
	int posCursorHight = 30;
	int posCursorWidth = 30;
	int counterHight = -1;
	int sizeinRoomf;
	bool endfunk = 0;
	bool ffflag = 0;
	int str = 0;
	string fTypeRoom;
	string fTypeLive;
	string fLook;
	string fCost;
	string fTime;
	string fTypeHotel;
	string ConvTypeRoom;
	string ConvTypeLive;
	string ConvLook;
	string ConvTypeHotel;
	string Conv;
	while (!endfunk) {
		switch (ifTypeRoom)
		{
		case 0:
			fTypeRoom = "No";
			break;
		case 1:
			fTypeRoom = "Econom";
			break;
		case 2:
			fTypeRoom = "Standart";
			break;
		case 3:
			fTypeRoom = "Delux";
			break;
		case 4:
			fTypeRoom = "Lux";
			break;
		case 5:
			fTypeRoom = "Pr.Lux";
			break;
		}
		switch (ifTypeLive)
		{
		case 0:
			fTypeLive = "No";
			break;
		case 1:
			fTypeLive = "SNGL";
			break;
		case 2:
			fTypeLive = "DBL";
			break;
		case 3:
			fTypeLive = "TWIN";
			break;
		case 4:
			fTypeLive = "TRPL";
			break;
		case 5:
			fTypeLive = "QDPL";
			break;
		}
		switch (ifLook)
		{
		case 0:
			fLook = "No";
			break;
		case 1:
			fLook = "Двор";
			break;
		case 2:
			fLook = "Город";
			break;
		case 3:
			fLook = "Река";
			break;
		}
		fCost = to_string(ifCost);
		switch (ifTypeHotel)
		{
		case 0:
			fTypeHotel = "No";
			break;
		case 1:
			fTypeHotel = "3*";
			break;
		case 2:
			fTypeHotel = "4*";
			break;
		case 3:
			fTypeHotel = "5*";
			break;
		}
		if (posCursorWidth<0 || posCursorWidth > posCursorWidth + sizeMenuWidth) { posCursorWidth = 30; }
		readRoom();
		system("cls");
		cout << setw(11) << "Фильтры"; cout << " ";
		PrintWithCursor(posCursorWidth, fTypeRoom, 1, 11); cout << " ";
		PrintWithCursor(posCursorWidth, fTypeLive, 2, 11); cout << " ";
		PrintWithCursor(posCursorWidth, fLook, 3, 11); cout << " ";
		PrintWithCursor(posCursorWidth, fCost, 4, 11); cout << " ";
		PrintWithCursor(posCursorWidth, "", -4, 11); cout << " ";
		PrintWithCursor(posCursorWidth, fTypeHotel, 5, 11); cout << " ";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		wcout << L"───────────────────────────────────────────────────────────────────────────────────────────────────" << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "Страница " << str + 1 << "\n";
		cout << setw(11) << ""; cout << " ";
		cout << setw(11) << "Класс"; cout << " ";
		cout << setw(11) << "Конфиг"; cout << " ";
		cout << setw(11) << "Вид из окна"; cout << " ";
		cout << setw(11) << "Цена"; cout << " ";
		cout << setw(11) << "Площадь"; cout << " ";
		cout << setw(11) << "Тип отеля"; cout << " ";
		cout << endl;
		inRoomf.clear();
		for (const auto& i : inRoom3) {
			int status = 1;
			Roomf d;
			if (ifTypeHotel == 0 || ifTypeHotel == 1) {
				if (ifTypeRoom == 0 || ifTypeRoom == i.TypeRoom) {
					if (ifTypeLive == 0 || ifTypeLive == i.TypeLive) {
						if (ifLook == 0 || ifLook == i.Look) {
							if (ifCost > i.Cost || ifCost == 0) {
								if (i.Status == 0) {
									d.setAll(i.Num, i.TypeRoom, i.TypeLive, i.Look, i.Size, i.Cost, i.Status, status);
									inRoomf.push_back(d);
								}
							}
						}
					}
				}
			}
		}
		for (const auto& i : inRoom4) {
			int status = 2;
			Roomf r;
			if (ifTypeHotel == 0 || ifTypeHotel == 2) {
				if (ifTypeRoom == 0 || ifTypeRoom == i.TypeRoom) {
					if (ifTypeLive == 0 || ifTypeLive == i.TypeLive) {
						if (ifLook == 0 || ifLook == i.Look) {
							if (ifCost > i.Cost || ifCost == 0) {
								if (i.Status == 0) {
									r.setAll(i.Num, i.TypeRoom, i.TypeLive, i.Look, i.Size, i.Cost, i.Status, status);
									inRoomf.push_back(r);
								}
							}
						}
					}
				}
			}
		}
		for (const auto& i : inRoom5) {
			int status = 3;
			Roomf y;
			if (ifTypeHotel == 0 || ifTypeHotel == 3) {
				if (ifTypeRoom == 0 || ifTypeRoom == i.TypeRoom) {
					if (ifTypeLive == 0 || ifTypeLive == i.TypeLive) {
						if (ifLook == 0 || ifLook == i.Look) {
							if (ifCost > i.Cost || ifCost == 0) {
								if (i.Status == 0) {
									y.setAll(i.Num, i.TypeRoom, i.TypeLive, i.Look, i.Size, i.Cost, i.Status, status);
									inRoomf.push_back(y);
								}
							}
						}
					}
				}
			}
		}
		sizeinRoomf = inRoomf.size();
		counterHight = 0;
		for (int i = str * sizeMenuHight; i < (str + 1) * sizeMenuHight; i++) {
			if (i < sizeinRoomf - 2) {
				ConvTypeRoom.clear();
				ConvTypeLive.clear();
				ConvTypeHotel.clear();
				switch (inRoomf[i].TypeRoom)
				{
				case 1:
					ConvTypeRoom = "Econom";
					break;
				case 2:
					ConvTypeRoom = "Standart";
					break;
				case 3:
					ConvTypeRoom = "Delux";
					break;
				case 4:
					ConvTypeRoom = "Lux";
					break;
				case 5:
					ConvTypeRoom = "Pr.Lux";
					break;
				}
				switch (inRoomf[i].TypeLive)
				{
				case 1:
					ConvTypeLive = "SNGL";
					break;
				case 2:
					ConvTypeLive = "DBL";
					break;
				case 3:
					ConvTypeLive = "TWIN";
					break;
				case 4:
					ConvTypeLive = "TRPL";
					break;
				case 5:
					ConvTypeLive = "QDPL";
					break;
				}
				switch (inRoomf[i].TypeHotel)
				{
				case 1:
					ConvTypeHotel = "3*";
					break;
				case 2:
					ConvTypeHotel = "4*";
					break;
				case 3:
					ConvTypeHotel = "5*";
					break;
				}
				switch (inRoomf[i].Look)
				{
				case 1:
					ConvLook = "Двор";
					break;
				case 2:
					ConvLook = "Город";
					break;
				case 3:
					ConvLook = "Река";
					break;
				}
				PrintWithCursor(posCursorHight, "", counterHight, 11); cout << " ";
				PrintWithCursor(posCursorHight, ConvTypeRoom, counterHight, 11); cout << " ";
				PrintWithCursor(posCursorHight, ConvTypeLive, counterHight, 11); cout << " ";
				PrintWithCursor(posCursorHight, ConvLook, counterHight, 11); cout << " ";
				PrintWithCursor(posCursorHight, to_string(inRoom3[i].Cost), counterHight, 11); cout << " ";
				PrintWithCursor(posCursorHight, to_string(inRoom3[i].Size), counterHight, 11); cout << " ";
				PrintWithCursor(posCursorHight, ConvTypeHotel, counterHight, 11); cout << " ";
				cout << "\n";
				counterHight++;
			}
		}
		if (posCursorWidth <= sizeMenuWidth) {
			int posCursor = 30;
			bool end = 0;
			int sizeMenu;
			int ch1 = 0;
			if (posCursorWidth == 5) {
				sizeMenu = 4;
				end = 0; posCursor = 30;
				while (!end) {
					system("cls");
					cout << "Выберите тип отеля\n";
					PrintWithCursor(posCursor, "NO", 0, 10); cout << "\n";
					PrintWithCursor(posCursor, "3 звезды", 1, 10); cout << "\n";
					PrintWithCursor(posCursor, "4 звезды", 2, 10); cout << "\n";
					PrintWithCursor(posCursor, "5 звёзд", 3, 10); cout << "\n";
					if (posCursor < sizeMenu) {
						switch (posCursor)
						{
						case 0:
							end = 1;
							system("cls");
							ifTypeHotel = 0;
							lookRoom();
							break;
						case 1:
							end = 1;
							system("cls");
							ifTypeHotel = 1;
							lookRoom();
							break;
						case 2:
							end = 1;
							system("cls");
							ifTypeHotel = 2;
							lookRoom();
							break;
						case 3:
							end = 1;
							system("cls");
							ifTypeHotel = 3;
							lookRoom();
							break;
						}
					}
					if (end == 0) {
						posCursor = moveCursor(sizeMenu, posCursor);
					}
				}
			}
			switch (posCursorWidth)
			{
			case 0:
				posCursorWidth = 30;
				break;
			case 2:
				sizeMenu = 6;
				while (!end) {
					//cout << "ch1" << ch1 << endl;
					system("cls");
					cout << "Выберите типу проживания\n";
					PrintWithCursor(posCursor, "NO", 0, 10); cout << " ";
					if (posCursor == 30) { cout << " Вывод номеров без применения фильтра по типу проживания"; } cout << "\n";
					PrintWithCursor(posCursor, "SNGL", 1, 10); cout << " ";
					if (posCursor == 31) { cout << " Одноместный номер с одной кроватью подойдет, если тех, кто путешествует в одиночестве"; }cout << "\n";
					PrintWithCursor(posCursor, "DBL", 2, 10); cout << " ";
					if (posCursor == 32) { cout << " Однокомнатный номер с двуспальной кроватью – отличный вариант для пары, путешествующей без детей"; }cout << "\n";
					PrintWithCursor(posCursor, "TWIN", 3, 10); cout << " ";
					if (posCursor == 33) { cout << " Для проживания двух человек с двумя отдельными односпальными кроватями"; }cout << "\n";
					PrintWithCursor(posCursor, "TRPL", 4, 10); cout << " ";
					if (posCursor == 34) { cout << " Cемейный вариант для трех человек"; }cout << "\n";
					PrintWithCursor(posCursor, "QDPL", 5, 10); cout << " ";
					if (posCursor == 35) { cout << " Четырехместное размещение для семьи с двумя детьми"; }cout << "\n";
					if (posCursor < sizeMenu) {
						switch (posCursor)
						{
						case 0:
							end = 1;
							system("cls");
							ifTypeLive = 0;
							lookRoom();
							break;
						case 1:
							end = 1;
							system("cls");
							ifTypeLive = 1;
							lookRoom();
							break;
						case 2:
							end = 1;
							system("cls");
							ifTypeLive = 2;
							lookRoom();
							break;
						case 3:
							end = 1;
							system("cls");
							ifTypeLive = 3;
							lookRoom();
							break;
						case 4:
							end = 1;
							system("cls");
							ifTypeLive = 4;
							lookRoom();
							break;
						case 5:
							end = 1;
							system("cls");
							ifTypeLive = 5;
							lookRoom();
							break;
						}
					}
					if (end == 0) {
						posCursor = moveCursor(sizeMenu, posCursor);
					}
				}
				break;
			case 1:
				sizeMenu = 6;
				while (!end) {
					system("cls");
					cout << "Выберите тип номера" << endl;
					PrintWithCursor(posCursor, "NO", 0, 10); cout << " ";
					if (posCursor == 30) { cout << " Вывод номеров без применения фильтра по типу номера"; }cout << "\n";
					PrintWithCursor(posCursor, "Econon", 1, 10); cout << " ";
					if (posCursor == 31) { cout << " В них есть все условия для отдыха, но никаких излишеств"; }cout << "\n";
					PrintWithCursor(posCursor, "Standart", 2, 10); cout << " ";
					if (posCursor == 32) { cout << " Cтандартный однокомнатный номер, чаще всего с прихожей, санузлом и балконом"; }cout << "\n";
					PrintWithCursor(posCursor, "Delux", 3, 10); cout << " ";
					if (posCursor == 33) { cout << " Номер отличается повышенной комфортностью, по сравнинию с Standart"; }cout << "\n";
					PrintWithCursor(posCursor, "Lux", 4, 10); cout << " ";
					if (posCursor == 34) { cout << " Представляет из себя 2х или 3х комнатный номер. Интерьер номера отличается превосходным дизайном, роскошной обстановкой"; }cout << "\n";
					PrintWithCursor(posCursor, "Pr. Lux", 5, 10); cout << " ";
					if (posCursor == 35) { cout << " Роскошь и масштабность номера такой категории поражает"; }cout << "\n";
					if (posCursor < sizeMenu) {
						switch (posCursor)
						{
						case 0:
							end = 1;
							system("cls");
							ifTypeRoom = 0;
							lookRoom();
							break;
						case 1:
							end = 1;
							system("cls");
							ifTypeRoom = 1;
							lookRoom();
							break;
						case 2:
							end = 1;
							system("cls");
							ifTypeRoom = 2;
							lookRoom();
							break;
						case 3:
							end = 1;
							system("cls");
							ifTypeRoom = 3;
							lookRoom();
							break;
						case 4:
							end = 1;
							system("cls");
							ifTypeRoom = 4;
							lookRoom();
							break;
						case 5:
							end = 1;
							system("cls");
							ifTypeRoom = 5;
							lookRoom();
							break;
						}
					}
					if (end == 0) {
						posCursor = moveCursor(sizeMenu, posCursor);
					}
				}
				break;
			case 3:
				sizeMenu = 4;
				while (!end) {
					system("cls");
					cout << "Выберите вид из окна номера\n";
					PrintWithCursor(posCursor, "NO", 0, 10); cout << "\n";
					PrintWithCursor(posCursor, "Двор", 1, 10); cout << "\n";
					PrintWithCursor(posCursor, "Город", 2, 10); cout << "\n";
					PrintWithCursor(posCursor, "Река", 3, 10); cout << "\n";
					if (posCursor < sizeMenu) {
						switch (posCursor)
						{
						case 0:
							end = 1;
							system("cls");
							ifLook = 0;
							lookRoom();
							break;
						case 1:
							end = 1;
							system("cls");
							ifLook = 1;
							lookRoom();
							break;
						case 2:
							end = 1;
							system("cls");
							ifLook = 2;
							lookRoom();
							break;
						case 3:
							end = 1;
							system("cls");
							ifLook = 3;
							lookRoom();
							break;
						}
					}
					if (end == 0) {
						posCursor = moveCursor(sizeMenu, posCursor);
					}
				}
				break;
			case 4:
				system("cls");
				cout << "Введите максимальную стоимость за 1 сутки\n";
				cin >> ifCost;
				lookRoom();
				break;
			case 5:
				break;
			}
		}
		if (posCursorHight < sizeMenuHight && posCursorWidth == 30) {
			int time = 1;
			bool end = 0;
			while (!end) {
				system("cls");
				switch (inRoomf[(str * sizeMenuHight) + posCursorHight].TypeRoom)
				{
				case 1:
					ConvTypeRoom = "Econom";
					break;
				case 2:
					ConvTypeRoom = "Standart";
					break;
				case 3:
					ConvTypeRoom = "Delux";
					break;
				case 4:
					ConvTypeRoom = "Lux";
					break;
				case 5:
					ConvTypeRoom = "Pr.Lux";
					break;
				}
				cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
				cout << "            ";
				PrintWithCursor(-4, "Номер", 0, 30);  PrintWithCursor(-4, to_string(inRoomf[(str * sizeMenuHight) + posCursorHight].Num), 0, 30); cout << "\n";
				cout << "            ";
				PrintWithCursor(-4, "Тип номера", 0, 30);  PrintWithCursor(-4, ConvTypeRoom, 0, 30); cout << "\n";
				cout << "\n";
				cout << "            ";
				PrintWithCursor(-4, "Укажите время проживания(w,s):", 0, 30);
				SetConsoleTextAttribute(hConsole, colorTime);
				if (time <= 20 && time >= 5) {
					PrintWithCursor(-4, to_string(time) + " дней", 0, 30); cout << "\n";
				}
				else {
					switch (time % 10)
					{
					case 1:
						PrintWithCursor(-4, to_string(time) + " день", 0, 30); cout << "\n";
						break;
					case 2: case 3: case 4:
						PrintWithCursor(-4, to_string(time) + " дня", 0, 30); cout << "\n";
						break;
					case 5: case 6: case 7: case 8: case 9: case 0:
						PrintWithCursor(-4, to_string(time) + " дней", 0, 30); cout << "\n";
						break;
					}
				}
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				cout << "            ";
				PrintWithCursor(-4, "Итоговая стоимость:", 0, 30);
				SetConsoleTextAttribute(hConsole, colorCorrect);
				PrintWithCursor(-4, to_string(time * inRoomf[(str * sizeMenuHight) + posCursorHight].Cost) + "$", 0, 30);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				int ch = _getch();
				if (ch == 119) {
					time++;
				}
				else if (ch == 115) {
					if (time > 1) {
						time--;
					}
				}
				else if (ch == 13) {
					end = 1;
					break;
				}
				else if (ch == 27) {
					lookRoom();
				}
			}
			system("cls");
			readRequestClient();
			cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "                      "; cout << "                ";
			PrintWait("Бронирование номера", 20);
			Sleep(1000);
			system("cls");
			SetConsoleTextAttribute(hConsole, colorCorrect);
			cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "          "; cout << "                ";
			PrintWait("Заявка создана, ожидайте подтверждения менеджером", 20);
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			ofstream out("data/ClientRequest.txt", ios::app);
			out << regisClient[clientID].Login << " " << inRoomf[(str * sizeMenuHight) + posCursorHight].Num << " " << inRoomf[(str * sizeMenuHight) + posCursorHight].TypeHotel
				<< " " << time << " " << regisClient[clientID].SecondName << " " << regisClient[clientID].Name << endl;
			out.close();
			Sleep(1000);
			workClient();
		}
		if (endfunk == 0) {
			int ch = _getch();
			if (ch == 119) {
				if (posCursorHight > 30) {
					posCursorHight--;
				}
				else if (posCursorHight == 30) {
					posCursorHight = sizeMenuHight - 1 + 30;
					if (str >= 1 && str < 15) {
						str--;
					}
				}
			}
			else if (ch == 115) {
				if (posCursorHight - 30 < sizeMenuHight - 1) {
					posCursorHight++;
				}
				else if (posCursorHight - 30 == sizeMenuHight - 1) {
					posCursorHight = 30;
					if (str < 15 && sizeinRoomf > str * sizeMenuHight) {
						str++;
					}
				}
			}
			else if (ch == 97) {
				if (posCursorWidth > 30) {
					posCursorWidth--;
				}
				else if (posCursorWidth == 30) {
					posCursorWidth = sizeMenuWidth + 30;
				}
			}
			else if (ch == 100) {
				if (posCursorWidth - 30 < sizeMenuWidth) {
					posCursorWidth++;
				}
				else if (posCursorWidth - 30 == sizeMenuWidth) {
					posCursorWidth = 30;
				}
			}
			else if (ch == 13) {
				posCursorHight = posCursorHight - 30;
				posCursorWidth = posCursorWidth - 30;
			}

			else if (ch == 27) {
				workClient();
				break;
			}
		}
	}
}
void MyRoom() {
	readClient();
	readRoom();
	int RoomID3 = -2;
	int RoomID4 = -2;
	int RoomID5 = -2;
	int temp = -1;
	string ConvLook;
	string ConvRoom;
	string ConvLive;
	if (regisClient[clientID].Room != 0) {
		switch (regisClient[clientID].Hotel)
		{
		case 1:
			for (const auto& i : inRoom3) {
				temp++;
				if (regisClient[clientID].Room == i.Num) {
					RoomID3 = temp;
					break;
				}
			}
			if (RoomID3 != -2) {
				switch (inRoom3[RoomID3].Look)
				{
				case 1:
					ConvLook = "Двор";
					break;
				case 2:
					ConvLook = "Город";
					break;
				case 3:
					ConvLook = "Река";
					break;
				}
				switch (inRoom3[RoomID3].TypeRoom)
				{
				case 1:
					ConvRoom = "Econom";
					break;
				case 2:
					ConvRoom = "Standart";
					break;
				case 3:
					ConvRoom = "Delux";
					break;
				case 4:
					ConvRoom = "Lux";
					break;
				case 5:
					ConvRoom = "Pr.Lux";
					break;
				}
				switch (inRoom3[RoomID3].TypeLive)
				{
				case 1:
					ConvLive = "SNGL";
					break;
				case 2:
					ConvLive = "DBL";
					break;
				case 3:
					ConvLive = "TWIN";
					break;
				case 4:
					ConvLive = "TRPL";
					break;
				case 5:
					ConvLive = "QDPL";
					break;
				}
				PrintWait("Ваша комната: ", 20);
				cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";
				cout << "                                 "; PrintWait("Комната: ", 20); PrintWithCursor(-1, to_string(inRoom3[RoomID3].Num), 0, 18 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Отель: ", 20); PrintWithCursor(-1, "3*", 0, 20 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Тип комнаты: ", 20); PrintWithCursor(-1, ConvRoom, 0, 14 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Тип жилья: ", 20); PrintWithCursor(-1, ConvLive, 0, 16 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Вид из окна: ", 20); PrintWithCursor(-1, ConvLook, 0, 14 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Время заселения: ", 20); PrintWithCursor(-1, to_string(regisClient[clientID].Time), 0, 10 + 6); cout << "\n";
				while (true) {
					int ch = _getch();
					if (ch == 27) {
						workClient();
						break;
					}
				}
			}
			break;
		case 2:
			for (const auto& i : inRoom4) {
				temp++;
				if (regisClient[clientID].Room == i.Num) {
					RoomID4 = temp;
					break;
				}
			}
			if (RoomID4 != -2) {
				switch (inRoom3[RoomID4].Look)
				{
				case 1:
					ConvLook = "Двор";
					break;
				case 2:
					ConvLook = "Город";
					break;
				case 3:
					ConvLook = "Река";
					break;
				}
				switch (inRoom3[RoomID4].TypeRoom)
				{
				case 1:
					ConvRoom = "Econom";
					break;
				case 2:
					ConvRoom = "Standart";
					break;
				case 3:
					ConvRoom = "Delux";
					break;
				case 4:
					ConvRoom = "Lux";
					break;
				case 5:
					ConvRoom = "Pr.Lux";
					break;
				}
				switch (inRoom3[RoomID4].TypeLive)
				{
				case 1:
					ConvLive = "SNGL";
					break;
				case 2:
					ConvLive = "DBL";
					break;
				case 3:
					ConvLive = "TWIN";
					break;
				case 4:
					ConvLive = "TRPL";
					break;
				case 5:
					ConvLive = "QDPL";
					break;
				}
				PrintWait("Ваша комната: ", 20);
				cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
				cout << "                                 "; PrintWait("Комната: ", 20); PrintWithCursor(-1, to_string(inRoom4[RoomID4].Num), 0, 18 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Отель: ", 20); PrintWithCursor(-1, "3*", 0, 20 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Тип комнаты: ", 20); PrintWithCursor(-1, ConvRoom, 0, 14 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Тип жилья: ", 20); PrintWithCursor(-1, ConvLive, 0, 16 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Вид из окна: ", 20); PrintWithCursor(-1, ConvLook, 0, 14 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Время заселения: ", 20); PrintWithCursor(-1, to_string(regisClient[clientID].Time), 0, 10 + 6); cout << "\n";
				while (true) {
					int ch = _getch();
					if (ch == 27) {
						workClient();
						break;
					}
				}
			}
			break;
		case 3:
			for (const auto& i : inRoom5) {
				temp++;
				if (regisClient[clientID].Room == i.Num) {
					RoomID5 = temp;
					break;
				}
			}
			if (RoomID5 != -2) {
				switch (inRoom3[RoomID5].Look)
				{
				case 1:
					ConvLook = "Двор";
					break;
				case 2:
					ConvLook = "Город";
					break;
				case 3:
					ConvLook = "Река";
					break;
				}
				switch (inRoom3[RoomID5].TypeRoom)
				{
				case 1:
					ConvRoom = "Econom";
					break;
				case 2:
					ConvRoom = "Standart";
					break;
				case 3:
					ConvRoom = "Delux";
					break;
				case 4:
					ConvRoom = "Lux";
					break;
				case 5:
					ConvRoom = "Pr.Lux";
					break;
				}
				switch (inRoom3[RoomID5].TypeLive)
				{
				case 1:
					ConvLive = "SNGL";
					break;
				case 2:
					ConvLive = "DBL";
					break;
				case 3:
					ConvLive = "TWIN";
					break;
				case 4:
					ConvLive = "TRPL";
					break;
				case 5:
					ConvLive = "QDPL";
					break;
				}
				PrintWait("Ваша комната: ", 20);
				cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";
				cout << "                                 "; PrintWait("Комната: ", 20); PrintWithCursor(-1, to_string(inRoom5[RoomID5].Num), 0, 18 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Отель: ", 20); PrintWithCursor(-1, "3*", 0, 20 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Тип комнаты: ", 20); PrintWithCursor(-1, ConvRoom, 0, 14 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Тип жилья: ", 20); PrintWithCursor(-1, ConvLive, 0, 16 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Вид из окна: ", 20); PrintWithCursor(-1, ConvLook, 0, 14 + 6); cout << "\n";
				cout << "                                 "; PrintWait("Время заселения: ", 20); PrintWithCursor(-1, to_string(regisClient[clientID].Time), 0, 10 + 6); cout << "\n";
				while (true) {
					int ch = _getch();
					if (ch == 27) {
						workClient();
						break;
					}
				}
			}
			break;
		}
	}
	else {
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "                                    ";
		PrintWait("У вас ещё нет комнаты", 20);
		Sleep(1000);
		workClient();
	}
}
void MyResque() {
	readRequestClient();
	int posCursor = 30;
	int counter = -1;
	int temp = 0;
	bool end = 0;
	while (!end) {
		system("cls");
		counter = -1;
		for (const auto& i : inRequestClient) {
			counter++;
			if (i.login == regisClient[clientID].Login) {
				temp++;
				PrintWithCursor(50, to_string(counter + 1), counter, 3);
				PrintWithCursor(50, to_string(i.num), -1, 5);
				PrintWithCursor(50, to_string(i.hotel), -1, 5);
				cout << "\n";
			}
		}
		if (posCursor == 100) {
			end = 1;
			workClient();
		}
		if (end == 0) {
			posCursor = moveCursor(temp, posCursor);
		}
	}
}
//--------------------------------Менеджер
void okRequestClient(int i) {
	readRequestClient();
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int pos2Cursor = 30;
	int size2menu = 2;
	bool end = 0;
	string ConvTypeHotel;
	int count = -1;
	bool end2 = 0;
	switch (inRequestClient[i].hotel)
	{
	case 1:
		ConvTypeHotel = "3*";
		break;
	case 2:
		ConvTypeHotel = "4*";
		break;
	case 3:
		ConvTypeHotel = "5*";
		break;
	}
	string SecondName = inRequestClient[i].SecondName;
	string login = inRequestClient[i].login;
	string Name = inRequestClient[i].Name;
	int num = inRequestClient[i].num;
	int hotel = inRequestClient[i].hotel;
	int Time = inRequestClient[i].time;
	Client d;
	while (!end) {
		system("cls");
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << "                                      ";
		cout << "Подтвердите заселение" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "                        "; cout << setw(5) << "Номер"; cout << setw(6) << "Отель"; cout << setw(11) << "Логин"; cout << setw(11) << "Фамилия"; cout << setw(11) << "Имя"; cout << endl;
		cout << "                        "; cout << setw(5) << num; cout << setw(6) << hotel; cout << setw(11) << fixString(login, 10); cout << setw(11) << fixString(SecondName, 10); cout << setw(11) << fixString(Name, 10);
		cout << endl;
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		cout << "\n";
		cout << "                           "; PrintWithCursorU(pos2Cursor, L"╔════════╗", 0, 10); cout << "                       "; PrintWithCursorU(pos2Cursor, L"╔════════╗", 1, 10); cout << "\n";
		cout << "                           "; PrintWithCursorU(pos2Cursor, L"║   Да   ║", 0, 10); cout << "                       "; PrintWithCursorU(pos2Cursor, L"║  Нет   ║", 1, 10); cout << "\n";
		cout << "                           "; PrintWithCursorU(pos2Cursor, L"╚════════╝", 0, 10); cout << "                       "; PrintWithCursorU(pos2Cursor, L"╚════════╝", 1, 10); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int counter = -1;
		int counterRoom = -1;
		switch (pos2Cursor)
		{
		case 0:
			readClient();
			readRoom();
			for (const auto& j : regisClient) {
				counter++;
				if (j.Login == login) {
					writeClientRoom(counter, num, hotel, Time);
				}
			}
			switch (inRequestClient[i].hotel)
			{
			case 1:
				for (const auto& j : inRoom3) {
					counterRoom++;
					if (j.Num == inRequestClient[i].num) {
						inRoom3[counterRoom].Status = 1;
						break;
					}
				}
				break;
			case 2:
				for (const auto& j : inRoom4) {
					counterRoom++;
					if (j.Num == inRequestClient[i].num) {
						inRoom4[counterRoom].Status = 1;
						break;
					}
				}
				break;
			case 3:
				for (const auto& j : inRoom5) {
					counterRoom++;
					if (j.Num == inRequestClient[i].num) {
						inRoom5[counterRoom].Status = 1;
						break;
					}
				}
				break;
			}
			system("cls");
			readRequestClient();
			writeRequestClient(i);
			SetConsoleTextAttribute(hConsole, colorCorrect);
			count = -1;
			end2 = 0;
			for (int j = 0; j < inRequestClient.size()+1; j++) {
				count = -1;
				for (const auto& i : inRequestClient) {
					count++;
					if (i.login == login) {
						readRequestClient();
						writeRequestClient(count);
						break;
					}
				}
			}

			cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
			cout << "            "; cout << "            ";
			cout << "Запрос принят" << endl;
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			Sleep(1500);
			writeRoom();
			lookRequestClient();
			break;
		case 1:
			readRequestClient();
			end = 1;
			system("cls");
			readClient();
			writeRequestClient(i);
			SetConsoleTextAttribute(hConsole, colorUnCorrect);
			cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
			cout << "            "; cout << "            ";
			cout << "Запрос отклонен" << endl;
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			Sleep(1500);
			lookRequestClient();
			break;
		}
		if (end == 0) {
			pos2Cursor = moveCursorW(size2menu, pos2Cursor);
			if (pos2Cursor >= 100) {
				end = 1;
				lookRequestClient();
			}
		}
	}
}
void lookRequestClient() {
	readRequestClient();
	int posCursor = 30;
	int pos2Cursor = 30;
	bool end = 0;
	bool flag = 0;
	int temp = 0;
	string ConvTypeHotel;
	string login;
	string SecondName;
	string Name;
	if (countRequestClient == -1) {
		flag = 1;
	}
	int sizeMenu = countRequestClient + 1;
	if (!flag) {
		while (!end) {
			readRequestClient();
			int counter = -1;
			system("cls");
			cout << setw(7) << "Номер";
			cout << setw(6) << "Отель";
			cout << setw(11) << "Логин";
			cout << setw(11) << "Фамилия";
			cout << setw(11) << "Имя";
			cout << setw(6) << "Время";
			cout << "\n";
			SetConsoleOutputCP(CP_UTF8);
			SetConsoleCP(CP_UTF8);
			setlocale(LC_ALL, "en_US.UTF-8");
			wcout << L"────────────────────────────────────────────────────────────────────────────────────────────────────" << "\n";
			setlocale(LC_ALL, "Rus");
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (const auto& i : inRequestClient) {
				switch (i.hotel)
				{
				case 1:
					ConvTypeHotel = "3*";
					break;
				case 2:
					ConvTypeHotel = "4*";
					break;
				case 3:
					ConvTypeHotel = "5*";
					break;
				}
				counter++;
				PrintWithCursor(posCursor, to_string(counter + 1), counter, 2);
				PrintWithCursor(posCursor, to_string(i.num), -1, 5);
				PrintWithCursor(posCursor, fixString(ConvTypeHotel, 5), -1, 6);
				PrintWithCursor(posCursor, fixString(i.login, 10), -1, 11);
				PrintWithCursor(posCursor, fixString(i.SecondName, 10), -1, 11);
				PrintWithCursor(posCursor, fixString(i.Name, 10), -1, 11);
				PrintWithCursor(posCursor, to_string(i.time), -1, 6);
				cout << endl;
			}

			if (posCursor < sizeMenu) {
				okRequestClient(posCursor);
			}
			if (end == 0) {
				posCursor = moveCursor(sizeMenu, posCursor);
				if (posCursor == 100) {
					end = 1;
					workMeneger();
				}
			}
		}
	}
	else {
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "                                     ";
		PrintWait("В данный момент нет заявок", 20);
		Sleep(1000);
		workMeneger();
	}
}

void banClient() {
	readClient();
	readRoom();
	int sizeSecondName = 10;
	int sizeName = 10;
	int sizeNum = 6;
	int sizeHotel = 6;
	int sizeTime = 6;
	bool flag = 0;
	int posCursor = 30;
	bool end = 0;
	for (const auto& i : regisClient) {
		if (i.Room != 0 && i.Hotel != 0) {
			flag = 1;
		}
	}
	string ConvHotel;
	int counter = -1;
	if (flag == 1) {
		while (!end) {
			system("cls");
			counter = -1;
			for (const auto& i : regisClient) {
				if (i.Room != 0 && i.Hotel != 0) {
					counter++;
				}
			}
			if (counter != -1) {
				PrintWithCursor(1, "Фамилия", -2, sizeSecondName + 10);
				PrintWithCursor(1, "Имя", -2, sizeName);
				PrintWithCursor(1, "Номер", -2, sizeNum);
				PrintWithCursor(1, "Отель", -2, sizeHotel);
				PrintWithCursor(1, "Время", -2, sizeTime);
				cout << "\n";
				SetConsoleOutputCP(CP_UTF8);
				SetConsoleCP(CP_UTF8);
				setlocale(LC_ALL, "en_US.UTF-8");
				wcout << L"────────────────────────────────────────────────────────────────────────────────────────────────────" << "\n";
				setlocale(LC_ALL, "Rus");
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);
				int countstr = -1;
				for (const auto& i : regisClient) {
					if (i.Room != 0 && i.Hotel != 0) {
						switch (i.Hotel)
						{
						case 0:
							ConvHotel = "No";
							break;
						case 1:
							ConvHotel = "3*";
							break;
						case 2:
							ConvHotel = "4*";
							break;
						case 3:
							ConvHotel = "5*";
							break;
						}
						countstr++;
						PrintWithCursor(posCursor, "Выселить", countstr, 10);
						PrintWithCursor(posCursor, fixString(i.SecondName, sizeSecondName), -1, sizeSecondName);
						PrintWithCursor(posCursor, fixString(i.Name, sizeName), -1, sizeName);
						PrintWithCursor(posCursor, to_string(i.Room), -1, sizeNum);
						PrintWithCursor(posCursor, ConvHotel, -1, sizeHotel);
						PrintWithCursor(posCursor, to_string(i.Time), -1, sizeTime);
						cout << "\n";
					}
				}
				if (posCursor < 30) {
					cout << "\n";
					int pos = -1;
					int pos2 = -1;
					int temp;
					for (const auto& i : regisClient) {
						pos++;
						if (i.Room != 0) {
							pos2++;
							if (pos2 == posCursor) {
								temp = pos;
								break;
							}
						}
					}
					cout << "Подтвердите выселение " << regisClient[temp].SecondName << " " << regisClient[temp].Name << "\n";
					int ch = _getch();
					if (ch == 13) {
						readClient();
						writeClientRoom(temp, 0, 0, 0);
						counter = -1;
						switch (regisClient[temp].Hotel)
						{
						case 1:
							for (const auto& i : inRoom3) {
								counter++;
								if (i.Num == regisClient[temp].Room) {
									inRoom3[counter].Status = 0;
									break;
								}
							}
							break;
						case 2:
							for (const auto& i : inRoom4) {
								counter++;
								if (i.Num == regisClient[temp].Room) {
									inRoom4[counter].Status = 0;
									break;
								}
							}
							break;
						case 3:
							for (const auto& i : inRoom3) {
								counter++;
								if (i.Num == regisClient[temp].Room) {
									inRoom5[counter].Status = 0;
									break;
								}
							}
							break;
						}
						system("cls");
						Sleep(1000);
						end = 1;
						banClient();
						break;
					}
					else {
						system("cls");
						end = 1;
						banClient();
						break;
					}
				}
				if (end == 0) {
					posCursor = moveCursor(counter + 1, posCursor);
					if (posCursor == 100){ workMeneger(); end = 1; break; }
				}
			}
			else { workMeneger(); end = 1; break; }
		}
	}
	else {
		system("cls");
		cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";
		cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";cout << "\n";
		cout << "                             ";
		PrintWait("В данный момент нет заселившихся клиентов", 20);
		Sleep(1000);
		workMeneger();
	}
}

//--------------------------------Админ

void editClient() {
	readClient();
	int sizeSecondName = 12;
	int sizeLogin = 10;
	int sizeName = 10;
	int sizeAge = 5;
	int sizeCountry = 15;
	int sizePassword = 10;
	int sizeFamily = 5;
	bool end = 0;
	int code;
	bool flag = 0;
	string password;
	string Login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	int family;
	int temp;
	if (countClient == -1) {
		flag = 1;
	}
	int posCursorHight = 30;
	int posCursorWidth = 30;
	int sizeMenuHight = countClient + 1;
	int sizeMenuWidth = 7;
	if (!flag) {
		while (!end) {
			system("cls");
			cout << setw(sizeLogin) << "Логин"; cout << " ";
			cout << setw(sizePassword) << "Пароль"; cout << " ";
			cout << setw(sizeSecondName) << "Фамилия"; cout << " ";
			cout << setw(sizeName) << "Имя"; cout << " ";
			cout << setw(sizeAge) << "лет"; cout << " ";
			cout << setw(sizeCountry) << "Страна"; cout << " ";
			cout << setw(sizeFamily) << "Семья";
			cout << "\n";
			SetConsoleOutputCP(CP_UTF8);
			SetConsoleCP(CP_UTF8);
			setlocale(LC_ALL, "en_US.UTF-8");
			wcout << L"────────────────────────────────────────────────────────────────────────────────────────────────────" << "\n";
			setlocale(LC_ALL, "Rus");
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (int i = 0; i < sizeMenuHight; i++) {
				if (posCursorHight - 30 == i) {
					PrintWithCursor(posCursorWidth, fixString(regisClient[i].Login, sizeLogin), 0, sizeLogin); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(regisClient[i].password, sizePassword), 1, sizePassword); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(regisClient[i].SecondName, sizeSecondName), 2, sizeSecondName); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(regisClient[i].Name, sizeName), 3, sizeName); cout << " ";
					PrintWithCursor(posCursorWidth, to_string(regisClient[i].Age), 4, sizeAge); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(regisClient[i].Country, sizeCountry), 5, sizeCountry); cout << " ";
					PrintWithCursor(posCursorWidth, to_string(regisClient[i].family), 6, sizeFamily); cout << " ";
					PrintWithCursor(posCursorWidth, "Удалить", 7, 7); cout << " ";
					cout << "\n";
				}
				else {
					cout << setw(sizeLogin) << fixString(regisClient[i].Login, sizeLogin); cout << " ";
					cout << setw(sizePassword) << fixString(regisClient[i].password, sizePassword); cout << " ";
					cout << setw(sizeSecondName) << fixString(regisClient[i].SecondName, sizeSecondName); cout << " ";
					cout << setw(sizeName) << fixString(regisClient[i].Name, sizeName); cout << " ";
					cout << setw(sizeAge) << regisClient[i].Age; cout << " ";
					cout << setw(sizeCountry) << fixString(regisClient[i].Country, sizeCountry); cout << " ";
					cout << setw(sizeFamily) << regisClient[i].family; cout << " ";
					cout << setw(7) << "Удалить";
					cout << "\n";
				}
			}
			if (posCursorHight > 30 + sizeMenuHight || posCursorWidth > 30 + sizeMenuWidth) {
				posCursorHight = 30;
				posCursorWidth = 30;
			}
			if (posCursorHight < sizeMenuHight && posCursorWidth < sizeMenuWidth + 1) {
				string text;
				int num;
				int size;
				int ch;
				int counter = -1;
				bool end = 0;
				string age;
				bool agechech = 0;
				bool login2 = 0;
				bool log = 0;
				int temp = -1;
				bool Countrychech = 0;
				int family;
				string login;
				string password;
				string SecondName;
				string Name;
				string erCounrty = "Такой страны не существует!";
				string erLogin = "Этот логин уже занят!";
				string erAgeMany = "Вы уже мертвы!";
				string erAgeLow = "Возраст слишком мал!";
				login.clear();
				password.clear();
				SecondName.clear();
				Name.clear();
				age.clear();
				if (posCursorWidth == 7) {
					cout << "Подтвердите удаление\n";
					code = getch1();
					if (code == 13) {
						readClient();
						readRoom();
						cout << "Чтение" << endl;
						int counter = -1;
						if (regisClient[posCursorHight].Room != 0) {
							counter = -1;
							switch (regisClient[posCursorHight].Hotel)
							{
							case 1:
								for (const auto& i : inRoom3) {
									counter++;
									if (i.Num == regisClient[posCursorHight].Room) {
										inRoom3[counter].Status = 0;
										break;
									}
								}
								break;
							case 2:
								for (const auto& i : inRoom4) {
									counter++;
									if (i.Num == regisClient[posCursorHight].Room) {
										inRoom4[counter].Status = 0;
										break;
									}
								}
								break;
							case 3:
								for (const auto& i : inRoom3) {
									counter++;
									if (i.Num == regisClient[posCursorHight].Room) {
										inRoom5[counter].Status = 0;
										break;
									}
								}
								break;
							}
						}
						cout << "запись" << endl;
						writeRoom();
						writeClient(posCursorHight);
						system("cls");
						SetConsoleTextAttribute(hConsole, colorUnCorrect);
						cout << "Идёт процесс удаления" << endl;
						SetConsoleTextAttribute(hConsole, colorCorrect);
						Sleep(1500);
						cout << "Удаление завершено" << endl;
						SetConsoleTextAttribute(hConsole, colorSelect);
						Sleep(1500);
						editClient();
						break;
					}
					else {
						cout << "Удаление отменено" << endl;
						Sleep(1000);
						editMeneger();
					}
				}
				switch (posCursorWidth)
				{
				case 0:
					cout << "\n";
					cout << "Введите новый логин: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						login2 = 0;
						switch (ch)
						{
						case 27:
							editClient();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								login.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								readClient();
								readMeneger();
								size = login.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								for (const auto& i : regisClient) {
									if (login == i.Login) {
										SetConsoleTextAttribute(hConsole, colorUnCorrect);
										cout << login; cout << " ";
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										end = 0;
										PrintWait(erLogin, 15);
										Sleep(1000);
										CleanWait(erLogin.size() + 1 + size, 20);
										counter = -1;
										login.clear();
										login2 = 1;
										break;
									}
								}
								for (const auto& i : regisMeneger) {
									if (login == i.Login) {
										SetConsoleTextAttribute(hConsole, colorUnCorrect);
										cout << login; cout << " ";
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										end = 0;
										SetConsoleTextAttribute(hConsole, colorWarning);
										PrintWait(erLogin, 15);
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										Sleep(1000);
										login2 = 1;
										CleanWait(erLogin.size() + 1 + size, 20);
										login.clear();
										counter = -1;
										break;
									}
								}
								if (login2 == 0) {
									SetConsoleTextAttribute(hConsole, colorCorrect);
									cout << login;
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									end = 1;
								}
							}
							break;
						case 32:
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							break;
						}
					}
					regisClient[posCursorHight].Login = login;
					writeClient();
					editClient();
					break;
				case 1:
					cout << "\n";
					cout << "Введите новый пароль: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						switch (ch)
						{
						case 27:
							editClient();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								password.erase(counter);
								counter = counter - 1;
							}
							break;
						case 32:
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = password.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								SetConsoleTextAttribute(hConsole, colorCorrect);
								cout << password;
								SetConsoleTextAttribute(hConsole, colorUnSelect);
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							break;
						}
					}
					regisClient[posCursorHight].password = password;
					writeClient();
					editClient();
					break;
				case 2:
					cout << "\n";
					cout << "Введите новую фамилию: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editClient();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								SecondName.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = SecondName.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								SetConsoleTextAttribute(hConsole, colorCorrect);
								cout << SecondName;
								SetConsoleTextAttribute(hConsole, colorUnSelect);
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							break;
						}
					}
					regisClient[posCursorHight].SecondName = SecondName;
					writeClient();
					editClient();
					break;
				case 3:
					cout << "\n";
					cout << "Введите новое имя: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editClient();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								Name.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = Name.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								SetConsoleTextAttribute(hConsole, colorCorrect);
								cout << Name;
								SetConsoleTextAttribute(hConsole, colorUnSelect);
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							break;
						}
					}
					regisClient[posCursorHight].Name = Name;
					writeClient();
					editClient();
					break;
				case 4:
					cout << "\n";
					cout << "Введите новый возраст: ";
					end = 0;
					counter = -1;
					while (!end) {
						agechech = 0;
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editClient();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								age.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = age.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								Age = stoi(age);
								if (Age > 130) {
									SetConsoleTextAttribute(hConsole, colorUnCorrect);
									cout << Age; cout << " ";
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									SetConsoleTextAttribute(hConsole, colorWarning);
									PrintWait(erAgeMany, 20); Sleep(1000);
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									CleanWait(erAgeMany.size() + 1 + size, 20);
									counter = -1;
									age.erase();
									end = 0;
									agechech = 1;
								}
								if (Age < 14) {
									SetConsoleTextAttribute(hConsole, colorUnCorrect);
									cout << Age; cout << " ";
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									SetConsoleTextAttribute(hConsole, colorWarning);
									PrintWait(erAgeLow, 20); Sleep(1000);
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									CleanWait(erAgeLow.size() + 1 + size, 20);
									counter = -1;
									age.erase();
									end = 0;
									agechech = 1;
								}
								if (agechech == 0) {
									SetConsoleTextAttribute(hConsole, colorCorrect);
									cout << Age;
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									end = 1;
								}
							}
							break;
						default:
							if (ch > 47 && ch < 58) {
								cout << char(ch);
								age.push_back(char(ch));
								counter++;
							}
							else counter--;
							break;
						}
					}
					regisClient[posCursorHight].Age = Age;
					writeClient();
					editClient();
					break;
				case 5:
					cout << "\n";
					cout << "Введите новую страну: ";
					end = 0;
					counter = -1;
					while (!end) {
						Countrychech = 0;
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editClient();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								Country.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								readCountry();
								size = Country.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								for (const auto& i : inCountry) {
									if (Country == i.Country) {
										SetConsoleTextAttribute(hConsole, colorCorrect);
										cout << Country;
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										Countrychech = 1;
										end = 1;
									}
								}
								if (Countrychech == 0) {
									SetConsoleTextAttribute(hConsole, colorUnCorrect);
									cout << Country; cout << " ";
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									SetConsoleTextAttribute(hConsole, colorWarning);
									PrintWait(erCounrty, 20);
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									Sleep(1000);
									CleanWait(erCounrty.size() + 1 + size, 20);
									Country.clear();
									end = 0;
									counter = -1;
								}
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							break;
						}
					}
					regisClient[posCursorHight].Country = Country;
					writeClient();
					editClient();
					break;
				case 6:
					cout << "\n";
					cout << "Выберите новую семью: ";
					while (true) {
						char ch2 = _getch();
						if (isdigit(ch2)) {
							if (ch2 - '0' < 5) {
								family = ch2 - '0';
								break;
							}
						}
					}
					regisClient[posCursorHight].family = family;
					writeClient();
					editClient();
					break;
				}
			}
			if (end == 0) {
				int ch = _getch();
				if (ch == 119) {
					if (posCursorHight > 30) {
						posCursorHight--;
					}
					else if (posCursorHight == 30) {
						posCursorHight = sizeMenuHight + 30;
					}
				}
				else if (ch == 115) {
					if (posCursorHight - 30 < sizeMenuHight) {
						posCursorHight++;
					}
					else if (posCursorHight - 30 == sizeMenuHight) {
						posCursorHight = 30;
					}
				}
				else if (ch == 97) {
					if (posCursorWidth > 30) {
						posCursorWidth--;
					}
					else if (posCursorWidth == 30) {
						posCursorWidth = sizeMenuWidth + 30;
					}
				}
				else if (ch == 100) {
					if (posCursorWidth - 30 < sizeMenuWidth) {
						posCursorWidth++;
					}
					else if (posCursorWidth - 30 == sizeMenuWidth) {
						posCursorWidth = 30;
					}
				}
				else if (ch == 13) {
					posCursorHight = posCursorHight - 30;
					posCursorWidth = posCursorWidth - 30;
				}
				else if (ch == 27) {
					workAdmin();
					break;
				}
			}
		}
	}
}
void editMeneger() {
	SetConsoleTextAttribute(hConsole, colorUnSelect);
	readMeneger();
	int sizeSecondName = 10;
	int sizeLogin = 10;
	int sizeName = 10;
	int sizeAge = 4;
	int sizeCountry = 14;
	int sizeNumber = 10;
	int sizeAducation = 10;
	int sizePassword = 10;
	int sizeFamily = 5;
	bool end = 0;
	bool flag = 0;
	int code;
	string Login;
	string SecondName;
	string Name;
	int Age;
	string Country;
	string Number;
	int family;
	int Aducation;
	string password;
	int temp;
	if (countMeneger == -1) {
		flag = 1;
	}
	int posCursorHight = 30;
	int posCursorWidth = 30;
	int sizeMenuHight = countMeneger + 1;
	int sizeMenuWidth = 9;
	if (!flag) {
		while (!end) {
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			system("cls");
			cout << setw(sizeLogin) << "Логин"; cout << " ";
			cout << setw(sizePassword) << "Пароль"; cout << " ";
			cout << setw(sizeSecondName) << "Фамилия"; cout << " ";
			cout << setw(sizeName) << "Имя"; cout << " ";
			cout << setw(sizeAge) << "лет"; cout << " ";
			cout << setw(sizeCountry) << "Страна"; cout << " ";
			cout << setw(sizeNumber) << "Номер"; cout << " ";
			cout << setw(sizeAducation) << "Образование"; cout << " ";
			cout << setw(sizeFamily) << "Семья";
			cout << "\n";
			SetConsoleOutputCP(CP_UTF8);
			SetConsoleCP(CP_UTF8);
			setlocale(LC_ALL, "en_US.UTF-8");
			wcout << L"────────────────────────────────────────────────────────────────────────────────────────────────────" << "\n";
			setlocale(LC_ALL, "Rus");
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (int i = 0; i < sizeMenuHight; i++) {
				if (posCursorHight - 30 == i) {
					PrintWithCursor(posCursorWidth, fixString(inMeneger[i].Login, sizeLogin), 0, sizeLogin); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(inMeneger[i].password, sizePassword), 1, sizePassword); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(inMeneger[i].SecondName, sizeSecondName), 2, sizeSecondName); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(inMeneger[i].Name, sizeName), 3, sizeName); cout << " ";
					PrintWithCursor(posCursorWidth, to_string(inMeneger[i].Age), 4, sizeAge); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(inMeneger[i].Country, sizeCountry), 5, sizeCountry); cout << " ";
					PrintWithCursor(posCursorWidth, fixString(inMeneger[i].Number, sizeNumber), 6, sizeNumber); cout << " ";
					PrintWithCursor(posCursorWidth, to_string(inMeneger[i].Aducation), 7, sizeAducation); cout << " ";
					PrintWithCursor(posCursorWidth, to_string(inMeneger[i].family), 8, sizeFamily); cout << " ";
					PrintWithCursor(posCursorWidth, "Удалить", 9, 7); cout << " ";
					cout << "\n";
				}
				else {
					cout << setw(sizeLogin) << fixString(inMeneger[i].Login, sizeLogin); cout << " ";
					cout << setw(sizePassword) << fixString(inMeneger[i].password, sizePassword); cout << " ";
					cout << setw(sizeSecondName) << fixString(inMeneger[i].SecondName, sizeSecondName); cout << " ";
					cout << setw(sizeName) << fixString(inMeneger[i].Name, sizeName); cout << " ";
					cout << setw(sizeAge) << inMeneger[i].Age; cout << " ";
					cout << setw(sizeCountry) << fixString(inMeneger[i].Country, sizeCountry); cout << " ";
					cout << setw(sizeNumber) << fixString(inMeneger[i].Number, sizeNumber); cout << " ";
					cout << setw(sizeAducation) << "  "; cout << " ";
					cout << setw(sizeFamily) << inMeneger[i].family; cout << " ";
					cout << setw(7) << "Удалить"; cout << " ";
					cout << "\n";
				}
			}
			if (posCursorHight > 30 + sizeMenuHight || posCursorWidth > 30 + sizeMenuWidth) {
				posCursorHight = 30;
				posCursorWidth = 30;
			}
			if (posCursorHight < sizeMenuHight && posCursorWidth < sizeMenuWidth + 1) {
				string text;
				int num;
				int size;
				int ch;
				int counter = -1;
				bool end = 0;
				string age;
				bool agechech = 0;
				bool login2 = 0;
				bool log = 0;
				int temp = -1;
				bool Countrychech = 0;
				int family;
				int Aducation;
				string login;
				string password;
				string SecondName;
				string Name;
				string Number;
				string erCounrty = "Такой страны не существует!";
				string erLogin = "Этот логин уже занят!";
				string erAgeMany = "Вы уже мертвы!";
				string erAgeLow = "Возраст слишком мал!";
				login.clear();
				password.clear();
				SecondName.clear();
				Name.clear();
				age.clear();
				Number.clear();
				if (posCursorWidth == 9) {
					cout << "Подтвердите удаление\n";
					code = getch1();
					if (code == 13) {
						readMeneger();
						writeMeneger(posCursorHight);
						system("cls");
						SetConsoleTextAttribute(hConsole, colorUnCorrect);
						cout << "Идёт процесс удаления" << endl;
						SetConsoleTextAttribute(hConsole, colorCorrect);
						Sleep(1500);
						cout << "Удаление завершено" << endl;
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						Sleep(1500);
						editMeneger();
						break;
					}
				}
				switch (posCursorWidth)
				{
				case 0:
					cout << endl;
					cout << "Введите новый логин: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						login2 = 0;
						switch (ch)
						{
						case 27:
							editMeneger();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								login.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								readClient();
								readMeneger();
								size = login.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								for (const auto& i : regisClient) {
									if (login == i.Login) {
										SetConsoleTextAttribute(hConsole, colorUnCorrect);
										cout << login; cout << " ";
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										end = 0;
										PrintWait(erLogin, 15);
										Sleep(1000);
										CleanWait(erLogin.size() + 1 + size, 20);
										counter = -1;
										login.clear();
										login2 = 1;
										break;
									}
								}
								for (const auto& i : inMeneger) {
									if (login == i.Login) {
										SetConsoleTextAttribute(hConsole, colorUnCorrect);
										cout << login; cout << " ";
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										end = 0;
										SetConsoleTextAttribute(hConsole, colorWarning);
										PrintWait(erLogin, 15);
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										Sleep(1000);
										login2 = 1;
										CleanWait(erLogin.size() + 1 + size, 20);
										login.clear();
										counter = -1;
										break;
									}
								}
								if (login2 == 0) {
									SetConsoleTextAttribute(hConsole, colorCorrect);
									cout << login;
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									end = 1;
								}
							}
							break;
						case 32:
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								login.push_back(char(ch));
							}
							break;
						}
					}
					inMeneger[posCursorHight].Login = login;
					writeMeneger();
					editMeneger();
					break;
				case 1:
					cout << endl;
					cout << "Введите новый пароль: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editMeneger();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								password.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = password.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								SetConsoleTextAttribute(hConsole, colorCorrect);
								cout << password;
								SetConsoleTextAttribute(hConsole, colorUnSelect);
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								password.push_back(char(ch));
							}
							break;
						}
					}
					inMeneger[posCursorHight].password = password;
					writeMeneger();
					editMeneger();
					break;
				case 2:
					cout << endl;
					cout << "Введите новую фамилию: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editMeneger();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								SecondName.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = SecondName.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								SetConsoleTextAttribute(hConsole, colorCorrect);
								cout << SecondName;
								SetConsoleTextAttribute(hConsole, colorUnSelect);
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								SecondName.push_back(char(ch));
							}
							break;
						}
					}
					inMeneger[posCursorHight].SecondName = SecondName;
					writeMeneger();
					editMeneger();
					break;
				case 3:
					cout << endl;
					cout << "Введите новое имя: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editMeneger();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								Name.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = Name.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								SetConsoleTextAttribute(hConsole, colorCorrect);
								cout << Name;
								SetConsoleTextAttribute(hConsole, colorUnSelect);
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								Name.push_back(char(ch));
							}
							break;
						}
					}
					inMeneger[posCursorHight].Name = Name;
					writeMeneger();
					editMeneger();
					break;
				case 4:
					cout << endl;
					cout << "Введите новый возраст: ";
					end = 0;
					counter = -1;
					while (!end) {
						agechech = 0;
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editMeneger();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								age.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = age.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								Age = stoi(age);
								if (Age > 130) {
									SetConsoleTextAttribute(hConsole, colorUnCorrect);
									cout << Age; cout << " ";
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									SetConsoleTextAttribute(hConsole, colorWarning);
									PrintWait(erAgeMany, 20); Sleep(1000);
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									CleanWait(erAgeMany.size() + 1 + size, 20);
									counter = -1;
									age.erase();
									end = 0;
									agechech = 1;
								}
								if (Age < 14) {
									SetConsoleTextAttribute(hConsole, colorUnCorrect);
									cout << Age; cout << " ";
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									SetConsoleTextAttribute(hConsole, colorWarning);
									PrintWait(erAgeLow, 20); Sleep(1000);
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									CleanWait(erAgeLow.size() + 1 + size, 20);
									counter = -1;
									age.erase();
									end = 0;
									agechech = 1;
								}
								if (agechech == 0) {
									SetConsoleTextAttribute(hConsole, colorCorrect);
									cout << Age;
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									end = 1;
								}
							}
							break;
						default:
							if (ch > 47 && ch < 58) {
								cout << char(ch);
								if (char(ch) != ' ') {
									age.push_back(char(ch));
									counter++;
								}
							}
							break;
						}
					}
					inMeneger[posCursorHight].Age = Age;
					writeMeneger();
					editMeneger();
					break;
				case 5:
					cout << endl;
					cout << "Введите новую страну: ";
					end = 0;
					counter = -1;
					while (!end) {
						Countrychech = 0;
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editMeneger();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								Country.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								readCountry();
								size = Country.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								for (const auto& i : inCountry) {
									if (Country == i.Country) {
										SetConsoleTextAttribute(hConsole, colorCorrect);
										cout << Country;
										SetConsoleTextAttribute(hConsole, colorUnSelect);
										Countrychech = 1;
										end = 1;
									}
								}
								if (Countrychech == 0) {
									SetConsoleTextAttribute(hConsole, colorUnCorrect);
									cout << Country; cout << " ";
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									SetConsoleTextAttribute(hConsole, colorWarning);
									PrintWait(erCounrty, 20);
									SetConsoleTextAttribute(hConsole, colorUnSelect);
									Sleep(1000);
									CleanWait(erCounrty.size() + 1 + size, 20);
									Country.clear();
									end = 0;
									counter = -1;
								}
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								Country.push_back(char(ch));
							}
							break;
						}
					}
					inMeneger[posCursorHight].Country = Country;
					writeMeneger();
					editMeneger();
					break;
				case 6:
					cout << endl;
					cout << "Введите новый номер: ";
					end = 0;
					counter = -1;
					while (!end) {
						ch = _getch();
						switch (ch)
						{
						case 32:
							break;
						case 27:
							editMeneger();
							break;
						case 8:
							if (counter > -1) {
								cout << char(ch) << " " << char(ch);
								Number.erase(counter);
								counter = counter - 1;
							}
							break;
						case 13:
							if (counter > -1) {
								end = 1;
								size = Number.size();
								for (int i = 0; i < size; i++) {
									cout << char(8) << " " << char(8);
								}
								SetConsoleTextAttribute(hConsole, colorCorrect);
								cout << Number;
								SetConsoleTextAttribute(hConsole, colorUnSelect);
							}
							break;
						default:
							if (ch == 95 || ch == 45 || ch == 46) {
								counter++;
								cout << char(ch);
								Number.push_back(char(ch));
							}
							if (ch >= 97 && ch <= 122) {
								counter++;
								cout << char(ch);
								Number.push_back(char(ch));
							}
							if (ch >= 48 && ch <= 57) {
								counter++;
								cout << char(ch);
								Number.push_back(char(ch));
							}
							if (ch >= 65 && ch <= 90) {
								counter++;
								cout << char(ch);
								Number.push_back(char(ch));
							}
							if (ch >= -128 && ch <= -17) {
								counter++;
								cout << char(ch);
								Number.push_back(char(ch));
							}
							break;
						}
					}
					inMeneger[posCursorHight].Number = Number;
					writeMeneger();
					editMeneger();
					break;
				case 7:
					cout << endl;
					cout << "Выберите новое образование: ";
					while (true) {
						char ch2 = _getch();
						if (isdigit(ch2)) {
							if (ch2 - '0' < 5) {
								Aducation = ch2 - '0';
								break;
							}
						}
					}
					inMeneger[posCursorHight].Aducation = Aducation;
					writeMeneger();
					editMeneger();
					break;
				case 8:
					cout << endl;
					cout << "Выберите новую семью: ";
					while (true) {
						char ch2 = _getch();
						if (isdigit(ch2)) {
							if (ch2 - '0' < 5) {
								family = ch2 - '0';
								break;
							}
						}
					}
					inMeneger[posCursorHight].family = family;
					writeMeneger();
					editMeneger();
					break;
				case 10:
					workAdmin();
					break;
				}
			}
			if (end == 0) {
				int ch = _getch();
				if (ch == 119) {
					if (posCursorHight > 30) {
						posCursorHight--;
					}
					else if (posCursorHight == 30) {
						posCursorHight = sizeMenuHight + 30;
					}
				}
				else if (ch == 115) {
					if (posCursorHight - 30 < sizeMenuHight) {
						posCursorHight++;
					}
					else if (posCursorHight - 30 == sizeMenuHight) {
						posCursorHight = 30;
					}
				}
				else if (ch == 97) {
					if (posCursorWidth > 30) {
						posCursorWidth--;
					}
					else if (posCursorWidth == 30) {
						posCursorWidth = sizeMenuWidth + 30;
					}
				}
				else if (ch == 100) {
					if (posCursorWidth - 30 < sizeMenuWidth) {
						posCursorWidth++;
					}
					else if (posCursorWidth - 30 == sizeMenuWidth) {
						posCursorWidth = 30;
					}
				}
				else if (ch == 13) {
					posCursorHight = posCursorHight - 30;
					posCursorWidth = posCursorWidth - 30;
				}
				else if (ch == 27) {
					workAdmin();
					break;
				}
			}
		}
	}
}
void findMeneger(int i) {
	int pos2Cursor = 30;
	int size2menu = 2;
	bool end = 0;
	string SecondName = regisMeneger[i].SecondName;
	string login = regisMeneger[i].Login;
	string Name = regisMeneger[i].Name;
	string Country = regisMeneger[i].Country;
	string password = regisMeneger[i].password;
	int Age = regisMeneger[i].Age;
	int family = regisMeneger[i].family;
	int Aducation = regisMeneger[i].Aducation;
	string Number = regisMeneger[i].Number;
	Meneger d;
	while (!end) {
		system("cls");
		cout << "\n";
		cout << "Вы заинтересованы данным кандидатом?" << endl;
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << setw(31) << "Фамилия";
		cout << setw(10) << "Имя";
		cout << setw(5) << "Лет";
		cout << setw(15) << "Страна";
		cout << setw(13) << "Образование\n";
		cout << "\n";
		PrintFromRegMeneger(i, 31, 10, 5, 15);
		cout << endl;
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		cout << "\n";
		cout << "                           "; PrintWithCursorU(pos2Cursor, L"╔════════╗", 0, 10); cout << "                       "; PrintWithCursorU(pos2Cursor, L"╔════════╗", 1, 10); cout << "\n";
		cout << "                           "; PrintWithCursorU(pos2Cursor, L"║   Да   ║", 0, 10); cout << "                       "; PrintWithCursorU(pos2Cursor, L"║  Нет   ║", 1, 10); cout << "\n";
		cout << "                           "; PrintWithCursorU(pos2Cursor, L"╚════════╝", 0, 10); cout << "                       "; PrintWithCursorU(pos2Cursor, L"╚════════╝", 1, 10); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		switch (pos2Cursor)
		{
		case 0:
			readRegMeneger();
			writeRegMeneger(i);
			readMeneger();
			d.setAll(login, SecondName, Name, Age, Country, Number, family, Aducation, password);
			inMeneger.push_back(d);
			writeMeneger();
			system("cls");
			cout << "Заявка принята" << endl;
			Sleep(1500);
			lookRequestMeneger();
			break;
		case 1:
			end = 1;
			readRegMeneger();
			writeRegMeneger(i);
			system("cls");
			cout << "Заявка отклонена" << endl;
			Sleep(1500);
			lookRequestMeneger();
			break;
		}
		if (end == 0) {
			pos2Cursor = moveCursorW(size2menu, pos2Cursor);
			if (pos2Cursor == 100) {
				end = 1;
				lookRequestMeneger();
				break;
			}
		}
	}
}
void lookRequestMeneger() {
	readRegMeneger();
	int posCursor = 30;
	int pos2Cursor = 30;
	int size2menu = 2;
	bool end = 0;
	bool flag = 0;
	int temp = 0;
	if (countWaitingMeneger == -1) {
		flag = 1;
	}
	int sizeMenu = countWaitingMeneger + 1;
	if (!flag) {
		while (!end) {
			system("cls");
			cout << setw(12) << "Фамилия";
			cout << setw(10) << "Имя";
			cout << setw(5) << "лет";
			cout << setw(15) << "Страна";
			cout << setw(15) << "Образование";
			cout << "\n";
			SetConsoleOutputCP(CP_UTF8);
			SetConsoleCP(CP_UTF8);
			setlocale(LC_ALL, "en_US.UTF-8");
			wcout << L"────────────────────────────────────────────────────────────────────────────────────────────────────" << "\n";
			setlocale(LC_ALL, "Rus");
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			for (int i = 0; i < sizeMenu; i++) {
				PrintWithCursor(posCursor, to_string(i + 1), i, 2);
				PrintFromRegMeneger(i, 10, 10, 5, 15);
				cout << "\n";
			}
			if (posCursor < sizeMenu) {
				findMeneger(posCursor);
			}
			if (end == 0) {
				posCursor = moveCursor(sizeMenu, posCursor);
				if (posCursor == 100) {
					end = 1;
					workAdmin();
					break;
				}
			}
		}
	}
	else {
		cout << "В данный момент нет заявок" << endl;
		Sleep(1500);
		workAdmin();
	}
}

void addRoom() {
	int posCursor = 30;
	int sizeMenu = 5;
	bool end = 0;
	int Class = 0;
	int Config = 0;
	int Look = 0;
	int Size = 0;
	int Cost = 0;
	int Status = 0;
	int Hotel = 0;
	int ch;
	string age;
	while (!end) {
		system("cls");
		cout << "\n";
		cout << "                                         Выберите класс номера\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Econom       ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║      Standart      ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        Delux       ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 2, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 3, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         Lux        ║", 3, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 3, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 4, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Pr.Lux       ║", 4, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 4, 62); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		switch (posCursor)
		{
		case 0:
			end = 1;
			Class = 1;
			break;
		case 1:
			end = 1;
			Class = 2;
			break;
		case 2:
			end = 1;
			Class = 3;
			break;
		case 3:
			end = 1;
			Class = 4;
			break;
		case 4:
			end = 1;
			Class = 5;
			break;
		}
		if (end == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { end = 1; Rooms(); }
	}
	posCursor = 30;
	sizeMenu = 5;
	end = 0;
	while (!end) {
		system("cls");
		cout << "\n";
		cout << "                                         Выберите конфиг номера\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        SNGL        ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         DBL        ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        TWIN        ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 2, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 3, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        TRPL        ║", 3, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 3, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 4, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        QDPL        ║", 4, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 4, 62); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		switch (posCursor)
		{
		case 0:
			end = 1;
			Config = 1;
			break;
		case 1:
			end = 1;
			Config = 2;
			break;
		case 2:
			end = 1;
			Config = 3;
			break;
		case 3:
			end = 1;
			Config = 4;
			break;
		case 4:
			end = 1;
			Config = 5;
			break;
		}
		if (end == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { end = 1; Rooms(); }
	}
	posCursor = 30;
	end = 0;
	sizeMenu = 3;
	while (!end) {
		system("cls");
		cout << "\n";
		cout << "                                         Выберите вид из окна\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        Двор        ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        Город       ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        Река        ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 2, 62); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		switch (posCursor)
		{
		case 0:
			end = 1;
			Look = 1;
			break;
		case 1:
			end = 1;
			Look = 2;
			break;
		case 2:
			end = 1;
			Look = 3;
			break;
		}
		if (end == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { end = 1; Rooms(); }
	}
	end = 0;
	int counter = -1;
	int size;
	system("cls");
		cout << "\n";
		cout << "                                         Введите площадь комнаты\n";
		cout << "\n"; cout << "\n"; cout << "\n";
		cout << "\n"; cout << "\n"; cout << "\n";
		cout << "\n"; cout << "\n"; cout << "\n";
		cout << "                              Площадь:                             ";
		age.clear();
		while (!end)
		{
		ch = _getch();
		switch (ch)
		{
		case 32:
			break;
		case 27:
			Rooms();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				age.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			if (counter > -1) {
				size = age.size();
				for (int i = 0; i < size; i++) {
					cout << char(8) << " " << char(8);
				}
				Size = stoi(age);

				
				cout << Size << "";
				
				end = 1;
			}
			break;
		default:
			if (ch > 47 && ch < 58) {
				SetConsoleTextAttribute(hConsole, colorTime);
				cout << char(ch);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				age.push_back(char(ch));
				counter++;
			}
			else counter--;
			break;
		}
	    }
		end = 0;
		counter = -1;

		system("cls");
		cout << "\n";
		cout << "                                         Введите цену комнаты\n";
		cout << "\n"; cout << "\n"; cout << "\n";
		cout << "\n"; cout << "\n"; cout << "\n";
		cout << "\n"; cout << "\n"; cout << "\n";
		cout << "                                 Цена:                             ";
		age.clear();
		while (!end)
		{
			ch = _getch();
			switch (ch)
			{
			case 32:
				break;
			case 27:
				Rooms();
				break;
			case 8:
				if (counter > -1) {
					cout << char(ch) << " " << char(ch);
					age.erase(counter);
					counter = counter - 1;
				}
				break;
			case 13:
				if (counter > -1) {
					size = age.size();
					for (int i = 0; i < size; i++) {
						cout << char(8) << " " << char(8);
					}
					Cost = stoi(age);


					cout << Cost << "";

					end = 1;
				}
				break;
			default:
				if (ch > 47 && ch < 58) {
					SetConsoleTextAttribute(hConsole, colorTime);
					cout << char(ch);
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					age.push_back(char(ch));
					counter++;
				}
				else counter--;
				break;
			}
		}
	posCursor = 30;
	end = 0;
	sizeMenu = 3;
	while (!end) {
		system("cls");
		cout << "\n";
		cout << "                                         Выберите тип отеля\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         3*         ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         4*         ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         5*         ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 2, 62); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		switch (posCursor)
		{
		case 0:
			end = 1;
			Hotel = 1;
			break;
		case 1:
			end = 1;
			Hotel = 2;
			break;
		case 2:
			end = 1;
			Hotel = 3;
			break;
		}
		if (end == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { end = 1; Rooms(); }
	}
	system("cls");
	readRoom();
	int num;
	switch (Hotel)
	{
	case 1:
		for (const auto& i : inRoom3) {
			num = i.Num;
		}
		num++;
		Room3 d;
		d.setAll(num, Class, Config, Look, Size, Cost, Status);
		inRoom3.push_back(d);
		writeRoom();
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << "                                      ";
		SetConsoleTextAttribute(hConsole, colorCorrect);
		PrintWait("Комната успешно создана", 20);
		SetConsoleTextAttribute(hConsole, colorUnSelect);
		Sleep(1000);
		Rooms();
		break;
	case 2:
		for (const auto& i : inRoom4) {
			num = i.Num;
		}
		num++;
		Room4 q;
		q.setAll(num, Class, Config, Look, Size, Cost, Status);
		inRoom4.push_back(q);
		writeRoom();
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << "                                       ";
		SetConsoleTextAttribute(hConsole, colorCorrect);
		PrintWait("Комната успешно создана", 20);
		SetConsoleTextAttribute(hConsole, colorUnSelect);
		Sleep(1000);
		Rooms();
		break;
	case 3:
		for (const auto& i : inRoom5) {
			num = i.Num;
		}
		num++;
		Room5 r;
		r.setAll(num, Class, Config, Look, Size, Cost, Status);
		inRoom5.push_back(r);
		writeRoom();
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n"; cout << "\n";
		cout << "                                      ";
		SetConsoleTextAttribute(hConsole, colorCorrect);
		PrintWait("Комната успешно создана", 20);
		SetConsoleTextAttribute(hConsole, colorUnSelect);
		Sleep(1000);
		Rooms();
		break;
	}
}
void delRoom() {
	readRoom();
	readClient();
	readRequestClient();
	int Hotel = 0;
	int num;
	int posCursor = 30;
	int sizeMenu = 3;
	bool end = 0;
	int counter = -1;
	cout << "\n"; cout << "\n"; cout << "\n";
	cout << "\n"; cout << "\n"; cout << "\n";
	cout << "\n"; cout << "\n"; cout << "\n";
	cout << "Введите номер комнаты для удаления:     ";
	cin >> num;
	bool flagleave = 0;
	bool flagroom = 0;
	while (!end) {
		system("cls");
		cout << "\n";
		cout << "                                         Выберите тип отеля\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         3*         ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         4*         ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║         5*         ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 2, 62); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		switch (posCursor)
		{
		case 0:
			end = 1;
			Hotel = 1;
			break;
		case 1:
			end = 1;
			Hotel = 2;
			break;
		case 2:
			end = 1;
			Hotel = 3;
			break;
		}
		if (end == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { end = 1; Rooms(); }
	}
	switch (Hotel) {
	case 1:
		for (const auto& i : inRoom3) {
			if (num == i.Num) {
				flagroom = 1;
				if(i.Status == 1){
					flagleave = 1;
				}
				break;
			}
		}
		if (flagroom == 1) {
			if (flagleave == 0) {
				writeRoom(num, Hotel);
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "                              ";
				SetConsoleTextAttribute(hConsole, colorCorrect);
				PrintWait("Комната удалена", 20);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				Sleep(1000);
			}
			else {
				counter = -1;
				for (const auto& i : regisClient) {
					counter++;
					if (i.Room == num && i.Hotel == Hotel) {
						regisClient[counter].Room = 0;
						regisClient[counter].Hotel = 0;
						regisClient[counter].Time = 0;
						break;
					}
				}
				counter = -1;
				for (const auto& i : inRequestClient) {
					counter++;
					if (i.num == num && i.hotel == Hotel) {
						writeRequestClient(counter);
						break;
					}
				}
				writeClient();
				writeRoom(num, Hotel);
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "                              ";
				SetConsoleTextAttribute(hConsole, colorCorrect);
				PrintWait("Комната удалена", 20);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				Sleep(1000);
			}
		}
		else {
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "                              ";
			SetConsoleTextAttribute(hConsole, colorUnCorrect);
			PrintWait("Комната не существует", 20);
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			Sleep(1000);
			Rooms();
		}
		break;
	case 2:
		for (const auto& i : inRoom4) {
			if (num == i.Num) {
				flagroom = 1;
				if (i.Status == 1) {
					flagleave = 1;
				}
				break;
			}
		}
		if (flagroom == 1) {
			if (flagleave == 0) {
				writeRoom(num, Hotel);
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "                              ";
				SetConsoleTextAttribute(hConsole, colorCorrect);
				PrintWait("Комната удалена", 20);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				Sleep(1000);
			}
			else {
				counter = -1;
				for (const auto& i : regisClient) {
					counter++;
					if (i.Room == num && i.Hotel == Hotel) {
						regisClient[counter].Room = 0;
						regisClient[counter].Hotel = 0;
						regisClient[counter].Time = 0;
						break;
					}
				}
				counter = -1;
				for (const auto& i : inRequestClient) {
					counter++;
					if (i.num == num && i.hotel == Hotel) {
						writeRequestClient(counter);
						break;
					}
				}
				writeClient();
				writeRoom(num, Hotel);
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "                              ";
				SetConsoleTextAttribute(hConsole, colorCorrect);
				PrintWait("Комната удалена", 20);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				Sleep(1000);
			}
		}
		else {
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "                              ";
			SetConsoleTextAttribute(hConsole, colorUnCorrect);
			PrintWait("Комната не существует", 20);
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			Sleep(1000);
			Rooms();
		}
		break;
	case 3:
		for (const auto& i : inRoom5) {
			if (num == i.Num) {
				flagroom = 1;
				if (i.Status == 1) {
					flagleave = 1;
				}
				break;
			}
		}
		if (flagroom == 1) {
			if (flagleave == 0) {
				writeRoom(num, Hotel);
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "                              ";
				SetConsoleTextAttribute(hConsole, colorCorrect);
				PrintWait("Комната удалена", 20);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				Sleep(1000);
			}
			else {
				counter = -1;
				for (const auto& i : regisClient) {
					counter++;
					if (i.Room == num && i.Hotel == Hotel) {
						regisClient[counter].Room = 0;
						regisClient[counter].Hotel = 0;
						regisClient[counter].Time = 0;
						break;
					}
				}
				counter = -1;
				for (const auto& i : inRequestClient) {
					counter++;
					if (i.num == num && i.hotel == Hotel) {
						writeRequestClient(counter);
						break;
					}
				}
				writeClient();
				writeRoom(num, Hotel);
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "\n"; cout << "\n"; cout << "\n";
				cout << "                              ";
				SetConsoleTextAttribute(hConsole, colorCorrect);
				PrintWait("Комната удалена", 20);
				SetConsoleTextAttribute(hConsole, colorUnSelect);
				Sleep(1000);
			}
		}
		else {
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "\n"; cout << "\n"; cout << "\n";
			cout << "                              ";
			SetConsoleTextAttribute(hConsole, colorUnCorrect);
			PrintWait("Комната не существует", 20);
			SetConsoleTextAttribute(hConsole, colorUnSelect);
			Sleep(1000);
			Rooms();
		}
		break;
	}
}
void Rooms() {
	int posCursor = 30;
	int sizeMenu = 2;
	bool end = 0;
	while (!end) {
		system("cls");
		cout << "\n";
		cout << "                                     Выберите действие с комнатами\n";
		cout << "\n";
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║     Добавление     ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║      Удаление      ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		switch (posCursor)
		{
		case 0:
			end = 1;
			system("cls");
			addRoom();
			break;
		case 1:
			end = 1;
			system("cls");
			delRoom();
			break;
		}
		if (end == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { end = 1; workAdmin(); break; }
	}
}

//--------------------------------

void entrance() {
	setlocale(LC_ALL, "Rus");
	string login;
	string password;
	string erLogin = "Пользователь не найден!";
	string erPassword = "Пароль не верен!";
	readClient();
	readMeneger();
	PrintWait("Введите логин: ", 20);
	bool end = 0;
	int counter = -1;
	int ch;
	int login2 = 0;
	int size = 0;
	int temp = -1;
	int right = 0;
	bool passwordcheck = 0;
	bool flaglogin = 0;
	while (!end) {
		ch = _getch();
		login2 = 0;
		temp = 0;
		switch (ch)
		{
		case 27:
			startMenu();
			break;
		case 8:
			if (counter > -1) {
				cout << char(ch) << " " << char(ch);
				login.erase(counter);
				counter = counter - 1;
			}
			break;
		case 13:
			if (counter > -1) {
				readClient();
				readMeneger();
				size = login.size();
				for (int i = 0; i < size; i++) {
					cout << char(8) << " " << char(8);
				}
				temp = -1;
				if (login == adminNik) {
					SetConsoleTextAttribute(hConsole, colorCorrect);
					cout << login; cout << " ";
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					flaglogin = 1;
					right = 3;
					login2 = 1;
					end = 1;
					break;
				}
				for (const auto& i : regisClient) {
					temp++;
					if (login == i.Login) {
						SetConsoleTextAttribute(hConsole, colorCorrect);
						cout << login; cout << " ";
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						clientID = temp;
						flaglogin = 1;
						right = 1;
						login2 = 1;
						end = 1;
						break;
					}
				}
				temp = -1;
				for (const auto& i : inMeneger) {
					temp++;
					if (login == i.Login) {
						SetConsoleTextAttribute(hConsole, colorCorrect);
						cout << login; cout << " ";
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						menegerID = temp;
						flaglogin = 1;
						right = 2;
						login2 = 1;
						end = 1;
						break;
					}
				}
				if (login2 == 0) {
					SetConsoleTextAttribute(hConsole, colorUnCorrect);
					cout << login;
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					cout << " ";
					SetConsoleTextAttribute(hConsole, colorWarning);
					PrintWait(erLogin, 20);
					SetConsoleTextAttribute(hConsole, colorUnSelect);
					Sleep(1000);
					CleanWait(erLogin.size() + 1 + size, 20);
					login.clear();
					counter = -1;
				}
			}
			break;
		case 32:
			break;
		default:
			if (ch == 95 || ch == 45 || ch == 46) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 97 && ch <= 122) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 48 && ch <= 57) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= 65 && ch <= 90) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			if (ch >= -128 && ch <= -17) {
				counter++;
				cout << char(ch);
				login.push_back(char(ch));
			}
			break;
		}
	}

	end = 0;
	counter = -1;
	cout << "\n";
	if (flaglogin == 1) {
		PrintWait("Введите пароль: ", 20);
		while (!end) {
			passwordcheck = 0;
			ch = _getch();
			switch (ch)
			{
			case 27:
				startMenu();
				break;
			case 8:
				if (counter > -1) {
					cout << char(ch) << " " << char(ch);
					password.erase(counter);
					counter = counter - 1;
				}
				break;
			case 32:
				break;
			case 13:
				if (counter > -1) {
					end = 1;
					size = password.size();
					for (int i = 0; i < size; i++) {
						cout << char(8) << " " << char(8);
					}
					switch (right)
					{
					case 1:
						if (regisClient[clientID].password == password) {
							SetConsoleTextAttribute(hConsole, colorCorrect);
							cout << password;
							SetConsoleTextAttribute(hConsole, colorUnSelect);
							Sleep(500);
							system("cls");
							passwordcheck = 1;
							workClient();
						}
						break;
					case 2:
						if (inMeneger[menegerID].password == password) {
							SetConsoleTextAttribute(hConsole, colorCorrect);
							cout << password;
							SetConsoleTextAttribute(hConsole, colorUnSelect);
							Sleep(500);
							system("cls");
							passwordcheck = 1;
							workMeneger();
						}
						break;
					case 3:
						if (adminPass == password) {
							SetConsoleTextAttribute(hConsole, colorCorrect);
							cout << password;
							SetConsoleTextAttribute(hConsole, colorUnSelect);
							Sleep(500);
							system("cls");
							passwordcheck = 1;
							workAdmin();
						}
					}
					if (passwordcheck == 0) {
						end = 0;
						counter = -1;
						SetConsoleTextAttribute(hConsole, colorUnCorrect);
						cout << password;
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						cout << " ";
						SetConsoleTextAttribute(hConsole, colorWarning);
						PrintWait(erPassword, 20);
						SetConsoleTextAttribute(hConsole, colorUnSelect);
						Sleep(1000);
						CleanWait(erPassword.size() + size + 1, 20);
						Sleep(1000);
						password.clear();
					}
				}
				break;
			default:
				if (ch == 95 || ch == 45 || ch == 46) {
					counter++;
					cout << char(ch);
					password.push_back(char(ch));
				}
				if (ch >= 97 && ch <= 122) {
					counter++;
					cout << char(ch);
					password.push_back(char(ch));
				}
				if (ch >= 48 && ch <= 57) {
					counter++;
					cout << char(ch);
					password.push_back(char(ch));
				}
				if (ch >= 65 && ch <= 90) {
					counter++;
					cout << char(ch);
					password.push_back(char(ch));
				}
				if (ch >= -128 && ch <= -17) {
					counter++;
					cout << char(ch);
					password.push_back(char(ch));
				}
				break;
			}
		}
	}
}
void regMenu() {
	int sizeMenu = 3;
	int posCursor = 30;
	while (true) {
		system("cls");
		if (posCursor > 100 || posCursor < -100) posCursor = 30;
		cout << "\n";
		cout << "\n";
		cout << "\n";
		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║      Как гость     ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║    Как менеджер    ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║       Назад        ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 2, 62); cout << "\n";
		setlocale(LC_ALL, "Rus");

		switch (posCursor)
		{
		case 0:
			system("cls");
			regClient();
			break;
		case 1:
			system("cls");
			regMeneger();
			break;
		case 2:
			system("cls");
			startMenu();
			break;
		}
		posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { startMenu(); break; }
	}
}
void startMenu() {
	int posCursor = 30;
	int sizeMenu = 3;
	bool heart = 0;
	while (!heart) {
		setlocale(LC_ALL, "en_US.UTF-8");
		system("cls");
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);

		cout << "\n";
		cout << "\n";
		cout << u8"                     █████╗  ███╗   ██╗ ████████╗  █████╗  ██████╗  ███████╗ ███████╗     \n";
		cout << u8"                    ██╔══██╗ ████╗  ██║ ╚══██╔══╝ ██╔══██╗ ██╔══██╗ ██╔════╝ ██╔════╝     \n";
		cout << u8"                    ███████║ ██╔██╗ ██║    ██║    ███████║ ██████╔╝ █████╗   ███████╗     \n";
		cout << u8"                    ██╔══██║ ██║╚██╗██║    ██║    ██╔══██║ ██╔══██╗ ██╔══╝   ╚════██║     \n";
		cout << u8"                    ██║  ██║ ██║ ╚████║    ██║    ██║  ██║ ██║  ██║ ███████╗ ███████║     \n";
		cout << u8"                    ╚═╝  ╚═╝ ╚═╝  ╚═══╝    ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝     \n";

		cout << "\n";
		cout << "\n";
		cout << "\n";

		setlocale(LC_ALL, "en_US.UTF-8");
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║     Регистрация    ║", 0, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 0, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║        Вход        ║", 1, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 1, 62); cout << "\n";
		cout << "\n";
		PrintWithCursorU(posCursor, L"╔════════════════════╗", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"║ Выйти из программы ║", 2, 62); cout << "\n";
		PrintWithCursorU(posCursor, L"╚════════════════════╝", 2, 62); cout << "\n";
		cout << "\n";
		switch (posCursor)
		{
		case 0:
			heart = 1;
			system("cls");
			regMenu();
			break;
		case 1:
			heart = 1;
			system("cls");
			entrance();
			break;
		case 2:
			heart = 1;
			system("cls");
			exit(0);
			break;
		}
		if (heart == 0)posCursor = moveCursor(sizeMenu, posCursor);
		if (posCursor == 100) { exit(0); }
	}
}