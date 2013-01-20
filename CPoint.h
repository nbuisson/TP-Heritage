/*************************************************************************
                           CPoint  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson et pmdartus
*************************************************************************/

//---------- Interface de la classe <CPoint> (fichier CPoint.h) ------
#if ! defined ( CPOINT_H_ )
#define CPOINT_H_

//--------------------------------------------------- Interfaces utilisees
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <CPoint>
//
//
//------------------------------------------------------------------------

class CPoint
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


	bool IsSelected(int x1, int y1, int x2, int y2);
    // Mode d'emploi :
    //
    // Contrat :
    //


	void Distance(int aX, int aY, long& dX, long& dY);
    // Mode d'emploi :
    //
    // Contrat :
    //


	void GetXY(int& aX, int& aY);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'operateurs
    //CPoint & operator = ( const CPoint & unCPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CPoint (const CPoint & unCPoint);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CPoint (int aX, int aY):x(aX), y(aY){};
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CPoint ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

//----------------------------------------------------- Attributs proteges

    int x;
    int y;

};

//--------------------------- Autres definitions dependantes de <CPoint>

#endif // CPOINT_H_

