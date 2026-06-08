#pragma once
#include<iostream>
#include<string> 
#include<random>
#include"Colours.h"
#include"Pet.h"
using namespace std;


class Cat : public Pet {
public:
    Cat(){
        pp = 150;
        max_age = 40;
        Inv_items[5] = {"Fake Mouse",    15, 0, true,  true,  false, false};
        Inv_items[6] = {"Cat Shampoo",   15, 0, false, false, false, true };
        Inv_items[7] = {"Laser Toy",     10, 0, true,  true,  false, false};
        Inv_items[8] = {"Cat Nip",       15, 0, false, false, true,  false};
        Inv_items[9] = {"Feather Stick", 10, 0, true,  true,  false, false};
        set_pet_face("😺");
    }

    void special_ability() override {
        if(mood >= 50){
            string special_abilities[3] = {
                " JUST CAUGHT A MOUSE 🐭😂.",
                " IS PURRING 😻.",
                " IS GROOMING ITSELF 🪮."
            };
            random_device scroll;
            mt19937 choose_ability(scroll());
            uniform_int_distribution<int> choose(0, 2);
            int run = choose(choose_ability);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"      "<<p_name<<special_abilities[run]<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        }
        else{
            cout<<YELLOW<<p_name<<" IS NOT INTERESTED RIGHT NOW."<<RESET<<endl;
            cout<<GREEN<<"TRY SHOWING "<<p_name<<" SOME AFFECTION."<<RESET<<endl;
        }
    }

    
    void pet_special_ability() override {
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"       ✨ "<<p_name<<"'S SPECIAL ABILITIES ✨ 😺"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN  <<"  1. Random Trick    🎲"<<RESET<<endl;
        cout<<BLUE   <<"  2. Catnap 😴💤  (Restores mood & energy a little)"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        int ch;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>ch;
            if(cin.fail()||ch<1||ch>2){
                cin.clear(); cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(ch==1){
            special_ability();
        }
        else{
            if(mood < 50){
                cout<<YELLOW<<p_name<<" IS TOO GRUMPY TO NAP RIGHT NOW. 😾"<<RESET<<endl;
                cout<<GREEN<<"SHOW SOME AFFECTION FIRST! 💖"<<RESET<<endl;
                return;
            }
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<Pink   <<"  "<<p_name<<" CURLS INTO A TINY BALL... 🐱💤"<<RESET<<endl;
            cout<<CYAN   <<"  ZZZzzz... ZZZzzz..."<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            mood   += 15; 
            if(mood   > 100){
                mood   = 100;
            }
            energy += 15; 
            if(energy > 100){
                energy = 100;
            }
            cout<<GREEN<<"MOOD +15  |  ENERGY +15  😸"<<RESET<<endl;
            display_bars();
        }
    }
};

class Dog : public Pet {
public:
    Dog(){
        pp = 150;
        max_age = 35;
        Inv_items[5] = {"Chewing Bone",    15, 0, true,  true,  false, false};
        Inv_items[6] = {"Dog Shampoo",     15, 0, false, false, false, true };
        Inv_items[7] = {"Frisbee Toy",     20, 0, true,  true,  false, false};
        Inv_items[8] = {"Beef Treats",     15, 0, false, false, true,  false};
        Inv_items[9] = {"Throwing Ball",   10, 0, true,  true,  false, false};
        set_pet_face("🐶");
    }

    void special_ability() override {
        if(mood >= 50){
            string special_abilities[3] = {
                " CHASED ITS OWN TAIL FURIOUSLY! 🐕🌀",
                " BROUGHT YOU A TENNIS BALL! 🎾",
                " ALMOST THOUGHT IT WAS A RABBIT AND STARTED JUMPING! 🐾"
            };
            random_device scroll;
            mt19937 choose_ability(scroll());
            uniform_int_distribution<int> choose(0, 2);
            int run = choose(choose_ability);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"      "<<p_name<<special_abilities[run]<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        }
        else{
            cout<<YELLOW<<p_name<<" IS NOT INTERESTED RIGHT NOW."<<RESET<<endl;
            cout<<GREEN<<"TRY SHOWING "<<p_name<<" SOME AFFECTION."<<RESET<<endl;
        }
    }

