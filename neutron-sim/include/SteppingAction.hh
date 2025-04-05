#ifndef STEPPING_ACTION_H
#define STEPPING_ACTION_H

#include "G4UserSteppingAction.hh"
#include "EventAction.hh"

class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction(EventAction*);
    virtual ~SteppingAction() = default;
    virtual void UserSteppingAction(const G4Step*) override;

private:
    EventAction* fEventAction;
};

#endif
