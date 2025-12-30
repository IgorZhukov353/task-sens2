/*
  Igor Zhukov (c)
  Created:       01-09-2025
  Last changed:  29-12-2025
*/
#include<Arduino.h>
#include "util.h"
#include "main.h"
//---------------------------------------------------------------------------
bool APP::espSendCommand(const String& cmd, const _STATE goodResponse, const unsigned long timeout, const char *postBuf=NULL, const String &cmd2=""){
  String str = F("espSendCommand:");
  str += cmd;
  trace(str);
  return 1;
}

//---------------------------------------------------------------------------
bool  APP::ping(const String &host, short timeout = 5000) {
    String str = F("AT+PING=\"");
    str += host;
    str += F("\"");
    return espSendCommand(str, _STATE::OK , timeout);
}



