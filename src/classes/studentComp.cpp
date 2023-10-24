#include "studentComp.h"


studentComp::studentComp(const std::string& code, const std::string& name) {
    this->code = code;
    this->name = name;
}

std::string studentComp::getCode() const {
    return code;
}

std::string studentComp::getName() const {
    return name;
}

const std::vector<ClassComp>& studentComp::getClasses() const {
    return classes;
}

void studentComp::addClass(const ClassComp& classe) {
    classes.push_back(classe);
}



