/*
 * FuseActionLogger.cc
 *
 *  Created on: 10-Sep-2018
 *      Author: deepak-3386
 */


#include <FuseActionLogger.h>
#include <iostream>
#include <fstream>

void Logger::logData(string filename,string data){
	  filename = filename + ".txt";
	  ofstream myfile;
	  myfile.open (filename);
	  myfile <<data;
	  myfile.close();
}
