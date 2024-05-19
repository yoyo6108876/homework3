#include "User.h"
#include <iostream>
bool User::Login(string username, string password) {
    return Security::validate(username, password) == 1;
}