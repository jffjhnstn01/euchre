#include "HumanPlayer.h"

HumanPlayer::~HumanPlayer(){}

HumanPlayer::HumanPlayer(const std::string &name)
{
    human_name = name;
}

const std::string & HumanPlayer::get_name() const
{
    return human_name;
}

void HumanPlayer::add_card(const Card &c)
{
    if (hand.size() < MAX_HAND_SIZE)
        hand.push_back(c);
    std::sort(hand.begin(), hand.end()); 
}

bool HumanPlayer::make_trump(const Card &upcard, bool is_dealer, 
                                    int round, std::string &order_up_suit) const
                                    {
                                        std::string called_suit;

                                        std::cout << "Human player " << HumanPlayer->get_name();
                                        if (round == 1)
                                        {
                                            return 1;
                                        }
                                        else
                                        {
                                            cin >> called_suit
                                        }
                                        
                                    }

void HumanPlayer::add_and_discard(const Card &upcard)
{

}  

Card HumanPlayer::lead_card(const std::string &trump)
{
    Card a;
    return a;
}

Card HumanPlayer::play_card(const Card &led_card, const std::string &trump)
{
    return led_card;
}

void HumanPlayer::show_hand()
{
    
}