# Secureshop
The Secure Shop project is a console-based retail management system developed in C++, designed with an emphasis on data security, user authentication, and role-based access control. It simulates the operations of a digital store while integrating fundamental cybersecurity concepts to ensure secure handling of sensitive data like user credentials, inventory records, and transaction logs.

The system features Admin and Customer roles, each with dedicated functionalities. Admins can add, update, and delete products, view sales history, manage user accounts, and generate secure transaction reports. Customers can sign up or log in securely, browse items, add products to cart, and checkout — with all transactions being logged for auditing purposes.

To enforce security, the project implements:

Encrypted login credentials using simple hashing techniques (e.g., SHA-256 simulated with custom logic),

Input validation to prevent buffer overflow and injection attempts,

Secure file handling, ensuring that all product, user, and transaction data are stored in encrypted or encoded form in external files (e.g., users.dat, products.dat, sales.log).

All sensitive operations are guarded by role-based permissions, ensuring unauthorized access is prevented at the logic level. Additionally, a logging module records user activities, supporting basic forensic analysis and accountability.

This project not only demonstrates core concepts of object-oriented programming, file I/O, and data structures in C++, but also reflects real-world secure coding practices, making it an ideal academic and practical project for students pursuing cybersecurity and software engineering.


