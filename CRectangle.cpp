/*************************************************************************
                           CRectangle  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Realisation de la classe <CRectangle> (fichier CRectangle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme

#include <iostream>
#include <string>
#include <sstream>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CRectangle.h"
#include "CFigure.h"
#include "CPoint.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type CRectangle::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


bool CRectangle::Move(int dX, int dY)
// Algorithme :
// Trivial
{
	bool ok1 = p1.Move(dX, dY);
	bool ok2 = p2.Move(dX, dY);
	bool cancelMove;

    // Annulation du déplacement d'un point si un seul bouge
	if ((not ok1) && (ok2))
	{
	    cancelMove = p2.Move(-dX, -dY);
	}
	else if ((not ok2) && (ok1))
	{
	    cancelMove = p1.Move(-dX, -dY);
	}

	return ok1 && ok2;
} //----- Fin de Methode



void CRectangle::Select(int x1, int y1, int x2, int y2)
// Algorithme :
// Trivial
{
	bool ok1 = p1.IsSelected(x1, y1, x2, y2);
	bool ok2 = p2.IsSelected(x1, y1, x2, y2);
	isSelected = ok1 && ok2;
} //----- Fin de Methode


string CRectangle::GetCreator()
// Algorithme :
//
{
	string cmd;

	int x1;
	int y1;
	int x2;
	int y2;

	stringstream intToStr;

	p1.GetXY(x1, y1);
	p2.GetXY(x2, y2);

	cmd += "R ";
	intToStr << x1 << " " << y1 << " " << x2 << " " << y2;
	cmd += intToStr.str();

	return cmd;
} //----- Fin de Methode

//------------------------------------------------- Surcharge d'operateurs
/*CRectangle & CRectangle::operator = ( const CRectangle & unCRectangle )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
CRectangle::CRectangle(const CRectangle & unCRectangle) : p1(unCRectangle.p1), p2(unCRectangle.p2)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CRectangle>" << endl;
#endif
} //----- Fin de CRectangle (constructeur de copie)


/*CRectangle::CRectangle()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CRectangle>" << endl;
#endif
} //----- Fin de CRectangle*/


CRectangle::~CRectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CRectangle>" << endl;
#endif
} //----- Fin de ~CRectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

