#include "customer.h"
void orderTXT() // ORDERS.TXT ke andar sales report ke hisaab se update karwane ke liye function
{
    // MODIFYING INTO ORDERS.TXT
    int Bid[10], Bprice[10], Bstock[10], Cid[20], Cprice[20], Cstock[20]; // ALL ARRAYS TO STORE DATA FROM RESPECTIVE FILES
    char Bname[10][100], Bcateg[10][100], Cname[20][100], Ccateg[20][100];
    int i = 0, j = 0;

    ifstream cart("cart.txt");
    if (!cart)
    {
        cout << "Error: Could not open cart.txt" << endl;
    }

    while (cart >> Bid[i] >> Bprice[i] >> Bstock[i])
    {
        cart.ignore();
        cart.getline(Bname[i], 100, '|');
        cart.getline(Bcateg[i], 100);
        i++;
    }
    cart.close();

    ifstream order("orders.txt");
    if (!order)
    {
        cout << "Error: Could not open orders.txt" << endl;
    }

    while (order >> Cid[j] >> Cprice[j] >> Cstock[j])
    {
        order.ignore();
        order.getline(Cname[j], 100, '|');
        order.getline(Ccateg[j], 100);
        j++;
    }
    order.close();

    ofstream order_out("orders.txt", ios::trunc);
    if (!order_out)
    {
        cout << "Error: Could not write to orders.txt" << endl;
    }

    for (int k = 0; k < j; k++)
    {
        for (int l = 0; l < i; l++)
        {
            if (Bid[l] == Cid[k])
            {
                Cstock[k] += Bstock[l];
                break;
            }
        }

        order_out << Cid[k] << " " << Cprice[k] << " " << Cstock[k]
                  << " " << setw(20) << Cname[k] << "| " << Ccateg[k] << endl;
    }

    for (int l = 0; l < i; l++) // Adding any new items from the cart that are not already in orders
    {
        bool match = false;
        for (int k = 0; k < j; k++)
        {
            if (Bid[l] == Cid[k])
            {
                match = true;
                break;
            }
        }
        if (!match)
        {
            order_out << Bid[l] << " " << Bprice[l] << " " << Bstock[l]
                      << " " << setw(20) << Bname[l] << "| " << Bcateg[l] << endl;
        }
    }

    order_out.close();
}
void itemstock(void) // jitne items purchase kiye ja rahe hain utne ki menu ke orignal items mai decrement laane ke liye function
{
    int id[25], price[25], stock[25], i = 0;
    char name[25][100], categ[25][100];
    ifstream file_in, order;
    ofstream update;

    file_in.open("./menu.txt");
    while (file_in >> id[i] >> price[i] >> stock[i]) // Storing all data in arrays first
    {
        file_in.getline(name[i], 100, '|');
        file_in.getline(categ[i], 100, '\n');
        i++;
    }
    file_in.close();

    order.open("cart.txt");
    int ID, Price, Stock, j = 0;
    char product[30], category[30];
    while (order >> ID >> Price >> Stock)
    {
        order.getline(product, 30, '|');
        order.getline(category, 30, '\n');
        for (int j = 0; j < i; j++)
        {
            if (ID == id[j])
            {
                stock[j] -= Stock;
                if (stock[j] < 0)
                {
                    stock[j] = 0;
                }
                break;
            }
        }

        update.open("./menu.txt", ios::out);
        for (int k = 0; k < i; k++)
        {
            update << id[k] << " " << price[k] << " " << stock[k] << name[k] << "|" << categ[k] << endl;
        }
    }
}
void support(char path[], char user[])
{
    cout << "------------------------ SUPPORT REQUESTS ---------------------------" << endl;
    char support[200], categ[25], name[25];
    char compare[25] = "Support";
    bool match = true;
    bool sameuser = true;
    fstream display;
    display.open("support.txt", ios::in);
    while (display.getline(name, 25, '|'))
    {
        match = true;
        sameuser = true;
        display.getline(support, 200, '|');
        display.getline(categ, 25, '\n');
        for (int i = 0; categ[i] != '\0'; i++)
        {
            if (categ[i] != compare[i])
            {
                match = false;
            }
        }
        for (int i = 0; name[i] != '\0'; i++)
        {
            if (name[i] != user[i])
            {
                sameuser = false;
            }
        }
        if (match && sameuser)
        {
            cout << support << endl;
        }
    }
    display.close();
    facilities(path, user);
}
void feedback(char path[], char user[])
{
    cout << "------------------------ FEEDBACKS ---------------------------" << endl;
    char feedback[200], categ[25], name[25];
    char compare[25] = "Feedback";
    bool match = true;
    bool sameuser = true;
    fstream display;
    display.open("support.txt", ios::in);
    while (display.getline(name, 25, '|'))
    {

        display.getline(feedback, 200, '|');
        match = true;
        sameuser = true;
        display.getline(categ, 25, '\n');
        for (int i = 0; categ[i] != '\0'; i++)
        {
            if (categ[i] != compare[i])
            {
                match = false;
            }
        }
        for (int i = 0; name[i] != '\0'; i++)
        {
            if (name[i] != user[i])
            {
                sameuser = false;
            }
        }
        if (match && sameuser)
        {
            cout << feedback << endl;
        }
    }
    display.close();
    facilities(path, user);
}
void displayWish(char path[], char user[])
{
    int id, money, stock, update;
    char name[200], purch[25], feedback[100];
    bool match;
    ifstream wish;
    wish.open(path, ios::in); // Displaying Wishlist
    char comp[20] = "Wishlist";
    wish.getline(name, 50, '\n'); // storing password and the username present at the top
    wish.getline(name, 50, '\n');
    cout << "--------------------------------------------- WISH LIST  --------------------------------------------------------" << endl;
    cout << " - ID ----------------------------------- NAME ---------- CATEG ---------- PRICE -------- ITEMS ------------------" << endl;
    while (wish >> id >> money >> stock)
    {
        match = true;
        wish.getline(name, 200, '|');
        wish.getline(purch, 20, '\n');
        for (int i = 0; purch[i] != '\0'; i++)
        {
            if (purch[i] != comp[i])
            {
                match = false;
                break;
            }
        }
        if (match)
        {

            cout << " " << id << setw(60) << name << setw(15) << money << setw(15) << stock << endl;
        }
    }
    wish.close();
    facilities(path, user);
}
bool addTowish(char path[], char user[])
{
    int id, stock;
    cout << "Enter the ID to add to List: ";
    cin >> id;
    bool find = false;
    char product[50];
    char categ[50];
    int money, avail, search;
    fstream wishL;
    wishL.open("./menu.txt", ios::in);
    while (wishL >> search >> money >> avail)
    {
        wishL.getline(product, 50, '|');
        wishL.getline(categ, 50, '\n');
        if (id == search)
        {
            find = true;
            break;
        }
    }
    wishL.close();
    if (find == true)
    {
        fstream list;
        list.open(path, ios::app);
        list << endl
             << search << " " << money << " " << 1 << " " << product << "|" << categ << "|Wishlist" << endl;
        list.close();
    }
    else
    {
        cout << "Item not found!\n"
             << endl;
    }

    displayWish(path, user);
    return true;
}
void PurchaseHistory(char path[], char user[])
{
    int id, price, stock, choice;
    char name[50], purch[25], feedback[100], categ[25];
    bool match;
    ifstream history;
    history.open(path, ios::in); // Displaying Purchase History
    char comp[20] = "History";
    history.getline(name, 50, '\n'); // taking password and username
    history.getline(name, 50, '\n');
    cout << "-------------------------------------------- PURCHASE HISTORY ------------------------------------------------" << endl;
    cout << " - ID ------------------------------------------- NAME ------------------------ PRICE ----------- ITEMS ------------------" << endl;
    while (history >> id >> price >> stock)
    {
        match = true;
        history.getline(name, 50, '|');
        history.getline(categ, 50, '|');
        history.getline(purch, 20, '\n');
        for (int i = 0; comp[i] != '\0'; i++)
        {
            if (purch[i] != comp[i])
            {
                match = false;
                break;
            }
        }
        if (match)
        {

            cout << id << setw(60) << name << setw(20) << price << setw(20) << stock << endl;
        }
    }
    cout << "Press: \n1 To leave Feedback \n2 Exit \nEnter here: ";
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
        cout << "Enter Feedback : ";
        cin.getline(feedback, 100, '\n');
        cout << "Feedback submitted! THANKYOU." << endl;
        fstream feed;
        feed.open("support.txt", ios::app);
        feed << user << "|" << feedback << "|Feedback" << endl;
        feed.close();
    }
    else
    {
        facilities(path, path);
    }
    history.close();
}
void RemoveItem()
{
    int removeID;
    cout << "Enter the ID you want to remove: " << endl;
    cin >> removeID;

    int id[25], price[25], stock[25], search1, search2, i = 0;
    char name[25][100];
    bool exists = false;

    ifstream store;
    store.open("./cart.txt");
    while (store >> id[i] >> price[i] >> stock[i])
    {
        store.getline(name[i], 100, '\n'); // storing all values in corresponding first
        i++;
    }
    store.close();

    ofstream cartcheck; // checking if the item is already present in the cart then increment in its number and price
    cartcheck.open("./cart.txt");
    for (int j = 0; j < i; j++) // jitni cheezein cart mai pari hain sirf utni dafa loop chalegi
    {
        if (id[j] == removeID)
        {
            exists = true;
            continue;
        }
        cartcheck << id[j] << " " << price[j] << " " << stock[j] << name[j] << endl;
    }
    if (!exists)
    {
        cout << "Item does not exists in your cart!" << endl;
    }
}
void displaycart()
{
    char arr1[50], arr2[50];
    int show1, show2, show3;
    ifstream display;
    display.open("./cart.txt", ios::in);
    cout << "----------------------------- C A R T ------------------------------------" << endl;
    cout << "-- ID ---- PRICE ---- ITEMS --------- NAME --------- CATEGORY ----" << endl;
    while (display >> show1 >> show2 >> show3) // CART SATH SATH DISPLAY HORAHI HAI
    {
        display.getline(arr1, 50, '|');
        display.getline(arr2, 50, '\n');
        cout << show1 << setw(10) << show2 << setw(10) << show3 << setw(15) << arr1 << setw(15) << arr2 << endl;
    }
}
void Checkout(char path[], char user[])
{
    // REMOVING ITEM FROM CART // CHECK OUT PROCESS // DISCOUNT CODES // ADDING PURCHASE HISTORY // ADDING TO ORDERS.TXT FOR SALES REPORT
    time_t now = time(nullptr);
    int id, price, stock, sum, rem, choice;
    double total = 0;
    char name[25], support[100];
    cout << "========================= FINAL CART ==============================" << endl;
    displaycart();

    do
    {
        cout << "\nDo you wish to remove any item?" << endl;
        cout << "1 Yes\n2 No \nEnter here: " << endl;
        cin >> rem;

        while (rem < 1 || rem > 2) // Input validation
        {
            cout << "Invalid choice. Try again: ";
            cin >> rem;
        }

        if (rem == 1)
        {
            RemoveItem();
        }
        displaycart();
    } while (rem == 1);

    cout << "\nThankyou for shopping with us today!  ";
    ifstream checkout;
    checkout.open("./cart.txt");

    while (checkout >> id >> price >> stock) // calculating total price from cart
    {
        checkout.getline(name, 25, '\n');
        sum = price * stock; // running sum of price multiplied by number of items of each product
        total += sum;
    }

    cout << "Your total is :  $" << total << endl;

    int disc;
    cout << "Press 1 to Enter a discount code \nPress any other digit to continue \nEnter here: ";
    cin >> disc;
    cin.ignore();
    if (disc == 1)
    {
        char discounts[50];
        cout << "Enter the discount code: ";
        cin.getline(discounts, 50, '\n');
        bool match = true;
        ifstream discount;
        discount.open("discounts.txt", ios::in);
        char code[50];
        int percent;
        while (discount.getline(code, 50, ' '))
        {
            discount >> percent;

            for (int i = 0; code[i] != '\0'; i++)
            {
                if (discounts[i] != code[i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                total = (total * (100.0 - percent)) / 100.0;
                cout << "Your new total is :  $" << total << endl;
            }
            else
            {
                cout << "Discount code not found! Proceeding without discounts..." << endl;
            }
        }
    }

    cout << "Loading Payment...   Payment successful!" << endl;
    cout << "Press: \n1 To leave Support requests \n2 Exit \nEnter here: ";
    cin >> choice;
    cin.ignore();
    while (choice < 1 or choice > 2) // Input validation
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
        cin.ignore();
    }

    if (choice == 1)
    {
        cout << "Enter Request : ";
        cin.getline(support, 100, '\n');
        cout << "Support Request submitted! THANKYOU." << endl;
        fstream feed;
        feed.open("support.txt", ios::app);
        feed << user << "|" << support << "|Support"; // adding the support request in supports to be viewed later on
        feed.close();
    }
    cout << "                               THANKYOU FOR SHOPPING WITH COWBOY BEBOP                        " << endl;
    cout << "-----------------------------          SEE YOU SPACE COWBOY            ---------------------------" << endl;

    fstream history; // ADDING PURCHASE HISTORY
    fstream update;  // saari purchases time.txt ke andar store karwane ke liye to get sales statistics across time periods
    history.open(path, ios::in);
    update.open("times.txt", ios::app);
    char data[50][100];
    int i;
    for (i = 0; history.getline(data[i], 100, '\n'); i++)
    {
    }
    history.close();
    history.open(path, ios::out);
    for (int a = 0; a <= i; a++)
    {
        history << data[a] << endl;
        if (a == 2)
        {
            char arr[30], arr2[30];
            int show1, show2, show3;
            ifstream display;
            display.open("./cart.txt", ios::in);
            while (display >> show1 >> show2 >> show3) // Adding the final cart to the purchase history
            {
                display.getline(arr, 30, '|');
                display.getline(arr2, 30, '\n');
                history << "  " << show1 << "        " << show2 << "               " << show3 << "      " << arr << "|" << arr2 << "|History" << endl;
                update << show1 << " " << show2 << " " << show3 << " " << arr << " " << arr2 << " " << ctime(&now) << endl;
            }
        }
    }
    history.close();
    update.close();
    orderTXT();
    itemstock();
    remove("cart.txt"); // Refreshing the cart
    fstream remake;
    remake.open("cart.txt", ios::out);
}

bool addTocart(char path[])
{
    int id[25], price[25], stock[25], search1, search2, i = 0;
    char name[25][100];
    char categ[25][100];
    bool find = false;
    bool exists = false;
    cout << "\nEnter ID of the product you want to buy: ";
    cin >> search1;

    ifstream store;
    store.open("./cart.txt");
    while (store >> id[i] >> price[i] >> stock[i])
    {
        store.ignore();
        store.getline(name[i], 100, '|'); // storing all values in corresponding first
        store.getline(categ[i], 100, '\n');
        i++;
    }
    store.close();

    ofstream cartcheck; // checking if the item is already present in the cart then increment in its number and price
    cartcheck.open("./cart.txt");
    for (int j = 0; j < i; j++) // jitni cheezein cart mai pari hain sirf utni dafa loop chalegi
    {
        if (id[j] == search1)
        {
            exists = true;
            stock[j]++;
        }
        cartcheck << endl
                  << id[j] << " " << price[j] << " " << stock[j] << name[j] << "|" << categ[j] << endl;
    }

    if (!exists) // if the item does not already exists in cart then searching for it in the menu
    {
        char product[50];
        char categ[50];
        int money, avail;
        fstream cart;
        cart.open("./menu.txt", ios::in);
        while (cart >> search2 >> money >> avail) // getting data from the menu
        {
            cart.ignore();
            cart.getline(product, 50, '|');
            cart.getline(categ, 50, '\n');
            if (search1 == search2) // if input id matches with the id present in menu
            {
                find = true;
                break;
            }
        }

        if (find == true)
        {
            fstream cart;
            cart.open("./cart.txt", ios::app);
            cart << endl
                 << search1 << " " << money << " " << 1 << " " << product << "|" << categ << endl;
        }
        else
        {
            cout << "Item not found!\n"
                 << endl;
        }
        cart.close();
    }

    displaycart(); // cart ko sath sath display karwa rahi hun
    return true;
}
void shopStart(char path[], char user[])
{
    int shopping;
    cout << "\n\nPress 1 to Add items in cart\nPress 2 to Add items in Wishlist \nPress 3 to Exit Shop \nEnter here: ";
    cin >> shopping; // variable for choosing facility

    while (shopping < 1 or shopping > 3)
    {
        cout << "Invalid option. Try again: "; // Input validation
        cin >> shopping;
    }

    if (shopping == 1)
    {
        while (addTocart(path)) // items get added and updated in cart.txt
        {
            int press;
            cout << "\nPress: \n1 Continue Shopping\n2 Proceed to Check out \n3 Main Menu\nEnter here:  ";
            cin >> press;

            while (press < 1 or press > 3) // input validation
            {
                cout << "Invalid option. Try again: ";
                cin >> press;
            }

            if (press == 1)
            {
                continue; // continue shopping
            }

            else if (press == 2)
            {
                Checkout(path, user); // proceeding to check out
                break;
            }

            else
            {
                shopStart(path, user); // back to main menu
                break;
            }
        }
    }
    else if (shopping == 2)
    {
        while (addTowish(path, user)) // items get updated in wishlist
        {
            int press;
            cout << "\nPress: \n1 Continue Adding\n2 Main Menu\nEnter here:  ";
            cin >> press;
            while (press < 1 or press > 3) // input validation
            {
                cout << "Invalid option. Try again: ";
                cin >> press;
            }

            if (press == 1)
            {
                continue;
            }

            else
            {
                shopStart(path, user);
                break;
            }
        }
    }
    else
    {

        cout << "\n\t\tSEE YOU SPACE COWBOY!" << endl;

        cout << "========================================================================================" << endl;
    }
}
void menudisplay(char path[], char user[])
{
    char arr[500];
    fstream display;
    display.open("./menu.txt", ios::in);

    cout << endl
         << "Do you wish to sort menu by: \n1 Display All \n2 By Price \n3 By Availability \n4 Category\nEnter here: ";
    int choice; // variable for initial choice
    cin >> choice;

    if (choice == 4)
    {
        int id, price, stock;
        char name[50], categ[50], categ1[8] = " Shoes", categ2[15] = " Outerwear", categ3[15] = " Bottoms"; // file mai jis tarah se data para hai usko match aur compare karane ke liye arrays
        bool match = true;
        cout << "\n\nWhich category would you like to be displayed?" << endl;
        cout << "1 Shoes\n2 Outerwear\n3 Bottoms\nEnter here: ";
        int choice1; // choice for category

        cin >> choice1;
        while (choice1 < 1 or choice1 > 3) // Input validation
        {
            cout << "Invalid choice. Try again: ";
            cin >> choice1;
        }

        cout << endl
             << endl;
        cout << "-------------------------------------------------MENU-----------------------------------";
        cout << "\n\n ID ================= Name ============ Price ==== Stock ========= Category =====\n";

        while (display >> id >> price >> stock) // file writing ke hisaab se the object is reading data
        {
            match = true;
            display.getline(name, 50, '|');
            display.getline(categ, 50, '\n');

            if (choice1 == 1) // for shoes
            {
                for (int i = 0; categ[i] != '\0'; i++)
                {
                    if (categ[i] != categ1[i]) // matching category with shoes
                    {
                        match = false;
                        break;
                    }
                }
                if (match)
                {
                    cout << id << setw(20) << name << setw(10) << price << setw(10) << stock << setw(20) << categ << endl;
                }
            }

            else if (choice1 == 2) // for outerwear
            {

                for (int i = 0; categ[i] != '\0'; i++) // matching category with outerwear
                {
                    if (categ[i] != categ2[i])
                    {

                        match = false;
                        break;
                    }
                }

                if (match)
                {
                    cout << id << setw(20) << name << setw(10) << price << setw(10) << stock << setw(20) << categ << endl;
                }
            }

            else // for bottoms
            {

                for (int i = 0; categ[i] != '\0'; i++)
                {

                    if (categ[i] != categ3[i]) // matching category with bottoms
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                {
                    cout << id << setw(20) << name << setw(10) << price << setw(10) << stock << setw(20) << categ << endl;
                }
            }
        }
    }
    else if (choice == 1)
    {
        int id, price, stock;
        char name[50], categ[50];
        cout << "-------------------------------MENU-----------------------------------";
        cout << "\n\n ID ======================================= Name ============ Price ==== Stock ========= Category =====\n"
             << endl;

        while (display >> id >> price >> stock)
        {
            display.getline(name, 50, '|');
            display.getline(categ, 50, '\n');
            cout << id << setw(50) << name << setw(15) << price << setw(15) << stock << setw(30) << categ << endl; // reading and displaying sath sath
        }
    }
    else if (choice == 2)
    {
        int id, price, avail;
        char name[50], categ[50];

        if (!display)
        {
            cout << "Error opening file!" << endl;
        }
        int choice2; // variable for choosing price range

        cout << "\n1 >15 $ \n2 >25 $ \n3 >30 $\n";
        cin >> choice2;

        while (choice2 < 1 or choice2 > 3) // input validation
        {
            cout << "Invalid choice. Try again: ";
            cin >> choice2;
        }
        cout << "------------------------------------------MENU-----------------------------------------";
        cout << "\n\n ID ================== Name ============ Price ==== Stock ========= Category =====\n";
        while (display >> id >> price >> avail)
        {
            display.getline(name, 50, '|');
            display.getline(categ, 50, '\n');
            if ((choice2 == 1 && price > 15) ||
                (choice2 == 2 && price > 25) ||
                (choice2 == 3 && price > 30)) // matching and displaying respective price ranges
            {
                cout << id << setw(55) << name << setw(15) << price << setw(15) << avail << setw(30) << categ << endl;
            }
        }
    }
    else if (choice == 3)
    {
        int id, price, avail;
        char name[50], categ[50];
        cout << "---------------------------------------------MENU------------------------------";
        cout << "\n\n ID ================= Name ============ Price ==== Stock ========= Category =====\n"
             << endl;
        while (display >> id >> price >> avail)
        {
            display.getline(name, 50, '|');
            display.getline(categ, 50, '\n');
            if (avail != 0) // displaying the products which are not out of stock only
            {
                cout << id << setw(55) << name << setw(15) << price << setw(15) << avail << setw(30) << categ << endl;
            }
        }
    }
    display.close();

    shopStart(path, user);
}
void facilities(char user[], char path[])
{
    int facility;
    char arr[100];
    fstream display;
    display.open("./announcements.txt", ios::in); // Displaying announcement upon login
    cout << "\n\nAnnouncements: \n";
    display.getline(arr, 100, ';');
    cout << arr;
    while (display.getline(arr, 100, ';'))
    {
        cout << arr << endl;
    }
    display.close();
    cout << "\n------------------------------- B A N G -------------------------------------" << endl
         << endl;
    cout << endl
         << "Press : \n1 Start Shopping \n2 View My Purchase History \n3 View My wishlist \n4 View My feedback response \n5 View My support requests \n6 Exit \nEnter here: ";
    cin >> facility;

    while (facility < 1 || facility > 6) // Input validation
    {
        cout << "Invalid choice. Try again: ";
        cin >> facility;
    }

    if (facility == 1)
    {
        menudisplay(path, user);
    }
    else if (facility == 2)
    {
        PurchaseHistory(path, user);
    }
    else if (facility == 3)
    {
        displayWish(path, user);
    }
    else if (facility == 4) // calling respective functions of options
    {
        feedback(path, user);
    }
    else if (facility == 5)
    {
        support(path, user);
    }
    else
    {
        cout << "================================ SEE YOU SPACE COWBOY ===============================" << endl;
    }
}
void encryptpass(char pass[])
{

    for (int c = 0; pass[c] != '\0'; c++) // user ki security ke liye password encrypted form mai store ho raha hai
    {
        pass[c] = (pass[c] + pass[c]) % 128; // jo ascii range ka character number hai utni value add horahi hai ussi character ke andar
    }
    // got this inspiration from Assignment number 5 of functions Question number 6
}
bool passValidation(char pass[])
{
    int i = 0;
    while (pass[i] != '\0') // calculating length
    {
        i++;
    }

    if (i < 8) // password must be 8 characters long
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool passwordcompare(char pass[], char path[])
{
    encryptpass(pass);           // password encrypt ho kar directly encrypted wale se compare horaha hai instead of file wala getting decrypted first
    char trash[10], compare[20]; // "Password: " store karne ke liye ek trash array jiska ending delimeter ':' hai
    ifstream o1;
    o1.open(path, ios::in);
    o1.get(trash, 9);
    o1.ignore(1, ':');
    o1.get(compare, 20, '\n');
    for (int i = 0; compare[i] != '\0'; i++)
    {
        if (compare[i] != pass[i]) // dono password compare horahe hain
            return false;
    }
    return true;
}

void constructPath(char user[], char path[])
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
}

void customerlogin(void)
{
    time_t now = time(nullptr);
    int sign; // To get the choice of sign up or login from User
    char user[20], pass[20], email[30], path[50] = "./customers/";
    cout << "-------------------------------------REGISTRATION PORTAL-----------------------------------\n\n";
    cout << "Press 0 for New User\nPress 1 for Registered User\nEnter here: ";
    cin >> sign;
    cin.ignore();

    while (sign < 0 || sign > 1) // input validation
    {
        cout << "Invalid option! Try again: ";
        cin >> sign;
        cin.ignore();
    }

    if (sign == 0) // for new user
    {

        cout << "\nEnter your username: ";
        cin.getline(user, 20, '\n');

        cout << "Enter your password: ";
        cin.getline(pass, 20, '\n');

        constructPath(user, path);

        ifstream check; // if file opens then user already exists
        check.open(path, ios::in);
        if (check)
        {
            cout << "You are already registered!\n" // Taking user to directly login portal if he already exists
                 << endl;

            if (passwordcompare(pass, path)) // comparing password
            {
                facilities(user, path);
            }
            else
            {
                bool authenticated = false;
                for (int attempts = 0; attempts < 3; ++attempts)
                {
                    if (passwordcompare(pass, path))
                    {
                        cout << "Authentication done! Welcome back " << user << endl;
                        authenticated = true; // Set the flag to true on successful authentication
                        facilities(user, path);
                        break;
                    }
                    else
                    {
                        cout << "Wrong password. Try again (" << (3 - attempts) << " attempts remaining): ";
                        cin.getline(pass, 20, '\n');
                    }
                }
                check.close();
                if (!authenticated) // If the flag is still false after the loop
                {
                    cout << "Too many failed attempts. Access de.\n";
                    ofstream activity;
                    activity.open("./activity.txt", ios::app);
                    activity << user << " chose sign in instead of log in and had 3 failed login attempts at" << ctime(&now) << endl; // updating activity for admin
                }
            }
        }

        else
        {

            while (passValidation(pass)) // returns true if the password is less than 8 characters
            {
                cout << "Password must be at least 8 characters long! Try again: ";
                cin.getline(pass, 20, '\n');
            }

            fstream o1;
            o1.open(path, ios::app);

            while (true) // loop is liye lagaya taake facilities function ko call kar saku sirf tab jab user ka data save hojaye
            {
                if (o1)
                {
                    encryptpass(pass);
                    o1 << "Password:" << pass << "\nUsername: " << user << endl;
                    o1.close();
                    cout << "Registration successful! Your details have been saved.\n";
                    facilities(user, path);
                    break;
                }
                else
                {
                    cout << "Error saving data! Please try again.\n";
                    break;
                }
            }
        }
    }
    else if (sign == 1)
    {

        ifstream o1;
        do
        {

            cout << "\nEnter your username: ";
            cin.getline(user, 20, '\n');

            cout << "Enter your password: ";
            cin.getline(pass, 20, '\n');

            constructPath(user, path);

            o1.open(path, ios::in);
            if (o1)
            {
                bool authenticated = false; // Flag to track authentication status

                for (int attempts = 0; attempts < 3; ++attempts)
                {
                    if (passwordcompare(pass, path))
                    {
                        cout << "Authentication done! Welcome back " << user << endl;
                        authenticated = true; // Set the flag to true on successful authentication
                        o1.close();
                        facilities(user, path);
                        break;
                    }
                    else
                    {
                        cout << "Wrong password. Try again (" << (3 - attempts) << " attempts remaining): ";
                        cin.getline(pass, 20, '\n');
                    }
                }

                if (!authenticated) // If the flag is still false after the loop
                {
                    cout << "Too many failed attempts. Access de.\n";
                    ofstream activity;
                    activity.open("./activity.txt", ios::app);
                    activity << user << " had 3 failed login attempts at time: " << " Access was de. " << endl; // updating activity for admin
                }
            }
            else
            {
                cout << "Data not found, please try again!\n";
            }
        } while (!o1); // while the credentials do not match with the registered users
    }

    else
        cout << "Invalid input. Please restart the program and try again.\n";
}
