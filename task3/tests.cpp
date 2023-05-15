#include "tests.h"
#include "ISort.h"
#include "matrix.h"
#include <vector>
#include <iostream>

bool firstTest() {
	bool result = true;
	matrix unsort;
	unsort.fillingArrayFromFile("testFile.txt");

	matrix sorted;
	sorted.fillingArrayFromFile("sortedMatrixForTests.txt");

	bubble bubSort{};
	bubSort.Sort(unsort);
	for (int i = 0; i < 3; i++)
		if (result)
			for (int j = 0; j < 3; j++)
				if (unsort[i][j] != sorted[i][j])
					result = false;

	if (bubSort.getCompares() != 9 || bubSort.getPermutations() != 3) {
		result = false;
	}

	if (!result) {
		std::cout << "Тест провален." << std::endl;
		std::cout << "Ожидаемый результат:" << std::endl;
		sorted.showArray();
		std::cout << "Кол-во сравнений: " << 9 << "\nКол-во перестановок: " << 3 << std::endl;
		std::cout << "\nПолученный результат:" << std::endl;
		unsort.showArray();
		std::cout << "Кол-во сравнений: " << bubSort.getCompares() << "\nКол-во перестановок: " << bubSort.getPermutations() << std::endl;
	}
	return result;
}

bool secondTest() {
	bool result = true;
	matrix unsort;
	unsort.fillingArrayFromFile("testFile.txt");

	matrix sorted;
	sorted.fillingArrayFromFile("sortedMatrixForTests.txt");

	selection selSort{};
	selSort.Sort(unsort);
	for (int i = 0; i < 3; i++)
		if (result)
			for (int j = 0; j < 3; j++)
				if (unsort[i][j] != sorted[i][j])
					result = false;

	if (selSort.getCompares() != 9 || selSort.getPermutations() != 3) {
		result = false;
	}

	if (!result) {
		std::cout << "Тест провален." << std::endl;
		std::cout << "Ожидаемый результат:" << std::endl;
		sorted.showArray();
		std::cout << "Кол-во сравнений: " << 9 << "\nКол-во перестановок: " << 3 << std::endl;
		std::cout << "\nПолученный результат:" << std::endl;
		unsort.showArray();
		std::cout << "Кол-во сравнений: " << selSort.getCompares() << "\nКол-во перестановок: " << selSort.getPermutations() << std::endl;
	}
	return result;
}

bool thirdTest() {
	bool result = true;
	matrix unsort;
	unsort.fillingArrayFromFile("testFile.txt");

	matrix sorted;
	sorted.fillingArrayFromFile("sortedMatrixForTests.txt");

	insertion insSort{};
	insSort.Sort(unsort);
	for (int i = 0; i < 3; i++)
		if (result)
			for (int j = 0; j < 3; j++)
				if (unsort[i][j] != sorted[i][j])
					result = false;

	if (insSort.getCompares() != 3 || insSort.getPermutations() != 5) {
		result = false;
	}

	if (!result) {
		std::cout << "Тест провален." << std::endl;
		std::cout << "Ожидаемый результат:" << std::endl;
		sorted.showArray();
		std::cout << "Кол-во сравнений: " << 3 << "\nКол-во перестановок: " << 5 << std::endl;
		std::cout << "\nПолученный результат:" << std::endl;
		unsort.showArray();
		std::cout << "Кол-во сравнений: " << insSort.getCompares() << "\nКол-во перестановок: " << insSort.getPermutations() << std::endl;
	}
	return result;
}

bool fourthTest() {
	bool result = true;
	matrix unsort;
	unsort.fillingArrayFromFile("testFile.txt");

	matrix sorted;
	sorted.fillingArrayFromFile("sortedMatrixForTests.txt");

	shell shellSort{};
	shellSort.Sort(unsort);
	for (int i = 0; i < 3; i++)
		if (result)
			for (int j = 0; j < 3; j++)
				if (unsort[i][j] != sorted[i][j])
					result = false;

	if (shellSort.getCompares() != 3 || shellSort.getPermutations() != 3) {
		result = false;
	}

	if (!result) {
		std::cout << "Тест провален." << std::endl;
		std::cout << "Ожидаемый результат:" << std::endl;
		sorted.showArray();
		std::cout << "Кол-во сравнений: " << 3 << "\nКол-во перестановок: " << 3 << std::endl;
		std::cout << "\nПолученный результат:" << std::endl;
		unsort.showArray();
		std::cout << "Кол-во сравнений: " << shellSort.getCompares() << "\nКол-во перестановок: " << shellSort.getPermutations() << std::endl;
	}
	return result;
}

bool fifthTest() {
	bool result = true;
	matrix unsort;
	unsort.fillingArrayFromFile("testFile.txt");

	matrix sorted;
	sorted.fillingArrayFromFile("sortedMatrixForTests.txt");

	quick quickSort{};
	quickSort.Sort(unsort);
	for (int i = 0; i < 3; i++)
		if (result)
			for (int j = 0; j < 3; j++)
				if (unsort[i][j] != sorted[i][j])
					result = false;

	if (quickSort.getCompares() != 5 || quickSort.getPermutations() != 3) {
		result = false;
	}

	if (!result) {
		std::cout << "Тест провален." << std::endl;
		std::cout << "Ожидаемый результат:" << std::endl;
		sorted.showArray();
		std::cout << "Кол-во сравнений: " << 5 << "\nКол-во перестановок: " << 3 << std::endl;
		std::cout << "\nПолученный результат:" << std::endl;
		unsort.showArray();
		std::cout << "Кол-во сравнений: " << quickSort.getCompares() << "\nКол-во перестановок: " << quickSort.getPermutations() << std::endl;
	}
	return result;
}

void mainTest() {
	std::cout << std::endl;
	bool firstCheck = firstTest();
	std::cout << std::endl;
	if (firstCheck) {
		std::cout << "Первый модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Первый модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	bool secondCheck = secondTest();
	std::cout << std::endl;
	if (secondCheck) {
		std::cout << "Второй модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Второй модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	bool thirdCheck = thirdTest();
	std::cout << std::endl;
	if (thirdCheck) {
		std::cout << "Третий модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Третий модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	bool fourthCheck = fourthTest();
	std::cout << std::endl;
	if (fourthCheck) {
		std::cout << "Четвертый модульный тест пройден." << std::endl;
	}
	else {
		std::cout << "Четвертый модульный тест не пройден." << std::endl;
	}
	std::cout << std::endl;
	bool fifthCheck = fifthTest();
	std::cout << std::endl;
	if (fifthCheck) {
		std::cout << "Пятый модульный тест пройден.\n" << std::endl;
	}
	else {
		std::cout << "Пятый модульный тест не пройден.\n" << std::endl;
	}
}