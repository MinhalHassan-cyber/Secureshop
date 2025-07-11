#include "employee.h"
void editMenu()
{
    int num;
    cout << "Enter the number of items at which this latest menu lies: ";
    cin >> num;
    while (num < 0)
    {
        cout << "ERROR! Try again: ";
        cin >> num;
    }
    int *id = new int[num];
    int *price = new int[num];
    int *stock = new int[num];
    int i = 0;
    char **name = new char *[num + 1];
    char **categ = new char *[num + 1];

    for (int i = 0; i < num; ++i)
    {
        name[i] = new char[100];
        categ[i] = new char[100];
    }
    ifstream file_in, order;
    ofstream update;

    file_in.open("./menu.txt");
    while (file_in >> id[i] >> price[i] >> stock[i]) // Storing all data of menu in arrays first
    {
        file_in.getline(name[i], 100, '|');
        file_in.getline(categ[i], 100, '\n');
        i++;
    }
    file_in.close();

    int upd;
    cout << "Press 1 to Update an item \nPress 2 to Remove an item \nEnter here: " << endl;
    cin >> upd;

    while (upd < 1 or upd > 2) // INPUT VALIDATION
    {
        cout << "Invalid choice. Try again: ";
        cin >> upd;
    }

    int ID, PRICE, AVAIL;
    char product[num + 1], category[num + 1];

    cout << "Enter the product ID: ";
    cin >> ID;
    if (upd == 1)
    {
        cin.ignore();

        cout << "Enter the updated price:  ";
        cin >> PRICE;

        while (PRICE < 0)
        {
            cout << "ERROR! Enter Price again: ";
            cin >> PRICE;
        }

        cin.ignore();
        cout << "Enter the updated stock: ";
        cin >> AVAIL;

        while (AVAIL < 0)
        {
            cout << "ERROR! Enter Price again: ";
            cin >> AVAIL;
        }
        cin.ignore();

        cout << "Enter the updated name: ";
        cin.getline(product, num + 1, '\n');

        cout << "Enter the updated category: ";
        cin.getline(category, num + 1, '\n');

        ofstream append;
        append.open("menu.txt", ios::out);
        int a = 0;
        bool match = false;
        while (a < i) // checks through the total number of items from 
        {
            if (id[a] == ID)
            {
                match = true;
                append << id[a] << " " << PRICE << " " << AVAIL << " " << product << " | " << category << endl;
            }
            else
            {
                append << id[a] << " " << price[a] << " " << stock[a] << " " << name[a] << " | " << categ[a] << endl;
            }
            a++;
        }

       if (match)
       {
        cout << endl
             << "Changes Done! Good work major <3" << endl;
       }
       else
       {
        cout << "ID NOT FOUND! REPEATING PROCESS. "<<endl;
        editMenu();
       }
    }

    else if (upd == 2)
    {
        ofstream append;
        append.open("menu.txt", ios::out);
        int a = 0;
        while (a < i)
        {
            if (id[a] == ID)
            {
                a++;
                continue;
            }
            else
            {
                append << id[a] << " " << price[a] << " " << stock[a] << " " << name[a] << " | " << categ[a] << endl;
            }
            a++;
        }
        cout << endl
             << "Changes Done! Good work major <3" << endl;
    }
    delete[] id;
    delete[] price;
    delete[] stock;
    for (int i = 0; i < num; ++i)
    {
        delete[] name[i];
        delete[] categ[i];
    }
    delete[] name;
    delete[] categ;
}
void Restock()
{
    int ID, restock, num;
    cout << "Enter the ID of the product you want to restock: ";
    cin >> ID;
    cout << "Enter the amount of items to restock: "; // INPUT VALIDATION ON ALL OF THESE
    cin >> restock;

    while (restock < 5) // 5 se kam items ke liye 
    {
        cout << "NOT ENOUGH ITEMS. ADD MORE: ";
        cin >> restock;
    }

    cout << "Enter the number of items at which the latest menu lies: ";
    cin >> num;
    while (num <=0 ) // input validation
    {
        cout << "LIES. Enter again: ";
        cin >> num;
    }
    int *id = new int[num];
    int *price = new int[num];
    int *stock = new int[num];
    int  i = 0;
    char **name = new char *[num + 1];
    char **categ = new char *[num + 1];

    for (int i = 0; i < num; ++i)
    {
        name[i] = new char[100];
        categ[i] = new char[100];
    }
    ifstream file_in, order;
    ofstream update;

    file_in.open("./menu.txt");
    while (file_in >> id[i] >> price[i] >> stock[i]) // Storing all data of menu in arrays first
    {
        file_in.getline(name[i], 100, '|');
        file_in.getline(categ[i], 100, '\n');
        i++;
    }
    file_in.close();

    int a = 0;
    ofstream append;
    append.open("menu.txt", ios::out);
    while (a < i)
    {
        if (id[a] == ID)
        {

            append << id[a] << " " << price[a] << " " << restock << " " << name[a] << " | " << categ[a] << endl;
        }
        else
        {
            append << id[a] << " " << price[a] << " " << stock[a] << " " << name[a] << " | " << categ[a] << endl;
        }
        a++;
    }
    append.close();
    int choice;
    cout << "Press 1 to Restock more items \nPress 2 to Exit \nEnter here: ";
    cin >> choice;
    while (choice < 1 or choice > 2)
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        addMenu();
    }
    else
    {
        cout << "-------------- GOOD WORK TODAY MAJOR ----------------" << endl;
    }

    delete[] id;
    delete[] price;
    delete[] stock;
    for (int i = 0; i < num; ++i)
    {
        delete[] name[i];
        delete[] categ[i];
    }
    delete[] name;
    delete[] categ;
}
void addMenu()
{
    int id, price, stock;
    char *name = new char[50];
    char *categ = new char[50];
    cout << "Enter the Product ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter the Price of item: ";
    cin >> price;
    cin.ignore();
    cout << "Enter the stock that item must have: ";
    cin >> stock;
    cin.ignore();
    cout << "Enter the name of the Product: ";
    cin.getline(name, 50, '\n');
    cout << "Enter the Category of the Product: ";
    cin.getline(categ, 50, '\n');

    ofstream append;
    append.open("menu.txt", ios::app);
    append << id << " " << price << " " << stock << "   " << name << "  | " << categ << endl;
    append.close();
}
void feedbacks(int employee_num)
{
    cout << "------------------ FEEDBACKS -------------------" << endl;
    bool sup = true;
    fstream feed;
    feed.open("support.txt", ios::in);
    char user[10], request[100], categ[15], usersup[10][15], match[15] = "Feedback"; // same pattern as support requests
    int c = 0;
    while (feed.getline(user, 10, '|'))
    {
        sup = true;
        feed.getline(request, 100, '|');
        feed.getline(categ, 15, '\n');
        for (int i = 0; categ[i] != '\0'; i++)
        {
            if (categ[i] != match[i])
            {
                sup = false;
            }
        }
        if (sup)
        {
            for (int a = 0; user[a] != '\0'; a++)
            {
                usersup[c][a] = user[a];
            }
            c++;
            cout << user << ": " << request << endl;
        }
    }
    feed.close();
    int choice;
    cout << "Press 1 to give response \nPress 2 to Exit \nEnter here: ";
    cin >> choice;
    cin.ignore();
    while (choice < 1 or choice > 2)
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 1)
    {
        bool search = true;
        char username[10];
        cout << "Enter the username you wish to respond to: ";
        cin.getline(username, 10, '\n');

        for (int x = 0; x < c; x++)
        {
            search = true;
            for (int i = 0; username[i] != '\0'; i++)
            {
                if (username[i] != usersup[x][i])
                {
                    search = false;
                    break;
                }
            }

            if (search)
            {
                char response[50];
                cout << "Enter the response: ";
                cin.getline(response, 50, '\n');
                feed.open("support.txt", ios::app);
                feed << endl
                     << username << "|" << "Staffs Response: " << response << "|Feedback" << endl;
            }
            else
            {
                cout << "User not found. " << endl;
            }


            fstream employee;
            employee.open("employee.txt", ios:: in);
            int c = 0;
            int *num = new int [6];
            int *score = new int [6];
            char pass[6][25];

            while (employee >> num[c]) // storing employee file data in arrays first to update their score based on responding to customers 
            {
                employee.getline(pass[c], 25, '|');
                employee >> score [c];
                c++;
            }

            employee.close();

            employee.open("employee.txt", ios:: out);
            for (int i = 0; i < c; i ++)
            {
                if (num[i] == employee_num)
                {
                    score[i]++;
                }
                employee << num[i] << " " << pass[i] << "|" << score[i] << endl;
            }

            ofstream report;
            report.open("SalesReport.txt", ios:: app);
            report << "Employee " << employee_num << " engaged with customers and is logging in regularly to complete tasks. "<<endl;
            report.close();
            employee.close();
        }
    }
}
void queries(int employee_num)
{
    cout << "---------------------- SUPPORT REQUESTS -----------------------------" << endl;
    bool sup = true;
    fstream support;
    support.open("support.txt", ios::in);
    char user[10], request[100], categ[15], usersup[10][15], match[15] = "Support";
    int c = 0;
    while (support.getline(user, 10, '|'))
    {
        sup = true;
        support.getline(request, 100, '|');
        support.getline(categ, 15, '\n');
        for (int i = 0; categ[i] != '\0'; i++)
        {
            if (categ[i] != match[i])
            {
                sup = false;
            }
        }
        if (sup) // if user had made a support request then storing those users in an array
        {
            for (int a = 0; user[a] != '\0'; a++)
            {
                usersup[c][a] = user[a]; // storing only those users to match from that have made support requests (not feedbacks)
            }
            c++;
            cout << user << ": " << request << endl; // displaying the support requests from supports category
        }
    }
    support.close();
    int choice;
    cout << "Press 1 to Address the queries \nPress 2 to Exit \nEnter here: ";
    cin >> choice;
    cin.ignore();
    while (choice < 1 or choice > 2)
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 1)
    {
        bool search = true;
        char username[10];
        cout << "Enter the username you wish to address the query of: ";
        cin.getline(username, 10, '\n');

        for (int x = 0; x < c; x++) // searching every user in the array
        {
            search = true;
            for (int i = 0; username[i] != '\0'; i++) // matching the entered user from users in arrays
            {
                if (username[i] != usersup[x][i])
                {
                    search = false;
                    break;
                }
            }

            if (search)
            {
                char response[50];
                cout << "Enter the response: ";
                cin.getline(response, 50, '\n');
                support.open("support.txt", ios::app);
                support << endl
                        << username << "|" << "Staffs Response: " << response << "|Support" << endl; // storing response in file in same pattern

            fstream employee;
            employee.open("employee.txt", ios:: in);
            int c = 0;
            int *num = new int [6];
            int *score = new int [6];
            char pass[6][25];

            while (employee >> num[c]) // storing employee file data in arrays first to update their score based on responding to customers 
            {
                employee.getline(pass[c], 25, '|');
                employee >> score [c];
                c++;
            }

            employee.close();

            employee.open("employee.txt", ios:: out);
            for (int i = 0; i < c; i ++)
            {
                if (num[i] == employee_num)
                {
                    score[i]++;
                }
                employee << num[i] << " " << pass[i] << "|" << score[i] << endl;
            }

            ofstream report;
            report.open("SalesReport.txt", ios:: app);
            report << "Employee " << employee_num << " engaged with customers and is logging in regularly to complete tasks. "<<endl;
            report.close();

            employee.close();
            }
            else
            {
                cout << "User not found. " << endl;
            }
        }
    }
}
void alerts()
{
    cout << " \n     Following products are getting out of stock! " << endl;
    cout << "---------------- A L E R T S ---------------------" << endl;
    cout << "-ID------------STOCK---------NAME------CATEGORY---" << endl;
    bool real = false;
    int id, price, stock;
    char name[30], categ[30];
    fstream menu;
    menu.open("./menu.txt", ios::in);
    while (menu >> id >> price >> stock) // reading from menu
    {
        menu.getline(name, 30, '|');
        menu.getline(categ, 30, '\n');
        if (stock < 5) // If product is less than 5 in stock then employees recieve alert
        {
            real = true;
            cout << id << setw(10) << stock << setw(20) << name << setw(20) << categ << endl;
        }
    }
    if (!real)
    {
        cout << endl
             << "  No products are currently out of stock. " << endl
             << endl;
    }
}
bool passwordcompare(int num, char pass[]) 
{
    int real, score;
    char real_pass[25];
    fstream check;
    check.open("employee.txt", ios::in);
    if (!check) {
        cerr << "Error: Could not open employee.txt" << endl;
        return false;
    }

    while (check >> real) 
    {
        check.ignore();
        check.getline(real_pass, 25, '|'); // Reading the password part
        check >> score;
        if (num == real)
         { 
          
            int i = 0;
            while (real_pass[i] != '\0' && pass[i] != '\0') 
            {
                if (real_pass[i] != pass[i]) 
                {
                    check.close();
                    return false; 
                }
                i++;
            }
           
            if (real_pass[i] != '\0' || pass[i] != '\0') 
            {
                check.close();
                return false;
            }
            check.close();
            return true; 
        }
    }
    check.close();
    return false; 
}

