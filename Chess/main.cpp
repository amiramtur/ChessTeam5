#include <iostream>
#include <thread>
#include "Board.h"
#include "Point.h"
#include "Pipe.h"

#define BLACK_STR "black"
#define WHITE_STR "WHITE"

#define WELCOME_MSG R"(  ____ _   _ _____ ____ ____  
 / ___| | | | ____/ ___/ ___| 
| |   | |_| |  _| \___ \___ \ 
| |___|  _  | |___ ___) |__) |
 \____|_| |_|_____|____/____/ )" << "\n"; // reads: "CHESS"


 int main()
 {
	 // variable setting
	 // c#
	 srand(time_t(NULL));
	 Pipe p;
	 bool isConnect = p.connect();
	 std::string ans;
	 char msgToGraphics[1024];
	 std::string msgFromGraphics = "";
	 std::string board_str = "ab";
	 int code = 0;

	 // c++
	 Board board = Board();
	 int turn = board.get_turn(), input = 0, flag = 1;
	 int source_point, destination_point;
	 std::string cords1 = " ", cords2 = " ";


	 // connection
	 std::cout << WELCOME_MSG;
	 while (!isConnect)
	 {
		 std::cout << "cant connect to graphics" << std::endl;
		 std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		 std::cin >> ans;

		 if (ans == "0")
		 {
			 std::cout << "trying connect again.." << std::endl;
			 Sleep(5000);
			 isConnect = p.connect();
		 }
		 else
		 {
			 p.close();
		 }
	 }

	 strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	 p.sendMessageToGraphics(msgToGraphics);
	 msgFromGraphics = p.getMessageFromGraphics();

	 // game loop
	 while (msgFromGraphics != "quit")
	 {
		 cords1[0] = msgFromGraphics[0];
		 cords1[1] = msgFromGraphics[1];
		 cords2[0] = msgFromGraphics[2];
		 cords2[1] = msgFromGraphics[3];
		 code = board.move(Point::get_index(cords1), Point::get_index(cords2));
		 board_str = (char)code + 48;
		 strcpy_s(msgToGraphics, board_str.c_str());
		 p.sendMessageToGraphics(msgToGraphics);
		 std::cout << msgToGraphics;

		 msgFromGraphics = p.getMessageFromGraphics();
	 }
 }