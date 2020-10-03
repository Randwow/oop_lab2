//
//  main.cpp
//  lab2OOp
//
//  Created by Nikita Makeev on 10/2/20.
//
#include <iostream>
using namespace std;
    class Doucument{
    private:
        char* name{nullptr};
        char* theme{nullptr};
        char* author{nullptr};
        int numberOfPage{0};
        int day{0};
        int month{0};
        int year{0};
        int hours{0};
        int minutes{0};
    public:
        Doucument(){
            cout << "Конструктор по умолчанию -------- " << this << endl;
        }
        Doucument(char* name, char* theme, char* author){
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);
            this->theme = new char[strlen(theme)+1];
            strcpy(this->theme, theme);
            this->author = new char[strlen(author)+1];
            strcpy(this->author, author);
            numberOfPage = 0;
            day = 0;
            month = 0;
            year = 0;
            hours = 0;
            minutes = 0;
            cout << "Конструктор с параметром -------- " << this << endl;
        }
        Doucument(const Doucument &doc){
            this->name = (doc.name == nullptr) ? nullptr : new char[strlen(doc.name) + 1];
            strcpy(this->name, doc.name);
//            if (doc.theme == nullptr) this->theme = nullptr;
//            else {
//            this->theme = new char[strlen(doc.theme) + 1];
//            strcpy(this->theme, doc.theme);
//            }
            this->theme = (doc.theme == nullptr) ? nullptr : new char[strlen(doc.theme) + 1];
            strcpy(this->theme, doc.theme);
            this->author = (doc.author == nullptr) ? nullptr : new char[strlen(doc.author) + 1];
            strcpy(this->author, doc.author);
            this->numberOfPage = doc.numberOfPage;
            this->day = doc.day;
            this->year = doc.year;
            this->month = doc.month;
            this->hours = doc.hours;
            this->minutes = doc.minutes;
            cout << "Конструктор копирования -------- " << this << endl;
        }
        ~Doucument(){
            delete [] name;
            delete [] theme;
            delete [] author;
            cout << "Диструктор" << this << endl;
        }
        void setName(char* newName){
        if (name != nullptr) { delete[] name; }
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        }
        void setTheme(char* newTheme){
            if (theme != nullptr) { delete[] theme; }
            theme = new char[strlen(newTheme) + 1];
            strcpy(theme, newTheme);
        }
        void setAuthor(char* newAuthor){
        if (author != nullptr) { delete[] author; }
            author = new char[strlen(newAuthor) + 1];
            strcpy(author, newAuthor);
        }
        void setDay(int day) { this->day = day; }
        void setMonth(int month) { this->month = month; }
        void setYear(int year) { this->year = year; }
        void setHours(int hours) { this->hours = hours; }
        void setMinutes(int minutes) { this->minutes = minutes; }
        void printDocument(){
            if (name != nullptr)
            cout << "\tName of Document: " << name << endl;
            if (theme != nullptr)
            cout << "\tTopic of Document: " << theme << endl;
            if (author != nullptr)
            cout << "\tAuthor of Document: " << author << endl;
            if ((day != 0)&&(month != 0) && (year!= 0))
              cout << "\tTime of the last Save: " <<day<<"-"<<month<<"-"<<year<<" "<<hours<<":"<<minutes << "\n" << endl;
            }
    };
