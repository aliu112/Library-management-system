#ifndef __user_h__
#define __user_h__
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class User{
    private:
        vector<User> userList;
        vector<string> userNameList;
        vector<string> passwordList;
        bool isAdmin;

    public:
        User();
        bool isValidLogin(string, string);
        void addAccount(string, string);
        void removeAccount(string, string);
};

#endif
