#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Colours.h"
#include"Pet.h"
using namespace std;

void save_game(Pet* p, int pet_type){

    ofstream s("Save.txt",ios::trunc);
    s<<pet_type<<endl;
    s<<p->p_name<<endl;
    s<<p->pp<<endl;
    s<<p->health<<endl;
    s<<p->mood<<endl;
    s<<p->hunger<<endl;
    s<<p->energy<<endl;
    s<<p->p_age<<endl;
    s<<p->p_alive<<endl;
    s<<p->max_age<<endl;
    s.close();

 
    ofstream inv("Inventory.txt",ios::trunc);
    for(int i = 0; i < p->inv_size; i++){
        inv<<p->Inv_items[i].it_qty<<endl;
    }
    inv.close();
    cout<<GREEN<<"GAME SAVED ✅"<<RESET<<endl;
}
void load_game(Pet* p, int& pet_type){
    ifstream s("Save.txt");
    if(!s.is_open()){
        cout<<YELLOW<<"NO SAVE FILE FOUND. ⚠️"<<RESET<<endl;
        return;
    }
    s>>pet_type;
    s.ignore(1000,'\n');
    getline(s, p->p_name);
    s>>p->pp;
    s>>p->health;
    s>>p->mood;
    s>>p->hunger;
    s>>p->energy;
    s>>p->p_age;
    s>>p->p_alive;
    s>>p->max_age;
    s.close();

    ifstream inv("Inventory.txt");
    if(inv.is_open()){
        for(int i = 0;i<p->inv_size;i++){
            inv>>p->Inv_items[i].it_qty;
        }
        inv.close();
    }
    cout<<GREEN<<"GAME LOADED! WELCOME BACK, "<<p->p_name<<" 😃"<<RESET<<endl;
}