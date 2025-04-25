# Class Diagram Description: Ancient Egypt Adventure Game

## Overview
This class diagram outlines the architecture for an **Ancient Egypt-themed adventure game** featuring six sequential challenges. The central `InputHandler` class manages player interactions and delegates actions to specialized controllers, primarily focusing on `PowerController` (likely for game mechanics/state), with additional support from `DisplayInterfaceController` and `ErrorController`.

---

## Core Components

### 1. **InputHandler**
- **Role**: Central hub for processing player input across all challenges.
- **Functionality**:
  - Routes actions to appropriate controllers (e.g., trap selection, puzzle piece placement).
  - Tracks challenge progression and validates player responses.
  - Interfaces with `ErrorController` for mistake handling (e.g., trap triggers, wrong answers).

### 2. **Controllers**
#### `PowerController` (Dominant)
- **Purpose**: Manages game state and challenge mechanics.
- **Usage Examples**:
  - **Memory Game**: Records/validates hieroglyph sequences.
  - **Trap Corridor**: Tracks safe/dangerous tile states.
  - **Tic-Tac-Toe Duel**: Enforces Pharaoh’s moves and win conditions.

#### `DisplayInterfaceController`
- **Purpose**: Handles visual feedback.
- **Features**:
  - Renders hieroglyph sequences, trap corridor tiles, and puzzle pieces.
  - Updates UI for quiz questions and door inscriptions.

#### `ErrorController`
- **Purpose**: Manages failures (e.g., wrong steps, quiz mistakes).
- **Actions**:
  - Triggers game-over states or challenge retries.
  - Logs errors for debugging.

---

## Challenges Mapped to Controllers
| Challenge               | Key Controllers               | Description                                                                 |
|-------------------------|-------------------------------|-----------------------------------------------------------------------------|
| 1. Memory Game          | `PowerController`, `Display`  | Validates player-repeated hieroglyph sequences.                             |
| 2. Trap Corridor        | `PowerController`, `Error`    | Detects safe/trap tiles; triggers penalties.                                |
| 3. Image Puzzle         | `Display`, `PowerController`  | Manages piece placement and completion checks.                              |
| 4. Three Mysterious Doors| `PowerController`             | Randomizes door outcomes (failure/next challenge/shortcut).                |
| 5. Knowledge Quiz       | `PowerController`, `Error`    | Scores answers; forces retries after too many mistakes.                     |
| 6. Pharaoh’s Tic-Tac-Toe| `PowerController`, `Display`  | Controls AI moves and checks win/lose conditions.                           |

---

## Suggested Improvements
1. **Challenge-Specific Controllers**:
   - Add dedicated controllers (e.g., `QuizController`, `PuzzleController`) to streamline logic.
2. **State Management**:
   - Clarify how `PowerController` transitions between challenges (e.g., via a `GameState` class).
3. **Relationships**:
   - Use arrows to show dependencies (e.g., `InputHandler` → `PowerController` for trap detection).
4. **Error Handling**:
   - Expand `ErrorController` to include challenge-specific feedback (e.g., "Wrong hieroglyph!").

## Conclusion
The diagram reflects a modular design where the `InputHandler` orchestrates challenges through controllers. To enhance clarity, consider separating challenge-specific logic and visually distinguishing controller roles in the diagram.
