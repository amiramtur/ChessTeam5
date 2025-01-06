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
	std::cout << board.get_board_string() << std::endl;
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
		std::cout << board.get_board_string() << std::endl;
		std::cout << msgToGraphics;

		//turn = board.get_turn();
		//std::cout << "Current turn: ";
		//if (turn)
		//{
		//	std::cout << BLACK_STR << std::endl;
		//}
		//else
		//{
		//	std::cout << WHITE_STR << std::endl;
		//}
		//
		//std::cout << "Enter your choice: " << std::endl <<
		//	"1 | MOVE" << std::endl <<
		//	"2 | PRINT BOARD" << std::endl <<
		//	"0 | EXIT" << std::endl;

		//std::cin >> input;

		//switch (input)
		//{
		//case 1: // move
		//	std::cout << "Enter src cords:" << std::endl; 
		//	std::cin >> cords1; 
		//	std::cout << "Enter dst cords:" << std::endl;
		//	std::cin >> cords2;
		//	code = board.move(Point::get_index(cords1), Point::get_index(cords2)); 
		//	// build move code


		//	std::cout << board.get_board_string();
		//	strcpy_s(msgToGraphics, std::to_string(code).c_str());
		//	p.sendMessageToGraphics(msgToGraphics);
		//	msgFromGraphics = p.getMessageFromGraphics(); // !
		//	break; 
		//case 2: // print board
		//	std::cout << board.get_board_string();

		//	break;
		//case 0: 
		//	std::cout << "Goodbye!";
		//	p.close();
		//	//msgFromGraphics = "quit" //(exit game engine)
		//	break;
		//default:
		//	std::cout << "Invalid input! Try again." << std::endl;
		//}

		msgFromGraphics = p.getMessageFromGraphics();
	}
}

// GAME ENGINE

//#include "Pipe.h"
//#include <iostream>
//#include <thread>
//
//using std::cout;
//using std::endl;
//using std::string;
//
//
//void main()
//{
//	srand(time_t(NULL));
//
//
//	Pipe p;
//	bool isConnect = p.connect();
//
//	string ans;
//	while (!isConnect)
//	{
//		cout << "cant connect to graphics" << endl;
//		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
//		std::cin >> ans;
//
//		if (ans == "0")
//		{
//			cout << "trying connect again.." << endl;
//			Sleep(5000);
//			isConnect = p.connect();
//		}
//		else
//		{
//			p.close();
//			return;
//		}
//	}
//
//
//	char msgToGraphics[1024];
//	// msgToGraphics should contain the board string accord the protocol
//	// YOUR CODE
//
//	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
//
//	p.sendMessageToGraphics(msgToGraphics);   // send the board string
//
//	// get message from graphics
//	string msgFromGraphics = p.getMessageFromGraphics();
//
//	while (msgFromGraphics != "quit")
//	{
//		// should handle the string the sent from graphics
//		// according the protocol. Ex: e2e4           (move e2 to e4)
//
//		// YOUR CODE
//		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation
//
//		/******* JUST FOR EREZ DEBUGGING ******/
//		int r = rand() % 10; // just for debugging......
//		msgToGraphics[0] = (char)(1 + '0');
//		msgToGraphics[1] = 0;
//		/******* JUST FOR EREZ DEBUGGING ******/
//
//
//		// return result to graphics		
//		p.sendMessageToGraphics(msgToGraphics);
//
//		// get message from graphics
//		msgFromGraphics = p.getMessageFromGraphics();
//	}
//
//	p.close();
//}