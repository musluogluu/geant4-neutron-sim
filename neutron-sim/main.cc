#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4PhysListFactory.hh"
#include "G4SystemOfUnits.hh"

#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"

int main() {
    auto runManager = G4RunManagerFactory::CreateRunManager();

    runManager->SetUserInitialization(new DetectorConstruction());

    G4PhysListFactory factory;
    runManager->SetUserInitialization(factory.GetReferencePhysList("FTFP_BERT"));

    runManager->SetUserInitialization(new ActionInitialization());

    runManager->Initialize();

    G4UImanager::GetUIpointer()->ApplyCommand("/run/initialize");
    G4UImanager::GetUIpointer()->ApplyCommand("/control/execute run.mac");

    delete runManager;
    return 0;
}
