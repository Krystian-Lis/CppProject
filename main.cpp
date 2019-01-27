#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <iterator>

using namespace std;

ifstream fileIn;
ofstream fileOut;
ostream_iterator<string> output_iterator (fileOut, "\n");

void gotoxy(int x, int y) {
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}
void background() {
	gotoxy(1,1);
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
  	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  	gotoxy(1,27);
  	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
  	cout<<"------------------------------------------------------------------------------------------------------------------------";
}

/********************************************************************************/
/*************************Obiekt glowny w programie******************************/
class continentalBed{
	protected:
		string colour;
		string material;
		int mattress;
		int width;
		int length;
		string headrest;
	public:
		continentalBed();
		continentalBed(string colour, string material, int mattress, int length, string headrest, int width);
		string getColour();
		void setColour(string colour);
		string getMaterial();
		void setMaterial(string material);
		int getMattress();
		void setMattress(int mattress);
		int getWidth();
		void setWidth(int width);
		int getLength();
		void setLength(int length);
		string getHeadrest();
		void setHeadrest(string headrest);
};
/********************************************************************************/
/********************************Lista zamowien**********************************/
class listOfOrders:public continentalBed{
	protected:
		string sMonth;
		char* cMonth;
	public:
		continentalBed *bed;
		vector<continentalBed*> orders;
		vector <string> reader;
		vector <string> search;
		bool ifEmpty();
		string listOfColours();
		string listOfMaterials();
		int listOfMattress();
		int listOfLengths();
		string listOfHeadrests();
		int listOfWidth();
		void viewingOptions();
		void showCurrent();
		bool closeFile();
		readFile();
		void saveToFile();
		string getSMonth();
		bool areYouSure();
		listOfMonths();
		void removeFile();
		pickFile();
		bool fileExists(char *fileName);
		string searchByColour(string colour);
		string searchByMattress(int mattress);
};

/********************************************************************************/
/************************Metody klasy continentalBed*****************************/

continentalBed::continentalBed(){
	colour = "";
	material = "";
	mattress = 0;
	width = 0;
	length = 0;
	headrest = "";
}

continentalBed::continentalBed(string colour, string material, int mattress, int length, string headrest, int width) {
	this->colour = colour;
	this->material = material;
	this->mattress = mattress;
	this->width = width;
	this->length = length;
	this->headrest = headrest;
}

string continentalBed::getColour() {
	return colour;
}

string continentalBed::getMaterial() {
	return material;
}
int continentalBed::getMattress() {
	return mattress;
}
int continentalBed::getWidth() {
	return width;
}
int continentalBed::getLength() {
	return length;
}
string continentalBed::getHeadrest() {
	return headrest;
}
void continentalBed::setColour(string colour) {
	this->colour = colour;
}
void continentalBed::setMaterial(string material) {
	this->material = material;
}
void continentalBed::setMattress(int mattress) {
	this->mattress = mattress;
}
void continentalBed::setWidth(int width) {
	this->width = width;
}
void continentalBed::setLength(int length) {
	this->length = length;
}
void continentalBed::setHeadrest(string headrest) {
	this->headrest = headrest;
}

/********************************************************************************/
/**************************Metody klasy listOfOrders*****************************/
string listOfOrders::listOfColours(){
	gotoxy(6,6);
	cout << "1) Wybierz kolor: "<<endl;
	int choice;

	cout<<"\t1) bialy\n\t2) czarny\n\t3) szary\n\t4) bezowy";
	gotoxy(6,11);
	cin >> choice;
	if (choice>=0 && choice <=4) {
		switch (choice) {
			case 1: return "bialy";
					break;
			case 2: return "czarny";
					break;
			case 3: return "szary";
					break;
			case 4: return "bezowy";
					break;
		}
	} else {
		gotoxy(6,11);
		cout<<"Nie ma takiego wyboru";
		Sleep(1000);
		gotoxy(6,11);
		cout<<"                     ";
		return listOfColours();
	}
}

