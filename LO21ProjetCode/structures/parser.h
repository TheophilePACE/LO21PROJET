#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QStringList>
#include <string>

/*! \brief      Le parser est un singleton qui interprète des chaines de caractères.
* Le parser est appelé par le GeneralManager ou le Controller via Controller::command.
* Cette fonction est capable de retourner le type et, si c'est possible, la valeur d'une littéral.
*/
class Parser {
    struct Singleton{
        Parser* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    static Parser& getInstance();
    static void freeInstance();
    ///Retourne le type de s sous forme de string. Utilise les fonctions booléeennes is... définies dans Parser.h
    std::string getType(QString s);
    bool isOperator(QString s);
    bool isOperatorBinary(QString s);
    bool isOperatorUnary(QString s);
    bool isOperatorStack(QString s);

    /*! \brief       A l'aide d'un split sur s, ces fnction retourne une partie de la chaine correspodante à la valeur de l'objet à créer.
   */
    ///@{
    long getNum(QString s);
    long getDenum(QString s);
    long getInteger(QString s); //renvoie tout ce qu'il y a avant le .

    double getMantisse(QString s);
    float getFloat(QString s); //non implémentée
    QString getRealPart(QString s); //renvoie la premiereparti du ima
    QString getImPart(QString s);
    ///@}

};

bool isRationnal(const QString s);
bool isReal(const QString s);
bool isInteger(const QString s);
bool isNumber(const QString s);
bool isComplex(const QString s);
bool isAtom(const QString s);
bool isExpression(const QString s);
bool isProgram(const QString s);

#endif // PARSER_H
