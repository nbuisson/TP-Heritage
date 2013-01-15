/*************************************************************************
                           CCircle  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
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
    //
    // Contrat :
    //


	void Select(int x1, int y1, int x2, int y2);
    // Mode d'emploi :
    //
    // Contrat :
    //


	string GetCreator();
    // Mode d'emploi :
    //
    // Contrat :
    //


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

