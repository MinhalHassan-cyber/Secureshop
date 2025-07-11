#include "admin.h"
void SalesReport()
{
    cout << "----------------------------------- S A L E S  R E P O R T -----------------------------" << endl;
    int Cid[20], Cprice[20], Cstock[20];
    char Cname[20][100], Ccateg[20][100];
    int j = 0;

    ifstream order("orders.txt");
    if (!order) {
        cerr << "Error: Could not open orders.txt" << endl;
    }
    
    while (order >> Cid[j] >> Cprice[j] >> Cstock[j]) {
        order.ignore(); 
        order.getline(Cname[j], 100, '|');
        order.getline(Ccateg[j], 100);
        j++;
    }
    order.close();

    int topID = 0;
    int maxSold = 0;  
    for (int i = 0; i < j; i++) {
        if (Cstock[i] > maxSold) {
            maxSold = Cstock[i];
            topID = i;
        }
    }

    int topRevenue = Cstock[topID] * Cprice[topID];

    cout << "Top-Selling Product Details:" << endl;
    cout << "ID: " << "           " << Cid[topID] << endl;
    cout << "Name: " << Cname[topID] << endl;
    cout << "Category: " << "    " << Ccateg[topID] << endl;
    cout << "Quantity Sold: " << "      " << Cstock[topID] << endl;
    cout << "Revenue Generated: " << "     $" << topRevenue << endl;
}
void ImportExport()
{
    int choice;
    cout << "Press 1 to see Data to Export \nPress 2 to see Data to Import \nEnter here: ";
    cin >> choice;
    
    while (choice < 1 or choice > 2)
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice; 
    }

    if (choice == 1)
    {
    cout << " \n     Following products are getting out of stock! " << endl;
    cout << "-------------------- A L E R T S -----------------------" << endl;
    cout << "-ID-------------STOCK----------NAME-------CATEGORY------" << endl;
    bool real = false;
    int id, price, stock;
    char name[30], categ[30];
    fstream menu;
    menu.open("./menu.txt", ios::in);
    while (menu >> id >> price >> stock) // reading from menu
    {
        menu.getline(name, 30, '|');
        menu.getline(categ, 30, '\n');
        if (stock < 5) // If product is less than 5 in stock then admin gets option to export items 
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
    else
    {
    int number, i = 0;
    int id[25], price[25], stock[25];
    char name[25][100], categ[25][100];
    cout << "Enter the number of items each to restock for all these products : ";
    cin >> number;
    while (number < 5)
    {
        cout << "Not enough items, Try again: ";
        cin >> number;
    }
 
    ifstream file_in, order;
    file_in.open("./menu.txt");
    while (file_in >> id[i] >> price[i] >> stock[i]) // Storing all data of menu in arrays first
    {
        file_in.getline(name[i], 100, '|');
        file_in.getline(categ[i], 100, '\n');
        i++;
    }
    file_in.close();

    ofstream update;
    update.open("menu.txt", ios:: out);

    for (int j = 0; j < i; j++)
    {
        if (stock [j] < 5)
        {
            stock[j] = number;
        }
        update << id[j] << " " << price[j] << " " << stock[j] << setw(20) << name[j] << setw(15) << "|" << categ[j] << endl;
    }
    cout << "Changes done!" << endl;
    update.close();
    }
    }

    else 
    {
    cout << "-------------------- I M P O R T S -----------------------" << endl;
    cout << "-ID-------------STOCK----------NAME-------CATEGORY------" << endl;
    bool real = false;
    int id, price, stock;
    char name[30], categ[30];
    fstream menu;
    menu.open("./menu.txt", ios::in);
    while (menu >> id >> price >> stock) // reading from menu
    {
        menu.getline(name, 30, '|');
        menu.getline(categ, 30, '\n');
        if (stock > 20) // If product is great in stock then admin gets option to export items 
        {
            real = true;
            cout << id << setw(10) << stock << setw(20) << name << setw(20) << categ << endl;
        }
    }
    if (!real)
    {
        cout << endl
             << "  No products are currently available for Imports!" << endl
             << endl;
    }
    else
    {
    int number, i = 0;
    int id[25], price[25], stock[25];
    char name[25][100], categ[25][100];
    cout << "Enter the number of items each to import for all these products : ";
    cin >> number;
    while (number > 15)
    {
        cout << "Too many items to import might affect our daily sales, Try again: ";
        cin >> number;
    }
 
    ifstream file_in, order;
    file_in.open("./menu.txt");
    while (file_in >> id[i] >> price[i] >> stock[i]) // Storing all data of menu in arrays first
    {
        file_in.getline(name[i], 100, '|');
        file_in.getline(categ[i], 100, '\n');
        i++;
    }
    file_in.close();

    ofstream update;
    update.open("menu.txt", ios:: out);

    for (int j = 0; j < i; j++)
    {
        if (stock [j] < 5)
        {
            stock[j] = number;
        }
        update << id[j] << " " << price[j] << " " << stock[j] << setw(20) << name[j] << setw(15) << "|" << categ[j] << endl;
    }
    cout << "Changes done!" << endl;
    update.close();
    }
    }


}
void announce()
{
        char *n = new char [100];
        fstream announce;
        announce.open("./announcements.txt", ios::out);
        cout << "Enter the announcement: ";
        cin.getline(n, 100, '\n');
        announce << n;
}
void activity()
{
    cout << "---------------- A --- C --- T --- I --- V --- I --- T --- Y --------------------" << endl;
    int choice;
    char active[15][200], path[30] = "./customers/", report[100];
    fstream activity;
    activity.open("./activity.txt", ios::in | ios::out);
    {
        int i = 0;
        while (activity.getline(active[i], 25, ' '))
        {
            cout << i << ": " << endl;
            activity.getline(report, 200, '\n');
            cout << active[i] << " " << report << endl;
            i++;
        }
    }
    activity.close();

    cout << "\nPress 1 to Remove customer \nPress 2 to Remove Employee \nPress 3 to exit \nEnter here: " << endl;
    cin >> choice;
    cin.ignore();
    while (choice < 1 or choice > 3) // Input validation
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 1)
    {
        char user[25];
        cout << "\nEnter the user of the customer: ";
        cin.getline(user, 25, '\n');
        bool match = true;

        for (int i = 0; i < 15; i++)
        {
            int j = 0;
            bool rowMatch = true;
            while (active[i][j] != '\0' && user[j] != '\0')
            {
                if (user[j] != active[i][j])
                {
                    rowMatch = false;
                    break;
                }
                j++;
            }
        }
        if (match)
        {
            int j = 12;
            char ext[5] = ".txt"; // to build a path to construct file

            for (int i = 0; user[i] != '\0'; i++, j++) // adding user name to path
            {
                path[j] = user[i];
            }
            for (int i = 0; ext[i] != '\0'; i++, j++) // adding extension to path after username
            {
                path[j] = ext[i];
            }
            remove(path);
            cout << "User Removed! " << endl;
        }

        else
        {
            cout << "User not found! (May have already been removed by other admins)" << endl;
        }
    }

    else if (choice == 2)
    {
        int employee, emp_num, i = 0;
        cout << "\nEnter the Employee number to remove: ";
        cin >> employee;

        cout << "\nHow many employees are there in total: ";
        cin >> emp_num;

        int *total = new int[emp_num];
        char pass[emp_num][10];
        ifstream emp;
        emp.open("./employee.txt");

        while (emp >> total[i]) // storing employees in an array first
        {
            emp.getline(pass[i], 10, '\n');
            i++;
        }

        emp.close();

        bool exists = false;
        ofstream check;
        check.open("./employee.txt", ios::out);
        for (int i = 0; i < emp_num; i++)
        {
            if (employee == total[i])
            {
                exists = true;
                continue; // Do not write employee data // Removing the employee data from the file
            }
            check << total[i] << pass[i] << endl;
        }
        check.close();

        if (!exists)
        {
            cout << "Employee does not exists or may have already been removed by another admin. ";
        }
        else
        {
            cout << "Employee Removed!" << endl;
        }
    }
}
void feedback()
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
        }
    }
}
void supports()
{

    cout << "------------------- SUPPORT REQUESTS ----------------------" << endl;
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
            }
            else
            {
                cout << "User not found. " << endl;
            }
        }
    }
}
// generate OTP
void adminlogin()
{
    time_t now = time(nullptr);
    int admin_num, i=0, choice;
    char security[23], announcement[100];
    char answer[] = "topak";
    bool key = true, match = false ;
    cout << "Enter your admin number: ";
    cin >> admin_num;
    cin.ignore();

    ifstream admin;
    admin.open("admin.txt", ios:: in);
    int *total = new int [6];
    while (admin >> total[i])
    {
        if (admin_num == total[i])
        {
            match = true;
            break;
        }
        i++;
    }

    if (!match) 
    {
        cout << "             ADMIN NUM NOT FOUND ! ACCESS DE     " << endl;
        fstream active;
        active.open("./activity.txt", ios::app);
        active << "An outsider tried to access admin portal at " << ctime(&now) << "." << endl; // Adding activity
        active.close();
        return;

    }

    cout << "-------------------- SECURTIY REGION -------------------" << endl;
    cout << "Welcome Real Cowboy " << admin_num << "." << endl;
    cout << "What is your favorite weapon?\n"; // security question for each admin
    cin.getline(security, 23, '\n');

    for (int i = 0; answer[i] != '\0'; i++)
    {
        if (answer[i] != security[i]) // dono password compare horahe hain
            bool key = false;
            break;
    }

    if (!key)
    {
        cout << "Wrong answer! Access de.";
        fstream active;
        active.open("./activity.txt", ios::app);
        active << "Admin " << admin_num << " did not answer security question correctly at " << ctime(&now) << endl; // Adding activity
        active.close();
        return;
    }

    cout << "                           Access granted!" << endl << endl;
    cout << "--------------------------- O P T I O N S -------------------------------" << endl;
    cout << "1  Check actvitiy \n2  Make an announcement \n3  Generate discount code \n4  Bulk Import or Export Data \n5  View Support Requests \n6  View Feedbacks  \n7  View Sales Report \n8  View Employee Performance report \n9  View Sales across time periods \n10 Add Employee \n11 Exit \nEnter here: ";
    cin >> choice;
    cin.ignore();

    while (choice < 1 || choice > 11) // Input validation
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 1)
    {
        activity();
    }
    else if (choice == 2)
    {
        announce();
    }
    else if (choice == 3)
    {
        int percent;
        char *code = new char [50];
        cout << "Enter the discount code: ";
        cin.getline(code, 50, ' ');
        cout << "Enter the discount percentage: ";
        cin >> percent;

        while (percent <  0)
        {
            cout << "Invalid. Try again: ";
            cin >> percent;
        }

        ofstream discount;
        discount.open("discounts.txt", ios:: app);
        discount << code << " " << percent << " %" << endl;

        int decision;
        cout << "-------- Discount code added. It is recommended to announce this to the customers... -----------" << endl;
        cout << "Press 1 to Announce this to the customers \nPress any other digit to exit \nEnter here: ";
        cin >> decision;
        if (decision == 1)
        {
            announce();
        }
        else
        {
            cout << "-------------------------------- GOOD WORK TODAY --------------------------" << endl;
        }
    }
     else if (choice == 4)
    {
        ImportExport();
    }
     else if (choice == 5)
    {
        supports();
    }
    else if (choice == 6)
    {
        feedback();
    }
    else if (choice == 7)
    {
        SalesReport();
    }
    else if (choice == 8)
    {
        cout << "---------------------------- E M P L O Y E E  R E P O R T ----------------------------"<<endl;
        char reports[150];
        ifstream employee;
        employee.open("SalesReport.txt", ios:: in);
        while (employee.getline(reports, 150, '\n'))
        {
            cout << reports << endl;
        }
        cout << "-------------------------------- S U M M A R Y ----------------------------------------------"<<endl;
    int employeeID[10], scores[10];
    char passwords[10][100];
    int count = 0;

    ifstream employeeFile("employee.txt");
    if (!employeeFile) {
        cerr << "Error: Could not open employee_data.txt" << endl;
        return;
    }

  
    while (employeeFile >> employeeID[count]) {
        employeeFile.getline(passwords[count], 100, '|');
        employeeFile >> scores[count];
        employeeFile.ignore(); 
        count++;
    }
    employeeFile.close();

    int topIndex = 0;
    for (int i = 1; i < count; i++) {
        if (scores[i] > scores[topIndex]) {
            topIndex = i;
        }
    }
    cout << "Top Performer Details:" << endl;
    cout << "Employee Number: " << employeeID[topIndex] << endl;
    cout << "Password: " << passwords[topIndex] << endl;
    cout << "Score: " << scores[topIndex] << endl;

    }
    else if (choice == 9)
    {
        cout << "ID--P-Stock------------Name----------Category--------Time---------"<<endl<<endl;
        char trends[250];
        ifstream watch;
        watch.open("times.txt");
        while (watch.getline(trends, 250, '\n'))
        {
            cout << trends << endl;
        }
        watch.close();
    }
    else if (choice == 10)
    {
        int num, compare;
        char pass[50];
        cout << "How many employees are there in total? \nEnter here: ";
        cin>> compare;
        cin.ignore();
        cout << "Add the latest number of employee: ";
        cin>>num;
        while (num < compare)
        {
            cout << "Match found! Enter a new number: ";
            cin >> num;
            cin.ignore();
        }
        cin.ignore();
        cout << "Add his password: ";
        cin.getline(pass, 50, '\n');
        ofstream upd;
        upd.open("employee.txt", ios::app);
        upd << num << " " << pass << "|" << 0 << endl;
        upd.close();
        cout << "Employee added successfully! "<<endl;

    }
    else
    {
        cout << "-------------------------- SEE YOU THE REAL COWBOY --------------------" << endl;
    }
}