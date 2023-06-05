#include <Adafruit_CircuitPlayground.h>

float X, Y, Z, totalAccel, accelThreshold = 65;
int dealerArray[52] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
int userArray[52] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
int userCount = 0, dealerCount = 0, dealerHand = 0, rightButton = 5, leftButton = 4, switchPin = 7, gameMode = 0, drawnCard = 0, finalUserCount = 0, finalDealerCount = 0, dealerDisplay = 0;
bool standFlag = false, hitFlag = false, switchFlag = false, startFlag = false, dealerFlag = false;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  while(!Serial);
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
  attachInterrupt(digitalPinToInterrupt(switchPin), switchFunction, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightButton), hitFunction, RISING);
  attachInterrupt(digitalPinToInterrupt(leftButton), standFunction, RISING);
  randomSeed(analogRead(1));
}

void loop() {
  startGame();
  checkReset();
  // checkEnd();
  // dealerView();
}

void startGame() {
  if(!startFlag){
    CircuitPlayground.clearPixels();
    delay(500);
    Serial.println("Starting Game");
    delay(200);
    //deal to user
    drawnCard = userArray[random(0,52)];
    userCount += drawnCard;
    Serial.print("User's Count: ");
    Serial.println(userCount);
    drawnCard = 0;
    delay(1000);
    checkReset();
    //deal to dealer
    drawnCard = dealerArray[random(0,52)];
    dealerCount += drawnCard;
    dealerHand += dealerCount;
    Serial.print("Dealer's Count: ");
    Serial.println(dealerCount);
    drawnCard = 0;
    delay(1000);
    checkReset();
    //deal again to user
    drawnCard = userArray[random(0,52)];
    userCount += drawnCard;
    Serial.print("User's Total: ");
    Serial.println(userCount);
    drawnCard = 0;
    delay(1000);
    checkReset();
    //deal again to dealer
    drawnCard = dealerArray[random(0,52)];
    dealerCount += drawnCard;
    Serial.println("Hit or Stand?");
    delay(1000);
    checkReset();
    startFlag = true;
    }
  checkEnd();
}

void checkReset() {
  X = 0;
  Y = 0;
  Z = 0;
  for (int i = 0; i < 10; i++) {
    X += CircuitPlayground.motionX();
    Y += CircuitPlayground.motionY();
    Z += CircuitPlayground.motionZ();
    delay(1);
  }

  X /= 10;
  Y /= 10;
  Z /= 10;

  totalAccel = sqrt(X*X + Y*Y + Z*Z);
  if(totalAccel > accelThreshold){
    Serial.println("Resetting");
    delay(100);
    initialize();
  }
  delay(10);
}

void checkEnd() {
  if((userCount > 21) || ((finalDealerCount > finalUserCount) && (finalDealerCount <= 21))) {
    bustSequence();
  }
  else if(((dealerCount > 21) && (userCount <= 21)) || ((finalUserCount > finalDealerCount) && standFlag)) {
    winSequence();
  }
  else if(finalDealerCount = finalUserCount) {
    pushSequence();
  }
  // else if(userCount = 21) {
  //   winSequence();
  // }
  checkReset();
}

void dealerView() {
  if(switchFlag) {
    dealerDisplay = dealerCount;
    if(dealerCount < 10) {
     for(int i = 0; i < dealerCount; i++) {
      CircuitPlayground.setPixelColor(i, 0, 0, 125);
     }
    }
    else if(dealerCount >= 10) {
      dealerDisplay = map(dealerCount, 10, 21, 0, 10);
      for(int i = 0; i < dealerDisplay; i++) {
      CircuitPlayground.setPixelColor(i, 0, 0, 255);
      }
    }
  }
}

void cardCheck() { //check if ace was drawn, then prompt user to choose between 11 and 1 for the values
  if(drawnCard = 11) {
    CircuitPlayground.playTone(250, 250);
    CircuitPlayground.playTone(200, 250);
    CircuitPlayground.playTone(150, 250);
    aceSequence();
  }
}

void initialize() {
  Serial.println("Resetting");
  userCount = 0;
  dealerCount = 0;
  standFlag = false;
  hitFlag = false;
  switchFlag = false;
  gameMode = 0;
  finalUserCount = 0;
  finalDealerCount = 0;
  dealerDisplay = 0;
  dealerFlag = false;
  delay(2000);
  CircuitPlayground.clearPixels();
  Serial.println("Reset Complete");
  delay(1000);
  startFlag = false;
  // startGame();
}


void aceSequence() {
  //CircuitPlayground.setPixelColor();
  checkReset();
}

void bustSequence() { //also used for losing
  for(int i = 0; i < 10; i++){
   CircuitPlayground.setPixelColor(i, 255, 0, 0);
   delay(40000);
  }
  delay(10000);
  CircuitPlayground.clearPixels();
  delay(10000);
  for(int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
  }
  delay(10000);
  Serial.println("You Lose :(");
  CircuitPlayground.playTone(300,500); 
  CircuitPlayground.playTone(250,500); 
  CircuitPlayground.playTone(200,1300);
  delay(10000);
  initialize();
}

void winSequence() {
  for(int i = 0; i < 10; i++){
   CircuitPlayground.setPixelColor(i, 0, 255, 0);
   delay(50000);
  }
  delay(10000);
  CircuitPlayground.playTone(200,500);
  CircuitPlayground.playTone(300,1000);
  Serial.println("You Win!");
  delay(1000);
  initialize();
}

void pushSequence() {
  Serial.println("Push");
  for(int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 125, 125, 125);
    delay(40000);
  }
  
  delay(50000);
  initialize();
}

void switchFunction() {
  delay(30);
  Serial.println(switchFlag);
  Serial.println("Switching Views");
  CircuitPlayground.clearPixels();
  switchFlag = !switchFlag;
}

void hitFunction() {
  delay(300);
  Serial.println("Hit");
  drawnCard = userArray[random(0,52)];
  userCount += drawnCard;
  Serial.print("User's Total: ");
  Serial.println(userCount);
  drawnCard = 0;
  checkReset();
  checkEnd();
}

void standFunction() {
  delay(300);
  Serial.println("Stand");
  delay(1000);
  standFlag = true;
  finalUserCount += userCount;
  Serial.print("User's Final Count: ");
  Serial.println(finalUserCount);
  delay(1000);
  dealerFlag = true;
  while(dealerFlag) {
   if((dealerCount < 17)) {
   drawnCard = userArray[random(0,49)];
   dealerCount += drawnCard;
   Serial.print("Dealer's Count: ");
   Serial.println(dealerCount);
   drawnCard = 0;
   delay(10000);
   }
   else if(dealerCount >= 17){
    finalDealerCount += dealerCount;
    delay(10000);
    Serial.print("Dealer's Final Count: ");
    Serial.println(finalDealerCount);
    delay(20000);
    checkEnd();
    dealerFlag = false;
   }
  }
  checkReset();
  checkEnd();
}