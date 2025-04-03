Curse of the Pharaoh 

Story :
Long ago, deep within the sands of Egypt, a legendary artifact known as the Seal of Anubis was said to hold unimaginable power. Forged by the god of the afterlife himself, this seal was entrusted to a great Pharaoh, who vowed to guard it for eternity. As centuries passed, the Pharaoh’s spirit became bound to the depths of his pyramid, awaiting a worthy challenger to prove their wisdom, courage, and skill.
Many adventurers have entered the cursed tomb in search of the Seal, but none have returned. Traps, puzzles, and ancient guardians lurk in the shadows, testing the resolve of those who dare to enter. It is said that only one who conquers the Seven Trials of the Pyramid can reach the Pharaoh’s chamber. There, a final challenge awaits—a battle of minds in a sacred game of Tic-Tac-Toe, where the fate of the Seal is decided.
As an ambitious archaeologist, you have spent years deciphering ancient texts and tracking the lost entrance to the Pharaoh’s tomb. Now, standing at the threshold, you must summon all your knowledge, skill, and bravery to survive the challenges ahead.
Will you uncover the truth, claim the Seal of Anubis, and rewrite history? Or will you become another forgotten soul, lost to the sands of time?
The Pharaoh awaits… Are you ready for the challenge?

1. General Description of the System
Curse of the Pharaoh is an adventure game where players take on the role of an archaeologist exploring an ancient Egyptian pyramid in search of the legendary Seal of Anubis. The game is designed to be engaging, featuring puzzles, traps, and enemies that players must overcome and collect six keys to solve the Pharaoh's treasure.
Key Features:
•	Exploration of an ancient Egyptian pyramid.
•	Five unique challenges, including puzzles and traps.
•	A final Tic-Tac-Toe match against the Pharaoh as the sixth and final challenge.
•	The first five challenges will involve various puzzles and obstacles 
•	Immersive graphics, animations, and sound effects.
•	Intuitive game mechanics that are easy to understand but offer depth.

2. System Requirements (Game Mechanics & Gameplay)
Game Structure:
•	The player must complete six challenges to win the treasure. and in every challenge you will win a key for the treasure (you need 6 keys)

Challenge 1: Memory Game  
Before you, hieroglyphs light up one by one, forming a precise sequence. A spectral guardian appears and challenges you: watch closely and repeat the sequence without mistakes. 

Challenge 2: The Trap Corridor  
A long corridor stretches ahead, covered in tiles marked with mysterious symbols. Some are safe, others trigger deadly traps. Find the right path and One wrong step… and it's all over.  

Challenge 3: Image Puzzle  
An ancient fresco lies shattered into several scattered pieces. An inscription on the wall reads: "Reconstruct the past to reveal your future." Put the pieces back in the correct order to restore the image and unlock the secret door.  

Challenge 4: The Three Mysterious Doors  
Three doors stand before you, each bearing a cryptic inscription. Choose wisely: one leads to failure, another to the next challenge, and the last one offers a shortcut to the final trial… but there's no way to know which is which.  

Challenge 5: The Knowledge Quiz  
An ancient library unfolds before you, filled with scrolls and millennia-old inscriptions. A guardian watches you closely and declares: "Answer questions about Ancient Egypt to prove your wisdom." Every mistake brings you closer to starting over…  

Challenge 6: The last Duel  
The final chamber is grand, you will play TicTacTeo against the Pharaoh  . One goal: win… or lose everything.
•	Losing the final challenge results in a retry or game over.

Player Abilities:
•	Move: The player can navigate through the pyramid using directional inputs.
•	Interact: The player can interact with objects, solve puzzles, and avoid traps.
•	Solve Puzzles: The player must complete challenges to progress through the game.
•	Strategy & Intelligence: The final challenge requires logical thinking to win against the Pharaoh.

Progression System:
•	The player must complete each challenge before proceeding to the next one.
•	There is a structured sequence of rooms leading to the treasure chamber.
•	Failing a challenge may require a retry, applying a penalty, or an alternative solution.

3. Use Cases

Use Case 1: Start Game
Actors: Player Precondition: The game is installed and launched. Flow:
1.	Player selects "History" from the menu. To know the story of the game
2.	Player selects "Instruction" from the menu, to know how to play
3.	Player selects "Exit" from the menu,to quit the game
4.	Player selects "Play" from the menu
5.	The game initializes and begins the adventure.
6.	Player navigates through the pyramid, solving challengesUse Case 2: Solve a Puzzle
7.	The puzzle is displayed.
8.	The player interacts with the puzzle elements.
9.	If successful, the puzzle is marked as completed.
10.	If unsuccessful, the player can retry.
11.	The player competes against the Pharaoh’s AI.
12.	Winning grants access to the treasure.
13.	Losing results in retry or game over. Postcondition: The game ends successfully or the player retries.

4. Component Diagram

Architecture:
Menu (Play, History, Instruction, Exit)
Each Challenge is separate from the other.
Challenge 1 (Memory , UI, processes user input)
Challenge2 (corridor , obstacles, input)
Challenge3 (Image Puzzle , UI)
Challenge4 (Doors, UI ,processes user input)
Challenge5 (Quiz ,UI ,button)
Challenge6 I use (MVC)
•	Model handles game logic, AI
•	View manages UI, sounds
•	Controller processes user input and manages game state.

5. Class Diagram

Player
KeysCounter 
Button (Challenge1)
Memory (Challenge1)
Corridor (Challenge2)
Obstacles (Challenge2)
Image Puzzle (Challenge3)
Doors (Challenge4)
Button (Challenge4)
Quiz (Challenge5)
Button (Challenge5)
InputHandler (Challenge6)
GameLogic (Challenge6)
Player (Challenge6)
AIPlayer (Challenge6)
MoveHistory (Challenge6)
GameView (Challenge6)
Button (Challenge6)
GameController (Challenge6)
GameStateManager (Challenge6)


6. Test Plan

The system follows a unit testing and integration testing approach to ensure reliability and correctness. Tests are written using Google Test (gtest).
Objective: Ensure that all functionalities work correctly, including gameplay, UI, animations, and sound.
Unit Testing:
•	Test movement mechanics.
•	Test puzzle logic (input and validation).
•	Test Tic-Tac-Toe AI logic.
