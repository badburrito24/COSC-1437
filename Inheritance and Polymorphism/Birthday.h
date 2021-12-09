#ifndef BIRTHDAY
#define BIRTHDAY
#include "Event.h"

class Birthday : public Event {
    private:
        string gifts;
    public:
        Birthday(string de, string l, const Time &t, const Date &d, string g);
        ~Birthday(){}
        string getGifts() const;
        string getType() const;
        void printSummary() const;
};

#endif