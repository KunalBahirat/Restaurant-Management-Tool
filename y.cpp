// system("cls");
    // system("COLOR F0");      // using white background
    // window_adjust(120,30);
    
    
    
    // while(program_stop != true){
		
		
	// 	//cleaning whatever was written before
	// 	system("cls");
		
	// 	//colors and text
	// 	system("COLOR F0"); // we use a white background and black text
		
	// 	window_adjust(120, 30); // we set the screen size
	// 	graphic_interface();
	// 	coordxy(50,12); std::cout<<"Hotel Grand Food";
    //     welcome();
    //     key =getch();
    //     if(key =='a'){
    //         system("cls");
    //         graphic_interface();
    //         Hotel grand_food;
    //         grand_food.show_menu();
    //         break;
    //     }
			
	// }
    // system("pause");


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
