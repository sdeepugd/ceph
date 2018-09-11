/*
 * FuseActionLogger.cc
 *
 *  Created on: 10-Sep-2018
 *      Author: deepak-3386
 */


#include "FuseActionLogger.h"
#include <iostream>
#include <fstream>
#include <sstream>

Logger* Logger::getInstance(){
	if(logger == 0){
		logger = new Logger();
	}
	return logger;
}

Logger::Logger(){

}

Logger* Logger::logger = 0;

void Logger::logData(string filename,string data){
	  filename = filename + ".txt";
	  ofstream myfile;
	  myfile.open (filename);
	  myfile <<data;
	  myfile.close();
}

void Logger::logData(string filename,uint64_t data){
	  string longval;
	  stringstream strstream;
	  strstream << data;
	  strstream >> longval;
	  logData(filename,longval);
}


