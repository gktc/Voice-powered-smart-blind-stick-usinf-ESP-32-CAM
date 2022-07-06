
#include "base64.hpp"
#include "WiFi.h"
#include "esp_camera.h"
#include "Arduino.h"
//#include "soc/soc.h"           
//#include "soc/rtc_cntl_reg.h"  
#include "driver/rtc_io.h"
#include <SPIFFS.h>
#include <FS.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>


#define API_KEY "AIzaSyAkmUI61zn0DnHL0vPKLRtPiBHI0BMa_Uc"
#define DATABASE_URL "https://esp-c315f-default-rtdb.firebaseio.com/"
#define TriggerPinFront  13
#define EchoPinFront     12
#define TriggerPinRight  4
#define EchoPinRight     2
#define TriggerPinLeft  14
#define EchoPinLeft     15
#define LED 4
#define SOUND_SPEED 0.034

// ENter Authorized Email and Password
#define USER_EMAIL "gopikrishnatc@gmail.com"
#define USER_PASSWORD "qwerty6%4#2!"

// Enter Firebase storage bucket ID
#define STORAGE_BUCKET_ID "esp-c315f.appspot.com"
#define IMAGE_PATH "/pictures/image.jpg"
#define CAMERA_MODEL_AI_THINKER 
// OV2640 camera module pins (CAMERA_MODEL_AI_THINKER)
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

//Enter your network credentials
const char* ssid = "HARIKRISHNAN";
const char* password = "Hari5341";
void startCameraServer();

float obj_dist_front ;
float obj_dist_right ;
float obj_dist_left ;

//String upload = "True"; 
String uid;
bool detect = true; 
//long duration;

FirebaseData fbdo;
FirebaseAuth authentication;
FirebaseConfig configuration;
//FirebaseJson json;

String distance = "/distance";
String image = "/image";

bool check_photo( fs::FS &fs ) {
  File f_pic = fs.open( IMAGE_PATH );
  unsigned int pic_sz = f_pic.size();
  return ( pic_sz > 100 );
}

// Capture Photo and Save it to SPIFFS
