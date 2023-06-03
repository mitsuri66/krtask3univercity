#pragma once

#include <vector>
#include <string>

class matrix {
	int rows{};
	int columns{};
	std::vector<std::vector<int>> elements;
public:
	matrix() = default;
	matrix(const int rows, const int columns);
	void setRowsColumns(const int rows, const int columns);
	int getElement(const int i, const int j) const;
	int getRows() const;
	int getColumns() const;
	void setElement(const int i, const int j, const int value);
	int getSumOfElement(const int i, const int j) const;
	void fillingArrayFromConsole();
	void fillingArrayFromFile(std::string);
	void fillingArrayWithRandom();
	void showArray() const;
	void saveMatrix() const;
	void saveResult(const int bc, const int bp, const int sc, const int sp, 
		const int ic, const int ip, const int Sc, const int Sp, const int qc, const int qp) const;
	void operator = (const matrix& other);
	std::vector<int>& operator[](int index);
	void clear();
};