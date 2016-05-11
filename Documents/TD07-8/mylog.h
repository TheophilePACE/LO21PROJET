#pragma once

#include"timing.h"
#include"evenement.h"
#include"log.h"

class MyLog : public Log {
	TIME::Agenda events;
public:
	void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s);
	virtual void displayLog(std::ostream& f) const;
};
/*
class MyLog : public Log, private TIME::Agenda { //Adaptateur de classe
public:
	void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string
		& s);
	void displayLog(std::ostream& f) const;
};*/