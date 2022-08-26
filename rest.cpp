#include <bits/stdc++.h>
//#include <unordered_map>
#include "welcome.h"
char key;
int program_stop=false;
const std::string currentDateTime() {       // fun to get date and time => putting in database
   time_t     now = time(0);
   struct tm  tstruct;
   char       buf[80];
   tstruct = *localtime(&now);
   // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
   // for more information about date/time format
   strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

   return buf;
}
class Item{
   friend class Hotel;
   string item_name;
   int id;
   double price;
};
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
           std::cout<<"\t\tHotel Grand Food\n";
           std::cout<<"--------Add To The Menu--------\n";
           string it_type;string it_name;int id;int price;
           std::cout<<"Enter Food Item Type to add \n";
           int i=1;
           std::cout<<i++<<" "<<"Starters"<<"\n";
           std::cout<<i++<<" "<<"Veg Main"<<"\n";
           std::cout<<i++<<" "<<"Non Veg Main"<<"\n";
           std::cout<<i++<<" "<<"Tiffin"<<"\n";
           cin>>i;
           while(i<0 or i>4 ){
               std::cout<<"Enter Valid Food Item Type :";
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
           std::cout<<"Enter  Name ";
           cin.ignore();
           getline(cin,it_name);
           // cin>>it_name;
           std::cout<<"Enter  ID ";
           cin>>id;
           while(item_details.find(id)!=item_details.end()){
               std::cout<<"Enter Valid ID ";
               cin>>id;
           }
           std::cout<<"Enter  Price ";
           cin>>price;
           auto it=menu.find(it_type);
           if(it!=menu.end()){
               it->second.push_back(id);
           }
           item_details.insert({id,{it_name,price}});

       }
       void show_menu(){
           auto it=menu.begin();
           std::cout<<"----------------------------------Today's Menu----------------------------------\n";
           // bool p=false;
           while(it!=menu.end()){
               std::cout<<(it->first)<<"\n";
               std::cout<<"\n"<<setw(10)<<"ID"<<setw(20)<<" NAME"<<setw(20)<<"PRICE\n";
               auto it2=it->second.begin();
               while(it2!=it->second.end()){
                   std::cout<<setw(10)<<*it2<<setw(20)<<item_details[*it2].first<<setw(20)<<item_details[*it2].second<<"\n";
                   it2++;
               }
               it++;
           }
       }
       void order_food(){
           system("cls");
           std::cout<<"\t\tHotel Grand Food\n";
           int id,quantity;
           int table_no,total_amt=0;
           std::cout<<"Enter Table Number : ";
           cin>>table_no;
           ofstream ord;ofstream dt_base;
           dt_base.open("Database",ios::app);
           ord.open("order table "+to_string(table_no),ios::app);
           ord<<"\nItem ID"<<setw(30)<<"Item Name"<<setw(30)<<"Quantity"<<setw(33)<<"Amount\n";
           ord<<"---------------------------------------------------------------------------------------------------------\n";
           std::cout<<"Enter Item ID : ";
           cin>>id;
           while(id!=-1){
               while(item_details.find(id)==item_details.end()){
                   std::cout<<"Enter Valid Item ID : ";
                   cin>>id;
               }
               std::cout<<"Enter Quantity of "<<item_details[id].first<<" : ";
               cin>>quantity;
               ord<<id<<setw(35)<<item_details[id].first<<setw(30)<<quantity<<setw(30)<<quantity*item_details[id].second<<endl;
               total_amt+=quantity*item_details[id].second;


               dt_base <<currentDateTime()<< setw(15) <<id<<setw(30)<<item_details[id].first <<setw(30)<<quantity<<"\n";


               std::cout<<"Enter Item ID : ";
               cin>>id;
           }
           ord<<"---------------------------------------------------------------------------------------------------------\n";
           ord<<" Thank You!                                                                          TOTAL: "<<total_amt<<"/-\n";
           
       }

};
char user(){
	coordxy(50,6); std::cout<<"----------- Wait a minute! Who are you ? -----------";
    coordxy(50,10);    std::cout<<"a)\tFoodie";
    coordxy(50,12);    std::cout<<"bc)\tManager";
    coordxy(50,14);    std::cout<<"c)\tAdmin";
    coordxy(50,18);    std::cout<<"You can respond using key a or b or c";
     key=getch() ;
    coordxy(52,20); std::cout<<"=> "<<key;
    return key;
}
bool admin_pass(){
    string p;    
    system("cls");
    coordxy(50,6); std::cout<<"Please Enter Your Password ";
    coordxy(50,10); std::cout<<"Password : ";
    cin.ignore();
    (cin,p);
    coordxy(50,10); std::cout<<"Password : "<<p;
}
int main(){
    system("cls");
    system("COLOR F0");      // using white background
    window_adjust(120,30);
    
    
    
    while(program_stop != true){
		
		
		//cleaning whatever was written before
		system("cls");
		
		//colors and text
		system("COLOR F0"); // we use a white background and black text
		
		window_adjust(120, 30); // we set the screen size
		graphic_interface();
		coordxy(50,12); std::cout<<"Hotel Grand Food";
        welcome();
        key =getch();
        if(key =='a'){
            system("cls");
            graphic_interface();
            Hotel grand_food;
            grand_food.show_menu();
            break;
        }
			
	}
    system("pause");
	
}

