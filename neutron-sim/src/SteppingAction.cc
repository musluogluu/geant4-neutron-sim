#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction(EventAction* eventAction) : fEventAction(eventAction) {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    auto track = step->GetTrack();
    if (track->GetDefinition()->GetParticleName() != "neutron") return;

    if (step->GetPostStepPoint()->GetStepStatus() == fWorldBoundary) {
        auto momentum = track->GetMomentumDirection();
        G4double angle = momentum.angle(G4ThreeVector(0, 0, 1)) * 180.0 / CLHEP::pi;
        G4double energy = track->GetKineticEnergy() / CLHEP::MeV;

        auto analysisManager = G4AnalysisManager::Instance();
        analysisManager->FillH1(0, angle);
        analysisManager->FillH1(1, energy);
    }
}
