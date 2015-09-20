#include "LiquidCrystal_I2C.h"
#include "application.h"

#define MAX_LENGTH 60  // Max string length defined by Particle API. Any longer, and the request will fail.

LiquidCrystal_I2C   *lcd;

String header = "Tweeting Rainbow:";
String tweet = "Butterfly in the sky, I can go twice as high, take a look, it's in a book, a reading rainbow, I can go anywhere!";
String pendingTweet = "";
uint16_t tweet_offset = 0;

void setup() 
{
  // Initalize the LCD with backlight
  lcd = new LiquidCrystal_I2C(0x3F, 20, 4);
  lcd->init();
  lcd->backlight();
  lcd->clear();
  updateDisplay();

  // Create a web endpoint to send commands. You must have the device ID and an access token.
  // https://api.particle.io/v1/devices/<device ID>/<function_name>?access_token=<access_token>
  Spark.function("setTweet", setTweet);
}

void loop() 
{
  display(4000);
}

// Web endpoint to set the tweet to be shown.
// Takes a message of the form "<segment #>/<total # of segments><message>"
// The server will send a long message in the form of multiple requests:
// "1 2 This is a really long message really really really long max length 60 chars"
// "2 2 but now we are good because of this messaging system"
int setTweet(String t) {
    int segment = t.substring(0,1).toInt();
    int total = t.substring(2,3).toInt();
    String sub = t.substring(4);

    if (segment == 1) {
        // First segment
        pendingTweet = sub;
    } else {
        // Appendage
        pendingTweet += sub;
    }
    
    if (segment == total) {
        // Got the entire message
        tweet = pendingTweet;
        tweet_offset = 0;
        updateDisplay();
    }

    return 1;
}

// Shows the next segment of the tweet if it is too long
void swapLengthyTweet() {
    if (tweet.length() > MAX_LENGTH) {
        tweet_offset = tweet_offset + 60;
        if (tweet_offset >= tweet.length()) {
            tweet_offset = 0;
        }
        updateDisplay();
    }
}

void updateDisplay() {
    setDisplay(header, tweet.substring(tweet_offset, tweet_offset + 20), 
                       tweet.substring(tweet_offset + 20, tweet_offset + 40), 
                       tweet.substring(tweet_offset + 40, tweet_offset + 60));
}

// Sets the message for each line of a 20x4 LCD screen.
void setDisplay(String a, String b, String c, String d) {
    if (a.length() > 20 || b.length() > 20 || c.length() > 20 || d.length() > 20) {
        return;
    }
 
    // Character 0, Line 0
    // Clear all 20 characters on the line, then print your message.
    lcd->setCursor(0, 0);
    lcd->print("                    ");
    lcd->setCursor(0, 0);
    lcd->print(a);

    // Character 0, Line 1
    lcd->setCursor(0, 1);
    lcd->print("                    ");
    lcd->setCursor(0, 1);
    lcd->print(b);

    // Character 0, Line 2
    lcd->setCursor(0, 2);
    lcd->print("                    ");
    lcd->setCursor(0, 2);
    lcd->print(c);

    // Character 0, Line 3
    lcd->setCursor(0, 3);
    lcd->print("                    ");
    lcd->setCursor(0, 3);
    lcd->print(d);
}