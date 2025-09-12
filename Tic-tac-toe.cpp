#include <bits/stdc++.h>
using namespace std;

// ---------------- Cell ----------------
class Cell {
    int row, col;
public:
    Cell(int r, int c) : row(r), col(c) {}
    int getRow() const { return row; }
    int getCol() const { return col; }
};

// ---------------- Player ----------------
class Player {
    string symbol;
public:
    Player(string s) : symbol(s) {}
    string getSymbol() const { return symbol; }
    Player flip() const {
        return Player(symbol == "X" ? "O" : "X");
    }
};

// ---------------- Move ----------------
class Move {
    Cell cell;
    Player player;
public:
    Move(Cell c, Player p) : cell(c), player(p) {}
    Cell getCell() const { return cell; }
    Player getPlayer() const { return player; }
};

// ---------------- GameResults ----------------
class GameResults {
    bool over;
    string winner;
public:
    GameResults(bool o, string w) : over(o), winner(w) {}
    bool isOver() const { return over; }
    string getWinner() const { return winner; }
};

// ---------------- Abstract Board ----------------
class Board {
public:
    virtual void move(const Move &m) = 0;
    virtual Board* copy() const = 0;
    virtual string getCell(int r, int c) const = 0;
    virtual string toString() const = 0;
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

    string getCell(int r, int c) const override {
        return board[r][c];
    }

    void move(const Move &m) override {
        setCell(m.getCell(), m.getPlayer().getSymbol());
    }

    string toString() const override {
        stringstream ss;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                ss << (board[i][j] != "" ? board[i][j] : "-");
                if(j<2) ss << " | ";
            }
            ss << "\n";
            if(i<2) ss << "---------\n";
        }
        return ss.str();
    }

    string getSymbol(int r, int c) const {
        return board[r][c];
    }

    Board* copy() const override {
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
    GameResults getState(const Board &b) {
        const TicTacToeBoard* board = dynamic_cast<const TicTacToeBoard*>(&b);
        if(!board) throw invalid_argument("Unsupported board");

        // Check rows
        for(int i=0;i<3;i++) {
            string first = board->getCell(i,0);
            if(first != "" && first == board->getCell(i,1) && first == board->getCell(i,2))
                return GameResults(true, first);
        }
        // Check cols
        for(int i=0;i<3;i++) {
            string first = board->getCell(0,i);
            if(first != "" && first == board->getCell(1,i) && first == board->getCell(2,i))
                return GameResults(true, first);
        }
        // Diagonals
        string first = board->getCell(0,0);
        if(first != "" && first == board->getCell(1,1) && first == board->getCell(2,2))
            return GameResults(true, first);

        first = board->getCell(0,2);
        if(first != "" && first == board->getCell(1,1) && first == board->getCell(2,0))
            return GameResults(true, first);

        // Check draw
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board->getCell(i,j) == "")
                    return GameResults(false, "-");

        return GameResults(true, "-"); // Draw
    }
};

// ---------------- AIPlayer ----------------
class AIPlayer {
    bool isStarting(const TicTacToeBoard &b, int threshold) {
        int count=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(b.getCell(i,j) != "") count++;
        return count < threshold;
    }

    Move getBasicMove(Player comp, const TicTacToeBoard &b) {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(b.getCell(i,j) == "")
                    return Move(Cell(i,j), comp);
        throw runtime_error("No move available");
    }

    Move getSmartMove(Player p, const TicTacToeBoard &board) {
        RuleEngine re;
        // Attack
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board.getCell(i,j) == "") {
                    Move move(Cell(i,j), p);
                    Board* copy = board.copy();
                    copy->move(move);
                    if(re.getState(*copy).isOver()) { delete copy; return move; }
                    delete copy;
                }
        // Defense
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board.getCell(i,j) == "") {
                    Move move(Cell(i,j), p.flip());
                    Board* copy = board.copy();
                    copy->move(move);
                    if(re.getState(*copy).isOver()) { delete copy; return Move(Cell(i,j), p); }
                    delete copy;
                }
        return getBasicMove(p, board);
    }

public:
    Move suggestMove(Player comp, const Board &b) {
        const TicTacToeBoard* t = dynamic_cast<const TicTacToeBoard*>(&b);
        if(!t) throw invalid_argument("Unsupported board");

        if(isStarting(*t, 2)) {
            return getBasicMove(comp, *t);
        } else {
            return getSmartMove(comp, *t);
        }
    }
};

// ---------------- GameEngine ----------------
class GameEngine {
public:
    Board* start(string type) {
        if(type == "TicTacToe") return new TicTacToeBoard();
        throw invalid_argument("Unsupported game type");
    }

    void move(Board &b, const Move &m) {
        b.move(m);
    }
};

// ---------------- Main ----------------
int main() {
    GameEngine gameEngine;
    Board* board = gameEngine.start("TicTacToe");
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
