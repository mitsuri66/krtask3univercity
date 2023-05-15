#include "matrix.h"
#include "inputValidation.h"
#include <fstream>
#include <iostream>

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
	int temp{};
	int tempElem = abs(elements[i][j]);
	while (tempElem) {
		temp += tempElem % 10;
		tempElem /= 10;
	}
	return temp;
}

void matrix::fillingArrayFromConsole() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << "¬ведите [" << i + 1 << "] [" << j + 1 << "] элемент матрицы:";
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
