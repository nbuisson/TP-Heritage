/*************************************************************************
                           CHistoric  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
=======
CHistoric - description
-------------------
debut : 10 déc. 2012
copyright : (C) 2012 par nbuisson
*************************************************************************/

//---------- Interface de la classe <CHistoric> (fichier CHistoric.h) ------
#if ! defined ( CHISTORIC_H_ )
#define CHISTORIC_H_

//--------------------------------------------------- Interfaces utilisees
#include <vector>
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes
#define MAX_UNDO 20;

//------------------------------------------------------------------ Types
typedef vector <string> vectCommande;
typedef vector <vectCommande *> vectStack;

//------------------------------------------------------------------------
// Role de la classe <CHistoric>
//
//
//------------------------------------------------------------------------

class CHistoric
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Methodes publiques
    void AddHistoric (vectCommande aVectCommande);
    // Mode d'emploi :
    // Ajout d'une commande dans l'historique
    // Contrat :
    // Rien

    bool Undo ();
    // Mode d'emploi :
    // Renvoi la dernière commande executée
    // Contrat :
    // Rien

    bool Redo ();
    // Mode d'emploi :
    // Contrustion de l'instorique au début de l'exec
    // Contrat :
    // Rien


//-------------------------------------------- Constructeurs - destructeur

    CHistoric ( );
    // Mode d'emploi :
    // Contrustion de l'instorique au début de l'exec
    // Contrat :
    // Rien

    virtual ~CHistoric ( );
    // Mode d'emploi :
    // Destruction de l'historique au moment de la fin de l'execution du programme
    // sur la commande EXIT
    // Contrat :
    // Rien

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

//----------------------------------------------------- Attributs proteges
    vectStack* vStack;
    vectStack::iterator it;


};

//--------------------------- Autres d�finitions d�pendantes de <CHistoric>

#endif // CHISTORIC_H_

