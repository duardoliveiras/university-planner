#ifndef CLASSCOMP_H
#define CLASSCOMP_H

#include <string>
#include <vector>
#include <iostream>


struct classInfo
{
    std::string code;
    std::string type;  
    std::string day;
    int dayInt;
    double startTime;
    double duration;

    bool operator<(const classInfo& other) const {
        return startTime < other.startTime;
    }  
};

struct classQtd
{
    std::string classCode;
    int qtd;

    bool operator<(const classQtd& other) const {
        return classCode < other.classCode;
    }  
};

class ClassComp {
public:
    ClassComp(const std::string& ucCode, std::string& classCode);

    std::string getClassCode() const;
    std::string getUcCode() const;

    std::vector<classInfo> getClassInfoVec() const;

    void addClassInfo(std::string type, std::string day, int dayInt, double startTime, double duration);
    void setClassCode(std::string classCode);

    bool operator<(const ClassComp& other) const;
    static bool compareUcCode(const ClassComp& a, const ClassComp& b);

private:
    std::string classCode;
    std::string ucCode;
    std::vector<classInfo> classInfoVec;

};

#endif
