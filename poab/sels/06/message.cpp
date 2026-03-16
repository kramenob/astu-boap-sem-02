/**
 * @author Болотин Максим Владимирович
 * @brief  Messages for Самостоятельная работа 06
 */

#include "index.hpp"

namespace sw06 {

	void message(const string& key) {
		if (key == "intro") {
			cout << R"(
# Самостоятельная работа №06

## Задание:

...

Человекочитаемый вид: https://github.com/kramenob/astu-boap-sem-02/blob/main/docs/sels/06/task-statement.md

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
