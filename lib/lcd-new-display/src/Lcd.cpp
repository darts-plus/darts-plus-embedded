#include "Lcd.hpp"

Lcd::Lcd(): ucg(A, CS, RESET)
{
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();                //display horizontally
  ucg.setRotate90(); 
  // current_pos = 1;             // this should be given from game services
  // selected_pos = 0;
  // dbl_in = 0;
  // dbl_out = 0;
  // players = 2;
  // points_index = 1;
  // menu_id = 0;
}

// void Lcd::print_main_menu(){             todo wifi etc
//   ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
//   ucg.setFontMode(UCG_FONT_MODE_SOLID);
//   ucg.setPrintPos(0, 15);
//   if(current_pos == 1 && selected_pos){
//     //start_game();
//   }else if(current_pos == 1){
//     ucg.setColor(0, 0, 0, 0);       // black color for the text
//     ucg.setColor(1, 150, 220, 255); // yellow for the background
//   }else {
//     ucg.setColor(0, 255, 255, 255);       // black color for the text
//     ucg.setColor(1, 0, 0, 0); // light blue for the background
//   }
//   ucg.print("Play");  // Print text or value

//   ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
//   ucg.setFontMode(UCG_FONT_MODE_SOLID);
//   ucg.setPrintPos(0, 15);
//   if(current_pos == 2 && selected_pos){
//     menu_id = 2;
//   }else if(current_pos == 2){
//     ucg.setColor(0, 0, 0, 0);       // black color for the text
//     ucg.setColor(1, 150, 220, 255); // yellow for the background
//   }else {
//     ucg.setColor(0, 255, 255, 255);      
//     ucg.setColor(1, 0, 0, 0); 
//   }
//   ucg.print("Game settings");  // Print text or value
// }

void Lcd::clear_display(){
  ucg.clearScreen(); 
}
void Lcd::menu_display(int cursor, bool dbl_in, bool dbl_out, int players){ 
  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setPrintPos(0, 15);
  //POINTS
  if(cursor == 0){
  ucg.setColor(0, 0, 0, 0);       // black color for the text
  ucg.setColor(1, 255,255,0); // yellow for the background
  }else {
    ucg.setColor(0, 255, 255, 255);       
    ucg.setColor(1, 0, 0, 0); 
  }
  ucg.print("Points");  // Print text or value

  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setPrintPos(130, 15);
  ucg.print(301);  // print given points

  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(0, 35);  // Set position (x,y)
  //PLAYERS
  if(cursor == 1){
  ucg.setColor(0, 0, 0, 0);       // black color for the text
  ucg.setColor(1, 255,255,0); // yellow for the background
  }else {
    ucg.setColor(0, 255, 255, 255);      
    ucg.setColor(1, 0, 0, 0); 
  }
  ucg.print("Players");  // Print text or value

  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setPrintPos(130, 35);
  ucg.print(players);  // Print number of players

  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(0, 55);  // Set position (x,y)
  //doublein
  if(cursor == 2){
  ucg.setColor(0, 0, 0, 0);       // black color for the text
  ucg.setColor(1, 255,255,0); // yellow for the background
  }else {
    ucg.setColor(0, 255, 255, 255);       
    ucg.setColor(1, 0, 0, 0); 
  }
  ucg.print("Double in");  // Print text or value

  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setPrintPos(130, 55);
  if (dbl_in)
  {
    ucg.print("On");  // Print text or value
  }else
  {
    ucg.print("Off");
  }
  
  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(0, 75);  // Set position (x,y)
  //DOUBLEOUT
  if(cursor == 3){
  ucg.setColor(0, 0, 0, 0);       // black color for the text
  ucg.setColor(1, 255,255,0); // yellow for the background
  }else {
    ucg.setColor(0, 255, 255, 255);       
    ucg.setColor(1, 0, 0, 0); 
  }
  ucg.print("Double out");  // Print text or value

  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setPrintPos(130, 75);
  if (dbl_out)
  {
    ucg.print("On");  // Print text or value
  }else
  {
    ucg.print("Off");
  }

  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(0, 95);  // Set position (x,y)
  //START
  if(cursor == 4){
    //start_game();
  }else {
    ucg.setColor(0, 255, 255, 255);    
    ucg.setColor(1, 0, 0, 0);
  }
  ucg.print("Start");  // Print text or value
//DON'T KNOW IF WE NEED THIS PART BELOW
  ucg.setFont(ucg_font_ncenB10_hf);	// do not use _tf for UCG_FONT_MODE_SOLID
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(0, 115);  // Set position (x,y)

  // if(cursor == BACK && selected_pos){
  //   //go_back();
  // }else if(cursor == BACK){
  //   ucg.setColor(0, 0, 0, 0);       // black color for the text
  //   ucg.setColor(1, 150, 220, 255); // light blue for the background
  // }else {
  //   ucg.setColor(0, 255, 255, 255);      
  //   ucg.setColor(1, 0, 0, 0);
  // }
  // ucg.print("Back");  // Print text or value

}