string listOfOrders::listOfMaterials() {
	gotoxy(6,12);
	cout <<"2) Wybierz material: \n";
	int choice;

	cout<<"\t1) skora\n\t2) eko skora\n\t3) skora licowa\n\t4) tkanina";
	gotoxy(6,17);
	cin >> choice;
	if ( choice>=0 && choice <=4) {
		switch (choice) {
			case 1: return "skora";
					break;
			case 2: return "eko skora";
					break;
			case 3: return "skora licowa";
					break;
			case 4: return "tkanina";
					break;
		}
	} else {
		gotoxy(6,17);
		cout<<"Nie ma takiego wyboru";
		Sleep(1000);
		gotoxy(6,17);
		cout<<"                     ";
		return listOfMaterials();
	}
}
int listOfOrders::listOfMattress() {
	gotoxy(6,18);
	cout<<"3) Wybierz ilosc materacy: \n";
	int choice;

	cout<<"\t1) 1\n\t2) 2\n\t3) 3";
	gotoxy(6,23);
	cin >> choice;
	if ( choice>=0 && choice <=3) {
		switch (choice) {
			case 1: return 1;
					break;
			case 2: return 2;
					break;
			case 3: return 3;
					break;
		}
	} else {
		gotoxy(6,23);
		cout<<"Nie ma takiego wyboru";
		Sleep(1000);
		gotoxy(6,23);
		cout<<"                     ";
		return listOfMattress();
	}
}

int listOfOrders::listOfLengths() {
	gotoxy(98,6);
	cout<<"4) Wybierz dlugosc: \n";
	int choice;
	gotoxy(105,7);
	cout<<"1) 160";
	gotoxy(105,8);
	cout<<"1) 180";
	gotoxy(105,9);
	cout<<"3) 200";

	gotoxy(98,10);
	cin >> choice;
	if ( choice>=0 && choice <=3) {
		switch (choice) {
			case 1: return 160;
					break;
			case 2: return 180;
					break;
			case 3: return 200;
					break;
		}
	} else {
		gotoxy(98,10);
		cout<<"Nie ma takiego wyboru";
		Sleep(1000);
		gotoxy(98,10);
		cout<<"                     ";
		return listOfLengths();
	}
}

string listOfOrders::listOfHeadrests() {
	gotoxy(98,12);
	cout<<"5) Wybierz zaglowek: \n";
	int choice;
	gotoxy(105,13);
	cout<<"1) zaokraglony";
	gotoxy(105,14);
	cout<<"1) prosty";
	gotoxy(105,15);
	cout<<"3) pikowany";
	gotoxy(105,16);
	cout<<"4) brak";

	gotoxy(98,17);
	cin >> choice;
	if ( choice>=0 && choice <=4) {
		switch (choice) {
			case 1: return "zaokraglony";
					break;
			case 2: return "prosty";
					break;
			case 3: return "pikowany";
					break;
			case 4: return "brak";
					break;
		}
	} else {
		gotoxy(98,17);
		cout<<"Nie ma takiego wyboru";
		Sleep(1000);
		gotoxy(98,17);
		cout<<"                     ";
		return listOfHeadrests();
	}
}

int listOfOrders::listOfWidth() {
	gotoxy(98,18);
	cout<<"6) Wybierz szerokosc: \n";
	int choice;
	gotoxy(105,19);
	cout<<"1) 160";
	gotoxy(105,20);
	cout<<"1) 180";
	gotoxy(105,21);
	cout<<"3) 200";
	gotoxy(98,22);
	cin >> choice;
	if ( choice>=0 && choice <=3) {
		switch (choice) {
			case 1: return 160;
					break;
			case 2: return 180;
					break;
			case 3: return 200;
					break;
		}
	} else {
		gotoxy(98,22);
		cout<<"Nie ma takiego wyboru";
		Sleep(1000);
		gotoxy(98,22);
		cout<<"                     ";
		return listOfWidth();
	}
}

