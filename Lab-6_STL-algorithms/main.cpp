/*
Lab 6 - STL Containers and Algorithms
Wolfgang C. Strack
Windows 8 Visual C++ 2013

This file includes the main application for this lab.
*/

#include "SpecializedPatientParser.h"
#include "PatientDatabase.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

typedef SpecializedPatientParser SPP;

bool populateDatabase(PatientDatabase *pDB, SPP &spp, const vector<string> &tags);
void testDatabase(PatientDatabase &pDB);

int main()
{
	clock_t begin = clock();
	// Variable declarations ---------------------------------------------
	const std::string dataFile = "Patient.xml";
	const std::string barcodeFile = "Barcodes.txt";
	PatientDatabase *pDB = PatientDatabase::getInstance();
	SPP spp;

	// Start program (and timer) -----------------------------------------
	cout << "Now parsing Patients from file...\n\n\n";
	if (!spp.specializedParse(dataFile, *pDB))
	{
		cout << "Error: something went wrong while parsing the XML file!\n";
		return 1;
	}

	/*cout << "Now populating Patient database...\n\n\n";
	if (!populateDatabase(pDB, spp, tags))
	{
		cout << "Error: something went wrong while populating the Patient DB!\n";
		return 2;
	}*/

	cout << "Now testing Patient database...\n\n\n";
	testDatabase(*pDB);

	// End program (and timer) and display statistics --------------------


	PatientDatabase::resetInstance();
	clock_t end = clock();
	cout << "\nElapsed time:\t" << double(end - begin) / CLOCKS_PER_SEC << endl;
	return 0;
}

//bool populateDatabase(PatientDatabase *pDB, SPP &spp, const vector<string> &tags)
//{
//	for (int i = 0; i < tags.size(); i++)
//	{
//		Patient patient;
//		patient.setXMLTags(tags[i]);
//
//		if (!spp.getXmlDataFromString(tags[i], patient))
//			return false;
//
//		if (!pDB->addPatient(patient))
//			return false;
//	}
//
//	return true;
//}

void testDatabase(PatientDatabase &pDB)
{
	PatientList *plist = pDB.getPatientList();

	cout << "THIS IS THE FIRST PATIENT: \n\n" << *plist->front() << endl;
}