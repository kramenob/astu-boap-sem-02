/**
 * @author Болотин Максим Владимирович
 * @brief  Messages for Самостоятельная работа 05
 */

#include "index.hpp"

namespace sw05 {

	void message(const string& key) {
		if (key == "intro") {
			cout << R"(
# Самостоятельная работа №05

## Задание:

...

Человекочитаемый вид: https://github.com/kramenob/astu-boap-sem-02/blob/main/docs/sels/05/task-statement.md

)";
		} else if (key == "else") {
			cout << R"(
## Индивидуальное задание:

...

)";
		}

		return;
	}

}