void listOfOrders::viewingOptions() {
	char c,pick;
	string result;
	system("CLS");
	background();
	if(!orders.empty()) {
		cout<<"Czy chcesz stworzyc kolejne zamowienie i dodac do aktualnych(T) czy usunac wszystkie poprzednie?(N)" <<endl;
		if(!areYouSure()) {
			orders.clear();
		}
	}
	gotoxy(45,5);
	cout <<"Tworzenie nowego zamowienia\n";
	orders.push_back(bed = new continentalBed(listOfColours(),listOfMaterials(),listOfMattress(),listOfLengths(),listOfHeadrests(),listOfWidth()));
	system("CLS");
	background();
	gotoxy(45,10);
	cout << "1. " << bed->getColour();
	gotoxy(45,11);
	cout << "2. " << bed->getMaterial();
	gotoxy(45,12);
	cout << "3. " << bed->getMattress();
	gotoxy(45,13);
	cout << "4. " << bed->getLength();
	gotoxy(45,14);
	cout << "5. " << bed->getHeadrest();
	gotoxy(45,15);
	cout << "6. " << bed->getWidth();
	gotoxy(40,9);
	cout<<"Czy jestes pewien swoich wyborow?(T/N)\n";
	if(!areYouSure()) {
		system("CLS");
		background();
		gotoxy(40,10);
		cout<<"Co chcialbys zmienic: \n\t\t\ta)kolor\n\t\t\tb)material\n\t\t\tc)ilosc materacy";
		cout<<"\n\t\t\td)dlugosc\n\t\t\te)zaglowek\n\t\t\tf)szerokosc";
		c = getch();
		c = tolower(c);
			switch(c){
				case 'a':
						system("CLS");
						background();
						gotoxy(6,5);
						cout<<"Wybierz inny kolor: "<<endl;
						bed->setColour(listOfColours());
						system("CLS");
					 	break;
			    case 'b':
							system("CLS");
							background();
							gotoxy(6,5);
							cout<<"Wybierz inny material: "<<endl;
							bed->setMaterial(listOfMaterials());
							system("CLS");
							break;
				case 'c':
									system("CLS");
									background();
									gotoxy(6,5);
									cout<<"Wybierz inna ilosc materacy: "<<endl;
									bed->setMattress(listOfMattress());
									system("CLS");
					 				break;
				case 'd':
									system("CLS");
									background();
									gotoxy(6,5);
									cout<<"Wybierz inna dlugosc: "<<endl;
									bed->setLength(listOfLengths());
									system("CLS");
					 				break;
				case 'e':
									system("CLS");
									background();
									gotoxy(6,5);
									cout<<"Wybierz inny zaglowek: "<<endl;
									bed->setHeadrest(listOfHeadrests());
									system("CLS");
					 				break;
				case 'f':
									system("CLS");
									background();
									gotoxy(6,5);
									cout<<"Wybierz inna szerokosc: "<<endl;
									bed->setWidth(listOfWidth());
									system("CLS");
									break;
		}
	} else {
			system("CLS");
		}
}

string listOfOrders::getSMonth() {
	return sMonth;
}
bool listOfOrders::ifEmpty() {
	if(orders.empty()){
		return true;
	} else
	return false;
}

 listOfOrders::readFile() {
	fileOut.close();
	fileOut.open(this->cMonth,ios::app);
	reader.clear();
	fileIn.open(this->cMonth, ios::in);
	string line,searched;
	int lineNr = 1;
	while(getline(fileIn,line)) {
			switch(lineNr) {
				case 1:
				reader.push_back(line);
				break;
				case 2:
				reader.push_back(line);
				break;
				case 3:
				reader.push_back(line);
				break;
				case 4:
				reader.push_back(line);
				break;
				case 5:
				reader.push_back(line);
				break;
				case 6:
				reader.push_back(line);
				break;
			}
			if(lineNr == 6) {
				lineNr = 1;
				} else {
					lineNr++;
				}
	}
	fileIn.close();
	system("CLS");
	background();
	gotoxy(1,4);
	int current = 0;
	char exit,option;
	if(!reader.empty()) {
	do {
		gotoxy(44,4);
		cout << "Aktualne wybrany plik - "<<this->sMonth<< endl;
		background();
		gotoxy(1,5);
		for (int i = 0; i<6; i++) {
		 cout<<"\t\t\t\t\t\t"<<reader[current+i]<<endl;
		}
		gotoxy(25,12);
		cout<< "N - Nastepny\tP - Poprzedni\tD - Usun\tS - Szukaj\tQ - Wyjdz";
		exit = getch();
		exit = toupper(exit);
		switch (exit) {
				case 'N':
				if (current != reader.size()) {
					if(current+6 != reader.size()) {
					current += 6;
					system("CLS");
					}
				}
				break;
				case 'P': if(current != 0) {
					current -= 6;
					system("CLS");
				}
				break;
				case 'D':
				gotoxy(45,13);
				cout<<"Czy jestes pewny? T/N"<<endl;
				if(!areYouSure()) {
					system("CLS");
					break;
				}
									reader.erase(reader.begin()+current, reader.begin()+(current+6));
									fileOut.close();
									fileOut.open(this->cMonth, ios::out);
									copy(reader.begin(), reader.end(), output_iterator);
										if(current != 0) {
											current -= 6;
										} else if(current != reader.size()) {
												current += 6;
											}
									system("CLS");
									fileOut.close();
									break;
				case 'S': search.erase(search.begin(),search.end());
									int current = 0;
									char enter,pick;
									gotoxy(43,14);
									cout<<"Witaj w przeszukiwaniu, czego szukasz?"<< endl;
									gotoxy(46,15);
									cout<<"1. Kolory"<<endl;
									gotoxy(46,16);
									cout<<"2.Ilosc materacy"<<endl;
									gotoxy(46,17);
									enter = getch();
									switch (enter) {
										case '1': searched = searchByColour(listOfColours());
										break;
										case '2': searched = searchByMattress(listOfMattress());
										break;
									}
									 do{
										system("CLS");
										background();
										gotoxy(44,4);
										cout << "Szukam po " << searched << endl;
										gotoxy(25,12);
										cout<< "N - Nastepny\tP - Poprzedni\tQ - Powrot do przegladania";
										gotoxy(1,5);
										if(!search.empty()) {
										for (int j = 0; j < 6; j++)
											cout << "\t\t\t\t\t\t"<<search[current+j]<<endl;
										} else {
											gotoxy(1,5);
											cout<<"Nie znaleziono"<<endl;
										}
										option = getch();
										option = toupper(option);

										switch(option) {
											case 'N': if (current != search.size()) {
																if(current + 6 != search.size()) {
																current += 6;
																system("CLS");
																} else {
																	break;
																}
																break;
																}
											case 'P': if(current != 0) {
																current -= 6;
																system("CLS");
																break;
																} else {
																	break;
																}
											}
											system("CLS");
								} while (option != 'Q');
							}
		}	while (exit != 'Q');
	}
}

