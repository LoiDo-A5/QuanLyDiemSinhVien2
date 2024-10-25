#include "CreditClass.h"

CreditClass::CreditClass(const std::string& id, const std::string& name, int credits)
    : classID(id), className(name), credits(credits) {}

std::string CreditClass::getClassID() const {
    return classID;
}

std::string CreditClass::getClassName() const {
    return className;
}

int CreditClass::getCredits() const {
    return credits;
}
