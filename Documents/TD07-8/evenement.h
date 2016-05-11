#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "timing.h"
namespace TIME {
	class Evt {
		std::string sujet;
	public:
		Evt(const std::string& s) :sujet(s) { std::cout << "Contruction d'un objet de la classe Evt\n"; }
		void afficher(std::ostream& f = std::cout) const;
		virtual const std::string& getDescription() const { return sujet; }
		virtual std::string toString()const = 0;
		virtual Evt* clone() const = 0;
	};
	class EvtPj : public Evt {
		Date dateDebut;
		Date dateFin;
	public:
		EvtPj(const Date& deb, const Date& fin, const std::string& s)
			: Evt(s), dateDebut(deb),dateFin(fin) {
			std::cout << "Contruction d'un objet de la classe EvtPj\n";
		}
		virtual ~EvtPj() { std::cout << "destruction d'un objet de la classe EvtPj\n"; }
		std::string toString()const;
		const Date& getDateDebut() const { return dateDebut; }
		const Date& getDateFin() const { return dateFin; }
		EvtPj * clone() const; //Factory
	};
	class Evt1j : public Evt {
	private:
		Date date;
	public:
		Evt1j(const Date& d, const std::string& s) 
			: Evt(s), date(d) {
			std::cout << "Contruction d'un objet de la classe Evt1j\n";
		}
		virtual ~Evt1j() { std::cout << "destruction d'un objet de la classe Evt1j\n"; }
		const Date& getDate() const { return date; }
		std::string toString()const;
		virtual bool operator<(const Evt1j& e) const;
		Evt1j * clone() const; //Factory
	};
	
	class Evt1jDur : public Evt1j {
		Horaire debut;
		Duree duree;
	public:
		Evt1jDur(const Date& d, const std::string& s, const Horaire& deb, const Duree& dur)
			:Evt1j(d, s), debut(deb), duree(dur) {
			std::cout << "Contruction d'un objet de la classe Evt1jDur\n";
		}
		virtual ~Evt1jDur() { std::cout << "destruction d'un objet de la classe Evt1jDur\n"; }
		const Horaire& getDebut() const { return debut; }
		const Duree& getDureee() const { return duree; }
		std::string toString()const;
		virtual bool operator<(const Evt1j& e) const;
		Evt1jDur * clone() const; //Factory
	};

	class Rdv : public Evt1jDur {
		std::string lieu;
		std::string personnes;
	public:
		Rdv(const Date& d, const std::string& s, const Horaire& deb, const Duree& dur, const std::string& p, const std::string& l)
			:Evt1jDur(d, s, deb, dur), lieu(l), personnes(p) {
			std::cout << "Contruction d'un objet de la classe Rdv\n";
		}
		~Rdv() { std::cout << "destruction d'un objet de la classe Rdv\n"; }
		const std::string& getLieu() const { return lieu; }
		const std::string& getPersonnes() const { return personnes; }
		//Exo 28 il aurait fallu redef la recopie mais osef
		std::string toString()const;
		Rdv * clone() const; //Factory
	};

	class Agenda {
		Evt** tab;
		unsigned int max;
		unsigned int nb;
		void operator=(const Evt& e){}
		Agenda(const Evt& e);
		//static Evt * make_event(std::string choice);
	public:
		Agenda(): tab(nullptr), max(0), nb(0) {}
		~Agenda() {
			/*for (unsigned int i = 0; i < nb; i++)
				delete tab[i];*/
			delete[] tab;
		}
		Agenda& Agenda::operator<<(Evt& e);
		void agrandirTab();
		void afficher(std::ostream& f = std::cout)const;
		class Iterator {
			Evt** current;
			unsigned int nbi;
			Iterator(Evt** c,unsigned int n):current(c), nbi(n){}
			friend class Agenda;
		public:
			bool ok() const { return nbi > 0; }
			void next() { if (ok()) { nbi--; current++; } else throw "Valeur d'un itérateur illégal";}
			void previous() { nbi++; current--; }
			const Evt& ev() { if (ok()) return **current; else throw "Valeur d'un itérateur illégal"; }
			bool operator !=(Iterator i) { return current != i.current; }
			Iterator():current(nullptr),nbi(0){}
		};
		Iterator getIterator() const { return Iterator(tab, nb); }
		Iterator getEndIterator() const { return Iterator(tab + nb, 0); }
		void statistiques() const;
	};
}
	std::ostream& operator<<(std::ostream& f, const TIME::Evt& r);
