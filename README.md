# Dx-Ball-arduino-ATmega328p


The infamous DX-Ball was a free pc game released in 1996 and it was an extension to the classic ball and paddle arcade games, in this game the player controls a paddle at the bottom and deflects a single ball, hitting different blocks on the top of the screen without having the ball fall below the screen. Clearing all the blocks results in completing the level and going to the next.


Inputs and outputs: 
LED grid: this grid will simulate the screen of the game.
LCD Screen: shows the current score of the player.
Two Infared Sensors: Move the Peddal right or left to prevent the ball from falling below the simulated screen.
Two touch sensors: sensors used for starting and resetting the game.
RGB LED: indicates the game status win or lose or playing.
Buzzer : indicates happening of each action, different sounds depending on the action.


Game Flow:
The grid will simulate the game with the blocks appearing on the upper half of the screen and the paddle with size about 3 LEDs will deflect the ball either up or diagonally left or right at the start of the game the ball will be present at the center of the paddle win the player touches the sensor responsible for the game start the ball will go up and bounces back down, the player will try to prevent the ball from reaching the lower end of the screen while hitting as many blocks as he can, if he gets to finish all the blocks the game end and the LED will indicates that he has won with his score displayed on the screen. The game gets harder by the time, the ball moves fatser and the probability to fall apart gets higher.