void employeelogin()
{
    time_t now = time(nullptr);
    int employee_num, i;
    char pass[25];
    bool authenticated = false; // for authentication process of the employee
    cout << "Enter your assigned employee number: ";
    cin >> employee_num;
    cin.ignore();

    while (employee_num <= 0)
    {
        cout << "Invalid choice. Try again: ";
        cin >> employee_num;
        cin.ignore();
    }

    cout << "Enter your password: ";
    cin.getline(pass, 25, '\n');

    for (i = 0; i < 3; i++) // 3 attempts for incorrect password
    {

        if (!passwordcompare(employee_num, pass)) // function will return true if password is correct
        {
            cout << "\t\tAuthentication done! Cowboy " << employee_num << " reporting to duty. " << endl;
            authenticated = true;
            break;
        }
        else
        {
            cout << "Wrong number or password. You have " << 3 - i << " attempts left: ";
            cin.getline(pass, 25, '\n');
        }
    }

    if (!authenticated)
    {
        cout << "Too many incorrect attempts. Access de! Reporting to Admins... " << endl;
        fstream activity;
        activity.open("activity.txt", ios::app);
        activity << employee_num << "Employee " << " suspiciously made incorrect attemptsm at " << ctime(&now) << endl; // reporting to activity.txt for admin access
        activity.close();
        return;
    }

    alerts(); // Alerts for restocking product
    int choice;
    cout << "--------------------------- O P T I O N S -------------------------------" << endl;
    cout << "\n1 Make an Announcement \n2 Restock items \n3 View Support Requests \n4 View Feedbacks \n5 Add items in menu \n6 Edit Menu  \n7 Exit \nEnter here: " << endl;
    cin >> choice;
    cin.ignore();
    while (choice < 1 || choice > 7) // Input validation
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
        cin.ignore();
    }
    cout << "----------------------------------------------------------------------------" << endl;
    if (choice == 1)
    {
        char announcement[100];
        fstream announce;
        announce.open("./announcements.txt", ios::out);
        cout << "Enter the announcement: ";
        cin.getline(announcement, 100, '\n');
        announce << announcement << endl; // Announcement ko announcement wali file mai daal rahi hun taake usse access kar ke customer ko display karwa saku
    }
    else if (choice == 2)
    {
            fstream employee;
            employee.open("employee.txt", ios:: in);
            int c = 0;
            int *num = new int [6];
            int *score = new int [6];
            char pass[6][25];

            while (employee >> num[c]) // storing employee file data in arrays first to update their score based on responding to customers 
            {
                employee.getline(pass[c], 25, '|');
                employee >> score [c];
                c++;
            }

            employee.close();

            employee.open("employee.txt", ios:: out);
            for (int i = 0; i < c; i ++)
            {
                if (num[i] == employee_num)
                {
                    score[i]++;
                }
                employee << num[i] << pass[i] << "|" << score[i] << endl;
            }
            employee.close();
            
        Restock();
    }
    else if (choice == 3)
    {
        queries(employee_num);
    }
    else if (choice == 4)
    {
        feedbacks(employee_num);
    }
    else if (choice == 5)
    {
        addMenu();
    }
    else if (choice == 6)
    {
        editMenu();
    }
    else
    {
        cout << "----------- SEE YOU SPACE FELLA -------------" << endl;
    }
}