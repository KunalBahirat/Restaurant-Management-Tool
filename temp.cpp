#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class Hotel{
                  // id      name   price
    unordered_map <int,pair<string,int>> item_details;
                  // it type   ids
    unordered_map <string,list<int>> menu;
    public:
        Hotel(){
            string it_type1="Starters";
            int id,price;string name; list<int> id_it_type_1;
              id=101; name="Crispy Corn"; price=170.00; item_details.insert({id,{name,price}});id_it_type_1.push_back(id);
              id=102; name="Veg Spring Rolls"; price=150.00;  item_details.insert({id,{name,price}});id_it_type_1.push_back(id);
              id=103; name="Chilly Paneer"; price=180.00;   item_details.insert({id,{name,price}});id_it_type_1.push_back(id);
            
            string it_type2="Veg Main"; list<int> id_it_type_2;
             id=201;name="Tomato Curry";price=160;  item_details.insert({id,{name,price}});id_it_type_2.push_back(id);
             id=202;name="Aloo Mutter";price=160;  item_details.insert({id,{name,price}});id_it_type_2.push_back(id);
             id=203;name="Kadai Paneer";price=220;  item_details.insert({id,{name,price}});id_it_type_2.push_back(id);

            string it_type3="Non Veg Main"; list<int> id_it_type_3;
             ;id=301;name="Ginger Chicken";price=190;  item_details.insert({id,{name,price}});id_it_type_3.push_back(id);
             ;id=302;name="Mutton Curry";price=300;  item_details.insert({id,{name,price}});id_it_type_3.push_back(id);
             ;id=303;name="Fish Fry";price=280;  item_details.insert({id,{name,price}});id_it_type_3.push_back(id);

            string it_type4="Tiffin"; list<int> id_it_type_4;
             id=401;name="Rava Dosa";price=60;  item_details.insert({id,{name,price}});id_it_type_4.push_back(id);
             id=402;name="Onion Pesara";price=60;  item_details.insert({id,{name,price}});id_it_type_4.push_back(id);
             id=403;name="Upma";price=80;  item_details.insert({id,{name,price}});id_it_type_4.push_back(id);  

            string it_type5="Rotis"; list<int> id_it_type_5;
             id=501;name="Roomal Roti";price=20;  item_details.insert({id,{name,price}});id_it_type_5.push_back(id);
             id=502;name="Chapati";price=20;  item_details.insert({id,{name,price}});id_it_type_5.push_back(id);
             id=503;name="Paratha";price=40;  item_details.insert({id,{name,price}});id_it_type_5.push_back(id);

             menu.insert({it_type1,id_it_type_1}) ;         
             menu.insert({it_type2,id_it_type_2}) ;         
             menu.insert({it_type3,id_it_type_3}) ;         
             menu.insert({it_type4,id_it_type_4}) ;         
             menu.insert({it_type5,id_it_type_5}) ;         
        }
        void add_to_menu(){
            system("cls");
            cout<<"\t\tHotel Grand Food\n";
            cout<<"--------Add To The Menu--------\n";
            string it_type;string it_name;int id;int price;
            cout<<"Enter Food Item Type to add \n";
            int i=1;
            cout<<i++<<" "<<"Starters"<<"\n";
            cout<<i++<<" "<<"Veg Main"<<"\n";
            cout<<i++<<" "<<"Non Veg Main"<<"\n";
            cout<<i++<<" "<<"Tiffin"<<"\n";
            cin>>i;
            while(i<0 or i>4 ){
                cout<<"Enter Valid Food Item Type :";
                cin>>i;
            }
            if(i==1){
                it_type="Starters";
            }
            if(i==2){
                it_type="Veg Main";
            }
            if(i==3){
                it_type="Non Veg Main";
            }
            if(i==4){
                it_type="Tiffin";
            }
            cout<<"Enter  Name ";
            cin.ignore();
            getline(cin,it_name);
            // cin>>it_name;
            cout<<"Enter  ID ";
            cin>>id;
            while(item_details.find(id)!=item_details.end()){
                cout<<"Enter Valid ID ";
                cin>>id;
            }
            cout<<"Enter  Price ";
            cin>>price;
            auto it=menu.find(it_type);
            if(it!=menu.end()){
                it->second.push_back(id);
            }
            item_details.insert({id,{it_name,price}});

        }
        void show_menu(){
            auto it=menu.begin();
            cout<<"----------------------------------Today's Menu----------------------------------\n";
            // bool p=false;
            while(it!=menu.end()){
                // if(!p){
                    cout<<(it->first)<<"\n";
                    // p=true;
                // }
                cout<<"\n"<<setw(10)<<"ID"<<setw(20)<<" NAME"<<setw(20)<<"PRICE\n";
                auto it2=it->second.begin();
                while(it2!=it->second.end()){
                    cout<<setw(10)<<*it2<<setw(20)<<item_details[*it2].first<<setw(20)<<item_details[*it2].second<<"\n";
                    it2++;
                }
                // p=false;
                it++;
            }
        }
        void order_food(){
            cout<<"\t\tHotel Grand Food\n";
            int id,quantity;
            int table_no,total_amt=0;
            cout<<"Enter Table Number : ";
            cin>>table_no;
            ofstream ord;
            ord.open("order table "+to_string(table_no),ios::app);
            ord<<"Item ID"<<setw(30)<<"Item Name"<<setw(30)<<"Quantity"<<setw(30)<<"Amount\n";
            ord<<"---------------------------------------------------------------------------------------------------------\n";
            cout<<"Enter Item ID : ";
            cin>>id;
            while(id!=-1){
                while(item_details.find(id)==item_details.end()){
                    cout<<"Enter Valid Item ID : ";
                    cin>>id;
                }
                cout<<"Enter Quantity of "<<item_details[id].first<<" : ";
                cin>>quantity;
                ord<<id<<setw(35)<<item_details[id].first<<setw(30)<<quantity<<setw(30)<<quantity*item_details[id].second<<endl;
                total_amt+=quantity*item_details[id].second;
                cout<<"Enter Item ID : ";
                cin>>id;
            }
            ord<<"---------------------------------------------------------------------------------------------------------\n";
            ord<<" Thank You!                                                                       TOTAL: "<<total_amt<<"/-\n";
            
        }

};
int main(){
    Hotel grandFood;
    grandFood.show_menu();
    // grandFood.add_to_menu();
    // grandFood.show_menu();
    grandFood.order_food();

    return 0;
}