#include "stdafx.h"
#include "LicenceLoader.h"

#define LICENCE_PATH L"DreamVR\\Preferences\\licenses.txt"

std::string LicenceLoader::licence = "";

void LicenceLoader::Initialize() {
  TryLoadLicence();

  if(LicenceLoader::licence == "") {
    Console::Y(L"Please setup licence.");
    while(true) {
      Console::Y(L"Checking for licence changes in 5 seconds...");
      Sleep(5000);
      LicenceLoader::TryLoadLicence();
      if(LicenceLoader::licence != "") {
        break;
      }
      if(!Console::IsOpen()) {
        exit(0);
      }
    }
  }

  Console::G(L"Found potential licence. Continuing...");
}

void LicenceLoader::TryLoadLicence() {
  if(!Utils::fileExists(LICENCE_PATH))
    return;

  std::ifstream infile(LICENCE_PATH);
  if(infile.good()) {
    std::string sLine;
    std::getline(infile, sLine);
    licence = sLine;
  }

  infile.close();

  if(licence.length() != 19 || licence[4] != '-' || licence[9] != '-' || licence[14] != '-') {
    Console::Y(L"Provided licence doesn't seem valid, please fix it.");
    Console::Y(L"Licence should match the following pattern: XXXX-XXXX-XXXX-XXXX");
    licence = "";
  }
}

std::string LicenceLoader::MakeLicenceJSON() {
  //std::string serialNumber = ProcUtils::GetValue("wmic baseboard get serialnumber");
  //std::string cpuName = ProcUtils::GetValue("wmic cpu get name");
  //std::string cpuId = ProcUtils::GetValue("wmic cpu get ProcessorId");
  //std::string windowsUniqueID = ProcUtils::GetValue("wmic csproduct get UUID");
  //std::string computerName = ProcUtils::GetValue("wmic computersystem get name");
  //std::string computerModel = ProcUtils::GetValue("wmic computersystem get model");

  std::string json = "";
  json += "{";
  //json += "\"MotherBoardSerial\": \"" + serialNumber + "\"" + ",";
  //json += "\"WindowsUniqueID\": \"" + windowsUniqueID + "\"" + ",";
  //json += "\"ProcessorName\": \"" + cpuName + "\"" + ",";
  //json += "\"ProcessorID\": \"" + cpuId + "\"" + ",";
  //json += "\"ComputerName\": \"" + computerName + "\"" + ",";
  //json += "\"ComputerUniqueID\": \"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\",";
  ////json += "\"ComputerUniqueID\": \"" + "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" + "\"" + ",";
  json += "\"Licence\": \"" + licence + "\"";
  json += "}";

  //ConsoleUtils::Log(json.c_str());
  //ConsoleUtils::Log(computerModel.c_str());

  return json;
}
