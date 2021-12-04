#include<bits/stdc++.h>
#include"console.cpp"

#define consoleWidth 90
#define consoleHeight 26

using namespace std; 

void veTuong(){  
	for(int i=0; i< consoleHeight; i++){
		for(int j = 0; j < 17; j++){
			gotoxy(j,i); cout<<"±";
			gotoxy(70-j,i); cout<<"±";
		}
	} 
	for(int i = 0; i < consoleHeight; i++){
		gotoxy(consoleWidth+5,i); cout<<"±";
		gotoxy(consoleWidth+6,i); cout<<"±";
	}
	for(int i = 71 ; i <= consoleWidth+5; i++){
		gotoxy(i,0); cout << "±";
		
	}
	for(int i = 17 ; i <= 59 ; i++){
		gotoxy(i,0);cout << "±";
	}
	for(int i = 0 ; i <= consoleWidth + 6; i++ ){
		gotoxy(i,consoleHeight);cout << "±";
	}
	for(int i = 71 ; i<= consoleWidth + 5; i++){
		gotoxy(i,consoleHeight/2 -11);cout << "±";
	}
	for(int i =1 ; i<= 2 ; i++ ){
		gotoxy(consoleWidth-8,i);cout << "±";
		gotoxy(consoleWidth-7,i);cout << "±";
	}
	TextColor(10);
	gotoxy(77,5); cout << "Pause--Enter";
	TextColor(11);
	gotoxy(78,11); cout << "Music--";
	putchar(016);
	TextColor(12);
	gotoxy(78,16); cout << "Menu--Space";
	TextColor(13);
	gotoxy(78,22); cout << "Exit--ESC";
}
int timeSleep = 200;
int toaDoX = 34;
int toaDoY = 22;
int score = 0; 
int lever = 0;
int vatcanX[2];
int vatcanY[2];
int trangThai[2];
char car[4][4] = { putchar(002),' ',' ',putchar(002), 
				   ' ','±','±',' ', 
				   ' ','±','±',' ',
				   putchar(002),' ',' ',putchar(002) }; 
				   

void hienThiVc(int n){
	if( trangThai[n] == 1 ){
		TextColor(8 + rand()%8);
		gotoxy(vatcanX[n], vatcanY[n]);   cout<<"±  ±";  
		gotoxy(vatcanX[n], vatcanY[n]+1); cout<<" ±± "; 
		gotoxy(vatcanX[n], vatcanY[n]+2); cout<<" ±± "; 
		gotoxy(vatcanX[n], vatcanY[n]+3); cout<<"±  ±";  
	} 
}
void xoaVc(int n){
	if( trangThai[n] == 1 ){
		gotoxy(vatcanX[n], vatcanY[n]);   cout<<"    ";  
		gotoxy(vatcanX[n], vatcanY[n]+1); cout<<"    "; 
		gotoxy(vatcanX[n], vatcanY[n]+2); cout<<"    "; 
		gotoxy(vatcanX[n], vatcanY[n]+3); cout<<"    "; 
	} 
}

void taoVc(int n){
	xoaVc(n);
	vatcanY[n] = 1;
	vatcanX[n] = 17 + rand()%(33);
}

void veXe(){
	TextColor(11);
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+toaDoX, i+toaDoY); cout<<car[i][j];
		}
	}
}
void xoaXe(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+toaDoX, i+toaDoY); cout<<" ";
		}
	}
}
 
