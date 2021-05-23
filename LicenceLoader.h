#pragma once
class LicenceLoader {
public:
  static string licence;

  static void Initialize();
  static void TryLoadLicence();
  static string MakeLicenceJSON();
};

