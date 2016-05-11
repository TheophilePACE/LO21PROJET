#include "stdafx.h"
#include "mylog.h"
/*
void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s) {
	*this << TIME::Evt1jDur(d, s, h,TIME::Duree(0));
}
void MyLog::displayLog(std::ostream& f) const {
	for (Agenda::Iterator i = getIterator(); i.ok(); i.next()) {
		f << "date - horaire : description \n"; 
		f << dynamic_cast<const TIME::Evt1j&>(i.ev()).getDate();
		f << " - "; 
		f << dynamic_cast<const TIME::Evt1jDur&>(i.ev()).getDebut(); 
		f << " : " << i.ev().getDescription();
	}
}*/
void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s) {
	TIME::Agenda::Iterator i = events.getIterator();
	TIME::Agenda::Iterator j = events.getEndIterator();
	if (j!=i) {
		TIME::Date lastDate = dynamic_cast<const TIME::Evt1j&>(j.ev()).getDate();
		TIME::Horaire lastHoraire = dynamic_cast<const TIME::Evt1jDur&>(j.ev()).getDebut();
		if (d < lastDate || ((d == lastDate) && (h < lastHoraire)))
			throw LogError("Introduction d'un évènement illégal");
	}
	events << TIME::Evt1jDur(d, s, h, TIME::Duree(0));
}
void MyLog::displayLog(std::ostream& f) const {
	for (TIME::Agenda::Iterator i = events.getIterator(); i.ok(); i.next()) {
		f << "date - horaire : description \n";
		f << dynamic_cast<const TIME::Evt1j&>(i.ev()).getDate();
		f << " - ";
		f << dynamic_cast<const TIME::Evt1jDur&>(i.ev()).getDebut();
		f << " : " << i.ev().getDescription();
	}
}