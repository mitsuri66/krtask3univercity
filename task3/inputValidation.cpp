#include "inputValidation.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>

int getInt() {
	int input = 0;

	while (true) {
		if (!(std::cin >> input)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "\nОшибка ввода, повторите: ";
		}
		else {
			break;
		}
	}
	while (std::cin.get() != '\n');
	return input;
}

int getPositiveInt() {
	int input = 0;

	while (true) {
		if (!(std::cin >> input) || input < 0) {
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "\nОшибка ввода, повторите: ";
		}
		else {
			break;
		}
	}
	while (std::cin.get() != '\n');
	return input;
}

int getRandomInt() {
	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(-100, 100);
	return dist(rng);
}

bool checkFilepath(const std::string filepath) {
	std::ifstream input(filepath);

	if (!std::ifstream(filepath)) {
		std::cout << "Файл не существует. Повторите ввод." << std::endl;
		input.close();
		return false;
	}

	std::error_code ec;
	if (!std::filesystem::is_regular_file(filepath, ec)) {
		std::cout << "Адрес содержит недопустимые значения. Повторите ввод." << std::endl;
		input.close();
		return false;
	}

	if (!input) {
		std::cout << "Загрузка запрещена. Повторите ввод." << std::endl;
		input.close();
		return false;
	}
	input.close();
	return true;
}