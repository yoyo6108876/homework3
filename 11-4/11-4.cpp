#include <iostream>
#include "Administrator.h"
#include "User.h"

using namespace std;

int main() {
    User user;
    Administrator admin;

    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (admin.Login(username, password)) {
        cout << "Administrator login successful." << endl;
    }
    else if (user.Login(username, password)) {
        cout << "User login successful." << endl;
    }
    else {
        cout << "Login failed." << endl;
    }

    return 0;
}
