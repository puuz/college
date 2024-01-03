import random

class BlackJack:
    suits = ['Clubs', 'Diamonds', 'Hearts', 'Spades']
    values = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
    # single array of every possible output of suits and values
    deck = []
    # array within array of suit and value
    player_cards = []
    player_score = 0
    # array within array of suit and value
    dealer_cards = []
    dealer_score = 0
    bet = 0
    def __init__(self, user_input):
        self.user_input = user_input
        # create deck array using a for loop within a for loop for suits and values of cards
        for suit in self.suits:
            for value in self.values:
                self.deck.append([value, suit])

        # std python class offering shuffle method, manips array in function randomly everytime
        random.shuffle(self.deck)
        self.player_cards = [self.deck.pop(), self.deck.pop()]
        # dealer gets cards last
        self.dealer_cards = [self.deck.pop(), self.deck.pop()]

        # calculate score
        self.player_score = self.total_cards_value(self.player_cards)
        self.dealer_score = self.total_cards_value(self.dealer_cards)

        # prompt for bet amount and handle errors accordingly
        self.bet = input('Bet Amount -> ')
        self._bet_valid()
        print('\n' + self.cards_to_string(True))
        print(self.cards_to_string(False))

        action = input('Hit or Stay [H or S] ->')
        # get second input whether user wants to hit or stay
        # and handle errors properly
        while True:
            if action == 'H':
                self.player_cards.append(self.deck.pop())
                self.player_score = self.total_cards_value(self.player_cards)
                print('\n' + self.cards_to_string(True))
                if self.player_score > 21:
                    money_left = self.user_input.get_money() - self.get_bet()
                    print('You busted and you lost $' + self.bet + '\nYou now have $' + str(money_left) + ' :(')
                    if not self.user_input.set_money(money_left):
                        print("\nYou're username wasn't found in the database, so we couldn't update your money.")
                else:
                    action = input('Hit or Stay [H or S] ->')
                    continue
                break
            elif action == 'S':
                if self.dealer_score < 17:
                    self.dealer_cards.append(self.deck.pop())
                    self.dealer_score = self.total_cards_value(self.dealer_cards)
                    print('\n' + self.cards_to_string(False))
                    if self.dealer_score > 21:
                        money_left = self.user_input.get_money() + self.get_bet()
                        print('Dealer busted and you won $' + self.bet + '!\nYou now have $' + str(money_left) + ' :)')
                        if not self.user_input.set_money(money_left):
                            print("\nYou're username wasn't found in the database, so we couldn't update your money.")
                    else:
                        continue
                else:
                    if self.player_score == self.dealer_score:
                        print("\nDealer stayed, it's a draw\nYou didn't win or loose any money :|")
                    elif self.player_score > self.dealer_score:
                        money_left = self.user_input.get_money() + self.get_bet()
                        print('\nDealer stayed, you won $' + self.bet + '!\nYou now have $' + str(money_left) + ' :)')
                        if not self.user_input.set_money(money_left):
                            print("\nYou're username wasn't found in the database, so we couldn't update your money.")
                    elif self.player_score < self.dealer_score:
                        money_left = self.user_input.get_money() - self.get_bet()
                        print('\nDealer stayed, you lost $' + self.bet + '\nYou now have $' + str(money_left) + ' :(')
                        if not self.user_input.set_money(money_left):
                            print("\nYou're username wasn't found in the database, so we couldn't update your money.")
                    else:
                        print("You broke math xD")
                break
            else:
                action = input('Incorrect input, Hit or Stay [H or S] -> ')


    # private function, get value total of a single card which is a value and suit 
    def _card_value(self, card):
        if card[0] in ['J', 'Q', 'K']:
            return 10
        elif card[0] == 'A':
            return 11
        else:
            return int(card[0])
    
    # private function, checks if bet is a valid input during start of blackjack
    def _bet_valid(self):
        while True:
            if not self.bet.isdigit():
                self.bet = input("That's not a digit, Bet Amount -> ")
            elif self.user_input.get_money() < self.get_bet():
                self.bet = input("You don't have enough money, Bet Amount -> ")
            elif self.get_bet() < 10:
                self.bet = input("There's a $10 minimum, Bet Amount -> ")
            else:
                break
    
    # get total of multiple cards so an array within array of a card with a value and suit
    def total_cards_value(self, cards):
        total = 0
        has_ace = False
        ace_count = 0
        for card in cards:
            value = self._card_value(card)
            total = total + value
            # account for Ace's if total is above 21
            if card[0] == 'A':
                has_ace = True
                ace_count = ace_count + 1
        if total > 21 and has_ace:
            total = total - (10 * ace_count)
        return total
    
    # return string of value and suit for output
    def cards_to_string(self, isPlayer):
        output = ''
        if isPlayer == True:
            output = "You're Cards (" + str(self.player_score) + ')\n'
            for card in self.player_cards:
                output = output + card[0] + ' of ' + card[1] + '\n'
        else:
            output = "Dealer's Cards (" + str(self.dealer_score) + ')\n'
            for card in self.dealer_cards:
                output = output + card[0] + ' of ' + card[1] + '\n'
        return output

    # easy way to covert string of bet to int rather than using int() every time
    def get_bet(self):
        return int(self.bet)
    