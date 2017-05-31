#include <iostream>
#include "Skeleton.h"
#include "Halberdier.h"
#include <cstdlib>
using namespace std;
void draw(char** map, int y, int x, char pl) {
	system("cls");
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (i == 0 || i == 11) {
				cout << "_";
			}
			else if (j == 0 || j == 11) {
				cout << "|";
			}
			else {
				if (i - 1 == y && j - 1 == x) {
					cout << pl;
				}
				else
				{
					cout << map[i - 1][j - 1];
				}

			}
		}
		cout << endl;
	}
}
int main() {
	bool end = false;
	int side = 3;
	char** map = new char*[10];
	for (int i = 0; i < 10; i++) {
		map[i] = new char[10];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = ' ';
		}
	}
	int army = 0, opponentArmy = 0;
	while (side > 2) {
		cout << "Choose ur side. 1 - light 2 - dark" << endl;
		cin >> side;
	}
	while (!(army > 0 && army < 11)) {
		cout << "Enter the size of yours army(1-10)" << endl;
		cin >> army;
	}
	while (!(opponentArmy > 1 && opponentArmy < 11)) {
		cout << "Enter the size of opponents army(1-10)" << endl;
		cin >> opponentArmy;
	}
	Halberdier* hUnits;
	Skeleton* sUnits;
	if (side == 1) {
		hUnits = new Halberdier[army];

		for (int i = 0; i < army; i++) {
			hUnits[i] = new Halberdier();
			hUnits[i].coordY = i;
			map[i][0] = 'h';
		}

		sUnits = new Skeleton[opponentArmy];

		for (int i = 0; i < opponentArmy; i++) {
			sUnits[i] = new Skeleton();
			sUnits[i].coordY = i;
			sUnits[i].coordX = 9;
			map[i][9] = 's';
		}
	}
	else {
		sUnits = new Skeleton[army];

		for (int i = 0; i < army; i++) {
			sUnits[i] = new Skeleton();
			sUnits[i].coordY = i;
			sUnits[i].coordX = 9;
			map[i][9] = 's';
		}

		hUnits = new Halberdier[opponentArmy];

		for (int i = 0; i < opponentArmy; i++) {
			hUnits[i] = new Halberdier();
			hUnits[i].coordY = i;
			map[i][0] = 'h';
		}
	}
	while (!end) {
		draw(map, hUnits[0].coordY, hUnits[0].coordX, 'H');
		cout << "1st player turn" << endl;
		for (int i = 0; i < army; i++) {
			hUnits[i].stamina = 2;
			if (side == 1) {
				while (hUnits[i].stamina > 0) {
					draw(map, hUnits[i].coordY, hUnits[i].coordX, 'H');
					cout << "Hp: " << hUnits[i].hp << endl;
					cout << "Damage: " << hUnits[i].damage << endl;
					cout << "Stamina: " << hUnits[i].stamina << endl;
					if (hUnits[i].coordY > 0) {
						if (map[hUnits[i].coordY - 1][hUnits[i].coordX] == ' ') {
							cout << "Press \"W\" to move Up" << "\n";
						}
						if (map[hUnits[i].coordY - 1][hUnits[i].coordX] == 's') {
							cout << "Press \"W\" to attack top enemy" << endl;
						}
					}
					if (hUnits[i].coordY < 9) {
						if (map[hUnits[i].coordY + 1][hUnits[i].coordX] == ' ') {
							cout << "Press \"S\" to move Down" << endl;
						}
						if (map[hUnits[i].coordY + 1][hUnits[i].coordX] == 's') {
							cout << "Press \"S\" to attack bottom enemy" << endl;
						}
					}
					if (hUnits[i].coordX < 9) {
						if (map[hUnits[i].coordY][hUnits[i].coordX + 1] == ' ') {
							cout << "Press \"D\" to move Right" << endl;
						}
						if (map[hUnits[i].coordY][hUnits[i].coordX + 1] == 's') {
							cout << "Press \"D\" to attack right enemy" << endl;
						}
					}
					if (hUnits[i].coordX > 0) {
						if (map[hUnits[i].coordY][hUnits[i].coordX - 1] == ' ') {
							cout << "Press \"A\" to move Left" << endl;
						}
						if (map[hUnits[i].coordY][hUnits[i].coordX - 1] == 's') {
							cout << "Press \"A\" to attack left enemy" << endl;
						}
					}
					char turn = ' ';
					bool nextAction = false;
					while (!nextAction) {
						cin >> turn;
						if ((turn == 'D' || turn == 'd') && hUnits[i].coordX < 9) {
							if (map[hUnits[i].coordY][hUnits[i].coordX + 1] == ' ') {
								hUnits[i].coordX += 1;
								map[hUnits[i].coordY][hUnits[i].coordX] = 'h';
								map[hUnits[i].coordY][hUnits[i].coordX - 1] = ' ';
								nextAction = true;
								hUnits[i].stamina -= 1;
							}
							else if (map[hUnits[i].coordY][hUnits[i].coordX + 1] == 's') {

								for (int k = 0; k < opponentArmy; k++) {
									if (sUnits[k].coordY == hUnits[i].coordY && sUnits[k].coordX - 1 == hUnits[i].coordX) {
										sUnits[k].hp -= hUnits[i].damage;
										sUnits[k].isAlive = sUnits[k].hp > 0;
										if (!(sUnits[k].isAlive)) {
											map[sUnits[k].coordY][sUnits[k].coordX] = ' ';
										}
									}
								}
								nextAction = true;
								hUnits[i].stamina -= 1;

							}
							draw(map, hUnits[i].coordY, hUnits[i].coordX, 'H');
						}
						else if (turn == 'W' || turn == 'w' && hUnits[i].coordY > 0) {
							if (map[hUnits[i].coordY - 1][hUnits[i].coordX] == ' ') {
								hUnits[i].coordY -= 1;
								map[hUnits[i].coordY][hUnits[i].coordX] = 'h';
								map[hUnits[i].coordY + 1][hUnits[i].coordX] = ' ';
								nextAction = true;
								hUnits[i].stamina -= 1;
							}
							else if (map[hUnits[i].coordY - 1][hUnits[i].coordX] == 's') {
								for (int k = 0; k < opponentArmy; k++) {
									if (sUnits[k].coordY == hUnits[i].coordY - 1 && sUnits[k].coordX == hUnits[i].coordX) {
										sUnits[k].hp -= hUnits[i].damage;
										sUnits[k].isAlive = sUnits[k].hp > 0;
										if (!(sUnits[k].isAlive)) {
											map[sUnits[k].coordY][sUnits[k].coordX] = ' ';
										}
									}
								}
								nextAction = true;
								hUnits[i].stamina -= 1;
							}
						}
						else if ((turn == 'A' || turn == 'a') && hUnits[i].coordX > 0) {
							if (map[hUnits[i].coordY][hUnits[i].coordX - 1] == ' ') {
								hUnits[i].coordX -= 1;
								map[hUnits[i].coordY][hUnits[i].coordX] = 'h';
								map[hUnits[i].coordY][hUnits[i].coordX + 1] = ' ';
								nextAction = true;
								hUnits[i].stamina -= 1;
							}
							else if (map[hUnits[i].coordY][hUnits[i].coordX - 1] == 's') {
								for (int k = 0; k < opponentArmy; k++) {
									if (sUnits[k].coordY == hUnits[i].coordY && sUnits[k].coordX + 1 == hUnits[i].coordX) {
										sUnits[k].hp -= hUnits[i].damage;
										sUnits[k].isAlive = sUnits[k].hp > 0;
										if (!(sUnits[k].isAlive)) {
											map[sUnits[k].coordY][sUnits[k].coordX] = ' ';
										}
									}
								}
								nextAction = true;
								hUnits[i].stamina -= 1;
							}
							nextAction = true;
						}
						else if ((turn == 'S' || turn == 's') && hUnits[i].coordY < 9) {
							if (map[hUnits[i].coordY + 1][hUnits[i].coordX] == ' ') {
								hUnits[i].coordY += 1;
								map[hUnits[i].coordY][hUnits[i].coordX] = 'h';
								map[hUnits[i].coordY - 1][hUnits[i].coordX] = ' ';
								nextAction = true;
								hUnits[i].stamina -= 1;
							}
							else if (map[hUnits[i].coordY + 1][hUnits[i].coordX] == 's') {
								for (int k = 0; k < opponentArmy; k++) {
									if (sUnits[k].coordY == hUnits[i].coordY + 1 && sUnits[k].coordX == hUnits[i].coordX) {
										sUnits[k].hp -= hUnits[i].damage;
										sUnits[k].isAlive = sUnits[k].hp > 0;
										if (!(sUnits[k].isAlive)) {
											map[sUnits[k].coordY][sUnits[k].coordX] = ' ';
										}
									}
								}
								nextAction = true;
								hUnits[i].stamina -= 1;
							}

						}
					}
				}
			}
			else
			{
				cout << "Hp: " << sUnits[i].hp << endl;
				cout << "Damage: " << sUnits[i].damage << endl;
				cout << "Stamina: " << sUnits[i].stamina << endl;
				if (sUnits[i].coordY > 1 && map[sUnits[i].coordX][sUnits[i].coordY + 1] == ' ') {
					cout << "Press \"W\" to move Up" << endl;
				}
				if (sUnits[i].coordY < 9 && map[sUnits[i].coordX][sUnits[i].coordY - 1] == ' ') {
					cout << "Press \"S\" to move Down" << endl;
				}
				if (sUnits[i].coordX > 1 && map[sUnits[i].coordX + 1][sUnits[i].coordY] == ' ') {
					cout << "Press \"D\" to move Right" << endl;
				}
				if (sUnits[i].coordX < 9 && map[sUnits[i].coordX - 1][sUnits[i].coordY] == ' ') {
					cout << "Press \"A\" to move Left" << endl;
				}
			}
		}
	}
	return 0;
}