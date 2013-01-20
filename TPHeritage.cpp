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



int main()
{
	CSchema *mySchema;
	mySchema = CSchema::getInstance();
	mySchema->Execute();
	return 0;
}

