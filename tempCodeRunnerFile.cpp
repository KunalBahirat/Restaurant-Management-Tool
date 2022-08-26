class Item{
    friend class Hotel;
    string item_name;
    int id;
    double price;
};
class Hotel{
    unordered_map <string, list<Item>> menu;
    list <Item> str;
    list <Item> veg;
    list <Item> non_veg;
    list <Item> tiff;
    public:
        Hotel(){
            string it_type1="Starters";
            Item one_str; one_str.id=101; one_str.item_name="Crispy Corn"; one_str.price=170.00;str.push_back(one_str); 
            Item two_str; two_str.id=102; two_str.item_name="Veg Spring Rolls"; two_str.price=150.00; str.push_back(two_str);
            Item three_str; three_str.id=103; three_str.item_name="Chilly Paneer"; three_str.price=180.00;  str.push_back(three_str);
            
            string it_type2="Veg Main";
            Item one_veg;one_veg.id=201;one_veg.item_name="Tomato Curry";one_veg.price=160; veg.push_back(one_veg); 
            Item two_veg;two_veg.id=202;two_veg.item_name="Aloo Mutter";two_veg.price=160; veg.push_back(two_veg); 
            Item three_veg;three_veg.id=203;three_veg.item_name="Kadai Paneer";three_veg.price=220; veg.push_back(three_veg); 

            string it_type3="Non Veg Main";
            Item one_non_veg;one_non_veg.id=301;one_non_veg.item_name="Ginger Chicken";one_non_veg.price=190; non_veg.push_back(one_non_veg); 
            Item two_non_veg;two_non_veg.id=302;two_non_veg.item_name="Mutton Curry";two_non_veg.price=300; non_veg.push_back(two_non_veg); 
            Item three_non_veg;three_non_veg.id=303;three_non_veg.item_name="Fish Fry";three_non_veg.price=280; non_veg.push_back(three_non_veg); 

            string it_type4="Tiffin";
            Item one_tiff;one_tiff.id=401;one_tiff.item_name="Rava Dosa";one_tiff.price=60; tiff.push_back(one_tiff); 
            Item two_tiff;two_tiff.id=402;two_tiff.item_name="Onion Pesara";two_tiff.price=60; tiff.push_back(two_tiff); 
            Item three_tiff;three_tiff.id=403;three_tiff.item_name="Upma";three_tiff.price=80; tiff.push_back(three_tiff); 


            menu[it_type1]=str;
            menu[it_type2]=veg;
            menu[it_type3]=non_veg;
            menu[it_type4]=tiff;
            
        }
        void add_to_menu(string it_type,string it_name,int id,int price){

        }
        void show_menu(){
            auto it=menu.begin();
            cout<<"----------------------------------Today's Menu----------------------------------\n";
            bool p=false;
            while(it!=menu.end()){
                if(!p){
                    cout<<(it->first)<<"\n";
                    p=true;
                }
                cout<<"\n\tID\t\tITEM NAME\t\tPRICE\n";
                auto it2=it->second.begin();
                while(it2!=it->second.end()){
                    cout<<"\t"<<it2->id<<"\t\t"<<it2->item_name<<"\t\t"<<it2->price<<"\n";
                    it2++;
                }
                p=false;
                it++;
            }
        }

};