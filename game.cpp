#include <cstdio>
#include <iostream>

class Player{
	public:
		int plcoordx;
		int plcoordy;
		int currentroomwidth;
		int currentroomheight;
		void movepl(char input){
			switch(input){
				case 'w':
					if(plcoordy>0){
						plcoordy--;}
					else break;
					break;
				case 's':
					if(plcoordy<currentroomheight-1){
						plcoordy++;}
					else break;
					break;
				case 'a':
					if(plcoordx>0){
						plcoordx--;}
					else break;
					break;
				case 'd':
					if(plcoordx<currentroomwidth-1){
						plcoordx++;}
					else break;
					break;
				default: break;}
		}
};

class Room{
	public:
		int roomwidth;
		int roomheight;
		int roominitx;
		int roominity;
		void render(Player prototype){
			for(int y=0; y<roomheight; y++){
				for(int x=0; x<roomwidth; x++){
					if(prototype.plcoordx==x&&prototype.plcoordy==y){
						std::cout<<'@';
					}
					else std::cout<<'#';
				}
				std::cout<<std::endl;
			}
		}
};

int main(){
	Player player;
	Room room;
	room.roomheight=10;
	room.roomwidth=10;
	room.roominitx=5;
	room.roominity=9;
	player.currentroomheight=room.roomheight;
	player.currentroomwidth=room.roomwidth;
	player.plcoordx=room.roominitx;
	player.plcoordy=room.roominity;
	do{
		std::cout<<"\033[2J\033[H"<<std::endl;
		room.render(player);
		player.movepl(getchar());
		}while(1);
}
