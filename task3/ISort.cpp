#include "ISort.h"

int ISort::getPermutations() const {
	return permutations;
}

int ISort::getCompares() const {
	return compares;
}

void bubble::Sort(matrix& myMatrix) {
	int i{}, j{}, k{};
	int temp{};
	for (i = 0; i < myMatrix.getRows(); i++) {
		bool flag = true;
		while (flag) {
			flag = false;
			for (k = 0; k < myMatrix.getColumns() - j - 1; k++) {
				if (myMatrix.getSumOfElement(i, k) < myMatrix.getSumOfElement(i, k + 1)) {
					temp = myMatrix.getElement(i, k);
					myMatrix.setElement(i, k, myMatrix.getElement(i, k + 1));
					myMatrix.setElement(i, k + 1, temp);
					permutations += 2;
					flag = true;
				}
				compares++;
			}
			j++;
		}
		j = 0;
	}
}

void selection::Sort(matrix& myMatrix) {
	int i{}, j{}, k{};
	int temp{};
	int minIndex{};
	for (i = 0; i < myMatrix.getRows(); i++) {
		for (j = 0; j < myMatrix.getColumns() - 1; j++) {
			minIndex = j;
			for (k = j + 1; k < myMatrix.getColumns(); k++) {
				if (myMatrix.getSumOfElement(i, k) > myMatrix.getSumOfElement(i, minIndex)) {
					minIndex = k;
				}
				compares++;
			}
			if (minIndex != j) {
				temp = myMatrix.getElement(i, j);
				myMatrix.setElement(i, j, myMatrix.getElement(i, minIndex));
				myMatrix.setElement(i, minIndex, temp);
				permutations += 2;
			}
		}
	}
}

void insertion::Sort(matrix& myMatrix) {
	int i{}, j{}, k{};
	int temp{};
	int key{};
	for (i = 0; i < myMatrix.getRows(); i++) {
		for (j = 1; j < myMatrix.getColumns(); j++) {
			key = myMatrix.getSumOfElement(i, j);
			temp = myMatrix.getElement(i, j);
			k = j - 1;
			compares++;
			if (myMatrix.getSumOfElement(i, k) != myMatrix.getSumOfElement(i, j)) {
				while (k >= 0 && myMatrix.getSumOfElement(i, k) < key) {
					myMatrix.setElement(i, k + 1, myMatrix.getElement(i, k));
					k--;
					permutations++;
				}
				myMatrix.setElement(i, k + 1, temp);
			}
		}
	}
}

void shell::Sort(matrix& myMatrix) {
	int i{}, j{}, k{};
	int step{};
	int temp{};
	for (i = 0; i < myMatrix.getRows(); i++) {
		for (step = myMatrix.getColumns() / 2; step > 0; step /= 2) {
			for (j = step; j < myMatrix.getColumns(); j++) {
				compares++;
				temp = myMatrix.getElement(i, j);
				for (k = j; k >= step && myMatrix.getSumOfElement(i, k - step) < myMatrix.getSumOfElement(i, j); k -= step) {
					myMatrix.setElement(i, k, myMatrix.getElement(i, k - step));
					permutations++;
				}
				myMatrix.setElement(i, k, temp);
			}
		}
	}
}

void quick::sorting(matrix& myMatrix, const int left, const int right, const int i) {
	int k = left;
	int j = right;
	int temp{};
	int pivot = myMatrix.getSumOfElement(i, (j + k) / 2);

	while (k <= j) {
		while (myMatrix.getSumOfElement(i, k) > pivot) {
			compares++;
			k++;
		}
		while (myMatrix.getSumOfElement(i, j) < pivot) {
			compares++;
			j--;
		}
		if (k <= j) {
			if (!(myMatrix.getSumOfElement(i, k) == myMatrix.getSumOfElement(i, j))) {
				temp = myMatrix.getElement(i, k);
				myMatrix.setElement(i, k, myMatrix.getElement(i, j));
				myMatrix.setElement(i, j, temp);
				permutations++;
			}
			k++;
			j--;
		}
	}

	if (left < j) {
		sorting(myMatrix, left, j, i);
	}
	if (k < right) {
		sorting(myMatrix, k, right, i);
	}
}

void quick::Sort(matrix& myMatrix) {
	int i{};
	for (i = 0; i < myMatrix.getRows(); i++) {
		sorting(myMatrix, 0, myMatrix.getColumns() - 1, i);
	}
}