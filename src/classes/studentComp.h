// studentComp.h
#ifndef STUDENTCOMP_H
#define STUDENTCOMP_H

#include <string>
#include <vector>
#include "ClassComp.h" // Inclua o cabeçalho completo da classe ClassComp

class studentComp {
public:
    studentComp(const std::string& code, const std::string& name);

    std::string getCode() const;
    std::string getName() const;
    const std::vector<ClassComp>& getClasses() const;
    void addClass(const ClassComp& classe);


private:
    std::string code;
    std::string name;
    std::vector<ClassComp> classes;
};

#endif
