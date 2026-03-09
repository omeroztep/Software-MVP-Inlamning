#include "UserInterface.h"

// Programmets startpunkt.
int main()
{
    UserInterface* ui = new UserInterface();
    ui->start();

    delete ui;
    ui = nullptr;

    return 0;
}