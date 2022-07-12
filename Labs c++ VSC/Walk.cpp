//*
//1. updatera walk.cpp till kodstandarden så den blir enklare att läsa
//2. Dela upp koden i följande 4 sektioner * DECLARATIONS * *INIT * *LOOP * *FUNCTIONS *
//3. Gör en generell funktion för movePlayer och moveBandit.Notera att det är exakt samma värden som sätts.
//* /

#include <climits>
#include <ctime>
#include <iostream>
#include <random>
#include <string>

using namespace std;

/**
 * DUNGEON: a simple game for the terminal. The objective of the
 * game is that the player ("P") reaches the treasure ("X")
 * avoiding the traps ("T") and the bandits ("B").
 * Bandits move randomly each turn.
 * */
const int NUMBEROFTRAPS = 3;
const int NUMBEROFBANDITS = 2;

// Represents a place in the board.
// xPosition is the x-axis index and yPosition is the y-axis index
struct Location {
	int xPosition;
	int yPosition;
};

// Represents the player.
// It is guaranteed Player position is in the board.
// Position is altered through function movePlayer.
struct Player {
	Location position;
	char symbol = 'P';
	std::string name = "player";
};

// Represents traps on the board
// It is guarateed Trap position is in the board.
struct Trap {
	Location position;
	char symbol = 'T';
};

// Represents Bandits moving around the map.
// Position is altered through funtion moveBandit.
struct Bandit {
	Location position;
	char symbol = 'B';
};

// Represents the treasure.
// The game ends as soon Player.position == Treasure.position
struct Treasure {
	Location position;
	char symbol = 'X';
};

// Represents the board.
struct
{
	int xDimension;
	int yDimension;
} board = { .xDimension = 10, .yDimension = 10 };

// Possible directions. WRONG_DIRECTION is used to report incorrect input
enum Direction { RIGHT, LEFT, TOP, BOTTOM, WRONG_DIRECTION };
enum Result { VICTORY, DEFEAT };

void drawBoard(Player, Trap[], Bandit[], Treasure);
void endGame(Result);
void movePlayer(Player&, Direction);
void moveBandit(Bandit&);
Direction askDirection();

//int main() {
//	std::srand(std::time(0));
//
//	// Treasure position is decided randomly.
//	Treasure treasure = {
//		.position = {.xPosition = std::rand() % board.xDimension,
//					 .yPosition = std::rand() % board.yDimension} };
//
//	// Traps are placed around the map. It is not guaranteed
//	// that traps position doesn't converge.
//	// In that case, the second trap can be assumed to not exist.
//	Trap trapsInMap[NUMBEROFTRAPS];//Här skulle man kunna lägga till kod som fixar detta.
//	for (int i = 0; i < NUMBEROFTRAPS; i++) {
//		int xPos = std::rand() % board.xDimension;
//		int yPos = std::rand() % board.yDimension;
//		Trap trap = { .position = {.xPosition = xPos, .yPosition = yPos} };
//		trapsInMap[i] = trap;
//	}
//
//	// Bandits are placed around the map. It is not guaranteed
//	// that bandits position doesn't converge, but they will move
//	// anyway.
//	Bandit banditsInMap[NUMBEROFBANDITS];
//	for (int i = 0; i < NUMBEROFBANDITS; i++) {
//		int xPos = std::rand() % board.xDimension;
//		int yPos = std::rand() % board.yDimension;
//		Bandit bandit = { .position = {.xPosition = xPos, .yPosition = yPos} };
//		banditsInMap[i] = bandit;
//	}
//
//	// Player position on the 1st turn is randomly decided.
//	// It can not be the same of a bandit or a trap.
//	bool match = false;
//	int xPos;
//	int yPos;
//	do {
//		xPos = std::rand() % board.xDimension;
//		yPos = std::rand() % board.yDimension;
//		for (int i = 0; i < NUMBEROFTRAPS; i++) {
//			if ((xPos == trapsInMap[i].position.xPosition &&
//				yPos == trapsInMap[i].position.yPosition) ||
//				(xPos == banditsInMap[i].position.xPosition &&
//					yPos == banditsInMap[i].position.yPosition)) {
//				match = true;
//			}
//		}
//	} while (match);
//
//	Player player = { .position = {.xPosition = xPos, .yPosition = yPos} };
//
//	// The order of the turn is the following:
//	// 1. Board is drawn.
//	// 2. User is asked for movement direction.
//	// 3. Player moves in the chosen direction.
//	// 4. Bandits move.
//	int maxTurnos = INT_MAX;
//	for (int i = 0; i <= maxTurnos; i++) {
//		drawBoard(player, trapsInMap, banditsInMap, treasure);
//		Direction direction;
//		do {
//			direction = askDirection();
//			std::cout << std::endl;
//		} while (direction == WRONG_DIRECTION);
//		movePlayer(player, direction);
//		for (int i = 0; i < NUMBEROFBANDITS; i++) {
//			moveBandit(banditsInMap[i]);
//		}
//		std::cout << "\x1B[2J\x1B[H";
//	}
//}

