#include "etudiant.h"
#include <QDebug>
#include "connexion.h"
Etudiant::Etudiant()
{
idinscription=0;
id=0;
idclasse=0;
nom="";
prenom="";

}
Etudiant::Etudiant(int id,QString nom,QString prenom,int idclasse,int idinscription)
{
  this->id=id;
  this->nom=nom;
  this->idinscription=idinscription;
  this->idclasse=idclasse;
  
  this->prenom=prenom;
}
QString Etudiant::get_nom(){return  nom;}
QString Etudiant::get_prenom(){return prenom;}
int Etudiant::get_id(){return  id;}
int Etudiant::get_idclasse(){return  idclasse;}
int Etudiant::get_idinscription(){return  idinscription;}

bool Etudiant::ajouter()
{
QSqlQuery testt;
QSqlQuery query;
QString res= QString::number(id);
QString resclasse= QString::number(idclasse);
QString resinscription= QString::number(idinscription);
query.prepare("INSERT INTO etudiants (ID, NOM, PRENOM,IDCLASSE,IDINSCRIPTION) "
                    "VALUES (:id, :nom, :prenom,:idclasse, :idinscription)");
query.bindValue(":id", res);
query.bindValue(":idclasse", resclasse);
query.bindValue(":idinscription", resinscription);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
testt.prepare("SELECT * FROM etudiants WHERE id = :id");
testt.exec();
if (testt.size() !=1)
{
  return    query.exec();}
return (1==2);
}

QSqlQueryModel * Etudiant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from etudiants");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("idclasse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idinscription"));
    return model;
}

bool Etudiant::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiants where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel *Etudiant::chercher(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);
                QSqlQuery query;
                query.prepare("select * FROM etudiants WHERE  id = :id ");
                query.bindValue(":id", res);
                query.exec();
                model->setQuery(query);


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("idclasse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("idinscription"));
        return model;
}
QSqlQueryModel * Etudiant::affichertriid()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from etudiants ORDER by ID");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("idclasse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idinscription"));
    return model;
}
QSqlQueryModel * Etudiant::affichertriclasse()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from etudiants ORDER by IDCLASSE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("idclasse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idinscription"));
    return model;
}
QSqlQueryModel * Etudiant::affichertriinscription()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from etudiants ORDER by IDINSCRIPTION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("idclasse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idinscription"));
    return model;
}

bool Etudiant::modifier(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("UPDATE etudiants SET ID = :id,NOM = :nom, PRENOM = :prenom,IDCLASSE = :id_classe,IDINSCRIPTION = :id_inscription  WHERE ID = :id");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":id_classe", idclasse);
query.bindValue(":id_inscription", idinscription);


return    query.exec();
}
