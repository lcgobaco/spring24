#include "taskException.h"

TaskException::TaskException(const std::string& taskName, const std::string& message) :
    taskName_(taskName), message_(message) {}

const char* TaskException::what() const noexcept {
    return message_.c_str();
}

const std::string& TaskException::getTaskName() const {
    return taskName_;
}
