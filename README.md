# ENGR-103

# Author
Tyler Henderson

# Game Description
The game I have chosen to (re)create on my CPX board is blackjack. As a refresher this game is played using a deck of cards minus the jokers with a dealer as well as players. The dealer will deal a card to each player including themselves and ultimately a second card as well. The players will be dealt their cards face up while the dealer places their face down except for the first card. The goal is to accumulate cards that add up to be as close to 21 without going over. Players are allowed to either “hit” where they will ask to be dealt another card to try and get closer to 21, or “stand” where they will let the dealer move on and not deal them any more cards. Once all the players are satisfied with their hands the dealer then looks at their card which isn’t face up and will continue to draw cards until they get as close to 21 as possible. Typically dealers at casinos will be forced to stand on anything that adds up to be 17 or over which the players can use to their advantage. The goal of the game is to beat the dealer, not your fellow players.

Each face card will count for 10, aces count for either 1 or 11 which is . Aces are typically the most powerful card to be dealt in this game because it allows the player so much flexibility in being able to hit without the worry of going bust. Sometimes players will be dealt an ace and a face card(or a 10) in the initial round of dealing, which is an automatic win at least and in the rarest case it might be a push(where the dealer also gets 21). Occasionally Blackjacks are awarded additional winnings in casinos but for legal purposes there is no betting allowed in CPX Blackjack.

The LEDs around the CPX board will light up according to what the player is dealt, with a half lit LED representing 1 and a fully lit LED representing 2 all the way around the board. All 10 fully lit LEDs represent a score of 20, if 21 is achieved there will be a noticeable pattern which celebrates the victory for the player and some sounds potentially. If the user goes over 21 then the board will do the negative and display a noticeably depressing light pattern as well as an equally depressing sound.
The right button will be used to “hit” and on the contrary the left button will be used to “stand”, the switch will be programmed to switch between the dealers hand and the players hand as well, different light schemes will be used to differentiate which hand the board is displaying. Blue to represent “not” the user and white to represent the user.
In order to help players properly use aces there will be an option to choose whether they want the ace to count for 1 or 11 when it is drawn. When the card is dealt to the user, there will be a noticeable tone which will notify them that they will have to decide what they want it to count for.
In order to reset the game, the board will need to be shook and there will be a board output which will confirm the reset.

# Specifications