    void pet_special_ability() override {
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"       ✨ "<<p_name<<"'S SPECIAL ABILITIES ✨ 🐶"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN  <<"  1. Random Trick    🎲"<<RESET<<endl;
        cout<<BLUE   <<"  2. Teach a Trick   🎓 (Sit / Shake / Roll Over)"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        int ch;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>ch;
            if(cin.fail()||ch<1||ch>2){
                cin.clear(); cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(ch==1){
            special_ability();
        }
        else{
            if(mood < 50){
                cout<<YELLOW<<p_name<<" IS TOO GRUMPY TO LEARN RIGHT NOW. 😒"<<RESET<<endl;
                cout<<GREEN<<"SHOW SOME AFFECTION FIRST! 💖"<<RESET<<endl;
                return;
            }
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN   <<"  CHOOSE A TRICK TO TEACH "<<p_name<<" :"<<RESET<<endl;
            cout<<GREEN  <<"  1. SIT   🐕"<<RESET<<endl;
            cout<<YELLOW <<"  2. SHAKE 🤝"<<RESET<<endl;
            cout<<Pink   <<"  3. ROLL OVER 🔄"<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            int trick;
            while(true){
                cout<<CYAN<<"ENTER CHOICE : "<<RESET;
                cin>>trick;
                if(cin.fail()||trick<1||trick>3){
                    cin.clear(); cin.ignore(1000,'\n');
                    cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                    continue;
                }
                break;
            }
            string tricks[3] = {"SIT 🐕","SHAKE 🤝","ROLL OVER 🔄"};
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN   <<"  "<<p_name<<" : ......"<<RESET<<endl;
            cout<<GREEN  <<"  "<<p_name<<" SUCCESSFULLY DID "<<tricks[trick-1]<<"! 🎉"<<RESET<<endl;
            cout<<CYAN   <<"  GOOD BOY/GIRL! 🦴"<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            mood   += 20; 
            if(mood   > 100){
                mood = 100;
            }
            energy -= 10; 
            if(energy <   0){
                energy = 0;
            }
            pp+=10;
            cout<<GREEN<<"MOOD +20  |  ENERGY -10  |  PP +10 💵"<<RESET<<endl;
            display_bars();
        }
    }
};

class Horse : public Pet {
public:
    Horse(){
        pp = 200;
        max_age = 60;
        Inv_items[5] = {"Crunchy Carrot",      10, 0, false, false, true,  false};
        Inv_items[6] = {"Horse Special Brush",  15, 0, true,  false, false, true };
        Inv_items[7] = {"Hay Bale",             15, 0, false, false, true,  false};
        Inv_items[8] = {"Horseshoes",           30, 0, true,  true,  false, false};
        Inv_items[9] = {"Fancy Saddle",         50, 0, true,  true,  false, false};
        set_pet_face("🐴");
    }

    void running(){
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN<<p_name<<" IS RUNNING."<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
    }

    void special_ability() override {
        if(mood >= 50){
            string special_abilities[3] = {
                " RUNNING AROUND THE FIELD! 🐎",
                " NEIGHED PROUDLY AT THE SKY! 🐴🔊",
                " DID A GENTLE NUDGE ON YOUR SHOULDER. 🥕"
            };
            random_device scroll;
            mt19937 choose_ability(scroll());
            uniform_int_distribution<int>choose(0, 2);
            int run=choose(choose_ability);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"      "<<p_name<<special_abilities[run]<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        }
        else{
            cout<<YELLOW<<p_name<<" IS NOT INTERESTED RIGHT NOW."<<RESET<<endl;
            cout<<GREEN<<"TRY SHOWING "<<p_name<<" SOME AFFECTION."<<RESET<<endl;
        }
    }