int main(int argc, const char * argv[]) {
    Doucument doc;
    int choice{0},
    newChoice{0},
    choiceInNewChoise{0};
        while (choice != 4){
            cout << "1. Enter new Document " << endl;
            cout << "2. Change values of Document " << endl;
            cout << "3. Output on Display" << endl;
            cout << "4. Explain Nothing" << endl;
            cin >> choice;
            char value[100];
            int newDay{0},
            newMonth{0},
            newYear{0},
            newHour{0},
            newMinutes{0};
            switch (choice){
                case 1:
                    cout << " Name of Document: ";
                    cin >> value;
                    doc.setName(value);
                    cout << " Topic of Document: ";
                    cin >> value;
                    doc.setTheme(value);
                    cout << " Enter Author of Document: ";
                    cin >> value;
                    doc.setAuthor(value);
                    cout << " Enter Day when Document was saving:= ";
                    cin >> newDay;
                    if (newDay <= 1 && newDay > 31) {
                        cout << "try again you enter value of hours < 1 or > 31 ";
                        cin >> newDay;
                    }
                    doc.setDay(newDay);
                    cout << " Enter Month when Document was saving:= ";
                    cin >> newMonth;
                    if (newMonth <= 1 && newMonth > 12) {
                        cout << "try again you enter value of hours < 1 or > 12 ";
                        cin >> newMonth;
                    }
                    doc.setMonth(newMonth);
                    cout << " Enter Year when Document was saving:= ";
                    cin >> newYear;
                    doc.setYear(newYear);
                    cout << " Enter Hours when Document was saving:= ";
                    cin >> newHour;
                    if (newHour > 24 && newHour < 0) {
                        cout<<"try again you enter value of hours < 0 or > 24 ";
                        cin >> newHour;
                    }
                    doc.setHours(newHour);
                    cout << " Enter Minutes when Document was saving:= ";
                    cin >> newMinutes;
                    if (newMinutes > 60 && newMinutes <  0) {
                        cout<<"try again you enter value of minutes < 0 or > 60 ";
                        cin >> newMinutes;
                    }
                    doc.setMinutes(newMinutes);
                    break;
                case 2:
                    cout << " Which field should be changed " << endl;
                    cout << "1. Topic of Document " << endl;
                    cout << "2. Time of saving" << endl;
                    cout << "3. Do not change anything" << endl;
                    cin >> newChoice;
                    switch (newChoice){
                        case 1:
                            cout << " Enter new Topic of Document: ";
                            cin >> value;
                            doc.setTheme(value);
                            break;
                        case 2:
                            cout << " What time parameter do you want to change?: "<<endl;;
                            cout << "1. Day " << endl;
                            cout << "2. Month " << endl;
                            cout << "3. Year " << endl;
                            cout << "4. Hours " << endl;
                            cout << "5. Minutes " << endl;
                            cout << "6. Do not change anything" << endl;
                            cin >> choiceInNewChoise;
                            switch (choiceInNewChoise) {
                                case 1:
                                    cout << " Enter a new Day: ";
                                    cin >> newDay;
                                    if (newDay <= 1 && newDay > 31) {
                                        cout << "try again you enter value of hours < 1 or > 31 ";
                                        cin >> newDay;
                                    }
                                    doc.setDay(newDay);
                                    break;
                                case 2:
                                    cout << " Enter a new Month: ";
                                    cin >> newMonth;
                                    if (newMonth <= 1 && newMonth > 12) {
                                        cout << "try again you enter value of hours < 1 or > 12 ";
                                        cin >> newMonth;
                                    }
                                    doc.setMonth(newMonth);
                                    break;
                                case 3:
                                    cout << " Enter new Year: ";
                                    cin >> newYear;
                                    doc.setYear(newYear);
                                    break;
                                case 4:
                                    cout << " Enter new Hours < 60 and > 0 ";
                                    cin >> newHour;
                                    if (newHour < 24 && newHour > 0) {
                                        cout<<"try again you enter value of hours < 0 or > 24 ";
                                        cin >> newHour;
                                    }
                                    doc.setHours(newHour);
                                    break;
                                case 5:
                                    cout << " Enter new Minutes < 60 and > 0 ";
                                    cin >> newMinutes;
                                    if (newMinutes < 60 && newMinutes > 0) {
                                        cout<<"try again you enter value of minutes < 0 or > 60 ";
                                        cin >> newMinutes;
                                    }
                                    doc.setMinutes(newMinutes);
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                        }
                    break;
                case 3:
                    doc.printDocument();
                    break;
                default:
                    break;
        }
    }
    return 0;
}

