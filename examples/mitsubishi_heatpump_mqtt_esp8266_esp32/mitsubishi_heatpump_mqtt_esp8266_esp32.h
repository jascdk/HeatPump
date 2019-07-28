//#define ESP32
//#define OTA
//const char* ota_password = "<YOUR OTA PASSWORD GOES HERE>";

/* MQTT */
#define MQTT_SERVER             ""     // MQTT Server IP - Defined through WifiManager.
#define MQTT_SERVER_PORT        "1883" // MQTT Port Number - Defined through WifiManager - "1883" is the default port.
#define MQTT_USER               ""     // MQTT Username - Defined through WifiManager - leave empty if you do nota have any.
#define MQTT_PSK                ""     // MQTT Password - Defined through WifiManager - leave empty if you do nota have any.

// mqtt client settings
// Note PubSubClient.h has a MQTT_MAX_PACKET_SIZE of 128 defined, so either raise it to 256 or use short topics
const char* client_id                   = "Mitsubishi Heatpump Gateway II"; // Must be unique on the MQTT network
const char* heatpump_topic              = "heatpump";
const char* heatpump_set_topic          = "heatpump/set";
const char* heatpump_status_topic       = "heatpump/status";
const char* heatpump_timers_topic       = "heatpump/timers";

const char* heatpump_debug_topic        = "heatpump/debug";
const char* heatpump_debug_set_topic    = "heatpump/debug/set";

// sketch settings
const unsigned int SEND_ROOM_TEMP_INTERVAL_MS = 60000;

/* NETWORK */
bool should_save_config = false;
uint64_t last_reconnect_attempt = 0;
const char* mqtt_server = MQTT_SERVER;
const char* mqtt_port = MQTT_SERVER_PORT;
const char* mqtt_username = MQTT_USER;
const char* mqtt_password = MQTT_PSK;
//WiFiManagerParameter c_device_name("device_name", "Device name", deviceLocation, 64);
WiFiManagerParameter c_mqtt_server("server", "MQTT server", mqtt_server, 64);
WiFiManagerParameter c_mqtt_port("port", "MQTT port", mqtt_port, 8);
WiFiManagerParameter c_mqtt_username("user", "MQTT username", mqtt_username, 64);
WiFiManagerParameter c_mqtt_password("pass", "MQTT password", mqtt_password, 64, "type='password'");
WiFiClient socket;
PubSubClient mqtt_client(socket);
WiFiManager wifiManager;
