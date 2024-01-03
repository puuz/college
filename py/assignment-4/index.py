#Sam Farris
#CS125_001
#10/5/2023

def computegrade(score):
    if score >= .9:
        return 'A'
    elif score >= .8:
        return 'B'
    elif score >= .7:
        return 'C'
    elif score >= .6:
        return 'D'
    else:
        return 'F'

userscore = float(input('What is your score? '))
grade = computegrade(userscore)
print('Your grade is', grade)