    void pet_special_ability() override {
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"       ✨ "<<p_name<<"'S SPECIAL ABILITIES ✨ 🐴"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN  <<"  1. Random Trick    🎲"<<RESET<<endl;
        cout<<BLUE   <<"  2. Race! 🏇        (Sprint across the field)"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        int ch;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>ch;
            if(cin.fail()||ch<1||ch>2){
                cin.clear(); 
                cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(ch==1){
            special_ability();
        }
        else{
            if(energy < 30){
                cout<<YELLOW<<p_name<<" IS TOO TIRED TO RACE! 😓 LET IT REST FIRST."<<RESET<<endl;
                return;
            }
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN   <<"  CHOOSE RACE DISTANCE :"<<RESET<<endl;
            cout<<GREEN  <<"  1. SHORT SPRINT  (100m) 💨"<<RESET<<endl;
            cout<<YELLOW <<"  2. MEDIUM RACE   (500m) 🏇"<<RESET<<endl;
            cout<<Pink   <<"  3. FULL GALLOP  (1000m) 🏆"<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            int dist;
            while(true){
                cout<<CYAN<<"ENTER CHOICE : "<<RESET;
                cin>>dist;
                if(cin.fail()||dist<1||dist>3){
                    cin.clear(); cin.ignore(1000,'\n');
                    cout<<YELLOW<<"INVALID CHOICE ,YOU ARE NOT ALLOWED TO ENTER THAT⚠️."<<RESET<<endl;
                    continue;
                }
                break;
            }
            string dist_names[3] = {"100M RACE 💨","500M RACE 🏇","1KM RACE 🏆"};
            int energy_cost[3]   = {15, 30, 50};
            int pp_reward[3]     = {20, 40, 70};
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"  "<<p_name<<" DASHES INTO THE "<<dist_names[dist-1]<<"!"<<RESET<<endl;
            cout<<BROWN<<"  🐴💨 ... ... ... 🏁"<<RESET<<endl;
            bool won=true;
            if(dist>1){
                random_device rd; 
                mt19937 gen(rd());
                uniform_int_distribution<int>coin(0,1);
                won=coin(gen);
            }
            if(won){
                cout<<GREEN<<"  "<<p_name<<" WINS THE RACE! 🏆🎉"<<RESET<<endl;
                cout<<GREEN<<"  PP REWARD : +"<<pp_reward[dist-1]<<" PP 💵"<<RESET<<endl;
                pp += pp_reward[dist-1];
                mood += 20; if(mood > 100) mood = 100;
            }
            else{
                cout<<YELLOW<<"  "<<p_name<<" GAVE IT EVERYTHING BUT CAME SECOND! 🥈"<<RESET<<endl;
                cout<<CYAN  <<"  PP REWARD : +"<<pp_reward[dist-1]/2<<" PP 💵"<<RESET<<endl;
                pp += pp_reward[dist-1]/2;
                mood += 10; if(mood > 100) mood = 100;
            }
            energy -= energy_cost[dist-1]; if(energy < 0) energy = 0;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            display_bars();
        }
    }
};

class Sparrow : public Pet {
public:
    Sparrow(){
        pp = 100;
        max_age = 20;
        Inv_items[5] = {"Bird Seeds",     10, 0, false, false, true,  false};
        Inv_items[6] = {"Bird Bath Bowl", 20, 0, true,  false, false, true };
        Inv_items[7] = {"Small Mirror",   10, 0, true,  true,  false, false};
        Inv_items[8] = {"Dried Worms",    10, 0, false, false, true,  false};
        Inv_items[9] = {"Swing",          15, 0, true,  true,  false, false};
        set_pet_face("🐦");
    }

