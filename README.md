# ENGR-103

# Author
Tyler Henderson

# Game Description
The game I have chosen to (re)create on my CPX board is blackjack. As a refresher this game is played using a deck of cards minus the jokers with a dealer as well as players. The dealer will deal a card to each player including themselves and ultimately a second card as well. The players will be dealt their cards face up while the dealer places their face down except for the first card. The goal is to accumulate cards that add up to be as close to 21 without going over. Players are allowed to either “hit” where they will ask to be dealt another card to try and get closer to 21, or “stand” where they will let the dealer move on and not deal them any more cards. Once all the players are satisfied with their hands the dealer then looks at their card which isn’t face up and will continue to draw cards until they get as close to 21 as possible. Typically dealers at casinos will be forced to stand on anything that adds up to be 17 or over which the players can use to their advantage. The goal of the game is to beat the dealer, not your fellow players.

Each face card will count for 10, aces count for either 1 or 11 which is . Aces are typically the most powerful card to be dealt in this game because it allows the player so much flexibility in being able to hit without the worry of going bust. Sometimes players will be dealt an ace and a face card(or a 10) in the initial round of dealing, which is an automatic win at least and in the rarest case it might be a push(where the dealer also gets 21). Occasionally Blackjacks are awarded additional winnings in casinos but for legal purposes there is no betting allowed in CPX Blackjack.

In order to help players properly use aces there will be an option to choose whether they want the ace to count for 1 or 11 when it is drawn. When the card is dealt to the user, there will be a noticeable tone which will notify them that they will have to decide what they want it to count for.
In order to reset the game, the board will need to be shook and there will be a board output which will confirm the reset.

# Specifications
Input Controls:
•	Hit: right button
•	Stand: left button
•	Switch: do not disturb mode where the sound will be disabled but the light features will still work
•	Shake: resets game
Outputs
•	LEDs indicate how many the user has:
o	with a half-lit LED showing 1, and 
o	fully lit LED indicating 2
•	Special light pattern to display exactly 21
•	Special sound pattern to represent getting 21
•	Special pattern to represent busts(going over 21)
•	Extra sound pattern to represent user drawing an ace(21 with first two cards dealt)
Speech Feedback
•	Either play a melody or voice for if user draws an ace
•	Either play a melody or a voice when user wins or loses
Controls:
•	Left Button
•	Right Button
•	Switch
Sensors Used:
•	Motion Detector
Functions and Ranges:
•	CircuitPlayground.setPixelColor();
o	Set different color and brightness depending on situation
Thresholds and map()’s:
•	Threshold for acceleration around 80-90
•	No mapping, the outputs will be based solely on outcomes of the game
