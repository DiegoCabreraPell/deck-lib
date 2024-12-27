/**
 * Author: Diego Cabrera Pell
 * Created: 27/12/2024
 *
 * A deck library for decks with multiple suits of identical values.
 * (i.e. if suit 1 has 13 values then all suits must have 13 values)
 **/

#include <deck.h>
#include <stdint.h>
#include <stdlib.h>

void create_deck(Deck* deck, uint8_t num_suits, uint8_t num_values) {
    uint16_t *cards, cursor;
    int max_cards = num_values * num_suits;

    deck->suits = num_suits;
    deck->values = num_values;
    deck->cards_left = max_cards;
    deck->cards_discarded = 0;
    deck->discard_head = 0;
    deck->deck_head = 0;
    deck->data = malloc(sizeof(uint16_t) * max_cards);

    cards = (uint16_t*) deck->data;

    /* setting default shuffling to organized by suits as the cards will point
     * to each other in order of least to greatest */
    for (cursor = 0; cursor < max_cards; cursor++) {
        cards[cursor] = cursor +1;
    }
}


void deal_card(Deck *deck, Card* card) {
    uint16_t card_num, *cards;

	if (deck->cards_left) {
        deck->cards_left--;
        cards = (uint16_t*) deck->data;

        card_num = deck->deck_head;

        card->suit = card_num % deck->values;
        card->value = card_num - (deck->values * deck->suits);

        deck->deck_head = cards[deck->deck_head];
    }
}


void reset_deck(Deck *deck) {
    uint16_t max_cards, *cards, cursor;

    max_cards = deck->values * deck->suits;

	deck->cards_left = max_cards;
    deck->cards_discarded = 0;
    deck->discard_head = 0;
    deck->deck_head = 0;

    cards = (uint16_t*) deck->data;

    /* setting default shuffling to organized by suits as the cards will point
     * to each other in order of least to greatest */
    for (cursor = 0; cursor < max_cards; cursor++) {
        cards[cursor] = cursor +1;
    }
}


void shuffle_deck(Deck *deck) {
	
}


void shuffle_discard_in(Deck *deck) {
	
}


void discard(Deck *deck, Card card) {
	uint16_t index, *cards;

    cards = deck->data;
    index = (deck->values * card.suit) + card.value;

    cards[index] = deck->discard_head;
    deck->discard_head = index;

    deck->cards_discarded++;
}


void put_in(Deck *deck, Card card, int position) {
    uint16_t index, *cards, cursor, prev;

    cards = deck->data;
    index = (deck->values * card.suit) + card.value;

    if (position >= deck->cards_left) {
        position = deck->cards_left-1;
    } else if (position < 0) {
        position = 0;
    }

    if (position == 0){
        cards[index] = deck->deck_head;
        deck->deck_head = index;
        return;
    }

    prev = deck->deck_head;
    cursor = deck->deck_head;
    while (position)
    {
        prev = cursor;
        cursor = cards[cursor];
    }

    cards[prev] = index;
    cards[index] = cursor;
}


void free_deck(Deck *deck) {
    free(deck->data);
}


int num_cards_left(Deck *deck) {
    return deck->cards_left;	
}

