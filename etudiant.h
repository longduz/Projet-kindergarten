#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Etudiant
{public:
    Etudiant();
    Etudiant(int,QString,QString,int,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    int get_idclasse();
    int get_idinscription();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * affichertriinscription();
    QSqlQueryModel * affichertriid();
    QSqlQueryModel * affichertriclasse();
     QSqlQueryModel * chercher(int);
    bool supprimer(int);
    bool modifier(int id);
private:
    QString nom,prenom;
    int idclasse;
    int id;
    int idinscription;
};

#endif // ETUDIANT_H
