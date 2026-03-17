/**
 * @author Болотин Максим Владимирович
 * @brief  Самостоятельная работа 06
 */

#include "index.hpp"

namespace sw06 {

	/**
	 * T.3. Вычисляет и выводит произведение элементов массива
	 * с чётными индексами (0, 2, 4, ...).
	 */
	void calcProductEvenIndexes(const vector<int>& arr) {
		long long product = 1;

		for (size_t i = 0; i < arr.size(); i += 2) {
			product *= arr[i];
		}

		cout << "Произведение элементов с четными номерами: " << product << endl;
	}

	/**
	 * T.4. Вычисляет и выводит сумму элементов массива,
	 * расположенных между первым и последним нулевыми элементами.
	 */
	void calcSumBetweenZeros(const vector<int>& arr) {

		int firstZero = -1;
		int lastZero  = -1;

		for (size_t i = 0; i < arr.size(); ++i) {
			if (arr[i] == 0) {
				if (firstZero == -1) {
					firstZero = static_cast<int>(i);
				}
				lastZero = static_cast<int>(i);
			}
		}

		int sumBetweenZeros = 0;

		if (firstZero == -1 || lastZero == -1 || firstZero == lastZero) {
			cout << "В массиве недостаточно нулевых элементов для вычисления суммы." << endl;
			return;
		}

		for (size_t i = firstZero + 1; i < lastZero; ++i) {
			sumBetweenZeros += arr[i];
		}

		cout << "Сумма элементов между первым и последним нулем: "
		     << sumBetweenZeros << endl;
	}

	void index() {
		message("intro");

		vector<int> arr;
		int n = 0, minVal = 0, maxVal = 0, choice = 0;

		// T.1. Сформировать массив по выбору пользователя <...>
		cout << "Способы формирования массива:" << endl
			 << " 1. Случайные числа;"          << endl
			 << " 2. Ввод с клавиатуры;"        << endl
										        << endl;

		while (choice < 1 || choice > 2) {
			cout << "Выберите способ формирования массива [1-2]: ";
			cin  >>  choice;
			cout <<  endl;
		}

		cout << "Введите количество элементов массива: ";
		cin  >>  n;
		cout <<  endl;

		switch (choice) {
			case 1:
				/** Random numbers */
				cout << "Введите мин.  значение: ";
				cin  >>  minVal;
				cout << "Введите макс. значение: ";
				cin  >>  maxVal;

				/**
				 * Random numbers generator init
				 * `srand(seed)` initializes the pseudo‑random numbers generator used by `rand()`.
				 * `static_cast<unsigned int>(...)` explicitly converts the value to the required type
				 * because `srand()` expects an argument of type `unsigned int`.
				 * `<unsigned int>` is the target type of the cast used for the seed value.
				 * `time(0)` returns current time in secconds since 01.01.1970,
				 * so each program execution returns completely new numbers' array
				 */
				srand(static_cast<unsigned int>(time(0)));

				/**
				 * Random numbers' array forming.
				 * The cycle executes `n` times, where `n` is array items count (from user input).
				 */
				for (int i = 0; i < n; ++i) {

					/**
					 * Random number generation in range: [ minVal ; maxVal ]
					 * `rand(...)` is the base number
					 * `rand(...) % ( maxVal - minVal + 1 )` is range limit
					 * `+ minVal` range's step to needed min. value
					 */
					int randomValue = minVal + rand() % (maxVal - minVal + 1);

					/**
					 * Push gotten random value at the end of dynamic vector array
					 */
					arr.push_back(randomValue);
				}
				break;

			case 2:
				/** User input */
				cout << "Введите элементы массива через пробел: ";
				for (int i = 0; i < n; ++i) {
					int val;
					cin >> val;
					arr.push_back(val);
				}
				break;

			default:
				cout << "Ошибка. Способов ввода массива лишь 2.";
				exit(1);
		}
		cout << endl;

		// Display the array
		cout << "Массив: ";
		for (int val : arr) {
			cout << val << " ";
		}
		cout << endl << endl;

		/** T.3. */
		calcProductEvenIndexes(arr);

		/** T.4. */
		calcSumBetweenZeros(arr);

	}

}
