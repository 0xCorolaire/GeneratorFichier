//*****************************************************************************
//                      CODE ECRIT PAR Hugo Paigneau                          *
//                                                                            *
//                 Garder ce header si vous utilisez le code                  *
//                                                                            *
//                                UTC 2017                                    *
//*****************************************************************************

#ifndef FONCTION_H
#define FONCTION_H
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QCommonStyle>


class FenetreFichier : public QWidget
{
  Q_OBJECT

  public :
      FenetreFichier();

  private slots:
      void genererFichier();

  private :
      QComboBox *extensionFichier;
      QLabel *extensionLabel;
      QLineEdit *nomFichier;
      QLineEdit *repertoire;
      QVBoxLayout *extchoix;
      QHBoxLayout *boutons;
      QPushButton *generer;
      QPushButton *quitter;

};


#endif
