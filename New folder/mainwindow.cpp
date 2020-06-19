#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include "QPixmap"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
QPixmap pixamine("E:/aio210/Atelier_Crud_Vf/Atelier_Crud_Vf/download1.png");
QPixmap pix2amine("E:/aio210/Atelier_Crud_Vf/Atelier_Crud_Vf/smartkidz1.jpg");
ui->image_1aminee->setPixmap(pixamine);
ui->image_2aminee->setPixmap(pix2amine.scaled(350,350,Qt::KeepAspectRatio));
ui->tabetudiantaminee->setModel(tmpetudiant.afficher());
ui->tabetudiant_3aminee->setModel(tmpeinscription.afficher());
ui->tabetudiant_6aminee->setModel(tmpeinscription.afficher2());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouteraminee_clicked()
{
    int id = ui->lineEdit_idaminee->text().toInt();
    QString nom= ui->lineEdit_nomaminee->text();
    QString prenom= ui->lineEdit_prenomaminee->text();
    int idinscription = ui->lineEdit_idinscriptionaminee->text().toInt();
    int idclasse = ui->lineEdit_idclasseaminee->text().toInt();
  Etudiant e(id,nom,prenom,idclasse,idinscription);
  bool test=e.ajouter();
  if(test)
{

      ui->tabetudiantaminee->setModel(tmpetudiant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimeraminee_clicked()
{
int id = ui->lineEdit_id_2aminee->text().toInt();
bool test=tmpetudiant.supprimer(id);
if(test)
{ui->tabetudiantaminee->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_chercheraminee_clicked(){

    int id = ui->lineEdit_id_3aminee->text().toInt();
    ui->tabetudiant_2aminee->setModel(tmpetudiant.chercher(id));

}
void MainWindow::on_pb_inscriaminee_clicked(){

   ui->tabetudiantaminee->setModel(tmpetudiant.affichertriinscription());
}
void MainWindow::on_pb_idaminee_clicked(){
ui->tabetudiantaminee->setModel(tmpetudiant.affichertriid());

}
void MainWindow::on_pb_classeaminee_clicked(){


    ui->tabetudiantaminee->setModel(tmpetudiant.affichertriclasse());
}




void MainWindow::on_pb_ajouter_2aminee_clicked()
{

    int id = ui->lineEdit_id_9aminee->text().toInt();
    QDate date_entree= ui->dateEdit_3aminee->date();
    QDate date_sortie=ui->dateEdit_4aminee->date();
    inscription e(id,date_entree,date_sortie);
    bool test=e.ajouter();
    if(test)
  {

        ui->tabetudiant_3aminee->setModel(tmpeinscription.afficher());
        ui->tabetudiant_6aminee->setModel(tmpeinscription.afficher2());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une inscription"),
                    QObject::tr("Inscription ajoutée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une inscription"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }



void MainWindow::on_pb_chercher_2aminee_clicked()
{
    int id = ui->lineEdit_id_10aminee->text().toInt();
    ui->tabetudiant_4aminee->setModel(tmpeinscription.chercher(id));
    
}

void MainWindow::on_pb_supprimer_2aminee_clicked()
{
    int id = ui->lineEdit_id_11aminee->text().toInt();
    bool test=tmpeinscription.supprimer(id);
    if(test)
    {ui->tabetudiantaminee->setModel(tmpetudiant.afficher());//refresh
     ui->tabetudiant_3aminee->setModel(tmpeinscription.afficher());

        QMessageBox::information(nullptr, QObject::tr("Supprimer une inscription"),
                    QObject::tr("Inscription supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une inscription"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_id_2aminee_clicked()
{
    
}

void MainWindow::on_pb_inscri_2aminee_clicked()
{
    
}

void MainWindow::on_pb_modifier_1aminee_clicked()
{

    int idd=ui->lineEdit_id_4aminee->text().toInt();
    QString nom= ui->lineEdit_id_5aminee->text();
    QString prenom= ui->lineEdit_id_6aminee->text();
    int idinscription = ui->lineEdit_id_7aminee->text().toInt();
    int idclasse = ui->lineEdit_id_8aminee->text().toInt();
  Etudiant e(idd,nom,prenom,idclasse,idinscription);
    bool test=e.modifier(idd);
     if(test)
     {
         ui->tabetudiantaminee->setModel(tmpetudiant.afficher());//refresh
              ui->tabetudiant_3aminee->setModel(tmpeinscription.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier Un etudiant"),
         QObject::tr("étudiant  Modifié\n"
         "Click Cancel to exit."), QMessageBox::Cancel);

               }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Modifier Un etudiant"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_2aminee_clicked()
{
    int idd=ui->lineEdit_id_12aminee->text().toInt();
    QDate entre= ui->dateEditaminee->date();
    QDate sortie= ui->dateEdit_2aminee->date();
    inscription e(idd,entre,sortie);
    bool test=e.modifier(idd);
     if(test)
     {
         ui->tabetudiantaminee->setModel(tmpetudiant.afficher());//refresh
              ui->tabetudiant_3aminee->setModel(tmpeinscription.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier Une inscription"),
         QObject::tr("inscription   Modifiée\n"
         "Click Cancel to exit."), QMessageBox::Cancel);

               }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Modifier Une inscription"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButtontri2aminee_clicked()
{
    ui->tabetudiantaminee->setModel(tmpetudiant.affichertriclasse());
}

void MainWindow::on_pb_chercher_3aminee_clicked()
{
    int id = ui->lineEdit_id_13aminee->text().toInt();
    ui->tabetudiant_5aminee->setModel(tmpeinscription.chercher2(id));

}

void MainWindow::on_pb_chercher_4aminee_clicked()
{
    int idd=ui->lineEdit_id_14aminee->text().toInt();
    QDate entre=QDate::currentDate();
    QDate sortie=QDate::currentDate();
    inscription e(idd,entre,sortie);
    bool test=e.modifier3(idd);
     if(test)
     {
         ui->tabetudiantaminee->setModel(tmpetudiant.afficher());//refresh
              ui->tabetudiant_3aminee->setModel(tmpeinscription.afficher());
              ui->tabetudiant_6aminee->setModel(tmpeinscription.afficher2());
        QMessageBox::information(nullptr, QObject::tr("Modifier Une inscription"),
         QObject::tr("inscription   Modifiée\n"
         "Click Cancel to exit."), QMessageBox::Cancel);

               }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Modifier Une inscription"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pb_chercher_5aminee_clicked()
{
    int idd=ui->lineEdit_id_14aminee->text().toInt();
    QDate entre=QDate::currentDate();
    QDate sortie=ui->dateEdit_5aminee->date();
    inscription e(idd,entre,sortie);
    bool test=e.modifier2(idd);
     if(test)
     {
         ui->tabetudiantaminee->setModel(tmpetudiant.afficher());//refresh
              ui->tabetudiant_3aminee->setModel(tmpeinscription.afficher());
              ui->tabetudiant_6aminee->setModel(tmpeinscription.afficher2());
        QMessageBox::information(nullptr, QObject::tr("Modifier Une inscription"),
         QObject::tr("inscription   Modifiée\n"
         "Click Cancel to exit."), QMessageBox::Cancel);

               }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Modifier Une inscription"),
                                 QObject::tr("Erreur !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

}
