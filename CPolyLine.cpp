/*************************************************************************
                           CPolyLine  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Realisation de la classe <CPolyLine> (fichier CPolyLine.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CPolyLine.h"
#include "CFigure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type CPolyLine::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


bool CPolyLine::Move(long dX, long dY)
// Algorithme :
// Trivial
{
	VectPoint::iterator itPoint = vPoint->begin();

	for( ; (itPoint != vPoint->end()) && ((*itPoint)->Move(dX, dY)) ; itPoint++)
	{
	}
	if(itPoint == vPoint->end())
	{
		return true;
	}
	else
	{
		return false;
	}
} //----- Fin de Methode


void CPolyLine::Select(int x1, int y1, int x2, int y2)
// Algorithme :
//
{
	VectPoint::iterator itPoint = vPoint->begin();
	for( ; (itPoint != vPoint->end()) && ((*itPoint)->IsSelected(x1, y1, x2, y2)) ; itPoint++)
	{
	}
	if(itPoint == vPoint->end())
	{
		isSelected = true;
	}
	else
	{
		isSelected = false;
	}
} //----- Fin de Methode


string CPolyLine::GetCreator()
// Algorithme :
//
{
	string cmd;

	cmd += "PL ";

	stringstream intToStr;
	int xN;
	int yN;
	VectPoint::iterator itPoint = vPoint->begin();
	for( ; itPoint != vPoint->end() ; itPoint++)
	{
	    intToStr.str("");
		(*itPoint)->GetXY(xN, yN);
        intToStr << xN << " " << yN << " ";
        cmd += intToStr.str();
	}
	cmd.replace(cmd.length()-1, 1, "");

	return cmd;
}


//------------------------------------------------- Surcharge d'operateurs
/*CPolyLine & CPolyLine::operator = ( const CPolyLine & unCPolyLine )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
CPolyLine::CPolyLine(const CPolyLine & unCPolyLine) // TODO : faire le constructeur de copie de CPolyLine
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CPolyLine>" << endl;
#endif
} //----- Fin de CPolyLine (constructeur de copie)



CPolyLine::~CPolyLine ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CPolyLine>" << endl;
#endif
    delete vPoint;
} //----- Fin de ~CPolyLine


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

