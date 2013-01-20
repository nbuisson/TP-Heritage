/*************************************************************************
                           CFigure  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson et pmdartus
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
	// Séléctionne les figures comprises dans le rectangle de séléction
	// défini par les points (x1,y1) et (x2,y2)
	// Contrat :
	// Aucun

	void SetSelected();
	// Mode d'emploi
	// Place l'attribut isSelected à vrai
	// Contrat :
	// Aucun


	bool GetisSelected();
	// Mode d'emploi :
	// Renvoie l'état de isSelected (pour savoir si l'objet est séléctionné ou non)
	// Contrat :
	// Aucun


	virtual bool Move(long dX, long dY) = 0;
	// Mode d'emploi :
	// Déplace la figure de (dX, dY)
	// Contrat :
	// Aucun


	void Unselect();
	// Mode d'emploi :
	// Place l'attribut isSelected à faux
	// Contrat :
	// Aucun


	virtual string GetCreator() = 0;
	// Mode d'emploi :
	// Renvoie la commande de création de la figure
	// Contrat :
	// Aucun

//------------------------------------------------- Surcharge d'op�rateurs
    //CFigure & operator = ( const CFigure & unCFigure );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CFigure ( const CFigure & unCFigure );
    // Mode d'emploi (constructeur de copie) :
    // Créateur de copie de CFigure
    // Contrat :
    // Aucun

    CFigure ();
    // Mode d'emploi :
    // Créateur de CFigure
    // Contrat :
    // Aucun

    virtual ~CFigure ( );
    // Mode d'emploi :
    // Destructeur de CFigure
    // Contrat :
    // Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs proteges
    bool isSelected;

};

//--------------------------- Autres d�finitions d�pendantes de <CFigure>

#endif // CFIGURE_H_

