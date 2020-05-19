int rpm_time = 0;

void update_rpm(){
  int interval = millis() - rpm_time;
  if(interval > 50)
  { 
    /* hitung rpm */ 
    rpm=(int)((float)(rot_count*60*1000)/(ppr*interval));

    /* Hitung posisi (total counter) */
    pos+=rot_count;

    /* Reset counter dan timer */
    rot_count = 0;
    rpm_time = millis();

    Serial.print(" Pos: "); Serial.print(pos);
    Serial.print(" Rpm: "); Serial.println(rpm);
  }
}
