#include <bits/stdc++.h>
using namespace std;

// ---------------- Cell ----------------
class Cell {
    int row, col;
public:
    Cell(int r, int c) {
        row = r;
        col = c;
    }
    int getRow() { return row; }
    int getCol() { return col; }
};

// ---------------- Player ----------------
class Player {
    string symbol;
public:
    Player(string s) {
        symbol = s;
    }
    string getSymbol() { return symbol; }
    Player flip() {
        if(symbol == "X") return Player("O");
        else return Player("X");
    }
};

// ---------------- Move ----------------
class Move {
    Cell cell;
    Player player;
public:
    Move(Cell c, Player p) : cell(c), player(p) {}
    Cell getCell() { return cell; }
    Player getPlayer() { return player; }
};

// ---------------- GameResults ----------------
class GameResults {
    bool over;
    string winner;
public:
    GameResults(bool o, string w) {
        over = o;
        winner = w;
    }
    bool isOver() { return over; }
    string getWinner() { return winner; }
};

// ---------------- Abstract Board ----------------
class Board {
public:
    virtual void move(Move m) = 0;
    virtual Board* copy() = 0;
    virtual string getCell(int r, int c) = 0;
    virtual string toString() = 0;
    virtual ~Board() {}
};

// ---------------- TicTacToeBoard ----------------
class TicTacToeBoard : public Board {
    string board[3][3];
public:
    TicTacToeBoard() {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                board[i][j] = "";
    }

    void setCell(Cell c, string symbol) {
        board[c.getRow()][c.getCol()] = symbol;
    }

    string getCell(int r, int c) {
        return board[r][c];
    }

    void move(Move m) {
        setCell(m.getCell(), m.getPlayer().getSymbol());
    }

    string toString() {
        stringstream ss;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j] != "") ss << board[i][j];
                else ss << "-";
                if(j<2) ss << " | ";
            }
            ss << "\n";
            if(i<2) ss << "---------\n";
        }
        return ss.str();
    }

    Board* copy() {
        TicTacToeBoard* newBoard = new TicTacToeBoard();
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                newBoard->board[i][j] = this->board[i][j];
        return newBoard;
    }
};

// ---------------- RuleEngine ----------------
class RuleEngine {
public:
    GameResults getState(TicTacToeBoard &board) {
        // Check rows
        for(int i=0;i<3;i++) {
            string first = board.getCell(i,0);
            if(first != "" && first == board.getCell(i,1) && first == board.getCell(i,2))
                return GameResults(true, first);
        }
        // Check cols
        for(int i=0;i<3;i++) {
            string first = board.getCell(0,i);
            if(first != "" && first == board.getCell(1,i) && first == board.getCell(2,i))
                return GameResults(true, first);
        }
        // Diagonals
        string first = board.getCell(0,0);
        if(first != "" && first == board.getCell(1,1) && first == board.getCell(2,2))
            return GameResults(true, first);

        first = board.getCell(0,2);
        if(first != "" && first == board.getCell(1,1) && first == board.getCell(2,0))
            return GameResults(true, first);

        // Check draw
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board.getCell(i,j) == "")
                    return GameResults(false, "-");

        return GameResults(true, "-"); // Draw
    }
};

// ---------------- AIPlayer ----------------
class AIPlayer {
    bool isStarting(TicTacToeBoard &b, int threshold) {
        int count=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(b.getCell(i,j) != "") count++;
        return count < threshold;
    }

    Move getBasicMove(Player comp, TicTacToeBoard &b) {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(b.getCell(i,j) == "")
                    return Move(Cell(i,j), comp);
        throw runtime_error("No move available");
    }

    Move getSmartMove(Player p, TicTacToeBoard &board) {
        RuleEngine re;
        // Attack
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board.getCell(i,j) == "") {
                    Move move(Cell(i,j), p);
                    Board* copy = board.copy();
                    copy->move(move);
                    if(re.getState(*(TicTacToeBoard*)copy).isOver()) {
                        delete copy;
                        return move;
                    }
                    delete copy;
                }
            }
        }
        // Defense
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board.getCell(i,j) == "") {
                    Move move(Cell(i,j), p.flip());
                    Board* copy = board.copy();
                    copy->move(move);
                    if(re.getState(*(TicTacToeBoard*)copy).isOver()) {
                        delete copy;
                        return Move(Cell(i,j), p);
                    }
                    delete copy;
                }
            }
        }
        return getBasicMove(p, board);
    }

public:
    Move suggestMove(Player comp, TicTacToeBoard &board) {
        if(isStarting(board, 2)) {
            return getBasicMove(comp, board);
        } else {
            return getSmartMove(comp, board);
        }
    }
};

// ---------------- GameEngine ----------------
class GameEngine {
public:
    TicTacToeBoard* start() {
        return new TicTacToeBoard();
    }

    void move(Board &b, Move m) {
        b.move(m);
    }
};

// ---------------- Main ----------------
int main() {
    GameEngine gameEngine;
    TicTacToeBoard* board = gameEngine.start();
    AIPlayer aiEngine;
    RuleEngine ruleEngine;

    Player human("X");
    Player computer("O");

    while(!ruleEngine.getState(*board).isOver()) {
        cout << board->toString() << endl;
        cout << "Make your move! Enter row and column (0-2): ";
        int r,c; cin >> r >> c;
        gameEngine.move(*board, Move(Cell(r,c), human));

        if(!ruleEngine.getState(*board).isOver()) {
            Move aiMove = aiEngine.suggestMove(computer, *board);
            gameEngine.move(*board, aiMove);
        }
    }

    cout << board->toString() << endl;
    cout << "Game Over! Winner: " << ruleEngine.getState(*board).getWinner() << endl;

    delete board;
    return 0;
}
