#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "etudiant.h"
#include <QMainWindow>
#include "inscription.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouteraminee_clicked();
    void on_pb_chercheraminee_clicked();
    void on_pb_supprimeraminee_clicked();
    void on_pb_idaminee_clicked();
    void on_pb_classeaminee_clicked();
    void on_pb_inscriaminee_clicked();

    void on_pb_ajouter_2aminee_clicked();
    
    void on_pb_chercher_2aminee_clicked();
    
    void on_pb_supprimer_2aminee_clicked();
    
    void on_pb_id_2aminee_clicked();
    
    void on_pb_inscri_2aminee_clicked();
    
    void on_pb_modifier_2aminee_clicked();

    void on_pb_modifier_1aminee_clicked();

    void on_pushButtontri2aminee_clicked();

    void on_pb_chercher_3aminee_clicked();

    void on_pb_chercher_4aminee_clicked();

    void on_pb_chercher_5aminee_clicked();



private:
    Ui::MainWindow *ui;
    Etudiant tmpetudiant;
    inscription tmpeinscription;

};

#endif // MAINWINDOW_H
