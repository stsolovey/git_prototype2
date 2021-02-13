#ifndef CHECKIFUSEREXISTS_H
#define CHECKIFUSEREXISTS_H
#include <QString>

class CheckIfUserExists
{
public:
    CheckIfUserExists();
    bool checkIfLoginExists(QString login);
    bool checkIfEmailExists(QString login);
};

#endif // CHECKIFUSEREXISTS_H
