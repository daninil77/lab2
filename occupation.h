#ifndef OCCUPATION_H
#define OCCUPATION_H

#include <QString>




enum TIPE {lecture=0,practice=1,laboratory=2,exam=3};

struct  Occupation
{
    int n;
    QString predmet;
    TIPE tipe;
    int aud;

};

#endif // OCCUPATION_H
