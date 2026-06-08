#include<iostream>
#include"User.h"
#include"Pet.h"
#include"Basic Animals.h"
#include"FileManager.h"
#include"logo.h"
#include<fstream>
#include<windows.h>
using namespace std;


void disp_main_menu(Pet& p){
    cout<<CALM_B1<<"\n▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
    cout<<CYAN  <<"   "<<p.face<<"  "<<p.p_name<<"   |   Age: "<<p.p_age<<"   |   PP: "<<p.pp<<RESET<<endl;
    cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
    cout<<GREEN  <<"  1.  Feed           🍖"<<RESET<<endl;
    cout<<BLUE   <<"  2.  Play           🛝"<<RESET<<endl;
    cout<<Pink   <<"  3.  Show Affection 💖"<<RESET<<endl;
    cout<<YELLOW <<"  4.  Groom          🧼"<<RESET<<endl;
    cout<<CYAN   <<"  5.  Sleep          😴"<<RESET<<endl;
    cout<<GREEN  <<"  6.  Pet Special Ability ✨"<<RESET<<endl;
    cout<<BROWN  <<"  7.  View Pet Health ❤️‍🩹"<<RESET<<endl;
    cout<<CALM_B1<<"  8.  Store          🛒"<<RESET<<endl;
    cout<<RED    <<"  0.  Quit           🚪"<<RESET<<endl;
    cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    disp_logo();

    User user;
    if(isNewGame()){
        user.create_account();
        user.Save_to_U_f();
        user.Congratulate();
    }
    else{
        user.Load_file();
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN<<"\nWelcome back, "<<user.first_name<<" "<<user.second_name<<" 😊"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
    }

    Cat     cat;
    Dog     dog;
    Horse   horse;
    Sparrow sparrow;
    Parrot  parrot;
    Rabbit  rabbit;
    Hen     hen;

    Pet* pet      = nullptr;
    int  pet_type = 0;
    bool loaded   = false;  

    cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
    cout<<CYAN   <<"  LOAD YOUR SAVED PET?"<<RESET<<endl;
    cout<<GREEN  <<"  1. YES - Continue 💾"<<RESET<<endl;
    cout<<RED    <<"  2. NO  - Start Fresh 🆕"<<RESET<<endl;
    cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;

    int load_ch;
    while(true){
        cout<<CYAN<<"ENTER CHOICE : "<<RESET;
        cin>>load_ch;
        if(cin.fail() || load_ch < 1 || load_ch > 2){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
            continue;
        }
        break;
    }

    if(load_ch==1){
        load_game(&cat, pet_type);  
        if(pet_type==1){
            pet=&cat;
            load_game(pet, pet_type);
        }
        else if(pet_type==2){
            pet=&dog;
            load_game(pet, pet_type);
        }
        else if(pet_type==3){
            pet=&horse;
            load_game(pet, pet_type);
        }
        else if(pet_type==4){
            pet=&sparrow;
            load_game(pet, pet_type);
        }
        else if(pet_type==5){
            pet=&parrot;
            load_game(pet, pet_type);
        }
        else if(pet_type==6){
            pet=&rabbit;
            load_game(pet, pet_type);
        }
        else if(pet_type==7){
            pet=&hen;
            load_game(pet, pet_type);
        }

        if(pet_type>=1&&pet_type<=7){
            loaded=true;
        }
        else{
            cout<<YELLOW<<"NO VALID SAVE DATA FOUND. STARTING A NEW GAME... 🆕"<<RESET<<endl;
        }
    }

    if(loaded==false){  
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"      CHOOSE YOUR PET 🐾"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN <<"  1.  Cat     😺"<<RESET<<endl;
        cout<<YELLOW<<"  2.  Dog     🐶"<<RESET<<endl;
        cout<<BROWN <<"  3.  Horse   🐴"<<RESET<<endl;
        cout<<CYAN  <<"  4.  Sparrow 🐦"<<RESET<<endl;
        cout<<Pink  <<"  5.  Parrot  🦜"<<RESET<<endl;
        cout<<GREEN <<"  6.  Rabbit  🐰"<<RESET<<endl;
        cout<<YELLOW<<"  7.  Hen     🐔"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>pet_type;
            if(cin.fail() || pet_type < 1 || pet_type > 7){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️. PLEASE ENTER 1-7."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(pet_type == 1){
            pet = &cat;
        }
        else if(pet_type == 2){
            pet = &dog;
        }
        else if(pet_type == 3){
            pet = &horse;
        }
        else if(pet_type == 4){
            pet = &sparrow;
        }
        else if(pet_type == 5){
            pet = &parrot;
        }
        else if(pet_type == 6){
            pet = &rabbit;
        }
        else{
            pet = &hen;
        }

        pet->set_data();
    }

    while(pet->p_alive){
        disp_main_menu(*pet);
        pet->check_mood_condition();
        int choice;
        cout<<CYAN<<"ENTER CHOICE : "<<RESET;
        cin>>choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
            continue;
        }
        if(choice==1){
            pet->feed();
        }
        else if(choice==2){
            pet->play();
        }
        else if(choice==3){
            pet->show_affection();
        }
        else if(choice==4){
            pet->groom();
        }
        else if(choice==5){
            pet->sleep();
        }
        else if(choice==6){
            pet->pet_special_ability();
        }
        else if(choice==7){
            pet->display_bars();
        }
        else if(choice==8){
            pet->purchase();
        }
        else if(choice == 0){
            pet->increase_age();
            save_game(pet, pet_type);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<Pink   <<"   GOODBYE! TAKE CARE OF "<<pet->p_name<<" 🐾💖"<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            
            return 0;
        }
        else{
            cout<<YELLOW<<"INVALID CHOICE ⚠️. PLEASE ENTER 0-9."<<RESET<<endl;
            continue;
        }

        pet->time_pass();
        pet->predator_attack();
        pet->check_health();
    }

    cout<<CYAN<<"YOUR FINAL PP : "<<pet->pp<<RESET<<endl;
    cout<<Pink<<"THANK YOU FOR PLAYING PETHAF STUDIO 🐾💖"<<RESET<<endl;

    return 0;
}