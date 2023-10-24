#ifndef CLASSCOMP_H
#define CLASSCOMP_H

#include <string>
#include <vector>
#include <iostream>

class ClassComp {
public:
    ClassComp(const std::string& classCode, const std::string& ucCode);

    std::string getClassCode() const;
    std::string getUcCode() const;
    std::string getDay() const;
    double getStartTime() const;
    double getDuration() const;
    std::string getType() const;

private:
    std::string classCode;
    std::string ucCode;

    std::string day;
    double startTime;
    double duration;
    std::string type;
};

#endif