    void special_ability() override {
        if(mood >= 50){
            string special_abilities[3] = {
                " SANG SOMETHING! 🎶🐦",
                " CHIRPED AND FLAPPED ITS WINGS! ✨",
                " SAT GENTLY ON YOUR FINGER! 👉"
            };
            random_device scroll;
            mt19937 choose_ability(scroll());
            uniform_int_distribution<int> choose(0, 2);
            int run = choose(choose_ability);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"      "<<p_name<<special_abilities[run]<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        }
        else{
            cout<<YELLOW<<p_name<<" IS NOT INTERESTED RIGHT NOW."<<RESET<<endl;
            cout<<GREEN<<"TRY SHOWING "<<p_name<<" SOME AFFECTION."<<RESET<<endl;
        }
    }

    void pet_special_ability() override {
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"       ✨ "<<p_name<<"'S SPECIAL ABILITIES ✨ 🐦"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN  <<"  1. Random Trick    🎲"<<RESET<<endl;
        cout<<BLUE   <<"  2. Whistle Duel 🎵 (Whistle a tune, "<<p_name<<" copies!)"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        int ch;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>ch;
            if(cin.fail()||ch<1||ch>2){
                cin.clear(); cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(ch==1){
            special_ability();
        }
        else{
            if(mood < 50){
                cout<<YELLOW<<p_name<<" IS NOT IN THE MOOD TO SING. 😶"<<RESET<<endl;
                cout<<GREEN<<"SHOW SOME AFFECTION FIRST! 💖"<<RESET<<endl;
                return;
            }
            cout<<CYAN<<"  TYPE YOUR WHISTLE (e.g. tweet-tweet, too-whit) : "<<RESET;
            string whistle;
            cin.ignore(1000,'\n');
            getline(cin,whistle);
            if(whistle.empty()) whistle = "chii-chii";
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"  YOU    : "<<whistle<<" 🎵"<<RESET<<endl;
            cout<<Pink<<"  "<<p_name<<" : "<<whistle<<" 🐦🎵"<<RESET<<endl;
            cout<<GREEN<<"  "<<p_name<<" COPIED YOU PERFECTLY! WHAT A SMART BIRD! 🧠"<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            mood += 15; 
            if(mood > 100){
                mood = 100;
            }
            pp+=10;
            cout<<GREEN<<"MOOD +15  |  PP +10 💵"<<RESET<<endl;
            display_bars();
        }
    }
};

class Parrot : public Pet {
public:
    Parrot(){
        pp = 130;
        max_age = 80;
        Inv_items[5] = {"Chili",          10, 0, false, false, true,  false};
        Inv_items[6] = {"Feather Spray",  20, 0, false, false, false, true };
        Inv_items[7] = {"Chew Stick",     15, 0, true,  true,  false, false};
        Inv_items[8] = {"Walnut Mix",     20, 0, false, false, true,  false};
        Inv_items[9] = {"Companion Toy",  25, 0, true,  true,  false, false};
        set_pet_face("🦜");
    }

