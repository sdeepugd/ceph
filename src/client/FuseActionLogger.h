/*
 * FuseActionLogger.h
 *
 *  Created on: 10-Sep-2018
 *      Author: deepak-3386
 *
 *      Logs the actions in a file.
 */

#ifndef SRC_CLIENT_FUSEACTIONLOGGER_H_
#define SRC_CLIENT_FUSEACTIONLOGGER_H_

#include <string>

using namespace std;

class Logger
{
private :
	string filename;
	string data;
	static Logger *logger;
	int inaction = 0;
	Logger();
	~Logger();
	Logger(string filename){
		this->filename = filename;
	}
public :
	// member func
	void logData(string filename,string data);
	void logData(string filename,uint64_t data);
	ofstream getLoggerFile();
	void returnLoggerFile(ofstream);

	// static member funcs
	static Logger* getInstance();
	static Logger* getInstance(string filename);
};

#endif /* SRC_CLIENT_FUSEACTIONLOGGER_H_ */
