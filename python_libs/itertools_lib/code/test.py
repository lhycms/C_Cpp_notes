import itertools


lst = [1, 2, 3, 4]
count_2 = 0
count_3 = 0

for item in itertools.permutations(lst, 2):
    count_2 += 1
    print(item)

print('*' * 40)

for item in itertools.permutations(lst, 3):
    count_3 += 1
    print(item)

# count_2 = 4 * 3 = 12
print("count_2 = {0}".format(count_2))
# count_3 = 4 * 3 * 2 = 24 
print("count_3 = {0}".format(count_3))