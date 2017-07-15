//*****************************************************************************
//                      CODE ECRIT PAR Hugo Paigneau                          *
//                                                                            *
//                 Garder ce header si vous utilisez le code                  *
//                                                                            *
//                                UTC 2017                                    *
//*****************************************************************************

#include "fonction.h"
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QFont>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QColor>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFormLayout>
#include <QGroupBox>
#include <QSize>



FenetreFichier::FenetreFichier()
{
  setFixedSize(350,450);
  setWindowTitle("Générateur de Fichier v1.2");

  //Mise en place du background
  QPalette pal = palette();
  pal.setColor(QPalette::Background,QColor(50,40,130));
  setAutoFillBackground(true);
  setPalette(pal);

  //Création choix de l'extension.
  extensionLabel = new QLabel("Choix du type de fichier", this);
  extensionLabel->setAlignment(Qt::AlignCenter);
  QFont font = extensionLabel->font();
  font.setPointSize(20);
  font.setBold(true);
  extensionLabel->setFont(font);
  extensionFichier = new QComboBox(this);
  extensionFichier->addItem(".html");
  extensionFichier->addItem(".css");
  extensionFichier->addItem(".cpp");
  extensionFichier->addItem(".js");
  extensionFichier->addItem(".php");
  extensionFichier->addItem(".h");
  extensionFichier->setFixedWidth(200);
  extensionFichier->setFixedHeight(50);
  nomFichier = new QLineEdit;
  repertoire = new QLineEdit("/home/");
  QFormLayout *nomF = new QFormLayout;
  nomF->addRow("Nom du fichier : ", nomFichier);
  nomF->addRow("Chemin du fichier : ", repertoire);
  QGroupBox *layoutnom = new QGroupBox;
  layoutnom->setLayout(nomF);
  extchoix = new QVBoxLayout;
  extchoix->addWidget(extensionLabel,0,Qt::AlignCenter);
  extchoix->addWidget(extensionFichier,0,Qt::AlignCenter);
  extchoix->addWidget(layoutnom,0,Qt::AlignTop);

  //Création des boutons générer et quitter
  generer = new QPushButton("Générer");
  quitter = new QPushButton("Quitter");
  boutons = new QHBoxLayout;
  boutons->addWidget(generer);
  boutons->addWidget(quitter);

  //Organisation layouts
  QVBoxLayout *LayPrincipal = new QVBoxLayout;
  LayPrincipal->addLayout(extchoix);
  LayPrincipal->addLayout(boutons);
  setLayout(LayPrincipal);

  //Connection des bouttons
  connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
  connect(generer, SIGNAL(clicked()), this, SLOT(genererFichier()));

}

  //Création de la fonction qui permet de générer un FenetreFichier
void FenetreFichier::genererFichier()
{
  if (extensionFichier->currentText() == ".html")
  {
    //Création du fichier
    QFile fichier(repertoire->text() + nomFichier->text() + ".html");
    if(fichier.open(QIODevice::WriteOnly))
    {
        QTextStream flux(&fichier);
        flux.setCodec("UTF-8");
        flux << "<!doctype html>" << endl << "<html lang=\"fr\">" << endl;
        flux << "<head>" << endl << "<meta charset=\"utf-8\">" << endl;
        flux << "<title>Titre de la page</title>" << endl << "<link rel=\"stylesheet\" href=\"style.css\">" << endl;
        flux << "<script src=\"script.js\"></script>" << endl << "</head>" << endl;
        flux << "<body>" << endl << endl << endl << "</body>" << endl << "</html>" << endl;
        fichier.flush();
        fichier.close();
    }
    QMessageBox::information(this, "Fichier généré avec succès", "Un fichier html a été crée sur le bureau");
    return;
   }
   else if (extensionFichier->currentText() == ".css")
  {
    QFile fichier(repertoire->text() + nomFichier->text() + ".css");
    if(fichier.open(QIODevice::WriteOnly))
    {
        QTextStream flux(&fichier);
        flux.setCodec("UTF-8");
        flux << "sélécteur {" << endl << "propriété : valeur;" << endl << "}";
        fichier.flush();
        fichier.close();
    }
    QMessageBox::information(this, "Fichier généré avec succès", "Un fichier css a été crée sur le bureau");
    return;
  }
  else if (extensionFichier->currentText() == ".js")
  {
    QFile fichier(repertoire->text() + nomFichier->text() + ".js");
    if(fichier.open(QIODevice::WriteOnly))
    {
        QTextStream flux(&fichier);
        flux.setCodec("UTF-8");
        flux << "js";
        fichier.flush();
        fichier.close();
    }
    QMessageBox::information(this, "Fichier généré avec succès", "Un fichier javascript a été crée sur le bureau");
    return;

  }
  else if (extensionFichier->currentText() == ".php")
  {
    QFile fichier(repertoire->text() + nomFichier->text() + ".php");
    if(fichier.open(QIODevice::WriteOnly))
    {
        QTextStream flux(&fichier);
        flux.setCodec("UTF-8");
        flux << "<?php" << endl << "echo'texte'; " << endl << "?>";
        fichier.flush();
        fichier.close();
    }
    QMessageBox::information(this, "Fichier généré avec succès", "Un fichier php a été crée sur le bureau");
    return;

  }
  else if (extensionFichier->currentText() == ".cpp")
  {
    QFile fichier(repertoire->text() + nomFichier->text() + ".cpp");
    if(fichier.open(QIODevice::WriteOnly))
    {
        QTextStream flux(&fichier);
        flux.setCodec("UTF-8");
        flux << "#include <iostream>" << endl << endl << "using namespace std;" << endl << endl;
        flux << "int main()" << endl << "{" << endl << endl << endl << endl << "}";
        fichier.flush();
        fichier.close();
    }
    QMessageBox::information(this, "Fichier généré avec succès", "Un fichier source C++ a été crée sur le bureau");
    return;

  }
  else if (extensionFichier->currentText() == ".h")
  {
    QFile fichier(repertoire->text() + nomFichier->text() + ".h");
    if(fichier.open(QIODevice::WriteOnly))
    {
        QTextStream flux(&fichier);
        flux.setCodec("UTF-8");
        flux << "#ifndef FICHIER_H_INCLUDED" << endl << "#define FICHIER_H_INCLUDED" << endl;
        flux << "#include <iostream>" << endl << endl << "using namespace std;" << endl << endl << endl << endl;
        flux << "endif";
        fichier.flush();
        fichier.close();
    }
    QMessageBox::information(this, "Fichier généré avec succès", "Un fichier header C++ a été crée sur le bureau");
    return;

  }


}