void listOfOrders::showCurrent(){
	if(!orders.empty()) {

	system("CLS");
	background();
	int current = 0;

		char exit,option;

		do {
			gotoxy(44,4);
			cout << "Aktualne zamowienie: " << endl;
			background();
			gotoxy(1,5);

			 cout<<"\t\t\t\t\t\t"<<orders[current]->getColour()<<endl;
			 cout<<"\t\t\t\t\t\t"<<orders[current]->getMaterial()<<endl;
			 cout<<"\t\t\t\t\t\t"<<orders[current]->getMattress()<<endl;
			 cout<<"\t\t\t\t\t\t"<<orders[current]->getLength()<<endl;
			 cout<<"\t\t\t\t\t\t"<<orders[current]->getHeadrest()<<endl;
			 cout<<"\t\t\t\t\t\t"<<orders[current]->getWidth()<<endl;

			gotoxy(25,12);
			cout<< "N - Nastepny\tP - Poprzedni\tD - Usun\tE - Edytuj\tQ - Wyjdz";
			exit = getch();
			exit = toupper(exit);
			switch (exit) {
					case 'N':
					if (current != orders.size()) {
						if(current+1 != orders.size()) {
						current += 1;
						system("CLS");
						}
					}
					break;
					case 'P': if(current != 0) {
						current -= 1;
						system("CLS");
					}
					break;
					case 'D':

							orders.erase(orders.begin()+current);
								if(current != 0) {
									current -= 1;
								} else if(current != orders.size()) {
										current+= 1;
									}
							system("CLS");
							break;
					case 'E':
					gotoxy(30,13);
							cout<<"Co chcialbys zmienic w aktualnie ogladanym zamowieniu?"<<endl;
							gotoxy(1,14);
							cout<<"\t\t\t\t1. Kolor\n\t\t\t\t2. Material\n\t\t\t\t3. Ilosc materacy\n\t\t\t\t4. Dlugosc\n\t\t\t\t5. Zaglowek\n\t\t\t\t6. Szerokosc";
							char c;
							c = getch();
							c = toupper(c);
							switch (c) {
								case '1':
								orders[current]->setColour(listOfColours());
								break;
								case '2': orders[current]->setMaterial(listOfMaterials());
								break;
								case '3': orders[current]->setMattress(listOfMattress());
								break;
								case '4': orders[current]->setLength(listOfLengths());
								break;
								case '5': orders[current]->setHeadrest(listOfHeadrests());
								break;
								case '6': orders[current]->setWidth(listOfWidth());
								break;
							}
							system("CLS");



			}
		}	while ((exit != 'Q') && (!orders.empty()));
		system("CLS");
	}
}


