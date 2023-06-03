#pragma once
#include "matrix.h"

class ISort {
protected:
	int permutations{};
	int compares{};
	virtual void Sort(matrix& myMatrix) = 0;
public:
	int getPermutations() const;
	int getCompares() const;

	virtual ~ISort() = default;
};

class bubble : public ISort {
public:
	void Sort(matrix& myMatrix) override;
};

class selection : public ISort {
public:
	void Sort(matrix& myMatrix) override;
};

class insertion : public ISort {
public:
	void Sort(matrix& myMatrix) override;
};

class shell : public ISort {
public:
	void Sort(matrix& myMatrix) override;
};

class quick : public ISort {
private:
	void sorting(matrix& myMatrix, const int left, const int right, const int i);
public:
	void Sort(matrix& myMatrix) override;
};