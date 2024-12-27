/**
 * Author: Diego Cabrera Pell
 * Created: 26/12/2024
 *
 * Interface for the deck library
 **/


#ifndef DECK_H
#define DECK_H

#include <stdint.h>

typedef struct Deck {    
    uint8_t suits;
    uint8_t values;
    uint16_t cards_left;
    uint16_t *data;
    uint16_t discard_head;
    uint16_t deck_head;
} Deck;

typedef struct Card {
    uint8_t suit;
    uint8_t value;
} Card;

void create_deck(Deck *deck, uint8_t num_suits, uint8_t num_values);

void deal_card(Deck *deck, Card* card);

void reset_deck(Deck *deck);

void shuffle_deck(Deck *deck);

void shuffle_discard_in(Deck *deck);

void discard(Deck *deck, Card card);

void put_in(Deck *deck, Card card, int position);

void free_deck(Deck *deck);

int num_cards_left(Deck *deck);

#endif
