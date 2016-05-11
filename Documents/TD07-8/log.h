#pragma once
#include "timing.h"
#include "evenement.h"
#include<iostream>
class Log {
public:
	virtual void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string
		& s) = 0;
	virtual void displayLog(std::ostream& f) const = 0;
};
class LogError : public std::exception {
	std::string info;
public:
	LogError(const std::string& str) :info(str) {}
	std::string getInfo() const { return info; }
};