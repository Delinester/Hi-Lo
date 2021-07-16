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
	std::cout << "Я генерирую число от 1 до 100. Ваша задача его угадать, дается 7 попыток.\n";
	std::cout << "Начинаем!\n\n";
	for (short tries = 1, guessNumber; tries != 8; tries++) {
		std::cout << "Попытка номер " << tries << ":";
		std::cin >> guessNumber;
		while (std::cin.fail() || guessNumber > 100) {
			std::cin.clear();
			std::cin.ignore(128, '\n');
			std::cout << "Ошибка ввода, повторите: ";
			std::cin >> guessNumber;
		}
		if (guessNumber > generatedNumber) std::cout << "\nВведенное Вами число больше сгенерированного.\n";
		if (guessNumber < generatedNumber) std::cout << "\nВведенное Вами число меньше сгенерированного.\n";
		if (guessNumber == generatedNumber) {
			std::cout << "\nВерно! Вы правильно угадали сгенерированное число!\n";
			gameEnd();
			break;
		}
		if (tries == 7) {
			std::cout << "К сожалению, Вы проиграли. Сгенерированным числом оказалось " << generatedNumber << std::endl;
			gameEnd();
		}
	}
}
void gameEnd() {
	char check;
	do {
		std::cout << "Введите y, если хотите повторить, или n, если хотите выйти из игры: ";
		std::cin >> check;
		std::cin.ignore(128, '\n');
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(128, '\n');
			std::cout << "Ошибка ввода, повторите: ";
			std::cin >> check;
		}
		switch (check) {
		case 'y':
			system("CLS");
			gameStart();
		case 'n':
			std::cout << "Спасибо за игру!";
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