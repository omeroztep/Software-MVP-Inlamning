#include "UserInterface.h"

int main()
{
    UserInterface* ui = new UserInterface();
    ui->start();

    delete ui;
    ui = nullptr;

    return 0;
}