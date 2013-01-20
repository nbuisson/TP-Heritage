/*************************************************************************
                           CPolyLine  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson et pmdartus
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

typedef vector<CPoint*> VectPoint;

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
    // Déplace la PolyLine de (dX, dY)
    // Contrat :
    // Aucun


	void Select(int x1, int y1, int x2, int y2);
    // Mode d'emploi :
    // Séléctionne la PolyLine si elle est dans le rectangle
    // défini par (x1, y1) et (x2, y2)
    // Contrat :
    // Aucun


	string GetCreator();
    // Mode d'emploi :
    // Renvoie la commande de création de la PolyLine
    // Contrat :
    // Aucun


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

