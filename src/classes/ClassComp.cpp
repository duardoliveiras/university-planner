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

void ClassComp::addClassInfo(std::string type, std::string day, double startTime, double duration){

    classInfo newClassInfo;
    newClassInfo.type = type;
    newClassInfo.day = day;
    newClassInfo.startTime = startTime;
    newClassInfo.duration = duration;

    classInfoVec.push_back(newClassInfo);


}