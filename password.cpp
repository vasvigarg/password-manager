#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PasswordEntry {
    string website;
    string username;
    string password;
};

vector<PasswordEntry> passwordDatabase;

void addPasswordEntry(const PasswordEntry& entry) {
    passwordDatabase.push_back(entry);
}

void viewPasswordEntries() {
    for (const auto& entry : passwordDatabase) {
        cout << "Website: " << entry.website << "\n";
        cout << "Username: " << entry.username << "\n";
        cout << "Password: " << entry.password << "\n\n";
    }
}

void updatePasswordEntry(const string& website, const string& newPassword) {
    for (auto& entry : passwordDatabase) {
        if (entry.website == website) {
            entry.password = newPassword;
            return;
        }
    }
}

void deletePasswordEntry(const string& website) {
    passwordDatabase.erase(
        remove_if(passwordDatabase.begin(), passwordDatabase.end(),
            [website](const PasswordEntry& entry) { return entry.website == website; }),
        passwordDatabase.end());
}

string encryptPassword(const string& password, int shift) {
    string encryptedPassword = password;
    for (char& c : encryptedPassword) {
        if (isalpha(c)) {
            c = static_cast<char>((c - 'a' + shift) % 26 + 'a');
        }
    }
    return encryptedPassword;
}

string decryptPassword(const string& encryptedPassword, int shift) {
    string decryptedPassword = encryptedPassword;
    for (char& c : decryptedPassword) {
        if (isalpha(c)) {
            c = static_cast<char>((c - 'a' - shift + 26) % 26 + 'a');
        }
    }
    return decryptedPassword;
}

string generateStrongPassword(int length) {
    const string charset =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-";
    string password;
    password.reserve(length);
    srand(time(0));
    for (int i = 0; i < length; ++i) {
        password.push_back(charset[rand() % charset.length()]);
    }
    return password;
}