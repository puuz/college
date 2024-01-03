# Sam Farris
# CS125_001
# 11/10/2023

name_scores = dict()

# prompt for name and score and store in dictionary
while True:
    name = input("Enter name: ")
    if name =='done':
        break
    score = input("Enter score: ")
    name_scores[name] = score

# print created dictionary and length from input once name
# is inputted as done
print(len(name_scores))
print(name_scores)