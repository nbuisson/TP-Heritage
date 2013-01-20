/*************************************************************************
                           main  -  description
                             -------------------
    d�but                : 10 déc. 2012
    copyright            : (C) 2012 par nbuisson et pmdartus
*************************************************************************/

//---------- R�alisation de la classe <main> (fichier main.cpp) -------

//---------------------------------------------------------------- INCLUDE
#include "CSchema.h"

//-------------------------------------------------------- Include syst�me
using namespace std;



int main()
{
    // Intialisation de l'application
	CSchema *mySchema;
	mySchema = CSchema::getInstance();
	mySchema->Execute();
	return 0;
}

