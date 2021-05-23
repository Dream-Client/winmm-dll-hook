#pragma once
class ClientDownloader {
  static string CreatePayload();
public:
  static void* _clientData;
  static size_t _clientSize;

  static void Download();
  static void HandleErrorResponse(int statusCode, string& body);
};

