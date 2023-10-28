#include <iostream>
#include <algorithm>
#include <string>
#include "password.cpp"

using namespace std;

int main() {
    int choice;
    string website, username, password;
    PasswordEntry p;
    while (true) {
        cout << "Password Manager" << endl;
        cout << "1. Add password" << endl;
        cout << "2. View password" << endl;
        cout << "3. Update password" << endl;
        cout << "4. Delete password" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter website: ";
                cin >> website;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                p.addPasswordEntry(website, username, password);
                break;
            case 2:
                cout << "Enter website: ";
                cin >> website;
                p.viewPasswordEntries(website);
                break;
            case 3:
                cout << "Enter website: ";
                cin >> website;
                cout << "Enter new password: ";
                cin >> password;
                p.updatePasswordEntry(website, password);
                break;
            case 4:
                cout << "Enter website: ";
                cin >> website;
                p.deletePasswordEntry(website);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
