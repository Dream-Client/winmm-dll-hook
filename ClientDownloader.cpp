#include "stdafx.h"
#include "ClientDownloader.h"
#include "LicenceLoader.h"

void* ClientDownloader::_clientData = nullptr;
size_t ClientDownloader::_clientSize = 0;

using json = nlohmann::json;

string ClientDownloader::CreatePayload() {
  json payload = {
    {"licenceKey", LicenceLoader::licence},
    {"checksum", Sha1::from_file(".\\GameAssembly.dll")},
    {"hashes", DreamUtils::GetMachineHashes()}
  };

  return payload.dump();
}

void ClientDownloader::Download() {
  string payload = CreatePayload();
  wstringstream ss;
  ss << payload.c_str();

  Console::P(ss.str());

  httplib::SSLClient cli("api.dreamclient.ovh");
  cli.set_follow_location(true);
  cli.set_connection_timeout(15, 0);
  cli.set_read_timeout(30, 0);
  cli.enable_server_certificate_verification(false);
  cli.set_write_timeout(30, 0);

  if(auto res = cli.Post("/api/v3/clients", payload, "application/json")) {
    if(res->status == 200) {
      auto val = res->get_header_value("Content-Length");
      _clientSize = atoi(val.c_str());
      _clientData = malloc(_clientSize);
      memcpy_s(_clientData, _clientSize, res->body.c_str(), _clientSize);
      Console::Log(L"Client downloaded");
      return;
    }

    HandleErrorResponse(res->status, res->body);
  } else {
    wstringstream requestSS;
    requestSS << L"Error when making request: " << (int)res.error();
    Console::R(requestSS.str());
  }
}

void ClientDownloader::HandleErrorResponse(int statusCode, string& body) {

  Console::Y(L"Response from server:");
  wstringstream statusCodeSS;
  statusCodeSS << L"Status code: " << statusCode;
  Console::Y(statusCodeSS.str());

  json payload = json::parse(body.c_str());

  if(!payload.contains("message")) {
    wstringstream messageSS;
    messageSS << "Error: " << body.c_str();
    return;
  }

  if(payload.at("message").is_array()) {
    wstringstream messagesSS;
    messagesSS << "Messages: ";
    Console::Y(messagesSS.str());
    json messages = payload.at("message");

    for(auto it = messages.begin(); it != messages.end(); it++) {
      string message;
      it.value().get_to(message);
      wstringstream messageSS;
      messageSS << " = " << message.c_str();
      Console::Y(messageSS.str());
    }
    return;

  }

  string message;
  payload.at("message").get_to(message);
  wstringstream messageSS;
  messageSS << "Message: " << message.c_str();
  Console::Y(messageSS.str());
}
