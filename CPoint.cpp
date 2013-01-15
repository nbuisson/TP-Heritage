/*************************************************************************
                           CPoint  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Realisation de la classe <CPoint> (fichier CPoint.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme

#include <iostream>
#include <limits>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CPoint.h"
using namespace std;

//------------------------------------------------------------- Constantes
const int maxInt = numeric_limits<int>::max();
const int minInt = numeric_limits<int>::min();


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type CPoint::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


bool CPoint::Move(long dX, long dY)
// Algorithme :
// Trivial
{

    // On caste les x et y dans des long avant l'opération pour
    // éviter l'overflow qui fait passer le résultat en négatif
    long xdX = (long)x+dX;
    long ydY = (long)y+dY;

    // TODO : enlever la trace
    cout << "Point.Move" << endl;
    cout << "dX : " << dX << " ; dY : " << dY << "\n" << endl;
    //

	if ((xdX > maxInt) || (xdX < minInt) || (ydY > maxInt) || (ydY < minInt))
	{
		return false;
	}
	else
	{
		x += dX;
		y += dY;

		return true;
	}
} //----- Fin de Methode


bool CPoint::IsSelected(int x1, int y1, int x2, int y2)
// Algorithme :
// Trivial
{
	int xmin = min(x1,x2);
	int xmax = max(x1,x2);
	int ymin = min(y1,y2);
	int ymax = max(y1,y2);

	if (xmin<=x && xmax>=x && ymin<=y && ymax>=y)
	{
		return true;
	}
	else
	{
		return false;
	}
} //----- Fin de Methode



void CPoint::Distance(int aX, int aY, long& dX, long& dY)
// Algorithme :
// Trivial
{
    // Cast des int en long pour éviter le dépassement de capacité
    // (si aX et aY sont de tailles limites)
	dX = (long)aX+(long)x;
	dY = (long)aY+(long)y;
}


void CPoint::GetXY(int& aX, int& aY)
// Algorithme :
// Trivial
{
	aX = x;
	aY = y;
}

//------------------------------------------------- Surcharge d'operateurs
/*CPoint & CPoint::operator = ( const CPoint & unCPoint )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
CPoint::CPoint ( const CPoint & unCPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CPoint>" << endl;
#endif
    x = unCPoint.x;
    y = unCPoint.y;
} //----- Fin de CPoint (constructeur de copie)


/*CPoint::CPoint ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CPoint>" << endl;
#endif
} //----- Fin de CPoint*/


CPoint::~CPoint ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CPoint>" << endl;
#endif
} //----- Fin de ~CPoint


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

