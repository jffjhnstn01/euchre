#include "SimplePlayer.h"

// Needed to avoid some compiler errors
SimplePlayer::~SimplePlayer()
{

}

SimplePlayer::SimplePlayer(const std::string &name)
{
    simple_name = name;
}

//EFFECTS returns player's name
const std::string & SimplePlayer::get_name() const
{
    return simple_name;
}

//REQUIRES player has less than MAX_HAND_SIZE cards
//EFFECTS  adds Card c to Player's hand
void SimplePlayer::add_card(const Card &c)
{
    if (hand.size() < MAX_HAND_SIZE)
        hand.push_back(c);
    std::sort(hand.begin(), hand.end());    
}

//REQUIRES round is 1 or 2
//MODIFIES order_up_suit
//EFFECTS If Player wishes to order up a trump suit then return true and
//  change order_up_suit to desired suit.  If Player wishes to pass, then do
//  not modify order_up_suit and return false.
bool SimplePlayer::make_trump(const Card &upcard, bool is_dealer,
                        int round, std::string &order_up_suit) const
                        {
                            int trump_face_card_count = 0;
                            int color_face_card_count = 0;

                            std::string card_color;
                            if (upcard.get_suit() == Card::SUIT_CLUBS || upcard.get_suit() == Card::SUIT_SPADES)
                                card_color = "black";
                            else
                                card_color = "red";
                            //Round 1, make trump if you have 2 or more face cards of the same suit at the up card
                            if (round == 1)
                            {
                                for (int i = 0; i < MAX_HAND_SIZE; i++)
                                {
                                    //Count the number of face trump cards
                                    if (hand[i].is_trump(order_up_suit) && hand[i].is_face())
                                         trump_face_card_count++;
                                    
                                    //Count the number of face cards of same color as upcard
                                    else if (card_color == "black" && !hand[i].is_trump(order_up_suit) && hand[i].is_face())
                                        color_face_card_count++;
                                }
                                //Order up trump with the same suit as upcard if you have more than 1 trump face card
                                if (trump_face_card_count > 1)
                                    return 1;
                                //Pass    
                                else
                                    return 0;
                            }
                            //Round 2, make trump if you have 2 or more face cards of the same color of the up card
                            else
                            {
                                //If round 2 and dealer, screw the dealer
                                if (is_dealer)
                                {
                                    if (order_up_suit == Card::SUIT_CLUBS)
                                    {
                                        order_up_suit = Card::SUIT_SPADES;
                                        return 1;
                                    } 
                                    else if (order_up_suit == Card::SUIT_SPADES)
                                    {
                                        order_up_suit = Card::SUIT_CLUBS;
                                        return 1;
                                    }
                                    else if (order_up_suit == Card::SUIT_DIAMONDS)
                                    {
                                        order_up_suit = Card::SUIT_HEARTS;
                                        return 1;
                                    }
                                    else
                                    {
                                        order_up_suit = Card::SUIT_DIAMONDS;
                                        return 1;
                                    }
                                }
                                //Not the dealer and you have 1 or more face card of the same color as the upcard
                                else if (color_face_card_count > 0)
                                {
                                    if (order_up_suit == Card::SUIT_CLUBS)
                                    {
                                        order_up_suit = Card::SUIT_SPADES;
                                        return 1;
                                    } 
                                    else if (order_up_suit == Card::SUIT_SPADES)
                                    {
                                        order_up_suit = Card::SUIT_CLUBS;
                                        return 1;
                                    }
                                    else if (order_up_suit == Card::SUIT_DIAMONDS)
                                    {
                                        order_up_suit = Card::SUIT_HEARTS;
                                        return 1;
                                    }
                                    else
                                    {
                                        order_up_suit = Card::SUIT_DIAMONDS;
                                        return 1;
                                    }
                                }
                                //Pass again
                                else
                                    return 0;
                            }
                        }

//REQUIRES Player has at least one card
//EFFECTS  Player adds one card to hand and removes one card from hand.
void SimplePlayer::add_and_discard(const Card &upcard)
{
    //Add upcard to hand
    hand.push_back(upcard);
    //Sort hand smallest to largest
    std::sort(hand.begin(), hand.end());
    //Remove lowest card which should now be the first one even if it is the upcard
    hand.erase(hand.begin())
;}

//REQUIRES Player has at least one card, trump is a valid suit
//EFFECTS  Leads one Card from Player's hand according to their strategy
//  "Lead" means to play the first Card in a trick.  The card
//  is removed the player's hand.
Card SimplePlayer::lead_card(const std::string &trump)
{
    std::sort(hand.begin(), hand.end());
    for (int i = hand.size() - 1; i >= 0; i--)
    {
        if (!hand[i].is_trump(trump))
            return hand[i];
    }
    return hand.back();
}

//REQUIRES Player has at least one card, trump is a valid suit
//EFFECTS  Plays one Card from Player's hand according to their strategy.
//  The card is removed from the player's hand.
Card SimplePlayer::play_card(const Card &led_card, const std::string &trump)
{
    for (int i = hand.size(); i >= 0; i--)
    {
        if (hand[i].get_suit() == led_card.get_suit())
            return hand[i];
    }
    return hand.front();
}

void SimplePlayer::show_hand()
{
    for (int i = 0; i < 5; i++)
        std::cout << hand[i] << std::endl;
    
}

/*//Comparator to sort cards from smallest to largest in terms of rank
static bool smaller_card (const Card lhs, const Card rhs)
{
    return lhs < rhs;
}*/