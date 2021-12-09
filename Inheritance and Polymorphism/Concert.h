#ifndef CONCERT
#define CONCERT
#include "Event.h"

class Concert : public Event {
    private:
        int tickets;
    public:
        Concert(string de, string l, const Time &t, const Date &d, int ti);
        ~Concert(){}
        int getTickets() const;
        string getType() const;
        void printSummary() const;
};

#endif