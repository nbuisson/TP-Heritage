/*************************************************************************
                           CRectangle  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Interface de la classe <CRectangle> (fichier CRectangle.h) ------
#if ! defined ( CRECTANGLE_H_ )
#define CRECTANGLE_H_

//--------------------------------------------------- Interfaces utilisees
#include "CFigure.h"
#include "CPoint.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <CRectangle>
//
//
//------------------------------------------------------------------------

class CRectangle : public CFigure
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
    //CRectangle & operator = ( const CRectangle & unCRectangle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CRectangle (const CRectangle & unCRectangle);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CRectangle (int& aX1, int& aY1, int& aX2, int& aY2) : p1(aX1, aY1), p2(aX2,aY2) {};
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CRectangle ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

//----------------------------------------------------- Attributs proteges
    CPoint p1;
    CPoint p2;

};

//--------------------------- Autres definitions dependantes de <CRectangle>

#endif // CRECTANGLE_H_

