import itertools


lst = [1, 2, 3, 4]
count_2 = 0
count_3 = 0

for item in itertools.combinations(lst, 2):
    print(item)
    count_2 += 1

print('*' * 40)

for item in itertools.combinations(lst, 3):
    print(item)
    count_3 += 1

# count_2 = (4*3) / (1*2) = 6
print("count_2 = {0}".format(count_2))
# count_3 = (4*3*2) / (1*2*3) = 4
print("count_3 = {0}".format(count_3))