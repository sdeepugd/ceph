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

Logger* Logger::getInstance() {
	if (logger == 0) {
		logger = new Logger();
	}
	return logger;
}

Logger* Logger::getInstance(string filename) {
	if (logger == 0) {
	} else {
		delete logger;
	}
	logger = new Logger(filename);
	return logger;
}

Logger::Logger() {

}

Logger* Logger::logger = 0;

void Logger::logData(string filename, string data) {
	filename = filename + ".txt";
	ofstream myfile;
	myfile.open(filename);
	myfile << data;
	myfile.close();
}

void Logger::logData(string filename, uint64_t data) {
	string longval;
	stringstream strstream;
	strstream << data;
	strstream >> longval;
	logData(filename, longval);
}

ofstream Logger::getLoggerFile() {
	if (!this->filename.empty()) {
		ofstream loggerfile;
		loggerfile.open(filename);
		return loggerfile;
	} else {
		throw "logger file in use. Please try return the logger and then use.";
	}
}

void Logger::returnLoggerFile(ofstream loggerfile) {
	loggerfile.close();
}

