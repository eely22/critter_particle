#define trapPin A7
#define TIME_TO_PUBLISH 3600000

unsigned long time_track;
bool trapSprung = false;

void setup() {
    // lower some BLE settings to save power
    BLE.setAdvertisingInterval(500);

    // take control of the RGB LED and turn it off to save power
    RGB.control(true);
    RGB.color(0, 0, 0);

    // attach interrupt to traigger when the trap springs
    pinMode(trapPin, INPUT_PULLUP);
    // attachInterrupt(trapPin, trap, CHANGE);

    time_track = millis();
}

void loop() {
    System.sleep(SLEEP_MODE_CPU);
    if (Particle.connected() && digitalRead(trapPin) == LOW && !trapSprung) {
        trapSprung = true;
        Particle.publish("CRITTER", "TRAP_TRIGGERED");

        // not super efficient, but this shouldn't happen often. used to debounce.
        delay(500);
    }
    if (millis() - time_track > TIME_TO_PUBLISH) {
        Spark.publish("VOLTAGE", String(readSupplyVoltage()));
        time_track = millis();
    }
}

void trap() {
}