#include "Player.h"

Player::Player() {
	Name = "\0";
}

Player::Player(string s) {
	Name = s;
}

Player::~Player() {
}

//void Player::View_Name() {
	//cout << Name << endl << endl;
//}

//void Player::View_Level() {
	//cout << Level << endl << endl;
//}