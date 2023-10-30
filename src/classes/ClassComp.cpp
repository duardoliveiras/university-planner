#include "ClassComp.h"


ClassComp::ClassComp(const std::string& ucCode,  std::string& classCode){
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

std::vector<classInfo> ClassComp::getClassInfoVec() const {
    return classInfoVec;
}

void ClassComp::setClassCode(std::string classCode){
    this->classCode = classCode;
}

void ClassComp::addClassInfo(std::string type, std::string day, int dayInt, double startTime, double duration){
    classInfo newClassInfo;
    newClassInfo.type = type;
    newClassInfo.day = day;
    newClassInfo.dayInt = dayInt;
    newClassInfo.startTime = startTime;
    newClassInfo.duration = duration;

    classInfoVec.push_back(newClassInfo);
}

bool ClassComp::compareUcCode(const ClassComp& a, const ClassComp& b){
    return a.ucCode < b.ucCode;
}
