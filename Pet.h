#pragma once
#include<iostream>
#include"User.h"
#include"Colours.h"
#include"Inventory.h"
#include"Store.h"
#include<windows.h>
#include<string>     
#include<fstream>
using namespace std;
  
class Pet : public Inventory{
    public:
    int health  = 100;
    int max_age = 15;   
    int mood    = 100;
    int hunger  = 100;
    int energy  = 100;
    int p_age   = 0;
    string face;
    bool p_alive = true;

    string p_name = "pet";

    Pet(){}

    virtual void set_pet_face(string facee){
        face = facee;
    }

    void set_data(){
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN<<"  WELCOME! GIVE YOUR PET A NAME : "<<RESET;
        cin.ignore(1000,'\n');
        getline(cin, p_name);
        if(p_name.empty()) p_name = "Pet";
        cout<<GREEN<<"  YOUR PET'S NAME IS : "<<p_name<<" "<<face<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
    }

    virtual void display_bars(){
        cout<<BLACK<<"\n▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃"<<RESET<<endl;
        string full_block = "█";
        string emp_block  = "▒";

        int remaining_health = 100 - health;
        cout<<YELLOW<<"║"<<RESET;
        for(int i = 0; i < health;           i += 5){
             cout<<GREEN<<full_block<<RESET;
        }
        for(int j = 0; j < remaining_health; j += 5){
             cout<<RED<<emp_block<<RESET;
        }
        cout<<YELLOW<<"║"<<RESET<<CYAN<<"    Health "<<health<<"/100"<<RESET<<endl;

        int remaining_mood = 100 - mood;
        cout<<YELLOW<<"║"<<RESET;
        for(int i = 0; i < mood;          i += 5){ 
            cout<<CALM_B1<<full_block<<RESET;
        }
        for(int j = 0; j < remaining_mood;j += 5){
             cout<<DARK_RED<<emp_block<<RESET;
        }
        cout<<YELLOW<<"║"<<RESET<<CYAN<<"    MOOD "<<mood<<"/100"<<RESET<<endl;

        int remaining_hunger = 100 - hunger;
        cout<<YELLOW<<"║"<<RESET;
        for(int i = 0; i < hunger;          i += 5){
             cout<<BROWN<<full_block<<RESET;
        }
        for(int j = 0; j < remaining_hunger;j += 5){
            cout<<RED<<emp_block<<RESET;
        }
        cout<<YELLOW<<"║"<<RESET<<CYAN<<"    HUNGER "<<hunger<<"/100"<<RESET<<endl;

        int remaining_energy = 100 - energy;
        cout<<YELLOW<<"║"<<RESET;
        for(int i = 0; i < energy;          i += 5){
            cout<<BLUE<<full_block<<RESET;
        }
        for(int j = 0; j < remaining_energy;j += 5){
            cout<<RED<<emp_block<<RESET;
        }
        cout<<YELLOW<<"║"<<RESET<<CYAN<<"    ENERGY "<<energy<<"/100"<<RESET;
        cout<<BLACK<<"\n▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂"<<RESET<<endl;
    }

    virtual void check_mood_condition(){
        if(mood <= 30 && hunger <= 75){
            cout<<YELLOW<<p_name<<" is lazy. (MOOD AND HUNGER LOW)."<<face<<"🥱"<<RESET<<endl;
        }
        else if(mood > 50){
            cout<<GREEN<<p_name<<" is Happy "<<face<<"."<<RESET<<endl;
        }
        else{
            cout<<RED<<p_name<<" is grumpy "<<face<<"."<<RESET<<endl;
        }
    }

