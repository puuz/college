# Sam Farris
# CS125_001
# 9/29/2023

hours = input('Enter Hours: ')
hours = float(hours)

rate = input('Enter Hourly Rate: ')
rate = float(rate)

ot = 0

if hours > 40:
    ot = hours - 40
    hours = 40

total = (hours * rate) + (ot * rate * 1.5)
print(total)