// void Lcd::print_menu_temp(){
//   switch (menu_id)
//   {
//   case 0:
//       print_main_menu();
//     break;
//   case 1:
//       //print_scoreboard();
//     break;
//   case 2:
//       print_game_menu();
//     break;
  
//   default:
//     break;
//   }
// }
// static const unsigned char PROGMEM logo_bmp[] = {              //not working
// 	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// 	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// 	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// 	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 
// 	0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 
// 	0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 
// 	0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xe7, 0x3f, 0xff, 0xff, 0xff, 0xb9, 0xff, 
// 	0xff, 0xe7, 0x3f, 0xff, 0xff, 0xff, 0x19, 0xff, 0xff, 0xe6, 0x7f, 0xff, 0xff, 0xff, 0x99, 0xff, 
// 	0xff, 0xe4, 0x7f, 0xff, 0xff, 0xff, 0xc9, 0xff, 0xff, 0xe4, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 
// 	0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 
// 	0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 
// 	0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xe7, 0xef, 0xff, 0xff, 0xfd, 0xf9, 0xff, 
// 	0xff, 0xe7, 0xc7, 0xff, 0xff, 0xf8, 0xf9, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xf8, 0xf9, 0xff, 
// 	0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 
// 	0xff, 0xf3, 0xff, 0xf1, 0xf3, 0xff, 0xf3, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xf1, 0xff, 0xe3, 0xff, 
// 	0xff, 0xf8, 0xff, 0xc7, 0xf8, 0xff, 0xc7, 0xff, 0xff, 0xfc, 0x3f, 0x0f, 0xfc, 0x3f, 0x0f, 0xff, 
// 	0xff, 0xff, 0x00, 0x1f, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xc0, 0x3f, 0xff, 
// 	0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0x3f, 0xff, 
// 	0xff, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 
// 	0xff, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xfe, 0x7f, 0xff, 
// 	0xff, 0xff, 0xcf, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xfe, 0x7f, 0xff, 
// 	0xff, 0xff, 0xcf, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 
// 	0xff, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 
// 	0xff, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0xff, 
// 	0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0x9f, 0xff, 
// 	0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xcf, 0xff, 
// 	0xff, 0xfc, 0xff, 0xff, 0xbf, 0xff, 0xcf, 0xff, 0xff, 0xf9, 0xff, 0xff, 0x3f, 0xff, 0xe7, 0xff, 
// 	0xff, 0xf1, 0xff, 0xff, 0x3f, 0xff, 0xf3, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x3f, 0xff, 0xf3, 0xff, 
// 	0xff, 0xe7, 0xff, 0xff, 0xbf, 0xff, 0xf9, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 
// 	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// 	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// 	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
// };

