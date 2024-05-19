#include "Administrator.h"
#include <iostream>

bool Administrator::Login(string username, string password) {
    return Security::validate(username, password) == 2;
}