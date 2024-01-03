class UserInput:
    # array within array
    users = []
    # single array
    user_data = []
    user = ''
    _password = ''
    _cpassword = ''
    money = ''
    _file = ''
    _FILE_NAME = 'users.txt'
    def __init__(self):
        action = input('Sign in or Login [S or L] -> ')
        # get first input whether user is signing in or logging in
        # and handle errors properly
        while True:
            if action == 'S':
                self.user = input('Username -> ')
                self._user_exists(False)
                self._password = input('Password -> ')
                self._cpassword = input('Confirm Password -> ')
                self._passwords_matches()
                self.money = input('Deposit Amount -> ')
                self._money_valid()
                file = open(self._FILE_NAME, 'a')
                self.user_data = self.user + ' ' + self._password + ' ' + self.money
                if len(self.users) != 0:
                    file.write('\n' + self.user_data)
                else:
                    file.write(self.user_data)
                file.close()
                break
            elif action == 'L':
                self.user = input('Username -> ')
                self._user_exists(True)
                self._password = input('Password -> ')
                self._password_correct()
                break
            else:
                action = input('Incorrect input, Sign in or Login [S or L] -> ')
        print('\nWelcome ' + self.user + '! You have $' + self.money + ' in your account.\n')

    # private function, checks if username exists that user inputted
    def _user_exists(self, passing):
        found = False
        file = open(self._FILE_NAME)
        for line in file:
            other_user_data = line.replace('\n', '').split(' ')
            if self.user == other_user_data[0]:
                if passing == True:
                    self.user_data = other_user_data
                    self.money = other_user_data[2]
                    found = True
                    continue
                self.user = input('Username already exists, Username -> ')
                self.users = []
                file.close()
                self._user_exists(passing)
            self.users.append(other_user_data)
        if not found and passing == True:
            self.user = input("Username doesn't exist, Username -> ")
            self.users = []
            file.close()
            self._user_exists(passing)
        file.close()



    # private function, checks if password and confirm password matches during signing up process
    def _passwords_matches(self):
        while True:
            if self._password != self._cpassword:
                self._cpassword = input("Password doesn't match, Confirm Password -> ")
            else:
                break

    # private function, checks if deposited money is a valid input during signing up process
    def _money_valid(self):
        while True:
            if not self.money.isdigit():
                self.money = input("That's not a digit, Deposit Amount -> ")
            elif self.get_money() > 1000 or self.get_money() < 100:
                self.money = input("Needs to be beetween 100 and 1000, Deposit Amount -> ")
            else:
                break

    # private function, checks if password is correct to the username inputted during logging in process
    def _password_correct(self):
        file = open(self._FILE_NAME)
        for line in file:
            other_user_data = line.replace('\n', '').split(' ')
            if self.user == other_user_data[0] and self._password == other_user_data[1]:
                file.close()
                return True
        self._password = input('Password is incorrect, Password -> ')
        file.close()
        self._password_correct()
    
    # allows to update the users money when they win or loose in blackjack and updates txt database
    def set_money(self, num):
        file = open(self._FILE_NAME)
        for line in file:
            other_user_data = line.replace('\n', '').split(' ')
            if self.user == other_user_data[0]:
                old_other_user_data = ' '.join(other_user_data)
                other_user_data[2] = str(num)
                self.money = other_user_data[2]
                file.close()
                file = open(self._FILE_NAME, 'r')
                new_users_data = file.read().replace(old_other_user_data, ' '.join(other_user_data))
                file.close()
                file = open(self._FILE_NAME, 'w')
                file.write(new_users_data)
                file.close()
                return True
        file.close()
        return False
    
    # easy way to covert string of money to int rather than using int() every time
    def get_money(self):
        return int(self.money)