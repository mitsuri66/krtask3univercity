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
		std::cout << "���� ��������." << std::endl;
		std::cout << "��������� ���������:" << std::endl;
		sorted.showArray();
		std::cout << "���-�� ���������: " << 9 << "\n���-�� ������������: " << 3 << std::endl;
		std::cout << "\n���������� ���������:" << std::endl;
		unsort.showArray();
		std::cout << "���-�� ���������: " << bubSort.getCompares() << "\n���-�� ������������: " << bubSort.getPermutations() << std::endl;
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
		std::cout << "���� ��������." << std::endl;
		std::cout << "��������� ���������:" << std::endl;
		sorted.showArray();
		std::cout << "���-�� ���������: " << 9 << "\n���-�� ������������: " << 3 << std::endl;
		std::cout << "\n���������� ���������:" << std::endl;
		unsort.showArray();
		std::cout << "���-�� ���������: " << selSort.getCompares() << "\n���-�� ������������: " << selSort.getPermutations() << std::endl;
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
		std::cout << "���� ��������." << std::endl;
		std::cout << "��������� ���������:" << std::endl;
		sorted.showArray();
		std::cout << "���-�� ���������: " << 3 << "\n���-�� ������������: " << 5 << std::endl;
		std::cout << "\n���������� ���������:" << std::endl;
		unsort.showArray();
		std::cout << "���-�� ���������: " << insSort.getCompares() << "\n���-�� ������������: " << insSort.getPermutations() << std::endl;
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
		std::cout << "���� ��������." << std::endl;
		std::cout << "��������� ���������:" << std::endl;
		sorted.showArray();
		std::cout << "���-�� ���������: " << 3 << "\n���-�� ������������: " << 3 << std::endl;
		std::cout << "\n���������� ���������:" << std::endl;
		unsort.showArray();
		std::cout << "���-�� ���������: " << shellSort.getCompares() << "\n���-�� ������������: " << shellSort.getPermutations() << std::endl;
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
		std::cout << "���� ��������." << std::endl;
		std::cout << "��������� ���������:" << std::endl;
		sorted.showArray();
		std::cout << "���-�� ���������: " << 5 << "\n���-�� ������������: " << 3 << std::endl;
		std::cout << "\n���������� ���������:" << std::endl;
		unsort.showArray();
		std::cout << "���-�� ���������: " << quickSort.getCompares() << "\n���-�� ������������: " << quickSort.getPermutations() << std::endl;
	}
	return result;
}

void mainTest() {
	std::cout << std::endl;
	bool firstCheck = firstTest();
	std::cout << std::endl;
	if (firstCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool secondCheck = secondTest();
	std::cout << std::endl;
	if (secondCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool thirdCheck = thirdTest();
	std::cout << std::endl;
	if (thirdCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool fourthCheck = fourthTest();
	std::cout << std::endl;
	if (fourthCheck) {
		std::cout << "��������� ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "��������� ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool fifthCheck = fifthTest();
	std::cout << std::endl;
	if (fifthCheck) {
		std::cout << "����� ��������� ���� �������.\n" << std::endl;
	}
	else {
		std::cout << "����� ��������� ���� �� �������.\n" << std::endl;
	}
}