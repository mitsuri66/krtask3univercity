#include <iostream>
#include <iomanip>
#include "menuInterface.h"
#include "matrix.h"
#include "ISort.h"
#include "menuItems.h"
#include "inputValidation.h"
#include "tests.h"

void showGreetings() {
	std::cout << "Здравствуйте!" << std::endl;
	std::cout << "Контрольная работа №3. Вариант №6" << std::endl;
	std::cout << "Работу выполнил: Губкин Максим\n" << "Группа №424\n" << std::endl;
}

void showTaskText() {
	std::cout << "Необходимо составить программу для сортировки массива данных методами:"
		<< "\nпузырьковой, отбора, вставки, Шелла и быстрой сортировки. Вывести на экран"
		<< "\nнеупорядоченный (один раз) и упорядоченные (для каждого из методов) массивы"
		<< "\nданных. Составить сравнительную таблицу эффективности методов, в которой"
		<< "\nнеобходимо указать число сравнений и перестановок переменных в каждом"
		<< "\nметоде сортировки.\n"
		<< "\nУпорядочить каждую строку матрицы по убыванию суммы значений цифр"
		<< "\nэлементов матрицы.\n" << std::endl;
}

void showMainMenu() {
	std::cout << "Выберите пункт меню:" << std::endl;
	std::cout << "1 - Ввести исходные данные с клавиатуры" << std::endl;
	std::cout << "2 - Загрузить исходные данные из файла" << std::endl;
	std::cout << "3 - Заполнить матрицу случайными числами" << std::endl;
	std::cout << "4 - Запустить модульные тесты" << std::endl;
	std::cout << "0 - Закончить работу" << std::endl;
}

void allSorts(matrix& matr) {
	bool save{};

	std::cout << "Исходная матрица:" << std::endl;
	matr.showArray();
	std::cout << "=================" << std::endl;
	matrix tempMatrix = matr;
	bubble first{};
	first.Sort(tempMatrix);
	std::cout << "Матрица после сортировки пузырьком:" << std::endl;
	int bubblePermutations = first.getPermutations();
	int bubbleCompares = first.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	selection second{};
	second.Sort(tempMatrix);
	std::cout << "Матрица после сортировки методом выбора:" << std::endl;
	int selectionPermutations = second.getPermutations();
	int selectionCompares = second.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	insertion third{};
	third.Sort(tempMatrix);
	std::cout << "Матрица после сортировки методом вставки:" << std::endl;
	int insertionPermutations = third.getPermutations();
	int insertionCompares = third.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	shell fourth{};
	fourth.Sort(tempMatrix);
	std::cout << "Матрица после сортировки методом Шелла:" << std::endl;
	int shellPermutations = fourth.getPermutations();
	int shellCompares = fourth.getCompares();
	tempMatrix.showArray();

	std::cout << "=================" << std::endl;
	tempMatrix = matr;
	quick fifth{};
	fifth.Sort(tempMatrix);
	std::cout << "Матрица после сортировки методом быстрой сортировки:" << std::endl;
	int quickPermutations = fifth.getPermutations();
	int quickCompares = fifth.getCompares();
	tempMatrix.showArray();

	std::cout << "\n-----------------------------" << std::endl;
	std::cout << "|    Метод сортировки      | Количество сравнений | Количество перестановок |" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "| Пузырьковая сортировка   |       " << std::setw(10) << bubbleCompares
		<< " |            " << std::setw(10) << bubblePermutations << "      |  " << std::endl;
	std::cout << "| Сортировка выбором       |       " << std::setw(10) << selectionCompares
		<< " |            " << std::setw(10) << selectionPermutations << "      |  " << std::endl;
	std::cout << "| Сортировка вставками     |       " << std::setw(10) << insertionCompares
		<< " |            " << std::setw(10) << insertionPermutations << "      |  " << std::endl;
	std::cout << "| Сортировка Шелла         |       " << std::setw(10) << shellCompares
		<< " |            " << std::setw(10) << shellPermutations << "      |  " << std::endl;
	std::cout << "| Быстрая сортировка       |       " << std::setw(10) << quickCompares
		<< " |            " << std::setw(10) << quickPermutations << "      |  " << std::endl;
	std::cout << "-----------------------------\n" << std::endl;

	std::cout << "Хотите сохранить результат в файл?" << std::endl;
	std::cout << "1 - Да\n0 - Нет" << std::endl;
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
			std::cout << "\nВы выбрали заполнить матрицу с консоли.\n" << std::endl;
			std::cout << "Введите кол-во строк в матрице: ";
			rows = getInt();
			std::cout << std::endl;
			while (rows <= 0) {
				std::cout << "Кол-во строк не может быть меньше или равным нулю. Повторите ввод: ";
				rows = getInt();
				std::cout << std::endl;
			}
			std::cout << "Введите кол-во столбцов в матрице: ";
			columns = getInt();
			std::cout << std::endl;
			while (columns <= 0) {
				std::cout << "Кол-во столбцов не может быть отрицательным или равным нулю. Повторите ввод: ";
				columns = getInt();
				std::cout << std::endl;
			}
			matr.setRowsColumns(rows, columns);
			matr.fillingArrayFromConsole();

			std::cout << "Хотите сохранить матрицу в файл?" << std::endl;
			std::cout << "1 - Да\n0 - Нет" << std::endl;
			save = getBool();
			if (save) {
				matr.saveMatrix();
			}

			allSorts(matr);
			matr.clear();
			break;
		case fstart:
			std::cout << "\nВы выбрали заполнение матрицы из файла.\n" << std::endl;
			std::cout << "Введите путь к файлу: ";
			std::getline(std::cin, filepath);
			while (!checkFilepath(filepath)) {
				std::getline(std::cin, filepath);
			}
			matr.fillingArrayFromFile(filepath);

			allSorts(matr);
			matr.clear();
			break;
		case ranstart:
			std::cout << "\nВы выбрали заполнить матрицу случайными числами.\n" << std::endl;
			std::cout << "Введите кол-во строк в матрице: ";
			rows = getInt();
			std::cout << std::endl;
			while (rows <= 0) {
				std::cout << "Кол-во строк не может быть меньше или равным нулю. Повторите ввод: ";
				rows = getInt();
				std::cout << std::endl;
			}
			std::cout << "Введите кол-во столбцов в матрице: ";
			columns = getInt();
			std::cout << std::endl;
			while (columns <= 0) {
				std::cout << "Кол-во столбцов не может быть отрицательным или равным нулю. Повторите ввод: ";
				columns = getInt();
				std::cout << std::endl;
			}
			matr.setRowsColumns(rows, columns);
			matr.fillingArrayWithRandom();

			std::cout << "Хотите сохранить матрицу в файл?" << std::endl;
			std::cout << "1 - Да\n0 - Нет" << std::endl;
			save = getBool();
			if (save) {
				matr.saveMatrix();
			}
			allSorts(matr);
			matr.clear();
			break;
		case test:
			std::cout << "\nВы выбрали провести модульные тесты." << std::endl;
			mainTest();
			break;
		case end:
			std::cout << "До свидания" << std::endl;
			quit = true;
			break;
		default:
			std::cout << "Такого пункта нет. Попробуйте еще раз." << std::endl;
			break;
		}
	}
}