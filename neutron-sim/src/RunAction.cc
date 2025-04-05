#include "RunAction.hh"
#include "G4AnalysisManager.hh"

void RunAction::BeginOfRunAction(const G4Run*) {
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->OpenFile("output.root");

    analysisManager->CreateH1("neutron_angle", "Neutron Angle [deg]", 180, 0, 180);
    analysisManager->CreateH1("neutron_energy", "Neutron Energy [MeV]", 100, 0, 1000);
}

void RunAction::EndOfRunAction(const G4Run*) {
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