void Lcd::score_display(String nickname, int score, int attempts){
  
  const char* nick = nickname.c_str();
  ucg.setFont(ucg_font_inr21_mr);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(0, 25);  // Set position (x,y)
  ucg.print(nick);  // Print text or value

  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)       print horizontal line to separate nick and score
  ucg.drawHLine(0, 36, 160);

  ucg.setFont(ucg_font_inr53_mn);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(4, 110);  // Set position (x,y)
  ucg.print(score);  // Print text or value

  if (attempts == 1)                                        //print number of remaining darts
  {      
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawDisc(148, 55, 8, UCG_DRAW_ALL);
  }else if (attempts ==2)
  {     
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawDisc(148, 55, 8, UCG_DRAW_ALL);
    
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawDisc(148, 82, 8, UCG_DRAW_ALL);
  }else if (attempts == 3)
  {
    // ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    // ucg.drawDisc(148, 55, 8, UCG_DRAW_ALL);
    
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 47, 156, 63);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 46, 156, 62);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 48, 156, 64);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawTriangle(158, 65, 158, 55, 148, 65);

    // ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    // ucg.drawDisc(148, 82, 8, UCG_DRAW_ALL); 

    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 74, 156, 90);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 73, 156, 89);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 75, 156, 91);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawTriangle(158, 92, 158, 82, 148, 92);
  
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 101, 156, 117);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 100, 156, 116);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawLine(140, 102, 156, 118);
    ucg.setColor(0, 0, 255, 0);  // Set color (0,R,G,B)
    ucg.drawTriangle(158, 119, 158, 109, 148, 119);
  }else
  {
      
  }
 
}

// THIS SHOULD BE GIVEN BY GAME SERVICE

// void Lcd::scroll_down(){
//   if (current_pos != 1)
//   {
//     current_pos--;
//   }else
//   {
//     current_pos = 6;
//   }
  
  
// }

// void Lcd::scroll_up(){
//   if (current_pos != 6)
//   {
//     current_pos++;
//   }else
//   {
//     current_pos = 1;
//   }
// }

// >>>>>>>>>>>>>>>>>>>>>>>>>>>> MAKE IT WORK WITH GAME SERVICES

// void Lcd::select(){
//   selected_pos = true ? selected_pos = false: selected_pos = true;
// }

// void Lcd::change_value_up(){
//   if (current_pos == 3)
//   {
//     // dbl_in = true;
//   }else if (current_pos == 4)
//   {
//     // dbl_out = true;
//   }else if (current_pos == 1)
//   {
//     // points_index < 4 ? points_index++ : points_index;
//   }else if (current_pos == 2)
//   {
//     // players < 10 ? players++ : players;
//   } 
  
// }	

// void Lcd::change_value_down(){
//   if (current_pos == 3)
//   {
//     // dbl_in = false;
//   }else if (current_pos == 4)
//   {
//     // dbl_out = false;
//   }else if (current_pos == 1)
//   {
//     // points_index > 0 ? points_index-- : points_index;
//   }else if (current_pos == 2)
//   {
//     // players > 1 ? players-- : players;
//   } 
  
// }	

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>
// DO WE EVEN NEED THAT??
// void Lcd::go_back(){
//   selected_pos = 0;
//   current_pos = 1;
//   menu_id = 0;
// }


// JUST SOME DISCO
void Lcd::win_animation(String nickname){
  
  const char* nick = nickname.c_str();
  ucg.setFont(ucg_font_inr30_mr);
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setPrintPos(40, 55);  // Set position (x,y)
  ucg.print(nick);  // Print text or value
  for (size_t i = 0; i < 10; i++)
  {
    uint8_t temp1 = rand() % 256;
    uint8_t temp2 = rand() % 256;
    uint8_t temp3 = rand() % 256;
    ucg.setColor(1, temp1, temp2, temp3);  // Set color of text background (1,R,G,B)
  }
  
  ucg.setColor(0, 255, 255, 255);  // Set color (0,R,G,B)
  ucg.setColor(1, 0, 0, 0);  // Set color of text background (1,R,G,B)
  ucg.setPrintPos(40, 55);  // Set position (x,y)
  ucg.print(nick);  // Print text or value
}