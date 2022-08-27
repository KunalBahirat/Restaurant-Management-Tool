#include <bits/stdc++.h>
#include "welcome.h"
using namespace std;
char key;
int program_stop=false;
const std::string currentDateTime() {       // fun to get date and time => putting in database
   time_t     now = time(0);
   struct tm  tstruct;
   char       buf[80];
   tstruct = *localtime(&now);
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
    friend void admin(Hotel &obj);                                        // Friend Function
    string pass="Kunal123";
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
           coordxy(2,2); std::cout<<"----------------------------------Today's Menu----------------------------------\n";
           // bool p=false;
           int y=2;
           
           while(it!=menu.end()){
            y+=2;
               coordxy(25,y++);std::cout<<(it->first);
               coordxy(15,y);std::cout<<"ID";
			   coordxy(35,y); cout<<" NAME";
			   coordxy(55,y);cout<<"PRICE";y++;
               auto it2=it->second.begin();
               while(it2!=it->second.end()){
                   coordxy(7,y);std::cout<<setw(10)<<*it2;
                   coordxy(35,y); cout<<item_details[*it2].first;
                   coordxy(55,y); cout<<item_details[*it2].second;
                   it2++;y++;
               }
               it++;
           }
       }
       void order_food(){
       	int count=1;
           coordxy(17,41) ; std::cout<<"\t\tHotel Grand Food\n";
           int id,quantity;
           int table_no,total_amt=0;
           std::cout<<"Enter Table Number : ";
           cin>>table_no;

           string table_name="order table "+to_string(table_no);

           ofstream ord;ofstream dt_base;
           dt_base.open("Database",ios::app);
           ord.open(table_name,ios::app);
           ord<<"\nItem ID"<<setw(30)<<"Item Name"<<setw(30)<<"Quantity"<<setw(33)<<"Amount\n";
           ord<<"---------------------------------------------------------------------------------------------------------\n";

           std::cout<<"Enter Item ID : ";
           cin>>id;
           while(id!=-1){
           		count++;
               while(item_details.find(id)==item_details.end()){
                   std::cout<<"Enter Valid Item ID : ";
                   cin>>id;
               }
               std::cout<<"Enter Quantity of "<<item_details[id].first<<" : ";
               cin>>quantity; setw(20);
			   if(count>5)cout<<"If Finished Press -1 \n";
               ord<<id<<setw(35)<<item_details[id].first<<setw(30)<<quantity<<setw(30)<<quantity*item_details[id].second<<endl;
               total_amt+=quantity*item_details[id].second;


               dt_base <<currentDateTime()<< setw(15) <<id<<setw(30)<<item_details[id].first <<setw(30)<<quantity<<"\n";


               std::cout<<"Enter Item ID : ";
               cin>>id;
           }
           ord<<"---------------------------------------------------------------------------------------------------------\n";
           ord<<" Thank You!                                                                              TOTAL: "<<total_amt<<"/-\n";
           ord.close();
           dt_base.close();
           ofstream rev("Revenue",ios::app);
            rev<<currentDateTime()<<setw(15)<<table_no<<setw(20)<<total_amt<<endl;
            rev.close();
           return ;
       }
       void generate_bill(){
       	    int table_no;
			cout<<"\nEnter Your Table Number : ";
       		cin>>table_no;
            string table_name="order table "+to_string(table_no);
			ifstream bill(table_name);
	        if (bill.is_open())
             std::cout << bill.rdbuf();
    		cout<<"\n";
    		bill.close();
            
            remove(table_name.c_str());            
	    }
       void show_revenue(){
          ifstream rev("Revenue");
          if(rev.is_open()){
            cout<<rev.rdbuf();
          }
          cout<<"\n";
          rev.close();
          getch();
       }
};
void manager(char k,Hotel &obj);
void customer(Hotel &grandFood){
    system("cls");
    coordxy(30,5);cout<<"Hotel Grand Food";
    coordxy(30,7); cout<<"WELCOME";
    Sleep(500);
    coordxy(30,7); cout<<"       ";
    Sleep(500);
    coordxy(30,7); cout<<"WELCOME";
    Sleep(500);
    coordxy(20,12); cout<<"Press 'a' To Show Menu "; 
    coordxy(20,14); cout<<"Press 'b' To Order Food ";
    coordxy(20,16); cout<<"Press 'c' To Generate Bill ";
    coordxy(20,18); key =getch(); cout<<"=> "<<key;
    Sleep(500);
    if(key=='a'){
        system("cls");
        grandFood.show_menu();
        coordxy(12,39);cout<<"Want To Order Your Meal ?  ";
        getch();
		grandFood.order_food();
		cout<<"           It Will take Just 20 Minutes  \n\t\tEnjoy The Meal!\n\tEnter 'z' to Exit ";
		key=getch();
		if(key=='z');
        return;
    };
    if(key=='b'){
    	system("cls");
        grandFood.show_menu();
        coordxy(12,39);cout<<"Want To Order Your Meal ?  ";
        getch();
		grandFood.order_food();
		cout<<"           It Will take Just 20 Minutes  \n\t\tEnjoy The Meal!\n\tEnter 'z' to Exit ";
		key=getch();
		if(key=='z');
        return;
	}
	if(key=='c'){
		manager('c',grandFood);
		cout<<"\n\t\tEnter 'z' to Exit ";
		key=getch();
		if(key=='z');
        return;
	}

}
void manager(char k,Hotel &grandFood){
	if(k=='c'){
		grandFood.generate_bill();
		return;
	}
	else if(k=='z'){
		program_stop=true;
		return;
	}
    else if(k=='a'){
    ofstream att("Attendance",ios::app);
    att<<currentDateTime()<<setw(15)<<"Manager"<<setw(20)<<"Yes\n";
    att.close();}

}
void admin(Hotel &grandFood){
    string p;
    system("cls");
    coordxy(20,5); cout<<"Hello Admin ";
    coordxy(20,9); cout<<"Enter Password ";
    coordxy(22,11); cout<<"=> ";cin>>p;
    int count=1;
    while(p!=grandFood.pass){
        if((count++)==5){
           coordxy(23,15); cout<<"5 UnsuccesFul Attempts";
           getch();
           program_stop=true;
           return;
        }

        coordxy(23,15);cout<<"Incorrect Password ";
        getch();
        system("cls");
        coordxy(20,5); cout<<"Hello Admin ";
        coordxy(20,9); cout<<"Enter Password ";
        coordxy(22,11); cout<<"=> ";cin>>p;
    }
    coordxy(23,15);cout<<" Password Matched! ";
    getch();
    system("cls");
    coordxy(40,8); cout<<"Admin Page";
    coordxy(40,12); cout<<"a) Show Revenue ";
    coordxy(40,13); cout<<"b) Show Bills ";
    coordxy(40,14); cout<<"c) Add To Menu ";
    coordxy(40,15); cout<<"d) End Program ";
    coordxy(42,17); cout<<"=> ";cin>>key;
    if(key=='a'){
        grandFood.show_revenue();
    }
    if(key=='c'){
        grandFood.add_to_menu();
    }
    if(key=='d'){
        program_stop=true;
        return;
    }

}
char login(){
    system("cls");
    graphic_interface();
    coordxy(40,8); std::cout<<"User Login";
    coordxy(40,12); cout<<"a) Foodie ";
    coordxy(40,14); cout<<"b) Manager ";
    coordxy(40,16); cout<<"c) Admin ";
    coordxy(40,19); cout<<"Respond Using Key 'a' or 'b' or 'c' "; key =getch(); 
    coordxy(40,25); cout<<"Press 'z' to Exit";
    while (key!='a' and key!='b' and key!='c' and key!='z')
    {
        coordxy(40,19); cout<<"Respond Using Key 'a' or 'b' or 'c'  ";key =getch();
        coordxy(40,20); cout<<"Invalid Key ";
    }
    if(key=='z'){
        program_stop=true;
    }
    coordxy(40,22); cout<<" => "<<key;
    Sleep(1500);
    return key;
}
int main(){
    system("cls");
    system("COLOR F0");
    window_adjust(150,50);
    graphic_interface();
    welcome();
    getch();
    Hotel grandFood;

    while(program_stop != true){
        system("cls");
        graphic_interface();
        key =login();

        if(key=='a'){
            customer(grandFood);
        }
        if(key=='b'){
            manager('a',grandFood);
        }
        if(key=='c'){
        	admin(grandFood);
		}
    }
	
}

