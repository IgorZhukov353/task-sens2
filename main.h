/* 
 Igor Zhukov (c)
 Created:       01-09-2025
 Last changed:  25-12-2025
*/
#define ARDUINOJSON_ENABLE_PROGMEM 1
#include <ArduinoJson.h>

//---------------------------------------------------------------------------
enum class _STATE {OK = 0, ERR = 1, HTTP = 2, HTTP_OK = 3, CLOSED = 4};
enum class _ErrorType {NONE=0,HTTP_FAIL=1,TIMEOUT=2,OTHER=3};
#define MAX_PING 10

class APP {
char WSSID[20], WPASS[10], HOST_STR[25], HOST_IP_STR[15]; 

public:
  long startTime;
  byte check_tcp_last_byte[MAX_PING]; // устройства для пингования
  byte check_tcp_err[MAX_PING];       // признак ошибки пингования устройств

  void configRead();
  bool ping(const String &host, short timeout = 5000);
  bool espSendCommand(const String& cmd, const _STATE goodResponse, const unsigned long timeout, const char *postBuf=NULL, const String &cmd2="");

  bool send2site(const String& reqStr){};
  void addEvent2Buffer(byte id, const String& msgText){};
  void addTempHum2Buffer(byte id, int8_t temp, int8_t hum){};
  void addSens2Buffer(byte id, byte val){};

};


#ifdef MAIN
APP app;

// TempSensor temper[TEMPER_MAX];
// LED led[LED_MAX];
// PIN p[PIN_MAX];
// Sensor * s[ALL_MAX];
// SensorArray sa;
// LED *sysledptr;

#else
extern APP app;

// extern TempSensor temper[TEMPER_MAX];
// extern LED led[LED_MAX];
// extern PIN p[PIN_MAX];
// extern Sensor * s[ALL_MAX];
// extern SensorArray sa;
// extern LED *sysledptr;

#endif

//---------------------------------------------------------------------------
void taskInit(String json);
void taskProcessing();
//---------------------------------------------------------------------------
//int sensorLoad(String json);
int sensorLoad(JsonDocument & doc);
int sensorProcessing();
