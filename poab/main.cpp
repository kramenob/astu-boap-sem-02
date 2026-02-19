/**
 *
 * @author  Болотин Максим Владимирович
 * @group   ДИНРб-11/2
 * @variant 3
 *
 * @brief   Entrypoint file. Magic starts here.
 *
 */

/** Everything defined here */
#include "bootstrap.hpp"

/** Main function */
int main() {

    printHeader();
    
    int choice;

    cout << "Выберите лабораторную [9-11]: ";
    cin  >> choice;

    switch(choice) {

        case 9:
            lw09::index();
            break;

        case 10:
            lw10::index();
            break;

        default:
            cout << "Лабораторная не найдена!" << endl;
    }

    return 0;
}
