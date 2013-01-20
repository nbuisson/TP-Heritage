/*************************************************************************
                           CPolyLine  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Interface de la classe <CPolyLine> (fichier CPolyLine.h) ------
#if ! defined ( CPOLYLINE_H_ )
#define CPOLYLINE_H_

//--------------------------------------------------- Interfaces utilisees

#include <string>
#include <vector>
#include "CFigure.h"
#include "CPoint.h"

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef vector<CPoint> VectPoint;

//------------------------------------------------------------------------
// Rele de la classe <CPolyLine>
//
//
//------------------------------------------------------------------------

class CPolyLine : public CFigure
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
    //CPolyLine & operator = ( const CPolyLine & unCPolyLine );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CPolyLine(const CPolyLine & unCPolyLine);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CPolyLine(VectPoint* aVPoint) : vPoint(aVPoint) {};
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CPolyLine();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

//----------------------------------------------------- Attributs proteges
    VectPoint* vPoint;

};

//--------------------------- Autres definitions dependantes de <CPolyLine>

#endif // CPOLYLINE_H_

