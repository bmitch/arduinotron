
#define FREQ_CONTROL         (0)
#define LFO_CONTROL          (1)

int syncPhaseInc;
int intensity; // Amount the freq will increase
int lfo; // lfo rate

uint16_t midiTable[] = {
  17,18,19,20,22,23,24,26,27,29,31,32,34,36,38,41,43,46,48,51,54,58,61,65,69,73,
  77,82,86,92,97,103,109,115,122,129,137,145,154,163,173,183,194,206,218,231,
  244,259,274,291,308,326,346,366,388,411,435,461,489,518,549,581,616,652,691,
  732,776,822,871,923,978,1036,1097,1163,1232,1305,1383,1465,1552,1644,1742,
  1845,1955,2071,2195,2325,2463,2610,2765,2930,3104,3288,3484,3691,3910,4143,
  4389,4650,4927,5220,5530,5859,6207,6577,6968,7382,7821,8286,8779,9301,9854,
  10440,11060,11718,12415,13153,13935,14764,15642,16572,17557,18601,19708,20879,
  22121,23436,24830,26306
};


uint16_t mapMidi(uint16_t input) {
  return (midiTable[(1023-input) >> 3]);
}


void setup() {
  
  Serial.begin(9600);
  intensity = 2;
  lfo = 100;
}

void loop() {

  // LFO low
  syncPhaseInc = mapMidi(analogRead(FREQ_CONTROL));
  lfo = analogRead(LFO_CONTROL);
  lfo = map(lfo, 0, 627, 10, 1000);
  delay(lfo);

  Serial.println(lfo);
  tone(8, syncPhaseInc, lfo);

  // LFO high

  syncPhaseInc = mapMidi(analogRead(FREQ_CONTROL)) * intensity;
  delay(lfo);
  tone(8, syncPhaseInc, lfo);


}