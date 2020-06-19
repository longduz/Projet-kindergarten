#include "inscription.h"
#include "QString"
#include <QDebug>
#include "connexion.h"
#include <QtSql>
inscription::inscription()
{
    idinscri=0;
    datefin=QDate(1,1,1);
    datedebut=QDate(1,1,1);
    int confirm=0;



}
inscription::inscription(int idinscri,QDate datedebut,QDate datefin)
{
    this->idinscri=idinscri;
    this->datedebut=datedebut;
    this->datefin=datefin;
    confirm=0;

}
int inscription::get_id(){return idinscri;}
QDate inscription::get_datefin(){return datefin;}
QDate inscription::get_datedebut(){return datedebut;}
int inscription::get_confirm(){return confirm;}
bool inscription::ajouter(){

    QSqlQuery t;
    QSqlQuery query;
    QString res= QString::number(idinscri);
    QString res1= QString::number(confirm);

    query.prepare("INSERT INTO inscription (ID,DATEDEBUT,DATEFIN,CONFIRMATION) "
                        "VALUES (:id,:datedebut,:datefin,:confirmation)");

    query.bindValue(":id", res);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":confirmation", res1);
    t.prepare("select * from inscription where ID = :id ");
    t.exec();
    if (t.size() == 0)
    {
      return    query.exec();}
    return (1==2);
    }



bool inscription::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from inscription where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


QSqlQueryModel * inscription::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from inscription");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEDEBUT "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEFIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CONFIRMATION"));

    return model;
}
bool inscription::modifier(int id){
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE inscription SET DATEDEBUT = :datedebut,DATEFIN = :datefin WHERE ID= :id");
    query.bindValue(":id", res);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);




    return    query.exec();


}

QSqlQueryModel *inscription::chercher(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);
                QSqlQuery query;
                query.prepare("select * FROM etudiants WHERE  id = :id ");
                model->setQuery("select * FROM inscription WHERE  ID = :id ");
                query.bindValue(":id", res);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Entrée "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Sortie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Confirmation"));

        return model;
}
QSqlQueryModel *inscription::chercher2(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(id);
                QSqlQuery query;
                query.prepare("select * FROM etudiants WHERE  IDINSCRIPTION = :id ");
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
QSqlQueryModel *inscription::afficher2()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QDate res= QDate::currentDate();
                QSqlQuery query;
                query.prepare("select * FROM inscription WHERE  DATEFIN < :date and CONFIRMATION = 0");

                query.bindValue(":date", res);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date Entrée "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Sortie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Confirmation"));

        return model;
}
bool inscription::modifier2(int id){
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE inscription SET DATEFIN = :datefin WHERE ID= :id");
    query.bindValue(":id", res);

    query.bindValue(":datefin", datefin);




    return    query.exec();


}
bool inscription::modifier3(int id){
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1=QString::number('1');
    query.prepare("UPDATE inscription SET CONFIRMATION = :datedebut WHERE ID= :id");
    query.bindValue(":id", res);
    query.bindValue(":datedebut",res1);





    return    query.exec();


}



