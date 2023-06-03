#include <iostream>
#include <iomanip>
#include "menuInterface.h"
#include "matrix.h"
#include "ISort.h"
#include "menuItems.h"
#include "inputValidation.h"
#include "tests.h"

void showGreetings() {
	std::cout << "������������!" << std::endl;
	std::cout << "����������� ������ �3. ������� �6" << std::endl;
	std::cout << "������ ��������: ������ ������\n" << "������ �424\n" << std::endl;
}

void showTaskText() {
	std::cout << "���������� ��������� ��������� ��� ���������� ������� ������ ��������:"
		<< "\n�����������, ������, �������, ����� � ������� ����������. ������� �� �����"
		<< "\n��������������� (���� ���) � ������������� (��� ������� �� �������) �������"
		<< "\n������. ��������� ������������� ������� ������������� �������, � �������"
		<< "\n���������� ������� ����� ��������� � ������������ ���������� � ������"
		<< "\n������ ����������.\n"
		<< "\n����������� ������ ������ ������� �� �������� ����� �������� ����"
		<< "\n��������� �������.\n" << std::endl;
}

void showMainMenu() {
	std::cout << "�������� ����� ����:" << std::endl;
	std::cout << "1 - ������ �������� ������ � ����������" << std::endl;
	std::cout << "2 - ��������� �������� ������ �� �����" << std::endl;
	std::cout << "3 - ��������� ������� ���������� �������" << std::endl;
	std::cout << "4 - ��������� ��������� �����" << std::endl;
	std::cout << "0 - ��������� ������" << std::endl;
}

void allSorts(matrix& matr) {
	bool save{};

	std::cout << "�������� �������:" << std::endl;
	matr.showArray();
	std::cout << "=================" << std::endl;
	matrix tempMatrix = matr;
	bubble first{};
	first.Sort(tempMatrix);
	std::cout << "������� ����� ���������� ���������:" << std::endl;
	int bubblePermutations = first.getPermutations();
	int bubbleCompares = first.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	selection second{};
	second.Sort(tempMatrix);
	std::cout << "������� ����� ���������� ������� ������:" << std::endl;
	int selectionPermutations = second.getPermutations();
	int selectionCompares = second.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	insertion third{};
	third.Sort(tempMatrix);
	std::cout << "������� ����� ���������� ������� �������:" << std::endl;
	int insertionPermutations = third.getPermutations();
	int insertionCompares = third.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	shell fourth{};
	fourth.Sort(tempMatrix);
	std::cout << "������� ����� ���������� ������� �����:" << std::endl;
	int shellPermutations = fourth.getPermutations();
	int shellCompares = fourth.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	quick fifth{};
	fifth.Sort(tempMatrix);
	std::cout << "������� ����� ���������� ������� ������� ����������:" << std::endl;
	int quickPermutations = fifth.getPermutations();
	int quickCompares = fifth.getCompares();
	tempMatrix.showArray();

	std::cout << "\n-----------------------------" << std::endl;
	std::cout << "|    ����� ����������      | ���������� ��������� | ���������� ������������ |" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "| ����������� ����������   |       " << std::setw(10) << bubbleCompares
		<< " |            " << std::setw(10) << bubblePermutations << "      |  " << std::endl;
	std::cout << "| ���������� �������       |       " << std::setw(10) << selectionCompares
		<< " |            " << std::setw(10) << selectionPermutations << "      |  " << std::endl;
	std::cout << "| ���������� ���������     |       " << std::setw(10) << insertionCompares
		<< " |            " << std::setw(10) << insertionPermutations << "      |  " << std::endl;
	std::cout << "| ���������� �����         |       " << std::setw(10) << shellCompares
		<< " |            " << std::setw(10) << shellPermutations << "      |  " << std::endl;
	std::cout << "| ������� ����������       |       " << std::setw(10) << quickCompares
		<< " |            " << std::setw(10) << quickPermutations << "      |  " << std::endl;
	std::cout << "-----------------------------\n" << std::endl;

	std::cout << "������ ��������� ��������� � ����?" << std::endl;
	std::cout << "1 - ��\n0 - ���" << std::endl;
	save = getBool();
	if (save) {
		matr.saveResult(bubbleCompares, bubblePermutations, selectionCompares, selectionPermutations, 
			insertionCompares, insertionPermutations, shellCompares, shellPermutations, quickCompares, quickPermutations);
	}
}

void startProgram() {
	bool quit = false;
	bool save{};
	std::string filepath{};
	int rows{}, columns{};
	matrix matr{};
	int programSelection{};
	showGreetings();
	showTaskText();
	while (!quit) {
		showMainMenu();
		programSelection = getInt();
		switch (programSelection) {
		case start:
			std::cout << "\n�� ������� ��������� ������� � �������.\n" << std::endl;
			std::cout << "������� ���-�� ����� � �������: ";
			rows = getInt();
			std::cout << std::endl;
			while (rows <= 0) {
				std::cout << "���-�� ����� �� ����� ���� ������ ��� ������ ����. ��������� ����: ";
				rows = getInt();
				std::cout << std::endl;
			}
			std::cout << "������� ���-�� �������� � �������: ";
			columns = getInt();
			std::cout << std::endl;
			while (columns <= 0) {
				std::cout << "���-�� �������� �� ����� ���� ������������� ��� ������ ����. ��������� ����: ";
				columns = getInt();
				std::cout << std::endl;
			}
			matr.setRowsColumns(rows, columns);
			matr.fillingArrayFromConsole();

			std::cout << "������ ��������� ������� � ����?" << std::endl;
			std::cout << "1 - ��\n0 - ���" << std::endl;
			save = getBool();
			if (save) {
				matr.saveMatrix();
			}

			allSorts(matr);
			matr.clear();
			break;
		case fstart:
			std::cout << "\n�� ������� ���������� ������� �� �����.\n" << std::endl;
			std::cout << "������� ���� � �����: ";
			std::getline(std::cin, filepath);
			while (!checkFilepath(filepath)) {
				std::getline(std::cin, filepath);
			}
			matr.fillingArrayFromFile(filepath);

			allSorts(matr);
			matr.clear();
			break;
		case ranstart:
			std::cout << "\n�� ������� ��������� ������� ���������� �������.\n" << std::endl;
			std::cout << "������� ���-�� ����� � �������: ";
			rows = getInt();
			std::cout << std::endl;
			while (rows <= 0) {
				std::cout << "���-�� ����� �� ����� ���� ������ ��� ������ ����. ��������� ����: ";
				rows = getInt();
				std::cout << std::endl;
			}
			std::cout << "������� ���-�� �������� � �������: ";
			columns = getInt();
			std::cout << std::endl;
			while (columns <= 0) {
				std::cout << "���-�� �������� �� ����� ���� ������������� ��� ������ ����. ��������� ����: ";
				columns = getInt();
				std::cout << std::endl;
			}
			matr.setRowsColumns(rows, columns);
			matr.fillingArrayWithRandom();

			std::cout << "������ ��������� ������� � ����?" << std::endl;
			std::cout << "1 - ��\n0 - ���" << std::endl;
			save = getBool();
			if (save) {
				matr.saveMatrix();
			}
			allSorts(matr);
			matr.clear();
			break;
		case test:
			std::cout << "\n�� ������� �������� ��������� �����." << std::endl;
			mainTest();
			break;
		case end:
			std::cout << "�� ��������" << std::endl;
			quit = true;
			break;
		default:
			std::cout << "������ ������ ���. ���������� ��� ���." << std::endl;
			break;
		}
	}
}