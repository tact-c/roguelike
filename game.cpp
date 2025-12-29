#ifdef _WIN32
#include <windows.h>
void enableVTMode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) return;

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
}
#else
void enableVTMode(){}
#endif
import std;
class Room{
	public:
	int roomwidth;
	int roomheight;
	int initxcoord;
	int initycoord;
	Room(int x, int y, int initx, int inity){
		roomwidth=x;
		roomheight=y;
		initxcoord=initx;
		initycoord=inity;}
};

class Player{
	public:
		int xcoord;
		int ycoord;
		Player(Room currentroom){
			xcoord=currentroom.initxcoord;
			ycoord=currentroom.initycoord;}
		void movement(Room currentroom, char x){
			switch(x){
				case 'w':
					if(ycoord>0){
						ycoord--;
					}
					break;
				case 's':
					if(ycoord<currentroom.roomheight){
						ycoord++;
					}
					break;
				case 'a':
					if(xcoord>0){
						xcoord--;
					}
					break;
				case 'd':
					if(xcoord<currentroom.roomwidth){
						xcoord++;
					}
					break;
				default: break;
			}
			for(int a = 0; a<currentroom.roomheight; a++){
				for(int b = 0; b<currentroom.roomwidth; b++){
					if(xcoord==b && ycoord==a){
						std::print("@");
					} else std::print("#");
				}
				std::print("\n");
			}
		}
};

int main(){
	Room room(10, 10, 4, 4);
	Player player(room);
	enableVTMode();
	char a;
	while(1){
		std::cin.get(a);
		std::println("\033[2J\033[H");
		player.movement(room,a);
	}
	return 0;
}
