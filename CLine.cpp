/*************************************************************************
                           CLine  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson et pmdartus
*************************************************************************/

//---------- Realisation de la classe <CLine> (fichier CLine.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CLine.h"
#include "CPolyLine.h"
#include "CFigure.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type CLine::Methode ( liste des parametres )
// Algorithme :
//
//{
//}


string CLine::GetCreator()
// Algorithme :
// Trivial
{
	string cmd;
	cmd += "L ";
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
} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs
/*CLine & CLine::operator = (const CLine & unCLine)
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
/*CLine::CLine (const CLine & unCLine)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CLine>" << endl;
#endif
} //----- Fin de CLine (constructeur de copie)*/


/*CLine::CLine()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CLine>" << endl;
#endif
} //----- Fin de CLine*/


CLine::~CLine ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CLine>" << endl;
#endif
    delete vPoint;
} //----- Fin de ~CLine


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

