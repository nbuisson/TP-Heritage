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
    //cout << intLim << endl;

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

	long liX;
	long liY;

	p1->Distance(2,2,liX,liY);
	cout << "liX " << liX << " liY " << liY << endl;

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

	bool ok2 = c1->Move(4,2);
	cout << "ok2 : " << ok2 << endl;
	creator = c1->GetCreator();
	cout << creator << endl;

	ok2 = c1->Move(-65,12);
	cout << "ok2 : " << ok2 << endl;
	creator = c1->GetCreator();
	cout << creator << endl;

    ok2 = c1->Move(intLim, intLim);
    cout << "ok2 : " << ok2 << endl;
    creator = c1->GetCreator();
    cout << creator << endl;

    ok2 = c1->Move(-intLim, 2);
    cout << "ok2 : " << ok2 << endl;
    creator = c1->GetCreator();
    cout << creator << endl;

    CFigure* c2 = new CCircle(0,0,4);
    c2->Select(0,0,5,6);
    bool select = c2->GetisSelected();
    cout << "select : " << select << endl;
    cout << endl;

    ok2 = c2->Move(intLim+4,intLim+4);
    cout << "c2 ok2 : " << ok2 << endl;
    cout << c2->GetCreator() << endl;

    delete c2;
    delete c1;


	// Tests de CRectangle

	int iX1r = 2;
	int iY1r = 3;
	int iX2r = 4;
	int iY2r = -7;

	CFigure* r1 = new CRectangle(iX1r, iY1r, iX2r, iY2r);
	string rectangleCreator = r1->GetCreator();
	cout << rectangleCreator << "\n" << endl;

    r1->Select(4,-8,2,3);
    bool selectR = r1->GetisSelected();
    //cout << "selectR : " << selectR << endl;

    bool moveR = r1->Move(1,1);
    //cout << "moveR : " << moveR << endl;
    cout << r1->GetCreator() << "\n" << endl;

    r1->Select(2,3,4,-8);
    selectR = r1->GetisSelected();
    cout << "selectR : " << selectR << endl;

    moveR = r1->Move(intLim,intLim);
    cout << "moveR : " << moveR << endl;
    cout << r1->GetCreator() << "\n" << endl; */



	CSchema * mySchema = new CSchema ();

	int i;
	cin>>i;

	return 0;
}