    void special_ability() override {
        if(mood >= 50){
            string special_abilities[3] = {
                " SCREAMED! 🗣️",
                " TRIED TO FLY BUT FAILED 😂",
                " JUMPED ON YOU! 😂"
            };
            random_device scroll;
            mt19937 choose_ability(scroll());
            uniform_int_distribution<int> choose(0, 2);
            int run = choose(choose_ability);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"      "<<p_name<<special_abilities[run]<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        }
        else{
            cout<<YELLOW<<p_name<<" IS NOT INTERESTED RIGHT NOW."<<RESET<<endl;
            cout<<GREEN<<"TRY SHOWING "<<p_name<<" SOME AFFECTION."<<RESET<<endl;
        }
    }

    
    void pet_special_ability() override {
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"       ✨ "<<p_name<<"'S SPECIAL ABILITIES ✨ 🦜"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN  <<"  1. Random Trick    🎲"<<RESET<<endl;
        cout<<BLUE   <<"  2. Talk! 🗣️        (Speak to "<<p_name<<", it repeats you!)"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        int ch;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>ch;
            if(cin.fail()||ch<1||ch>2){
                cin.clear(); cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(ch==1){
            special_ability();
        }
        else{
            if(mood < 50){
                cout<<YELLOW<<p_name<<" IS NOT IN THE MOOD TO TALK. 😶"<<RESET<<endl;
                cout<<GREEN<<"SHOW SOME AFFECTION FIRST! 💖"<<RESET<<endl;
                return;
            }
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"SPEAK SOMETHING TO "<<p_name<<" : "<<RESET;
            string Talk;
            cin.ignore(1000,'\n');
            getline(cin,Talk);
            if(Talk.empty()) Talk = "Hello!";
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            for(int t = 0; t < 3; t++){
                cout<<CYAN<<p_name<<" SAYS : "<<Talk<<" 🦜"<<RESET<<endl;
            }
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            mood += 10; if(mood > 100) mood = 100;
            pp   += 5;
            cout<<GREEN<<"MOOD +10  |  PP +5 💵"<<RESET<<endl;
            display_bars();
        }
    }
};

class Rabbit : public Pet {
public:
    Rabbit(){
        pp = 120;
        max_age = 15;
        Inv_items[5] = {"Carrot",               10, 0, false, false, true,  false};
        Inv_items[6] = {"Hair Groomer",          15, 0, true,  false, false, true };
        Inv_items[7] = {"Chew Wood",             10, 0, true,  true,  false, false};
        Inv_items[8] = {"Fresh Lettuce",         10, 0, false, false, true,  false};
        Inv_items[9] = {"Small Plastic Tunnel",  30, 0, true,  true,  false, false};
        set_pet_face("🐰");
    }

    void special_ability() override {
        if(mood >= 50){
            string special_abilities[3] = {
                " JUMPED HIGH! 🐰",
                " RAN SO FAST! 🏃🏼‍♀️‍➡️🐰",
                " LAID ON THE GROUND 😴"
            };
            random_device scroll;
            mt19937 choose_ability(scroll());
            uniform_int_distribution<int> choose(0, 2);
            int run = choose(choose_ability);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"      "<<p_name<<special_abilities[run]<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        }
        else{
            cout<<YELLOW<<p_name<<" IS NOT INTERESTED RIGHT NOW."<<RESET<<endl;
            cout<<GREEN<<"TRY SHOWING "<<p_name<<" SOME AFFECTION."<<RESET<<endl;
        }
    }

 
    void pet_special_ability() override {
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"       ✨ "<<p_name<<"'S SPECIAL ABILITIES ✨ 🐰"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN  <<"  1. Random Trick    🎲"<<RESET<<endl;
        cout<<BLUE   <<"  2. Binky! 🎊       ("<<p_name<<" does happy joy jumps!)"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        int ch;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>ch;
            if(cin.fail()||ch<1||ch>2){
                cin.clear(); cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(ch==1){
            special_ability();
        }
        else{
            if(mood < 50){
                cout<<YELLOW<<p_name<<" IS TOO SAD TO BINKY. 😢"<<RESET<<endl;
                cout<<GREEN<<"SHOW SOME AFFECTION FIRST! 💖"<<RESET<<endl;
                return;
            }
            if(energy < 20){
                cout<<YELLOW<<p_name<<" IS TOO TIRED TO BINKY. 😪 LET IT REST."<<RESET<<endl;
                return;
            }
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<Pink <<"  "<<p_name<<" : 🐰💨  *ZOOOM* 🐰💨  *LEAP* 🐰🌀  *TWIST*"<<RESET<<endl;
            cout<<GREEN<<"  "<<p_name<<" IS BINKYING WITH PURE JOY! 🎊🎉"<<RESET<<endl;
            cout<<CYAN <<"  A BINKYING RABBIT MEANS A VERY HAPPY RABBIT! 💖"<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            mood   += 25; if(mood   > 100) mood   = 100;
            energy -= 15; if(energy <   0) energy = 0;
            pp     += 15;
            cout<<GREEN<<"MOOD +25  |  ENERGY -15  |  PP +15 💵"<<RESET<<endl;
            display_bars();
        }
    }
};

class Hen : public Pet {
public:
    Hen(){
        pp = 90;
        max_age = 10;
        Inv_items[5] = {"Corn",             10, 0, false, false, true,  false};
        Inv_items[6] = {"Sand",             15, 0, false, false, false, true };
        Inv_items[7] = {"Nesting Material", 10, 0, true,  true,  false, false};
        Inv_items[8] = {"Worms",            10, 0, false, false, true,  false};
        Inv_items[9] = {"Fake Worms",       15, 0, true,  true,  false, false};
        set_pet_face("🐔");
    }

