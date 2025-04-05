#include "DetectorConstruction.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();

    G4Material* worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* tungsten = nist->FindOrBuildMaterial("G4_W");

    G4double worldSize = 1.5 * m;
    auto solidWorld = new G4Box("World", worldSize, worldSize, worldSize);
    auto logicWorld = new G4LogicalVolume(solidWorld, worldMat, "World");
    auto physWorld = new G4PVPlacement(0, {}, logicWorld, "World", 0, false, 0);

    auto solidTarget = new G4Tubs("Target", 0., 7.5*cm, 30*cm, 0., 360.*deg);
    auto logicTarget = new G4LogicalVolume(solidTarget, tungsten, "Target");
    new G4PVPlacement(0, {}, logicTarget, "Target", logicWorld, false, 0);

    return physWorld;
}