int xuLyVaCham(){

	for(int i = 0 ; i < 2 ; i ++){
		int x = abs(vatcanX[i] - toaDoX);
		int y = abs(vatcanY[i] - toaDoY);
		if( x <= 3 && y <= 3 ){
			
				return -1;
			
		}
	}
	return 0;
} 
void gameover(){
	clrscr();
	cout<<endl;
	TextColor(11);
	cout << "                                GGGGGGGGGGGGG               AAA               MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE" << endl;
	cout << "                             GGG::::::::::::G              A:::A              M:::::::M             M:::::::ME::::::::::::::::::::E" << endl;
	cout << "                           GG:::::::::::::::G             A:::::A             M::::::::M           M::::::::ME::::::::::::::::::::E" << endl;
	cout << "                          G:::::GGGGGGGG::::G            A:::::::A            M:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E" << endl;
	cout << "                         G:::::G       GGGGGG           A:::::::::A           M::::::::::M       M::::::::::M  E:::::E       EEEEEE" << endl;
	cout << "                        G:::::G                        A:::::A:::::A          M:::::::::::M     M:::::::::::M  E:::::E" << endl;             
	cout << "                        G:::::G                       A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE" << endl;   
	cout << "                        G:::::G    GGGGGGGGGG        A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M  E:::::::::::::::E" << endl;   
	cout << "                        G:::::G    G::::::::G       A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M  E:::::::::::::::E" << endl;   
	cout << "                        G:::::G    GGGGG::::G      A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE" << endl;   
	cout << "                        G:::::G        G::::G     A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M  E:::::E" << endl;             
	cout << "                         G:::::G       G::::G    A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M  E:::::E       EEEEEE" << endl;
	cout << "                          G:::::GGGGGGGG::::G   A:::::A             A:::::A   M::::::M               M::::::MEE::::::EEEEEEEE:::::E" << endl;
	cout << "                           GG:::::::::::::::G  A:::::A               A:::::A  M::::::M               M::::::ME::::::::::::::::::::E" << endl;
	cout << "                             GGG::::::GGG:::G A:::::A                 A:::::A M::::::M               M::::::ME::::::::::::::::::::E" << endl;
	cout << "                                GGGGGG   GGGGAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE" << endl;
    cout << endl;
    TextColor(12);                                                               
	cout << "                                       OOOOOOOOO     VVVVVVVV           VVVVVVVVEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR" << endl;  
	cout << "                                     OO:::::::::OO   V::::::V           V::::::VE::::::::::::::::::::ER::::::::::::::::R" << endl;  
	cout << "                                   OO:::::::::::::OO V::::::V           V::::::VE::::::::::::::::::::ER::::::RRRRRR:::::R" << endl; 
	cout << "                                  O:::::::OOO:::::::OV::::::V           V::::::VEE::::::EEEEEEEEE::::ERR:::::R     R:::::R" << endl;
	cout << "                                  O::::::O   O::::::O V:::::V           V:::::V   E:::::E       EEEEEE  R::::R     R:::::R" << endl;
	cout << "                                  O:::::O     O:::::O  V:::::V         V:::::V    E:::::E               R::::R     R:::::R" << endl;
	cout << "                                  O:::::O     O:::::O   V:::::V       V:::::V     E::::::EEEEEEEEEE     R::::RRRRRR:::::R" << endl; 
	cout << "                                  O:::::O     O:::::O    V:::::V     V:::::V      E:::::::::::::::E     R:::::::::::::RR" << endl;  
	cout << "                                  O:::::O     O:::::O     V:::::V   V:::::V       E:::::::::::::::E     R::::RRRRRR:::::R" << endl; 
	cout << "                                  O:::::O     O:::::O      V:::::V V:::::V        E::::::EEEEEEEEEE     R::::R     R:::::R" << endl;
	cout << "                                  O:::::O     O:::::O       V:::::V:::::V         E:::::E               R::::R     R:::::R" << endl;
	cout << "                                  O::::::O   O::::::O        V:::::::::V          E:::::E       EEEEEE  R::::R     R:::::R" << endl;
	cout << "                                  O:::::::OOO:::::::O         V:::::::V         EE::::::EEEEEEEE:::::ERR:::::R     R:::::R" << endl;
	cout << "                                   OO:::::::::::::OO           V:::::V          E::::::::::::::::::::ER::::::R     R:::::R" << endl;
	cout << "                                     OO:::::::::OO              V:::V           E::::::::::::::::::::ER::::::R     R:::::R" << endl;
	cout << "                                       OOOOOOOOO                 VVV            EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR" << endl;                                                                                          

	getch();
}
void hienThiScore(){
	TextColor(9);
	gotoxy(70 + 2, 1);cout<<"S";
	TextColor(11);
	gotoxy(70 + 3, 1);cout<<"c";
	TextColor(12);
	gotoxy(70 + 4, 1);cout<<"o";
	TextColor(13);
	gotoxy(70 + 5, 1);cout<<"r";
	TextColor(10);
	gotoxy(70 + 6, 1);cout<<"e: ";
	TextColor(14);
	cout<<score<<endl;
}

void hienThiLever(){
	TextColor(12);
	gotoxy(70 + 16, 1);cout<<"L";
	TextColor(11);
	gotoxy(70 + 17, 1);cout<<"e";
	TextColor(9);
	gotoxy(70 + 18, 1);cout<<"v";
	TextColor(7);
	gotoxy(70 + 19, 1);cout<<"e";
	TextColor(13);
	gotoxy(70 + 20, 1);cout<<"r: ";
	TextColor(15);
	cout<<lever<<endl;
}