void drawBoard(
	/* in */ Player player,
	/* in */ Trap totalTraps[],
	/* in */ Bandit totalBandits[],
	/* in */ Treasure treasure)

	// Draws a (board.xDimension * board.yDimension) grid.
	// Elements are drawn using .location.?Dimensions.

	// Precondition: 0 <= Player.xPosition <= board.xDimension &&
	//      0 <= player.position.yPosition <= board.yDimension  &&
	//      board.xDimension > 0  && board.yDimension > 0 &&
	// Postcondition: The grid has been drawn.
	//      All elements have been drawn.
	//      If the player is in the same square than the treasure,
	//      the game ends with victory.
	//      If the player is in the same square than a bandit or
	//      a trap, the game ends with defeat.
{
	bool squareDrawn = false;
	for (int y = 0; y <= board.yDimension; y++) {
		for (int x = 0; x <= board.xDimension; x++) {
			// Traps are drawn
			for (int z = 0; z <= NUMBEROFTRAPS; z++) {
				Trap trapToDraw = totalTraps[z];
				if (trapToDraw.position.xPosition == x &&
					trapToDraw.position.yPosition == y) {
					std::cout << trapToDraw.symbol;
					squareDrawn = true;
				}
			}
			// Bandits are drawn.
			// In case of collision with a trap,
			// only the second is drawn.
			for (int z = 0; z <= NUMBEROFBANDITS; z++) {
				Bandit banditToDraw = totalBandits[z];
				if (banditToDraw.position.xPosition == x &&
					banditToDraw.position.yPosition == y && !squareDrawn) {
					std::cout << banditToDraw.symbol;
					squareDrawn = true;
				}
			}

			// Treasure is drawn. If position of treasure == position of player
			// game ends with victory
			if (x == treasure.position.xPosition &&
				y == treasure.position.yPosition) {
				if (treasure.position.xPosition == player.position.xPosition &&
					treasure.position.yPosition == player.position.yPosition) {
					endGame(VICTORY);
				}

				std::cout << "X";
				continue;
			}

			if (x == player.position.xPosition && y == player.position.yPosition) {
				if (squareDrawn)
					endGame(DEFEAT);
				std::cout << "P";
				continue;
			}
			// Empty square "." is drawn. It only gets printed if there is nothing
			// on the square.
			if (!squareDrawn)
				std::cout << ".";
			squareDrawn = false;
		}
		std::cout << std::endl;
	}
}

