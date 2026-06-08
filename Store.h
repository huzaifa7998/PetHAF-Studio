#pragma once
#include<iostream>
#include"Inventory.h"
#include"Colours.h"
using namespace std;

void Inventory::disp_store_inv(){
    cout<<CALM_B1<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
    cout<<YELLOW<<"  #  Reusable          Cost        NAME"<<endl;
    cout<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
    for(int i = 0; i < inv_size; i++){
        if(Inv_items[i].it_name.empty()) continue;
        cout<<" "<<i+1<<"   ";
        cout<<CYAN<<(Inv_items[i].it_reusable ? "YES              " : "NO               ")<<RESET;
        cout<<GREEN<<Inv_items[i].it_price<<" PP\t"<<RESET;
        if(Inv_items[i].it_reusable && Inv_items[i].it_qty >= 1){
            cout<<YELLOW<<"[OWNED] "<<RESET;
        }
        cout<<Inv_items[i].it_name<<endl;
    }
    cout<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<endl;
}   

void Inventory::purchase(){
    cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
    cout<<CYAN<<"   WELCOME TO PETHAF INVENTORY STORE 🏪🛒."<<RESET<<endl;
    cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;

    while(true){
        disp_store_inv();
        cout<<CYAN<<"YOUR PP : "<<pp<<RESET<<endl;
        cout<<CYAN<<"ENTER THE ITEM NUMBER YOU WANNA BUY (0 to Exit): "<<RESET;
        int buy_ch;
        cin>>buy_ch;
        if(cin.fail() || buy_ch < 0 || buy_ch > inv_size){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<YELLOW<<"YOU ARE NOT ALLOWED TO ENTER THAT ⚠️."<<RESET<<endl;
            continue;
        }
        if(buy_ch == 0){
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            cout<<Pink<<" Thank YOU FOR SHOPPING FOR YOUR PET. 🛒😃          "<<RESET<<endl;
            cout<<CALM_B1<<"▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱"<<RESET<<endl;
            break;
        }
        int inv_idx = buy_ch - 1;
        if(Inv_items[inv_idx].it_name.empty()){
            cout<<YELLOW<<"THAT ITEM DOES NOT EXIST ⚠️."<<RESET<<endl;
            continue;
        }
        if(Inv_items[inv_idx].it_reusable && Inv_items[inv_idx].it_qty >= 1){
            cout<<BLACK<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            cout<<YELLOW<<"    YOU ALREADY OWN "<<Inv_items[inv_idx].it_name<<". REUSABLE ITEMS CAN ONLY BE BOUGHT ONCE. 🔒"<<RESET<<endl;
            cout<<BLACK<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            continue;
        }
        cout<<CALM_B1<<"▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫"<<RESET<<endl;
        cout<<BLUE<<"        - - - - - - - PROCESSING YOUR PURCHASE - - - - - - -"<<RESET<<endl;
        cout<<CALM_B1<<"▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫▫"<<RESET<<endl;
        if(Inv_items[inv_idx].it_price > pp){
            cout<<BLACK<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            cout<<RED<<"    SORRY, YOU HAVE INSUFFICIENT PP FOR THIS PURCHASE 💳💸.    "<<RESET<<endl;
            cout<<BLACK<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
            continue;  
        }
        pp-=Inv_items[inv_idx].it_price;
        Inv_items[inv_idx].it_qty++;

        cout<<BLACK<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
        cout<<GREEN<<"  "<<Inv_items[inv_idx].it_name<<" PURCHASED SUCCESSFULLY 😃💳 FOR "<<Inv_items[inv_idx].it_price<<" PP."<<RESET<<endl;
        cout<<GREEN<<"REMAINING PP : "<<pp<<RESET<<endl;
        cout<<BLACK<<"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬"<<RESET<<endl;
    }
}