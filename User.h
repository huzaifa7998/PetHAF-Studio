#pragma once
#include<iostream>
#include<windows.h>
#include"Colours.h"
#include<fstream>
#include<string>
using namespace std;
class User{
    public:
        string first_name;
        string second_name;
        int age;
        string gender;

        void create_account(){
            cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬✨CREATE ACCOUNT✨▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;

            while(true){
                cout<<WHITE<<"Enter Your First Name: "<<RESET;
                getline(cin, first_name);
                if (first_name.empty()) {
                    cout<<RED<<"Invalid! First name cannot be empty.\n"<<RESET;
                } else if (first_name.find(' ') != string::npos) {
                    cout<<RED<<"Invalid! First name should not have any spaces.\n"<<RESET;
                } else {
                    break;
                }
            }

            while(true){
                cout<<WHITE<<"\nEnter Your Second Name: "<<RESET;
                getline(cin, second_name);
                if (second_name.empty()) {
                    cout<<RED<<"Invalid! Second name cannot be empty.\n"<<RESET;
                } else if (second_name.find(' ') != string::npos) {
                    cout<<RED<<"Invalid! Second name should not have any spaces.\n"<<RESET;
                } else {
                    break;
                }
            }

            while(true){
                cout<<WHITE<<"\nEnter Your Age: "<<RESET;
                cin>>age;
                if(cin.fail() || age<3 || age>95){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<RED<<"INVALID AGE! Not Accepted⚠️."<<endl;
                    continue;
                }
                else{
                    cin.ignore(1000, '\n');
                    break;
                }
            }

            while(true){
                cout<<"Choose Your Gender (M or F) : "<<endl;
                cout<<Pink<<"1.Female"<<RESET<<endl;
                cout<<BLUE<<"2.Male"<<RESET<<endl;  
                string choice;
                cin>>choice;  
                if(choice=="F" || choice=="f"){
                    gender="Female";
                    break;
                    
                }
                else if(choice=="M"||choice=="m"){
                gender="Male";
                break;
                }
            else{
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<YELLOW<<"INVALID CHOICE (YOU ARE NOT ALLOWED TO ENTER THAT)⚠️."<<RESET<<endl;
                continue;
                }
            }
           
            cout<<CYAN<<"\n▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            }
            void Save_to_U_f(){
            ofstream fout("User.txt",ios::trunc);
            if(!fout){ cout<<"Error Giving Output To User.txt"<<endl;}
            fout<<"first_name="<<first_name<<endl;
            fout<<"second_name="<<second_name<<endl;
            fout<<"age="<<age<<endl;
            fout<<"gender="<<gender<<endl;
            fout.close();
            }

            void Congratulate() {
            cout<<GREEN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            cout<<GREEN<<"CONGRATULATIONS "<<first_name<<" "<<second_name<<"! YOUR ACCOUNT HAS BEEN CREATED🎉🎉."<<RESET<<endl;
            cout<<YELLOW<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            }
            void Load_file(){
            ifstream file("User.txt", ios::in);
            if(!file){ 
            cout<<RED<<"Error reading User.txt"<<RESET<<endl;
            }
            string line;
            while(getline(file, line)){
            int eq=line.find('=');
            string pehla_word=line.substr(0, eq);
            string dusra_word=line.substr(eq+1);

            if(pehla_word=="first_name"){
            first_name=dusra_word;
            }  
        }
        file.close();
        }
    
};
        bool isNewGame() {
            ifstream file("User.txt");  
            if(!file){
            cout<<"Could not read file."<<endl;
            return true;  
        }
        string line;
        while (getline(file, line)){
            if(line.find("first_name=none845yhwda") != string::npos) {
            return true;
            }
        }
        file.close();
        return false;
}    
