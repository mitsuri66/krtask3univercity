#include "matrix.h"
#include "inputValidation.h"
#include <fstream>
#include <iostream>
#include <filesystem>

matrix::matrix(const int i, const int j) {
	setRowsColumns(i, j);
}

void matrix::setRowsColumns(const int i, const int j) {
	rows = i;
	columns = j;
	elements = std::vector<std::vector<int>>(rows, std::vector<int>(columns, 0));
}

int matrix::getElement(const int i, const int j) const {
	return elements[i][j];
}

int matrix::getRows() const {
	return rows;
}

int matrix::getColumns() const {
	return columns;
}

void matrix::setElement(const int i, const int j, const int value) {
	elements[i][j] = value;
}

int matrix::getSumOfElement(const int i, const int j) const {
	int result{};
	int tempElem = abs(elements[i][j]);
	while (tempElem) {
		result += tempElem % 10;
		tempElem /= 10;
	}
	return result;
}

void matrix::fillingArrayFromConsole() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << "Введите [" << i + 1 << "] [" << j + 1 << "] элемент матрицы:";
			elements[i][j] = getInt();
		}
	}
}

void matrix::fillingArrayFromFile(std::string filepath) {
	std::ifstream input{};
	int i{}, j{};
	int tempRows{}, tempColumns{};
	input.open(filepath);
	input >> tempRows;
	input >> tempColumns;
	setRowsColumns(tempRows, tempColumns);
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			input >> elements[i][j];
		}
	}
	input.close();
}

void matrix::fillingArrayWithRandom() {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			elements[i][j] = getRandomInt();
}

void matrix::showArray() const {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << elements[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

void matrix::saveMatrix() const {
	std::string filepath;
	bool isDataSaved = false;
	while (!isDataSaved){
		std::cout << "Введите путь к файлу, в который хотите сохранить результат: ";
		std::getline(std::cin, filepath);

		if (std::ifstream(filepath)) {
			std::cout << "Файл уже существует." << std::endl;
			std::cout << "0 - Перезаписать текущий файл.\n" << "1 - Ввести новый путь." << std::endl;
			int anotherFile = getInt();
			if (anotherFile) {
				continue;
			}
		}

		std::ofstream myFile(filepath, std::ofstream::app);

		std::error_code ec{};

		if (!std::filesystem::is_regular_file(filepath, ec)) {
			std::cout << "Адрес содержит недопустимые значения. Повторите ввод." << std::endl;
			myFile.close();
			continue;
		}

		if (!myFile) {
			std::cout << "Запись запрещена. Повторите ввод." << std::endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filepath, std::ofstream::trunc);
		myFile << rows << " ";
		myFile << columns << std::endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				myFile << elements[i][j] << " ";
			}
			myFile << std::endl;
		}
		myFile.close();
		std::cout << "Запись завершена." << std::endl;
		isDataSaved = true;
	}
}

void matrix::saveResult(const int bc, const int bp, const int sc, const int sp,
	const int ic, const int ip, const int Sc, const int Sp, const int qc, const int qp) const {
	std::string filepath;
	bool isDataSaved = false;
	while (!isDataSaved) {
		std::cout << "Введите путь к файлу, в который хотите сохранить результат: ";
		std::getline(std::cin, filepath);

		if (std::ifstream(filepath)) {
			std::cout << "Файл уже существует." << std::endl;
			std::cout << "0 - Перезаписать текущий файл.\n" << "1 - Ввести новый путь." << std::endl;
			int anotherFile = getInt();
			if (anotherFile) {
				continue;
			}
		}

		std::ofstream myFile(filepath, std::ofstream::app);

		std::error_code ec{};

		if (!std::filesystem::is_regular_file(filepath, ec)) {
			std::cout << "Адрес содержит недопустимые значения. Повторите ввод." << std::endl;
			myFile.close();
			continue;
		}

		if (!myFile) {
			std::cout << "Запись запрещена. Повторите ввод." << std::endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filepath, std::ofstream::trunc);
		myFile << "-----------------------------" << std::endl;
		myFile << "|    Метод сортировки      | Количество сравнений | Количество перестановок |" << std::endl;
		myFile << "-----------------------------" << std::endl;
		myFile << "| Пузырьковая сортировка   |       " << std::setw(10) << bc
			<< " |            " << std::setw(10) << bp << "      |  " << std::endl;
		myFile << "| Сортировка выбором       |       " << std::setw(10) << sc
			<< " |            " << std::setw(10) << sp << "      |  " << std::endl;
		myFile << "| Сортировка вставками     |       " << std::setw(10) << ic
			<< " |            " << std::setw(10) << ip << "      |  " << std::endl;
		myFile << "| Сортировка Шелла         |       " << std::setw(10) << Sc
			<< " |            " << std::setw(10) << Sp << "      |  " << std::endl;
		myFile << "| Быстрая сортировка       |       " << std::setw(10) << qc
			<< " |            " << std::setw(10) << qp << "      |  " << std::endl;
		myFile << "-----------------------------" << std::endl;
		myFile.close();
		std::cout << "Запись завершена." << std::endl;
		isDataSaved = true;
	}
}

void matrix::operator=(const matrix& other)
{
	this->rows = other.rows;
	this->columns = other.columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->elements[i][j] = other.elements[i][j];
		}
	}
}

std::vector<int>& matrix::operator[] (int index) {
	return elements.at(index);
}

void matrix::clear() {
	elements.clear();
	rows = 0;
	columns = 0;
}