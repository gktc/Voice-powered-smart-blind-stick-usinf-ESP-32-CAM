float ultra_dist_front() {
  long duration;
  float distanceCm;
  
  digitalWrite(TriggerPinFront, LOW);
  delayMicroseconds(10);
  // Sets the TriggerPin on HIGH state for 10 micro seconds
  digitalWrite(TriggerPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPinFront, LOW);

  // Reads the EchoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(EchoPinFront, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_SPEED / 2;

  // Convert to inches
//  distanceInch = distanceCm * CM_TO_INCH;

  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm) Front: ");
  Serial.println(distanceCm);
//  Serial.print("Distance (inch): ");
//  Serial.println(distanceInch);
  delay(500);

  return distanceCm;
}