void huongDan(){
	int x = 40;
	int y = 10;
	system("cls");
	TextColor(14);
	gotoxy(x,y);cout << "RACING GAME GUIDE : ";
	TextColor(10);
	gotoxy(x,y+2);cout << "1.Your mission is to dodge the obstacles.";
	gotoxy(x,y+3);cout << "2.Press 'A' or 'D' to move left or right.";
	gotoxy(x,y+4);cout << "3.Try to get the highest score possible !";
	TextColor(13); 
	gotoxy(x,y+5);cout << "----> If you understand then PRESS ANY KEY TO START.";
	getch();
}

void play(){
	clrscr();
	
	veTuong(); 
	hienThiScore();
	hienThiLever();
	
	trangThai[0] = 1;
	trangThai[1] = 0;
	
	vatcanX[0] = vatcanX[1] = 17 + rand()%(33);
	vatcanY[0] = vatcanY[1] = 1;
	
	gotoxy(24, 8);cout<<"Press any key to start";
	getch();
	gotoxy(24, 8);cout<<"                      ";
	
	while(1){
		if(kbhit()){
			char nut = getch();
			if( (nut=='a' || nut=='A') && toaDoX > 18 ){
				toaDoX -= 4;
			}
			else if( (nut=='d' || nut=='D') && toaDoX < 50 ){
				toaDoX += 4;
			}
			else if( (nut=='w' || nut=='W') && toaDoY > 2 ){
				toaDoY -= 2;
			}
			else if( (nut=='s' || nut=='S') && toaDoY < consoleHeight - 4 ){
				toaDoY += 2;
			}
			else if(nut == 32){
				return;
			}
			else if(nut == 27){
				gotoxy(100,100);
				exit(0);
			}
			
			else if(nut==13){
				gotoxy(24, 8);cout<<"Press any key to start!";
				getch();
				gotoxy(24, 8);cout<<"                       ";
			}
		} 
			
		veXe(); 
		hienThiVc(0); 
		hienThiVc(1);
		
		Sleep(timeSleep);
		
		xoaXe();
		xoaVc(0);
		xoaVc(1);
		
		
		if( xuLyVaCham() == -1  ){
			gameover();
			return;
		}
		
		if( vatcanY[0] == 13 )
			if( trangThai[1] == 0 )
				trangThai[1] = 1;
		
		for(int i = 0 ; i < 2 ; i++){
			
			if( trangThai[i] == 1 )
				vatcanY[i] += 1;
		
			if( vatcanY[i] > consoleHeight-5 ){
				taoVc(i);
				if(timeSleep > 30){
					timeSleep-=5;
				}
				score++;
				for(int n = 0 ; n <= 10000 ; n+=10){
					if(score == n){
						lever++;
					}
				}
				hienThiLever();	
				hienThiScore();
			}
		}
	}
}

