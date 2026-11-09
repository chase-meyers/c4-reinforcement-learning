# c4-reinforcement-learning

Connect 4 playable against an agent that uses reinforcement learning to get better at playing.

## Project Structure

*Originated on October 15, 2026, updated on Nov 8 *
```text
├── C4Board.cpp         # Connect Four board implementation
├── C4Board.h           # Connect Four board header
├── C4Col.cpp           # Column implementation
├── C4Col.h             # Column header
├── main.cpp            # Main program entry point
├── makefile            # Build instructions
├── README.md           # Project documentation
├── agent_current.py    # AI agent playing
└── future.py           # Smart play strategies
```

## Planned Improvements

1. Agent has been merged with C++ code and tested successfully
2. Now future.py is to be developed to cover dynamic strategies
3. Current agent has static weights, limiting potential choices. 

## note:
1. The board is default to be 7 * 6, but can be any size with current C++.  So, please do not hard code the board size, but use col and row.
2. We may need to think about AI's static weight. Current test shows col 2 seems the consistently best position for AI. Need to make some changes
3. Ideally, smart strategies may tap different weights dynamically. Future.py is not playing any roles and will need to be incorporated once it is completed. 
