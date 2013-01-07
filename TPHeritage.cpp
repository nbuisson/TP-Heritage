/*************************************************************************
                           main  -  description
                             -------------------
    d�but                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- R�alisation de la classe <main> (fichier main.cpp) -------

//---------------------------------------------------------------- INCLUDE
#include "CSchema.h"

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>

int main()
{
	/*
	// Tests de CPoint

	int iX;
	int iY;
	CPoint* p1 = new CPoint (0, 0);
	p1->GetXY(iX, iY);
	cout << "x " << iX << " y " << iY << endl;

	p1->Move(-1,-1);
	p1->GetXY(iX, iY);
	cout << "x " << iX << " y " << iY << endl;

	p1->Distance(2,2,iX,iY);
	cout << "iX " << iX << " iY " << iY << endl;

	bool ok = p1->IsSelected(-1,-3,0,4);
	cout << ok << endl;

	ok = p1->IsSelected(-1,0,2,2);
	cout << ok << endl;


	// Tests de CCircle

	CCircle * c1 = new CCircle(0,0,4);
	c1->Move(1,1);
	string creator = c1->GetCreator();
	cout << creator << endl; */

	CSchema * mySchema = new CSchema ();

	int i;
	cin>>i;
}