    void special_ability() override {
        if(mood >= 50){
            string special_abilities[3] = {
                " CLUCKED EXTREMELY LOUDLY! 🐔🔊",
                " LAID A FRESH EGG! 🥚",
                " PECKED AT THE DUST LOOKING FOR BUGS! 🐛"
            };
            random_device scroll;
            mt19937 choose_ability(scroll());
            uniform_int_distribution<int> choose(0, 2);
            int run = choose(choose_ability);
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"      "<<p_name<<special_abilities[run]<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        }
        else{
            cout<<YELLOW<<p_name<<" IS NOT INTERESTED RIGHT NOW."<<RESET<<endl;
            cout<<GREEN<<"TRY SHOWING "<<p_name<<" SOME AFFECTION."<<RESET<<endl;
        }
    }

   
    void pet_special_ability() override {
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<CYAN   <<"       ✨ "<<p_name<<"'S SPECIAL ABILITIES ✨ 🐔"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        cout<<GREEN  <<"  1. Random Trick    🎲"<<RESET<<endl;
        cout<<BLUE   <<"  2. Collect Eggs 🥚 (Sell eggs for PP!)"<<RESET<<endl;
        cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
        int ch;
        while(true){
            cout<<CYAN<<"ENTER CHOICE : "<<RESET;
            cin>>ch;
            if(cin.fail()||ch<1||ch>2){
                cin.clear(); cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE ⚠️."<<RESET<<endl;
                continue;
            }
            break;
        }
        if(ch==1){
            special_ability();
        }
        else{
            if(hunger < 30){
                cout<<YELLOW<<p_name<<" IS TOO HUNGRY TO LAY EGGS. 🍗 FEED IT FIRST!"<<RESET<<endl;
                return;
            }
            if(mood < 50){
                cout<<YELLOW<<p_name<<" IS TOO UNHAPPY TO LAY EGGS RIGHT NOW. 😔"<<RESET<<endl;
                cout<<GREEN<<"SHOW SOME AFFECTION FIRST! 💖"<<RESET<<endl;
                return;
            }
  
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> egg_roll(1,4);
            int eggs = egg_roll(gen);
            int earned = eggs * 12;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<CYAN<<"  "<<p_name<<" CLUCKS AND HEADS TO THE NEST... 🐔"<<RESET<<endl;
            cout<<YELLOW<<"  🥚";
            for(int e=1;e<eggs;e++){
                cout<<" 🥚";
            }
            cout<<RESET<<endl;
            cout<<GREEN<<"  "<<p_name<<" LAID "<<eggs<<" EGG(S)! YOU SOLD THEM FOR "<<earned<<" PP! 💵"<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            pp     += earned;
            hunger -= 10; 
            if(hunger < 0) hunger = 0;
            cout<<GREEN<<"PP +"<<earned<<"  |  HUNGER -10"<<RESET<<endl;
            display_bars();
        }
    }
};