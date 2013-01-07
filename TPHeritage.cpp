/*************************************************************************
                           main  -  description
                             -------------------
    d�but                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson
*************************************************************************/

//---------- R�alisation de la classe <main> (fichier main.cpp) -------

//---------------------------------------------------------------- INCLUDE
#include "CSchema.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CFigure.h"

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>
#include <limits>

int main()
{
    int intLim = numeric_limits<int>::min();
    cout << intLim << endl;

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

	delete p1;*/

    /*
	// Tests de CCircle

	CCircle* c1 = new CCircle(0,0,4);
	string creator = c1->GetCreator();
	cout << creator << endl;

	bool ok = c1->Move(4,2);
	cout << "ok : " << ok << endl;
	creator = c1->GetCreator();
	cout << creator << endl;

	ok = c1->Move(-65,12);
	cout << "ok : " << ok << endl;
	creator = c1->GetCreator();
	cout << creator << endl;

    ok = c1->Move(intLim, intLim);
    cout << "ok : " << ok << endl;
    creator = c1->GetCreator();
    cout << creator << endl;

    ok = c1->Move(-intLim, 2);
    cout << "ok : " << ok << endl;
    creator = c1->GetCreator();
    cout << creator << endl;

    CFigure* c2 = new CCircle(0,0,4);
    c2->Select(0,0,5,6);
    bool select = c2->GetisSelected();
    cout << "select : " << select << endl;
    cout << endl;

    ok = c2->Move(intLim+4,intLim+4);
    cout << "c2 ok : " << ok << endl;
    cout << c2->GetCreator() << endl;

    delete c2;
    delete c1;*/


	// Tests de CRectangle

	int iX1r = 2;
	int iY1r = 3;
	int iX2r = 4;
	int iY2r = -8;

	CRectangle* r1 = new CRectangle(iX1r, iY1r, iX2r, iY2r);
	string rectangleCreator = r1->GetCreator();
	cout << rectangleCreator << endl;


    /*
	//CSchema * mySchema = new CSchema ();

	int i;
	cin>>i;*/

	return 0;
}

