def board_input():
    # Placeholder THIS WILL CHANGE INTO WHAT IS CHANGING PLAY BY PLAY FROM CPP FILE.  
    # Su Su made change rto read the board exported by C++
    board = []
    try:
        with open("board.txt", "r") as f:
           for line in f:
               row = line.strip().split()
               if row:
                   board.append(row)
    except FileNotFoundError:
        board = [[ '-' for _ in range(7)] for _ in range(6)]
    return board


# Puts all full columns to 0.0 since they cannot be selected from
def availability_rule(board_copy, agent_weights):
    for col in range(len(board_copy[0])):
        if '-' not in [row[col] for row in board_copy]:
            agent_weights[str(col)] *= 0.0
    return agent_weights


# Weighs closeness to center since center gives more options
def center_rule(agent_weights):
    bonus = {"0": 0.8, "1": 0.85, "2": 0.9, "3": 0.9, "4": 0.85, "5": 0.8, "6": 0.8}
    for key in agent_weights:
        agent_weights[key] *= bonus[key]
    return agent_weights


# Uses function rules
def agent_weight_rules(board_copy, agent_weights):
    agent_weights = center_rule(agent_weights)
    agent_weights = availability_rule(board_copy, agent_weights)  # mask last
    return agent_weights


# Interprets board: handles rules, instantiates weight dictionary and creates board copy
def agent_interpret():
    agent_weights = {"0": 1.0, "1": 1.0, "2": 1.0, "3": 1.0, "4": 1.0,
                     "5": 1.0, "6": 1.0}
    board_copy = board_input()
    agent_weights = agent_weight_rules(board_copy, agent_weights)
    return agent_weights


def main():
    weights =agent_interpret(); 
    valid_moves = {k: v for k, v in weights.items() if v > 0.0}
    if valid_moves:
        best_col = max(valid_moves, key=valid_moves.get)
    else:
        best_col = "0"
        
    # Write the chosen move to a file for C++ to read
    with open("move.txt", "w") as f:
        f.write(best_col)   

if __name__ == "__main__":
    print(main())