    virtual void time_pass(){
        
        hunger -= 5;
        mood   -= 2;
        energy -= 3;   
        if(hunger <= 0){ hunger = 0; health -= 10; }
        if(energy <  0)  energy = 0;
        if(mood   <  0)  mood   = 0;
        if(health <  0)  health = 0;

        if(health < 50){
            cout<<YELLOW<<"REMINDER : "<<p_name<<" HAS HEALTH BELOW 50 — GIVE MEDICINE OR FEED. ✱✱🍴💊"<<RESET<<endl;
        }
        if(health <= 10){
            cout<<RED<<"CRITICAL ALERT 🚨🚨. "<<p_name<<" IS LOW ON HEALTH — FEED OR GIVE MEDICINE. ✱✱🍴💊🤧"<<RESET<<endl;
        }
        if(hunger < 30){
            cout<<RED<<"CRITICAL ALERT 🚨🚨. "<<p_name<<" IS STARVING 🍴😩. ✱✱"<<RESET<<endl;
        }
        
    }
    virtual void increase_age(){
        p_age  += 1;
        if(p_age >= max_age){
            cout<<YELLOW<<"⏳ "<<p_name<<" IS GETTING VERY OLD..."<<RESET<<endl;
        }
    }
    virtual void check_health(){
        if(hunger <= 0 || health <= 0 || p_age >= max_age){
            p_alive = false;
            cout<<endl;
            cout<<BLACK<<"╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩"<<RESET<<endl;
            cout<<RED<<p_name<<" IS NO MORE. 💔💔"<<RESET<<endl;
            if(p_age >= max_age){
                cout<<BLACK<<p_name<<" DIED OF OLD AGE."<<RESET<<endl;
            }
            cout<<BLACK<<"DIED AT AGE : "<<CYAN<<p_age<<RESET<<endl;
            cout<<BLACK<<p_name<<Pink<<" Will Always Be Missed. 😢"<<RESET<<endl;
            cout<<BLACK<<"╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦"<<RESET<<endl;
            cout<<endl;
        }
    }

    virtual void play(){
        if(energy <= 20){
            cout<<YELLOW<<p_name<<" IS TOO TIRED TO PLAY 😪. LET IT GET SOME REST. 🛏️"<<RESET<<endl;
            return;
        }

        cout<<CYAN<<"Pick an item for "<<p_name<<" to play with."<<RESET<<endl;

        bool played=use_inv_f_play();
        if(!played){
            return;
        }

        cout<<GREEN<<"☄▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<p_name<<" PLAYING ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
        mood   += 10; if(mood   > 100) mood   = 100;
        hunger -= 10; if(hunger <   0) hunger = 0;
        energy -= 10; if(energy <   0) energy = 0;
        display_bars();
    }