Direction askDirection() {

	// Asks the user to input a direction and returns it.
	// Precondition: -
	// Poscondition:
	// Return: a Direction value containing the direction chosen or
	// WRONG_DIRECTION.

	std::cout << "Select [L/A]eft, [R/D]ight, [T/W]op or [B/S]ottom: ";
	char answer;
	std::cin.get(answer);

	Direction chosenDirection;
	switch (std::toupper(answer)) { // Fixa styling
	case 'L':
	case 'A':
		chosenDirection = LEFT;
		break;
	case 'R':
	case 'D':
		chosenDirection = RIGHT;
		break;
	case 'T':
	case 'W':
		chosenDirection = TOP;
		break;
	case 'B':
	case 'S':
		chosenDirection = BOTTOM;
		break;
	default:
		chosenDirection = WRONG_DIRECTION;
	}
	return chosenDirection;
}

void movePlayer(
	/* inout */ Player& player,   // Player of the game
	/* in */ Direction direction) // Direction previously chosen.
								  // It is represented by a Direction object,
								  // different from WRONG_DIRECTION.

// Moves player in the chosen direction, by altering its coordinates. If the
// player would finish out of the board, no movement is made.

// Precondition: 0 <= Player.xPosension <= board.xDimension &&
//        0 <= player.position.yPosition <= board.yDimension  &&
//        board.xDimension > 0  && board.yDimension > 0 &&
//        direction in {LEFT; RIGHT; TOP; BOTTOM} &&
// Postcondition: player coordinates have been altered &&
//        player remains inside the board.
{
	switch (direction) {
	case RIGHT:
		if (player.position.xPosition < board.xDimension)
			player.position.xPosition += 1;
		break;
	case LEFT:
		if (player.position.xPosition > 0)
			player.position.xPosition -= 1;
		break;
	case TOP:
		if (player.position.yPosition > 0)
			player.position.yPosition -= 1;
		break;
	case BOTTOM:
		if (player.position.yPosition < board.yDimension)
			player.position.yPosition += 1;
		break;
	}
}

void moveBandit(
	/* inout */ Bandit& bandit) // Player of the game
								// It is represented by a Direction object,
								// different from WRONG_DIRECTION.

// Moves player in the chosen direction, by altering its coordinates. If the
// player would finish out of the board, no movement is made.

// Precondition: 0 <= Player.xPosension <= board.xDimension &&
//        0 <= player.position.yPosition <= board.yDimension  &&
//        board.xDimension > 0  && board.yDimension > 0 &&
//        direction in {LEFT; RIGHT; TOP; BOTTOM} &&
// Postcondition: player coordinates have been altered &&
//        player remains inside the board.
{

	int direction = std::rand() % 4;
	switch (direction) {
	case 0:
		if (bandit.position.xPosition < board.xDimension)
			bandit.position.xPosition += 1;
		break;
	case 1:
		if (bandit.position.xPosition > 0)
			bandit.position.xPosition -= 1;
		break;
	case 2:
		if (bandit.position.yPosition > 0)
			bandit.position.yPosition -= 1;
		break;
	case 3:
		if (bandit.position.yPosition < board.yDimension)
			bandit.position.yPosition += 1;
		break;
	}
}

void endGame(
	/* in */ Result result) // Result of the game.
							// It is either VICTORY or DEFEAT
// Cleans screen, prints a good bye message
// and ends the game.
// Precondition: a condition for ending the game has been found.
//              Either player.position == bandit.position ||
//              player.position == trap.position [DEFEAT]
//              or player.position == treasure.position [VICTORY]
// Poscondition: game is ended. Greeting message is printed.
{
	std::string announcement = (result == VICTORY) ? "YOU WIN" : "GAME OVER";
	std::cout << "\x1B[2J\x1B[H"; // Resets terminal
	std::cout << std::endl << std::endl;
	std::cout << "===========================" << std::endl;
	std::cout << "||\t\t\t||" << std::endl;
	std::cout << "||\t" << announcement << "\t\t||" << std::endl;
	std::cout << "||\t\t\t||" << std::endl;
	std::cout << "===========================" << std::endl;
	exit(1);
}