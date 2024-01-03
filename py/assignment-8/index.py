#Sam Farris
#CS125_001
#11/3/2023

number_list = []

# infinite loop for number prompt and store in array until input is done
while True:
    user_input = input('Enter a number: ')
    if user_input == 'done':
        break
    else:
        number_list.append(user_input)

# print max number and minimum number from inputted numbers
print('Max:', max(number_list))
print('Min:', min(number_list))