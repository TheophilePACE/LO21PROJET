#include "stdafx.h"
#include "evenement.h"
#include "timing.h"

using namespace TIME;
//Les virtuals ne doivent pas être en inline normalement, même si ça marche ici
std::string EvtPj::toString()const {
	std::stringstream f;
	f << "***** Evt ********" << "\n" << "DateDebut=" << dateDebut
		<< "DateFin=" << dateFin << " sujet=" << getDescription() << "\n";
	return f.str();
}
std::string Evt1j::toString()const {
	std::stringstream f;
	f << "***** Evt ********" << "\n" << "Date=" << date << " sujet=" << getDescription() << "\n";
	return f.str();
}
std::string Evt1jDur::toString()const {
	std::stringstream f;
	f << Evt1j::toString();
	f << "Debut=" << debut << " Duree=" << duree << "\n";
	return f.str();
}
std::string Rdv::toString()const {
	std::stringstream f;
	f << Evt1jDur::toString();
	f << "Lieu=" << lieu << " Personnes=" << personnes << "\n";
	return f.str();
}
void Evt::afficher(std::ostream& f) const {
	f << toString();
}
EvtPj * EvtPj::clone() const {return new EvtPj(*this);}
Evt1j * Evt1j::clone() const { return new Evt1j(*this);  }
Evt1jDur * Evt1jDur::clone() const {return new Evt1jDur(*this);}
Rdv * Rdv::clone() const {return new Rdv(*this);}


std::ostream& operator<<(std::ostream& f, const Evt& r)
{
	r.afficher(f);
	return f;
}

Agenda& Agenda::operator<<(Evt & e)
{
	if (nb == max)
		agrandirTab();
	//Evt event = new Evt
	tab[nb++] = e.clone();
	return *this;
}

void Agenda::agrandirTab()
{
	max = max * 2 + 1;
	Evt** newtab = new Evt*[max];
	for(unsigned int i = 0; i < nb; i++)
		newtab[i] = tab[i];
	Evt** old = tab;
	tab = newtab;
	delete[] old;
}

void Agenda::afficher(std::ostream& f) const {
	Iterator i;
	i = getIterator();
	f << "Affichage d'un agenda : \n\n";
	while(i.ok())
	{
		f << "Evenement " << nb - i.nbi << " : \n";
		i.ev().afficher(f);
		i.next();
	}
		
}
bool Evt1j::operator<(const Evt1j& e) const {
	return date < e.date;
}
bool Evt1jDur::operator<(const Evt1j& e) const {
	if (this->Evt1j::operator<(e)) return true;
	if (e < *this) return false;
	//Comparer les horaires
	const Evt1jDur * ex = dynamic_cast<const Evt1jDur*>(&e);
	if (ex != 0 && debut < ex->debut) return true;
	return false;
}
void Agenda::statistiques() const{
	struct info {
		std::string nom;
		int nb;
		info() : nb(0) {}
	};
	info infos[10];
	int nb_infos = 0;
	for (int i = 0; i < nb; i++) {
		std::string nom = typeid(*tab[i]).name();
		int j;
		for (j = 0; j < nb_infos; j++) {
			if (infos[j].nom == nom) {
				infos[j].nb++;
				break;
			}
		}
		if (j == nb_infos) {
			infos[j].nom = nom;
			infos[j].nb = 1;
			nb_infos++;
		}
	}
	std::cout << "NOM TYPE - NB\n";
	for (int j = 0; j < nb_infos; j++)
		std::cout << infos[j].nom << " - " << infos[j].nb << "\n";

}