void listOfOrders::saveToFile(){
	gotoxy(30,1);
	cout<<"Aktualnie otwarty plik: " << this->sMonth << endl;
	gotoxy(30,2);
	cout<<"Czy jestes pewny ze chcesz to zapisac do tego pliku (T/N)\n";
	if(areYouSure()) {
		for (int i=0; i<orders.size(); i++) {
		fileOut << orders[i]->getColour() << endl
		<<orders[i]->getMaterial() << endl
		<<orders[i]->getMattress() << endl
		<<orders[i]->getLength() << endl
		<<orders[i]->getHeadrest() << endl
		<<orders[i]->getWidth() << endl;
		}
		orders.clear();
	}	else
	cout<<"Dane nie zostaly zapisane";

}

bool listOfOrders::areYouSure() {
	int quit = 0;
	while(quit == 0) {
		gotoxy(45,16);
		cout<<"                ";
		gotoxy(45,16);
		char answer;
		cin >> answer;
		answer = toupper(answer);
		if(answer == 'T'){
			return true;
	 	}
		if (answer == 'N'){
	  	return false;
		} else {
				gotoxy(45,15);
				cout<<"Sproboj ponownie"<<endl;
				Sleep(1000);
		}
	}
}

bool listOfOrders::closeFile() {
	if(fileOut.is_open()) {
		cout<< "Czy napewno chcesz zamknac ten plik? (T/N)" << endl;
		if(areYouSure()) {
			fileOut.close();
			this->cMonth = NULL;
			this->sMonth = "";
			system("CLS");
			return true;
			} else {
				return false;
	  	}
	} return false;
}

void listOfOrders::removeFile() {
	if(this->sMonth.empty()) {
    cout<< "Musisz najpierw wybrac jakis plik"<<endl;
		cout<< "Wracam do menu"<<endl;
	}
  else {
		cout << "Czy jestes pewien ze chcesz usunac aktualnie wybrany plik (" << this->sMonth << ")? (T/N)"<<endl;
		if(areYouSure()) {
			fileOut.close();
			remove(this->cMonth);
			this->sMonth = "";
			this->cMonth = NULL;
    	cout<< "Udalo sie! Plik zostal usuniety.";
		}
	}
}

string listOfOrders::searchByColour(string colour) {
	fileIn.open(this->cMonth, ios::in);
	string line;
	int lineNr;
		while(getline(fileIn,line)){
			if(line == colour) {
				search.push_back(reader[lineNr]);
				for (int i=1; i<6;i++){
					search.push_back(reader[lineNr+i]);
				}
			}
			lineNr++;
		}
		string exit = "kolorze: ";
		return exit + colour;
}

string listOfOrders::searchByMattress(int mattress) {
	fileIn.open(this->cMonth, ios::in);
	stringstream ss;
	string line;
	int lineNr;
	string mat;
	ss<<mattress;
	mat = ss.str();
		while(getline(fileIn,line)) {
			if(line == mat) {
				search.push_back(reader[lineNr-2]);
				search.push_back(reader[lineNr-1]);
				search.push_back(reader[lineNr]);
				for (int i=1; i<=3;i++){
					search.push_back(reader[lineNr+i]);
				}
			}
			lineNr++;
		}
		string exit = "ilosci materacy: ";
		return exit + mat;
}
listOfOrders::listOfMonths() {
	background();
	gotoxy(30,10);
	cout<<"Wybierz odpowiedni numer dla danego miesiaca"<<endl;
	gotoxy(30,11);
	cout<<"1 = Styczen"<<endl;
	gotoxy(30,12);
	cout<<"2 = Luty"<<endl;
	gotoxy(30,13);
	cout<<"3 = Marzec"<<endl;
	gotoxy(30,14);
	cout<<"4 = Kwiecen"<<endl;
	gotoxy(30,15);
	cout<<"5 = Maj"<<endl;
	gotoxy(30,16);
	cout<<"6 = Czerwiec"<<endl;
	gotoxy(30,17);
	cout<<"7 = Lipiec"<<endl;
	gotoxy(30,18);
	cout<<"8 = Sierpien"<<endl;
	gotoxy(30,19);
	cout<<"9 = Wrzesien"<<endl;
	gotoxy(30,20);
	cout<<"10 = Pazdziernik"<<endl;
	gotoxy(30,21);
	cout<<"11 = Listopad"<<endl;
	gotoxy(30,22);
	cout<<"12 = Grudzien"<<endl;
	pickFile();
}

