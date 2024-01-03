#Sam Farris
#CS125_001
#10/17/2023

# counts number of specified letters in specified word
def count(word, char):
    count = 0
    # loops string for each letter counting if iterated letter matches specified letter
    for letter in word:
        if letter == char:
            count = count + 1
    # print total count of specified letters in specified word
    print(count)

user_word = input('Enter Word: ')
user_char = input('Enter Letter: ')
count(user_word, user_char)