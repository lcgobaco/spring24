#ifndef TASKEXCEPTION_H
#define TASKEXCEPTION_H

#include <stdexcept>
#include <string>

class TaskException : public std::exception {
public:
    TaskException(const std::string& taskName, const std::string& message);

    // Override the what() function to return a custom error message
    virtual const char* what() const noexcept override;

    // Get the name of the task associated with the exception
    const std::string& getTaskName() const;

private:
    std::string taskName_;
    std::string message_;
};

#endif // TASKEXCEPTION_H
