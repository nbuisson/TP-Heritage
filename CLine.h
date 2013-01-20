/*************************************************************************
                           CLine  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Interface de la classe <CLine> (fichier CLine.h) ------
#if ! defined ( CLINE_H_ )
#define CLINE_H_

//--------------------------------------------------- Interfaces utilisees

#include <string>
#include <vector>
#include "CFigure.h"
#include "CPolyLine.h"
#include "CPoint.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <CLine>
//
//
//------------------------------------------------------------------------

class CLine : public CPolyLine
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // type Methode ( liste des parametres );
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
    //CLine & operator = (const CLine & unCLine);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CLine (const CLine & unCLine);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CLine(VectPoint* aVPoint) : CPolyLine(aVPoint) {};
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CLine ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

//----------------------------------------------------- Attributs proteges

};

//--------------------------- Autres definitions dependantes de <CLine>

#endif // CLINE_H_

