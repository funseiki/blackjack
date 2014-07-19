#Game Structure Ramblings

##Classes

    - Game
        - Handles managing the game loop and initializing things
    - Player
        - Manages player resources such as:
            - Number of chips
            - Current hand
            - Current bet amount
            - Location at table
            - Other meta data
                - E.g. name, eye color, long walks at the beach
    - Dealer
        - Perhaps a subclass of player?
        - No chips
        - Has a hand
        - Has an 'AI' - e.g. Stay after 17
    - Deck
        - Helper class for handling some of the card related features:
            - Number of cards in deck
            - Deck shuffling
            - etc.
    - Action
        - Class (or Game method) which defines rules for how to update the game's state on an action

##States

    - Start:
        - Initialize deck(s): Somewhere between 1 and 8 decks used
        - Initialize players (and dealer) with number of chips
    - Shuffle:
        - Shuffle the cards in the deck
    - Bet:
        - Player places bet
    - Deal:
        - Give each player, starting from the dealers left, a card
            - dealer is dealt last, with first card face up
    - Perform action:
        - Wait for player (or dealer) input
            - Actions available:
                - Hit - offer player card from top of deck
                - Stand - player stops taking cards
            - Stopping events:
                - Player reaches 21
                    - Dealer still plays
                - Player exceeds 21
                    - Round ends, dealer takes money
    - Distribute chips
    - Repeat from Shuffle
