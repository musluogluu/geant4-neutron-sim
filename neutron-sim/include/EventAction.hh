#ifndef EVENT_ACTION_H
#define EVENT_ACTION_H

#include "G4UserEventAction.hh"

class EventAction : public G4UserEventAction {
public:
    EventAction() = default;
    virtual ~EventAction() = default;
    virtual void BeginOfEventAction(const G4Event*) override {}
    virtual void EndOfEventAction(const G4Event*) override {}
};

#endif
