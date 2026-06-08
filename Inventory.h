#pragma once
#include<iostream>
#include"Colours.h"
#include<fstream>
using namespace std;

struct Item{
    string it_name;
    int it_price;
    int it_qty;
    bool it_reusable;
    bool it_is_toy;
    bool it_is_food;
    bool it_is_groom;
};

class Inventory{ 
public:
    int pp;
    Item Inv_items[10]={
        {"Basic Food",    15, 5, false, false, true,  false},
        {"Premium Food",  20, 2, false, false, true,  false},
        {"Basic Medicine",15, 5, false, false, false, false},
        {"Prem. Medicine",20, 2, false, false, false, false},
        {"Brush",         15, 1, true,  false, false, true},
    };
    int inv_size=10;

    void disp_store_inv();
    void purchase();

    void display_inv(){
        cout<<CALM_B1<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
        cout<<YELLOW<<"  #  Reusable          Cost    Qty     NAME"<<endl;
        cout<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
        for(int i = 0; i < inv_size; i++){
            if(Inv_items[i].it_name.empty()) continue;
            cout<<" "<<i+1<<"   ";
            cout<<CYAN<<(Inv_items[i].it_reusable ? "YES              " : "NO               ")<<RESET;
            cout<<GREEN<<Inv_items[i].it_price<<" PP\t"<<RESET;
            cout<<Pink<<Inv_items[i].it_qty<<"     "<<RESET;
            cout<<Inv_items[i].it_name<<endl;
        }
        cout<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<endl;
    }

    bool use_inv_f_play(){

        bool any_toy_available = false;
        for(int i = 0; i < inv_size; i++){
            if(Inv_items[i].it_is_toy){
                if(Inv_items[i].it_reusable && Inv_items[i].it_qty >= 1){
                    any_toy_available = true; break;
                }
                if(!Inv_items[i].it_reusable && Inv_items[i].it_qty >= 1){
                    any_toy_available = true; break;
                }
            }
        }
        if(!any_toy_available){
            cout<<YELLOW<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<RED   <<"  NO TOYS AVAILABLE IN INVENTORY! 🧸❌"<<RESET<<endl;
            cout<<CYAN  <<"  PLAYING WITHOUT A TOY INSTEAD... 🐾✨"<<RESET<<endl;
            cout<<YELLOW<<"  (VISIT THE STORE 🛒 TO BUY TOYS FOR BONUS FUN!)"<<RESET<<endl;
            cout<<YELLOW<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            return true;
        }
        while(true){
            display_inv();
            int inv_choice;
            cout<<"Enter The Number Of Item You Want To Use :       (0 to Leave)";
            cin>>inv_choice;
            if(cin.fail() || inv_choice < 1 || inv_choice > inv_size){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<YELLOW<<"INVALID CHOICE TRY AGAIN.. ⚠️"<<RESET<<endl;
                continue;
            }
            int inv_idx = inv_choice - 1;
            if(Inv_items[inv_idx].it_name.empty()){
                cout<<YELLOW<<"INVALID CHOICE TRY AGAIN.. ⚠️"<<RESET<<endl;
                continue;
            }
        if(inv_choice==0){
            break;
        }
            if(Inv_items[inv_idx].it_is_toy == true){
                if(Inv_items[inv_idx].it_reusable == false){
                    if(Inv_items[inv_idx].it_qty < 1){
                        cout<<RED<<"YOU DON'T HAVE ENOUGH "<<Inv_items[inv_idx].it_name<<" 🥲"<<RESET<<endl;
                        cout<<CYAN<<"VISIT THE STORE FOR UPDATING INVENTORY 🛒."<<RESET<<endl;
                        return false;   
                    }
                    Inv_items[inv_idx].it_qty -= 1;
                    break;
                }
                cout<<CYAN<<"Playing With "<<Inv_items[inv_idx].it_name<<RESET<<endl;
                return true;   
            }
            else{
                cout<<Pink<<"You Can't Use This Item For Playing."<<RESET<<endl;
                continue;
            }
        }
    }
};