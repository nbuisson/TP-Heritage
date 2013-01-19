/*************************************************************************
                           CFigure  -  description
                             -------------------
    debut                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- Realisation de la classe <CFigure> (fichier CFigure.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme

#include <iostream>

//------------------------------------------------------ Include personnel
//#include "stdafx.h"
#include "CFigure.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
// type CFigure::Methode ( liste des parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode

bool CFigure::GetisSelected()
// Algorithme :
// Trivial
{
	return isSelected;
} //----- Fin de Methode


void CFigure::Unselect()
// Algorithme :
// Trivial
{
	isSelected = false;
} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs
/*CFigure & CFigure::operator = ( const CFigure & unCFigure )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur

CFigure::CFigure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CFigure>" << endl;
#endif
} //----- Fin de CFigure


CFigure::~CFigure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CFigure>" << endl;
#endif
} //----- Fin de ~CFigure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

