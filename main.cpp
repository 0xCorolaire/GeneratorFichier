//*****************************************************************************
//                      CODE ECRIT PAR Hugo Paigneau                          *
//                                                                            *
//                 Garder ce header si vous utilisez le code                  *
//                                                                            *
//                                UTC 2017                                    *
//*****************************************************************************

#include <QApplication>
#include "fonction.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Application du style

    //Création de la fenêtre
    FenetreFichier fenetre;
    fenetre.show();

    return app.exec();
}
