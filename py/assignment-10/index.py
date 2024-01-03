# Sam Farris
# CS125_001
# 11/17/2023

name_scores = dict()

# prompt for name and score and store in dictionary until name is inputted as done
while True:
    name = input("Enter name: ")
    if name =='done':
        break
    score = input("Enter score: ")
    name_scores[name] = score

# store name_scores as a list for sorting and printing
t = list(name_scores.items())
t.sort()

# print key and value of list that is sorted alphabetically 
for key, val in t:
    print(key, val)

student_name = input("Display score for: ")
# loop over keys in name scores list to print out inputted student's score
for key, val in t:
    if key == student_name:
        print(val)