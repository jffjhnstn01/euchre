// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// EFFECTS Initializes Card to the Two of Spades
Card::Card()
{
    rank = RANK_TWO;
    suit = SUIT_SPADES;
}

//REQUIRES rank is one of "Two", "Three", "Four", "Five", "Six", "Seven",
  //  "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
  //  suit is one of "Spades", "Hearts", "Clubs", "Diamonds"
  //EFFECTS Initializes Card to specified rank and suit
Card::Card(const std::string &rank_in, const std::string &suit_in)
{
    rank = rank_in;
    suit = suit_in;
}

//EFFECTS Returns the rank
std::string Card::get_rank() const
{
    return rank;
}

//EFFECTS Returns the suit.  Does not consider trump.
std::string Card::get_suit() const
{
    return suit;
}

//REQUIRES trump is a valid suit
  //EFFECTS Returns the suit
  //HINT: the left bower is the trump suit!
std::string Card::get_suit(const std::string &trump) const
{
    return suit;
}

//EFFECTS Returns true if card is a face card (Jack, Queen, King or Ace)
bool Card::is_face() const
{
    if (rank == SUIT_SPADES || rank == SUIT_HEARTS || rank == SUIT_CLUBS || rank == SUIT_DIAMONDS)
        return 1;
    else
        return 0;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if card is the Jack of the trump suit
bool Card::is_right_bower(const std::string &trump) const
{
    if (rank == RANK_JACK && suit == trump)
        return 1;
    else
        return 0;
}

 //REQUIRES trump is a valid suit
  //EFFECTS Returns true if card is the Jack of the next suit
  bool Card::is_left_bower(const std::string &trump) const
  {
      if (rank == RANK_JACK)
      {
            if (trump == SUIT_SPADES && suit == SUIT_SPADES)
                return 1;
            else if (trump == SUIT_HEARTS && suit == SUIT_DIAMONDS)
                return 1;
            else if (trump == SUIT_CLUBS && suit == SUIT_SPADES)
                return 1;
            else if (trump == SUIT_DIAMONDS && suit == SUIT_HEARTS)
                return 1;
            else
                return 0;
      }
      else
        return 0;
  }

//REQUIRES trump is a valid suit
//EFFECTS Returns true if the card is a trump card.  All cards of the trump
// suit are trump cards.  The left bower is also a trump card.
bool Card::is_trump(const std::string &trump) const
{
    if (suit == trump)
        return 1;
    else if (is_left_bower(trump))
        return 1;
    else
        return 0;
}

//      HELLO OPERATORS     //

//EFFECTS Returns true if lhs is lower value than rhs.
//  Does not consider trump.
bool operator<(const Card &lhs, const Card &rhs)
{
    int lhs_rank_comp = 0;
    int rhs_rank_comp = 0;

    for (int i = 0; i < NUM_RANKS; i++)
    {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank())
            lhs_rank_comp = i;
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank())
            rhs_rank_comp = i;
        if ((lhs_rank_comp + rhs_rank_comp) > 0)
            break;
    }

    if (lhs_rank_comp < rhs_rank_comp)
        return 1;
    else
        return 0;
}

//EFFECTS Returns true if lhs is higher value than rhs.
//  Does not consider trump.
bool operator>(const Card &lhs, const Card &rhs)
{
    int lhs_rank_comp = 0;
    int rhs_rank_comp = 0;

    for (int i = 0; i < NUM_RANKS; i++)
    {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank())
            lhs_rank_comp = i;
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank())
            rhs_rank_comp = i;
        if ((lhs_rank_comp + rhs_rank_comp) > 0)
            break;
    }

    if (lhs_rank_comp > rhs_rank_comp)
        return 1;
    else
        return 0;
    
}

//EFFECTS Returns true if lhs is same card as rhs.
//  Does not consider trump.
bool operator==(const Card &lhs, const Card &rhs)
{
    int lhs_rank_comp = 0;
    int rhs_rank_comp = 0;

    for (int i = 0; i < NUM_RANKS; i++)
    {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank())
            lhs_rank_comp = i;
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank())
            rhs_rank_comp = i;
        if ((lhs_rank_comp + rhs_rank_comp) > 0)
            break;
    }

    if (lhs_rank_comp == rhs_rank_comp)
        return 1;
    else
        return 0;
}

//EFFECTS Returns true if lhs is not the same card as rhs.
//  Does not consider trump.
bool operator!=(const Card &lhs, const Card &rhs)
{
    int lhs_rank_comp = 0;
    int rhs_rank_comp = 0;

    for (int i = 0; i < NUM_RANKS; i++)
    {
        if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank())
            lhs_rank_comp = i;
        if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank())
            rhs_rank_comp = i;
        if ((lhs_rank_comp + rhs_rank_comp) > 0)
            break;
    }

    if (lhs_rank_comp != rhs_rank_comp)
        return 1;
    else
        return 0;
}

//REQUIRES suit is a valid suit
//EFFECTS returns the next suit, which is the suit of the same color
std::string Suit_next(const std::string &suit)
{
    if (suit == Card::SUIT_SPADES)
        return Card::SUIT_CLUBS;
    else if (suit == Card::SUIT_HEARTS)
        return Card::SUIT_DIAMONDS;
    else if (suit == Card::SUIT_CLUBS)
        return Card::SUIT_SPADES;
    else if (suit == Card::SUIT_DIAMONDS)
        return Card::SUIT_HEARTS;
    else
        return 0;
}

//EFFECTS Prints Card to stream, for example "Two of Spades"
std::ostream & operator<<(std::ostream &os, const Card &card)
{
    os << card.get_rank() << " of " << card.get_suit();
    return os;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses trump to determine
// order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const std::string &trump)
{
    //a < b both not trump
    if (!a.is_trump(trump) && !b.is_trump(trump) && a < b)
        return 1;
    //a < b both trump
    else if (a.is_trump(trump) && b.is_trump(trump))
    {
        if (a.is_left_bower(trump) && b.is_right_bower(trump))
            return 1;
        else if (a < b)
            return 1;
        else
            return 0;
    }
    //a < b with b is trump
    else if (!a.is_trump(trump) && b.is_trump(trump))
        return 1;
    else
        return 0;
}

//REQUIRES trump is a valid suit
//EFFECTS Returns true if a is lower value than b.  Uses both the trump suit
//  and the suit led to determine order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const Card &led_card,
               const std::string &trump)
{
    //card led is less than trump but better than the others
    //a < b both trump
    if (a.is_trump(trump) && b.is_trump(trump))
    {
        if (a.is_left_bower(trump) && b.is_right_bower(trump))
            return 1;
        else if (a < b)
            return 1;
        else
            return 0;
    }
    //a < b both led suit
    else if (led_card.get_suit() == a.get_suit() && 
            led_card.get_suit() == b.get_suit() && a < b)
        return 1;
    //a < b with b trump, a is not
    else if (!a.is_trump(trump) && b.is_trump(trump))
        return 1;
    //a < b with b is led suit, a is not
    else if (led_card.get_suit() != a.get_suit() &&
            led_card.get_suit() == b.get_suit())
        return 1;
    //a < b both not led suit or trump
    else if (a < b)
        return 1;
    //a > b
    else
        return 0;

}