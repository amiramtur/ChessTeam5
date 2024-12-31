#include <iostream>
#include "Board.h"

#define WELCOME_MSG R"(  ____ _   _ _____ ____ ____  
 / ___| | | | ____/ ___/ ___| 
| |   | |_| |  _| \___ \___ \ 
| |___|  _  | |___ ___) |__) |
 \____|_| |_|_____|____/____/ )" << "\n"; // reads: "CHESS"


int main()
{
	// variable setting
	Board board = Board();
	int turn = board.get_turn(), input = 0, flag = 1;
	int source_point, destination_point;

	std::cout << WELCOME_MSG;
	
	// game loop
	while (flag) // change after fusing with game engine
	{
		turn = board.get_turn();
		std::cout << "Enter your choice: " << std::endl <<
			"1 | MOVE" << std::endl <<
			"2 | " << std::endl <<
			"0 | EXIT" << std::endl;

		std::cin >> input;
		if (input == 1)
		{
			// move
		}
		else if (input == 0)
		{
			flag = 1; // change after fusing with game engine
			std::cout << "GOODBYE";
			//msgFromGraphics != "quit" (exit game engine)
		}
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