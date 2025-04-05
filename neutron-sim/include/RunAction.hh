#ifndef RUN_ACTION_H
#define RUN_ACTION_H

#include "G4UserRunAction.hh"

class RunAction : public G4UserRunAction {
public:
    RunAction() = default;
    virtual ~RunAction() = default;
    virtual void BeginOfRunAction(const G4Run*) override;
    virtual void EndOfRunAction(const G4Run*) override;
};

#endif