int main()
{
	setcursor(0,0); 
	srand(time(NULL)); 
	 
	while(1){
		system("cls");
		TextColor(14);
		cout << "                                GGGGGGGGGGGGG               AAA               MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE" << endl;
		cout << "                             GGG::::::::::::G              A:::A              M:::::::M             M:::::::ME::::::::::::::::::::E" << endl;
		cout << "                           GG:::::::::::::::G             A:::::A             M::::::::M           M::::::::ME::::::::::::::::::::E" << endl;
		cout << "                          G:::::GGGGGGGG::::G            A:::::::A            M:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E" << endl;
		cout << "                         G:::::G       GGGGGG           A:::::::::A           M::::::::::M       M::::::::::M  E:::::E       EEEEEE" << endl;
		cout << "                        G:::::G                        A:::::A:::::A          M:::::::::::M     M:::::::::::M  E:::::E" << endl;             
		cout << "                        G:::::G                       A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE" << endl;   
		cout << "                        G:::::G    GGGGGGGGGG        A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M  E:::::::::::::::E" << endl;   
		cout << "                        G:::::G    G::::::::G       A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M  E:::::::::::::::E" << endl;   
		cout << "                        G:::::G    GGGGG::::G      A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE" << endl;   
		cout << "                        G:::::G        G::::G     A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M  E:::::E" << endl;             
		cout << "                         G:::::G       G::::G    A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M  E:::::E       EEEEEE" << endl;
		cout << "                          G:::::GGGGGGGG::::G   A:::::A             A:::::A   M::::::M               M::::::MEE::::::EEEEEEEE:::::E" << endl;
		cout << "                           GG:::::::::::::::G  A:::::A               A:::::A  M::::::M               M::::::ME::::::::::::::::::::E" << endl;
		cout << "                             GGG::::::GGG:::G A:::::A                 A:::::A M::::::M               M::::::ME::::::::::::::::::::E" << endl;
		cout << "                                GGGGGG   GGGGAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE" << endl;
    	cout << endl;
		TextColor(10);
		cout << "                    DDDDDDDDDDDDD       UUUUUUUU     UUUUUUUU           AAA                    XXXXXXX       XXXXXXXEEEEEEEEEEEEEEEEEEEEEE" << endl;
		cout << "                    D::::::::::::DDD    U::::::U     U::::::U          A:::A                   X:::::X       X:::::XE::::::::::::::::::::E" << endl;
		cout << "                    D:::::::::::::::DD  U::::::U     U::::::U         A:::::A                  X:::::X       X:::::XE::::::::::::::::::::E" << endl;
		cout << "                    DDD:::::DDDDD:::::D UU:::::U     U:::::UU        A:::::::A                 X::::::X     X::::::XEE::::::EEEEEEEEE::::E" << endl;
		cout << "                      D:::::D    D:::::D U:::::U     U:::::U        A:::::::::A                XXX:::::X   X:::::XXX  E:::::E       EEEEEE" << endl;
		cout << "                      D:::::D     D:::::DU:::::D     D:::::U       A:::::A:::::A                  X:::::X X:::::X     E:::::E" << endl;            
		cout << "                      D:::::D     D:::::DU:::::D     D:::::U      A:::::A A:::::A                  X:::::X:::::X      E::::::EEEEEEEEEE" << endl;   
		cout << "                      D:::::D     D:::::DU:::::D     D:::::U     A:::::A   A:::::A                  X:::::::::X       E:::::::::::::::E" << endl;   
		cout << "                      D:::::D     D:::::DU:::::D     D:::::U    A:::::A     A:::::A                 X:::::::::X       E:::::::::::::::E" << endl;  
		cout << "                      D:::::D     D:::::DU:::::D     D:::::U   A:::::AAAAAAAAA:::::A               X:::::X:::::X      E::::::EEEEEEEEEE" << endl;   
		cout << "                      D:::::D     D:::::DU:::::D     D:::::U  A:::::::::::::::::::::A             X:::::X X:::::X     E:::::E" << endl;             
		cout << "                      D:::::D    D:::::D U::::::U   U::::::U A:::::AAAAAAAAAAAAA:::::A         XXX:::::X   X:::::XXX  E:::::E       EEEEEE" << endl;
		cout << "                    DDD:::::DDDDD:::::D  U:::::::UUU:::::::UA:::::A             A:::::A        X::::::X     X::::::XEE::::::EEEEEEEE:::::E" << endl;
		cout << "                    D:::::::::::::::DD    UU:::::::::::::UUA:::::A               A:::::A       X:::::X       X:::::XE::::::::::::::::::::E" << endl;
		cout << "                    D::::::::::::DDD        UU:::::::::UU A:::::A                 A:::::A      X:::::X       X:::::XE::::::::::::::::::::E" << endl;
		cout << "                    DDDDDDDDDDDDD             UUUUUUUUU  AAAAAAA                   AAAAAAA     XXXXXXX       XXXXXXXEEEEEEEEEEEEEEEEEEEEEE" << endl;

		int x = 57;
		int y = 35;
		TextColor(10);
		gotoxy(x,y); cout<<"1.Start Game";
		TextColor(13);
		gotoxy(x+21,y); cout<<"2.Game Guide";
		TextColor(8);
		gotoxy(x+13,y+2); cout<<"3.Quit";		
		TextColor(11);
		gotoxy(x-16,y+6); cout << "------------------A43019 Tran Van Tien (Hecker 15 age)------------------";
		TextColor(14);
		gotoxy(x+10,y+4); cout<<"Select option: ";
		
		char bam = getche();
		
		if( bam =='1'){
			play();
		} 
		else if( bam =='2'){
			huongDan();
		} 
		else if( bam =='3'){
			exit(0);
		} 
		
	}
	return 0;
}
