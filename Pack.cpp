#include "Pack.h"

// EFFECTS: Initializes the Pack to be in the following standard order:
  //          the cards of the lowest suit arranged from lowest rank to
  //          highest rank, followed by the cards of the next lowest suit
  //          in order from lowest to highest rank, and so on.
  // NOTE: The standard order is the same as that in pack.in.
  // NOTE: Do NOT use pack.in in your implementation of this function
Pack::Pack()
{
    cards = {
        Card(Card::RANK_NINE, Card::SUIT_SPADES),
        Card(Card::RANK_TEN, Card::SUIT_SPADES),
        Card(Card::RANK_JACK, Card::SUIT_SPADES),
        Card(Card::RANK_QUEEN, Card::SUIT_SPADES),
        Card(Card::RANK_KING, Card::SUIT_SPADES),
        Card(Card::RANK_ACE, Card::SUIT_SPADES),
        Card(Card::RANK_NINE, Card::SUIT_HEARTS),
        Card(Card::RANK_TEN, Card::SUIT_HEARTS),
        Card(Card::RANK_JACK, Card::SUIT_HEARTS),
        Card(Card::RANK_QUEEN, Card::SUIT_HEARTS),
        Card(Card::RANK_KING, Card::SUIT_HEARTS),
        Card(Card::RANK_ACE, Card::SUIT_HEARTS),
        Card(Card::RANK_NINE, Card::SUIT_CLUBS),
        Card(Card::RANK_TEN, Card::SUIT_CLUBS),
        Card(Card::RANK_JACK, Card::SUIT_CLUBS),
        Card(Card::RANK_QUEEN, Card::SUIT_CLUBS),
        Card(Card::RANK_KING, Card::SUIT_CLUBS),
        Card(Card::RANK_ACE, Card::SUIT_CLUBS),
        Card(Card::RANK_NINE, Card::SUIT_DIAMONDS),
        Card(Card::RANK_TEN, Card::SUIT_DIAMONDS),
        Card(Card::RANK_JACK, Card::SUIT_DIAMONDS),
        Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS),
        Card(Card::RANK_KING, Card::SUIT_DIAMONDS),
        Card(Card::RANK_ACE, Card::SUIT_DIAMONDS)
    };
    next = 0;
}

// REQUIRES: pack_input contains a representation of a Pack in the
  //           format required by the project specification
  // MODIFIES: pack_input
  // EFFECTS: Initializes Pack by reading from pack_input.
Pack::Pack(std::istream& pack_input)
{
    std::string card_rank = "";
    std::string card_suit = "";
    next = 0;
    int i = 0;
    while (!pack_input.eof())
    {
        getline(pack_input, card_rank, ' ');
        pack_input.ignore(5, ' ');
        getline(pack_input, card_suit, '\n');
        cards[i] = Card(card_rank, card_suit);
        i++;
    }
}

// REQUIRES: cards remain in the Pack
  // EFFECTS: Returns the next card in the pack and increments the next index
Card Pack::deal_one()
{
    if (Pack::empty())
    {
        Pack::reset();
        return cards[next];
    }
    else
    {
        next++;
        return cards[next - 1];
    }
}

// EFFECTS: Resets next index to first card in the Pack
void Pack::reset()
{
    next = 0;
}

// EFFECTS: Shuffles the Pack and resets the next index. This
  //          performs an in shuffle seven times. See
  //          https://en.wikipedia.org/wiki/In_shuffle.
void Pack::shuffle()
{
    std::array<Card, 12> first_half_deck;
    std::array<Card, 12> second_half_deck;
    int i = 0, j = 0, k = 0, shuffles = 0;
    while (shuffles < 7)
    {
        //Copy cards into two separate halves
        for (i = 0; i < PACK_SIZE/2; i++)
            first_half_deck[i] = cards[i];
        
       for (j = 0; j < PACK_SIZE/2; j++)
       {
            second_half_deck[j] = cards[i];
            i++;
       }

        i = 0;
        j = 0;

        //In-shuffle from two separate halves back into original array
        //i goes from 0 to 23, j and k go from 0 to 12
        while (i < PACK_SIZE)
        {
            cards[i] = second_half_deck[j];
            i++;
            cards[i] = first_half_deck[k];
            i++;
            j++;
            k++;
        }
        shuffles++;
        k = 0;
        
    }
}

// EFFECTS: returns true if there are no more cards left in the pack
bool Pack::empty() const
{
    if (next == PACK_SIZE)
        return 1;
    else
        return 0;
}