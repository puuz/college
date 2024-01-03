# Sam Farris
# CS125_001
# 10/26/2023

# counts number of specified letters in specified word
def count(word, char):
    count = 0
    # loops string for each letter counting if iterated letter matches specified letter
    for letter in word:
        if letter == char:
            count = count + 1
    # returns total count of specified letters in specified word
    return count

# open file containing words to iterate over
# with error handling for valid file name and
# only allowing 1 letter
error = True
file = None
user_letter = None
while(error):
    try:
        file = open(input('Enter file name: '))
        error = False
    except:
        print('Invalid file name!')

error = True
while(error):
    user_letter = input('Enter letter: ')
    if (len(user_letter) == 1):
        error = False
    else:
        print('Letter means 1!')

total = 0
# loops each line in specified file and counts number of specified letters in each line
for line in file:
    total = total + count(line, user_letter)

print(str(total) + ' ' + user_letter + '\'s found in file')