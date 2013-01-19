/*************************************************************************
                           CFigure  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Interface de la classe <CFigure> (fichier CFigure.h) ------
#if ! defined ( CFIGURE_H_ )
#define CFIGURE_H_

//--------------------------------------------------- Interfaces utilisees
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <CFigure>
//
//
//------------------------------------------------------------------------

class CFigure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // type Methode ( liste des parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //


	virtual void Select(int x1, int y1, int x2, int y2) = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//


	bool GetisSelected();
	// Mode d'emploi :
	//
	// Contrat :
	//


	virtual bool Move(long dX, long dY) = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//


	void Unselect();
	// Mode d'emploi :
	//
	// Contrat :
	//


	virtual string GetCreator() = 0;
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'op�rateurs
    //CFigure & operator = ( const CFigure & unCFigure );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CFigure ( const CFigure & unCFigure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CFigure ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CFigure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs proteges
bool isSelected;

};

//--------------------------- Autres d�finitions d�pendantes de <CFigure>

#endif // CFIGURE_H_

