#include <iostream>
#include <cstdlib>

const short minNumber = 1;
const short maxNumber = 100;

void gameEnd();
short randomize(short min, short max) {
	return max - rand() % (max - min + 1);
}
void gameStart() {
	short generatedNumber = randomize(minNumber, maxNumber);
	std::cout << "� ��������� ����� �� 1 �� 100. ���� ������ ��� �������, ������ 7 �������.\n";
	std::cout << "��������!\n\n";
	for (short tries = 1, guessNumber; tries != 8; tries++) {
		std::cout << "������� ����� " << tries << ":";
		std::cin >> guessNumber;
		while (std::cin.fail() || guessNumber > 100) {
			std::cin.clear();
			std::cin.ignore(128, '\n');
			std::cout << "������ �����, ���������: ";
			std::cin >> guessNumber;
		}
		if (guessNumber > generatedNumber) std::cout << "\n��������� ���� ����� ������ ����������������.\n";
		if (guessNumber < generatedNumber) std::cout << "\n��������� ���� ����� ������ ����������������.\n";
		if (guessNumber == generatedNumber) {
			std::cout << "\n�����! �� ��������� ������� ��������������� �����!\n";
			gameEnd();
			break;
		}
		if (tries == 7) {
			std::cout << "� ���������, �� ���������. ��������������� ������ ��������� " << generatedNumber << std::endl;
			gameEnd();
		}
	}
}
void gameEnd() {
	char check;
	do {
		std::cout << "������� y, ���� ������ ���������, ��� n, ���� ������ ����� �� ����: ";
		std::cin >> check;
		std::cin.ignore(128, '\n');
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(128, '\n');
			std::cout << "������ �����, ���������: ";
			std::cin >> check;
		}
		switch (check) {
		case 'y':
			system("CLS");
			gameStart();
		case 'n':
			std::cout << "������� �� ����!";
			exit(0);
		}

	} while (check != 'y' || check != 'n');
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	gameStart();
	return 0;
}