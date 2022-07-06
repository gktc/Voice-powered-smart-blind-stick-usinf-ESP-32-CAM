void loop() {
  WifiStatus();
  while (detect == true) {
    
    obj_dist_front = ultra_dist_front();
    obj_dist_right = ultra_dist_right();
    obj_dist_left = ultra_dist_left();
  
    if (obj_dist_front <= 15.00) {
      captureSave_photo();
      detect = false;
      if (Firebase.ready()) {
  
        Serial.print("Uploading Photo... ");
  
        if (Firebase.Storage.upload(&fbdo, STORAGE_BUCKET_ID, IMAGE_PATH, mem_storage_type_flash, IMAGE_PATH, "image/jpeg" )) {
          Serial.printf("\nDownload URL: %s\n", fbdo.downloadURL().c_str());
          Firebase.RTDB.setString(&fbdo, "image", fbdo.downloadURL().c_str());
          Firebase.RTDB.setFloat(&fbdo, "distance", obj_dist_front);
          detect = true; // work here
        }
        else {
          Serial.println(fbdo.errorReason());
        }
      }
      else {
        Serial.println("Not working");
      }
    }
    if (obj_dist_right <= 15.00) {
      detect = false;
      Firebase.RTDB.setFloat(&fbdo, "dist_left", obj_dist_right);
      detect = true;

    }
  
    if (obj_dist_left <= 15.00) {
      detect = false;
      Firebase.RTDB.setFloat(&fbdo, "dist_right", obj_dist_left);
      detect = true;

    }

  delay(1);
  }

}
