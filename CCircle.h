/*************************************************************************
                           CCircle  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson et pmdartus
*************************************************************************/

//---------- Interface de la classe <CCircle> (fichier CCircle.h) ------
#if ! defined ( CCIRCLE_H_ )
#define CCIRCLE_H_

//--------------------------------------------------- Interfaces utilisees

#include <string>
#include "CFigure.h"
#include "CPoint.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <CCircle>
//
//
//------------------------------------------------------------------------

class CCircle : public CFigure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // type Methode ( liste des parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //


	bool Move(long dX, long dY);
    // Mode d'emploi :
    // Déplace le cercle de (dX, dY)
    // Contrat :
    // Aucun


	void Select(int x1, int y1, int x2, int y2);
    // Mode d'emploi :
    // Séléctionne le cercle s'il est dans le rectangle défini par (x1, y1)
    // et (x2, y2)
    // Contrat :
    // Aucun


	string GetCreator();
    // Mode d'emploi :
    // Renvoie la commande de création du cercle
    // Contrat :
    // Aucun


//------------------------------------------------- Surcharge d'operateurs
    //CCircle & operator = ( const CCircle & unCCircle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CCircle ( const CCircle & unCCircle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CCircle (int aX, int aY, int aR):center(aX, aY), rayon(aR) {};
    // Mode d'emploi :
    //
    // Contrat :
    // Vérifier que les coordonnées du cercle sont toutes des integers

    virtual ~CCircle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

//----------------------------------------------------- Attributs proteges
    CPoint center;
    int rayon;

};

//--------------------------- Autres definitions dependantes de <CCircle>

#endif // CCIRCLE_H_

