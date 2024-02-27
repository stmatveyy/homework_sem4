#include <iostream>
#include "matrix.h"


int main()
{
	Matrix m1(3, 3); // Создаем матрицы 3х3
	Matrix m2(3, 3);

	m1.fillRandom(); // Заполняем случайными числами
	m2.fillRandom();

	std::cout << " ---- Showcases ----" << std::endl;
	std::cout << "1) First random matrix: " << "\n" << m1 << std::endl; // Тест вывода в виде таблицы
	std::cout << "2) Second random matrix: " << "\n" << m2 << std::endl;

	std::cout << "3) Addition: " << "\n" << m1 + m2 << std::endl; // Тест сложения

	Matrix m3(3, 3); // Создаем третью матрицу, заполняем нулями
	m3.fillZeros();
	m3 += m1; // Складываем ее с первой, теперь они одинаковые

	std::cout << "4) In-place addition: " << "\n" << m3 << std::endl; // Тут это видно
	std::cout << "5) Grab value by index: " << "\n" << m1[0][0] << std::endl; // Взятие по индексу

	m3[0][0] = 9999; // Изменение по индексу

	std::cout << "6) Change value by index: " << "\n" << m3 << std::endl;

	std::cout << "7) Subtraction: " << "\n" << m1 - m2 << std::endl;

	m3 -= m1; 

	std::cout << "8) In-place subtraction: " << "\n" << m3 << std::endl;
	std::cout << "9) Multiplication: " << m1 * m2 << std::endl;

	m1.fillZeros(); //Заполняем нулями для теста на равенство
	m2.fillZeros();

	bool is_equal = m1 == m2;
	std::cout << "10) Equality test: " << "\n" << is_equal << std::endl; // Выведет True

	m1[0][0] = 4389; // Меняем элемент
	bool is_not_equal = m1 != m2;
	std::cout << "11) Inequality test: " << "\n" << is_not_equal << std::endl; // Выведет True
}

