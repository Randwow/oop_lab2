//
//  main.cpp
//  lab2OOp
//
//  Created by Nikita Makeev on 10/2/20.
//
#include <time.h>
#include <iostream>
#include <sys/time.h>
using namespace std;
struct timeval tv;
struct tm *tm;
    class Doucument{
    private:
        
        char* name{nullptr}, * theme{nullptr}, * author{nullptr};
        int day, month, year, hours, minutes;
        
    public:
        Doucument(){
            gettimeofday(&tv, NULL);
            tm = localtime(&tv.tv_sec);
            
            day = tm->tm_mday;
            month = tm->tm_mon + 1;
            year = tm->tm_year + 1900;
            hours = tm->tm_hour;
            minutes = tm->tm_min;
            
            cout << "Конструктор по умолчанию -------- " << this << endl;
        }
        Doucument(char* name, char* theme, char* author, int day, int month, int year, int hours, int minutes){
            
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);
            
            this->theme = new char[strlen(theme)+1];
            strcpy(this->theme, theme);
            
            this->author = new char[strlen(author)+1];
            strcpy(this->author, author);
            
            day = tm->tm_mday;
            month = tm->tm_mon + 1;
            year = tm->tm_year + 1900;
            hours = tm->tm_hour;
            minutes = tm->tm_min;;
            cout << "Конструктор с параметром -------- " << this << endl;
        }
        Doucument(const Doucument &doc){

            if (doc.name != nullptr)  {
            this->name = new char[strlen(doc.name) + 1];
            strcpy(this->name, doc.name);
            }
            
            if (doc.theme != nullptr)  {
            this->theme = new char[strlen(doc.theme) + 1];
            strcpy(this->theme, doc.theme);
            }
            
            if (doc.author != nullptr)  {
            this->author = new char[strlen(doc.author) + 1];
            strcpy(this->author, doc.author);
            }
            
            this->day = doc.day;
            this->year = doc.year;
            this->month = doc.month;
            this->hours = doc.hours;
            this->minutes = doc.minutes;
            
            cout << "Конструктор копирования -------- " << this << endl;
        }
        ~Doucument(){
            
            delete [] this->name;
            delete [] this->theme;
            delete [] this->author;
            
            cout << "Диструктор" << this << endl;
        }
        void setName(char* newName){
            
        if (name == nullptr) { delete[] name; }
            
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        }
        void setTheme(char* newTheme){
            if (theme == nullptr) { delete[] theme; }
            
            theme = new char[strlen(newTheme) + 1];
            strcpy(theme, newTheme);
        }
        void setAuthor(char* newAuthor){
        if (author == nullptr) { delete[] author; }
            
            author = new char[strlen(newAuthor) + 1];
            strcpy(author, newAuthor);
        }
        void setDay(int day) { this->day = day; }
        
        void setMonth(int month) { this->month = month; }
        
        void setYear(int year) { this->year = year; }
        
        void setHours(int hours) { this->hours = hours; }
        
        void setMinutes(int minutes) { this->minutes = minutes; }
        
        void printDocument(){
           
            cout << "\tName of Document: " << ((name!= nullptr)?name:"") << endl;
            
            cout << "\tTopic of Document: " << ((theme!= nullptr)?theme:"") << endl;
            
            cout << "\tAuthor of Document: " << ((author!= nullptr)?author:"") << endl;
            
            if ((day != 0)&&(month != 0) && (year!= 0))
              cout << "\tTime of the last Save: " <<day<<"-"<<month<<"-"<<year<<" "<<hours<<":"<<minutes << "\n" << endl;
            }
        
        void printTime(){
            if ((day != 0)&&(month != 0) && (year!= 0))
              cout << "\tTime of creation document: " <<day<<"-"<<month<<"-"<<year<<" "<<hours<<":"<<minutes << "\n" << endl;
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
            
            char newName[100],newAuthor[100],newTheme[100];
            int newDay{0},
            newMonth{0},
            newYear{0},
            newHour{0},
            newMinutes{0};

            switch (choice){
                case 1:
                    doc.printTime();
                    cout << " Name of Document: ";
                    cin >> newName;
                    doc.setName(newName);
                    
                    cout << " Topic of Document: ";
                    cin >> newTheme;
                    doc.setTheme(newTheme);
                    
                    cout << " Enter Author of Document: ";
                    cin >> newAuthor;
                    doc.setAuthor(newAuthor);
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
                            cin >> newTheme;
                            doc.setTheme(newTheme);
                            
                            break;
                        case 2:
                            
                            cout << " What time parameter do you want to change?: "<<endl;;
                            cout << "1. Day " << endl;
                            cout << "2. Month " << endl;
                            cout << "3. Year " << endl;
                            cout << "4. Hours " << endl;
                            cout << "5. Minutes " << endl;
                            cout << "6. Seconds " << endl;
                            cout << "7. Do not change anything" << endl;
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

