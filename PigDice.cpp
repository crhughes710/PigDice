#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

class Die {
private:
    int m_value;
    int m_numOfSides;
public:
    Die () { // default constructor
        m_value = 0;
        m_numOfSides = 6;
    }
    void setNumOfSides(int numOfSides) {
        switch (numOfSides) {
            case 4:
                m_numOfSides = 4;
                break;
            case 6:
                m_numOfSides = 6;
                break;
            case 8:
                m_numOfSides = 8;
                break;
            default:
                m_numOfSides = 6;
        }
    }
    int getNumOfSides() {
        return m_numOfSides;
    }

    void setValue() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1,m_numOfSides);
        m_value = dis(gen);
    }
    int getValue() {
        return m_value;
    }
};

void display_rules() {
    std::cout << "Let's Play PIG Dice!\n\n" <<
            "* See how many turns it takes you to get to 20 points.\n" <<
            "* Turn ends when you hold or roll a 1.\n" << "* If you roll a 1, you lose all points for the turn.\n" <<
            "* If you hold, you bank all points for the turn to the game score.\n\n";
}

void roll_dice(GameState& my_game, Die& myDie) {
    //int x = time(0);
    //srand(x);
    //int die = 1 + rand() % 6;
    myDie.setValue();
    int die = myDie.getValue();
    if (die == 1) {
        std::cout << "Die: " << die << "\n";
        my_game.turn_over = true;
        my_game.score_this_turn = 0;
        std::cout << "Turn over. No score.\n";
    }
    else {
        my_game.score_this_turn = die + my_game.score_this_turn;
        std::cout << "Die: " << die << " - Running score this turn: " << my_game.score_this_turn << "\n";
    }
}

void hold_turn(GameState& my_game) {
    my_game.turn_over = true;
    my_game.game_score= my_game.score_this_turn + my_game.game_score;
}

void take_turn (GameState& my_game, Die& myDie) {
    my_game.turn_over = false;
    my_game.score_this_turn = 0;
    my_game.turn_count = ++my_game.turn_count;
    std::cout << "TURN " << my_game.turn_count << " - Game Score: " << my_game.game_score << "\n";
    while (my_game.turn_over == false) {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> my_game.choice;
        if (my_game.choice == 'r') {
            roll_dice(my_game, myDie);
        }
        else if (my_game.choice == 'h') {
            hold_turn(my_game);
        }
        else {
            std::cout<< "Invalid choice. Please either (r/h)\n";
        }
    }
        std::cout << "Score Banked This Turn: " << my_game.score_this_turn << "\n\n";
}

void play_game(GameState& my_game, Die& myDie) {

    /* "This will be used eventually when deciding sides, we need a try clause to catch strings though."
    int sidesUserChoice;
    int sidesDecision;
    std::cout << "How many sides of the dice?: ";
    std::cin >> sidesUserChoice;
    myDie.setNumOfSides(sidesUserChoice);
    sidesDecision = myDie.getNumOfSides();
    std::cout << "This game, the dice will have " << sidesDecision << " sides. Goodluck!" << std::endl << std::endl;*/

    while (my_game.game_over == false) {
        if (my_game.game_score < 20) {
            take_turn(my_game, myDie);
        }
        else {
            std::cout << "You finished with a final score of " << my_game.game_score << " in " << my_game.turn_count << " turns!\n" <<
            "Thanks for playing PIG Dice!\n";
            my_game.game_over = true;
        }
    }
}

int main() {
    GameState my_game; // instantiate a GameState object
    Die myDie;
    display_rules(); // call the display_rules function
    play_game(my_game, myDie); // call the play_game function and pass the GameState object
    return 0;
}