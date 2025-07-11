#include "customer.h"
#include "employee.h"
#include "admin.h"
using namespace std;
int main()
{
    int base;
    cout << "------------------- <3 ------------------- <3 --------------------" << endl
         << "Are you here as: " << endl
         << "1 Customer\n2 Admin \n3 Employee\nEnter here: ";
    cin >> base;
    while (base < 1 || base > 3)
    {
        cout << "Invalid option. Try again: ";
        cin >> base;
    }
    if (base == 1)
    {
        customerlogin();
    }
    else if (base == 2)
    {
        adminlogin();
    }
    else if (base == 3)
    {
        employeelogin();
    }
}