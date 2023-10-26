#ifndef CLASSCOMP_H
#define CLASSCOMP_H

#include <string>
#include <vector>
#include <iostream>


struct classInfo
{
    std::string type;  
    std::string day;
    double startTime;
    double duration;
    
};


class ClassComp {
public:
    ClassComp(const std::string& ucCode, std::string& classCode);

    std::string getClassCode() const;
    std::string getUcCode() const;

    void addClassInfo(std::string type, std::string day, double startTime, double duration);

    bool operator<(const ClassComp& other) const;

private:
    std::string classCode;
    std::string ucCode;
    std::vector<classInfo> classInfoVec;

};

#endif
