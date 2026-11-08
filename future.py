# Take in board
# Determine future possibilities
# Evaluate the best move
# Ensure move does not let opposing player win
# If any move allows computer to win, take it immediately
# Return best found move

#For reading in the board -- for now, will use set board until files are connected
#input_board = input()
#board = []
#for x in input_board.split():
#    board.append(int(x))

# Return list of lists containing all possible boards
def determine_possible_boards(board):
    possible_boards = []
    temp_board = board.copy()

    # For each column, start at the bottom
    for x in range(7):
        for y in range(5, -1, -1):

            # Calculate index
            index = y * 7 + x

            # If row is not full, add a chip and include board with potential moves
            if (board[index] == 0):
                temp_board[index] = 1
                possible_boards.append(temp_board.copy())
                temp_board[index] = 0
                break

    return possible_boards

def examine_board(board):
    # Implement logic for board examination
    # Will determine potential winning moves
    # If no winning moves, determine if user has any winning moves
    # If user has no winning moves, determine best defensive move
    # If no defensive moves, 
    pass

blank_board = [0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0]

possible_boards = determine_possible_boards(blank_board)

print(possible_boards)