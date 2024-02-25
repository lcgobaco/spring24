#ifndef discussions_hpp
#define discussionshpp
#include <string>

using namespace std;

class Discussions {

public:

    //constructor
    Discussions(string discussion);
    //destructor
    ~Discussions();

    //accessors
    string getDiscussion() const;

    //mutators
    void setDiscussion(string discussion);

private:
    string discussion;
};

#endif