    virtual void feed(){
        if(hunger == 100){
            cout<<BLUE<<p_name<<" IS COMPLETELY FULL 😋"<<RESET<<endl;
            return;
        }
        while(true){
            display_inv();
            cout<<CYAN<<"ENTER NUMBER OF FOOD ITEM : "<<RESET;
            int food_choice;
            cin>>food_choice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<RED<<"YOU ARE NOT ALLOWED TO ENTER THAT! ⚠️"<<RESET<<endl;
                continue;
            }
            if(food_choice < 1 || food_choice > inv_size){
                cout<<RED<<"WRONG CHOICE. INVALID ITEM NUMBER. ❌"<<RESET<<endl;
                continue;
            }
            int food_idx = food_choice - 1;
            if(Inv_items[food_idx].it_name.empty()){
                cout<<RED<<"WRONG CHOICE. INVALID ITEM NUMBER. ❌"<<RESET<<endl;
                continue;
            }
            if(Inv_items[food_idx].it_is_food == false){
                cout<<RED<<"WRONG CHOICE. "<<Inv_items[food_idx].it_name<<" IS NOT A FOOD ITEM. ❌"<<RESET<<endl;
                continue;
            }
            if(Inv_items[food_idx].it_qty < 1){
                cout<<RED<<"YOU DON'T HAVE ENOUGH "<<Inv_items[food_idx].it_name<<" 🥲"<<RESET<<endl;
                break;
            }
            cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            cout<<CALM_B1<<"FEEDING "<<p_name<<" ...."<<RESET<<endl;
            cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            Inv_items[food_idx].it_qty--;

            int hunger_gain = 0;
            int health_gain = 0;
            if(Inv_items[food_idx].it_price <= 10){
                hunger_gain = 15; 
                health_gain = 3;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
                cout<<CYAN<<p_name<<" HAD A LIGHT SNACK 😋."<<RESET<<endl;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            }
            else if(Inv_items[food_idx].it_price <= 15){
                hunger_gain = 20; 
                health_gain = 5;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
                cout<<CYAN<<p_name<<" HAD A SNACK 😋."<<RESET<<endl;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            }
            else if(Inv_items[food_idx].it_price <= 20){
                hunger_gain = 35; 
                health_gain = 10;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
                cout<<CYAN<<p_name<<" HAD A GOOD MEAL 😋."<<RESET<<endl;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            }
            else{
                hunger_gain = 50; 
                health_gain = 20;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
                cout<<CYAN<<p_name<<" HAD A GREAT MEAL 😋."<<RESET<<endl;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            }

            hunger += hunger_gain;
            health += health_gain;
            cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            cout<<BROWN<<"HUNGER LEVEL INCREASED BY "<<hunger_gain<<"."<<RESET<<endl;
            cout<<GREEN<<"HEALTH INCREASED BY "<<health_gain<<"."<<RESET<<endl;
            cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;

            if(health > 100){
             health = 100; 
            }
            if(hunger > 100){
                hunger = 100;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
                cout<<BLUE<<p_name<<" IS COMPLETELY FULL 😋"<<RESET<<endl;
                cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            }
            display_bars();
            break;
        }
    }

    virtual void predator_attack(){
        if(p_age % 4 != 0 || p_age == 0) return;

        cout<<RED<<"\n⚠️  PREDATOR ATTACK ⚠️"<<RESET<<endl;
        cout<<RED<<"A PREDATOR IS ATTACKING "<<p_name<<"! 🐺"<<RESET<<endl;
        cout<<YELLOW<<"DO YOU WANT TO SAVE "<<p_name<<"? IT WILL COST 20 PP."<<RESET<<endl;
        cout<<CYAN<<"1. YES - SAVE 🛡️ "<<p_name<<" (20 PP)"<<RESET<<endl;
        cout<<CYAN<<"2. NO  - LET "<<p_name<<" GET ATTACKED 💔."<<RESET<<endl;

        int choice;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>choice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<RED<<"YOU ARE NOT ALLOWED TO ENTER THAT! ⚠️"<<RESET<<endl;
                continue;
            }
            if(choice < 1 || choice > 2){
                cout<<RED<<"WRONG CHOICE. ❌"<<RESET<<endl;
                continue;
            }
            break;
        }

        if(choice == 1){
            if(pp < 20){
                cout<<RED<<"NOT ENOUGH PP TO SAVE "<<p_name<<"! 💸"<<RESET<<endl;
                cout<<RED<<"THE PREDATOR ATTACKS "<<p_name<<"! 🐾"<<RESET<<endl;
                health -= 20; if(health < 0) health = 0;
                mood   -= 15; if(mood   < 0) mood   = 0;
                cout<<RED<<"HEALTH -20. MOOD -15."<<RESET<<endl;
            }
            else{
                pp -= 20;
                cout<<GREEN<<"YOU SAVED "<<p_name<<"! 🛡️"<<RESET<<endl;
                cout<<CYAN<<"20 PP DEDUCTED. REMAINING PP : "<<pp<<RESET<<endl;
                mood += 10; if(mood > 100) mood = 100;
                cout<<GREEN<<"MOOD +10."<<RESET<<endl;
                cout<<GREEN<<p_name<<" IS HAPPY THAT YOU SAVED IT 😃 SO YOU ARE REWARDED WITH 50 PP 😎💵."<<RESET<<endl;
                pp += 50;
            }
        }
        else{
            cout<<RED<<"THE PREDATOR ATTACKS "<<p_name<<"! 🐾"<<RESET<<endl;
            health -= 20; if(health < 0) health = 0;
            mood   -= 15; if(mood   < 0) mood   = 0;
            cout<<RED<<"HEALTH -20. MOOD -15."<<RESET<<endl;
        }
        display_bars();
        check_health();
    }

    virtual void show_affection(){
        if(mood >= 50){
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET;
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET;
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET;
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET;
            cout<<"\n              "<<CALM_B1<<"♥♥CUDDLING♥♥ "<<p_name<<" 🤗✨✨."<<RESET<<endl;
            cout<<"             "<<Pink<<p_name<<" is Feeling Loved 🤗💖"<<RESET<<endl;
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET;
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET;
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET;
            cout<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<RED<<"♥"<<RESET<<Pink<<"♥"<<RESET<<endl;
            mood += 20;
            if(mood > 100) mood = 100;
            display_bars();
        }
        else{
            cout<<BLUE<<p_name<<" IS NOT IN A GOOD MOOD RIGHT NOW. 😠"<<RESET<<endl;
            mood -= 10;
            if(mood < 0) mood = 0;
            display_bars();
        }
    }

    virtual void groom(){
        while(true){
            display_inv();
            cout<<CYAN<<"Enter Grooming Item Number : "<<RESET;
            int g_choice;
            cin>>g_choice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<RED<<"YOU ARE NOT ALLOWED TO ENTER THAT ❌"<<RESET<<endl;
                continue;
            }
            if(g_choice < 1 || g_choice > inv_size){
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            int g_idx = g_choice - 1;
            if(Inv_items[g_idx].it_name.empty()){
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            if(Inv_items[g_idx].it_is_groom == false){
                cout<<YELLOW<<"THAT ITEM CANNOT BE USED FOR GROOMING. 😐"<<RESET<<endl;
                continue;
            }
            if(Inv_items[g_idx].it_qty < 1){
                cout<<RED<<"YOU DON'T HAVE ENOUGH "<<Inv_items[g_idx].it_name<<" ❌"<<RESET<<endl;
                break;
            }
            cout<<Pink<<p_name<<" HAS BEEN GROOMED 🧼 WITH "<<Inv_items[g_idx].it_name<<"."<<RESET<<endl;
            cout<<CYAN<<"YOU ARE REWARDED WITH 15 PP BECAUSE "<<p_name<<" IS FEELING HAPPY 😃."<<RESET<<endl;
            pp += 15;
            if(Inv_items[g_idx].it_reusable == false){
                Inv_items[g_idx].it_qty--;
            }
            break;
        }
        display_bars();
    }

    virtual void special_ability() = 0;

    virtual void pet_special_ability() = 0;

    virtual void sleep(){
        if(energy >= 70){
            cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            cout<<CYAN<<p_name<<" IS NOT SLEEPY AT ALL 😎. Try Playing Instead."<<RESET<<endl;
            cout<<CYAN<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            while(true){
                cout<<BLUE<<"WANNA PLAY WITH "<<p_name<<" ? "<<RESET<<endl;
                cout<<GREEN<<"1 - ◽ YES 😃."<<RESET<<endl;
                cout<<RED  <<"2 - ◽ NO  😐."<<RESET<<endl;
                int p_ch;
                cin>>p_ch;
                if(cin.fail() || p_ch < 1 || p_ch > 2){
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout<<YELLOW<<"YOU ARE NOT ALLOWED TO ENTER THAT."<<RESET<<endl;
                    continue;
                }
                if(p_ch == 1){ play(); }
                break;
            }
            return;
        }
        cout<<CYAN<<"▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂"<<RESET<<endl;
        cout<<CYAN<<p_name<<" IS NOW SLEEPING 😴🛏️💤."<<RESET<<endl;
        cout<<GREEN<<"ENERGY RESTORED 😎."<<RESET<<endl;
        energy = 100;
        cout<<GREEN<<"YOU ARE REWARDED WITH 10 PP FOR TAKING CARE OF "<<p_name<<" 💵😃"<<RESET<<endl;
        cout<<CYAN<<"▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂"<<RESET<<endl;
        pp   += 10;
        mood += 35;
        if(mood > 100) mood = 100;
        display_bars();
    }
};