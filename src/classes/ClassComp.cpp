#include "ClassComp.h"


ClassComp::ClassComp(const std::string& ucCode, const std::string& classCode){
    this->classCode = classCode;
    this->ucCode = ucCode;
}

bool ClassComp::operator<(const ClassComp& other) const {
    return classCode < other.classCode;
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

void ClassComp::setDay(std::string day) {
    this->day = day;
}

void ClassComp::setStartTime(double startTime) {
    this->startTime = startTime;
}

void ClassComp::setDuration(double duration) {
    this->duration = duration;
}

void ClassComp::setType(std::string type) {
    this->type = type;
}