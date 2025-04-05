#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

void ActionInitialization::Build() const {
    auto eventAction = new EventAction();
    SetUserAction(new PrimaryGeneratorAction());
    SetUserAction(new RunAction());
    SetUserAction(eventAction);
    SetUserAction(new SteppingAction(eventAction));
}
