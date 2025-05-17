from random import choice, random
day1 = ["sunny","cloudy","rainy"]
days = [choice(day1)]

for i in range(1,10):
    chance = random()
    # print(days[i-1], chance)
    if days[i-1] == "sunny":
        days.append("sunny" if chance < 0.8 else "cloudy" if chance < 0.9 else "rainy")
    elif days[i-1] == "cloudy":
        days.append("sunny" if chance < 0.4 else "cloudy" if chance < 0.8 else "rainy")
    else:
        days.append("sunny" if chance < 0.2 else "cloudy" if chance < 0.5 else "rainy")
# print(days[-1])
print(days)