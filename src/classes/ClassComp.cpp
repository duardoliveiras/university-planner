#include "ClassComp.h"


ClassComp::ClassComp(const std::string& classCode, const std::string& ucCode){
    this->classCode = classCode;
    this->ucCode = ucCode;
}

std::string ClassComp::getClassCode() const {
    return classCode;
}

std::string ClassComp::getUcCode() const {
    return ucCode;
}

std::string ClassComp::getDay() const {
    return day;
}

double ClassComp::getStartTime() const {
    return startTime;
}

double ClassComp::getDuration() const {
    return duration;
}

std::string ClassComp::getType() const {
    return type;
}

