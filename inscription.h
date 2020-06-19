#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QObject>
#include <QWidget>
#include <QDate>
#include <QSqlQueryModel>

class inscription
{
public:
    inscription();
    bool ajouter();
    inscription(int,QDate,QDate);
    int get_id();
    int get_confirm();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    bool modifier3(int);
    bool modifier2(int);
    QDate get_datedebut();
    QDate get_datefin();
    QSqlQueryModel * chercher(int);
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * chercher2(int);

private:
    int idinscri;
    QDate datedebut;
    QDate datefin;
    int confirm=0;
};

#endif // INSCRIPTION_H