bool listOfOrders::fileExists(char *fileName) {
	fstream plik;
	plik.open(fileName, ios::in);
	if(plik.good() == true){
		return true;
	} else false;
}

listOfOrders::pickFile() {
	cin.clear();
	int month;
	gotoxy(30,23);
	cin >> month;
	if(!cin.good()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		pickFile();
	} else {
		system("CLS");
		if (month>0 && month<13) {
			switch (month) {
				case 1:	this->sMonth = "Styczen";
								break;
				case 2: this->sMonth = "Luty";
								break;
				case 3: this->sMonth = "Marzec";
								break;
				case 4: this->sMonth = "Kwiecien";
								break;
				case 5: this->sMonth = "Maj";
								break;
				case 6: this->sMonth = "Czerwiec";
								break;
				case 7: this->sMonth = "Lipiec";
								break;
				case 8: this->sMonth = "Sierpien";
								break;
				case 9: this->sMonth = "Wrzesien";
								break;
				case 10: this->sMonth = "Pazdziernik";
								break;
				case 11: this->sMonth = "Listopad";
								break;
				case 12: this->sMonth = "Grudzien";
								break;
			}
		} else {
				cout<<"Sproboj ponownie"<<endl;
				pickFile();
			}
	}
	this->cMonth = (char*) sMonth.c_str();
	strcat(this->cMonth, ".txt");

	if(!fileExists(this->cMonth)){
		fileOut.open(this->cMonth, ofstream::out);
	}	else {
		cout<<"Taki plik juz istnieje, czy chcialbys go nadpisac(T) lub otworzyc(N)?";
			if(areYouSure()) {
				fileOut.open(this->cMonth, ofstream::out);
			} else {
				fileOut.open(this->cMonth, ios_base::app);
			}
		system("CLS");
	}
}
/********************************************************************************/
/***********************************Obsluga**************************************/
int main() {
	listOfOrders list;

//	Order currentOrder(list.viewingOptions());
	char choice;
  do{
  	background();
		gotoxy(30,10);
		cout<< "Witaj sprzedawco, w czym moge ci dzisiaj pomoc?\n";
		gotoxy(35,11);
		cout<< "1. Wyswietl zamowienia z pliku\n";
		gotoxy(35,12);
		cout<< "2. Stworz nowe zamowienie\n";
		gotoxy(35,13);
		cout<< "3. Pokaz aktualne zamowienia\n";
		gotoxy(35,14);
		cout<< "4. Stworz nowy lub wybierz aktualny plik na zamowienia\n";
		gotoxy(35,15);
		cout<< "S. Zapisz dane do pliku\n";
		gotoxy(35,16);
		cout<< "R. Usun aktualny plik z zamowieniami\n";
		gotoxy(35,17);
		cout<< "Q. Zakoncz\n";
		gotoxy(35,18);

	choice = getch();
	choice = toupper(choice);
			switch(choice) {
				case '1': system("CLS");
				if(list.getSMonth().empty()) {
				gotoxy(35,23);
				cout << "Musisz stworzyc lub wybrac jakas liste"<<endl;
				} else {
						system("CLS");
						background();
						list.readFile();
						gotoxy(40,15);
						cout<<"Dziekuje(wcisnij dowolny klawisz)"<<endl;
						getch();
						system("CLS");
					}
				break;
				case '2': list.viewingOptions();
				break;
		case '3': list.showCurrent();
		break;
		case '4': system("CLS");
						background();
						gotoxy(30,8);
						if(!list.closeFile()) {
							list.listOfMonths();
						}
						break;
		case 'S':	if(!list.getSMonth().empty()) {
			list.saveToFile();
		}	else {
			cout<<"Musisz najpierw wybrac/stworzyc jakis plik"<<endl;
			Sleep(1000);
			system("CLS");
		}
				break;
		case 'R':	list.removeFile();
				break;
		case 'Q':
				if(!list.ifEmpty()) {
				system("CLS");
				gotoxy(30,15);
				cout<<"Czy chcesz zapisac aktualne zamowienia?(T/N)"<<endl;
				if(list.areYouSure())
				list.saveToFile();
				}
				break;
	}
	}
	while(choice!='Q');
	return 0;
}
