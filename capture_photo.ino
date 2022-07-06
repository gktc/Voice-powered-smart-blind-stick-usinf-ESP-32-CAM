void captureSave_photo( void ) {
  
  camera_fb_t * fb = NULL; 
  bool ok = 0; 
  do {
    Serial.println("ESP32-CAM capturing photo...");

    fb = esp_camera_fb_get();
//    String encoded = (base64::encode(fb->buf)).toString;
//    Serial.println(encoded);
    if (!fb) {
      Serial.println("Failed");
      return;
    }
    Serial.printf("Picture file name: %s\n", IMAGE_PATH);
    File file = SPIFFS.open(IMAGE_PATH, FILE_WRITE);
    if (!file) {
      Serial.println("Failed to open file in writing mode");
    }
    else {
      file.write(fb->buf, fb->len); 
      Serial.print("The picture has been saved in ");
      Serial.print(IMAGE_PATH);
      Serial.print(" - Size: ");
      Serial.print(file.size());
      Serial.println(" bytes");
    }
    file.close();
    esp_camera_fb_return(fb);
    ok = check_photo(SPIFFS);
  } while ( !ok );

}
