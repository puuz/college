#Sam Farris
#CS125_001
#10/12/2023

total = 0
count = 0

user_input = input('Enter a number: ')

while user_input != 'done':
    try:
        total = total + float(user_input)
        count = count + 1
        user_input = input('Enter another number: ')
    except:
        print('Invalid input!')
        user_input = input('Enter another number: ')

avg = total / count
print('\nTotal: ' + str(total))
print('Count: ' + str(count))
print('Average: ' + str(avg))